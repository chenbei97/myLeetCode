/********************************************************************************
** Form generated from reading UI file 'graphicsVideoItem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSVIDEOITEM_H
#define UI_GRAPHICSVIDEOITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphicsVideoItem
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnAdd_2;
    QPushButton *btnPlay_2;
    QPushButton *btnPause_2;
    QPushButton *btnStop_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSound_2;
    QSlider *sliderVolumn_2;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabCurMedia_2;
    QLabel *LabRatio_2;
    QSlider *sliderPosition_2;

    void setupUi(QMainWindow *graphicsVideoItem)
    {
        if (graphicsVideoItem->objectName().isEmpty())
            graphicsVideoItem->setObjectName(QStringLiteral("graphicsVideoItem"));
        graphicsVideoItem->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        graphicsVideoItem->setFont(font);
        centralwidget = new QWidget(graphicsVideoItem);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 35));
        widget_2->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(9);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, 1, 1, 1);
        btnAdd_2 = new QPushButton(widget_2);
        btnAdd_2->setObjectName(QStringLiteral("btnAdd_2"));
        btnAdd_2->setMinimumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/001.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd_2->setIcon(icon);

        horizontalLayout_6->addWidget(btnAdd_2);

        btnPlay_2 = new QPushButton(widget_2);
        btnPlay_2->setObjectName(QStringLiteral("btnPlay_2"));
        btnPlay_2->setMinimumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay_2->setIcon(icon1);

        horizontalLayout_6->addWidget(btnPlay_2);

        btnPause_2 = new QPushButton(widget_2);
        btnPause_2->setObjectName(QStringLiteral("btnPause_2"));
        btnPause_2->setMinimumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause_2->setIcon(icon2);

        horizontalLayout_6->addWidget(btnPause_2);

        btnStop_2 = new QPushButton(widget_2);
        btnStop_2->setObjectName(QStringLiteral("btnStop_2"));
        btnStop_2->setMinimumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop_2->setIcon(icon3);

        horizontalLayout_6->addWidget(btnStop_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        btnSound_2 = new QPushButton(widget_2);
        btnSound_2->setObjectName(QStringLiteral("btnSound_2"));
        btnSound_2->setMinimumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound_2->setIcon(icon4);
        btnSound_2->setFlat(true);

        horizontalLayout_6->addWidget(btnSound_2);

        sliderVolumn_2 = new QSlider(widget_2);
        sliderVolumn_2->setObjectName(QStringLiteral("sliderVolumn_2"));
        sliderVolumn_2->setMinimumSize(QSize(100, 30));
        sliderVolumn_2->setMaximum(100);
        sliderVolumn_2->setValue(100);
        sliderVolumn_2->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sliderVolumn_2);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/237.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_2);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(500, 31));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line_2);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LabCurMedia_2 = new QLabel(centralwidget);
        LabCurMedia_2->setObjectName(QStringLiteral("LabCurMedia_2"));
        LabCurMedia_2->setMinimumSize(QSize(150, 30));

        horizontalLayout_5->addWidget(LabCurMedia_2);

        LabRatio_2 = new QLabel(centralwidget);
        LabRatio_2->setObjectName(QStringLiteral("LabRatio_2"));
        LabRatio_2->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(LabRatio_2);

        sliderPosition_2 = new QSlider(centralwidget);
        sliderPosition_2->setObjectName(QStringLiteral("sliderPosition_2"));
        sliderPosition_2->setMinimumSize(QSize(300, 30));
        sliderPosition_2->setTracking(false);
        sliderPosition_2->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderPosition_2);


        gridLayout_3->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        graphicsVideoItem->setCentralWidget(centralwidget);

        retranslateUi(graphicsVideoItem);

        QMetaObject::connectSlotsByName(graphicsVideoItem);
    } // setupUi

    void retranslateUi(QMainWindow *graphicsVideoItem)
    {
        graphicsVideoItem->setWindowTitle(QApplication::translate("graphicsVideoItem", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        btnAdd_2->setText(QString());
        btnPlay_2->setText(QString());
        btnPause_2->setText(QString());
        btnStop_2->setText(QString());
        btnSound_2->setText(QString());
        pushButton_2->setText(QApplication::translate("graphicsVideoItem", "\345\205\250\345\261\217\346\222\255\346\224\276", Q_NULLPTR));
        LabCurMedia_2->setText(QApplication::translate("graphicsVideoItem", "\346\227\240\346\233\262\347\233\256", Q_NULLPTR));
        LabRatio_2->setText(QApplication::translate("graphicsVideoItem", "\350\277\233\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class graphicsVideoItem: public Ui_graphicsVideoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSVIDEOITEM_H
