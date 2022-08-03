/********************************************************************************
** Form generated from reading UI file 'TestVideoPlayBack.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTVIDEOPLAYBACK_H
#define UI_TESTVIDEOPLAYBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestVideoPlayBack
{
public:
    QAction *actVideoWidget;
    QAction *actGraphicsVideoItem;
    QAction *actOperateCamera;
    QWidget *centralwidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestVideoPlayBack)
    {
        if (TestVideoPlayBack->objectName().isEmpty())
            TestVideoPlayBack->setObjectName(QStringLiteral("TestVideoPlayBack"));
        TestVideoPlayBack->resize(992, 213);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        TestVideoPlayBack->setFont(font);
        actVideoWidget = new QAction(TestVideoPlayBack);
        actVideoWidget->setObjectName(QStringLiteral("actVideoWidget"));
        actGraphicsVideoItem = new QAction(TestVideoPlayBack);
        actGraphicsVideoItem->setObjectName(QStringLiteral("actGraphicsVideoItem"));
        actOperateCamera = new QAction(TestVideoPlayBack);
        actOperateCamera->setObjectName(QStringLiteral("actOperateCamera"));
        centralwidget = new QWidget(TestVideoPlayBack);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TestVideoPlayBack->setCentralWidget(centralwidget);
        toolBar = new QToolBar(TestVideoPlayBack);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        TestVideoPlayBack->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actVideoWidget);
        toolBar->addAction(actGraphicsVideoItem);
        toolBar->addAction(actOperateCamera);

        retranslateUi(TestVideoPlayBack);

        QMetaObject::connectSlotsByName(TestVideoPlayBack);
    } // setupUi

    void retranslateUi(QMainWindow *TestVideoPlayBack)
    {
        TestVideoPlayBack->setWindowTitle(QApplication::translate("TestVideoPlayBack", "TestVideoPlayBack", Q_NULLPTR));
        actVideoWidget->setText(QApplication::translate("TestVideoPlayBack", "\345\237\272\344\272\216QVideoWidget\347\232\204\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actVideoWidget->setToolTip(QApplication::translate("TestVideoPlayBack", "\345\237\272\344\272\216QVideoWidget\347\232\204\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actGraphicsVideoItem->setText(QApplication::translate("TestVideoPlayBack", "\345\237\272\344\272\216QGraphicsVideoItem\347\232\204\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actGraphicsVideoItem->setToolTip(QApplication::translate("TestVideoPlayBack", "\345\237\272\344\272\216QGraphicsVideoItem\347\232\204\350\247\206\351\242\221\346\222\255\346\224\276\345\231\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actOperateCamera->setText(QApplication::translate("TestVideoPlayBack", "\346\221\204\345\203\217\345\244\264\346\223\215\344\275\234", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOperateCamera->setToolTip(QApplication::translate("TestVideoPlayBack", "\346\221\204\345\203\217\345\244\264\346\223\215\344\275\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("TestVideoPlayBack", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestVideoPlayBack: public Ui_TestVideoPlayBack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTVIDEOPLAYBACK_H
