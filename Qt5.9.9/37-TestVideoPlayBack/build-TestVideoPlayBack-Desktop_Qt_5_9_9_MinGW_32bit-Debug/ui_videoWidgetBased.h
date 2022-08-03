/********************************************************************************
** Form generated from reading UI file 'videoWidgetBased.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGETBASED_H
#define UI_VIDEOWIDGETBASED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
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
#include "myVideoWidget.h"

QT_BEGIN_NAMESPACE

class Ui_videoWidgetBased
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    myVideoWidget *videoWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAdd;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSound;
    QSlider *sliderVolumn;
    QPushButton *pushButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabCurMedia;
    QLabel *LabRatio;
    QSlider *sliderPosition;

    void setupUi(QMainWindow *videoWidgetBased)
    {
        if (videoWidgetBased->objectName().isEmpty())
            videoWidgetBased->setObjectName(QStringLiteral("videoWidgetBased"));
        videoWidgetBased->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        videoWidgetBased->setFont(font);
        centralwidget = new QWidget(videoWidgetBased);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        videoWidget = new myVideoWidget(groupBox);
        videoWidget->setObjectName(QStringLiteral("videoWidget"));
        videoWidget->setMinimumSize(QSize(500, 500));

        gridLayout->addWidget(videoWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 35));
        widget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(9);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        btnAdd = new QPushButton(widget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMinimumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/001.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        horizontalLayout_3->addWidget(btnAdd);

        btnPlay = new QPushButton(widget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setMinimumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon1);

        horizontalLayout_3->addWidget(btnPlay);

        btnPause = new QPushButton(widget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setMinimumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon2);

        horizontalLayout_3->addWidget(btnPause);

        btnStop = new QPushButton(widget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setMinimumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon3);

        horizontalLayout_3->addWidget(btnStop);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnSound = new QPushButton(widget);
        btnSound->setObjectName(QStringLiteral("btnSound"));
        btnSound->setMinimumSize(QSize(30, 30));
        btnSound->setFlat(true);

        horizontalLayout_3->addWidget(btnSound);

        sliderVolumn = new QSlider(widget);
        sliderVolumn->setObjectName(QStringLiteral("sliderVolumn"));
        sliderVolumn->setMinimumSize(QSize(100, 30));
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderVolumn);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(80, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/237.GIF"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addWidget(widget);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(500, 31));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(6);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LabCurMedia = new QLabel(centralwidget);
        LabCurMedia->setObjectName(QStringLiteral("LabCurMedia"));
        LabCurMedia->setMinimumSize(QSize(150, 30));

        horizontalLayout_4->addWidget(LabCurMedia);

        LabRatio = new QLabel(centralwidget);
        LabRatio->setObjectName(QStringLiteral("LabRatio"));
        LabRatio->setMinimumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(LabRatio);

        sliderPosition = new QSlider(centralwidget);
        sliderPosition->setObjectName(QStringLiteral("sliderPosition"));
        sliderPosition->setMinimumSize(QSize(300, 30));
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderPosition);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        videoWidgetBased->setCentralWidget(centralwidget);

        retranslateUi(videoWidgetBased);

        QMetaObject::connectSlotsByName(videoWidgetBased);
    } // setupUi

    void retranslateUi(QMainWindow *videoWidgetBased)
    {
        videoWidgetBased->setWindowTitle(QApplication::translate("videoWidgetBased", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        btnAdd->setText(QString());
        btnPlay->setText(QString());
        btnPause->setText(QString());
        btnStop->setText(QString());
        btnSound->setText(QString());
        pushButton->setText(QApplication::translate("videoWidgetBased", "\345\205\250\345\261\217\346\222\255\346\224\276", Q_NULLPTR));
        LabCurMedia->setText(QApplication::translate("videoWidgetBased", "\346\227\240\346\233\262\347\233\256", Q_NULLPTR));
        LabRatio->setText(QApplication::translate("videoWidgetBased", "\350\277\233\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoWidgetBased: public Ui_videoWidgetBased {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGETBASED_H
