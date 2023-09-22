#ifndef DIALOG_H
#define DIALOG_H

#include "qmessagebox.h"

//https://cloud.tencent.com/developer/ask/sof/427509
static QMessageBox* getWaitDialog(QWidget*parent = nullptr)
{
    QMessageBox * dlg = new QMessageBox(parent);
    dlg->setText("请稍等,正在处理...");
    dlg->setWindowModality(Qt::WindowModal);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setStandardButtons(QMessageBox::NoButton);
    dlg->setFixedSize(400,300);
    return dlg;
}
#endif // DIALOG_H
