#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setFileMenuActEnabled(bool enabled)
{
      // 文件菜单有7个动作,退出、新建和打开不涉及(总是可用)
       ui->actSave->setEnabled(enabled);
       ui->actSaveAs->setEnabled(enabled);
       ui->actPrint->setEnabled(enabled);
       ui->actPrintPreview->setEnabled(enabled);
}

void MainWindow::setFormatMenuActEnabled(bool enabled)
{
      // 格式菜单有8个动作,全部涉及
      ui->actBold->setEnabled(enabled);
      ui->actItalic->setEnabled(enabled);
      ui->actUnderline->setEnabled(enabled);
      ui->actLeft->setEnabled(enabled);
      ui->actCenter->setEnabled(enabled);
      ui->actRight->setEnabled(enabled);
      ui->actJusitify->setEnabled(enabled);
      ui->actColor->setEnabled(enabled);
}

void MainWindow::setWindowMenuActEnabled(bool enabled)
{
      // 窗口菜单有6个动作,全部涉及
       ui->actClose->setEnabled(enabled);
       ui->actCloseAll->setEnabled(enabled);
       ui->actTile->setEnabled(enabled);
       ui->actCascade->setEnabled(enabled);
       ui->actNext->setEnabled(enabled);
       ui->actPrevious->setEnabled(enabled);
}

