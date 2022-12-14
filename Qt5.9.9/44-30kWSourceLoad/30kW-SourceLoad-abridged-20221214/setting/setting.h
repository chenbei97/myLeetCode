#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QStackedWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <core/enum.h>
#include <table/tableview.h>

class Setting : public QDialog
{
    Q_OBJECT
public:
    explicit Setting(QWidget * parent = Q_NULLPTR);
private:
    void initUI();
    void initConnections();
    QGridLayout * mainLayout;
    QHBoxLayout * topLayout;
    QHBoxLayout * bottomLayout;
    QListWidget * listwidget;
    QStackedWidget * stackwidget;
    QPushButton * okBtn;
    QPushButton * cancelBtn;
    TableView * mTableView;
signals:
    void workModeChanged(WORKMODE);
    void selectedPeriod(quint32 ms, quint32 s = 0,quint32 m = 0, quint32 h = 0);
    void log(const QList<QByteArray>&);
};

#endif // SETTING_H
