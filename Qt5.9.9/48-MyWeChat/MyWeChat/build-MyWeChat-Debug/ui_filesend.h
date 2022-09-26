/********************************************************************************
** Form generated from reading UI file 'filesend.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESEND_H
#define UI_FILESEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileSend
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *sfileNameLineEdit;
    QPushButton *openFilePushButton;
    QPushButton *sendFilePushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *sfileSizeLineEdit;
    QLabel *label_4;
    QLineEdit *sendSizeLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *sendProgressBar;
    QPushButton *srvClosePushButton;

    void setupUi(QDialog *FileSend)
    {
        if (FileSend->objectName().isEmpty())
            FileSend->setObjectName(QStringLiteral("FileSend"));
        FileSend->resize(576, 273);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(11);
        FileSend->setFont(font);
        gridLayout = new QGridLayout(FileSend);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(FileSend);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(FileSend);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        sfileNameLineEdit = new QLineEdit(FileSend);
        sfileNameLineEdit->setObjectName(QStringLiteral("sfileNameLineEdit"));
        sfileNameLineEdit->setEnabled(false);
        sfileNameLineEdit->setFont(font2);
        sfileNameLineEdit->setAlignment(Qt::AlignCenter);
        sfileNameLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(sfileNameLineEdit);

        openFilePushButton = new QPushButton(FileSend);
        openFilePushButton->setObjectName(QStringLiteral("openFilePushButton"));
        openFilePushButton->setFont(font2);

        horizontalLayout->addWidget(openFilePushButton);

        sendFilePushButton = new QPushButton(FileSend);
        sendFilePushButton->setObjectName(QStringLiteral("sendFilePushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        sendFilePushButton->setFont(font3);

        horizontalLayout->addWidget(sendFilePushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(FileSend);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        sfileSizeLineEdit = new QLineEdit(FileSend);
        sfileSizeLineEdit->setObjectName(QStringLiteral("sfileSizeLineEdit"));
        sfileSizeLineEdit->setEnabled(false);
        sfileSizeLineEdit->setFont(font2);
        sfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        sfileSizeLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(sfileSizeLineEdit);

        label_4 = new QLabel(FileSend);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);

        sendSizeLineEdit = new QLineEdit(FileSend);
        sendSizeLineEdit->setObjectName(QStringLiteral("sendSizeLineEdit"));
        sendSizeLineEdit->setEnabled(false);
        sendSizeLineEdit->setFont(font2);
        sendSizeLineEdit->setAlignment(Qt::AlignCenter);
        sendSizeLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(sendSizeLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(FileSend);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        horizontalLayout_3->addWidget(label_5);

        sendProgressBar = new QProgressBar(FileSend);
        sendProgressBar->setObjectName(QStringLiteral("sendProgressBar"));
        sendProgressBar->setValue(0);

        horizontalLayout_3->addWidget(sendProgressBar);

        srvClosePushButton = new QPushButton(FileSend);
        srvClosePushButton->setObjectName(QStringLiteral("srvClosePushButton"));
        srvClosePushButton->setFont(font2);

        horizontalLayout_3->addWidget(srvClosePushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FileSend);

        QMetaObject::connectSlotsByName(FileSend);
    } // setupUi

    void retranslateUi(QDialog *FileSend)
    {
        FileSend->setWindowTitle(QApplication::translate("FileSend", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FileSend", "\346\226\207 \344\273\266 \345\217\221 \351\200\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileSend", "\345\217\221 \351\200\201 \346\226\207 \344\273\266", Q_NULLPTR));
        openFilePushButton->setText(QApplication::translate("FileSend", "...", Q_NULLPTR));
        sendFilePushButton->setText(QApplication::translate("FileSend", "\345\217\221  \351\200\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("FileSend", "\345\244\247   \345\260\217\357\274\232", Q_NULLPTR));
        sfileSizeLineEdit->setText(QString());
        label_4->setText(QApplication::translate("FileSend", "\345\267\262 \345\217\221 \351\200\201\357\274\232", Q_NULLPTR));
        sendSizeLineEdit->setText(QString());
        label_5->setText(QApplication::translate("FileSend", "\350\277\233         \345\272\246", Q_NULLPTR));
        srvClosePushButton->setText(QApplication::translate("FileSend", "\345\201\234  \346\255\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileSend: public Ui_FileSend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESEND_H
