#include "TestStandardDialog.h"
#include "ui_TestStandardDialog.h"
#include <QDir>
#include <QColorDialog>
#include <QFontDialog>

// 1. 颜色对话框
void TestStandardDialog::on_btnColor_clicked()
{
    QPalette pal=ui->plainTextEdit->palette(); //获取现有 palette
    QColor  iniColor=pal.color(QPalette::Text); //现有的文字颜色

    // 以现有的颜色打开颜色对话框
    QColor color=QColorDialog::getColor(iniColor,this,"选择颜色");
    if (color.isValid()) //选择有效
    {
        pal.setColor(QPalette::Text,color); //palette 设置选择的颜色
        ui->plainTextEdit->setPalette(pal); //设置 palette
    }
    else
     ui->plainTextEdit->appendPlainText("设置颜色失败!");
}

// 2.字体对话框
void TestStandardDialog::on_btnFont_clicked()
{
      QFont iniFont=ui->plainTextEdit->font(); //获取文本框的字体
      bool   ok = false;
      QFont font=QFontDialog::getFont(&ok,iniFont); //选择字体
      if (ok) //选择有效
          ui->plainTextEdit->setFont(font);
      else
           ui->plainTextEdit->appendPlainText("设置字体失败!");
}
