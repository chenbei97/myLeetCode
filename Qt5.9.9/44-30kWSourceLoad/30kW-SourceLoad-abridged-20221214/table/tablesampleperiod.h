#ifndef TABLESAMPLEPERIOD_H
#define TABLESAMPLEPERIOD_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

class TableSamplePeriod : public QDialog
{
    Q_OBJECT
public:
    explicit TableSamplePeriod(QWidget * parent = Q_NULLPTR);
    struct Period {
        quint32 ms = 0;
        quint32 s = 0;
        quint32 m = 0;
        quint32 h = 0;
    } mPeriod;
private:
    QVBoxLayout * mainLayout;
    QComboBox * mPeriodList;
    QPushButton * mOkBtn;
    QPushButton * mCancelBtn;
    QString showSelectUnit();//自定义周期选择单位的对话框
    QString checkCustomItem(QString);
    void emitPeriod(QString);
signals:
    void selectedPeriod(quint32 ms, quint32 s = 0,quint32 m = 0, quint32 h = 0);
};

#endif // TABLESAMPLEPERIOD_H
