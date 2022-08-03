/********************************************************************************
** Form generated from reading UI file 'graphicsVideoItemBased.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSVIDEOITEMBASED_H
#define UI_GRAPHICSVIDEOITEMBASED_H

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
    QVBoxLayout *verticalLayout_;
    QWidget *widget_;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnAdd_;
    QPushButton *btnPlay_;
    QPushButton *btnPause_;
    QPushButton *btnStop_;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSound_;
    QSlider *sliderVolumn_;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabCurMedia_;
    QLabel *LabRatio_;
    QSlider *sliderPosition_;

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

        verticalLayout_ = new QVBoxLayout();
        verticalLayout_->setObjectName(QStringLiteral("verticalLayout_"));
        widget_ = new QWidget(centralwidget);
        widget_->setObjectName(QStringLiteral("widget_"));
        widget_->setMinimumSize(QSize(0, 35));
        widget_->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_6 = new QHBoxLayout(widget_);
        horizontalLayout_6->setSpacing(9);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, 1, 1, 1);
        btnAdd_ = new QPushButton(widget_);
        btnAdd_->setObjectName(QStringLiteral("btnAdd_"));
        btnAdd_->setMinimumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/001.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd_->setIcon(icon);

        horizontalLayout_6->addWidget(btnAdd_);

        btnPlay_ = new QPushButton(widget_);
        btnPlay_->setObjectName(QStringLiteral("btnPlay_"));
        btnPlay_->setMinimumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay_->setIcon(icon1);

        horizontalLayout_6->addWidget(btnPlay_);

        btnPause_ = new QPushButton(widget_);
        btnPause_->setObjectName(QStringLiteral("btnPause_"));
        btnPause_->setMinimumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause_->setIcon(icon2);

        horizontalLayout_6->addWidget(btnPause_);

        btnStop_ = new QPushButton(widget_);
        btnStop_->setObjectName(QStringLiteral("btnStop_"));
        btnStop_->setMinimumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop_->setIcon(icon3);

        horizontalLayout_6->addWidget(btnStop_);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        btnSound_ = new QPushButton(widget_);
        btnSound_->setObjectName(QStringLiteral("btnSound_"));
        btnSound_->setMinimumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound_->setIcon(icon4);
        btnSound_->setFlat(true);

        horizontalLayout_6->addWidget(btnSound_);

        sliderVolumn_ = new QSlider(widget_);
        sliderVolumn_->setObjectName(QStringLiteral("sliderVolumn_"));
        sliderVolumn_->setMinimumSize(QSize(100, 30));
        sliderVolumn_->setMaximum(100);
        sliderVolumn_->setValue(100);
        sliderVolumn_->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sliderVolumn_);


        verticalLayout_->addWidget(widget_);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(500, 31));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(6);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_->addWidget(line_2);


        gridLayout_3->addLayout(verticalLayout_, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LabCurMedia_ = new QLabel(centralwidget);
        LabCurMedia_->setObjectName(QStringLiteral("LabCurMedia_"));
        LabCurMedia_->setMinimumSize(QSize(150, 30));

        horizontalLayout_5->addWidget(LabCurMedia_);

        LabRatio_ = new QLabel(centralwidget);
        LabRatio_->setObjectName(QStringLiteral("LabRatio_"));
        LabRatio_->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(LabRatio_);

        sliderPosition_ = new QSlider(centralwidget);
        sliderPosition_->setObjectName(QStringLiteral("sliderPosition_"));
        sliderPosition_->setMinimumSize(QSize(300, 30));
        sliderPosition_->setTracking(false);
        sliderPosition_->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(sliderPosition_);


        gridLayout_3->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        graphicsVideoItem->setCentralWidget(centralwidget);

        retranslateUi(graphicsVideoItem);

        QMetaObject::connectSlotsByName(graphicsVideoItem);
    } // setupUi

    void retranslateUi(QMainWindow *graphicsVideoItem)
    {
        graphicsVideoItem->setWindowTitle(QApplication::translate("graphicsVideoItem", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        btnAdd_->setText(QString());
        btnPlay_->setText(QString());
        btnPause_->setText(QString());
        btnStop_->setText(QString());
        btnSound_->setText(QString());
        LabCurMedia_->setText(QApplication::translate("graphicsVideoItem", "\346\227\240\346\233\262\347\233\256", Q_NULLPTR));
        LabRatio_->setText(QApplication::translate("graphicsVideoItem", "\350\277\233\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class graphicsVideoItem: public Ui_graphicsVideoItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSVIDEOITEMBASED_H
