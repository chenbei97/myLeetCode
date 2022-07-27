#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPen mpen;
protected:
    void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE;
private slots:
    void on_action_Pen_triggered();
};
#endif // MAINWINDOW_H
