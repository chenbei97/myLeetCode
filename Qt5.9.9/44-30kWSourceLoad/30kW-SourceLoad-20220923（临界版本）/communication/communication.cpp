#include "communication/communication.h"

Communication::Communication(QWidget * parent) :QDialog(parent)
{
          setFont(QFont("Times New Roman",12));
          resize(600,200);
          setWindowFlag(Qt::Window); // 设置window属性就不会总是让监控界面在前了
          setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
          setWindowFlag(Qt::WindowMinimizeButtonHint);
          setWindowModality(Qt::NonModal);
          Qt::WindowFlags flags = windowFlags();
          setWindowFlags(flags^Qt::WindowCloseButtonHint
                  ^Qt::WindowContextHelpButtonHint); // 关闭按钮去除防止用户不暂停就直接关闭导致线程还在运行却无法停止
          setWindowIcon(QIcon(":/images/communication.png"));

          mainWindow = (MainWindow *) parentWidget();
          mPort = new QSerialPort;
          mFixedQueryThread = new SerialFixedQueryThread;
          mPort->moveToThread(mFixedQueryThread); // 这个是必要的!,在这里移动即可
          mFixedQueryTimer = new QTimer;
          mFixedQueryTimer->setInterval(mFixedQueryTime);

          mSetController = new SerialVariableSetting(mPort);
          mSetControllerThread = new QThread;
          mSetController->moveToThread(mSetControllerThread); // 同理,设定任务也要挪到子线程执行

          initUI();
          initConnections();
}

