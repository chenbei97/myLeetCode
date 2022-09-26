/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *sendPushButton;
    QLabel *label_2;
    QTableWidget *userListTableWidget;
    QPushButton *searchPushButton;
    QLabel *userLabel;
    QTextEdit *chatTextEdit;
    QLabel *label;
    QLabel *label_5;
    QPushButton *transPushButton;
    QTextBrowser *chatTextBrowser;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(763, 525);
        QFont font;
        font.setFamily(QStringLiteral("System"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sendPushButton = new QPushButton(centralwidget);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));
        sendPushButton->setGeometry(QRect(650, 460, 75, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        sendPushButton->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 0, 250, 65));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resource/search.jpg")));
        userListTableWidget = new QTableWidget(centralwidget);
        if (userListTableWidget->columnCount() < 1)
            userListTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        userListTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        userListTableWidget->setObjectName(QStringLiteral("userListTableWidget"));
        userListTableWidget->setGeometry(QRect(60, 65, 250, 435));
        QFont font2;
        font2.setFamily(QStringLiteral("System"));
        font2.setPointSize(14);
        userListTableWidget->setFont(font2);
        userListTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userListTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userListTableWidget->setShowGrid(false);
        userListTableWidget->horizontalHeader()->setVisible(false);
        userListTableWidget->horizontalHeader()->setDefaultSectionSize(250);
        userListTableWidget->verticalHeader()->setVisible(false);
        searchPushButton = new QPushButton(centralwidget);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));
        searchPushButton->setGeometry(QRect(74, 25, 191, 26));
        searchPushButton->setFlat(true);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(311, 1, 121, 62));
        QFont font3;
        font3.setFamily(QStringLiteral("04b_21"));
        font3.setPointSize(16);
        userLabel->setFont(font3);
        userLabel->setAutoFillBackground(true);
        userLabel->setFrameShape(QFrame::NoFrame);
        userLabel->setFrameShadow(QFrame::Plain);
        userLabel->setAlignment(Qt::AlignCenter);
        chatTextEdit = new QTextEdit(centralwidget);
        chatTextEdit->setObjectName(QStringLiteral("chatTextEdit"));
        chatTextEdit->setGeometry(QRect(310, 400, 431, 97));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 60, 500));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/bar.jpg")));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 365, 432, 40));
        label_5->setFrameShape(QFrame::Box);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resource/tool.jpg")));
        transPushButton = new QPushButton(centralwidget);
        transPushButton->setObjectName(QStringLiteral("transPushButton"));
        transPushButton->setGeometry(QRect(350, 375, 31, 23));
        transPushButton->setFlat(true);
        chatTextBrowser = new QTextBrowser(centralwidget);
        chatTextBrowser->setObjectName(QStringLiteral("chatTextBrowser"));
        chatTextBrowser->setGeometry(QRect(310, 65, 431, 300));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 0, 432, 65));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/title.jpg")));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        userListTableWidget->raise();
        searchPushButton->raise();
        userLabel->raise();
        chatTextEdit->raise();
        label->raise();
        label_5->raise();
        transPushButton->raise();
        chatTextBrowser->raise();
        label_3->raise();
        sendPushButton->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        sendPushButton->setText(QApplication::translate("MainWindow", "\345\217\221 \351\200\201(S)", Q_NULLPTR));
        label_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = userListTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\345\234\250 \347\272\277 \345\245\275 \345\217\213", Q_NULLPTR));
        searchPushButton->setText(QString());
        userLabel->setText(QString());
        label->setText(QString());
        label_5->setText(QString());
        transPushButton->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
