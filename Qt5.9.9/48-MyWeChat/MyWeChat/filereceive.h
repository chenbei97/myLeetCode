#ifndef FILERECEIVE_H
#define FILERECEIVE_H

 #include <QDialog>
 #include <QFile>
 #include <QTime>
 #include <QTcpSocket>
 #include <QHostAddress>
 #include <QDataStream>

namespace Ui {
  class FileReceive;
}

class FileReceive : public QDialog
{
  Q_OBJECT

public:
  explicit FileReceive(QWidget *parent = nullptr);
  void getReceiveAddr(QHostAddress saddr);
  void getLocalPath(QString path);
protected:
    void closeEvent(QCloseEvent *);
private:
    Ui::FileReceive *ui;

    void readChatMsg();
private:

    QTcpSocket *myCntSocket;
    QHostAddress mySrvAddr;
    qint16 mySrvPort;

    qint64 myTotalBytes;
    qint64 myRcvedBytes;
    QByteArray myInputBlock;
    quint16 myBlockSize;

    QFile *myLocPathFile;
    QString myFileName;
    qint64 myFileNameSize;

    QTime mytime;
};

#endif // FILERECEIVE_H
