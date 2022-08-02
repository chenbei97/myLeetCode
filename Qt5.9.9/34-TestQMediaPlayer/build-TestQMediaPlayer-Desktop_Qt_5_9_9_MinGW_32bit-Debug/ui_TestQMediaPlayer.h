/********************************************************************************
** Form generated from reading UI file 'TestQMediaPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQMEDIAPLAYER_H
#define UI_TESTQMEDIAPLAYER_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQMediaPlayer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnClear;
    QFrame *line;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPlay;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPause;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnPrevious;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnSound;
    QSpacerItem *horizontalSpacer_6;
    QSlider *sliderVolumn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LabCurMedia;
    QLabel *LabRatio;
    QSlider *sliderPosition;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButton10;

    void setupUi(QMainWindow *TestQMediaPlayer)
    {
        if (TestQMediaPlayer->objectName().isEmpty())
            TestQMediaPlayer->setObjectName(QStringLiteral("TestQMediaPlayer"));
        TestQMediaPlayer->resize(1100, 730);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQMediaPlayer->setFont(font);
        centralwidget = new QWidget(TestQMediaPlayer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMinimumSize(QSize(80, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/316.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        horizontalLayout->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        btnRemove->setMinimumSize(QSize(80, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/318.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon1);

        horizontalLayout->addWidget(btnRemove);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMinimumSize(QSize(80, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/214.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon2);

        horizontalLayout->addWidget(btnClear);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 2, 0, 1, 1);

        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(1100, 400));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnPlay = new QPushButton(centralwidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setMinimumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon3);

        horizontalLayout_2->addWidget(btnPlay);

        horizontalSpacer = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setMinimumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon4);

        horizontalLayout_2->addWidget(btnPause);

        horizontalSpacer_2 = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setMinimumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon5);

        horizontalLayout_2->addWidget(btnStop);

        horizontalSpacer_3 = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnPrevious = new QPushButton(centralwidget);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));
        btnPrevious->setMinimumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/616.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevious->setIcon(icon6);

        horizontalLayout_2->addWidget(btnPrevious);

        horizontalSpacer_4 = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setMinimumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/630.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon7);

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer_5 = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        btnSound = new QPushButton(centralwidget);
        btnSound->setObjectName(QStringLiteral("btnSound"));
        btnSound->setMinimumSize(QSize(30, 30));
        btnSound->setFocusPolicy(Qt::StrongFocus);
        btnSound->setAutoFillBackground(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/images/volumn.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSound->setIcon(icon8);
        btnSound->setCheckable(false);
        btnSound->setAutoDefault(true);
        btnSound->setFlat(false);

        horizontalLayout_2->addWidget(btnSound);

        horizontalSpacer_6 = new QSpacerItem(30, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        sliderVolumn = new QSlider(centralwidget);
        sliderVolumn->setObjectName(QStringLiteral("sliderVolumn"));
        sliderVolumn->setMinimumSize(QSize(100, 30));
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderVolumn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        LabCurMedia = new QLabel(centralwidget);
        LabCurMedia->setObjectName(QStringLiteral("LabCurMedia"));
        LabCurMedia->setMinimumSize(QSize(230, 30));

        horizontalLayout_3->addWidget(LabCurMedia);

        LabRatio = new QLabel(centralwidget);
        LabRatio->setObjectName(QStringLiteral("LabRatio"));
        LabRatio->setMinimumSize(QSize(180, 30));

        horizontalLayout_3->addWidget(LabRatio);

        sliderPosition = new QSlider(centralwidget);
        sliderPosition->setObjectName(QStringLiteral("sliderPosition"));
        sliderPosition->setMinimumSize(QSize(100, 30));
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderPosition);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(500, 80));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton1 = new QPushButton(groupBox_2);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton2 = new QPushButton(groupBox_2);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton2, 0, 1, 1, 1);

        pushButton3 = new QPushButton(groupBox_2);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        pushButton3->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton3, 0, 2, 1, 1);

        pushButton4 = new QPushButton(groupBox_2);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));
        pushButton4->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton4, 0, 3, 1, 1);

        pushButton5 = new QPushButton(groupBox_2);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));

        gridLayout_2->addWidget(pushButton5, 0, 4, 1, 1);

        pushButton6 = new QPushButton(groupBox_2);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));

        gridLayout_2->addWidget(pushButton6, 0, 5, 1, 1);

        pushButton7 = new QPushButton(groupBox_2);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));

        gridLayout_2->addWidget(pushButton7, 0, 6, 1, 1);

        pushButton8 = new QPushButton(groupBox_2);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));

        gridLayout_2->addWidget(pushButton8, 0, 7, 1, 1);

        pushButton9 = new QPushButton(groupBox_2);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));
        pushButton9->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton9, 0, 8, 1, 1);

        pushButton10 = new QPushButton(groupBox_2);
        pushButton10->setObjectName(QStringLiteral("pushButton10"));
        pushButton10->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(pushButton10, 0, 9, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 1);

        TestQMediaPlayer->setCentralWidget(centralwidget);

        retranslateUi(TestQMediaPlayer);

        btnSound->setDefault(false);


        QMetaObject::connectSlotsByName(TestQMediaPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *TestQMediaPlayer)
    {
        TestQMediaPlayer->setWindowTitle(QApplication::translate("TestQMediaPlayer", "TestQMediaPlayer", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestQMediaPlayer", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("TestQMediaPlayer", "\346\267\273\345\212\240", Q_NULLPTR));
        btnRemove->setText(QApplication::translate("TestQMediaPlayer", "\347\247\273\351\231\244", Q_NULLPTR));
        btnClear->setText(QApplication::translate("TestQMediaPlayer", "\346\270\205\347\251\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnPlay->setToolTip(QApplication::translate("TestQMediaPlayer", "\346\222\255\346\224\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnPlay->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPause->setToolTip(QApplication::translate("TestQMediaPlayer", "\346\232\202\345\201\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnStop->setToolTip(QApplication::translate("TestQMediaPlayer", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnStop->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPrevious->setToolTip(QApplication::translate("TestQMediaPlayer", "\345\211\215\344\270\200\346\233\262\347\233\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnPrevious->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnNext->setToolTip(QApplication::translate("TestQMediaPlayer", "\344\270\213\344\270\200\346\233\262\347\233\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnNext->setText(QString());
        btnSound->setText(QString());
        LabCurMedia->setText(QApplication::translate("TestQMediaPlayer", "\345\275\223\345\211\215\346\222\255\346\224\276\346\233\262\347\233\256\357\274\232\346\227\240\346\233\262\347\233\256", Q_NULLPTR));
        LabRatio->setText(QApplication::translate("TestQMediaPlayer", "\350\277\233\345\272\246\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TestQMediaPlayer", "\346\222\255\346\224\276\351\237\263\346\225\210", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("TestQMediaPlayer", "AK47", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("TestQMediaPlayer", "\346\234\272\346\236\252", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("TestQMediaPlayer", "\345\274\200\346\236\252", Q_NULLPTR));
        pushButton4->setText(QApplication::translate("TestQMediaPlayer", "\347\202\256\345\274\271", Q_NULLPTR));
        pushButton5->setText(QApplication::translate("TestQMediaPlayer", "\345\234\260\351\233\267", Q_NULLPTR));
        pushButton6->setText(QApplication::translate("TestQMediaPlayer", "\345\235\246\345\205\213", Q_NULLPTR));
        pushButton7->setText(QApplication::translate("TestQMediaPlayer", "\347\201\253\346\224\2731", Q_NULLPTR));
        pushButton8->setText(QApplication::translate("TestQMediaPlayer", "\347\201\253\346\224\2732", Q_NULLPTR));
        pushButton9->setText(QApplication::translate("TestQMediaPlayer", "\347\210\206\347\202\2701", Q_NULLPTR));
        pushButton10->setText(QApplication::translate("TestQMediaPlayer", "\347\210\206\347\202\2702", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQMediaPlayer: public Ui_TestQMediaPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQMEDIAPLAYER_H
