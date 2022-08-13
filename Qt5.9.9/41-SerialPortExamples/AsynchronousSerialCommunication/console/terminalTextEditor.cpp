#include "terminalTextEditor.h"
#include <QScrollBar>
terminalTextEditor::terminalTextEditor(QWidget*parent):QPlainTextEdit(parent)
{
        // this->setTabletTracking(true);
        this->document()->setMaximumBlockCount(100);
        QPalette p = palette();
        p.setColor(QPalette::Base, Qt::black);
        p.setColor(QPalette::Text, Qt::green);
        this->setPalette(p);
}

void terminalTextEditor::appendText(const QByteArray& s)
{
    this->insertPlainText(QString::fromLocal8Bit(s));
    QScrollBar *bar = this->verticalScrollBar();
    bar->setValue(bar->maximum()); // 更新垂直滑动条
}
