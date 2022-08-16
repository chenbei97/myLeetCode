#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QComboBox>

class MainWindow : public QDialog
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private:
  QStackedWidget * stack;
  QListWidget * listwidget;
  QComboBox * combo;
  QLabel * label1;
  QLabel * label2;
  QLabel * label3;
};
#endif // MAINWINDOW_H
