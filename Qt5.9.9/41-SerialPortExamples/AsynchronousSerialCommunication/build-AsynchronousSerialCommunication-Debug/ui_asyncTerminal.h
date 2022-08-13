/********************************************************************************
** Form generated from reading UI file 'asyncTerminal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASYNCTERMINAL_H
#define UI_ASYNCTERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <console/terminalTextEditor.h>

QT_BEGIN_NAMESPACE

class Ui_asyncTerminal
{
public:
    QAction *actConnect;
    QAction *actDisconnect;
    QAction *actQuit;
    QAction *actSetPortParams;
    QAction *actAbout;
    QAction *actAboutQt;
    QAction *actClear;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *textEditorGroup;
    QGridLayout *gridLayout_2;
    terminalTextEditor *textEditor;
    QFrame *line;
    QGroupBox *textMonitorGroup;
    QGridLayout *gridLayout;
    QPlainTextEdit *textMonitor;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *asyncTerminal)
    {
        if (asyncTerminal->objectName().isEmpty())
            asyncTerminal->setObjectName(QStringLiteral("asyncTerminal"));
        asyncTerminal->resize(1200, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(asyncTerminal->sizePolicy().hasHeightForWidth());
        asyncTerminal->setSizePolicy(sizePolicy);
        asyncTerminal->setMinimumSize(QSize(1200, 900));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        asyncTerminal->setFont(font);
        asyncTerminal->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actConnect = new QAction(asyncTerminal);
        actConnect->setObjectName(QStringLiteral("actConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actConnect->setIcon(icon);
        actDisconnect = new QAction(asyncTerminal);
        actDisconnect->setObjectName(QStringLiteral("actDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDisconnect->setIcon(icon1);
        actQuit = new QAction(asyncTerminal);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actSetPortParams = new QAction(asyncTerminal);
        actSetPortParams->setObjectName(QStringLiteral("actSetPortParams"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSetPortParams->setIcon(icon3);
        actAbout = new QAction(asyncTerminal);
        actAbout->setObjectName(QStringLiteral("actAbout"));
        actAboutQt = new QAction(asyncTerminal);
        actAboutQt->setObjectName(QStringLiteral("actAboutQt"));
        actClear = new QAction(asyncTerminal);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon4);
        centralwidget = new QWidget(asyncTerminal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        textEditorGroup = new QGroupBox(centralwidget);
        textEditorGroup->setObjectName(QStringLiteral("textEditorGroup"));
        textEditorGroup->setMinimumSize(QSize(770, 768));
        gridLayout_2 = new QGridLayout(textEditorGroup);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEditor = new terminalTextEditor(textEditorGroup);
        textEditor->setObjectName(QStringLiteral("textEditor"));
        textEditor->setMinimumSize(QSize(746, 715));

        gridLayout_2->addWidget(textEditor, 0, 0, 1, 1);


        gridLayout_3->addWidget(textEditorGroup, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFocusPolicy(Qt::ClickFocus);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 1, 1);

        textMonitorGroup = new QGroupBox(centralwidget);
        textMonitorGroup->setObjectName(QStringLiteral("textMonitorGroup"));
        gridLayout = new QGridLayout(textMonitorGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textMonitor = new QPlainTextEdit(textMonitorGroup);
        textMonitor->setObjectName(QStringLiteral("textMonitor"));

        gridLayout->addWidget(textMonitor, 0, 0, 1, 1);


        gridLayout_3->addWidget(textMonitorGroup, 0, 2, 1, 1);

        asyncTerminal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(asyncTerminal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 36));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(14);
        menubar->setFont(font1);
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        asyncTerminal->setMenuBar(menubar);
        statusbar = new QStatusBar(asyncTerminal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        asyncTerminal->setStatusBar(statusbar);
        toolBar = new QToolBar(asyncTerminal);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QFont font2;
        font2.setPointSize(14);
        toolBar->setFont(font2);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        asyncTerminal->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actSetPortParams);
        menu->addAction(actQuit);
        menu_2->addAction(actConnect);
        menu_2->addAction(actDisconnect);
        menu_2->addAction(actClear);
        menu_4->addAction(actAbout);
        menu_4->addAction(actAboutQt);
        toolBar->addAction(actConnect);
        toolBar->addAction(actDisconnect);
        toolBar->addAction(actSetPortParams);
        toolBar->addAction(actClear);
        toolBar->addAction(actQuit);

        retranslateUi(asyncTerminal);

        QMetaObject::connectSlotsByName(asyncTerminal);
    } // setupUi

    void retranslateUi(QMainWindow *asyncTerminal)
    {
        asyncTerminal->setWindowTitle(QApplication::translate("asyncTerminal", "asyncTerminal", Q_NULLPTR));
        actConnect->setText(QApplication::translate("asyncTerminal", "\350\277\236\346\216\245\344\270\262\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actConnect->setToolTip(QApplication::translate("asyncTerminal", "\350\277\236\346\216\245\344\270\262\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actDisconnect->setText(QApplication::translate("asyncTerminal", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actDisconnect->setToolTip(QApplication::translate("asyncTerminal", "\346\226\255\345\274\200\344\270\262\345\217\243\350\277\236\346\216\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("asyncTerminal", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("asyncTerminal", "\351\200\200\345\207\272\345\272\224\347\224\250\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actSetPortParams->setText(QApplication::translate("asyncTerminal", "\351\205\215\347\275\256\344\270\262\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSetPortParams->setToolTip(QApplication::translate("asyncTerminal", "\350\256\276\347\275\256\344\270\262\345\217\243\345\217\202\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAbout->setText(QApplication::translate("asyncTerminal", "\345\205\263\344\272\216\345\272\224\347\224\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAbout->setToolTip(QApplication::translate("asyncTerminal", "\345\205\263\344\272\216\345\272\224\347\224\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actAboutQt->setText(QApplication::translate("asyncTerminal", "\345\205\263\344\272\216Qt", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actAboutQt->setToolTip(QApplication::translate("asyncTerminal", "\345\205\263\344\272\216Qt", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("asyncTerminal", "\346\270\205\347\251\272\346\266\210\346\201\257", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("asyncTerminal", "\346\270\205\347\251\272\346\224\266\345\210\260\347\232\204\344\270\262\345\217\243\346\266\210\346\201\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        textEditorGroup->setTitle(QApplication::translate("asyncTerminal", "\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", Q_NULLPTR));
        textMonitorGroup->setTitle(QApplication::translate("asyncTerminal", "\346\226\207\346\234\254\347\274\226\350\276\221\347\233\221\346\216\247\345\231\250", Q_NULLPTR));
        menu->setTitle(QApplication::translate("asyncTerminal", "\351\205\215\347\275\256", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("asyncTerminal", "\345\267\245\345\205\267", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("asyncTerminal", "\345\205\263\344\272\216", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("asyncTerminal", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class asyncTerminal: public Ui_asyncTerminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASYNCTERMINAL_H
