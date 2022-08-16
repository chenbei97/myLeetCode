#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
    ,EmailLabel(new QLabel("邮箱："))
    ,EmailEdit(new QLineEdit("chenbei_electric@163.com"))
    ,AddrLabel(new QLabel("地址："))
    ,AddrEdit(new QLineEdit("北京市顺义区"))
    ,CodeLabel(new QLabel("邮编："))
    ,CodeEdit(new QLineEdit("101300"))
    ,PhoneLabel(new QLabel("手机："))
    ,PhoneEdit(new QLineEdit("19801279791"))
    ,AcceptInfoCheckBox(new QCheckBox("接收留言"))
    ,LandTelLabel(new QLabel("座机："))
    ,LandTelEdit(new QLineEdit("123456789"))
    ,mainLayout(new QGridLayout(this))
{
      AcceptInfoCheckBox->setCheckState(Qt::CheckState::Checked); //默认Checked状态
      mainLayout->setMargin(5);
      mainLayout->setSpacing(10);
      mainLayout->addWidget(EmailLabel,0,0);mainLayout->addWidget(EmailEdit,0,1);
      mainLayout->addWidget(AddrLabel,1,0);mainLayout->addWidget(AddrEdit,1,1);
      mainLayout->addWidget(CodeLabel,2,0);mainLayout->addWidget(CodeEdit,2,1);
      mainLayout->addWidget(PhoneLabel,3,0);mainLayout->addWidget(PhoneEdit,3,1);
      mainLayout->addWidget(LandTelLabel,4,0);mainLayout->addWidget(LandTelEdit,4,1);
      mainLayout->addWidget(AcceptInfoCheckBox,5,2);
      mainLayout->setColumnStretch(0,3);
      mainLayout->setColumnStretch(1,5);
      mainLayout->setColumnStretch(2,2);
      mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
}
