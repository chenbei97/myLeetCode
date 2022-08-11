#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>

//如果定义了下边这个宏那么debug版本输出到终端release版本的时候输出到日志文件
//#define _DEBUG
// 因为debug版本也想写入日志,所以这里不定义它

namespace myLOG
{

    static int mLogLevel = 0; // 默认调试级别为debug,所有信息都会写入日志文件
    static QString mLogFile = QString("%1.log").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss")); // 保存文件名
    QMutex mLogMutex; // 线程保护

    void myMessageOutput(QtMsgType type , const QMessageLogContext &context , const QString &msg)
    {
            if (type < mLogLevel) // 小于指定级别的信息将被忽略,这里type>=0,而mLogLevel=0,所以if永远不会成立
            {
                return;
            }

            QString mLogInfo; // 要打印的信息
            switch (type) // enum QtMsgType { QtDebugMsg, QtWarningMsg, QtCriticalMsg, QtFatalMsg, QtInfoMsg, QtSystemMsg = QtCriticalMsg };
            {
                case QtDebugMsg:
                    mLogInfo = QString("%1 [Debug]: ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                    break;
                case QtWarningMsg:
                    mLogInfo = QString("%1 [Warning]: ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                    break;
                case QtCriticalMsg:
                    mLogInfo = QString("%1 [Critical]: ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                    break;
               case QtFatalMsg:
                      mLogInfo = QString("%1[Fatal]:").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                      abort();
                case QtInfoMsg:
                    mLogInfo = QString("%1 [Info]: ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                    break;
            }

            mLogInfo += QString(context.file) + QString(context.line) + QString("%1").arg(msg); // 把log的文件信息,所在行信息和消息写进来

            //为了线程安全,因为要写入文本
            mLogMutex.lock();
            QFile outFile(mLogFile); // 文件名绑定到目录
            outFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text); //打开
            QTextStream ts(&outFile); // 绑定到文本输出流
            ts << mLogInfo << endl; // 把日志信息写入文本
            outFile.close();
            mLogMutex.unlock();
    }

    void logInit(QString logFile = "", int logLevel = 0)
    {
        #ifndef _DEBUG
            if ((logLevel < 0) || (logLevel > 4)) // 如果参数范围有误使用默认级别0
            {
                mLogLevel = 0;
            }
            else
            {
                mLogLevel = logLevel; // 否则使用指定的级别
            }

            if (!logFile.isEmpty()) // 如果指定了输出文件名就用默认的
            {
                mLogFile = logFile; // 静态对象可以直接更改
            }
            /*
                  安装之前定义的 Qt 消息处理程序。返回指向前一个消息处理程序的指针。
                  消息处理程序是一个打印调试消息、警告、严重和致命错误消息的函数。
                  Qt 库（调试模式）包含数百条在发生内部错误（通常是无效的函数参数）时打印的警告消息。
                  除非在编译期间设置了 QT_NO_WARNING_OUTPUT 和/或 QT_NO_DEBUG_OUTPUT
                  否则 Qt 内置发布模式也包含此类警告。如果您实现自己的消息处理程序，您可以完全控制这些消息。
                  默认消息处理程序将消息打印到 X11 下的标准输出或 Windows 下的调试器。如果是致命消息，应用程序将立即中止。
                只能定义一个消息处理程序，因为这通常在应用程序范围内完成以控制调试输出。
                  要恢复消息处理程序，请调用 qInstallMessageHandler(0)。
            */
            qInstallMessageHandler(myMessageOutput);
        #endif
    }
} // end namespace myLOG
#endif // LOG_H
