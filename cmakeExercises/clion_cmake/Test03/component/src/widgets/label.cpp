//
// Created by chenbei on 2023/9/20.
//

#include "../../inc/label.h"

Label::Label(QWidget*parent):QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
    mPressEvent = false;
    mEffectSwitch = false;
    mAnimation = nullptr;
    mEffect = nullptr;
}

Label::Label(const QString&text,QWidget*parent) :QLabel(parent)
{
    setText(text);
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
    mPressEvent = false;
    mEffectSwitch = false;
    mAnimation = nullptr;
    mEffect = nullptr;
}

void Label::mousePressEvent(QMouseEvent *e)
{
    if (mPressEvent)
    {
        int ret = QMessageBox::warning(this,tr("警告"),mWarningInfo,QMessageBox::Ok|QMessageBox::Cancel);
        if (ret == QMessageBox::Ok) {
            auto opendir = text().isEmpty()?QDir::homePath():text().remove(tr("目录: "));
            QString dir =  QFileDialog::getExistingDirectory(this,tr("选择保存目录"),opendir,
                                                             QFileDialog::ShowDirsOnly|QFileDialog::DontUseNativeDialog
                                                             |QFileDialog::DontResolveSymlinks);
            if (!dir.isEmpty())
                setText(tr("目录: %1").arg(dir));
        }
    }
    QLabel::mousePressEvent(e);
}

void Label::setWaringInfo(const QString&info)
{
    mWarningInfo = info;
}

QString Label::warningInfo() const
{
    return mWarningInfo;
}

void Label::enablePressEvent()
{
    mPressEvent = true;
}

void Label::disablePressEvent()
{
    mPressEvent = false;
}

void Label::enableEffect()
{
    mEffectSwitch = true;

    mEffect = new QGraphicsOpacityEffect(this); // 延迟创建
    mEffect->setOpacity(1.0);
    setGraphicsEffect(mEffect);

    mAnimation = new QPropertyAnimation(mEffect,"opacity",this);
    mAnimation->setEasingCurve(QEasingCurve::Linear);
    mAnimation->setDuration(AnimationDuration_1000ms);

    mAnimation->setStartValue(0.0);
    mAnimation->setEndValue(1.0);
}

void Label::disableEffect()
{
    mEffectSwitch = false;
}

void Label::showEvent(QShowEvent*e)
{
    if (mEffectSwitch) {
        mAnimation->start(QAbstractAnimation::KeepWhenStopped);
    }
    QLabel::showEvent(e);
}

Label::~Label()
{
    delete mAnimation;
    delete mEffect;
}
