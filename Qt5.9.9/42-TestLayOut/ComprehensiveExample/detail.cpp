#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
    ,NationLabel(new QLabel("国家/地址："))
    ,NationCombo(new QComboBox)
    ,ProvinceLabel(new QLabel("省份："))
    ,ProvinceCombo(new QComboBox)
    ,CityLabel(new QLabel("城市："))
    ,CityEdit(new QLineEdit)
    ,IntroLabel(new QLabel("个人说明："))
    ,IntroEdit(new QTextEdit)
    ,mainLayout(new QGridLayout(this))
{
      NationCombo->addItems(QStringList{"中国","美国","俄罗斯","法国","英国"});
      ProvinceCombo->addItems(QStringList{"北京","上海","广州","深圳"});
      CityEdit->setText("海淀区");
      mainLayout->setMargin(5);
      mainLayout->setSpacing(10);
      mainLayout->addWidget(NationLabel,0,0);mainLayout->addWidget(NationCombo,0,1);
      mainLayout->addWidget(ProvinceLabel,1,0);mainLayout->addWidget(ProvinceCombo,1,1);
      mainLayout->addWidget(CityLabel,2,0);mainLayout->addWidget(CityEdit,2,1);
      mainLayout->addWidget(IntroLabel,3,0);mainLayout->addWidget(IntroEdit,3,1);
      mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
}
