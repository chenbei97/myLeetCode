/********************************************************************************
** Form generated from reading UI file 'TestQAudioRecorder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQAUDIORECORDER_H
#define UI_TESTQAUDIORECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQAudioRecorder
{
public:
    QAction *actRecord;
    QAction *actPause;
    QAction *actStop;
    QAction *actQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGetFile;
    QLineEdit *editOutputFile;
    QLabel *LabPassTime;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboDevices;
    QLabel *label_2;
    QComboBox *comboCodec;
    QLabel *label_3;
    QComboBox *comboSampleRate;
    QLabel *label_4;
    QComboBox *comboChannels;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBitrate;
    QRadioButton *radioQuality;
    QSlider *sliderQuality;
    QRadioButton *radioBitrate;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpinBox *spin_byteCount;
    QLabel *label_7;
    QSpinBox *spin_duration;
    QLabel *label_8;
    QSpinBox *spin_frameCount;
    QLabel *label_9;
    QSpinBox *spin_sampleCount;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QSpinBox *spin_channelCount;
    QLabel *label_11;
    QLineEdit *edit_byteOrder;
    QLabel *label_12;
    QLineEdit *edit_codec;
    QLabel *label_13;
    QLineEdit *edit_sampleType;
    QLabel *label_14;
    QSpinBox *spin_sampleSize;
    QLabel *label_15;
    QSpinBox *spin_sampleRate;
    QLabel *label_16;
    QSpinBox *spin_bytesPerFrame;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQAudioRecorder)
    {
        if (TestQAudioRecorder->objectName().isEmpty())
            TestQAudioRecorder->setObjectName(QStringLiteral("TestQAudioRecorder"));
        TestQAudioRecorder->resize(890, 604);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQAudioRecorder->setFont(font);
        actRecord = new QAction(TestQAudioRecorder);
        actRecord->setObjectName(QStringLiteral("actRecord"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/626.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actRecord->setIcon(icon);
        actPause = new QAction(TestQAudioRecorder);
        actPause->setObjectName(QStringLiteral("actPause"));
        actPause->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/622.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actPause->setIcon(icon1);
        actStop = new QAction(TestQAudioRecorder);
        actStop->setObjectName(QStringLiteral("actStop"));
        actStop->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon2);
        actQuit = new QAction(TestQAudioRecorder);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon3);
        centralwidget = new QWidget(TestQAudioRecorder);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        btnGetFile = new QPushButton(groupBox_3);
        btnGetFile->setObjectName(QStringLiteral("btnGetFile"));
        btnGetFile->setMinimumSize(QSize(200, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnGetFile->setIcon(icon4);

        horizontalLayout->addWidget(btnGetFile);

        editOutputFile = new QLineEdit(groupBox_3);
        editOutputFile->setObjectName(QStringLiteral("editOutputFile"));

        horizontalLayout->addWidget(editOutputFile);

        LabPassTime = new QLabel(groupBox_3);
        LabPassTime->setObjectName(QStringLiteral("LabPassTime"));
        LabPassTime->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(LabPassTime);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, -1, 3, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 30));
        label->setMaximumSize(QSize(70, 16777215));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboDevices = new QComboBox(groupBox);
        comboDevices->setObjectName(QStringLiteral("comboDevices"));

        gridLayout->addWidget(comboDevices, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 30));
        label_2->setMaximumSize(QSize(70, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboCodec = new QComboBox(groupBox);
        comboCodec->setObjectName(QStringLiteral("comboCodec"));

        gridLayout->addWidget(comboCodec, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 30));
        label_3->setMaximumSize(QSize(70, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboSampleRate = new QComboBox(groupBox);
        comboSampleRate->setObjectName(QStringLiteral("comboSampleRate"));

        gridLayout->addWidget(comboSampleRate, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 30));
        label_4->setMaximumSize(QSize(70, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboChannels = new QComboBox(groupBox);
        comboChannels->setObjectName(QStringLiteral("comboChannels"));

        gridLayout->addWidget(comboChannels, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBitrate = new QComboBox(groupBox_2);
        comboBitrate->setObjectName(QStringLiteral("comboBitrate"));

        gridLayout_2->addWidget(comboBitrate, 1, 1, 1, 1);

        radioQuality = new QRadioButton(groupBox_2);
        radioQuality->setObjectName(QStringLiteral("radioQuality"));
        radioQuality->setMinimumSize(QSize(100, 30));
        radioQuality->setChecked(true);

        gridLayout_2->addWidget(radioQuality, 0, 0, 1, 1);

        sliderQuality = new QSlider(groupBox_2);
        sliderQuality->setObjectName(QStringLiteral("sliderQuality"));
        sliderQuality->setMaximum(8);
        sliderQuality->setOrientation(Qt::Horizontal);
        sliderQuality->setTickPosition(QSlider::TicksAbove);
        sliderQuality->setTickInterval(1);

        gridLayout_2->addWidget(sliderQuality, 0, 1, 1, 1);

        radioBitrate = new QRadioButton(groupBox_2);
        radioBitrate->setObjectName(QStringLiteral("radioBitrate"));
        radioBitrate->setMinimumSize(QSize(100, 30));
        radioBitrate->setChecked(false);

        gridLayout_2->addWidget(radioBitrate, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(420, 30));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 2, 3, 2);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(200, 30));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        spin_byteCount = new QSpinBox(groupBox_4);
        spin_byteCount->setObjectName(QStringLiteral("spin_byteCount"));
        spin_byteCount->setMaximum(999999999);

        gridLayout_3->addWidget(spin_byteCount, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(200, 30));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        spin_duration = new QSpinBox(groupBox_4);
        spin_duration->setObjectName(QStringLiteral("spin_duration"));
        spin_duration->setMaximum(999999999);

        gridLayout_3->addWidget(spin_duration, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(200, 30));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        spin_frameCount = new QSpinBox(groupBox_4);
        spin_frameCount->setObjectName(QStringLiteral("spin_frameCount"));
        spin_frameCount->setMaximum(999999999);

        gridLayout_3->addWidget(spin_frameCount, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(200, 30));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        spin_sampleCount = new QSpinBox(groupBox_4);
        spin_sampleCount->setObjectName(QStringLiteral("spin_sampleCount"));
        spin_sampleCount->setMaximum(999999999);

        gridLayout_3->addWidget(spin_sampleCount, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(4);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        spin_channelCount = new QSpinBox(groupBox_5);
        spin_channelCount->setObjectName(QStringLiteral("spin_channelCount"));

        gridLayout_4->addWidget(spin_channelCount, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        edit_byteOrder = new QLineEdit(groupBox_5);
        edit_byteOrder->setObjectName(QStringLiteral("edit_byteOrder"));

        gridLayout_4->addWidget(edit_byteOrder, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        edit_codec = new QLineEdit(groupBox_5);
        edit_codec->setObjectName(QStringLiteral("edit_codec"));

        gridLayout_4->addWidget(edit_codec, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_13, 3, 0, 1, 1);

        edit_sampleType = new QLineEdit(groupBox_5);
        edit_sampleType->setObjectName(QStringLiteral("edit_sampleType"));

        gridLayout_4->addWidget(edit_sampleType, 3, 1, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_14, 4, 0, 1, 1);

        spin_sampleSize = new QSpinBox(groupBox_5);
        spin_sampleSize->setObjectName(QStringLiteral("spin_sampleSize"));
        spin_sampleSize->setMaximum(999);

        gridLayout_4->addWidget(spin_sampleSize, 4, 1, 1, 1);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_15, 5, 0, 1, 1);

        spin_sampleRate = new QSpinBox(groupBox_5);
        spin_sampleRate->setObjectName(QStringLiteral("spin_sampleRate"));
        spin_sampleRate->setMaximum(9999999);

        gridLayout_4->addWidget(spin_sampleRate, 5, 1, 1, 1);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(150, 30));

        gridLayout_4->addWidget(label_16, 6, 0, 1, 1);

        spin_bytesPerFrame = new QSpinBox(groupBox_5);
        spin_bytesPerFrame->setObjectName(QStringLiteral("spin_bytesPerFrame"));
        spin_bytesPerFrame->setMaximum(999999);

        gridLayout_4->addWidget(spin_bytesPerFrame, 6, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_5);


        gridLayout_5->addWidget(groupBox_4, 1, 1, 1, 1);

        TestQAudioRecorder->setCentralWidget(centralwidget);
        toolBar = new QToolBar(TestQAudioRecorder);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQAudioRecorder->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actRecord);
        toolBar->addAction(actPause);
        toolBar->addAction(actStop);
        toolBar->addAction(actQuit);

        retranslateUi(TestQAudioRecorder);
        QObject::connect(actQuit, SIGNAL(triggered()), TestQAudioRecorder, SLOT(close()));

        QMetaObject::connectSlotsByName(TestQAudioRecorder);
    } // setupUi

    void retranslateUi(QMainWindow *TestQAudioRecorder)
    {
        TestQAudioRecorder->setWindowTitle(QApplication::translate("TestQAudioRecorder", "TestQAudioRecorder", Q_NULLPTR));
        actRecord->setText(QApplication::translate("TestQAudioRecorder", "\345\275\225\351\237\263", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actRecord->setToolTip(QApplication::translate("TestQAudioRecorder", "\345\275\225\351\237\263", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actPause->setText(QApplication::translate("TestQAudioRecorder", "\346\232\202\345\201\234", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actPause->setToolTip(QApplication::translate("TestQAudioRecorder", "\346\232\202\345\201\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("TestQAudioRecorder", "\345\201\234\346\255\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("TestQAudioRecorder", "\345\201\234\346\255\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("TestQAudioRecorder", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("TestQAudioRecorder", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QString());
        btnGetFile->setText(QApplication::translate("TestQAudioRecorder", "\350\256\276\347\275\256\345\275\225\351\237\263\350\276\223\345\207\272\346\226\207\344\273\266", Q_NULLPTR));
        LabPassTime->setText(QApplication::translate("TestQAudioRecorder", "\345\267\262\345\275\225\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestQAudioRecorder", "\345\275\225\351\237\263\350\256\276\347\275\256\357\274\210QAudioEncoderSettings\357\274\211", Q_NULLPTR));
        label->setText(QApplication::translate("TestQAudioRecorder", "\350\276\223\345\205\245\350\256\276\345\244\207", Q_NULLPTR));
        label_2->setText(QApplication::translate("TestQAudioRecorder", "\351\237\263\351\242\221\347\274\226\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\347\216\207", Q_NULLPTR));
        label_4->setText(QApplication::translate("TestQAudioRecorder", "\351\200\232\351\201\223\346\225\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TestQAudioRecorder", "\347\274\226\347\240\201\346\250\241\345\274\217", Q_NULLPTR));
        radioQuality->setText(QApplication::translate("TestQAudioRecorder", "\345\233\272\345\256\232\351\237\263\351\242\221\350\264\250\351\207\217", Q_NULLPTR));
        radioBitrate->setText(QApplication::translate("TestQAudioRecorder", "\345\233\272\345\256\232\345\216\213\347\274\251\346\257\224\347\211\271\347\216\207", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("TestQAudioRecorder", "\346\216\242\346\265\213QAudioBuffer\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("TestQAudioRecorder", "  \347\274\223\345\206\262\345\214\272\345\255\227\350\212\202\346\225\260", Q_NULLPTR));
        spin_byteCount->setSuffix(QApplication::translate("TestQAudioRecorder", "  bytes", Q_NULLPTR));
        label_7->setText(QApplication::translate("TestQAudioRecorder", "  \347\274\223\345\206\262\345\214\272\346\227\266\351\225\277(ms)", Q_NULLPTR));
        spin_duration->setSuffix(QApplication::translate("TestQAudioRecorder", "  ms", Q_NULLPTR));
        label_8->setText(QApplication::translate("TestQAudioRecorder", "  \347\274\223\345\206\262\345\214\272\345\270\247\346\225\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("TestQAudioRecorder", "  \347\274\223\345\206\262\345\214\272\351\207\207\346\240\267\346\225\260", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("TestQAudioRecorder", "QAudioFormat\344\277\241\346\201\257", Q_NULLPTR));
        label_10->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\351\200\232\351\201\223\346\225\260", Q_NULLPTR));
        label_11->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\345\255\227\350\212\202\345\272\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\347\274\226\347\240\201\346\240\274\345\274\217", Q_NULLPTR));
        label_13->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\347\202\271\346\225\260\346\215\256\347\261\273\345\236\213", Q_NULLPTR));
        label_14->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\345\244\247\345\260\217", Q_NULLPTR));
        spin_sampleSize->setSuffix(QApplication::translate("TestQAudioRecorder", "  bits", Q_NULLPTR));
        label_15->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\347\216\207", Q_NULLPTR));
        spin_sampleRate->setSuffix(QApplication::translate("TestQAudioRecorder", "  Hz", Q_NULLPTR));
        label_16->setText(QApplication::translate("TestQAudioRecorder", "\351\207\207\346\240\267\346\257\217\345\270\247\345\255\227\350\212\202\346\225\260", Q_NULLPTR));
        spin_bytesPerFrame->setSuffix(QApplication::translate("TestQAudioRecorder", "  bytes", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TestQAudioRecorder", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQAudioRecorder: public Ui_TestQAudioRecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQAUDIORECORDER_H
