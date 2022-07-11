/********************************************************************************
** Form generated from reading UI file 'TestStandardDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSTANDARDDIALOG_H
#define UI_TESTSTANDARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestStandardDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnClearText;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnInputString;
    QPushButton *btnInputInt;
    QPushButton *btnInputFloat;
    QPushButton *btnInputItem;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnMsgQuestion;
    QPushButton *btnMsgInformation;
    QPushButton *btnMsgWarning;
    QPushButton *btnMsgCritical;
    QPushButton *btnMsgAbout;
    QPushButton *btnMsgAboutQt;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnSelDir;
    QPushButton *btnColor;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnFont;
    QPushButton *btnOpenMulti;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *TestStandardDialog)
    {
        if (TestStandardDialog->objectName().isEmpty())
            TestStandardDialog->setObjectName(QStringLiteral("TestStandardDialog"));
        TestStandardDialog->resize(1194, 719);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestStandardDialog->setFont(font);
        layoutWidget = new QWidget(TestStandardDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(19, 20, 1151, 371));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 9, -1, -1);
        btnClearText = new QPushButton(groupBox_4);
        btnClearText->setObjectName(QStringLiteral("btnClearText"));
        btnClearText->setMinimumSize(QSize(38, 80));

        horizontalLayout->addWidget(btnClearText);


        gridLayout_4->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        btnInputString = new QPushButton(groupBox_3);
        btnInputString->setObjectName(QStringLiteral("btnInputString"));
        btnInputString->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(btnInputString, 0, 0, 1, 1);

        btnInputInt = new QPushButton(groupBox_3);
        btnInputInt->setObjectName(QStringLiteral("btnInputInt"));
        btnInputInt->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(btnInputInt, 0, 1, 1, 1);

        btnInputFloat = new QPushButton(groupBox_3);
        btnInputFloat->setObjectName(QStringLiteral("btnInputFloat"));
        btnInputFloat->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(btnInputFloat, 1, 0, 1, 1);

        btnInputItem = new QPushButton(groupBox_3);
        btnInputItem->setObjectName(QStringLiteral("btnInputItem"));
        btnInputItem->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(btnInputItem, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        btnMsgQuestion = new QPushButton(groupBox_2);
        btnMsgQuestion->setObjectName(QStringLiteral("btnMsgQuestion"));
        btnMsgQuestion->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgQuestion, 0, 0, 1, 1);

        btnMsgInformation = new QPushButton(groupBox_2);
        btnMsgInformation->setObjectName(QStringLiteral("btnMsgInformation"));
        btnMsgInformation->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgInformation, 0, 1, 1, 1);

        btnMsgWarning = new QPushButton(groupBox_2);
        btnMsgWarning->setObjectName(QStringLiteral("btnMsgWarning"));
        btnMsgWarning->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgWarning, 0, 2, 1, 1);

        btnMsgCritical = new QPushButton(groupBox_2);
        btnMsgCritical->setObjectName(QStringLiteral("btnMsgCritical"));
        btnMsgCritical->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgCritical, 1, 0, 1, 1);

        btnMsgAbout = new QPushButton(groupBox_2);
        btnMsgAbout->setObjectName(QStringLiteral("btnMsgAbout"));
        btnMsgAbout->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgAbout, 1, 1, 1, 1);

        btnMsgAboutQt = new QPushButton(groupBox_2);
        btnMsgAboutQt->setObjectName(QStringLiteral("btnMsgAboutQt"));
        btnMsgAboutQt->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(btnMsgAboutQt, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(220, 0));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        btnSelDir = new QPushButton(groupBox);
        btnSelDir->setObjectName(QStringLiteral("btnSelDir"));

        gridLayout->addWidget(btnSelDir, 1, 0, 1, 1);

        btnColor = new QPushButton(groupBox);
        btnColor->setObjectName(QStringLiteral("btnColor"));

        gridLayout->addWidget(btnColor, 2, 0, 1, 1);

        btnOpen = new QPushButton(groupBox);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));

        gridLayout->addWidget(btnOpen, 0, 0, 1, 1);

        btnSave = new QPushButton(groupBox);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        gridLayout->addWidget(btnSave, 1, 1, 1, 1);

        btnFont = new QPushButton(groupBox);
        btnFont->setObjectName(QStringLiteral("btnFont"));

        gridLayout->addWidget(btnFont, 2, 1, 1, 1);

        btnOpenMulti = new QPushButton(groupBox);
        btnOpenMulti->setObjectName(QStringLiteral("btnOpenMulti"));

        gridLayout->addWidget(btnOpenMulti, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(TestStandardDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 410, 1151, 301));

        retranslateUi(TestStandardDialog);

        QMetaObject::connectSlotsByName(TestStandardDialog);
    } // setupUi

    void retranslateUi(QDialog *TestStandardDialog)
    {
        TestStandardDialog->setWindowTitle(QApplication::translate("TestStandardDialog", "TestStandardDialog", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        btnClearText->setText(QApplication::translate("TestStandardDialog", "\346\270\205\351\231\244\346\226\207\346\234\254\346\241\206\345\206\205\345\256\271", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("TestStandardDialog", "\346\240\207\345\207\206\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206 QInputDialog", Q_NULLPTR));
        btnInputString->setText(QApplication::translate("TestStandardDialog", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262", Q_NULLPTR));
        btnInputInt->setText(QApplication::translate("TestStandardDialog", "\350\276\223\345\205\245\346\225\264\346\225\260", Q_NULLPTR));
        btnInputFloat->setText(QApplication::translate("TestStandardDialog", "\350\276\223\345\205\245\346\265\256\347\202\271\346\225\260", Q_NULLPTR));
        btnInputItem->setText(QApplication::translate("TestStandardDialog", "\346\235\241\347\233\256\351\200\211\346\213\251\350\276\223\345\205\245", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TestStandardDialog", "\346\240\207\345\207\206\346\266\210\346\201\257\346\241\206 QMessageBox", Q_NULLPTR));
        btnMsgQuestion->setText(QApplication::translate("TestStandardDialog", "question", Q_NULLPTR));
        btnMsgInformation->setText(QApplication::translate("TestStandardDialog", "information", Q_NULLPTR));
        btnMsgWarning->setText(QApplication::translate("TestStandardDialog", "warning", Q_NULLPTR));
        btnMsgCritical->setText(QApplication::translate("TestStandardDialog", "critical", Q_NULLPTR));
        btnMsgAbout->setText(QApplication::translate("TestStandardDialog", "about", Q_NULLPTR));
        btnMsgAboutQt->setText(QApplication::translate("TestStandardDialog", "aboutQt", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestStandardDialog", "\346\240\207\345\207\206\345\257\271\350\257\235\346\241\206", Q_NULLPTR));
        btnSelDir->setText(QApplication::translate("TestStandardDialog", "\351\200\211\346\213\251\345\267\262\346\234\211\347\233\256\345\275\225", Q_NULLPTR));
        btnColor->setText(QApplication::translate("TestStandardDialog", "\351\200\211\346\213\251\351\242\234\350\211\262", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("TestStandardDialog", "\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\344\273\266", Q_NULLPTR));
        btnSave->setText(QApplication::translate("TestStandardDialog", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        btnFont->setText(QApplication::translate("TestStandardDialog", "\351\200\211\346\213\251\345\255\227\344\275\223", Q_NULLPTR));
        btnOpenMulti->setText(QApplication::translate("TestStandardDialog", "\346\211\223\345\274\200\345\244\232\344\270\252\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestStandardDialog: public Ui_TestStandardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSTANDARDDIALOG_H
