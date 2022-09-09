目前设计的一些注意点：

1、QToolButton的trigger信号是在关联的动作触发后才发射，这样tool.cpp关联triggered信号是不对的
会发现点击按钮没有反应，但是点击菜单有反应，因为菜单直接调用了动作，触发了action的triggered信号
紧接着又会触发toolbutton的triggered信号，所以切记不能递归调用
后来查到QToolButton的父类也就是QAbstractButton是有clicked信号，可以用，所以绑定了clicked信号
在clicked信号的槽函数下是可以直接调用action触发的
void MainWindow::on_SystemSettingsTbn()
{
    SystemSettingsAct->trigger(); //事先不关联动作,使用手动的方式触发动作
}

为啥要这么麻烦，因为QToolButton实际上点击时会弹出菜单，考虑到用户的感觉，对于主界面的9个按钮
最好就像QPushButton那样点击一下就调用功能，而不是弹出菜单还要选择，并且QToolButton如果只关联了1个QAction
就没必要使用菜单的模式，但是又想用到QToolButton的setAutoRaise(true)功能，所以没使用QPushButton
这样的话为了产生QPushButton的使用效果，就在create.cpp中的createToolButtons()函数禁用下拉菜单样式
同时菜单模式除了About以外都注释掉，因为没有菜单也就没必要设置
setStyleSheet("QToolButton::menu-indicator{image:none;}");
setPopupMode(QToolButton::InstantPopup);
------------------------------------------------------------------------------------------------------------------------------------------------------------

2. 主窗口-子窗口-堆叠窗口的数据传递

(2.1) 前向传递
主窗口有私有属性来保存子窗口设置的参数 (可以在setting.cpp的on_BasicSettingsAct()函数中的(ret == QDialog::Accepted)判断后更新数据,也可以借助槽函数on_basicSettings响应)
             <-----子窗口的公共函数settings()和槽机制basicSettings()均可以传递数据(在点击确定按钮时更新和发送数据)
                                <-----同理堆叠窗口依靠组件的信号绑定槽函数来更新设置的信息mSettings

因为子窗口和堆叠窗口定义的struct都是聚合类型，所以默认的operator=函数已足够无需重定义
同时为了避免未初始化问题在堆叠窗口的struct类型定义了默认构造函数，而子窗口的struct因为会自动调用堆叠窗口的构造函数所以不用再定义默认构造

现在因为子窗口并不是一直驻留后台，即不是全局的子窗口指针，而是在setting.cpp的on_BasicSettingsAct()中new出来
这样原来用户设置的参数就会丢失，例如用户设置完以后再次打开设置串口应当是保留上次状态的，所以必须有一个主窗口到子窗口再到堆叠窗口的数据传递过程

如果是首次启动主界面，那么主窗口保存的数据必然是不能未经初始化就传递给子窗口的
这也是为何在上边提到提供堆叠窗口的struct的一个默认构造防止出现问题，默认都是0参数和CV工作模式，这样传递不会出现问题

(2.2) 反向传递
反向传递的时候就需要子窗口和堆叠窗口都提供一个函数为setSettings()

主窗口的数据mainwindow::mSettings ------> on_BasicSettingsAct()函数中new出一个子窗口的dialog后(先经过构造函数,内部的mCommonSettings是个全新的默认设置)，然后调用dialog->setSettings()
                -------->   dialog->setSettings()就将数据传递给了子窗口，子窗口的mCommonSettings还是默认设置，故在dialog->setSettings内调用mCommonSettings->setSettings()更新数据
                                ------> mCommonSettings->setSettings()同理把数据给了堆叠窗口，在该函数内部把数据更新
------------------------------------------------------------------------------------------------------------------------------------------------------------
