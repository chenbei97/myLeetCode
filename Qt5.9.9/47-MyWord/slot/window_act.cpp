#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actClose_triggered()
{
      ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actCloseAll_triggered()
{
      ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actTile_triggered()
{
     ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actNext_triggered()
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_actPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}
