#include "asyncTerminal.h"
#include "ui_asyncTerminal.h"
#include <QScrollBar>

void asyncTerminal::on_textEditor_eventInfomation(const QString &s)
{
        ui->textMonitor->appendPlainText(s);
        QScrollBar * bar = ui->textMonitor->verticalScrollBar();
        bar->setValue(bar->maximum());//因为是不可编辑的,所以需要自动更新滚动条
}

void asyncTerminal::on_textEditor_forwardKeyInput(const QByteArray& s)
{
        mutex.lock();
        this->mPort->write(s); // 串口写入从textEditor获取的键盘输入
        mutex.unlock();
}
