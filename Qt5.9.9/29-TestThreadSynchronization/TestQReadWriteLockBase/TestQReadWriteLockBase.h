#ifndef TESTQREADWRITELOCKBASE_H
#define TESTQREADWRITELOCKBASE_H

#include <QMainWindow>
#include "writeThread.h"
#include "readThread.h"
#include "saveThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestQReadWriteLockBase; }
QT_END_NAMESPACE

class TestQReadWriteLockBase : public QMainWindow
{
    Q_OBJECT

public:
    TestQReadWriteLockBase(QWidget *parent = nullptr);
    ~TestQReadWriteLockBase();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void onReadValue(int ret);
    void onSaveValue(int ret);
    void on_pushButton_7_clicked();

private:
    writeThread * wThread;
    readThread  * rThread;
    saveThread * sThread;
private:
    Ui::TestQReadWriteLockBase *ui;
    int count1 = 0, count2 = 0;
};
#endif // TESTQREADWRITELOCKBASE_H
