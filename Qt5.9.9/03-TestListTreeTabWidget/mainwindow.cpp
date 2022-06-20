#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>
#include <QMetaProperty>
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize();
}
void MainWindow::initialize()
{
    setAllActionsForToolButtons(); // 设置所有工具按钮的动作联系

    // 其他一些细节的初始化
      /*工具栏可以显示出文字和图标,涉及的枚举类型是enum ToolButtonStyle {
        ToolButtonIconOnly,
        ToolButtonTextOnly,
        ToolButtonTextBesideIcon,
        ToolButtonTextUnderIcon,
        ToolButtonFollowStyle}
    */
    this->ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    /*将给定的小部件设置为主窗口的中心小部件。
    注意：QMainWindow拥有小部件指针的所有权，并在适当的时间将其删除。*/
    setCentralWidget(ui->splitter); //设置ui->splitter为中心组件

    // 设置2个spinbox的范围和格式
    QDateTime datetime = QDateTime::currentDateTime();
    this->ui->spinDateBox->setValue(datetime.date().day());
    this->ui->spinDateBox->setSuffix("天");
    this->ui->spinDateBox->setPrefix("第");
    this->ui->spinDateBox->setRange(1,31);
    this->ui->spinMonthBox->setRange(1,12);
    this->ui->spinMonthBox->setValue(datetime.date().month());
    this->ui->spinMonthBox->setSuffix("月");
    this->ui->spinMonthBox->setPrefix("第");
    // 展示日期的默认文本
    // 2022-06-20 六月 星期一  07::34::54.790 下午
    // this->ui->textLabelLineEdit->setText(datetime.toString("yyyy-MM-dd MMMM dddd hh::mm::ss.zzz AP"));
    this->ui->textLabelLineEdit->setText(datetime.toString("yyyy-MM-dd dddd hh::mm::ss.zzz"));

    // 设置进度条格式
    this->ui->progressBar->setFormat("%p%"); // 百分比显示
    this->ui->progressBar->setTextVisible(true); // 文字可见
    this->ui->progressBar->setRange(1,366); // 范围
    this->ui->progressBar->setValue(datetime.date().dayOfYear()); // 当前值

    // datetimeedit组件和lcd组件
    this->ui->dateTimeEdit->setDateTime(datetime);
    this->ui->lcdHourNumber->display(datetime.time().hour());
    this->ui->lcdMinuteNumber->display(datetime.time().minute());
    this->ui->lcdSecondNumber->display(datetime.time().second());

    // QDial
    this->ui->dial->setFont(QFont("黑体",16,QFont::Bold,true)); // 黑体16号字,加粗斜体
}
void MainWindow::setAllActionsForToolButtons()
{
     /*
        1. QAction：总计20个
        1.1 共10个
            System：2个，actionReboot和actionClose
            Tool：5个，actionlistInit、actionlistClear、actionlistAppend、actionlistDelete、actionListInsert
            File：3个，actionshowText、actionclearText、actionsaveText
            这10个动作自动关联菜单栏，或者说菜单栏下拉项创建的实际上就是动作QAction类型
         1.2 5个
                actListIni、actListClear、actListInsert、actListAppend、actListDelete
                这是5个自定义的动作,不像菜单栏会自动关联,所以需要手动关联QToolButton,那么点击按钮就联系此动作
                这里自动关联了工具栏的5个QToolButton
        1.3 3个
                tBtnSelALL、tBtnSelInvs、tBtnSelNone
                这3个将会关联界面TabWidget组件的QGroupBox的3个QToolButton
        1.4 2个
                actQuit、actSelPopMenu
                这2个是在UI界面中就自动关联了非QToolButton的2个对象
                actQuit的triggered()信号关联了MainWindow的close()槽函数
                    同时actQuit也被动态ToolButton"退出"关联,等同于点击退出按钮->关闭窗口
                actSelPopMenu动作的triggered()信号关联了tBtnSelInvs动作的trigger()信号,"反选"按钮的信号
                    同时actSelPopMenu也被tBtnSelectItem、动态Toolbutton"项选择"关联
                    等同于点击2个项选择按钮都会弹出下拉菜单选项

        2. QToolButton：总计11个
        2.1 5个
                  tBtnListIni、tBtnListClear、tBtnListInsert、tBtnListAppend、tBtnListDelete
                  关联QAction1.2说明的5个动作
        2.2 3个
                   tBtnSelALL、tBtnSelInvs、tBtnSelNone
                   关联QAction1.3说明的3个动作
        2.3 1个
                    tBtnSelectItem
                    这个按钮比较特殊，具有下拉式菜单，需要动态创建
                    用于动态创建的函数是setPopMenuForBtnSelectItem()
         2.4 2个
                    工具栏中动态添加的按钮"项选择"和"退出"
                    在setTwoDynamicToolButtonForToolBar()函数中动态创建
    */
    // 2.1 5个QToolButton联系的5个QAction
    ui->tBtnListIni->setDefaultAction(ui->actListIni);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);
    // 2.2  3个QToolButton联系的3个QAction
    ui->tBtnSelALL->setDefaultAction(ui->actSelALL);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);
    // 2.3 调用此函数给tBtnSelectItem创建动态菜单和设置动作
    this->setPopMenuForBtnSelectItem();
    // 2.4 调用此函数给toolBar创建2个动态ToolButton
    this->setTwoDynamicToolButtonForToolBar();
}
void    MainWindow::setPopMenuForBtnSelectItem()
{
    //创建下拉菜单
        QMenu* menuSelection=new QMenu(this); //创建选择弹出式菜单
        menuSelection->addAction(ui->actSelALL); // 菜单有3个动作,直接联系2.2的3个动作即可
        menuSelection->addAction(ui->actSelNone);
        menuSelection->addAction(ui->actSelInvs);

    //listWidget上方的tBtnSelectItem按钮
        // enum ToolButtonPopupMode {DelayedPopup,MenuButtonPopup,InstantPopup};
        // MenuButtonPopup模式将会让工具按钮显示一个特殊箭头，指示存在菜单，但是按钮本身也可以联系1个默认动作
        // InstantPopup模式点击按钮时立即显示菜单,没有默认的动作，即此模式下不会触发按钮自身联系的动作
        // DelayedPopup模式按住工具按钮一段时间后(超时取决于样式，请参阅 QStyle::SH_ToolButton_PopupDelay)，将显示菜单

        ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);//可以点击也可以下三角菜单的弹出模式，执行按钮的Action
        ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //按钮样式
        // 如果希望ToolButton点击时也有响应,那么可以设置默认动作,动作actSelPopMenu可以继续关联反选、全选、全不选任意1个动作的trigger()信号
        ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu); // 此动作继续关联的是tBtnSelInvs的trigger(),即"反选"按钮的信号
        ui->tBtnSelectItem->setMenu(menuSelection); //设置下拉菜单
}
void    MainWindow::setTwoDynamicToolButtonForToolBar()
{
    //创建下拉菜单
        QMenu* menuSelection=new QMenu(this); //创建选择弹出式菜单
        menuSelection->addAction(ui->actSelALL); // 菜单有3个动作,直接联系2.2的3个动作即可
        menuSelection->addAction(ui->actSelNone);
        menuSelection->addAction(ui->actSelInvs);

    //工具栏上的下拉式菜单按钮,除了UI已有的5个按钮额外动态增加2个按钮,"项选择"和"退出"
       QToolButton  *aBtn=new QToolButton(this);

       aBtn->setPopupMode(QToolButton::InstantPopup);//按钮按下时立即显示菜单,此模式下不会触发按钮自身联系的动作
       aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//按钮样式
       aBtn->setDefaultAction(ui->actSelPopMenu); //联系"项选择"按钮,获取图标、标题等设置
       aBtn->setMenu(menuSelection);//设置下拉菜单
       ui->toolBar->addWidget(aBtn); //工具栏添加按钮

   //工具栏添加分隔条，联系"退出"按钮
       ui->toolBar->addSeparator();
       ui->toolBar->addAction(ui->actQuit);
}
MainWindow::~MainWindow()
{
    delete ui;
}


// 以下的函数是20个QAction自动关联的槽函数
// 1. 初始化列表，2个QAction,动作一致,调用公共函数actListIniCommon(); +2
void MainWindow::on_actListIni_triggered() {// toolBar上的
   this->actListIniCommon();
}
void MainWindow::on_actionlistInit_triggered() {// menuBar上的
    this->actListIniCommon();
}
void MainWindow::actListIniCommon(){
    //初始化项
   QListWidgetItem *aItem; //列表的每一行是一个QListWidgetItem

   QIcon aIcon;
   aIcon.addFile(":icons/check2.ico"); //设置ICON的图标
   bool chk=ui->chkBoxListEditable->isChecked();//是否可编辑,界面组件tab1上的QCheckBox对象

   ui->listWidget->clear(); //清除项
   for (int i=0; i<10; i++)
   {
       QString name=QString::asprintf("Item %d",i+1); // 10个项的名称
       aItem=new QListWidgetItem(); //新建一个项

       aItem->setText(name); //设置文字标签
       aItem->setIcon(aIcon);//设置图标
       aItem->setCheckState(Qt::Checked); //设置为选中状态
       if (chk) //可编辑, 设置flags
           // 含义依次时可被选择、可被编辑、用户可以选择check属性、用户可以与项目交互
           aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
       else//不可编辑, 设置flags
           aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
       ui->listWidget->addItem(aItem); //增加一个项
   }
}

// 2. 清除列表, 2个QAction,动作一致,调用listWidget的自带槽函数clear(); +4
void MainWindow::on_actListClear_triggered(){ // toolBar上的
    ui->listWidget->clear(); //清除项
}
void MainWindow::on_actionListClear_triggered(){// menuBar上的
    ui->listWidget->clear(); //清除项
}

// 3.插入项,  2个QAction,动作一致,调用公共函数actListInsertCommon(); +6
void MainWindow::on_actListInsert_triggered(){ // toolBar上的
    this->actListInsertCommon();
}
void MainWindow::on_actionListInsert_triggered(){// menuBar上的
    this->actListInsertCommon();
}
void MainWindow::actListInsertCommon(){
    //插入一个项
     QIcon aIcon;
     aIcon.addFile(":/icons/check2.ico"); //图标

     bool chk=ui->chkBoxListEditable->isChecked(); //是否可编辑

     QListWidgetItem* aItem=new QListWidgetItem("New Inserted Item"); //创建一个项
     aItem->setIcon(aIcon);//设置图标
     aItem->setCheckState(Qt::Checked); //设置为checked,选中状态
     if (chk) //设置标记
         aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
     else
         aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);

     ui->listWidget->insertItem(ui->listWidget->currentRow(),aItem); //在当前行的上方插入一个项
}

// 4.添加项,2个QAction,动作一致,调用公共函数actListAppendCommon(); +8
void MainWindow::on_actListAppend_triggered(){ // toolBar上的
    this->actListAppendCommon();
}

void MainWindow::on_actionListAppend_triggered(){// menuBar上的
    this->actListAppendCommon();
}
void MainWindow::actListAppendCommon(){//增加一个项
    QIcon aIcon;
    aIcon.addFile(":icons/check2.ico"); //设定图标

    bool chk=ui->chkBoxListEditable->isChecked();//是否可编辑

    QListWidgetItem* aItem=new QListWidgetItem("New Added Item"); //创建一个Item
    aItem->setIcon(aIcon); //设置图标
    aItem->setCheckState(Qt::Checked); //设置为checked
    if (chk) //设置标志
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);

    ui->listWidget->addItem(aItem);//增加一个项
}

// 5.删除项,2个QAction,动作一致,调用公共函数actListDeleteCommon(); +10
void MainWindow::on_actListDelete_triggered(){// toolBar上的
    this->actListDeleteCommon();
}
void MainWindow::on_actionListDelete_triggered(){// menuBar上的
    this->actListDeleteCommon();
}
void  MainWindow::actListDeleteCommon(){
    //删除当前项
   int row=ui->listWidget->currentRow();//当前行
   QListWidgetItem* aItem=ui->listWidget->takeItem(row); //移除指定行的项，但不delete
   delete aItem; //需要手工删除对象

   // 需要注意的是takeItem函数 QListWidgetItem *QListWidget::takeItem(int row)
   // 从列表小部件的给定行中删除并返回项；否则返回 0
   // 从列表小部件中删除的项目不会由 Qt 管理，需要手动删除
}
// 6. 全选
void MainWindow::on_actSelALL_triggered() // tabWidget上的 +11
{
   int cnt=ui->listWidget->count();//项个数
   for (int i=0; i<cnt; i++)
   {
       QListWidgetItem *aItem=ui->listWidget->item(i);//获取每个项
       aItem->setCheckState(Qt::Checked);//设置为选中状态
   }
}
// 7. 全不选
void MainWindow::on_actSelNone_triggered()// tabWidget上的 +12
{
    int i,cnt;
    QListWidgetItem *aItem;

    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; i++)
    {
        aItem=ui->listWidget->item(i);//获取每个项
        aItem->setCheckState(Qt::Unchecked);//不选
    }
}
// 8. 反选
void MainWindow::on_actSelInvs_triggered()// tabWidget上的 +13
{
    // 反选的意思就是,原来选中的不选中,原来不选中的选中
    int i,cnt;
    QListWidgetItem *aItem;

    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; i++)
    {
        aItem=ui->listWidget->item(i);//获取每个项
        if (aItem->checkState()!=Qt::Checked)
            aItem->setCheckState(Qt::Checked);
        else
            aItem->setCheckState(Qt::Unchecked);
    }
}

// 9.关闭窗口,2个QAction,这里关联的是自带的槽函数close() +15
void MainWindow::on_actQuit_triggered() { // toolBar上的
    // 其实ui界面已经联系了,不手动添加也是ok的
    // 但注意手动添加也不是this->ui->widget->close();而是this->close();
    // this->close();
}
void MainWindow::on_actionClose_triggered() {// menuBar上的
    // ui界面没有进行联系,需要手动联系
    this->close();
}
// 10. 重启窗口
void MainWindow::on_actionReboot_triggered() { // menuBar上的 +16
    this->close();
    QThread::msleep(1000);
    this->show();
}
// 11. 初始化文本
void MainWindow::on_actioninitText_triggered(){ // menuBar上的
    this->ui->textEdit->setText(QString("Hello C++! Hello Qt.5.9.9! Hello Python! Hello PyQt5!\n"
                                        "It's my pleasure to use such a tool to develop interfaces."));

    const QMetaObject *metaobject = this->ui->plainTextEdit->metaObject(); // 获取QPlainTextEdit的元信息
    int count = metaobject->propertyCount(); // QPlainTextEdit具备的属性个数
    this->ui->plainTextEdit->setPlainText(QString::asprintf("QPlainTextEdit's propertites count is %d.",count));
    this->ui->plainTextEdit->appendPlainText(QString("Here are the 10 property names and their values:"));
    for (int i = 60; i < 70; ++i) {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant value = this->ui->plainTextEdit->property(name);
        this->ui->plainTextEdit->appendPlainText(QString("name = ")+QString(name)+QString(" <=> value = ")+value.toString());
    }
}
// 12. 清除文本
void MainWindow::on_actionclearText_triggered(){ // menuBar上的
    this->ui->textEdit->clear();
    this->ui->plainTextEdit->clear();
}
// 13. 保存文本
void MainWindow::on_actionsaveText_triggered(){ // menuBar上的 +19
    if (openFileDialog() == false || this->filePath == ""){
        this->ui->textEdit->clear();
        this->ui->plainTextEdit->clear();
        this->ui->plainTextEdit->appendPlainText("Failed to save text!");
        return;
    }
    QFile myfile(this->filePath);
    if (myfile.open(QIODevice::ReadWrite| QIODevice::Append|QIODevice::Text)){
         QDateTime curtime =QDateTime::currentDateTime();
        this->ui->plainTextEdit->appendPlainText("File opened successfully!");
        this->ui->plainTextEdit->appendPlainText("Text saved successfully!");
        this->ui->plainTextEdit->appendPlainText("The saved file path is "+this->filePath);
         myfile.write(curtime.toString(Qt::DateFormat::SystemLocaleDate).toStdString().c_str()) ;// 写入时间
         myfile.write("\n");
         myfile.write(ui->textEdit->toPlainText().toStdString().c_str()) ;
         myfile.write("\n");
         myfile.write(ui->plainTextEdit->toPlainText().toStdString().c_str()) ;
//        QTextStream out(&myfile); //这种写法也是ok的
//        out <<(ui->textEdit->toPlainText().toStdString().c_str());// 写入文本
//        out << (ui->plainTextEdit->toPlainText().toStdString().c_str());// 写入文本
        myfile.write("\n\n");
        this->ui->textEdit->clear();
        this->ui->plainTextEdit->clear();
    }
    this->ui->plainTextEdit->appendPlainText("File opened successfully!");
    this->ui->plainTextEdit->appendPlainText("Text saved successfully!");
    this->ui->textEdit->setText("The saved file path is "+this->filePath);
}
bool MainWindow:: openFileDialog()
{
    // 打开文本选择框,选择文件并返回路径
    QString path = QFileDialog::getOpenFileName(nullptr,QString::fromUtf8("选择文件"),"",QObject::tr("txt(*.txt)"));
    if (path == ""){
        QMessageBox::information(this,QString::fromUtf8("错误"),QString::fromUtf8("文件路径不存在"),"ok");
        return false;
    }
    this->filePath = path; // 保存好路径
    return true;
}
// 14.菜单弹出
void MainWindow::on_actSelPopMenu_triggered() // toolBar上的 +20
{
    // 此动作的triggered()信号可以关联任何其他动作trigger()信号
    // 这里关联的实际是"全选"按钮的trigger()信号
    // 在UI界面已经设计好,所以这里不再需要代码动态连接
    // 即此动作没有直接执行,而是动作连接另一个动作来执行
}

// 以下是一些除了QAction以外的额外槽函数响应,用于补充界面的其他组件细节
// 1. listWidget提供快捷右键菜单的槽函数,也就是右击listWidget组件时的响应
// customContextMenuRequested信号是继承自QWidget的
void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<<"the mouse pos is ("<<pos.x()<<","<<pos.y()<<")";
    // Q_UNUSED(pos);

    // 一般右击时习惯会产生1个菜单项,这个菜单就是需要我们动态创建的
    QMenu* menuList=new QMenu(this); //创建菜单

    //添加Actions创建菜单项
    menuList->addAction(ui->actListIni); // 初始化列表
    menuList->addAction(ui->actListClear); // 清除列表
    menuList->addAction(ui->actListInsert); // 插入项
    menuList->addAction(ui->actListAppend); // 添加项
    menuList->addAction(ui->actListDelete); // 删除项
    menuList->addSeparator(); // 添加分隔符
    menuList->addAction(ui->actSelALL); // 全选
    menuList->addAction(ui->actSelNone); // 全不选
    menuList->addAction(ui->actSelInvs); // 反选
    menuList->addAction(ui->actQuit); // 关闭窗口
    menuList->addAction(ui->actionReboot);// 重启窗口
     menuList->addAction(ui->actioninitText); // 初始化文本
     menuList->addAction(ui->actionclearText); // 清空文本
     menuList->addAction(ui->actionsaveText); // 保存文本

    menuList->exec(QCursor::pos()); //在鼠标光标位置显示右键快捷菜单
    delete menuList; //手工创建的指针必须手工删除
}
// 2. 工具箱toolBox的联动功能
void MainWindow::on_toolBox_currentChanged(int index){ // toolBox上的
    ui->tabWidget->setCurrentIndex(index);//ToolBox当前页与tabWidget的当前页联动
}
// 3.当前项变化后,把项的名称反馈给界面组件
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *next)
{
    //listWidget当前选中项发生变化
    QString str;
    if (current != nullptr) //需要检测变量指针是否为空
    {
    if (next==nullptr)  //需要检测变量指针是否为空
      str="currentItem is "+current->text();
    else
      str="nextItem is "+next->text()+"; currentItem is "+current->text();
    ui->editCutItemText->setText(str);
    }
}
// 4.界面组件的"可编辑"复选框
void MainWindow::on_chkBoxListEditable_clicked()
{
    //可编辑 QCheckBox的响应代码， 设置所有项是否可编辑
       int i,cnt;
       QListWidgetItem *aItem;

       cnt=ui->listWidget->count();//项的个数
       for (i=0; i<cnt; i++)
       {
           aItem=ui->listWidget->item(i);//获得一个项
           if (ui->chkBoxListEditable->isChecked()) //可编辑
               aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
           else
               aItem->setFlags(Qt::ItemIsSelectable |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
       }
}
// 5.界面组件的"重启"复选框reboot和QPushButton组件
void MainWindow::on_btnclose_clicked()
{
    this->close();
    if (this->ui->reboot->isChecked()){
        QThread::msleep(1000);
        this->show();
    }
}
// 6.日期组件反馈给textLabelLineEdit文本组件、进度条组件和spinBox组件
// 以及DateTimeEdit组件、LCD组件
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
   // qDebug()<< date.toString("yyyy-MM-dd MMMM dddd"); // "2022-06-20 六月 星期一"
    this->ui->textLabelLineEdit->setText(date.toString("yyyy-MM-dd dddd"));
    this->ui->spinDateBox->setValue(date.day()); // 仅用于展示月份和天数
    this->ui->spinMonthBox->setValue(date.month());

    // 进度条
//    qDebug()<<"当年有多少天? "<<date.daysInYear();
//    qDebug()<<"今天是第几天? "<<date.dayOfYear();
    this->ui->progressBar->setValue(date.dayOfYear());

    // DateTimeEdit组件
    QTime curtime = QTime::currentTime();
    this->ui->dateTimeEdit->setDateTime(QDateTime(date,curtime));

    // LCD组件
    this->ui->lcdHourNumber->display(curtime.hour());
    this->ui->lcdMinuteNumber->display(curtime.minute());
    this->ui->lcdSecondNumber->display(curtime.second());
}
// 7.恢复日期时间按钮
void MainWindow::on_btnRecoveryDate_clicked()
{
    QDateTime datetime = QDateTime::currentDateTime();
    // 文本组件、进度条和spinbox组件
    this->ui->textLabelLineEdit->setText(datetime.toString("yyyy-MM-dd dddd hh::mm::ss.zzz"));
    this->ui->spinDateBox->setValue(datetime.date().day());
    this->ui->spinMonthBox->setValue(datetime.date().month());
    this->ui->progressBar->setValue(datetime.date().dayOfYear());
    // DateTimeEdit组件
    this->ui->dateTimeEdit->setDateTime(datetime);
    // lcd组件
    this->ui->lcdHourNumber->display(datetime.time().hour());
    this->ui->lcdMinuteNumber->display(datetime.time().minute());
    this->ui->lcdSecondNumber->display(datetime.time().second());
}
// 8.QDial的槽函数
void MainWindow::on_dial_sliderMoved(int position)
{
    // 反馈到状态栏中
    this->statusBar()->showMessage(QString::asprintf("now the qdial's position is %d",position));
}
