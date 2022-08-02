/********************************************************************************
** Form generated from reading UI file 'TestQAudioInput.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQAUDIOINPUT_H
#define UI_TESTQAUDIOINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_TestQAudioInput
{
public:
    QAction *actDeviceTest;
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QGroupBox *groupBoxDevice;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboDevices;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *actualCodecLabel;
    QComboBox *comboCodec;
    QLabel *actualFreqLabel;
    QComboBox *comboSampleRate;
    QLabel *actualChannelLabel;
    QComboBox *comboChannels;
    QLabel *actualSampleTypeLabel;
    QComboBox *comboSampleTypes;
    QLabel *actualSampleSizeLabel;
    QComboBox *comboSampleSizes;
    QLabel *actualEndianLabel;
    QComboBox *comboByteOrder;
    QFrame *line_2;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QChartView *chartView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabBufferSize;
    QLabel *LabBlockSize;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQAudioInput)
    {
        if (TestQAudioInput->objectName().isEmpty())
            TestQAudioInput->setObjectName(QStringLiteral("TestQAudioInput"));
        TestQAudioInput->resize(1190, 668);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQAudioInput->setFont(font);
        actDeviceTest = new QAction(TestQAudioInput);
        actDeviceTest->setObjectName(QStringLiteral("actDeviceTest"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/22.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actDeviceTest->setIcon(icon);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        actDeviceTest->setFont(font1);
        actStart = new QAction(TestQAudioInput);
        actStart->setObjectName(QStringLiteral("actStart"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/626.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon1);
        actStop = new QAction(TestQAudioInput);
        actStop->setObjectName(QStringLiteral("actStop"));
        actStop->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon2);
        actQuit = new QAction(TestQAudioInput);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon3);
        centralwidget = new QWidget(TestQAudioInput);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBoxDevice = new QGroupBox(splitter);
        groupBoxDevice->setObjectName(QStringLiteral("groupBoxDevice"));
        groupBoxDevice->setMinimumSize(QSize(360, 400));
        groupBoxDevice->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBoxDevice);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBoxDevice);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(140, 30));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label);

        comboDevices = new QComboBox(groupBoxDevice);
        comboDevices->setObjectName(QStringLiteral("comboDevices"));

        horizontalLayout->addWidget(comboDevices);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(groupBoxDevice);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        actualCodecLabel = new QLabel(groupBoxDevice);
        actualCodecLabel->setObjectName(QStringLiteral("actualCodecLabel"));
        actualCodecLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualCodecLabel, 0, 0, 1, 1);

        comboCodec = new QComboBox(groupBoxDevice);
        comboCodec->setObjectName(QStringLiteral("comboCodec"));

        gridLayout->addWidget(comboCodec, 0, 1, 1, 1);

        actualFreqLabel = new QLabel(groupBoxDevice);
        actualFreqLabel->setObjectName(QStringLiteral("actualFreqLabel"));
        actualFreqLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualFreqLabel, 1, 0, 1, 1);

        comboSampleRate = new QComboBox(groupBoxDevice);
        comboSampleRate->setObjectName(QStringLiteral("comboSampleRate"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboSampleRate->sizePolicy().hasHeightForWidth());
        comboSampleRate->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboSampleRate, 1, 1, 1, 1);

        actualChannelLabel = new QLabel(groupBoxDevice);
        actualChannelLabel->setObjectName(QStringLiteral("actualChannelLabel"));
        actualChannelLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualChannelLabel, 2, 0, 1, 1);

        comboChannels = new QComboBox(groupBoxDevice);
        comboChannels->setObjectName(QStringLiteral("comboChannels"));

        gridLayout->addWidget(comboChannels, 2, 1, 1, 1);

        actualSampleTypeLabel = new QLabel(groupBoxDevice);
        actualSampleTypeLabel->setObjectName(QStringLiteral("actualSampleTypeLabel"));
        actualSampleTypeLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualSampleTypeLabel, 3, 0, 1, 1);

        comboSampleTypes = new QComboBox(groupBoxDevice);
        comboSampleTypes->setObjectName(QStringLiteral("comboSampleTypes"));

        gridLayout->addWidget(comboSampleTypes, 3, 1, 1, 1);

        actualSampleSizeLabel = new QLabel(groupBoxDevice);
        actualSampleSizeLabel->setObjectName(QStringLiteral("actualSampleSizeLabel"));
        actualSampleSizeLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualSampleSizeLabel, 4, 0, 1, 1);

        comboSampleSizes = new QComboBox(groupBoxDevice);
        comboSampleSizes->setObjectName(QStringLiteral("comboSampleSizes"));

        gridLayout->addWidget(comboSampleSizes, 4, 1, 1, 1);

        actualEndianLabel = new QLabel(groupBoxDevice);
        actualEndianLabel->setObjectName(QStringLiteral("actualEndianLabel"));
        actualEndianLabel->setMinimumSize(QSize(140, 30));

        gridLayout->addWidget(actualEndianLabel, 5, 0, 1, 1);

        comboByteOrder = new QComboBox(groupBoxDevice);
        comboByteOrder->setObjectName(QStringLiteral("comboByteOrder"));

        gridLayout->addWidget(comboByteOrder, 5, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line_2 = new QFrame(groupBoxDevice);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_2 = new QLabel(groupBoxDevice);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(label_2);

        splitter->addWidget(groupBoxDevice);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chartView = new QChartView(groupBox_2);
        chartView->setObjectName(QStringLiteral("chartView"));

        gridLayout_2->addWidget(chartView, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LabBufferSize = new QLabel(groupBox_2);
        LabBufferSize->setObjectName(QStringLiteral("LabBufferSize"));
        LabBufferSize->setMinimumSize(QSize(250, 30));

        horizontalLayout_2->addWidget(LabBufferSize);

        LabBlockSize = new QLabel(groupBox_2);
        LabBlockSize->setObjectName(QStringLiteral("LabBlockSize"));
        LabBlockSize->setMinimumSize(QSize(250, 30));

        horizontalLayout_2->addWidget(LabBlockSize);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        TestQAudioInput->setCentralWidget(centralwidget);
        toolBar = new QToolBar(TestQAudioInput);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQAudioInput->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actDeviceTest);
        toolBar->addAction(actStart);
        toolBar->addAction(actStop);
        toolBar->addAction(actQuit);

        retranslateUi(TestQAudioInput);
        QObject::connect(actQuit, SIGNAL(triggered()), TestQAudioInput, SLOT(close()));

        QMetaObject::connectSlotsByName(TestQAudioInput);
    } // setupUi

    void retranslateUi(QMainWindow *TestQAudioInput)
    {
        TestQAudioInput->setWindowTitle(QApplication::translate("TestQAudioInput", "TestQAudioInput", Q_NULLPTR));
        actDeviceTest->setText(QApplication::translate("TestQAudioInput", "\346\265\213\350\257\225\351\237\263\351\242\221\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDeviceTest->setToolTip(QApplication::translate("TestQAudioInput", "\346\265\213\350\257\225\351\237\263\351\242\221\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStart->setText(QApplication::translate("TestQAudioInput", "\345\274\200\345\247\213\350\276\223\345\205\245\351\237\263\351\242\221", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("TestQAudioInput", "\345\274\200\345\247\213", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("TestQAudioInput", "\345\201\234\346\255\242\351\237\263\351\242\221\350\276\223\345\205\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("TestQAudioInput", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestQAudioInput", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestQAudioInput", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBoxDevice->setTitle(QApplication::translate("TestQAudioInput", "\346\224\257\346\214\201\347\232\204\351\237\263\351\242\221\350\276\223\345\205\245\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("TestQAudioInput", "\351\237\263\351\242\221\350\276\223\345\205\245\350\256\276\345\244\207", Q_NULLPTR));
        actualCodecLabel->setText(QApplication::translate("TestQAudioInput", "\347\274\226\347\240\201\346\240\274\345\274\217", Q_NULLPTR));
        actualFreqLabel->setText(QApplication::translate("TestQAudioInput", "\351\207\207\346\240\267\347\216\207(Hz)", Q_NULLPTR));
        actualChannelLabel->setText(QApplication::translate("TestQAudioInput", "\351\200\232\351\201\223\346\225\260", Q_NULLPTR));
        actualSampleTypeLabel->setText(QApplication::translate("TestQAudioInput", "\351\207\207\346\240\267\347\261\273\345\236\213", Q_NULLPTR));
        actualSampleSizeLabel->setText(QApplication::translate("TestQAudioInput", "\351\207\207\346\240\267\345\244\247\345\260\217(Bytes)", Q_NULLPTR));
        actualEndianLabel->setText(QApplication::translate("TestQAudioInput", "\345\255\227\350\212\202\345\272\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("TestQAudioInput", "<html><head/><body><p>\344\270\272\344\272\206\345\244\204\347\220\206\346\226\271\344\276\277\357\274\214\346\234\254\347\250\213\345\272\217\345\233\272\345\256\232\351\207\207\346\240\267\346\226\271\345\274\217\357\274\232</p><p>\351\207\207\346\240\267\346\240\274\345\274\217\345\246\202\344\270\213\346\211\200\347\244\272\357\274\232</p><p>\351\207\207\346\240\267\347\216\207\357\274\2328000Hz\357\274\233</p><p>\351\200\232\351\201\223\346\225\260\357\274\2321\357\274\233</p><p>\347\274\226\347\240\201\346\240\274\345\274\217\357\274\232audio/pcm\357\274\233</p><p>\346\257\217\345\270\247\345\255\227\350\212\202\346\225\260\357\274\2328bits\357\274\233</p><p>\351\207\207\346\240\267\347\202\271\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232\346\227\240\347\254\246\345\217\267\346\225\264\345\236\213\357\274\233</p><p>\345\255\227\350\212\202\345\272\217\347\261\273\345\236\213\357\274\232\344\275\216\345\255\227\350\212\202\345\272\217\343\200\202</p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TestQAudioInput", "\345\256\236\346\227\266\350\276\223\345\205\245\351\237\263\351\242\221\346\263\242\345\275\242", Q_NULLPTR));
        LabBufferSize->setText(QApplication::translate("TestQAudioInput", "\351\237\263\351\242\221\350\276\223\345\205\245\350\256\276\345\244\207\347\274\223\345\206\262\345\214\272\345\244\247\345\260\217\344\270\272\357\274\232", Q_NULLPTR));
        LabBlockSize->setText(QApplication::translate("TestQAudioInput", "\346\225\260\346\215\256\345\235\227\345\244\247\345\260\217\344\270\272\357\274\232", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TestQAudioInput", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQAudioInput: public Ui_TestQAudioInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQAUDIOINPUT_H
