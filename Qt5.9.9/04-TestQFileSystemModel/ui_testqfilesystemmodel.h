/********************************************************************************
** Form generated from reading UI file 'testqfilesystemmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQFILESYSTEMMODEL_H
#define UI_TESTQFILESYSTEMMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestQFileSystemModel
{
public:
    QWidget *centralwidget;
    QSplitter *splitterMain;
    QGroupBox *groupBox3;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QSplitter *splitter;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QGroupBox *groupBox2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *display1;
    QLabel *LabFileName;
    QLabel *display2;
    QLabel *LabFileSize;
    QLabel *display3;
    QLabel *LabType;
    QCheckBox *chkIsDir;
    QLabel *display1_2;
    QLabel *LabPath;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestQFileSystemModel)
    {
        if (TestQFileSystemModel->objectName().isEmpty())
            TestQFileSystemModel->setObjectName(QStringLiteral("TestQFileSystemModel"));
        TestQFileSystemModel->resize(1388, 813);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestQFileSystemModel->setFont(font);
        centralwidget = new QWidget(TestQFileSystemModel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        splitterMain = new QSplitter(centralwidget);
        splitterMain->setObjectName(QStringLiteral("splitterMain"));
        splitterMain->setGeometry(QRect(20, 0, 1351, 551));
        splitterMain->setOrientation(Qt::Horizontal);
        groupBox3 = new QGroupBox(splitterMain);
        groupBox3->setObjectName(QStringLiteral("groupBox3"));
        verticalLayout_3 = new QVBoxLayout(groupBox3);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 4);
        treeView = new QTreeView(groupBox3);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout_3->addWidget(treeView);

        splitterMain->addWidget(groupBox3);
        splitter = new QSplitter(splitterMain);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox1 = new QGroupBox(splitter);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        verticalLayout = new QVBoxLayout(groupBox1);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        listView = new QListView(groupBox1);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        splitter->addWidget(groupBox1);
        groupBox2 = new QGroupBox(splitter);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        verticalLayout_2 = new QVBoxLayout(groupBox2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        tableView = new QTableView(groupBox2);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        splitter->addWidget(groupBox2);
        splitterMain->addWidget(splitter);
        groupBox4 = new QGroupBox(centralwidget);
        groupBox4->setObjectName(QStringLiteral("groupBox4"));
        groupBox4->setGeometry(QRect(20, 569, 1350, 180));
        groupBox4->setMinimumSize(QSize(1000, 180));
        groupBox4->setMaximumSize(QSize(16777215, 500));
        verticalLayout_4 = new QVBoxLayout(groupBox4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        display1 = new QLabel(groupBox4);
        display1->setObjectName(QStringLiteral("display1"));
        display1->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(display1);

        LabFileName = new QLabel(groupBox4);
        LabFileName->setObjectName(QStringLiteral("LabFileName"));

        horizontalLayout->addWidget(LabFileName);

        display2 = new QLabel(groupBox4);
        display2->setObjectName(QStringLiteral("display2"));
        display2->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(display2);

        LabFileSize = new QLabel(groupBox4);
        LabFileSize->setObjectName(QStringLiteral("LabFileSize"));

        horizontalLayout->addWidget(LabFileSize);

        display3 = new QLabel(groupBox4);
        display3->setObjectName(QStringLiteral("display3"));
        display3->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(display3);

        LabType = new QLabel(groupBox4);
        LabType->setObjectName(QStringLiteral("LabType"));

        horizontalLayout->addWidget(LabType);

        chkIsDir = new QCheckBox(groupBox4);
        chkIsDir->setObjectName(QStringLiteral("chkIsDir"));
        chkIsDir->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(chkIsDir);


        verticalLayout_4->addLayout(horizontalLayout);

        display1_2 = new QLabel(groupBox4);
        display1_2->setObjectName(QStringLiteral("display1_2"));
        display1_2->setMaximumSize(QSize(150, 16777215));

        verticalLayout_4->addWidget(display1_2);

        LabPath = new QLabel(groupBox4);
        LabPath->setObjectName(QStringLiteral("LabPath"));
        LabPath->setMinimumSize(QSize(0, 45));

        verticalLayout_4->addWidget(LabPath);

        TestQFileSystemModel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestQFileSystemModel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1388, 32));
        TestQFileSystemModel->setMenuBar(menubar);
        statusbar = new QStatusBar(TestQFileSystemModel);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestQFileSystemModel->setStatusBar(statusbar);

        retranslateUi(TestQFileSystemModel);

        QMetaObject::connectSlotsByName(TestQFileSystemModel);
    } // setupUi

    void retranslateUi(QMainWindow *TestQFileSystemModel)
    {
        TestQFileSystemModel->setWindowTitle(QApplication::translate("TestQFileSystemModel", "TestQFileSystemModel", Q_NULLPTR));
        groupBox3->setTitle(QApplication::translate("TestQFileSystemModel", "TreeView", Q_NULLPTR));
        groupBox1->setTitle(QApplication::translate("TestQFileSystemModel", "ListView", Q_NULLPTR));
        groupBox2->setTitle(QApplication::translate("TestQFileSystemModel", "TableView", Q_NULLPTR));
        groupBox4->setTitle(QString());
        display1->setText(QApplication::translate("TestQFileSystemModel", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        LabFileName->setText(QString());
        display2->setText(QApplication::translate("TestQFileSystemModel", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        LabFileSize->setText(QString());
        display3->setText(QApplication::translate("TestQFileSystemModel", "\346\226\207\344\273\266\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        LabType->setText(QString());
        chkIsDir->setText(QApplication::translate("TestQFileSystemModel", "\350\212\202\347\202\271\346\230\257\347\233\256\345\275\225", Q_NULLPTR));
        display1_2->setText(QApplication::translate("TestQFileSystemModel", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        LabPath->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TestQFileSystemModel: public Ui_TestQFileSystemModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQFILESYSTEMMODEL_H
