#include "TestStandardDialog.h"
#include "ui_TestStandardDialog.h"
#include <QMessageBox>

// 1.Question消息框
void TestStandardDialog::on_btnMsgQuestion_clicked()
{
    QString dlgTitle="Question消息框";
    QString strInfo="文件已被修改，是否保存修改?";

    QMessageBox::StandardButton  defaultBtn=QMessageBox::NoButton; //缺省按钮

    QMessageBox::StandardButton result;//返回选择的按钮
    result=QMessageBox::question(this, dlgTitle, strInfo,
                      QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,
                      defaultBtn);

    if (result==QMessageBox::Yes)
        ui->plainTextEdit->appendPlainText("Question消息框: Yes 被选择");
    else if(result==QMessageBox::No)
        ui->plainTextEdit->appendPlainText("Question消息框: No 被选择");
    else if(result==QMessageBox::Cancel)
        ui->plainTextEdit->appendPlainText("Question消息框: Cancel 被选择");
    else
        ui->plainTextEdit->appendPlainText("Question消息框: 无选择");
}

// 2. information消息框
void TestStandardDialog::on_btnMsgInformation_clicked()
{
    QString dlgTitle="information消息框";
    QString strInfo="文件已经打开，字体大小已设置";

    // QMessageBox::information(this, dlgTitle, strInfo);//使用缺省的按钮
   QMessageBox::information(this, dlgTitle, strInfo,
                              QMessageBox::Ok,QMessageBox::NoButton);
}

// 3. warning 消息框
void TestStandardDialog::on_btnMsgWarning_clicked()
{
    QString dlgTitle="warning 消息框";
    QString strInfo="文件内容已经被修改";

    QMessageBox::warning(this, dlgTitle, strInfo);
}

// 4. critical消息框
void TestStandardDialog::on_btnMsgCritical_clicked()
{
    QString dlgTitle="critical消息框";
    QString strInfo="有不明程序访问网络";
    QMessageBox::critical(this, dlgTitle, strInfo);
}

// 5. about消息框
void TestStandardDialog::on_btnMsgAbout_clicked()
{
    QString dlgTitle="about消息框";
    QString strInfo="我开发的数据查看软件 V1.0 \n 保留所有版权";

    QMessageBox::about(this, dlgTitle, strInfo);
}

// 6. aboutQt消息框
void TestStandardDialog::on_btnMsgAboutQt_clicked()
{
    QString dlgTitle="aboutQt消息框";
    QMessageBox::aboutQt(this, dlgTitle);
}
