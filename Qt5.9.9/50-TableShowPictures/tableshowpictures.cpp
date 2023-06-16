#include "tableshowpictures.h"
#include <QHeaderView>
#include <QLabel>
#include <QDebug>

TableShowPictures::TableShowPictures(QWidget *parent)
    : QMainWindow(parent)
{

     //mView = new QTableWidget;
     mView = new QTableView;
     mModel = new PictureModel;
     mDelegate = new PictureDelegate(this);

//     mView->setEditTriggers(QTableWidget::EditTrigger::NoEditTriggers);
//     mView->setRowCount(3);
//     mView->setColumnCount(3);

//     QTableWidgetItem * item;
//     QLabel * label ;
//     int tem = 1;
//     for (int i = 0; i < 3; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             item = new QTableWidgetItem;
//             mView->setItem(i,j,item);
//             label = new QLabel;
//             label->setAlignment(Qt::AlignCenter);
//             label->setPixmap(QPixmap(QString("../50-TableShowPictures/%1.jpg")
//                                      .arg(tem)).scaled(300,(int)300*0.618));
//             mView->setCellWidget(i,j,label);
//             tem++;
//         }
//     }
     mView->setModel(mModel);
     //mView->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

     mView->setItemDelegate(mDelegate);
     mView->setMouseTracking(true);
    qDebug()<<mView->itemDelegate()->metaObject()->className();
//     QLabel * label;
//     for(int r = 0; r < mModel->rowCount(); r++)
//     {
//         for (int c = 0; c < mModel->columnCount(); ++c)
//         {
//             label = new QLabel;
//             label->setAlignment(Qt::AlignCenter);
//             qDebug()<<"r = "<<r<<" c = "<<c;
//             mView->setIndexWidget(mModel->index(r,c),label);
//         }
//     }


        //qDebug()<<mView->indexWidget(mModel->index(0,0))->metaObject()->className();
//     mView->resizeColumnsToContents();
//     mView->resizeRowsToContents();
//     mView->setIconSize(QSize(200,100));
//     mView->setAutoFillBackground(true);

     connect(mView,&QTableView::iconSizeChanged,this,&TableShowPictures::onIconSizeChanged);

     mView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     mView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

     setCentralWidget(mView);
     resize(800,600);
     setFont(QFont("Times New Roman",12));
}

void TableShowPictures::resizeEvent(QResizeEvent *e)
{
    qDebug()<<e->size();
    e->accept();
}

void TableShowPictures::onIconSizeChanged(const QSize&size)
{
    qDebug()<<size;
}

TableShowPictures::~TableShowPictures()
{
}

