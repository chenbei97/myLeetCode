/********************************************************************************
** Form generated from reading UI file 'Test3DSurface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3DSURFACE_H
#define UI_TEST3DSURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_Test3DSurface
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
    QLabel *label_12;
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
    QComboBox *comboDrawMode;
    QGridLayout *gridLayout_3;
    QCheckBox *chkBoxBackground;
    QCheckBox *chkBoxGrid;
    QCheckBox *chkBoxShadow;
    QCheckBox *chkBoxReflection;
    QCheckBox *chkBoxSmooth;
    QCheckBox *chkBoxReverse;
    QCheckBox *chkBoxItemLabel;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chkBoxAxisTitle;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *chkBoxAxisBackground;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QPushButton *btnBarColor;
    QLabel *label_9;
    QPushButton *btnGrad1;
    QLabel *label_10;
    QPushButton *btnGrad2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *Test3DSurface)
    {
        if (Test3DSurface->objectName().isEmpty())
            Test3DSurface->setObjectName(QStringLiteral("Test3DSurface"));
        Test3DSurface->resize(1000, 680);
        Test3DSurface->setMinimumSize(QSize(1000, 680));
        Test3DSurface->setMaximumSize(QSize(1000, 680));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        Test3DSurface->setFont(font);
        centralwidget = new QWidget(Test3DSurface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 311, 681));
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

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

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

        comboDrawMode = new QComboBox(groupBox);
        comboDrawMode->setObjectName(QStringLiteral("comboDrawMode"));

        gridLayout->addWidget(comboDrawMode, 8, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        chkBoxBackground = new QCheckBox(groupBox);
        chkBoxBackground->setObjectName(QStringLiteral("chkBoxBackground"));

        gridLayout_3->addWidget(chkBoxBackground, 0, 0, 1, 1);

        chkBoxGrid = new QCheckBox(groupBox);
        chkBoxGrid->setObjectName(QStringLiteral("chkBoxGrid"));

        gridLayout_3->addWidget(chkBoxGrid, 0, 1, 1, 3);

        chkBoxShadow = new QCheckBox(groupBox);
        chkBoxShadow->setObjectName(QStringLiteral("chkBoxShadow"));

        gridLayout_3->addWidget(chkBoxShadow, 1, 0, 1, 1);

        chkBoxReflection = new QCheckBox(groupBox);
        chkBoxReflection->setObjectName(QStringLiteral("chkBoxReflection"));

        gridLayout_3->addWidget(chkBoxReflection, 1, 1, 1, 3);

        chkBoxSmooth = new QCheckBox(groupBox);
        chkBoxSmooth->setObjectName(QStringLiteral("chkBoxSmooth"));

        gridLayout_3->addWidget(chkBoxSmooth, 2, 0, 1, 1);

        chkBoxReverse = new QCheckBox(groupBox);
        chkBoxReverse->setObjectName(QStringLiteral("chkBoxReverse"));

        gridLayout_3->addWidget(chkBoxReverse, 2, 1, 1, 3);

        chkBoxItemLabel = new QCheckBox(groupBox);
        chkBoxItemLabel->setObjectName(QStringLiteral("chkBoxItemLabel"));

        gridLayout_3->addWidget(chkBoxItemLabel, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 2, 1, 2);

        chkBoxAxisTitle = new QCheckBox(groupBox);
        chkBoxAxisTitle->setObjectName(QStringLiteral("chkBoxAxisTitle"));

        gridLayout_3->addWidget(chkBoxAxisTitle, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 4, 2, 2, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 5, 3, 2, 1);

        chkBoxAxisBackground = new QCheckBox(groupBox);
        chkBoxAxisBackground->setObjectName(QStringLiteral("chkBoxAxisBackground"));

        gridLayout_3->addWidget(chkBoxAxisBackground, 6, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        btnBarColor = new QPushButton(groupBox);
        btnBarColor->setObjectName(QStringLiteral("btnBarColor"));

        gridLayout_2->addWidget(btnBarColor, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        btnGrad1 = new QPushButton(groupBox);
        btnGrad1->setObjectName(QStringLiteral("btnGrad1"));

        gridLayout_2->addWidget(btnGrad1, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        btnGrad2 = new QPushButton(groupBox);
        btnGrad2->setObjectName(QStringLiteral("btnGrad2"));

        gridLayout_2->addWidget(btnGrad2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Test3DSurface->setCentralWidget(centralwidget);
#ifndef QT_NO_SHORTCUT
        label_6->setBuddy(comboBox);
        label_7->setBuddy(sliderH);
        label_8->setBuddy(sliderV);
        label->setBuddy(cBoxTheme);
        label_2->setBuddy(cBoxBarStyle);
        label_3->setBuddy(cBoxSelectionMode);
        label_4->setBuddy(spinFontSize);
        label_11->setBuddy(btnBarColor);
        label_9->setBuddy(btnGrad1);
        label_10->setBuddy(btnGrad2);
#endif // QT_NO_SHORTCUT

        retranslateUi(Test3DSurface);

        QMetaObject::connectSlotsByName(Test3DSurface);
    } // setupUi

    void retranslateUi(QMainWindow *Test3DSurface)
    {
        Test3DSurface->setWindowTitle(QApplication::translate("Test3DSurface", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("Test3DSurface", "\351\242\204\350\256\276\350\247\206\350\247\222", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Test3DSurface", "FrontLow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Front", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "FrontHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "LeftLow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Left", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "LeftHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "RightLow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Right", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "RightHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "BehindLow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Behind", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "BehindHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "IsometricLeft", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "IsometricLeftHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "IsometricRight", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "IsometricRightHigh", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "DirectlyAbove", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "DirectlyAboveCW45", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "DirectlyAboveCCW45", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "FrontBelow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "LeftBelow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "RightBelow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "BehindBelow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "DirectlyBelow", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Test3DSurface", "\346\260\264\345\271\263\346\227\213\350\275\254", Q_NULLPTR));
        label_8->setText(QApplication::translate("Test3DSurface", "\345\236\202\347\233\264\346\227\213\350\275\254", Q_NULLPTR));
        label_12->setText(QApplication::translate("Test3DSurface", "\347\274\251  \346\224\276", Q_NULLPTR));
        label->setText(QApplication::translate("Test3DSurface", "\344\270\273  \351\242\230", Q_NULLPTR));
        cBoxTheme->clear();
        cBoxTheme->insertItems(0, QStringList()
         << QApplication::translate("Test3DSurface", "Qt", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Primary Colors", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Digia", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "StoneMoss", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "ArmyBlue", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Retro", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Ebony", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Isabelle", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Test3DSurface", "\345\215\225\347\202\271\345\275\242\347\212\266", Q_NULLPTR));
        cBoxBarStyle->clear();
        cBoxBarStyle->insertItems(0, QStringList()
         << QApplication::translate("Test3DSurface", "Bar", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Cube", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Pyramid", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Cone", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Cylinder", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "BevelBar", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "BevelCube", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Sphere", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Minimal", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Arrow", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Point", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("Test3DSurface", "\351\200\211\346\213\251\346\250\241\345\274\217", Q_NULLPTR));
        cBoxSelectionMode->clear();
        cBoxSelectionMode->insertItems(0, QStringList()
         << QApplication::translate("Test3DSurface", "None", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Item", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Row Slice", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Column Slice", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Test3DSurface", "\350\275\264\345\255\227\344\275\223\345\244\247\345\260\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("Test3DSurface", "\346\233\262\351\235\242\346\240\267\345\274\217", Q_NULLPTR));
        comboDrawMode->clear();
        comboDrawMode->insertItems(0, QStringList()
         << QApplication::translate("Test3DSurface", "Wireframe", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Surface", Q_NULLPTR)
         << QApplication::translate("Test3DSurface", "Surface And Wireframe", Q_NULLPTR)
        );
        chkBoxBackground->setText(QApplication::translate("Test3DSurface", "\346\230\276\347\244\272\350\203\214\346\231\257", Q_NULLPTR));
        chkBoxGrid->setText(QApplication::translate("Test3DSurface", "\346\230\276\347\244\272\350\203\214\346\231\257\347\275\221\346\240\274", Q_NULLPTR));
        chkBoxShadow->setText(QApplication::translate("Test3DSurface", "\346\230\276\347\244\272\351\230\264\345\275\261", Q_NULLPTR));
        chkBoxReflection->setText(QApplication::translate("Test3DSurface", "\346\230\276\347\244\272\345\200\222\345\275\261", Q_NULLPTR));
        chkBoxSmooth->setText(QApplication::translate("Test3DSurface", "\345\205\211\346\273\221\346\233\262\351\235\242", Q_NULLPTR));
        chkBoxReverse->setText(QApplication::translate("Test3DSurface", "Y\350\275\264\345\217\215\345\220\221", Q_NULLPTR));
        chkBoxItemLabel->setText(QApplication::translate("Test3DSurface", "\351\241\271\346\240\207\347\255\276\345\217\257\350\247\201", Q_NULLPTR));
        chkBoxAxisTitle->setText(QApplication::translate("Test3DSurface", "\350\275\264\346\240\207\351\242\230\345\217\257\350\247\201", Q_NULLPTR));
        chkBoxAxisBackground->setText(QApplication::translate("Test3DSurface", "\346\230\276\347\244\272\350\275\264\346\240\207\347\255\276\350\203\214\346\231\257", Q_NULLPTR));
        label_11->setText(QApplication::translate("Test3DSurface", "\345\215\225\344\270\200\351\242\234\350\211\262", Q_NULLPTR));
        btnBarColor->setText(QApplication::translate("Test3DSurface", "\350\256\276\347\275\256\346\233\262\351\235\242\351\242\234\350\211\262", Q_NULLPTR));
        label_9->setText(QApplication::translate("Test3DSurface", "\346\270\220\345\217\230\350\211\2621", Q_NULLPTR));
        btnGrad1->setText(QString());
        label_10->setText(QApplication::translate("Test3DSurface", "\346\270\220\345\217\230\350\211\2622", Q_NULLPTR));
        btnGrad2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Test3DSurface: public Ui_Test3DSurface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3DSURFACE_H
