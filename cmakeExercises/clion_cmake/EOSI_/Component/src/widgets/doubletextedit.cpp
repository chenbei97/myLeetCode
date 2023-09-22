#include "../../inc/widgets/doubletextedit.h"

DoubleTextEdit::DoubleTextEdit(QWidget *parent) : QWidget(parent)
{
    leftbox = new GroupBox;
    rightbox = new GroupBox;
    leftedit = new QTextEdit;
    rightedit = new QTextEdit;
    auto line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Plain);

    QHBoxLayout * lay = new QHBoxLayout(this);

    leftbox = new GroupBox;
    auto lay1 = new QHBoxLayout;
    lay1->addWidget(leftedit);
    leftbox->setLayout(lay1);

    rightbox = new GroupBox;
    auto lay2 = new QHBoxLayout;
    lay2->addWidget(rightedit);
    rightbox->setLayout(lay2);

    lay->addWidget(leftbox);
    lay->addWidget(line);
    lay->addWidget(rightbox);

    setLeftReadonly(true);
    setRightReadonly(true);
}

void DoubleTextEdit::setLeftTitle(const QString &title)
{
    leftbox->setTitle(title);
}

void DoubleTextEdit::setRightTitle(const QString &title)
{
   rightbox->setTitle(title);
}

QString DoubleTextEdit::leftText() const
{
    return leftedit->toPlainText();
}

QString DoubleTextEdit::rightText() const
{
    return rightedit->toPlainText();
}

void DoubleTextEdit::setLeftText(const QString& text)
{
    leftedit->setText(text);
}

void DoubleTextEdit::setRightText(const QString& text)
{
    rightedit->setText(text);
}

void DoubleTextEdit::setLeftReadonly(bool r)
{
    leftedit->setReadOnly(r);
}

void DoubleTextEdit::setRightReadonly(bool r)
{
    rightedit->setReadOnly(r);
}

void DoubleTextEdit::setReadonly(bool r)
{
    setLeftReadonly(r);
    setRightReadonly(r);
}
