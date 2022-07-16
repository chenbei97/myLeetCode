/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *editUser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *editPSWD;
    QCheckBox *chkBoxSave;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnOK;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnCancel;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(790, 612);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        LoginDialog->setFont(font);
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 731, 451));
        label->setMinimumSize(QSize(1, 0));
        label->setMaximumSize(QSize(2000, 2000));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/splash2.jpg")));
        label->setScaledContents(true);
        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 490, 710, 44));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 40));
        label_2->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(label_2);

        editUser = new QLineEdit(widget);
        editUser->setObjectName(QStringLiteral("editUser"));
        editUser->setMinimumSize(QSize(160, 40));
        editUser->setMaximumSize(QSize(160, 40));

        horizontalLayout->addWidget(editUser);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 40));
        label_3->setMaximumSize(QSize(100, 40));

        horizontalLayout_2->addWidget(label_3);

        editPSWD = new QLineEdit(widget);
        editPSWD->setObjectName(QStringLiteral("editPSWD"));
        editPSWD->setMinimumSize(QSize(160, 40));
        editPSWD->setMaximumSize(QSize(160, 40));
        editPSWD->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(editPSWD);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        chkBoxSave = new QCheckBox(widget);
        chkBoxSave->setObjectName(QStringLiteral("chkBoxSave"));
        chkBoxSave->setMinimumSize(QSize(160, 40));
        chkBoxSave->setMaximumSize(QSize(160, 40));

        horizontalLayout_3->addWidget(chkBoxSave);

        widget1 = new QWidget(LoginDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(170, 550, 434, 42));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnOK = new QPushButton(widget1);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setMinimumSize(QSize(160, 40));
        btnOK->setMaximumSize(QSize(160, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon);

        horizontalLayout_4->addWidget(btnOK);

        horizontalSpacer_3 = new QSpacerItem(100, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnCancel = new QPushButton(widget1);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(160, 40));
        btnCancel->setMaximumSize(QSize(160, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);

        horizontalLayout_4->addWidget(btnCancel);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\345\257\206 \347\240\201", Q_NULLPTR));
        chkBoxSave->setText(QApplication::translate("LoginDialog", "\344\277\235\345\255\230\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        btnOK->setText(QApplication::translate("LoginDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("LoginDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
