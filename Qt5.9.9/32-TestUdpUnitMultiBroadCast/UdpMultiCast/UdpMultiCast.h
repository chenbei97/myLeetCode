#ifndef UDPMULTICAST_H
#define UDPMULTICAST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpMultiCast; }
QT_END_NAMESPACE

class UdpMultiCast : public QMainWindow
{
  Q_OBJECT

public:
  UdpMultiCast(QWidget *parent = nullptr);
  ~UdpMultiCast();

private:
  Ui::UdpMultiCast *ui;
};
#endif // UDPMULTICAST_H
