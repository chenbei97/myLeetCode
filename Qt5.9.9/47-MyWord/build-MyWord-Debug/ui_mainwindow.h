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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *actOpen;
    QAction *actSave;
    QAction *actSaveAs;
    QAction *actPrint;
    QAction *actPrintPreview;
    QAction *actexit;
    QAction *actUndo;
    QAction *actRedo;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actBold;
    QAction *actItalic;
    QAction *actUnderline;
    QAction *actLeft;
    QAction *actCenter;
    QAction *actRight;
    QAction *actJusitify;
    QAction *actColor;
    QAction *actClose;
    QAction *actCloseAll;
    QAction *actTile;
    QAction *actCascade;
    QAction *actNext;
    QAction *actPrevious;
    QAction *action;
    QAction *action_Qt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *bulletComboBox;
    QComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QMenu *menuZiti;
    QMenu *menuAlign;
    QMenu *menuWindow;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1146, 600);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actNew = new QAction(MainWindow);
        actNew->setObjectName(QStringLiteral("actNew"));
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QStringLiteral("actSave"));
        actSave->setEnabled(false);
        actSaveAs = new QAction(MainWindow);
        actSaveAs->setObjectName(QStringLiteral("actSaveAs"));
        actSaveAs->setEnabled(false);
        actPrint = new QAction(MainWindow);
        actPrint->setObjectName(QStringLiteral("actPrint"));
        actPrint->setEnabled(false);
        actPrintPreview = new QAction(MainWindow);
        actPrintPreview->setObjectName(QStringLiteral("actPrintPreview"));
        actPrintPreview->setEnabled(false);
        actexit = new QAction(MainWindow);
        actexit->setObjectName(QStringLiteral("actexit"));
        actUndo = new QAction(MainWindow);
        actUndo->setObjectName(QStringLiteral("actUndo"));
        actRedo = new QAction(MainWindow);
        actRedo->setObjectName(QStringLiteral("actRedo"));
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QStringLiteral("actCut"));
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QStringLiteral("actCopy"));
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QStringLiteral("actPaste"));
        actBold = new QAction(MainWindow);
        actBold->setObjectName(QStringLiteral("actBold"));
        actItalic = new QAction(MainWindow);
        actItalic->setObjectName(QStringLiteral("actItalic"));
        actUnderline = new QAction(MainWindow);
        actUnderline->setObjectName(QStringLiteral("actUnderline"));
        actLeft = new QAction(MainWindow);
        actLeft->setObjectName(QStringLiteral("actLeft"));
        actCenter = new QAction(MainWindow);
        actCenter->setObjectName(QStringLiteral("actCenter"));
        actRight = new QAction(MainWindow);
        actRight->setObjectName(QStringLiteral("actRight"));
        actJusitify = new QAction(MainWindow);
        actJusitify->setObjectName(QStringLiteral("actJusitify"));
        actColor = new QAction(MainWindow);
        actColor->setObjectName(QStringLiteral("actColor"));
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QStringLiteral("actClose"));
        actCloseAll = new QAction(MainWindow);
        actCloseAll->setObjectName(QStringLiteral("actCloseAll"));
        actTile = new QAction(MainWindow);
        actTile->setObjectName(QStringLiteral("actTile"));
        actCascade = new QAction(MainWindow);
        actCascade->setObjectName(QStringLiteral("actCascade"));
        actNext = new QAction(MainWindow);
        actNext->setObjectName(QStringLiteral("actNext"));
        actPrevious = new QAction(MainWindow);
        actPrevious->setObjectName(QStringLiteral("actPrevious"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_Qt = new QAction(MainWindow);
        action_Qt->setObjectName(QStringLiteral("action_Qt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bulletComboBox = new QComboBox(centralwidget);
        bulletComboBox->setObjectName(QStringLiteral("bulletComboBox"));
        bulletComboBox->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(bulletComboBox);

        fontComboBox = new QComboBox(centralwidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(fontComboBox);

        sizeComboBox = new QComboBox(centralwidget);
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));
        sizeComboBox->setMinimumSize(QSize(150, 30));

        horizontalLayout->addWidget(sizeComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout->addWidget(mdiArea, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1146, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QStringLiteral("menuFormat"));
        menuZiti = new QMenu(menuFormat);
        menuZiti->setObjectName(QStringLiteral("menuZiti"));
        menuAlign = new QMenu(menuFormat);
        menuAlign->setObjectName(QStringLiteral("menuAlign"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuFormat->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actNew);
        menuFile->addAction(actOpen);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actSave);
        menuFile->addAction(actSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actPrint);
        menuFile->addAction(actPrintPreview);
        menuFile->addSeparator();
        menuFile->addAction(actexit);
        menuEdit->addAction(actUndo);
        menuEdit->addAction(actRedo);
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addAction(actCut);
        menuEdit->addAction(actCopy);
        menuEdit->addAction(actPaste);
        menuFormat->addAction(menuZiti->menuAction());
        menuFormat->addAction(menuAlign->menuAction());
        menuFormat->addAction(actColor);
        menuZiti->addAction(actBold);
        menuZiti->addAction(actItalic);
        menuZiti->addAction(actUnderline);
        menuAlign->addAction(actLeft);
        menuAlign->addAction(actCenter);
        menuAlign->addAction(actRight);
        menuAlign->addAction(actJusitify);
        menuWindow->addAction(actClose);
        menuWindow->addAction(actCloseAll);
        menuWindow->addSeparator();
        menuWindow->addAction(actTile);
        menuWindow->addAction(actCascade);
        menuWindow->addSeparator();
        menuWindow->addSeparator();
        menuWindow->addAction(actNext);
        menuWindow->addAction(actPrevious);
        menuAbout->addAction(action);
        menuAbout->addAction(action_Qt);
        toolBar->addAction(actNew);
        toolBar->addAction(actOpen);
        toolBar->addAction(actSaveAs);
        toolBar->addAction(actPrint);
        toolBar->addSeparator();
        toolBar->addAction(actUndo);
        toolBar->addAction(actRedo);
        toolBar->addAction(actCut);
        toolBar->addAction(actCopy);
        toolBar->addAction(actPaste);
        toolBar->addSeparator();
        toolBar->addAction(actBold);
        toolBar->addAction(actItalic);
        toolBar->addAction(actUnderline);
        toolBar->addSeparator();
        toolBar->addAction(actLeft);
        toolBar->addAction(actCenter);
        toolBar->addAction(actRight);
        toolBar->addAction(actJusitify);

        retranslateUi(MainWindow);
        QObject::connect(actexit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actNew->setStatusTip(QApplication::translate("MainWindow", "\346\226\260\345\273\2721\344\270\252\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        actOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        actSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        actSaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        actPrint->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", Q_NULLPTR));
        actPrintPreview->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", Q_NULLPTR));
        actexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        actUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        actRedo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
        actCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
        actCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        actPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        actBold->setText(QApplication::translate("MainWindow", "\345\212\240\347\262\227", Q_NULLPTR));
        actItalic->setText(QApplication::translate("MainWindow", "\345\200\276\346\226\234", Q_NULLPTR));
        actUnderline->setText(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
        actLeft->setText(QApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", Q_NULLPTR));
        actCenter->setText(QApplication::translate("MainWindow", "\345\261\205\344\270\255", Q_NULLPTR));
        actRight->setText(QApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", Q_NULLPTR));
        actJusitify->setText(QApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220", Q_NULLPTR));
        actColor->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262", Q_NULLPTR));
        actClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
        actCloseAll->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211", Q_NULLPTR));
        actTile->setText(QApplication::translate("MainWindow", "\345\271\263\351\223\272", Q_NULLPTR));
        actCascade->setText(QApplication::translate("MainWindow", "\345\261\202\345\217\240", Q_NULLPTR));
        actNext->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        actPrevious->setText(QApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        action_Qt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", Q_NULLPTR));
        bulletComboBox->clear();
        bulletComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\240\207\345\207\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\217)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\213)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\226\240)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\274\226\345\217\267(1,2,3)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\274\226\345\217\267(a,b,c)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\274\226\345\217\267(A,B,C)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\274\226\345\217\267(i,ii,iii)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\274\226\345\217\267(I,II,III)", Q_NULLPTR)
        );
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menuFormat->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217", Q_NULLPTR));
        menuZiti->setTitle(QApplication::translate("MainWindow", "\345\255\227\344\275\223", Q_NULLPTR));
        menuAlign->setTitle(QApplication::translate("MainWindow", "\346\256\265\350\220\275", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
