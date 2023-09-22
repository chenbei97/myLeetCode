#include "../../inc/flow/scansettingconfig.h"

ScanSettingConfig::ScanSettingConfig(QWidget *parent) : GradientHiddenWidget(parent)
{
    header->setText(tr("通道物镜孔板视野设置"));
    mChannels = new ComboBox;
    mObjectives = new ComboBox;
    mViews = new ComboBox;
    mWells = new ComboBox;
    mPattern = new Pattern;
    mViewCircle = new ViewCircle;

    mChannels->addItems(QStringList()<<"bright"<<"phase"<<"red"<<"green"<<"blue");
    mObjectives->addItems(QStringList()<<"4x"<<"10x"<<"20x"<<"40x");
    mWells->addItems(QStringList()<<"6"<<"24"<<"96"<<"384");
    mPattern->setPatternSize(8,12);
    mPattern->toggleState(Pattern::BlankState);

    QFormLayout * top = new QFormLayout;
    top->addRow("channel: ",mChannels);
    top->addRow("objective: ",mObjectives);
    top->addRow("wellsize: ",mWells);
    top->addRow("view: ",mViews);
    top->setHorizontalSpacing(50);
    top->setVerticalSpacing(110);


    auto toplay = new QHBoxLayout;
    toplay->addLayout(top);
    //toplay->addStretch();
    toplay->addWidget(mPattern);
    toplay->addWidget(mViewCircle);

    mainlay->addLayout(toplay);
    mainlay->addStretch();

#if defined(Q_CC_MSVC)
    connect(mObjectives,QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,&ScanSettingConfig::updateView);
    connect(mWells,QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,&ScanSettingConfig::toggleWellsize);
    connect(mViews,QOverload<const QString&>::of(&QComboBox::currentIndexChanged),
            this,&ScanSettingConfig::toggleView);
#elif defined (Q_CC_MINGW)
    connect(mObjectives,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateView(QString)));
    connect(mWells,SIGNAL(currentIndexChanged(QString)),this,SLOT(toggleWellsize(QString)));
    connect(mViews,SIGNAL(currentIndexChanged(QString)),this,SLOT(toggleView(QString)));
#else

#endif
    mChannels->setCurrentIndex(-1);
    mObjectives->setCurrentIndex(-1);
    mViews->setCurrentIndex(-1);
    mWells->setCurrentIndex(-1); // 让用户必须选,不然直接下一步就没法传递选择的信息
}

QString ScanSettingConfig::channel()
{
    auto c = mChannels->currentText();
    if (c.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("至少选择一个成像模式!"));
    }
    return c;
}

QString ScanSettingConfig::objective()
{
    auto o = mObjectives->currentText();
    if (o.isEmpty()) QMessageBox::warning(this,tr("警告"),tr("至少选择一个物镜倍数!"));
    return o;
}

int ScanSettingConfig::wellsize()
{
    auto w = mWells->currentText().toUInt();
    if (!w) QMessageBox::warning(this,tr("警告"),tr("至少选择一个孔板规格!"));
    return w;
}

int ScanSettingConfig::views()
{
    auto v = mViews->currentText().toUInt();
    if (!v) QMessageBox::warning(this,tr("警告"),tr("至少选择一个每孔视野数!"));
    return v;
}

static QStringList getSquareNumber(int count)
{
    QStringList list;

    for(int i = 1; i <= count; ++i)
        list<<QString::number(i*i);

    return list;
}

void ScanSettingConfig::updateView(int index)
{ // 4x：2.89个视野；10x：18个；20x：72个；40x：293个
    // 4x: 1,2 10x: 1,2,4,9,16 20x:  ...25,36,49,64, 40x: 81,100,121,144,169,196,225,256,289
    mViews->blockSignals(true);
    mViews->clear();

    switch (index) {
        case 0: mViews->addItems(QStringList()<<"1"<<"2"); break;// 2不是平方数
        case 1: mViews->addItems(getSquareNumber(4));break;
        case 2: mViews->addItems(getSquareNumber(8));break;
        case 3: mViews->addItems(getSquareNumber(17));break;
        default:break;
    }

    mViews->setCurrentIndex(-1);
    mViews->blockSignals(false);
}

void ScanSettingConfig::toggleWellsize(int index)
{
    switch (index) {
        case 0: mPattern->setPatternSize(2,3);break;
        case 1: mPattern->setPatternSize(4,6);break;
        case 2: mPattern->setPatternSize(8,12);break;
        case 3: mPattern->setPatternSize(16,24);break;
        default:break;
    }
}

void ScanSettingConfig::toggleView(const QString& views)
{
    // 对于2 特殊处理

    // 其它的都是平方数

    mViewCircle->setView(views.toUInt());
}
