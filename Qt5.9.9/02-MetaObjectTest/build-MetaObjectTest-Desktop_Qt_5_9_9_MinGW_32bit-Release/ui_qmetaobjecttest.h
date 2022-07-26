/********************************************************************************
** Form generated from reading UI file 'qmetaobjecttest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMETAOBJECTTEST_H
#define UI_QMETAOBJECTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMetaObjectTest
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBoy;
    QPushButton *btnBoyInc;
    QPushButton *btnClassInfo;
    QLabel *label_2;
    QSpinBox *spinGirl;
    QPushButton *btnGirlInc;
    QPushButton *btnClear;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *QMetaObjectTest)
    {
        if (QMetaObjectTest->objectName().isEmpty())
            QMetaObjectTest->setObjectName(QStringLiteral("QMetaObjectTest"));
        QMetaObjectTest->resize(800, 600);
        layoutWidget = new QWidget(QMetaObjectTest);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 641, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBoy = new QSpinBox(layoutWidget);
        spinBoy->setObjectName(QStringLiteral("spinBoy"));
        spinBoy->setMinimum(0);
        spinBoy->setMaximum(200);
        spinBoy->setValue(10);

        gridLayout->addWidget(spinBoy, 0, 1, 1, 1);

        btnBoyInc = new QPushButton(layoutWidget);
        btnBoyInc->setObjectName(QStringLiteral("btnBoyInc"));

        gridLayout->addWidget(btnBoyInc, 0, 2, 1, 1);

        btnClassInfo = new QPushButton(layoutWidget);
        btnClassInfo->setObjectName(QStringLiteral("btnClassInfo"));

        gridLayout->addWidget(btnClassInfo, 0, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinGirl = new QSpinBox(layoutWidget);
        spinGirl->setObjectName(QStringLiteral("spinGirl"));
        spinGirl->setMaximum(200);
        spinGirl->setValue(20);

        gridLayout->addWidget(spinGirl, 1, 1, 1, 1);

        btnGirlInc = new QPushButton(layoutWidget);
        btnGirlInc->setObjectName(QStringLiteral("btnGirlInc"));

        gridLayout->addWidget(btnGirlInc, 1, 2, 1, 1);

        btnClear = new QPushButton(layoutWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        gridLayout->addWidget(btnClear, 1, 3, 1, 1);

        plainTextEdit = new QPlainTextEdit(QMetaObjectTest);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(80, 160, 651, 421));

        retranslateUi(QMetaObjectTest);

        QMetaObject::connectSlotsByName(QMetaObjectTest);
    } // setupUi

    void retranslateUi(QWidget *QMetaObjectTest)
    {
        QMetaObjectTest->setWindowTitle(QApplication::translate("QMetaObjectTest", "QMetaObjectTest", Q_NULLPTR));
        label->setText(QApplication::translate("QMetaObjectTest", "\350\256\276\347\275\256\347\224\267\347\224\237\345\271\264\351\276\204", Q_NULLPTR));
        btnBoyInc->setText(QApplication::translate("QMetaObjectTest", "boy\351\225\277\345\244\247\344\270\200\345\262\201", Q_NULLPTR));
        btnClassInfo->setText(QApplication::translate("QMetaObjectTest", "\347\261\273\347\232\204\345\205\203\345\257\271\350\261\241\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("QMetaObjectTest", "\350\256\276\347\275\256\345\245\263\347\224\237\345\271\264\351\276\204", Q_NULLPTR));
        btnGirlInc->setText(QApplication::translate("QMetaObjectTest", "girl\351\225\277\345\244\247\344\270\200\345\262\201", Q_NULLPTR));
        btnClear->setText(QApplication::translate("QMetaObjectTest", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QMetaObjectTest: public Ui_QMetaObjectTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMETAOBJECTTEST_H
