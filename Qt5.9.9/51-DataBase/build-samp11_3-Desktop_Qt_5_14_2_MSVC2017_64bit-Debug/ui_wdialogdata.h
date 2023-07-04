/********************************************************************************
** Form generated from reading UI file 'wdialogdata.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDIALOGDATA_H
#define UI_WDIALOGDATA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WDialogData
{
public:
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinEmpNo;
    QLabel *label_2;
    QLineEdit *editName;
    QLabel *label_3;
    QComboBox *comboSex;
    QLabel *label_4;
    QDoubleSpinBox *spinHeight;
    QLabel *label_5;
    QDateEdit *editBirth;
    QLabel *label_10;
    QLineEdit *editMobile;
    QLabel *label_7;
    QComboBox *comboProvince;
    QLabel *label_8;
    QLineEdit *editCity;
    QLabel *label_6;
    QComboBox *comboDep;
    QPlainTextEdit *editMemo;
    QLabel *label_9;
    QLabel *label_11;
    QSpinBox *spinSalary;
    QLabel *label_12;
    QComboBox *comboEdu;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QLabel *LabPhoto;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnSetPhoto;
    QPushButton *btnClearPhoto;
    QPushButton *btnOK;
    QPushButton *btnClose;

    void setupUi(QDialog *WDialogData)
    {
        if (WDialogData->objectName().isEmpty())
            WDialogData->setObjectName(QString::fromUtf8("WDialogData"));
        WDialogData->resize(1000, 800);
        QFont font;
        font.setPointSize(10);
        WDialogData->setFont(font);
        groupBox_2 = new QGroupBox(WDialogData);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(5, 5, 661, 751));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinEmpNo = new QSpinBox(groupBox_2);
        spinEmpNo->setObjectName(QString::fromUtf8("spinEmpNo"));
        spinEmpNo->setMinimum(1);
        spinEmpNo->setMaximum(10000);

        gridLayout->addWidget(spinEmpNo, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editName = new QLineEdit(groupBox_2);
        editName->setObjectName(QString::fromUtf8("editName"));

        gridLayout->addWidget(editName, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboSex = new QComboBox(groupBox_2);
        comboSex->addItem(QString());
        comboSex->addItem(QString());
        comboSex->setObjectName(QString::fromUtf8("comboSex"));

        gridLayout->addWidget(comboSex, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinHeight = new QDoubleSpinBox(groupBox_2);
        spinHeight->setObjectName(QString::fromUtf8("spinHeight"));
        spinHeight->setMaximum(3.000000000000000);
        spinHeight->setSingleStep(0.010000000000000);
        spinHeight->setValue(1.560000000000000);

        gridLayout->addWidget(spinHeight, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        editBirth = new QDateEdit(groupBox_2);
        editBirth->setObjectName(QString::fromUtf8("editBirth"));
        editBirth->setCalendarPopup(true);
        editBirth->setDate(QDate(2017, 2, 20));

        gridLayout->addWidget(editBirth, 4, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        editMobile = new QLineEdit(groupBox_2);
        editMobile->setObjectName(QString::fromUtf8("editMobile"));

        gridLayout->addWidget(editMobile, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        comboProvince = new QComboBox(groupBox_2);
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->addItem(QString());
        comboProvince->setObjectName(QString::fromUtf8("comboProvince"));
        comboProvince->setEditable(true);

        gridLayout->addWidget(comboProvince, 6, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        editCity = new QLineEdit(groupBox_2);
        editCity->setObjectName(QString::fromUtf8("editCity"));

        gridLayout->addWidget(editCity, 7, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        comboDep = new QComboBox(groupBox_2);
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->addItem(QString());
        comboDep->setObjectName(QString::fromUtf8("comboDep"));
        comboDep->setEditable(true);

        gridLayout->addWidget(comboDep, 8, 1, 1, 1);

        editMemo = new QPlainTextEdit(groupBox_2);
        editMemo->setObjectName(QString::fromUtf8("editMemo"));
        editMemo->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(editMemo, 11, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 11, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        spinSalary = new QSpinBox(groupBox_2);
        spinSalary->setObjectName(QString::fromUtf8("spinSalary"));
        spinSalary->setMinimum(1000);
        spinSalary->setMaximum(50000);
        spinSalary->setSingleStep(100);
        spinSalary->setValue(1000);

        gridLayout->addWidget(spinSalary, 10, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 10, 0, 1, 1);

        comboEdu = new QComboBox(groupBox_2);
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->addItem(QString());
        comboEdu->setObjectName(QString::fromUtf8("comboEdu"));
        comboEdu->setEditable(true);

        gridLayout->addWidget(comboEdu, 9, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout->addWidget(label_13);

        LabPhoto = new QLabel(groupBox_2);
        LabPhoto->setObjectName(QString::fromUtf8("LabPhoto"));
        LabPhoto->setMinimumSize(QSize(150, 0));
        LabPhoto->setMaximumSize(QSize(350, 16777215));

        verticalLayout->addWidget(LabPhoto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        layoutWidget = new QWidget(WDialogData);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(740, 230, 241, 441));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSetPhoto = new QPushButton(layoutWidget);
        btnSetPhoto->setObjectName(QString::fromUtf8("btnSetPhoto"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/00.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetPhoto->setIcon(icon);

        verticalLayout_2->addWidget(btnSetPhoto);

        btnClearPhoto = new QPushButton(layoutWidget);
        btnClearPhoto->setObjectName(QString::fromUtf8("btnClearPhoto"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearPhoto->setIcon(icon1);

        verticalLayout_2->addWidget(btnClearPhoto);

        btnOK = new QPushButton(layoutWidget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon2);

        verticalLayout_2->addWidget(btnOK);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon3);

        verticalLayout_2->addWidget(btnClose);

#if QT_CONFIG(shortcut)
        label->setBuddy(spinEmpNo);
        label_2->setBuddy(editName);
        label_3->setBuddy(comboSex);
        label_4->setBuddy(spinHeight);
        label_5->setBuddy(editBirth);
        label_10->setBuddy(editMobile);
        label_7->setBuddy(comboProvince);
        label_8->setBuddy(editCity);
        label_6->setBuddy(comboDep);
        label_9->setBuddy(editMemo);
        label_11->setBuddy(comboEdu);
        label_12->setBuddy(spinSalary);
#endif // QT_CONFIG(shortcut)

        retranslateUi(WDialogData);
        QObject::connect(btnClose, SIGNAL(clicked()), WDialogData, SLOT(reject()));
        QObject::connect(btnOK, SIGNAL(clicked()), WDialogData, SLOT(accept()));

        QMetaObject::connectSlotsByName(WDialogData);
    } // setupUi

    void retranslateUi(QDialog *WDialogData)
    {
        WDialogData->setWindowTitle(QCoreApplication::translate("WDialogData", "\347\274\226\350\276\221\350\256\260\345\275\225", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("WDialogData", "\345\267\245  \345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("WDialogData", "\345\247\223  \345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("WDialogData", "\346\200\247  \345\210\253", nullptr));
        comboSex->setItemText(0, QCoreApplication::translate("WDialogData", "\347\224\267", nullptr));
        comboSex->setItemText(1, QCoreApplication::translate("WDialogData", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("WDialogData", "\350\272\253  \351\253\230", nullptr));
        spinHeight->setSuffix(QString());
        label_5->setText(QCoreApplication::translate("WDialogData", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        editBirth->setDisplayFormat(QCoreApplication::translate("WDialogData", "yyyy-MM-dd", nullptr));
        label_10->setText(QCoreApplication::translate("WDialogData", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_7->setText(QCoreApplication::translate("WDialogData", "\345\207\272\347\224\237\347\234\201\344\273\275", nullptr));
        comboProvince->setItemText(0, QCoreApplication::translate("WDialogData", "\345\214\227\344\272\254", nullptr));
        comboProvince->setItemText(1, QCoreApplication::translate("WDialogData", "\344\270\212\346\265\267", nullptr));
        comboProvince->setItemText(2, QCoreApplication::translate("WDialogData", "\345\244\251\346\264\245", nullptr));
        comboProvince->setItemText(3, QCoreApplication::translate("WDialogData", "\351\207\215\345\272\206", nullptr));
        comboProvince->setItemText(4, QCoreApplication::translate("WDialogData", "\345\256\211\345\276\275", nullptr));
        comboProvince->setItemText(5, QCoreApplication::translate("WDialogData", "\346\262\263\345\214\227", nullptr));
        comboProvince->setItemText(6, QCoreApplication::translate("WDialogData", "\346\262\263\345\215\227", nullptr));
        comboProvince->setItemText(7, QCoreApplication::translate("WDialogData", "\346\271\226\345\214\227", nullptr));
        comboProvince->setItemText(8, QCoreApplication::translate("WDialogData", "\346\271\226\345\215\227", nullptr));
        comboProvince->setItemText(9, QCoreApplication::translate("WDialogData", "\345\261\261\350\245\277", nullptr));
        comboProvince->setItemText(10, QCoreApplication::translate("WDialogData", "\345\261\261\344\270\234", nullptr));
        comboProvince->setItemText(11, QCoreApplication::translate("WDialogData", "\351\231\225\350\245\277", nullptr));
        comboProvince->setItemText(12, QCoreApplication::translate("WDialogData", "\346\261\237\350\213\217", nullptr));
        comboProvince->setItemText(13, QCoreApplication::translate("WDialogData", "\346\261\237\350\245\277", nullptr));

        comboProvince->setCurrentText(QCoreApplication::translate("WDialogData", "\345\214\227\344\272\254", nullptr));
        label_8->setText(QCoreApplication::translate("WDialogData", "\345\237\216  \345\270\202", nullptr));
        label_6->setText(QCoreApplication::translate("WDialogData", "\351\203\250  \351\227\250", nullptr));
        comboDep->setItemText(0, QCoreApplication::translate("WDialogData", "\351\224\200\345\224\256\351\203\250", nullptr));
        comboDep->setItemText(1, QCoreApplication::translate("WDialogData", "\346\212\200\346\234\257\351\203\250", nullptr));
        comboDep->setItemText(2, QCoreApplication::translate("WDialogData", "\347\224\237\344\272\247\351\203\250", nullptr));
        comboDep->setItemText(3, QCoreApplication::translate("WDialogData", "\350\241\214\346\224\277\351\203\250", nullptr));

        comboDep->setCurrentText(QCoreApplication::translate("WDialogData", "\351\224\200\345\224\256\351\203\250", nullptr));
        label_9->setText(QCoreApplication::translate("WDialogData", "\345\244\207   \346\263\250", nullptr));
        label_11->setText(QCoreApplication::translate("WDialogData", "\345\255\246  \345\216\206", nullptr));
        spinSalary->setPrefix(QString());
        label_12->setText(QCoreApplication::translate("WDialogData", "\345\267\245  \350\265\204", nullptr));
        comboEdu->setItemText(0, QCoreApplication::translate("WDialogData", "\345\215\232\345\243\253\347\240\224\347\251\266\347\224\237", nullptr));
        comboEdu->setItemText(1, QCoreApplication::translate("WDialogData", "\347\241\225\345\243\253\347\240\224\347\251\266\347\224\237", nullptr));
        comboEdu->setItemText(2, QCoreApplication::translate("WDialogData", "\345\244\247\345\255\246\346\234\254\347\247\221", nullptr));
        comboEdu->setItemText(3, QCoreApplication::translate("WDialogData", "\345\244\247\345\255\246\344\270\223\347\247\221", nullptr));
        comboEdu->setItemText(4, QCoreApplication::translate("WDialogData", "\351\253\230\344\270\255", nullptr));
        comboEdu->setItemText(5, QCoreApplication::translate("WDialogData", "\345\210\235\344\270\255", nullptr));
        comboEdu->setItemText(6, QCoreApplication::translate("WDialogData", "\345\260\217\345\255\246", nullptr));

        comboEdu->setCurrentText(QCoreApplication::translate("WDialogData", "\345\215\232\345\243\253\347\240\224\347\251\266\347\224\237", nullptr));
        label_13->setText(QCoreApplication::translate("WDialogData", "\347\205\247  \347\211\207", nullptr));
        LabPhoto->setText(QCoreApplication::translate("WDialogData", "dbLabPhoto", nullptr));
        btnSetPhoto->setText(QCoreApplication::translate("WDialogData", "\345\257\274\345\205\245\347\205\247\347\211\207", nullptr));
        btnClearPhoto->setText(QCoreApplication::translate("WDialogData", "\346\270\205\351\231\244\347\205\247\347\211\207", nullptr));
        btnOK->setText(QCoreApplication::translate("WDialogData", "\347\241\256  \345\256\232", nullptr));
        btnClose->setText(QCoreApplication::translate("WDialogData", "\345\217\226  \346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WDialogData: public Ui_WDialogData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDIALOGDATA_H
