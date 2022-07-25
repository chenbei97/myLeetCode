/********************************************************************************
** Form generated from reading UI file 'Test3DScatter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3DSCATTER_H
#define UI_TEST3DSCATTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test3DScatter
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QComboBox *comboBox;
    QLabel *label_7;
    QSlider *sliderH;
    QLabel *label_8;
    QSlider *sliderV;
    QLabel *label_9;
    QSlider *sliderZoom;
    QLabel *label;
    QComboBox *cBoxTheme;
    QLabel *label_2;
    QComboBox *cBoxBarStyle;
    QLabel *label_3;
    QComboBox *cBoxSelectionMode;
    QLabel *label_4;
    QSpinBox *spinFontSize;
    QLabel *label_5;
    QDoubleSpinBox *spinItemSize;
    QPushButton *btnBarColor;
    QGridLayout *gridLayout_2;
    QCheckBox *chkBoxBackground;
    QCheckBox *chkBoxGrid;
    QCheckBox *chkBoxShadow;
    QCheckBox *chkBoxReflection;
    QCheckBox *chkBoxSmooth;
    QCheckBox *chkBoxReverse;
    QCheckBox *chkBoxItemLabel;
    QCheckBox *chkBoxAxisTitle;
    QCheckBox *chkBoxAxisBackground;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *Test3DScatter)
    {
        if (Test3DScatter->objectName().isEmpty())
            Test3DScatter->setObjectName(QStringLiteral("Test3DScatter"));
        Test3DScatter->resize(1000, 580);
        Test3DScatter->setMinimumSize(QSize(1000, 580));
        Test3DScatter->setMaximumSize(QSize(1000, 580));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        Test3DScatter->setFont(font);
        centralwidget = new QWidget(Test3DScatter);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 371, 571));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        sliderH = new QSlider(groupBox);
        sliderH->setObjectName(QStringLiteral("sliderH"));
        sliderH->setMinimum(-180);
        sliderH->setMaximum(180);
        sliderH->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderH, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        sliderV = new QSlider(groupBox);
        sliderV->setObjectName(QStringLiteral("sliderV"));
        sliderV->setMinimum(-180);
        sliderV->setMaximum(180);
        sliderV->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderV, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        sliderZoom = new QSlider(groupBox);
        sliderZoom->setObjectName(QStringLiteral("sliderZoom"));
        sliderZoom->setMinimum(10);
        sliderZoom->setMaximum(500);
        sliderZoom->setValue(100);
        sliderZoom->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderZoom, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        cBoxTheme = new QComboBox(groupBox);
        cBoxTheme->setObjectName(QStringLiteral("cBoxTheme"));

        gridLayout->addWidget(cBoxTheme, 4, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        cBoxBarStyle = new QComboBox(groupBox);
        cBoxBarStyle->setObjectName(QStringLiteral("cBoxBarStyle"));

        gridLayout->addWidget(cBoxBarStyle, 5, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        cBoxSelectionMode = new QComboBox(groupBox);
        cBoxSelectionMode->setObjectName(QStringLiteral("cBoxSelectionMode"));

        gridLayout->addWidget(cBoxSelectionMode, 6, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        spinFontSize = new QSpinBox(groupBox);
        spinFontSize->setObjectName(QStringLiteral("spinFontSize"));
        spinFontSize->setMinimum(5);
        spinFontSize->setValue(10);

        gridLayout->addWidget(spinFontSize, 7, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        spinItemSize = new QDoubleSpinBox(groupBox);
        spinItemSize->setObjectName(QStringLiteral("spinItemSize"));
        spinItemSize->setMaximum(1);
        spinItemSize->setSingleStep(0.02);

        gridLayout->addWidget(spinItemSize, 8, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        btnBarColor = new QPushButton(groupBox);
        btnBarColor->setObjectName(QStringLiteral("btnBarColor"));

        verticalLayout->addWidget(btnBarColor);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chkBoxBackground = new QCheckBox(groupBox);
        chkBoxBackground->setObjectName(QStringLiteral("chkBoxBackground"));

        gridLayout_2->addWidget(chkBoxBackground, 0, 0, 1, 1);

        chkBoxGrid = new QCheckBox(groupBox);
        chkBoxGrid->setObjectName(QStringLiteral("chkBoxGrid"));

        gridLayout_2->addWidget(chkBoxGrid, 0, 1, 1, 1);

        chkBoxShadow = new QCheckBox(groupBox);
        chkBoxShadow->setObjectName(QStringLiteral("chkBoxShadow"));

        gridLayout_2->addWidget(chkBoxShadow, 1, 0, 1, 1);

        chkBoxReflection = new QCheckBox(groupBox);
        chkBoxReflection->setObjectName(QStringLiteral("chkBoxReflection"));

        gridLayout_2->addWidget(chkBoxReflection, 1, 1, 1, 1);

        chkBoxSmooth = new QCheckBox(groupBox);
        chkBoxSmooth->setObjectName(QStringLiteral("chkBoxSmooth"));

        gridLayout_2->addWidget(chkBoxSmooth, 2, 0, 1, 1);

        chkBoxReverse = new QCheckBox(groupBox);
        chkBoxReverse->setObjectName(QStringLiteral("chkBoxReverse"));

        gridLayout_2->addWidget(chkBoxReverse, 2, 1, 1, 1);

        chkBoxItemLabel = new QCheckBox(groupBox);
        chkBoxItemLabel->setObjectName(QStringLiteral("chkBoxItemLabel"));

        gridLayout_2->addWidget(chkBoxItemLabel, 3, 0, 1, 1);

        chkBoxAxisTitle = new QCheckBox(groupBox);
        chkBoxAxisTitle->setObjectName(QStringLiteral("chkBoxAxisTitle"));

        gridLayout_2->addWidget(chkBoxAxisTitle, 3, 1, 1, 1);

        chkBoxAxisBackground = new QCheckBox(groupBox);
        chkBoxAxisBackground->setObjectName(QStringLiteral("chkBoxAxisBackground"));

        gridLayout_2->addWidget(chkBoxAxisBackground, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Test3DScatter->setCentralWidget(centralwidget);
#ifndef QT_NO_SHORTCUT
        label_6->setBuddy(comboBox);
        label_7->setBuddy(sliderH);
        label_8->setBuddy(sliderV);
        label_9->setBuddy(sliderZoom);
        label->setBuddy(cBoxTheme);
        label_2->setBuddy(cBoxBarStyle);
        label_3->setBuddy(cBoxSelectionMode);
        label_4->setBuddy(spinFontSize);
        label_5->setBuddy(spinItemSize);
#endif // QT_NO_SHORTCUT

        retranslateUi(Test3DScatter);

        QMetaObject::connectSlotsByName(Test3DScatter);
    } // setupUi

    void retranslateUi(QMainWindow *Test3DScatter)
    {
        Test3DScatter->setWindowTitle(QApplication::translate("Test3DScatter", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("Test3DScatter", "\351\242\204\350\256\276\350\247\206\350\247\222", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Test3DScatter", "FrontLow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Front", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "FrontHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "LeftLow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Left", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "LeftHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "RightLow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Right", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "RightHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "BehindLow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Behind", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "BehindHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "IsometricLeft", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "IsometricLeftHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "IsometricRight", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "IsometricRightHigh", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "DirectlyAbove", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "DirectlyAboveCW45", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "DirectlyAboveCCW45", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "FrontBelow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "LeftBelow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "RightBelow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "BehindBelow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "DirectlyBelow", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Test3DScatter", "\346\260\264\345\271\263\346\227\213\350\275\254", Q_NULLPTR));
        label_8->setText(QApplication::translate("Test3DScatter", "\345\236\202\347\233\264\346\227\213\350\275\254", Q_NULLPTR));
        label_9->setText(QApplication::translate("Test3DScatter", "\347\274\251  \346\224\276", Q_NULLPTR));
        label->setText(QApplication::translate("Test3DScatter", "\344\270\273  \351\242\230", Q_NULLPTR));
        cBoxTheme->clear();
        cBoxTheme->insertItems(0, QStringList()
         << QApplication::translate("Test3DScatter", "Qt", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Primary Colors", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Digia", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "StoneMoss", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "ArmyBlue", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Retro", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Ebony", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Isabelle", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Test3DScatter", "\346\225\243\347\202\271\345\275\242\347\212\266", Q_NULLPTR));
        cBoxBarStyle->clear();
        cBoxBarStyle->insertItems(0, QStringList()
         << QApplication::translate("Test3DScatter", "Bar", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Cube", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Pyramid", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Cone", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Cylinder", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "BevelBar", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "BevelCube", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Sphere", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Minimal", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Arrow", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Point", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Test3DScatter", "\351\200\211\346\213\251\346\250\241\345\274\217", Q_NULLPTR));
        cBoxSelectionMode->clear();
        cBoxSelectionMode->insertItems(0, QStringList()
         << QApplication::translate("Test3DScatter", "None", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Item", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Row", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Item And Row", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Column", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Item And Column", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Row And Column", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Item Row And Column", Q_NULLPTR)
         << QApplication::translate("Test3DScatter", "Slice", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Test3DScatter", "\350\275\264\345\255\227\344\275\223\345\244\247\345\260\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("Test3DScatter", "\346\225\243\347\202\271\345\244\247\345\260\217", Q_NULLPTR));
        btnBarColor->setText(QApplication::translate("Test3DScatter", "\350\256\276\347\275\256\346\225\243\347\202\271\351\242\234\350\211\262", Q_NULLPTR));
        chkBoxBackground->setText(QApplication::translate("Test3DScatter", "\346\230\276\347\244\272\350\203\214\346\231\257", Q_NULLPTR));
        chkBoxGrid->setText(QApplication::translate("Test3DScatter", "\346\230\276\347\244\272\350\203\214\346\231\257\347\275\221\346\240\274", Q_NULLPTR));
        chkBoxShadow->setText(QApplication::translate("Test3DScatter", "\346\230\276\347\244\272\351\230\264\345\275\261", Q_NULLPTR));
        chkBoxReflection->setText(QApplication::translate("Test3DScatter", "\346\230\276\347\244\272\345\200\222\345\275\261", Q_NULLPTR));
        chkBoxSmooth->setText(QApplication::translate("Test3DScatter", "\345\205\211\346\273\221\346\225\210\346\236\234", Q_NULLPTR));
        chkBoxReverse->setText(QApplication::translate("Test3DScatter", "\345\236\202\347\233\264\345\235\220\346\240\207\350\275\264\345\217\215\345\220\221", Q_NULLPTR));
        chkBoxItemLabel->setText(QApplication::translate("Test3DScatter", "\351\241\271\346\240\207\347\255\276\345\217\257\350\247\201", Q_NULLPTR));
        chkBoxAxisTitle->setText(QApplication::translate("Test3DScatter", "\350\275\264\346\240\207\351\242\230\345\217\257\350\247\201", Q_NULLPTR));
        chkBoxAxisBackground->setText(QApplication::translate("Test3DScatter", "\346\230\276\347\244\272\350\275\264\346\240\207\347\255\276\350\203\214\346\231\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Test3DScatter: public Ui_Test3DScatter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3DSCATTER_H
