#include <setting/workmodedialog.h>

WorkModeDialog::WorkModeDialog(WORKMODE mode,QWidget * parent) :QDialog(parent)
{
    QPalette pal = palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/images/monitormode.jpg")));
    setPalette(pal);
    setWindowIcon(QIcon(":/images/monitorSettings.png"));
    setFont(QFont("Times New Roman",12));
    resize(450,120);
    setWindowTitle(tr("工作模式设置"));
    //setWindowModality(Qt::ApplicationModal);
    //setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//不能更改大小
    //setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);//添加最大最小化按钮

    QLabel * label = new QLabel(tr("请选择工作模式："));
    QRadioButton * ccBtn = new QRadioButton(tr("CC模式"));
    QRadioButton * cvBtn = new QRadioButton(tr("CV模式"));
    QPushButton * okBtn = new QPushButton(tr("确定"));
    QPushButton * cancelBtn = new QPushButton(tr("取消"));
    //QGroupBox * modeBox = new QGroupBox;

    QHBoxLayout * radiolayout = new QHBoxLayout;
    isCVMode = mode==WORKMODE::CV?true:false; // 主窗口的mainWorkMode不是每次都需要new出来,会保持上次的设置状态
    cvBtn->setChecked(isCVMode); // 构造函数只会调用1次,mode只起1次作用
    ccBtn->setChecked(!isCVMode); // 如果需要每次都new那么mode会起作用,mode使用外部的mWorkMode传递
    radiolayout->addWidget(cvBtn);
    radiolayout->addWidget(ccBtn);
   // modeBox->setAlignment(Qt::AlignCenter);
    //modeBox->setStyleSheet("border:none");
//      modeBox->setStyleSheet("QGroupBox{border: 1px solid black;"
//                             "border-radius: 0px;"
//                             "margin-top: 0ex;}");
//      modeBox->setLayout(radiolayout); // 使用容器可以让2个radiobtn互斥

    QHBoxLayout * hlayout1 = new QHBoxLayout; //不使用容器也可以互斥,groupbox弃用,因为设置无边框会导致字体变小解决不了
    hlayout1->addWidget(label);
    hlayout1->addWidget(cvBtn);
    hlayout1->addWidget(ccBtn);

    QHBoxLayout * hlayout2 = new QHBoxLayout;
    hlayout2->addStretch();
    hlayout2->addWidget(okBtn);
    hlayout2->addWidget(cancelBtn);

    QGridLayout * layout = new QGridLayout;
    layout->addLayout(hlayout1,0,0,1,1,Qt::AlignCenter);
    layout->addLayout(hlayout2,1,0,1,1,Qt::AlignCenter);
    setLayout(layout);

    connect(okBtn,&QPushButton::clicked,this,[=]{
        isCVMode = cvBtn->isChecked();// 把信息发出去,mainSettings的mTableSizeDlg接收
        WORKMODE mode = isCVMode?WORKMODE::CV:WORKMODE::CC;
        emit workModeChanged(mode);
        accept();
    });
    connect(cancelBtn,&QPushButton::clicked,this,[=]{reject();});
}
