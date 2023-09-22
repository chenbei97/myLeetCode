#include "../../inc/flow/scanexperimentconfig.h"

ScanExperimentConfig::ScanExperimentConfig(QWidget *parent) :GradientHiddenWidget(parent)
{

    mProliferation = new Button(tr("细胞增殖"));
    mScratch = new Button(tr("划痕"));
    mOrganoid = new Button(tr("类器官"));
    mPC  = new Button(tr("药效和细胞毒性"));
    mInvasion = new Button(tr("侵袭"));
    mMorphology = new Button(tr("形态学"));
    mTransfection = new Button(tr("转染"));

    mProliferation->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mScratch->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mOrganoid->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mPC->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mInvasion->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mMorphology->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);
    mTransfection->setMinimumSize(NewExperPushButtonMinWidth,NewExperButtonMinHeight);

    mProliferation->setStyleSheet(MainNewExper_ButtonStyle);
    mScratch->setStyleSheet(MainNewExper_ButtonStyle);
    mOrganoid->setStyleSheet(MainNewExper_ButtonStyle);
    mPC->setStyleSheet(MainNewExper_ButtonStyle);
    mInvasion->setStyleSheet(MainNewExper_ButtonStyle);
    mMorphology->setStyleSheet(MainNewExper_ButtonStyle);
    mTransfection->setStyleSheet(MainNewExper_ButtonStyle);

    auto mLay = new QGridLayout;
    mLay->addWidget(mProliferation,0,0,Qt::AlignCenter);
    mLay->addWidget(mScratch,0,1,Qt::AlignCenter);
    mLay->addWidget(mOrganoid,0,2,Qt::AlignCenter);
    mLay->addWidget(mPC,1,0,Qt::AlignCenter);
    mLay->addWidget(mInvasion,1,1,Qt::AlignCenter);
    mLay->addWidget(mMorphology,1,2,Qt::AlignCenter);
    mLay->addWidget(mTransfection,2,0,Qt::AlignCenter);

    mCurrentExper = new Label(tr("当前配置的实验类型: %1").arg(""));
    auto blay = new QHBoxLayout;
    blay->addWidget(mCurrentExper);
    blay->addStretch();

    header->setText(tr("实验类型选择"));
    mainlay->addStretch();
    mainlay->addSpacing(20);
    mainlay->addLayout(mLay);
    mainlay->addStretch();
    mainlay->addSpacing(10);
    mainlay->addLayout(blay);
    mainlay->addStretch();

    connect(mProliferation,&Button::clicked,this,&ScanExperimentConfig::onProliferation);
    connect(mScratch,&Button::clicked,this,&ScanExperimentConfig::onScratch);
    connect(mOrganoid,&Button::clicked,this,&ScanExperimentConfig::onOrganoid);
    connect(mPC,&Button::clicked,this,&ScanExperimentConfig::onPC);
    connect(mInvasion,&Button::clicked,this,&ScanExperimentConfig::onInvasion);
    connect(mMorphology,&Button::clicked,this,&ScanExperimentConfig::onMorphology);
    connect(mTransfection,&Button::clicked,this,&ScanExperimentConfig::onTransfection);
}

void ScanExperimentConfig::onProliferation()
{
    type = "proliferation";
    mCurrentExper->setText(tr("当前配置的实验类型: 细胞增殖"));
}

void ScanExperimentConfig::onScratch()
{
    type = "scratch";
    mCurrentExper->setText(tr("当前配置的实验类型: 划痕"));
}

void ScanExperimentConfig::onOrganoid()
{
    type = "organoid";
    mCurrentExper->setText(tr("当前配置的实验类型: 类器官"));
}

void ScanExperimentConfig::onPC()
{
    type = "pharmacodynamics and cytotoxicity";
    mCurrentExper->setText(tr("当前配置的实验类型: 药效和细胞毒性"));
}

void ScanExperimentConfig::onInvasion()
{
    type = "invasion";
    mCurrentExper->setText(tr("当前配置的实验类型: 侵袭"));
}

void ScanExperimentConfig::onMorphology()
{
    type = "morphology";
    mCurrentExper->setText(tr("当前配置的实验类型: 形态学"));
}

void ScanExperimentConfig::onTransfection()
{
    type = "transfection";
    mCurrentExper->setText(tr("当前配置的实验类型: 转染"));
}

QString ScanExperimentConfig::experimentType()
{
    if(type.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("必须配置且只能配置一个实验!"));
    };
    return type;
}
