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

3. 监控界面 - 通讯界面 - 串口固定查询线程、串口设定查询线程的数据传递

(3.1) 前向传递
(3.1.1) 监控界面信号=>mainwindow_connect.cpp完成绑定=>通讯界面槽函数
监控界面的组件(spinbox)值改变时触发对应的槽函数，在槽函数内拿到当前的值只做1个转 /发信号的处理
一共10个信号,这些信号会与通讯界面的对应槽函数绑定，那么通讯界面就拿到了这些值再进一步传递给串口设定查询线程
信号和槽的绑定在mainwindow_connect.cpp中的函数void MainWindow::initMonitorToCommunicationConnections()完成
因为主窗口才同时有监控界面和通讯界面的全局指针mainMonitor和mianCommunication，这样可以完成绑定
void powSourceChanged(QByteArray value);
void powLoadChanged(QByteArray value);
void resSourceChanged(QByteArray value);
void resLoadChanged(QByteArray value);
void voltChanged(QByteArray value);
void currSourceChanged(QByteArray value);
void currLoadChanged(QByteArray value);
void currChanged(QByteArray value);
void voltSourceChanged(QByteArray value);
void voltLoadChanged(QByteArray value);
通讯界面的communication_slot_from_monitor.cpp定义了和这10个信号绑定的槽函数
(3.1.2) 通讯界面信号 => communication_connect.cpp => 固定查询线程槽函数
void sendInfo(SETTINGVARIABLE role,QByteArray request);
在communication_slot_from_monitor.cpp中使用,通讯界面=>设定查询告知设定的角色和要设定的值
serial_fixedquery_thread.cpp的void SerialFixedQueryThread::on_SendInfo(SETTINGVARIABLE role,QByteArray request)响应
然后固定查询线程会读取数据，如果数据不包含分号就说明是设定查询的回复，那么就把数据、发送的角色一起发出去，交给反向传递流程
如果数据包含分号，说明是固定查询的回复，同样直接转发交给反向传递流程，但是不需要指定角色

(3.2) 反向传递
(3.2.1) 固定查询线程 => 通讯界面
反向传递在设定查询线程没有任何信号，因为串口资源只有1个，且在固定查询线程使用
所以固定查询依据收到的数据是否包含分号来传递2种信号，同时还有超时、串口错误等信号
之后就是在communication_slot_from_fixedquery.cpp处理这些来自固定查询线程的信号
(3.2.2) 通讯界面 => 监控界面
通讯界面只是做一些必要的处理，主要还是作转发工作，定义了同名信号转发
void availableFixedQueryData(const QList<QByteArray> & values); //  固定查询-数据VAPR =>监控界面
void errorCode(TIMEOUTCODE code); // 固定查询-超时错误 =>监控界面
void errorCode(SERIALERROR code); // 固定查询-串口错误 =>监控界面
void errorCode(bool failed,SETTINGVARIABLE role) ; // 设定查询-设定成功或失败 =>监控界面
然后在监控界面有对应的槽函数响应上述4个信号，信号和槽函数的连接在mainwindow_connect.cpp内完成















