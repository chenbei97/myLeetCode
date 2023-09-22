#include "../../inc/flow/scanload.h"

ScanLoad::ScanLoad(QWidget *parent) : QWidget(parent)
{
    config = nullptr;
    btn = new PushButton(tr("启动"));
    QHBoxLayout * lay = new QHBoxLayout(this);
    lay->addStretch();
    lay->addWidget(btn);
    lay->addStretch();
    connect(btn,&PushButton::clicked,this,&ScanLoad::onClicked);
}

void ScanLoad::setStyle(const QString &s)
{
    style = s;
}

void ScanLoad::onClicked()
{
    if (config) {delete config; config = nullptr;}
    config = new ScanVesselConfig;
    config->setStyleSheet(style);
    config->setCurrentUser(cuser);
    config->show();
}

void ScanLoad::setCurrentUser(QCString user)
{ // user是
    cuser = user;
}
