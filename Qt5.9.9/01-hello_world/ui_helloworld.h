/********************************************************************************
** Form generated from reading UI file 'helloworld.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWORLD_H
#define UI_HELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloWorld
{
public:
    QAction *actionclose;
    QAction *actionreboot;
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnclose;
    QCheckBox *handsome;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *age;
    QLineEdit *ageText;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLineEdit *nameText;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sex;
    QComboBox *sexBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbt_red;
    QRadioButton *rbt_green;
    QRadioButton *rbt_blue;
    QMenuBar *menubar;
    QMenu *menufile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloWorld)
    {
        if (helloWorld->objectName().isEmpty())
            helloWorld->setObjectName(QStringLiteral("helloWorld"));
        helloWorld->setEnabled(true);
        helloWorld->resize(600, 600);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        helloWorld->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        helloWorld->setFont(font);
        actionclose = new QAction(helloWorld);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/It.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionclose->setIcon(icon);
        actionreboot = new QAction(helloWorld);
        actionreboot->setObjectName(QStringLiteral("actionreboot"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Saw.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionreboot->setIcon(icon1);
        centralwidget = new QWidget(helloWorld);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 270, 431, 50));
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        label->setIndent(-1);
        btnclose = new QPushButton(centralwidget);
        btnclose->setObjectName(QStringLiteral("btnclose"));
        btnclose->setGeometry(QRect(60, 380, 141, 41));
        btnclose->setCheckable(true);
        btnclose->setChecked(false);
        btnclose->setAutoDefault(false);
        handsome = new QCheckBox(centralwidget);
        handsome->setObjectName(QStringLiteral("handsome"));
        handsome->setGeometry(QRect(250, 380, 271, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 20, 371, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 344, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        age = new QLabel(layoutWidget);
        age->setObjectName(QStringLiteral("age"));
        age->setMinimumSize(QSize(65, 40));

        horizontalLayout_2->addWidget(age);

        ageText = new QLineEdit(layoutWidget);
        ageText->setObjectName(QStringLiteral("ageText"));

        horizontalLayout_2->addWidget(ageText);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 344, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(layoutWidget1);
        name->setObjectName(QStringLiteral("name"));
        name->setEnabled(true);
        name->setMinimumSize(QSize(65, 40));
        name->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(name);

        nameText = new QLineEdit(layoutWidget1);
        nameText->setObjectName(QStringLiteral("nameText"));

        horizontalLayout->addWidget(nameText);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 130, 341, 42));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sex = new QLabel(layoutWidget2);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setEnabled(true);
        sex->setMinimumSize(QSize(65, 40));
        sex->setMaximumSize(QSize(65, 40));

        horizontalLayout_3->addWidget(sex);

        sexBox = new QComboBox(layoutWidget2);
        sexBox->setObjectName(QStringLiteral("sexBox"));

        horizontalLayout_3->addWidget(sexBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 430, 521, 91));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 30, 441, 36));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        rbt_red = new QRadioButton(layoutWidget3);
        rbt_red->setObjectName(QStringLiteral("rbt_red"));
        rbt_red->setEnabled(true);
        rbt_red->setCheckable(true);
        rbt_red->setChecked(true);

        horizontalLayout_4->addWidget(rbt_red);

        rbt_green = new QRadioButton(layoutWidget3);
        rbt_green->setObjectName(QStringLiteral("rbt_green"));

        horizontalLayout_4->addWidget(rbt_green);

        rbt_blue = new QRadioButton(layoutWidget3);
        rbt_blue->setObjectName(QStringLiteral("rbt_blue"));

        horizontalLayout_4->addWidget(rbt_blue);

        helloWorld->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloWorld);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QStringLiteral("menufile"));
        helloWorld->setMenuBar(menubar);
        statusbar = new QStatusBar(helloWorld);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setEnabled(true);
        statusbar->setMinimumSize(QSize(300, 20));
        helloWorld->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(btnclose);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menufile->menuAction());
        menufile->addAction(actionclose);
        menufile->addSeparator();
        menufile->addAction(actionreboot);

        retranslateUi(helloWorld);

        QMetaObject::connectSlotsByName(helloWorld);
    } // setupUi

    void retranslateUi(QMainWindow *helloWorld)
    {
        helloWorld->setWindowTitle(QApplication::translate("helloWorld", "helloWorld", Q_NULLPTR));
        actionclose->setText(QApplication::translate("helloWorld", "close", Q_NULLPTR));
        actionreboot->setText(QApplication::translate("helloWorld", "reboot", Q_NULLPTR));
        label->setText(QApplication::translate("helloWorld", "\345\202\273\345\256\235\345\256\235\357\274\214\344\275\240\346\234\200\345\202\273\357\274\214\345\207\206\345\244\207\345\245\275\345\261\201\350\202\241\345\274\200\350\212\261", Q_NULLPTR));
        btnclose->setText(QApplication::translate("helloWorld", "\345\205\263\351\227\255", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btnclose->setShortcut(QApplication::translate("helloWorld", "Ctrl+K", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        handsome->setText(QApplication::translate("helloWorld", "\345\214\227\345\223\245\345\244\251\344\270\213\347\254\254\344\270\200\345\270\205\345\220\227\357\274\237", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("helloWorld", "information", Q_NULLPTR));
        age->setText(QApplication::translate("helloWorld", "age", Q_NULLPTR));
        ageText->setText(QApplication::translate("helloWorld", "18", Q_NULLPTR));
        name->setText(QApplication::translate("helloWorld", "name", Q_NULLPTR));
        nameText->setText(QApplication::translate("helloWorld", "\346\235\216\346\225\254\346\226\207", Q_NULLPTR));
        sex->setText(QApplication::translate("helloWorld", "sex", Q_NULLPTR));
        sexBox->clear();
        sexBox->insertItems(0, QStringList()
         << QApplication::translate("helloWorld", "man", Q_NULLPTR)
         << QApplication::translate("helloWorld", "woman", Q_NULLPTR)
         << QApplication::translate("helloWorld", "simon", Q_NULLPTR)
        );
        groupBox_2->setTitle(QString());
        rbt_red->setText(QApplication::translate("helloWorld", "red", Q_NULLPTR));
        rbt_green->setText(QApplication::translate("helloWorld", "green", Q_NULLPTR));
        rbt_blue->setText(QApplication::translate("helloWorld", "blue", Q_NULLPTR));
        menufile->setTitle(QApplication::translate("helloWorld", "file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helloWorld: public Ui_helloWorld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWORLD_H
