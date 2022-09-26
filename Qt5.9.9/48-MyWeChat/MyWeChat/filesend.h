#ifndef FILESEND_H
#define FILESEND_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTime>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCloseEvent>

namespace Ui {
  class FileSend;
}

class FileSend : public QDialog
{
  Q_OBJECT

public:
      explicit FileSend(QWidget *parent = nullptr);
      void sendRefused();
      void sendChatMsg();
      void onBytesWritten(qint64 size);
protected:
      void closeEvent(QCloseEvent *e);
private:
      Ui::FileSend *ui;
      QTcpServer *myTcpSrv;
      QTcpSocket *mySrvSocket;
      qint16 mySrvPort;

      QFile *myLocPathFile;
      QString myPathFile;
      QString myFileName;

      qint64 myTotalBytes;
      qint64 mySendBytes;
      qint64 myBytesTobeSend;
      qint64 myPayloadSize;
      QByteArray myOutputBlock;
      QTime mytime;
signals:
    void sendFileName(QString name);
};

#endif // FILESEND_H
