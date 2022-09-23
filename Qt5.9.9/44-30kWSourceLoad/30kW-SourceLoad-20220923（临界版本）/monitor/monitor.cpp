#include "monitor/monitor.h"

Monitor::Monitor(WORKMODE  workmode,QWidget *parent) : QMainWindow(parent)
{
        resize(1200,800);
        setFont(QFont("Times New Roman",12)); //格式和字体要先初始化,然后基于此时窗口初始化布局,放在后头就会错误
        setWindowIcon(QIcon(":/images/monitorInterface.png"));

        mWorkMode = workmode;

        ConnectState = new QLabel(tr("连接状态：")); // 共用的,无论USB还是TCP或其它
        MessageRequestState = new QLabel(tr("消息请求状态：")); // 同理
        MessageReceiveState = new QLabel(tr("消息回复状态：")); // 同理
        MessageSetState = new QLabel(tr("设定状态：暂无设定角色")); // 同理
        ConnectState->setMinimumSize(150,20);
        MessageRequestState->setMinimumSize(200,20);
        MessageReceiveState->setMinimumSize(200,20);
        MessageSetState->setMaximumSize(250,20);
        statusBar()->addWidget(ConnectState);
        statusBar()->addWidget(MessageRequestState);
        statusBar()->addWidget(MessageReceiveState);
        statusBar()->addWidget(MessageSetState);

        QString title;
        if (workmode == WORKMODE::CV)
        {
              initCVUI();
              title = tr("监控界面(CV模式)");
        }
        else {
              initCCUI();
              title = tr("监控界面(CC模式)");
        }
        initConnections();
        setWindowTitle(title);
}

WORKMODE Monitor::workMode() const
{
      return this->mWorkMode;
}

