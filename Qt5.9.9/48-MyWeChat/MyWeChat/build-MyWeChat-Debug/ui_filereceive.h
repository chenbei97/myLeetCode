/********************************************************************************
** Form generated from reading UI file 'filereceive.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECEIVE_H
#define UI_FILERECEIVE_H

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

class Ui_FileReceive
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *rfileNameLineEdit;
    QPushButton *cntClosePushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *rfileSizeLineEdit;
    QLabel *label_4;
    QLineEdit *recvSizeLineEdit;
    QLabel *rateLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *recvProgressBar;

    void setupUi(QDialog *FileReceive)
    {
        if (FileReceive->objectName().isEmpty())
            FileReceive->setObjectName(QStringLiteral("FileReceive"));
        FileReceive->resize(572, 297);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        FileReceive->setFont(font);
        gridLayout = new QGridLayout(FileReceive);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(FileReceive);
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
        label_2 = new QLabel(FileReceive);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        rfileNameLineEdit = new QLineEdit(FileReceive);
        rfileNameLineEdit->setObjectName(QStringLiteral("rfileNameLineEdit"));
        rfileNameLineEdit->setEnabled(false);
        rfileNameLineEdit->setFont(font2);
        rfileNameLineEdit->setAlignment(Qt::AlignCenter);
        rfileNameLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(rfileNameLineEdit);

        cntClosePushButton = new QPushButton(FileReceive);
        cntClosePushButton->setObjectName(QStringLiteral("cntClosePushButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        cntClosePushButton->setFont(font3);

        horizontalLayout->addWidget(cntClosePushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(FileReceive);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        rfileSizeLineEdit = new QLineEdit(FileReceive);
        rfileSizeLineEdit->setObjectName(QStringLiteral("rfileSizeLineEdit"));
        rfileSizeLineEdit->setEnabled(false);
        rfileSizeLineEdit->setFont(font2);
        rfileSizeLineEdit->setAlignment(Qt::AlignCenter);
        rfileSizeLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(rfileSizeLineEdit);

        label_4 = new QLabel(FileReceive);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);

        recvSizeLineEdit = new QLineEdit(FileReceive);
        recvSizeLineEdit->setObjectName(QStringLiteral("recvSizeLineEdit"));
        recvSizeLineEdit->setEnabled(false);
        recvSizeLineEdit->setFont(font2);
        recvSizeLineEdit->setAlignment(Qt::AlignCenter);
        recvSizeLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(recvSizeLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        rateLabel = new QLabel(FileReceive);
        rateLabel->setObjectName(QStringLiteral("rateLabel"));
        rateLabel->setFont(font2);
        rateLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(rateLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(FileReceive);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        horizontalLayout_3->addWidget(label_5);

        recvProgressBar = new QProgressBar(FileReceive);
        recvProgressBar->setObjectName(QStringLiteral("recvProgressBar"));
        recvProgressBar->setValue(0);

        horizontalLayout_3->addWidget(recvProgressBar);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(FileReceive);

        QMetaObject::connectSlotsByName(FileReceive);
    } // setupUi

    void retranslateUi(QDialog *FileReceive)
    {
        FileReceive->setWindowTitle(QApplication::translate("FileReceive", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FileReceive", "\346\226\207 \344\273\266 \346\216\245 \346\224\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("FileReceive", "\346\216\245 \346\224\266 \346\226\207 \344\273\266", Q_NULLPTR));
        cntClosePushButton->setText(QApplication::translate("FileReceive", "\345\201\234  \346\255\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("FileReceive", "\345\244\247   \345\260\217\357\274\232", Q_NULLPTR));
        rfileSizeLineEdit->setText(QString());
        label_4->setText(QApplication::translate("FileReceive", "\345\267\262 \346\216\245 \346\224\266\357\274\232", Q_NULLPTR));
        recvSizeLineEdit->setText(QString());
        rateLabel->setText(QString());
        label_5->setText(QApplication::translate("FileReceive", "\350\277\233         \345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileReceive: public Ui_FileReceive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECEIVE_H
