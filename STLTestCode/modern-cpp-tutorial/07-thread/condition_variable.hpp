/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 10:30:49
 * @LastEditTime: 2022-05-23 10:49:44
 * @Description: condition_variable.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\07-thread\condition_variable.hpp
 * @Signature: A boy without dreams
 */
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>
#include <iostream>
using namespace std;
// 条件变量 std::condition_variable 是为了解决死锁而生，当互斥操作不够用而引入的
// 比如，线程可能需要等待某个条件为真才能继续执行
// 而一个忙等待循环中可能会导致所有其他线程都无法进入临界区使得条件为真时，就会发生死锁
// 所以，condition_variable 实例被创建出现主要就是用于唤醒等待线程从而避免死锁
// std::condition_variable的 notify_one() 用于唤醒一个线程
// notify_all() 则是通知所有线程。
// 生产者中我们虽然可以使用 notify_one()，但实际上并不建议在此处使用
// 因为在多消费者的情况下，我们的消费者实现中简单放弃了锁的持有
// 这使得可能让其他消费者争夺此锁，从而更好的利用多个消费者之间的并发
// 下面是一个生产者和消费者模型的例子：
void producer_consumer_(){
    // 创建一个队列
    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    bool notified = false;  // 通知信号

    // 生产者
    auto producer = [&]() {
        for (int i = 0; ; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all(); // 此处也可以使用 notify_one
        }
    };
    // 消费者
    auto consumer = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified) {  // 避免虚假唤醒
                cv.wait(lock);
            }
            // 短暂取消锁，使得生产者有机会在消费者消费空前继续生产
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 消费者慢于生产者
            lock.lock();
            while (!produced_nums.empty()) {
                std::cout << "consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
            notified = false;
        }
    };

    // 分别在不同的线程中运行
    std::thread p(producer);
    std::thread cs[2];
    for (int i = 0; i < 2; ++i) {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < 2; ++i) {
        cs[i].join();
    }
}

void test_condition_variable(){
    producer_consumer_();
}