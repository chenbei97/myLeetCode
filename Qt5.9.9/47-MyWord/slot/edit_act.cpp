#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actUndo_triggered()
{
    if (activateTextWindow()) activateTextWindow()->undo();
}

void MainWindow::on_actRedo_triggered()
{
    if (activateTextWindow()) activateTextWindow()->redo();
}

void MainWindow::on_actCut_triggered()
{
    if (activateTextWindow()) activateTextWindow()->cut();
}

void MainWindow::on_actCopy_triggered()
{
    if (activateTextWindow()) activateTextWindow()->copy();
}

void MainWindow::on_actPaste_triggered()
{
    if (activateTextWindow()) activateTextWindow()->paste();
}
