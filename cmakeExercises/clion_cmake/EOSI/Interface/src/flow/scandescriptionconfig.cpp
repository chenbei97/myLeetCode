#include "../../inc/flow/scandescriptionconfig.h"

ScanDescriptionConfig::ScanDescriptionConfig(QWidget *parent) : GradientHiddenWidget(parent)
{
    mExperName = new LineEdit;
    mExperPerson = new LineEdit;
    mCellType = new LineEdit;

    mExperName->setToolTip(tr("*表示必填项"));
    mExperPerson->setToolTip(tr("*表示必填项"));

    auto flay = new QFormLayout;
    flay->addRow(tr("   实验日期"),new QLabel(QDate::currentDate().toString("yyyy/MM/dd")));
    flay->addRow(tr("* 实验名称: "),mExperName);
    flay->addRow(tr("* 实验人员: "),mExperPerson);
    flay->addRow(tr("   细胞类型: "),mCellType);

    mDescription = new QTextEdit;
    auto boxlay = new QHBoxLayout;
    boxlay->addWidget(mDescription);
    auto box = new QGroupBox(tr("其他实验信息描述"));
    box->setLayout(boxlay);

    header->setText(tr("设置实验信息"));
    mainlay->addLayout(flay);
    mainlay->addWidget(box);
}

QString ScanDescriptionConfig::experName()
{
    auto n = mExperName->text().simplified();
    if (n.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("实验名称为必填项!"));
        return "";
    }
    return n.remove('\''); // 防止转义符导致数据库保存失败
}

QString ScanDescriptionConfig::personName()
{
    auto n = mExperPerson->text().simplified();
    if (n.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("实验人员为必填项!"));
        return "";
    }
    return n.remove('\''); // 防止转义符导致数据库保存失败
}

QString ScanDescriptionConfig::cellType() const
{
    auto n = mCellType->text().simplified().remove('\''); // 防止转义符导致数据库保存失败
    return n;
}

QString ScanDescriptionConfig::description() const
{
    return mDescription->toPlainText().remove('\''); // 防止转义符导致数据库保存失败
}
