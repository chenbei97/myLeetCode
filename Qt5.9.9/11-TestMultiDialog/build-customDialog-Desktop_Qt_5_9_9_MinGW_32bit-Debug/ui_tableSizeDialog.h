/********************************************************************************
** Form generated from reading UI file 'tableSizeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLESIZEDIALOG_H
#define UI_TABLESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_tableSizeDialog
{
public:
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *spinBoxColumn;
    QLabel *label;
    QSpinBox *spinBoxRow;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *tableSizeDialog)
    {
        if (tableSizeDialog->objectName().isEmpty())
            tableSizeDialog->setObjectName(QStringLiteral("tableSizeDialog"));
        tableSizeDialog->resize(350, 175);
        tableSizeDialog->setMinimumSize(QSize(350, 175));
        tableSizeDialog->setMaximumSize(QSize(350, 175));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        tableSizeDialog->setFont(font);
        groupBox = new QGroupBox(tableSizeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 151));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBoxColumn = new QSpinBox(groupBox);
        spinBoxColumn->setObjectName(QStringLiteral("spinBoxColumn"));
        spinBoxColumn->setMinimum(1);
        spinBoxColumn->setMaximum(500);
        spinBoxColumn->setValue(6);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxColumn);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        spinBoxRow = new QSpinBox(groupBox);
        spinBoxRow->setObjectName(QStringLiteral("spinBoxRow"));
        spinBoxRow->setMinimum(1);
        spinBoxRow->setMaximum(500);
        spinBoxRow->setValue(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxRow);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        splitter = new QSplitter(tableSizeDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(250, 40, 91, 101));
        splitter->setOrientation(Qt::Vertical);
        btnOK = new QPushButton(splitter);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnOK->setIcon(icon);
        splitter->addWidget(btnOK);
        btnCancel = new QPushButton(splitter);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        splitter->addWidget(btnCancel);

        retranslateUi(tableSizeDialog);

        QMetaObject::connectSlotsByName(tableSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *tableSizeDialog)
    {
        tableSizeDialog->setWindowTitle(QApplication::translate("tableSizeDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("tableSizeDialog", "\350\256\276\347\275\256\350\241\250\346\240\274\350\241\214\346\225\260\345\222\214\345\210\227\346\225\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("tableSizeDialog", "\345\210\227  \346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("tableSizeDialog", "\350\241\214  \346\225\260", Q_NULLPTR));
        btnOK->setText(QApplication::translate("tableSizeDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("tableSizeDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tableSizeDialog: public Ui_tableSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLESIZEDIALOG_H
