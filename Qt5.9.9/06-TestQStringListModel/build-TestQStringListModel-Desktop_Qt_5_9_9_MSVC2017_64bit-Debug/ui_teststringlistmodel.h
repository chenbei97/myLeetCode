/********************************************************************************
** Form generated from reading UI file 'teststringlistmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSTRINGLISTMODEL_H
#define UI_TESTSTRINGLISTMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestStringListModel
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *btnIniList;
    QPushButton *btnListAppend;
    QPushButton *btnListInsert;
    QPushButton *btnListDelete;
    QPushButton *btnListClear;
    QListView *listView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnTextClear;
    QPushButton *btnTextImport;
    QPlainTextEdit *plainTextEdit;
    QLabel *LabInfo1;
    QLabel *LabInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestStringListModel)
    {
        if (TestStringListModel->objectName().isEmpty())
            TestStringListModel->setObjectName(QStringLiteral("TestStringListModel"));
        TestStringListModel->resize(1020, 750);
        TestStringListModel->setMinimumSize(QSize(1000, 750));
        TestStringListModel->setMaximumSize(QSize(1020, 800));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestStringListModel->setFont(font);
        centralwidget = new QWidget(TestStringListModel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 10, 981, 601));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 4);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnIniList = new QPushButton(groupBox);
        btnIniList->setObjectName(QStringLiteral("btnIniList"));
        btnIniList->setMinimumSize(QSize(200, 30));
        btnIniList->setMaximumSize(QSize(120, 100));

        gridLayout->addWidget(btnIniList, 0, 0, 1, 1);

        btnListAppend = new QPushButton(groupBox);
        btnListAppend->setObjectName(QStringLiteral("btnListAppend"));
        btnListAppend->setMinimumSize(QSize(200, 30));
        btnListAppend->setMaximumSize(QSize(120, 100));

        gridLayout->addWidget(btnListAppend, 1, 0, 1, 1);

        btnListInsert = new QPushButton(groupBox);
        btnListInsert->setObjectName(QStringLiteral("btnListInsert"));
        btnListInsert->setMinimumSize(QSize(200, 30));
        btnListInsert->setMaximumSize(QSize(400, 100));

        gridLayout->addWidget(btnListInsert, 1, 1, 1, 1);

        btnListDelete = new QPushButton(groupBox);
        btnListDelete->setObjectName(QStringLiteral("btnListDelete"));
        btnListDelete->setMinimumSize(QSize(200, 30));
        btnListDelete->setMaximumSize(QSize(400, 100));

        gridLayout->addWidget(btnListDelete, 2, 0, 1, 1);

        btnListClear = new QPushButton(groupBox);
        btnListClear->setObjectName(QStringLiteral("btnListClear"));
        btnListClear->setMinimumSize(QSize(200, 30));
        btnListClear->setMaximumSize(QSize(400, 100));

        gridLayout->addWidget(btnListClear, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(250, 160));
        listView->setMaximumSize(QSize(20000, 20000));

        verticalLayout_3->addWidget(listView);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnTextClear = new QPushButton(groupBox_2);
        btnTextClear->setObjectName(QStringLiteral("btnTextClear"));
        btnTextClear->setMinimumSize(QSize(250, 30));
        btnTextClear->setMaximumSize(QSize(2000, 100));

        verticalLayout->addWidget(btnTextClear);

        btnTextImport = new QPushButton(groupBox_2);
        btnTextImport->setObjectName(QStringLiteral("btnTextImport"));
        btnTextImport->setMinimumSize(QSize(250, 30));
        btnTextImport->setMaximumSize(QSize(2000, 100));

        verticalLayout->addWidget(btnTextImport);


        verticalLayout_2->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        splitter->addWidget(groupBox_2);
        LabInfo1 = new QLabel(centralwidget);
        LabInfo1->setObjectName(QStringLiteral("LabInfo1"));
        LabInfo1->setGeometry(QRect(10, 630, 400, 50));
        LabInfo1->setMinimumSize(QSize(400, 50));
        LabInfo = new QLabel(centralwidget);
        LabInfo->setObjectName(QStringLiteral("LabInfo"));
        LabInfo->setGeometry(QRect(430, 630, 400, 50));
        LabInfo->setMinimumSize(QSize(400, 50));
        TestStringListModel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestStringListModel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1020, 23));
        TestStringListModel->setMenuBar(menubar);
        statusbar = new QStatusBar(TestStringListModel);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestStringListModel->setStatusBar(statusbar);

        retranslateUi(TestStringListModel);

        QMetaObject::connectSlotsByName(TestStringListModel);
    } // setupUi

    void retranslateUi(QMainWindow *TestStringListModel)
    {
        TestStringListModel->setWindowTitle(QApplication::translate("TestStringListModel", "TestStringListModel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TestStringListModel", "QListView", Q_NULLPTR));
        btnIniList->setText(QApplication::translate("TestStringListModel", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", Q_NULLPTR));
        btnListAppend->setText(QApplication::translate("TestStringListModel", "\346\267\273\345\212\240\351\241\271", Q_NULLPTR));
        btnListInsert->setText(QApplication::translate("TestStringListModel", "\346\217\222\345\205\245\351\241\271", Q_NULLPTR));
        btnListDelete->setText(QApplication::translate("TestStringListModel", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", Q_NULLPTR));
        btnListClear->setText(QApplication::translate("TestStringListModel", "\346\270\205\351\231\244\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TestStringListModel", "QPlainTextEdit", Q_NULLPTR));
        btnTextClear->setText(QApplication::translate("TestStringListModel", "\346\270\205\347\251\272\346\226\207\346\234\254", Q_NULLPTR));
        btnTextImport->setText(QApplication::translate("TestStringListModel", "\346\230\276\347\244\272\346\225\260\346\215\256\346\250\241\345\236\213\347\232\204StringList", Q_NULLPTR));
        LabInfo1->setText(QApplication::translate("TestStringListModel", "\345\275\223\345\211\215\351\241\271\347\232\204ModelIndex", Q_NULLPTR));
        LabInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TestStringListModel: public Ui_TestStringListModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSTRINGLISTMODEL_H
