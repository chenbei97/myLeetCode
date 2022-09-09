#include "mainwindow.h"
#include "communication/communication.h"
#include <QDialog>
#include <QRadioButton>
#include <QMessageBox>

// 启动工作模式设置界面
void MainWindow::on_MonitorSettingsAct() // 设置工作模式的窗口
{
      QDialog * mMonitorSettings = new QDialog;
      mMonitorSettings->setWindowIcon(QIcon(":/images/monitorSettings.png"));
      mMonitorSettings->setFont(QFont("Times New Roman",12));
      mMonitorSettings->resize(450,120);
      mMonitorSettings->setWindowTitle(tr("监控模式设置"));
      //mMonitorSettings->setWindowModality(Qt::ApplicationModal);
      //mMonitorSettings->setWindowFlag(Qt::WindowStaysOnTopHint);
      mMonitorSettings->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//不能更改大小
      //mMonitorSettings->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);//添加最大最小化按钮

      QLabel * label = new QLabel(tr("请选择工作模式："));
      QRadioButton * ccBtn = new QRadioButton(tr("CC模式"));
      QRadioButton * cvBtn = new QRadioButton(tr("CV模式"));
      QPushButton * okBtn = new QPushButton(tr("确定"));
      QPushButton * cancelBtn = new QPushButton(tr("取消"));
      //QGroupBox * modeBox = new QGroupBox;

      QHBoxLayout * radiolayout = new QHBoxLayout;
      bool state = mWorkMode==WORKMODE::CV?true:false;
      cvBtn->setChecked(state); // 这是为了再次点击设置时能够和上次设置保持一致
      ccBtn->setChecked(!state);
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
      mMonitorSettings->setLayout(layout);

      connect(okBtn,&QPushButton::clicked,this,&MainWindow::on_MonitorSettingsOkBtn);
      connect(cancelBtn,&QPushButton::clicked,this,&MainWindow::on_MonitorSettingsCancelBtn);
      int ret = mMonitorSettings->exec();
      if (ret == QDialog::Accepted)// 如果点击的是确定按钮
      {
           bool checked = cvBtn->isChecked(); // 获取CV的state
           this->mWorkMode = checked?WORKMODE::CV: WORKMODE::CC;
      }
      // 如果是取消按钮,保持原有的状态即可
}

// 启动监控界面
void MainWindow::on_MonitorInterfaceAct()
{
      int ret = QMessageBox::information(this,tr("消息"),tr("是否已设置监控模式?(默认CV模式)"),
                                                                QMessageBox::Yes,QMessageBox::No);
      if (ret == QMessageBox::No) // 如果没有设置就弹出设置的界面
      {
            on_MonitorSettingsAct();
      }
       if (mainMonitor->workMode() != this->mWorkMode) // 说明切换了工作模式
       {
            delete mainMonitor;
            mainMonitor = new Monitor(mWorkMode);//新的工作界面
            initCommunicationToMonitorConnections(); // 新的界面要绑定好连接
            initMonitorToCommunicationConnections(); // 信号是双向的
       }
      mainMonitor->showNormal();
      //mainMonitor->setAttribute(Qt::WA_DeleteOnClose);
}

// 工作模式选择确定
void MainWindow::on_MonitorSettingsOkBtn()
{
      QPushButton * pushbutton = qobject_cast<QPushButton*>(sender()); // 发动信号的btn
      QDialog * dlg = qobject_cast<QDialog *>(pushbutton->parent()); // 获取按钮的父类窗口也就是new出来的dlg
      dlg->accept(); // 发送ACCEPTED信号
}

// 工作模式选择取消
void MainWindow::on_MonitorSettingsCancelBtn()
{
      QPushButton * pushbutton = qobject_cast<QPushButton*>(sender()); // 发动信号的btn
      QDialog * dlg = qobject_cast<QDialog *>(pushbutton->parent()); // 获取按钮的父类窗口也就是new出来的dlg
      dlg->reject(); // 发送REJECTED信号
}
