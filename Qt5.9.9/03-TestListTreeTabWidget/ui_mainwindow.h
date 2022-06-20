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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actListIni;
    QAction *actListClear;
    QAction *actListInsert;
    QAction *actListAppend;
    QAction *actListDelete;
    QAction *actSelALL;
    QAction *actSelNone;
    QAction *actSelInvs;
    QAction *actQuit;
    QAction *actSelPopMenu;
    QAction *actionReboot;
    QAction *actionClose;
    QAction *actionlistInit;
    QAction *actionListClear;
    QAction *actionListAppend;
    QAction *actionListDelete;
    QAction *actioninitText;
    QAction *actionclearText;
    QAction *actionsaveText;
    QAction *actionListInsert;
    QWidget *centralwidget;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page1;
    QGridLayout *gridLayout;
    QToolButton *tBtnListIni;
    QToolButton *tBtnListClear;
    QToolButton *tBtnListInsert;
    QToolButton *tBtnListAppend;
    QToolButton *tBtnListDelete;
    QWidget *page2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnRecoveryDate;
    QLabel *textLabel1;
    QLineEdit *textLabelLineEdit;
    QLabel *textLabel2;
    QSpinBox *spinMonthBox;
    QLabel *textLabel3;
    QSpinBox *spinDateBox;
    QSpacerItem *verticalSpacer;
    QWidget *page3;
    QPushButton *btnclose;
    QCheckBox *reboot;
    QDial *dial;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout;
    QLabel *currentItemLabel;
    QLineEdit *editCutItemText;
    QCheckBox *chkBoxListEditable;
    QGroupBox *groupBox2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tBtnSelectItem;
    QToolButton *tBtnSelALL;
    QToolButton *tBtnSelNone;
    QToolButton *tBtnSelInvs;
    QListWidget *listWidget;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QProgressBar *progressBar;
    QWidget *tab3;
    QDateTimeEdit *dateTimeEdit;
    QPlainTextEdit *plainTextEdit;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *lcdHourNumber;
    QLCDNumber *lcdMinuteNumber;
    QLCDNumber *lcdSecondNumber;
    QMenuBar *menubar;
    QMenu *menuReboot;
    QMenu *menuTool;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1062, 544);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actListIni = new QAction(MainWindow);
        actListIni->setObjectName(QStringLiteral("actListIni"));
        actListIni->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/128.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListIni->setIcon(icon);
        actListIni->setFont(font);
        actListClear = new QAction(MainWindow);
        actListClear->setObjectName(QStringLiteral("actListClear"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/delete1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListClear->setIcon(icon1);
        actListClear->setFont(font);
        actListClear->setIconVisibleInMenu(true);
        actListInsert = new QAction(MainWindow);
        actListInsert->setObjectName(QStringLiteral("actListInsert"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/424.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListInsert->setIcon(icon2);
        actListInsert->setFont(font);
        actListAppend = new QAction(MainWindow);
        actListAppend->setObjectName(QStringLiteral("actListAppend"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/316.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListAppend->setIcon(icon3);
        actListAppend->setFont(font);
        actListDelete = new QAction(MainWindow);
        actListDelete->setObjectName(QStringLiteral("actListDelete"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/324.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actListDelete->setIcon(icon4);
        actListDelete->setFont(font);
        actSelALL = new QAction(MainWindow);
        actSelALL->setObjectName(QStringLiteral("actSelALL"));
        actSelALL->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSelALL->setIcon(icon5);
        actSelNone = new QAction(MainWindow);
        actSelNone->setObjectName(QStringLiteral("actSelNone"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/undo2.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSelNone->setIcon(icon6);
        actSelNone->setMenuRole(QAction::AboutRole);
        actSelInvs = new QAction(MainWindow);
        actSelInvs->setObjectName(QStringLiteral("actSelInvs"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/redo2.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSelInvs->setIcon(icon7);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        actQuit->setIcon(icon1);
        actSelPopMenu = new QAction(MainWindow);
        actSelPopMenu->setObjectName(QStringLiteral("actSelPopMenu"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/320.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actSelPopMenu->setIcon(icon8);
        actionReboot = new QAction(MainWindow);
        actionReboot->setObjectName(QStringLiteral("actionReboot"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/326.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionReboot->setIcon(icon9);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose->setIcon(icon1);
        actionlistInit = new QAction(MainWindow);
        actionlistInit->setObjectName(QStringLiteral("actionlistInit"));
        actionlistInit->setIcon(icon2);
        actionListClear = new QAction(MainWindow);
        actionListClear->setObjectName(QStringLiteral("actionListClear"));
        actionListClear->setIcon(icon1);
        actionListAppend = new QAction(MainWindow);
        actionListAppend->setObjectName(QStringLiteral("actionListAppend"));
        actionListAppend->setIcon(icon3);
        actionListDelete = new QAction(MainWindow);
        actionListDelete->setObjectName(QStringLiteral("actionListDelete"));
        actionListDelete->setIcon(icon4);
        actioninitText = new QAction(MainWindow);
        actioninitText->setObjectName(QStringLiteral("actioninitText"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/new2.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actioninitText->setIcon(icon10);
        actionclearText = new QAction(MainWindow);
        actionclearText->setObjectName(QStringLiteral("actionclearText"));
        actionclearText->setIcon(icon1);
        actionsaveText = new QAction(MainWindow);
        actionsaveText->setObjectName(QStringLiteral("actionsaveText"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/save1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveText->setIcon(icon11);
        actionListInsert = new QAction(MainWindow);
        actionListInsert->setObjectName(QStringLiteral("actionListInsert"));
        actionListInsert->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 10, 1041, 451));
        splitter->setFrameShape(QFrame::Box);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(1);
        splitter->setMidLineWidth(3);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(150, 0));
        toolBox->setMaximumSize(QSize(300, 16777215));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        page1->setGeometry(QRect(0, 0, 232, 326));
        gridLayout = new QGridLayout(page1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tBtnListIni = new QToolButton(page1);
        tBtnListIni->setObjectName(QStringLiteral("tBtnListIni"));
        tBtnListIni->setMinimumSize(QSize(120, 25));
        tBtnListIni->setPopupMode(QToolButton::DelayedPopup);
        tBtnListIni->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnListIni->setAutoRaise(false);
        tBtnListIni->setArrowType(Qt::NoArrow);

        gridLayout->addWidget(tBtnListIni, 0, 0, 1, 1);

        tBtnListClear = new QToolButton(page1);
        tBtnListClear->setObjectName(QStringLiteral("tBtnListClear"));
        tBtnListClear->setMinimumSize(QSize(120, 25));
        tBtnListClear->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(tBtnListClear, 1, 0, 1, 1);

        tBtnListInsert = new QToolButton(page1);
        tBtnListInsert->setObjectName(QStringLiteral("tBtnListInsert"));
        tBtnListInsert->setMinimumSize(QSize(120, 25));
        tBtnListInsert->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(tBtnListInsert, 2, 0, 1, 1);

        tBtnListAppend = new QToolButton(page1);
        tBtnListAppend->setObjectName(QStringLiteral("tBtnListAppend"));
        tBtnListAppend->setMinimumSize(QSize(120, 25));
        tBtnListAppend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(tBtnListAppend, 3, 0, 1, 1);

        tBtnListDelete = new QToolButton(page1);
        tBtnListDelete->setObjectName(QStringLiteral("tBtnListDelete"));
        tBtnListDelete->setMinimumSize(QSize(120, 25));
        tBtnListDelete->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(tBtnListDelete, 4, 0, 1, 1);

        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/icons/410.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page1, icon12, QString::fromUtf8("QListWidget\346\223\215\344\275\234"));
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        page2->setGeometry(QRect(0, 0, 211, 340));
        verticalLayout_4 = new QVBoxLayout(page2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox4 = new QGroupBox(page2);
        groupBox4->setObjectName(QStringLiteral("groupBox4"));
        verticalLayout_3 = new QVBoxLayout(groupBox4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btnRecoveryDate = new QPushButton(groupBox4);
        btnRecoveryDate->setObjectName(QStringLiteral("btnRecoveryDate"));

        verticalLayout_3->addWidget(btnRecoveryDate);

        textLabel1 = new QLabel(groupBox4);
        textLabel1->setObjectName(QStringLiteral("textLabel1"));

        verticalLayout_3->addWidget(textLabel1);

        textLabelLineEdit = new QLineEdit(groupBox4);
        textLabelLineEdit->setObjectName(QStringLiteral("textLabelLineEdit"));

        verticalLayout_3->addWidget(textLabelLineEdit);

        textLabel2 = new QLabel(groupBox4);
        textLabel2->setObjectName(QStringLiteral("textLabel2"));

        verticalLayout_3->addWidget(textLabel2);

        spinMonthBox = new QSpinBox(groupBox4);
        spinMonthBox->setObjectName(QStringLiteral("spinMonthBox"));

        verticalLayout_3->addWidget(spinMonthBox);

        textLabel3 = new QLabel(groupBox4);
        textLabel3->setObjectName(QStringLiteral("textLabel3"));

        verticalLayout_3->addWidget(textLabel3);

        spinDateBox = new QSpinBox(groupBox4);
        spinDateBox->setObjectName(QStringLiteral("spinDateBox"));

        verticalLayout_3->addWidget(spinDateBox);


        verticalLayout_4->addWidget(groupBox4);

        verticalSpacer = new QSpacerItem(20, 119, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/icons/408.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page2, icon13, QString::fromUtf8("QTreeWidget\346\223\215\344\275\234"));
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        page3->setGeometry(QRect(0, 0, 232, 326));
        btnclose = new QPushButton(page3);
        btnclose->setObjectName(QStringLiteral("btnclose"));
        btnclose->setGeometry(QRect(40, 40, 131, 41));
        reboot = new QCheckBox(page3);
        reboot->setObjectName(QStringLiteral("reboot"));
        reboot->setGeometry(QRect(40, 120, 131, 41));
        dial = new QDial(page3);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(70, 200, 50, 64));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/icons/412.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolBox->addItem(page3, icon14, QString::fromUtf8("QTableWidget\346\223\215\344\275\234"));
        splitter->addWidget(toolBox);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        verticalLayout = new QVBoxLayout(tab1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        groupBox1 = new QGroupBox(tab1);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        horizontalLayout = new QHBoxLayout(groupBox1);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        currentItemLabel = new QLabel(groupBox1);
        currentItemLabel->setObjectName(QStringLiteral("currentItemLabel"));

        horizontalLayout->addWidget(currentItemLabel);

        editCutItemText = new QLineEdit(groupBox1);
        editCutItemText->setObjectName(QStringLiteral("editCutItemText"));
        editCutItemText->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        editCutItemText->setClearButtonEnabled(false);

        horizontalLayout->addWidget(editCutItemText);

        chkBoxListEditable = new QCheckBox(groupBox1);
        chkBoxListEditable->setObjectName(QStringLiteral("chkBoxListEditable"));

        horizontalLayout->addWidget(chkBoxListEditable);


        verticalLayout->addWidget(groupBox1);

        groupBox2 = new QGroupBox(tab1);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 2, -1, 2);
        tBtnSelectItem = new QToolButton(groupBox2);
        tBtnSelectItem->setObjectName(QStringLiteral("tBtnSelectItem"));
        tBtnSelectItem->setMinimumSize(QSize(100, 25));
        tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
        tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSelectItem);

        tBtnSelALL = new QToolButton(groupBox2);
        tBtnSelALL->setObjectName(QStringLiteral("tBtnSelALL"));
        tBtnSelALL->setMinimumSize(QSize(70, 25));
        tBtnSelALL->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSelALL);

        tBtnSelNone = new QToolButton(groupBox2);
        tBtnSelNone->setObjectName(QStringLiteral("tBtnSelNone"));
        tBtnSelNone->setMinimumSize(QSize(70, 25));
        tBtnSelNone->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSelNone);

        tBtnSelInvs = new QToolButton(groupBox2);
        tBtnSelInvs->setObjectName(QStringLiteral("tBtnSelInvs"));
        tBtnSelInvs->setMinimumSize(QSize(70, 25));
        tBtnSelInvs->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSelInvs);


        verticalLayout->addWidget(groupBox2);

        listWidget = new QListWidget(tab1);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/icons/check2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setCheckState(Qt::Checked);
        __qlistwidgetitem->setIcon(icon15);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        __qlistwidgetitem1->setIcon(icon15);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setSelectionRectVisible(false);

        verticalLayout->addWidget(listWidget);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        verticalLayout_2 = new QVBoxLayout(tab2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        calendarWidget = new QCalendarWidget(tab2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout_2->addWidget(calendarWidget);

        progressBar = new QProgressBar(tab2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        dateTimeEdit = new QDateTimeEdit(tab3);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(0, 10, 201, 51));
        plainTextEdit = new QPlainTextEdit(tab3);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 140, 801, 261));
        textEdit = new QTextEdit(tab3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 70, 751, 61));
        widget = new QWidget(tab3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 10, 551, 51));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lcdHourNumber = new QLCDNumber(widget);
        lcdHourNumber->setObjectName(QStringLiteral("lcdHourNumber"));

        horizontalLayout_3->addWidget(lcdHourNumber);

        lcdMinuteNumber = new QLCDNumber(widget);
        lcdMinuteNumber->setObjectName(QStringLiteral("lcdMinuteNumber"));

        horizontalLayout_3->addWidget(lcdMinuteNumber);

        lcdSecondNumber = new QLCDNumber(widget);
        lcdSecondNumber->setObjectName(QStringLiteral("lcdSecondNumber"));

        horizontalLayout_3->addWidget(lcdSecondNumber);

        tabWidget->addTab(tab3, QString());
        splitter->addWidget(tabWidget);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1062, 32));
        menuReboot = new QMenu(menubar);
        menuReboot->setObjectName(QStringLiteral("menuReboot"));
        menuTool = new QMenu(menubar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuReboot->menuAction());
        menubar->addAction(menuTool->menuAction());
        menubar->addAction(menuFile->menuAction());
        menuReboot->addAction(actionReboot);
        menuReboot->addAction(actionClose);
        menuTool->addAction(actionlistInit);
        menuTool->addAction(actionListClear);
        menuTool->addAction(actionListAppend);
        menuTool->addAction(actionListDelete);
        menuTool->addAction(actionListInsert);
        menuFile->addSeparator();
        menuFile->addAction(actioninitText);
        menuFile->addAction(actionclearText);
        menuFile->addAction(actionsaveText);
        toolBar->addAction(actListIni);
        toolBar->addSeparator();
        toolBar->addAction(actListClear);
        toolBar->addSeparator();
        toolBar->addAction(actListInsert);
        toolBar->addSeparator();
        toolBar->addAction(actListAppend);
        toolBar->addSeparator();
        toolBar->addAction(actListDelete);

        retranslateUi(MainWindow);
        QObject::connect(actSelPopMenu, SIGNAL(triggered()), actSelALL, SLOT(trigger()));
        QObject::connect(actQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        actListIni->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actListIni->setToolTip(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actListIni->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actListClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actListClear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actListClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actListInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actListInsert->setToolTip(QApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actListInsert->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actListAppend->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actListAppend->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actListAppend->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actListDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actListDelete->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actListDelete->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actSelALL->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSelALL->setToolTip(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSelALL->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actSelNone->setText(QApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSelNone->setToolTip(QApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSelNone->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actSelInvs->setText(QApplication::translate("MainWindow", "\345\217\215\351\200\211", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSelInvs->setToolTip(QApplication::translate("MainWindow", "\345\217\215\351\200\211", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSelInvs->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actSelPopMenu->setText(QApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSelPopMenu->setToolTip(QApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSelPopMenu->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionReboot->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionReboot->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionlistInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionlistInit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionListClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionListClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionListAppend->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionListAppend->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionListDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionListDelete->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actioninitText->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\346\226\207\346\234\254", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actioninitText->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionclearText->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\226\207\346\234\254", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionclearText->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+Backspace", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionsaveText->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\346\234\254", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionsaveText->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionListInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionListInsert->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        tBtnListIni->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", Q_NULLPTR));
        tBtnListClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", Q_NULLPTR));
        tBtnListInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", Q_NULLPTR));
        tBtnListAppend->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", Q_NULLPTR));
        tBtnListDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page1), QApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", Q_NULLPTR));
        groupBox4->setTitle(QString());
        btnRecoveryDate->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", Q_NULLPTR));
        textLabel1->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237", Q_NULLPTR));
        textLabel2->setText(QApplication::translate("MainWindow", "\346\234\210\344\273\275", Q_NULLPTR));
        textLabel3->setText(QApplication::translate("MainWindow", "\345\244\251\346\225\260", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page2), QApplication::translate("MainWindow", "QTreeWidget\346\223\215\344\275\234", Q_NULLPTR));
        btnclose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", Q_NULLPTR));
        reboot->setText(QApplication::translate("MainWindow", "\351\207\215\345\220\257", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page3), QApplication::translate("MainWindow", "QTableWidget\346\223\215\344\275\234", Q_NULLPTR));
        groupBox1->setTitle(QString());
        currentItemLabel->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\351\241\271\345\217\230\345\214\226", Q_NULLPTR));
        chkBoxListEditable->setText(QApplication::translate("MainWindow", "\345\217\257\347\274\226\350\276\221", Q_NULLPTR));
        groupBox2->setTitle(QString());
        tBtnSelectItem->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\351\241\271", Q_NULLPTR));
        tBtnSelALL->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
        tBtnSelNone->setText(QApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", Q_NULLPTR));
        tBtnSelInvs->setText(QApplication::translate("MainWindow", "\345\217\215\351\200\211", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "New Item1", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "New Item2", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "QListWidget", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "QTreeWidget", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MainWindow", "QTableWidget", Q_NULLPTR));
        menuReboot->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237", Q_NULLPTR));
        menuTool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
