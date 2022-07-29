#ifndef TESTONEQSEMAPHOREBASE_H
#define TESTONEQSEMAPHOREBASE_H

#include <QMainWindow>
#include "producerConsumerThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestOneQSemaphoreBase; }
QT_END_NAMESPACE

class TestOneQSemaphoreBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestOneQSemaphoreBase(QWidget *parent = nullptr);
    ~TestOneQSemaphoreBase();
private:
        Producer producer;
        Consumer consumer;
protected:
    void    closeEvent(QCloseEvent *event);
private slots:
    void on_btnStartThread_clicked();
    void on_btnStopThread_clicked();
    void on_btnClear_clicked();
    void on_producer_started();
    void on_producer_finished();
    void on_consumer_started();
    void on_consumer_finished();
    void on_consumer_newValue(int *data,int count, int bufId);
private:
    Ui::TestOneQSemaphoreBase *ui;
};
#endif // TESTONEQSEMAPHOREBASE_H
