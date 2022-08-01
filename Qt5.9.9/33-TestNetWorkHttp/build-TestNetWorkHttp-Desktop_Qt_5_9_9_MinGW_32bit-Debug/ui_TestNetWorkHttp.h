/********************************************************************************
** Form generated from reading UI file 'TestNetWorkHttp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTNETWORKHTTP_H
#define UI_TESTNETWORKHTTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestNetWorkHttp
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editURL;
    QPushButton *btnDownload;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *editPath;
    QPushButton *btnDefaultPath;
    QLabel *label_3;
    QProgressBar *progressBar;
    QCheckBox *checkOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestNetWorkHttp)
    {
        if (TestNetWorkHttp->objectName().isEmpty())
            TestNetWorkHttp->setObjectName(QStringLiteral("TestNetWorkHttp"));
        TestNetWorkHttp->resize(659, 247);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestNetWorkHttp->setFont(font);
        centralwidget = new QWidget(TestNetWorkHttp);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 30));

        horizontalLayout->addWidget(label);

        editURL = new QLineEdit(groupBox);
        editURL->setObjectName(QStringLiteral("editURL"));
        editURL->setMinimumSize(QSize(0, 30));
        editURL->setClearButtonEnabled(true);

        horizontalLayout->addWidget(editURL);

        btnDownload = new QPushButton(groupBox);
        btnDownload->setObjectName(QStringLiteral("btnDownload"));
        btnDownload->setMinimumSize(QSize(80, 30));
        btnDownload->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(btnDownload);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        editPath = new QLineEdit(groupBox_2);
        editPath->setObjectName(QStringLiteral("editPath"));

        gridLayout->addWidget(editPath, 0, 1, 1, 1);

        btnDefaultPath = new QPushButton(groupBox_2);
        btnDefaultPath->setObjectName(QStringLiteral("btnDefaultPath"));
        btnDefaultPath->setMinimumSize(QSize(150, 30));

        gridLayout->addWidget(btnDefaultPath, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 1, 1, 1);

        checkOpen = new QCheckBox(groupBox_2);
        checkOpen->setObjectName(QStringLiteral("checkOpen"));
        checkOpen->setChecked(true);

        gridLayout->addWidget(checkOpen, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        TestNetWorkHttp->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TestNetWorkHttp);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestNetWorkHttp->setStatusBar(statusbar);

        retranslateUi(TestNetWorkHttp);

        QMetaObject::connectSlotsByName(TestNetWorkHttp);
    } // setupUi

    void retranslateUi(QMainWindow *TestNetWorkHttp)
    {
        TestNetWorkHttp->setWindowTitle(QApplication::translate("TestNetWorkHttp", "TestNetWorkHttp", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("TestNetWorkHttp", "URL:", Q_NULLPTR));
        btnDownload->setText(QApplication::translate("TestNetWorkHttp", "\344\270\213\350\275\275", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("TestNetWorkHttp", "\344\270\213\350\275\275\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
        btnDefaultPath->setText(QApplication::translate("TestNetWorkHttp", "\350\256\276\347\275\256\344\270\213\350\275\275\350\267\257\345\276\204", Q_NULLPTR));
        label_3->setText(QApplication::translate("TestNetWorkHttp", "\346\226\207\344\273\266\344\270\213\350\275\275\350\277\233\345\272\246", Q_NULLPTR));
        checkOpen->setText(QApplication::translate("TestNetWorkHttp", "\345\256\214\346\210\220\345\220\216\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestNetWorkHttp: public Ui_TestNetWorkHttp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTNETWORKHTTP_H
