/********************************************************************************
** Form generated from reading UI file 'tableItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEITEMDIALOG_H
#define UI_TABLEITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_tableItemDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label1;
    QSpinBox *spinBoxColumn;
    QLabel *label2;
    QSpinBox *spinBoxRow;
    QLabel *label3;
    QLineEdit *edtCaption;
    QSplitter *splitter;
    QPushButton *btnSetText;
    QPushButton *btnClose;
    QLabel *label;

    void setupUi(QDialog *tableItemDialog)
    {
        if (tableItemDialog->objectName().isEmpty())
            tableItemDialog->setObjectName(QStringLiteral("tableItemDialog"));
        tableItemDialog->resize(450, 270);
        tableItemDialog->setMinimumSize(QSize(450, 270));
        tableItemDialog->setMaximumSize(QSize(450, 270));
        tableItemDialog->setSizeIncrement(QSize(460, 210));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        tableItemDialog->setFont(font);
        groupBox = new QGroupBox(tableItemDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 181));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label1 = new QLabel(groupBox);
        label1->setObjectName(QStringLiteral("label1"));

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        spinBoxColumn = new QSpinBox(groupBox);
        spinBoxColumn->setObjectName(QStringLiteral("spinBoxColumn"));
        spinBoxColumn->setMinimum(0);

        gridLayout->addWidget(spinBoxColumn, 0, 1, 1, 1);

        label2 = new QLabel(groupBox);
        label2->setObjectName(QStringLiteral("label2"));

        gridLayout->addWidget(label2, 1, 0, 1, 1);

        spinBoxRow = new QSpinBox(groupBox);
        spinBoxRow->setObjectName(QStringLiteral("spinBoxRow"));

        gridLayout->addWidget(spinBoxRow, 1, 1, 1, 1);

        label3 = new QLabel(groupBox);
        label3->setObjectName(QStringLiteral("label3"));

        gridLayout->addWidget(label3, 2, 0, 1, 1);

        edtCaption = new QLineEdit(groupBox);
        edtCaption->setObjectName(QStringLiteral("edtCaption"));

        gridLayout->addWidget(edtCaption, 2, 1, 1, 2);

        splitter = new QSplitter(tableItemDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(340, 40, 101, 131));
        splitter->setOrientation(Qt::Vertical);
        btnSetText = new QPushButton(splitter);
        btnSetText->setObjectName(QStringLiteral("btnSetText"));
        QFont font1;
        font1.setFamily(QStringLiteral("Trebuchet MS"));
        font1.setPointSize(12);
        btnSetText->setFont(font1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/506.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetText->setIcon(icon);
        splitter->addWidget(btnSetText);
        btnClose = new QPushButton(splitter);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        btnClose->setIcon(icon1);
        splitter->addWidget(btnClose);
        label = new QLabel(tableItemDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 200, 420, 61));

        retranslateUi(tableItemDialog);

        QMetaObject::connectSlotsByName(tableItemDialog);
    } // setupUi

    void retranslateUi(QDialog *tableItemDialog)
    {
        tableItemDialog->setWindowTitle(QApplication::translate("tableItemDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        label1->setText(QApplication::translate("tableItemDialog", "\345\210\227  \345\217\267", Q_NULLPTR));
        label2->setText(QApplication::translate("tableItemDialog", "\350\241\214  \345\217\267", Q_NULLPTR));
        label3->setText(QApplication::translate("tableItemDialog", "\350\256\276\345\256\232\346\226\207\345\255\227", Q_NULLPTR));
        btnSetText->setText(QApplication::translate("tableItemDialog", "\350\256\276\345\256\232\346\226\207\345\255\227", Q_NULLPTR));
        btnClose->setText(QApplication::translate("tableItemDialog", "\345\205\263  \351\227\255", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tableItemDialog: public Ui_tableItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEITEMDIALOG_H
