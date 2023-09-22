#include "../../inc/login/loginnext.h"

LoginNext::LoginNext()
{
    mBtn = new PushButton(tr("进入主界面"));
    mMachineInfo = new Label(tr("机器信息: 请先连接机器..."));

#ifdef SCREEN_2560X1600
   mBtn->setMinimumHeight(ComponentMaxHeight);
   mBtn->setMinimumWidth(ComponentMinWidth-100);
#endif

    auto p = mMachineInfo->palette();
    p.setColor(QPalette::WindowText,Qt::white); //不是Text 可以设置文字颜色是白色
    mMachineInfo->setPalette(p);
    addWidget(mMachineInfo);
    addStretch();
    addWidget(mBtn);
    connect(mBtn,&QPushButton::clicked,this,[=]{emit clicked();});
}

void LoginNext::updateMachineInfo(bool isConnected)
{
    isConnected?mMachineInfo->setText(tr("机器信息: 主机已连接")):
            mMachineInfo->setText(tr("机器信息: 主机已断开"));
}
