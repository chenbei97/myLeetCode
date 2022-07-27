#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controllworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_handleResult(const QString & result);
private:
    Ui::MainWindow *ui;
    controllWorker * cWorker;
};
#endif // MAINWINDOW_H
