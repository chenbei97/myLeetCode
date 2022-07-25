#include "TestQ3DBarScatterSurface.h"
#include "ui_TestQ3DBarScatterSurface.h"
#include "Test3DBar.h"
#include "Test3DScatter.h"
#include "Test3DSurface.h"
#include "Test3DMap.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

TestQ3DBarScatterSurface::TestQ3DBarScatterSurface(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQ3DBarScatterSurface)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

TestQ3DBarScatterSurface::~TestQ3DBarScatterSurface()
{
    delete ui;
}


void TestQ3DBarScatterSurface::on_act3DBar_triggered()
{
    Test3DBar * bar = new Test3DBar(this);
    //bar->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    bar->setWindowTitle("三维柱状图");
    bar->show();
    // delete bar;//不需要,会自动删除
}

void TestQ3DBarScatterSurface::on_act3DScatter_triggered()
{
    Test3DScatter * scatter = new Test3DScatter(this);
    // scatter->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    scatter->setWindowTitle("三维散点图");
    scatter->show();
}

void TestQ3DBarScatterSurface::on_act3DSurface_triggered()
{
    Test3DSurface * surface = new Test3DSurface(this);
    // surface->setAttribute(Qt::WA_DeleteOnClose);//关闭时自动删除
    surface->setWindowTitle("三维曲面图");
    surface->show();
}

void TestQ3DBarScatterSurface::on_act3DMap_triggered()
{
    ui->pushButton->setEnabled(true);
    this->map = new Test3DMap(this);
    connect(this,SIGNAL(mapImageName(QString)),this->map,SLOT(on_mapImageName(QString)));
    map->setWindowTitle("三维地形图");
    map->show();
}

void TestQ3DBarScatterSurface::on_actExit_triggered()
{
    this->close();
}

void TestQ3DBarScatterSurface::on_pushButton_clicked()
{
    QDir curr = QDir::current();
    curr.cdUp();
    curr.cd(QCoreApplication::applicationName());
    QString filename = QFileDialog::getOpenFileName(this,tr("打开图片"),curr.path()+"/images","图片文件(*.jpg *.png *.bmp)");
    if (filename.isEmpty()) return;
    this->ui->statusbar->showMessage("选择的三维地形图片地址为："+filename);
    QFileInfo info(filename);
    //qDebug()<<info.baseName()<<"."<<info.suffix();
    QString name = info.baseName()+"."+info.suffix();
    if (name == "sea.png" || name == "mountain.png" || name == "seagray.png")
    {
          emit mapImageName(name); // sea.png(图片的名字发送出去)
    }
    else{
        QMessageBox::critical(this,"错误","你只能选择images文件夹下的sea.png,mountain.png或seagray.png!");
    }
}
