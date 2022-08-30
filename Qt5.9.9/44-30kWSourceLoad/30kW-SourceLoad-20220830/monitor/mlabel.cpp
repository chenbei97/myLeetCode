#include "mlabel.h"
// QPalette VolatgePalette = ShowVoltage->palette();VolatgePalette.setColor(QPalette::Background,Qt::red);howVoltage->setPalette(VolatgePalette);
// setPalette不能控制颜色,setFont不能控制大小
// 如果想固定宽度可以指定this，不过我这里还是想要跟随QSplitter的变化所以不设定固定宽度和高度

MonitorLabel::MonitorLabel(QWidget * parent):QLabel(parent)
{
      if (parent!=Q_NULLPTR) this->setFixedWidth(parent->width()/2);
      this->init();
}

MonitorLabel::MonitorLabel(const char * text, QWidget * parent):QLabel(parent)
{
      if (parent!=Q_NULLPTR) this->setFixedWidth(parent->width()/2);
      this->setText(text);
      this->init();
}

MonitorLabel::MonitorLabel(const QString& text,QWidget * parent):QLabel(parent)
{
      if (parent!=Q_NULLPTR) this->setFixedWidth(parent->width()/2);
      this->setText(text);
      this->init();
}

void MonitorLabel::init()
{
     this->setAttribute(Qt::WA_Hover ); // QLabel没有悬停属性,自定义的Label设置这个属性这是为了实现鼠标悬停后文字变大的效果
     this->setAlignment(Qt::AlignCenter);
     this->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
     this->setFrameStyle(QFrame::Sunken | QFrame::Panel);
}

