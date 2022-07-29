#ifndef TESTTWOQSEMAPHOREBASE_H
#define TESTTWOQSEMAPHOREBASE_H

#include <QMainWindow>
#include "producerConsumerThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestTwoQSemaphoreBase; }
QT_END_NAMESPACE

class TestTwoQSemaphoreBase : public QMainWindow
{
    Q_OBJECT
public:
    TestTwoQSemaphoreBase(QWidget *parent = nullptr);
    ~TestTwoQSemaphoreBase();
private slots:
    void on_pushButton_clicked();
    void on_stringConsumed(const QString&text);
    void on_stringProduced(const QString&text);
private:
    Ui::TestTwoQSemaphoreBase *ui;
    Producer producer;
    Consumer consumer;
    int count1 = 0, count2 = 0;
};
#endif // TESTTWOQSEMAPHOREBASE_H
