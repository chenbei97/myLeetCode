#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actBold_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->actBold->isChecked() ? QFont::Bold : QFont::Normal);
    if(activateTextWindow()) activateTextWindow()->setDocFormat(fmt);
}

void MainWindow::on_actItalic_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->actItalic->isChecked());
    if(activateTextWindow()) activateTextWindow()->setDocFormat(fmt);
}

void MainWindow::on_actUnderline_triggered()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->actUnderline->isChecked());
    if(activateTextWindow()) activateTextWindow()->setDocFormat(fmt);
}

void MainWindow::on_actLeft_triggered()
{
      if(activateTextWindow())
          activateTextWindow()->setDocAlignment(1);
}

void MainWindow::on_actCenter_triggered()
{
      if(activateTextWindow())
          activateTextWindow()->setDocAlignment(2);
}

void MainWindow::on_actRight_triggered()
{
      if(activateTextWindow())
          activateTextWindow()->setDocAlignment(3);
}

void MainWindow::on_actJusitify_triggered()
{
      if(activateTextWindow())
          activateTextWindow()->setDocAlignment(4);
}

void MainWindow::on_actColor_triggered()
{
    if (activateTextWindow())
    {
        QColor color = QColorDialog::getColor(activateTextWindow()->textColor(), this);
        if (!color.isValid()) return;
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activateTextWindow()->setDocFormat(fmt);
        QPixmap pix(16, 16);
        pix.fill(color);
        ui->actColor->setIcon(pix);
    }
}
