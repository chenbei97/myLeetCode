'''
Author: chenbei
Date: 2022-09-14 09:07:50
LastEditTime: 2022-09-14 09:35:53
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap02\\define_thread_subclass.py
Description: 演示如何定义线程子类,关键是重载__init__和run方法
Signature: A boy without dreams
'''
import time
import os
from threading import Thread
from random import randint


class MyThread(Thread):
    def __init__(self, name: str, duration: int) -> None:
        Thread.__init__(self)  # 用父类初始化继承来的参数
        self.name = name
        self.duration = duration

    def run(self):
        print(f"name : {self.name} duration : {self.duration}")
        print("current run() belong to process ID"+str(os.getpid()))
        time.sleep(self.duration)
        print("\n")


def main():
    now = time.time()

    ts = []
    for i in range(10):
        ts.append(MyThread(f"Thread{i+1}", randint(1, 10)))
    for t in ts:
        t.start()
    for t in ts:
        t.join()

    print("cost time = ", time.time()-now)


if __name__ == "__main__":
    main()
    # 这里的结果时所有线程都会同时执行,相互竞争
    # 如果想要顺序打印第一种方法是在t.start()后紧跟着t.join()
    # 或者使用锁、信号量等同步机制，一个线程拿到锁后执行完才能让其它线程拿到执行，其它线程在没获得锁时只能阻塞等待
