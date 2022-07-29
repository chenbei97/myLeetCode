#ifndef TESTTWOQWAITCONDITIONBASE_H
#define TESTTWOQWAITCONDITIONBASE_H

#include <QMainWindow>
#include "producerConsumerThread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TestTwoQWaitConditionBase; }
QT_END_NAMESPACE

class TestTwoQWaitConditionBase : public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent * event);
public:
    explicit TestTwoQWaitConditionBase(QWidget *parent = nullptr);
    ~TestTwoQWaitConditionBase();
private slots:
    void on_pushButton_clicked();
    void on_stringConsumed(const QString&text);
    void on_stringProduced(const QString&text);
private:
    Ui::TestTwoQWaitConditionBase *ui;
    Producer producer;
    Consumer consumer;
    int count1 = 0, count2 = 0;
};
#endif // TESTTWOQWAITCONDITIONBASE_H
