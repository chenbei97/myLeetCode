#include "UdpMultiCast.h"
#include "ui_UdpMultiCast.h"

UdpMultiCast::UdpMultiCast(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::UdpMultiCast)
{
  ui->setupUi(this);
}

UdpMultiCast::~UdpMultiCast()
{
  delete ui;
}

