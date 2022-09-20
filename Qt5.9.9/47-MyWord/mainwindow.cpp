#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow), mSignalMapper(new QSignalMapper(this))
{
        ui->setupUi(this);
        init_ui();
        init_connections();
}

void MainWindow::init_ui()
{
     // 初始化3个QComboBox组件
     QList<int> sizes = QFontDatabase::standardSizes();
     QStringList sizeString;
     for(auto size : sizes)
     {
        sizeString << QString::number(size);
     }
      ui->sizeComboBox->addItems(sizeString);

      ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(
              QString::number(this->font().pointSize())
      )); // 跟随当前窗口字体大小

      QFontDatabase base;

      //qDebug()<<base->families();
      ui->fontComboBox->addItems(base.families(QFontDatabase::Any));
      ui->fontComboBox->setCurrentText(this->font().family()); // 跟随窗口字体风格

      // 各对齐方式功能项加入同一个菜单项组，这样程序运行的任一时刻用户能且只能选中其中一项
      QActionGroup *alignGroup = new QActionGroup(this);
      alignGroup->addAction(ui->actLeft);
      alignGroup->addAction(ui->actCenter);
      alignGroup->addAction(ui->actRight);
      alignGroup->addAction(ui->actJusitify);
      ui->actLeft->setChecked(true);
}

void MainWindow::init_connections()
{
    // 字体、字号、段落标记的QComboBox的下拉项变化
    connect(ui->fontComboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated),this,
          [=](const QString& fmly){
                  QTextCharFormat fmt;
                  fmt.setFontFamily(fmly);
                  if(activateTextWindow())
                      activateTextWindow()->setDocFormat(fmt);
          }
    );
    connect(ui->sizeComboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated),this,
          [=](const QString& size)
          {
              qreal pointSize = size.toFloat();
              if (size.toFloat() > 0)
              {
                  QTextCharFormat fmt;
                  fmt.setFontPointSize(pointSize);
                  if(activateTextWindow())
                      activateTextWindow()->setDocFormat(fmt);
              }
          }
    );
    connect(ui->bulletComboBox,static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),this,
          [=](int idx)
          {
              if (activateTextWindow()) activateTextWindow()->setDocParagraphStyle(idx);
          }
    );
    // mdiarea区域有子窗口处于激活状态时就发出subWindowActivated信号
    // 如果window=0就说明没有活动窗口,刷新菜单动作的使能
    connect(ui->mdiArea,static_cast<void (QMdiArea::*)(QMdiSubWindow*)>(&QMdiArea::subWindowActivated),this,
          [=](QMdiSubWindow * window){
                  // hasChild为true才能继续执行下方的文件/窗口操作,和一个编辑菜单的粘贴操作
                  bool hasChild = (activateTextWindow() != Q_NULLPTR);
                  setFileMenuActEnabled(hasChild);
                  setWindowMenuActEnabled(hasChild);
                  ui->actPaste->setEnabled(hasChild);
                  // 有选中文本才能执行格式菜单的动作和编辑菜单的复制、剪切操作
                  bool hasSelected = (hasChild && activateTextWindow()->textCursor().hasSelection()); // 窗口内鼠标有选中的文本
                  setFormatMenuActEnabled(hasSelected);
                  ui->actCopy->setEnabled(hasSelected);
                  ui->actCut->setEnabled(hasSelected);
                  Q_UNUSED(window);
          }
    );

    // 还要绑定映射器的mapped信号和mdiarea设置当前活动窗口的连接关系
    connect(mSignalMapper,static_cast<void (QSignalMapper::*)(QWidget*)>(&QSignalMapper::mapped),this,
          [=](QWidget*wnd)
          {
                if (!wnd) return; // 如果映射来的子窗口指针为空就返回
                // 借助mdiarea的函数实现设置当前的活动的窗口
                ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(wnd));
           }
    );
    addSubWindowActForWindowMenu();

    // 窗口菜单显示时更新菜单选项
    connect(ui->menuWindow, &QMenu::aboutToShow, this, &MainWindow::addSubWindowActForWindowMenu);
}












