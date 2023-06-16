#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
       QPushButton * btn;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onUsernameChanged(QString name);
    void onPasswordChanged(QString name);
};
#endif // MAINWINDOW_H
