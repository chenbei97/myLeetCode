#include "label.h"

Label::Label(QWidget * parent):QLabel(parent)
{
      this->init();
}

Label::Label(const char * text, QWidget * parent):QLabel(parent)
{
      this->setText(text);
      this->init();
}

Label::Label(const QString& text,QWidget * parent):QLabel(parent)
{
      this->setText(text);
      this->init();
}

void Label::init()
{
     this->setAlignment(Qt::AlignCenter);
     this->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
     this->setFrameStyle(QFrame::Sunken | QFrame::Panel);
}
