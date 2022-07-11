#include "testDelegate.h"
#include "ui_testdelegate.h"

TestDelegate::TestDelegate(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestDelegate)
{
  ui->setupUi(this);
  this->initilize();
}

TestDelegate::~TestDelegate()
{
    if (!this->ui) delete this->ui;
    if (!this->LabCellPos) delete  this->LabCellPos;
    if(!this->LabCurFile) delete  this->LabCurFile;
    if (!this->LabCellText) delete  this->LabCellText;
    if (!this->theModel) delete  this->theModel;
    if (!this->theSelection) delete  this->theSelection;
}

