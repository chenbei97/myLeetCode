/********************************************************************************
** Form generated from reading UI file 'TestQStyle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQSTYLE_H
#define UI_TESTQSTYLE_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQStyle
{
public:
    QAction *actOpen;
    QAction *actSave;
    QAction *actFind;
    QAction *actEdit;
    QAction *actQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboSysStyle;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QSpinBox *spinBox;
    QGridLayout *gridLayout_2;
    QPushButton *btnCancelStyleSheet;
    QPushButton *btnSetStyleSheet;
    QPushButton *btnFontLarge;
    QPushButton *btnFontSmall;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestQStyle)
    {
        if (TestQStyle->objectName().isEmpty())
            TestQStyle->setObjectName(QStringLiteral("TestQStyle"));
        TestQStyle->resize(800, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQStyle->setFont(font);
        actOpen = new QAction(TestQStyle);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/open3.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actSave = new QAction(TestQStyle);
        actSave->setObjectName(QStringLiteral("actSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/save1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon1);
        actFind = new QAction(TestQStyle);
        actFind->setObjectName(QStringLiteral("actFind"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/304.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actFind->setIcon(icon2);
        actEdit = new QAction(TestQStyle);
        actEdit->setObjectName(QStringLiteral("actEdit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/812.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actEdit->setIcon(icon3);
        actQuit = new QAction(TestQStyle);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon4);
        centralwidget = new QWidget(TestQStyle);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(750, 200));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 30));
        label_4->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        comboSysStyle = new QComboBox(groupBox_2);
        comboSysStyle->setObjectName(QStringLiteral("comboSysStyle"));

        gridLayout->addWidget(comboSysStyle, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QStringLiteral("selection-color: rgb(85, 170, 255);"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QStringLiteral(""));
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(99);

        gridLayout->addWidget(spinBox, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnCancelStyleSheet = new QPushButton(groupBox_2);
        btnCancelStyleSheet->setObjectName(QStringLiteral("btnCancelStyleSheet"));
        btnCancelStyleSheet->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(btnCancelStyleSheet, 0, 0, 1, 1);

        btnSetStyleSheet = new QPushButton(groupBox_2);
        btnSetStyleSheet->setObjectName(QStringLiteral("btnSetStyleSheet"));
        btnSetStyleSheet->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(btnSetStyleSheet, 0, 1, 1, 1);

        btnFontLarge = new QPushButton(groupBox_2);
        btnFontLarge->setObjectName(QStringLiteral("btnFontLarge"));
        btnFontLarge->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(btnFontLarge, 1, 0, 1, 1);

        btnFontSmall = new QPushButton(groupBox_2);
        btnFontSmall->setObjectName(QStringLiteral("btnFontSmall"));
        btnFontSmall->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(btnFontSmall, 1, 1, 1, 1);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(checkBox, 2, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(100, 30));
        checkBox_2->setChecked(true);

        gridLayout_2->addWidget(checkBox_2, 2, 1, 1, 1);

        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMinimumSize(QSize(100, 30));

        gridLayout_2->addWidget(radioButton, 3, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(100, 30));
        radioButton_2->setChecked(true);

        gridLayout_2->addWidget(radioButton_2, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(plainTextEdit, 1, 0, 1, 1);

        TestQStyle->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TestQStyle);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQStyle->setStatusBar(statusbar);
        toolBar = new QToolBar(TestQStyle);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TestQStyle->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actOpen);
        toolBar->addAction(actEdit);
        toolBar->addAction(actFind);
        toolBar->addAction(actSave);
        toolBar->addAction(actQuit);

        retranslateUi(TestQStyle);
        QObject::connect(actQuit, SIGNAL(triggered()), TestQStyle, SLOT(close()));

        QMetaObject::connectSlotsByName(TestQStyle);
    } // setupUi

    void retranslateUi(QMainWindow *TestQStyle)
    {
        TestQStyle->setWindowTitle(QApplication::translate("TestQStyle", "TestQStyle", Q_NULLPTR));
        actOpen->setText(QApplication::translate("TestQStyle", "\346\211\223\345\274\200", Q_NULLPTR));
        actSave->setText(QApplication::translate("TestQStyle", "\344\277\235\345\255\230", Q_NULLPTR));
        actFind->setText(QApplication::translate("TestQStyle", "\346\237\245\346\211\276", Q_NULLPTR));
        actEdit->setText(QApplication::translate("TestQStyle", "\347\274\226\350\276\221", Q_NULLPTR));
        actQuit->setText(QApplication::translate("TestQStyle", "\345\205\263\351\227\255", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("TestQStyle", "\347\263\273\347\273\237\346\240\267\345\274\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("TestQStyle", "ComboBox", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("TestQStyle", "Item 1", Q_NULLPTR)
         << QApplication::translate("TestQStyle", "Item 2", Q_NULLPTR)
         << QApplication::translate("TestQStyle", "Item 3", Q_NULLPTR)
         << QApplication::translate("TestQStyle", "Item 4", Q_NULLPTR)
        );
        label->setText(QApplication::translate("TestQStyle", "LineEdit", Q_NULLPTR));
        label_5->setText(QApplication::translate("TestQStyle", "SpinBox", Q_NULLPTR));
        btnCancelStyleSheet->setText(QApplication::translate("TestQStyle", "\345\217\226\346\266\210\346\240\267\345\274\217\350\241\250", Q_NULLPTR));
        btnSetStyleSheet->setText(QApplication::translate("TestQStyle", "\345\272\224\347\224\250\346\240\267\345\274\217\350\241\250", Q_NULLPTR));
        btnFontLarge->setText(QApplication::translate("TestQStyle", "\350\256\276\347\275\256\345\244\247\345\255\227\344\275\223", Q_NULLPTR));
        btnFontSmall->setText(QApplication::translate("TestQStyle", "\350\256\276\347\275\256\345\260\217\345\255\227\344\275\223", Q_NULLPTR));
        checkBox->setText(QApplication::translate("TestQStyle", "CheckBox1", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("TestQStyle", "CheckBox2", Q_NULLPTR));
        radioButton->setText(QApplication::translate("TestQStyle", "RadioButton2", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("TestQStyle", "RadioButto2", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("TestQStyle", "#ifndef MAINWINDOW_H\n"
"#define MAINWINDOW_H\n"
"\n"
"#include <QtWidgets>\n"
"\n"
"#include \"ui_mainwindow.h\"\n"
"\n"
"class StyleSheetEditor;\n"
"\n"
"class MainWindow : public QMainWindow\n"
"{\n"
"    Q_OBJECT\n"
"\n"
"public:\n"
"    MainWindow();\n"
"\n"
"private slots:\n"
"    void on_editStyleAction_triggered();\n"
"    void on_aboutAction_triggered();\n"
"\n"
"private:\n"
"    StyleSheetEditor *styleSheetEditor;\n"
"    Ui::MainWindow ui;\n"
"};\n"
"\n"
"#endif", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TestQStyle", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestQStyle: public Ui_TestQStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQSTYLE_H
