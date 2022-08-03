/********************************************************************************
** Form generated from reading UI file 'operateCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATECAMERA_H
#define UI_OPERATECAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcameraviewfinder.h>

QT_BEGIN_NAMESPACE

class Ui_operateCamera
{
public:
    QAction *actStartCamera;
    QAction *actStopCamera;
    QAction *actVideoRecord;
    QAction *actCapture;
    QAction *actQuit;
    QAction *actVideoStop;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboCamera;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkStillImage;
    QCheckBox *checkVideo;
    QLabel *LabDuration;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *chkMute;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnVideoFile;
    QLineEdit *editOutputFile;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCameraViewfinder *viewFinder;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *LabCapturedImage;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *operateCamera)
    {
        if (operateCamera->objectName().isEmpty())
            operateCamera->setObjectName(QStringLiteral("operateCamera"));
        operateCamera->resize(1000, 600);
        operateCamera->setMinimumSize(QSize(1000, 600));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        operateCamera->setFont(font);
        actStartCamera = new QAction(operateCamera);
        actStartCamera->setObjectName(QStringLiteral("actStartCamera"));
        actStartCamera->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/video_chat.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actStartCamera->setIcon(icon);
        actStopCamera = new QAction(operateCamera);
        actStopCamera->setObjectName(QStringLiteral("actStopCamera"));
        actStopCamera->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/remove_user.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actStopCamera->setIcon(icon1);
        actVideoRecord = new QAction(operateCamera);
        actVideoRecord->setObjectName(QStringLiteral("actVideoRecord"));
        actVideoRecord->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/5.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actVideoRecord->setIcon(icon2);
        actCapture = new QAction(operateCamera);
        actCapture->setObjectName(QStringLiteral("actCapture"));
        actCapture->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/file_pictures.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCapture->setIcon(icon3);
        actQuit = new QAction(operateCamera);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/exit_24.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon4);
        actVideoStop = new QAction(operateCamera);
        actVideoStop->setObjectName(QStringLiteral("actVideoStop"));
        actVideoStop->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/Shut Down.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actVideoStop->setIcon(icon5);
        centralwidget = new QWidget(operateCamera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 120));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(120, 30));
        label->setMaximumSize(QSize(1666666, 16777215));

        horizontalLayout->addWidget(label);

        comboCamera = new QComboBox(groupBox_2);
        comboCamera->setObjectName(QStringLiteral("comboCamera"));
        comboCamera->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(comboCamera);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkStillImage = new QCheckBox(groupBox_2);
        checkStillImage->setObjectName(QStringLiteral("checkStillImage"));
        checkStillImage->setEnabled(false);
        checkStillImage->setMinimumSize(QSize(80, 30));
        checkStillImage->setCheckable(true);
        checkStillImage->setChecked(false);

        horizontalLayout_2->addWidget(checkStillImage);

        checkVideo = new QCheckBox(groupBox_2);
        checkVideo->setObjectName(QStringLiteral("checkVideo"));
        checkVideo->setEnabled(false);
        checkVideo->setMinimumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(checkVideo);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        LabDuration = new QLabel(groupBox_2);
        LabDuration->setObjectName(QStringLiteral("LabDuration"));
        LabDuration->setMinimumSize(QSize(80, 30));
        LabDuration->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(LabDuration);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        chkMute = new QCheckBox(groupBox_2);
        chkMute->setObjectName(QStringLiteral("chkMute"));
        chkMute->setMinimumSize(QSize(120, 30));
        chkMute->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_5->addWidget(chkMute);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnVideoFile = new QPushButton(groupBox_2);
        btnVideoFile->setObjectName(QStringLiteral("btnVideoFile"));
        btnVideoFile->setMinimumSize(QSize(150, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnVideoFile->setIcon(icon6);
        btnVideoFile->setFlat(false);

        horizontalLayout_4->addWidget(btnVideoFile);

        editOutputFile = new QLineEdit(groupBox_2);
        editOutputFile->setObjectName(QStringLiteral("editOutputFile"));
        editOutputFile->setMinimumSize(QSize(300, 30));

        horizontalLayout_4->addWidget(editOutputFile);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        viewFinder = new QCameraViewfinder(groupBox);
        viewFinder->setObjectName(QStringLiteral("viewFinder"));
        viewFinder->setMinimumSize(QSize(450, 0));

        gridLayout_2->addWidget(viewFinder, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(450, 0));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        LabCapturedImage = new QLabel(groupBox_3);
        LabCapturedImage->setObjectName(QStringLiteral("LabCapturedImage"));
        LabCapturedImage->setMinimumSize(QSize(450, 0));
        LabCapturedImage->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(LabCapturedImage, 0, 0, 1, 1);

        splitter->addWidget(groupBox_3);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);

        operateCamera->setCentralWidget(centralwidget);
        toolBar = new QToolBar(operateCamera);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        operateCamera->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(operateCamera);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        operateCamera->setStatusBar(statusBar);

        toolBar->addAction(actStartCamera);
        toolBar->addAction(actStopCamera);
        toolBar->addAction(actVideoRecord);
        toolBar->addAction(actVideoStop);
        toolBar->addAction(actCapture);
        toolBar->addAction(actQuit);

        retranslateUi(operateCamera);
        QObject::connect(actQuit, SIGNAL(triggered()), operateCamera, SLOT(close()));

        QMetaObject::connectSlotsByName(operateCamera);
    } // setupUi

    void retranslateUi(QMainWindow *operateCamera)
    {
        operateCamera->setWindowTitle(QApplication::translate("operateCamera", "MainWindow", Q_NULLPTR));
        actStartCamera->setText(QApplication::translate("operateCamera", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStartCamera->setToolTip(QApplication::translate("operateCamera", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStopCamera->setText(QApplication::translate("operateCamera", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStopCamera->setToolTip(QApplication::translate("operateCamera", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actVideoRecord->setText(QApplication::translate("operateCamera", "\345\274\200\345\247\213\345\275\225\345\203\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actVideoRecord->setToolTip(QApplication::translate("operateCamera", "\345\274\200\345\247\213\345\275\225\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCapture->setText(QApplication::translate("operateCamera", "\346\212\223\345\233\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCapture->setToolTip(QApplication::translate("operateCamera", "\346\212\223\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("operateCamera", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("operateCamera", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actVideoStop->setText(QApplication::translate("operateCamera", "\345\201\234\346\255\242\345\275\225\345\203\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actVideoStop->setToolTip(QApplication::translate("operateCamera", "\345\201\234\346\255\242\345\275\225\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("operateCamera", "  \346\221\204\345\203\217\345\244\264\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("operateCamera", "\346\221\204\345\203\217\345\244\264\350\256\276\345\244\207", Q_NULLPTR));
        checkStillImage->setText(QApplication::translate("operateCamera", "\346\224\257\346\214\201\346\212\223\345\233\276", Q_NULLPTR));
        checkVideo->setText(QApplication::translate("operateCamera", "\346\224\257\346\214\201\345\275\225\345\203\217", Q_NULLPTR));
        LabDuration->setText(QApplication::translate("operateCamera", "\345\275\225\345\210\266\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        chkMute->setText(QApplication::translate("operateCamera", "\345\275\225\345\203\217\346\227\266\351\235\231\351\237\263", Q_NULLPTR));
        btnVideoFile->setText(QApplication::translate("operateCamera", "\350\247\206\351\242\221\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        editOutputFile->setText(QString());
        groupBox->setTitle(QApplication::translate("operateCamera", "\346\221\204\345\203\217\345\244\264\351\242\204\350\247\210", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("operateCamera", "\346\212\223\345\217\226\345\233\276\347\211\207", Q_NULLPTR));
        LabCapturedImage->setText(QApplication::translate("operateCamera", "\346\212\223\345\217\226\347\232\204\345\233\276\347\211\207", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("operateCamera", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class operateCamera: public Ui_operateCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATECAMERA_H
