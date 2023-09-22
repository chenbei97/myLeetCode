#include "../../inc/flow/scancreateconfig.h"

ScanCreateConfig::ScanCreateConfig(QWidget *parent) :GradientHiddenWidget(parent)
{
    disableEffect();
    header->setText(tr("创建新流程还是使用已有流程?"));
    btnNew = createNewButton();
    btnCurrent = copyCurrentButton();
    btnPrevious = copyPreviousButton();

    auto lay1 = new QHBoxLayout;
    lay1->addWidget(btnNew);
    lay1->addStretch();
    auto lay2 = new QHBoxLayout;
    lay2->addWidget(btnCurrent);
    lay2->addStretch();
    auto lay3 = new QHBoxLayout;
    lay3->addWidget(btnPrevious);
    lay3->addStretch();

    mainlay->addLayout(lay1);
    mainlay->addSpacing(ScanCreateConfigSpacing);
    mainlay->addLayout(lay2);
    mainlay->addSpacing(ScanCreateConfigSpacing);
    mainlay->addLayout(lay3);
    mainlay->addSpacing(ScanCreateConfigSpacing);

    connect(btnNew,&QRadioButton::clicked,this,&ScanCreateConfig::onCreateConfig);
    connect(btnCurrent,&QRadioButton::clicked,this,&ScanCreateConfig::onCreateConfig);
    connect(btnPrevious,&QRadioButton::clicked,this,&ScanCreateConfig::onCreateConfig);
}

void ScanCreateConfig::onCreateConfig()
{
    auto w = qobject_cast<QRadioButton*>(sender());
    if (w->objectName() == "create") {
        emit createMode(New);
    } else if (w->objectName() == "current"){
        emit createMode(Current);
    } else {
        emit createMode(Previous);
    }
}

void ScanCreateConfig::clearRadioState()
{// 先取消独占,设置checked才能都取消,然后再恢复即可
    btnNew->setAutoExclusive(false);
    btnCurrent->setAutoExclusive(false);
    btnPrevious->setAutoExclusive(false);
    btnNew->setChecked(false);
    btnCurrent->setChecked(false);
    btnPrevious->setChecked(false);
    btnNew->setAutoExclusive(true);
    btnCurrent->setAutoExclusive(true);
    btnPrevious->setAutoExclusive(true);
}

QRadioButton * ScanCreateConfig::createNewButton() const
{
    auto btn = new QRadioButton(tr("创建全新实验流程"));
    btn->setObjectName("create");
    return btn;
}

QRadioButton * ScanCreateConfig::copyCurrentButton()  const
{
    auto btn = new QRadioButton(tr("复制当前实验流程"));
    btn->setObjectName("current");
    return btn;
}

QRadioButton * ScanCreateConfig::copyPreviousButton() const
{
    auto btn = new QRadioButton(tr("复制历史实验流程"));
    btn->setObjectName("previous");
    return btn;
}


