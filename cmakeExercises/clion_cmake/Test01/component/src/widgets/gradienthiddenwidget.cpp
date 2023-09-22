#include "../../inc/widgets/gradienthiddenwidget.h"

GradientHiddenWidget::GradientHiddenWidget(QWidget *parent) : QWidget(parent)
{
    auto effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(1.0);
    setGraphicsEffect(effect);

    animation = new GradientHiddenAnimation(this);
    animation->setPropertyName("opacity");
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(2000);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setTargetObject(effect);

    line = horline();
    header = headerLabel();
    mainlay =  new QVBoxLayout(this);
    mainlay->addWidget(header);
    mainlay->addWidget(line);
}

QFrame* GradientHiddenWidget::horline() const
{
    auto line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Plain);
    return line;
}

Label * GradientHiddenWidget::headerLabel() const
{
    auto label = new Label(tr("创建新流程还是使用已有流程?"));
    auto p = label->palette();
    p.setColor(QPalette::Foreground,"#0FC4F5");
    label->setPalette(p); // 会被全局qss覆盖,得用style才起作用
    label->setStyleSheet("color:#0FC4F5;");
    auto font = label->font();
    font.setBold(true);
    font.setPointSize(18);
    label->setFont(font);
    return label;
}


void GradientHiddenWidget::showEvent(QShowEvent *event)
{
    if (enabled)
        animation->start();
    return QWidget::showEvent(event);
}

void GradientHiddenWidget::enableEffect()
{
    enabled = true;
}

void GradientHiddenWidget::disableEffect()
{
    enabled = false;
}
