#include "portConfig.h"
#include "ui_portConfig.h"
#include <QLineEdit>
#include <QDebug>

portConfig::portConfig(QWidget *parent) :
    QDialog(parent),ui(new Ui::portConfig)
{
        ui->setupUi(this);
        this->setWindowTitle("串口配置");

        this->intValidator = new QIntValidator(0, 4000000, this); // 下拉选项还有自定义,自定义时限定用户输入必须是整数
        ui->portBaudRateCombo->setInsertPolicy(QComboBox::NoInsert); // 用户的自定义不能插入到原有的下拉项

        this->initAvailPorts();
        this->initConfigs();
        this->updateConfigs();//这个步骤不可缺少,否则会有未初始化问题
}

portConfig::~portConfig()
{
        delete ui;
}

// 1. 应用配置,点击确定
void portConfig::on_btnConfigSure_clicked()
{
    this->updateConfigs();
    this->hide();
}

// 2. 返回设置的参数
portConfig::Configs portConfig::configs() const
{
    return this->currentConfigs;
}

// 3. 串口下拉项变化时显示对应的信息
void portConfig::on_availPortsComboBox_currentIndexChanged(int index)
{
    this->showPortInfo(index);
}

// 4. 波特率下拉项变化时,因为存在自定义的情况,需要进行一个处理
void portConfig::on_portBaudRateCombo_currentIndexChanged(int index)
{
    if (index+1 == ui->portBaudRateCombo->count()) // 最后1个选项(自定义)
    {
        ui->portBaudRateCombo->setEditable(true); //可编辑,让用户自己输入
        ui->portBaudRateCombo->clearEditText();
        QLineEdit *edit = ui->portBaudRateCombo->lineEdit();// 获取编辑框(QComboBox默认使用的代理是QLineEdit)
        edit->setValidator(intValidator); // 设置约束使之只能输入整数
    }
}
