#include "TestStandardDialog.h"
#include "ui_TestStandardDialog.h"

TestStandardDialog::TestStandardDialog(QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::TestStandardDialog)
{
  ui->setupUi(this);
}

TestStandardDialog::~TestStandardDialog()
{
  delete ui;
}

void TestStandardDialog::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}
