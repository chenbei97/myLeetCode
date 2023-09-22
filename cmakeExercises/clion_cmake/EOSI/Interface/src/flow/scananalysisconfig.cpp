#include "../../inc/flow/scananalysisconfig.h"

ScanAnalysisConfig::ScanAnalysisConfig(QWidget *parent) : GradientHiddenWidget(parent)
{
    mAnaType = new ComboBox;
    mAnaDefine = new ComboBox;
    mAnaType->setCurrentIndex(-1);
    mAnaDefine->setCurrentIndex(-1);
    auto str1 = " of Green removed from Red";
    auto str2 = " of Red removed from Green";
    mSpectralFirst = new SpectralUnmixing(str1);
    mSpectralSecond = new SpectralUnmixing(str2);
    mNotes = new QTextEdit;

    QFormLayout * lay = new QFormLayout;
    lay->addRow(tr("分析类型: "),mAnaType);
    lay->addRow(tr("分析定义: "),mAnaDefine);
    lay->addRow(tr("光谱解混: "),mSpectralFirst);
    lay->addRow("",mSpectralSecond);
    lay->addRow(tr("分析笔记: "),mNotes);


    header->setText(tr("已扫描过后的分析步骤设置(可选)"));
    mainlay->addLayout(lay);
}

QString ScanAnalysisConfig::analysisType() const
{
    return mAnaType->currentText();
}

QString ScanAnalysisConfig::analysisDefinition() const
{
    return mAnaDefine->currentText();
}

double ScanAnalysisConfig::spectralUnmixPercentOf1() const
{
    return mSpectralFirst->value();
}

double ScanAnalysisConfig::spectralUnmixPercentOf2() const
{
    return mSpectralSecond->value();
}

QString ScanAnalysisConfig::analysisNotes() const
{
    return mNotes->toPlainText().remove('\''); // 防止转义符导致数据库保存失败
}

SpectralUnmixing::SpectralUnmixing(QWidget *parent):QWidget(parent)
{
    spinbox = new SpinBox;
    spinbox->setRange(0.0,1.0);
    spinbox->setValue(0.0);
    spinbox->setSingleStep(0.01);
    spinbox->setDecimals(2);
    spinbox->setSuffix(" %");
    label = new Label;
    label->setAlignment(Qt::AlignLeft);

    QHBoxLayout * lay = new QHBoxLayout(this);
    lay->addWidget(spinbox);
    lay->addWidget(label);
}

SpectralUnmixing::SpectralUnmixing(const QString &text,QWidget *parent):QWidget(parent)
{
    spinbox = new SpinBox;
    spinbox->setRange(0.0,1.0);
    spinbox->setValue(0.0);
    spinbox->setSingleStep(0.01);
    spinbox->setDecimals(2);
    spinbox->setSuffix(" %");
    label = new Label(text);
    label->setAlignment(Qt::AlignLeft);

    QHBoxLayout * lay = new QHBoxLayout(this);
    lay->addWidget(spinbox);
    lay->addWidget(label);
}

void SpectralUnmixing::setText(const QString &text)
{
    label->setText(text);
}

double SpectralUnmixing::value() const
{
    return spinbox->value();
}
