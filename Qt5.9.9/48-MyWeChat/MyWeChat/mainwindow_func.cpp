#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::getLocalMsg()
{
    QList<QHostAddress> addrlist = QNetworkInterface::allAddresses();
    foreach (QHostAddress addr, addrlist)
    {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol) return addr.toString();
    }
    return 0;
}

QString MainWindow::getLocalHostIP()
{
    QString chatmsg = ui->chatTextEdit->toHtml();
    ui->chatTextEdit->clear();
    ui->chatTextEdit->setFocus();
    return chatmsg;
}

void MainWindow::onLine(const QString& name, const QString& time)
{
    bool notExist = ui->userListTableWidget->findItems(name, Qt::MatchExactly).isEmpty();
    if (notExist)
    {
        QTableWidgetItem *newuser = new QTableWidgetItem(name);
        ui->userListTableWidget->insertRow(0);
        ui->userListTableWidget->setItem(0, 0, newuser);
        ui->chatTextBrowser->setTextColor(Qt::gray);
        ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 12));
        ui->chatTextBrowser->append(tr("%1 %2 上线！").arg(time).arg(name));
        chatLine(OnLine);
    }
}

void MainWindow::offLine(const QString& name, const QString& time)
{
    int row = ui->userListTableWidget->findItems(name, Qt::MatchExactly).first()->row();
    ui->userListTableWidget->removeRow(row);
    ui->chatTextBrowser->setTextColor(Qt::gray);
    ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 12));
    ui->chatTextBrowser->append(tr("%1 %2 离线！").arg(time).arg(name));
}

void MainWindow::recvFileName(QString name, QString hostip, QString rmtname, QString filename)
{
    if (mName == rmtname)
    {
        int result = QMessageBox::information(this, tr("收到文件"), tr("好友 %1 给您发文件：\r\n%2，是否接收？").arg(name).arg(filename), QMessageBox::Yes, QMessageBox::No);
        if (result == QMessageBox::Yes)
        {
            QString fname = QFileDialog::getSaveFileName(0, tr("保 存"), filename);
            if (!fname.isEmpty())
            {
                FileReceive * mFileReceive = new FileReceive(this);
                mFileReceive->getLocalPath(fname);
                mFileReceive->getReceiveAddr(QHostAddress(hostip));
                mFileReceive->show();
            }
        } else {
            chatLine(Refuse, name);
        }
    }
}
