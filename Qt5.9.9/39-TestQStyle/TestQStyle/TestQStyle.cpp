#include "TestQStyle.h"
#include "./ui_TestQStyle.h"
#include <QStyleFactory>

TestQStyle::TestQStyle(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQStyle)
{
      ui->setupUi(this);
      QRegExp regExp(".(.*)\\+?Style");
      QString defaultStyle = QApplication::style()->metaObject()->className();
      ui->statusbar->showMessage("应用程序默认样式名称为："+defaultStyle);
      if (regExp.exactMatch(defaultStyle))
          defaultStyle = regExp.cap(1);
      ui->comboSysStyle->addItems(QStyleFactory::keys());
      ui->comboSysStyle->setCurrentIndex(ui->comboSysStyle->findText(defaultStyle, Qt::MatchContains));
}

TestQStyle::~TestQStyle()
{
  delete ui;
}

// 切换样式
void TestQStyle::on_comboSysStyle_currentIndexChanged(const QString& arg1)
{
    QStyle *style=QStyleFactory::create(arg1);
    qApp->setStyle(style);
    ui->statusbar->showMessage(QString("当前应用样式名称为：")+style->metaObject()->className());
}

// 取消样式表
void TestQStyle::on_btnCancelStyleSheet_clicked()
{
    this->setStyleSheet("");
    // this->styleSheet().clear();//不起作用
}

// 应用样式表
void TestQStyle::on_btnSetStyleSheet_clicked()
{
        this->setStyleSheet("QPlainTextEdit{" //设置QPlainText颜色、字体和悬停状态时的背景色是亮绿色
                        "color: blue; "
                        "font: 13pt '宋体';}"
                        "QPushButton:hover{background-color:lime;}"

                        "QLineEdit{ border: 2px groove red;" // 设置QLineEdit的边框、背景颜色和圆角半径
                        "background-color: rgb(170, 255, 127); "
                        "border-radius: 6px;}"

                        "QCheckBox:checked{color: red;}" // 选中状态时红色

                        "QRadioButton:checked{color:red;}" // 选中状态时红色
                        );
}

// 设置字体大小
void TestQStyle::on_btnFontLarge_clicked()
{
    ui->plainTextEdit->setStyleSheet("font: 13pt '宋体';");
}

void TestQStyle::on_btnFontSmall_clicked()
{
    ui->plainTextEdit->setStyleSheet("font: 10pt '宋体';");
}
