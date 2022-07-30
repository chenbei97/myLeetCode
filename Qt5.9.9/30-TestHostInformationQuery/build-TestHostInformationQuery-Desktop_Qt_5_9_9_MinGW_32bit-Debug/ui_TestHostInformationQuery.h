/********************************************************************************
** Form generated from reading UI file 'TestHostInformationQuery.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTHOSTINFORMATIONQUERY_H
#define UI_TESTHOSTINFORMATIONQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestHostInformationQuery
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *btnGetHostInfo;
    QPushButton *btnGetDNS;
    QLabel *label;
    QLineEdit *editHost;
    QPushButton *btnLookup;
    QGroupBox *groupBox_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QPushButton *btnDetail;
    QPushButton *btnALLInterface;
    QPushButton *btnClear;
    QCheckBox *chkOnlyIPv4;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *TestHostInformationQuery)
    {
        if (TestHostInformationQuery->objectName().isEmpty())
            TestHostInformationQuery->setObjectName(QStringLiteral("TestHostInformationQuery"));
        TestHostInformationQuery->resize(1059, 876);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestHostInformationQuery->setFont(font);
        centralwidget = new QWidget(TestHostInformationQuery);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(330, 440));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 302, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(300, 30));
        label_2->setMaximumSize(QSize(300, 30));

        verticalLayout->addWidget(label_2);

        btnGetHostInfo = new QPushButton(widget);
        btnGetHostInfo->setObjectName(QStringLiteral("btnGetHostInfo"));
        btnGetHostInfo->setMinimumSize(QSize(300, 50));
        btnGetHostInfo->setMaximumSize(QSize(300, 50));

        verticalLayout->addWidget(btnGetHostInfo);

        btnGetDNS = new QPushButton(widget);
        btnGetDNS->setObjectName(QStringLiteral("btnGetDNS"));
        btnGetDNS->setMinimumSize(QSize(300, 50));
        btnGetDNS->setMaximumSize(QSize(300, 50));

        verticalLayout->addWidget(btnGetDNS);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(300, 50));
        label->setMaximumSize(QSize(300, 50));

        verticalLayout->addWidget(label);

        editHost = new QLineEdit(widget);
        editHost->setObjectName(QStringLiteral("editHost"));
        editHost->setMinimumSize(QSize(300, 50));
        editHost->setMaximumSize(QSize(300, 50));

        verticalLayout->addWidget(editHost);

        btnLookup = new QPushButton(widget);
        btnLookup->setObjectName(QStringLiteral("btnLookup"));
        btnLookup->setMinimumSize(QSize(300, 50));
        btnLookup->setMaximumSize(QSize(300, 50));

        verticalLayout->addWidget(btnLookup);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(330, 250));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 311, 311));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(300, 50));
        label_3->setMaximumSize(QSize(300, 50));

        verticalLayout_2->addWidget(label_3);

        btnDetail = new QPushButton(widget1);
        btnDetail->setObjectName(QStringLiteral("btnDetail"));
        btnDetail->setMinimumSize(QSize(300, 50));
        btnDetail->setMaximumSize(QSize(300, 50));

        verticalLayout_2->addWidget(btnDetail);

        btnALLInterface = new QPushButton(widget1);
        btnALLInterface->setObjectName(QStringLiteral("btnALLInterface"));
        btnALLInterface->setMinimumSize(QSize(300, 50));
        btnALLInterface->setMaximumSize(QSize(0, 50));

        verticalLayout_2->addWidget(btnALLInterface);

        btnClear = new QPushButton(widget1);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setMinimumSize(QSize(300, 50));
        btnClear->setMaximumSize(QSize(300, 50));

        verticalLayout_2->addWidget(btnClear);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        chkOnlyIPv4 = new QCheckBox(centralwidget);
        chkOnlyIPv4->setObjectName(QStringLiteral("chkOnlyIPv4"));
        chkOnlyIPv4->setMinimumSize(QSize(300, 50));
        chkOnlyIPv4->setMaximumSize(QSize(300, 50));
        chkOnlyIPv4->setChecked(true);

        gridLayout->addWidget(chkOnlyIPv4, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 1, 3, 1);

        TestHostInformationQuery->setCentralWidget(centralwidget);

        retranslateUi(TestHostInformationQuery);

        QMetaObject::connectSlotsByName(TestHostInformationQuery);
    } // setupUi

    void retranslateUi(QMainWindow *TestHostInformationQuery)
    {
        TestHostInformationQuery->setWindowTitle(QApplication::translate("TestHostInformationQuery", "TestHostInformationQuery", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("TestHostInformationQuery", "QHostInfo\346\226\271\345\274\217\346\237\245\346\211\276", Q_NULLPTR));
        btnGetHostInfo->setText(QApplication::translate("TestHostInformationQuery", "\350\216\267\345\217\226\346\234\254\346\234\272\345\220\215\345\222\214IP\345\234\260\345\235\200", Q_NULLPTR));
        btnGetDNS->setText(QApplication::translate("TestHostInformationQuery", "\350\216\267\345\217\226\346\234\254\346\234\272DNS\345\237\237\345\220\215", Q_NULLPTR));
        label->setText(QApplication::translate("TestHostInformationQuery", "\350\246\201\346\237\245\346\211\276\347\232\204\345\237\237\345\220\215\357\274\232", Q_NULLPTR));
        editHost->setText(QApplication::translate("TestHostInformationQuery", "www.163.com", Q_NULLPTR));
        btnLookup->setText(QApplication::translate("TestHostInformationQuery", "\346\237\245\346\211\276\346\214\207\345\256\232\345\237\237\345\220\215IP\345\234\260\345\235\200", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("TestHostInformationQuery", "QNetworkInterface\346\226\271\345\274\217\346\237\245\346\211\276", Q_NULLPTR));
        btnDetail->setText(QApplication::translate("TestHostInformationQuery", "\350\216\267\345\217\226\346\234\254\346\234\272IP\345\234\260\345\235\200", Q_NULLPTR));
        btnALLInterface->setText(QApplication::translate("TestHostInformationQuery", "\350\216\267\345\217\226\347\275\221\347\273\234\346\216\245\345\217\243\345\210\227\350\241\250", Q_NULLPTR));
        btnClear->setText(QApplication::translate("TestHostInformationQuery", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
        chkOnlyIPv4->setText(QApplication::translate("TestHostInformationQuery", "\346\230\257\345\220\246\345\217\252\346\230\276\347\244\272IPv4\345\234\260\345\235\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestHostInformationQuery: public Ui_TestHostInformationQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTHOSTINFORMATIONQUERY_H
