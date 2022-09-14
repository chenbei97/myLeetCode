'''
Author: chenbei
Date: 2022-09-14 09:25:18
LastEditTime: 2022-09-14 09:36:47
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap02\\thread_sync_bylock.py
Description: 使用锁的线程同步,acquire获得锁,release释放锁
Signature: A boy without dreams
'''
# acquire方法接受可选参数,如果没有指定或设置为True.则线程阻塞
# 直到其他线程释放锁为止,然后获得锁
# 如果设置为False,则返回一个bool结果,如果已经得到锁则返回True否则False,不会阻塞

import threading
import os
from threading import Thread
from random import randint
import time

threadLock = threading.Lock()  # 全局锁


class MyThread(Thread):
    def __init__(self, name: str, duration: int):
        Thread.__init__(self)
        self.name = name
        self.duration = duration

    def run(self):
        threadLock.acquire()  # 获取锁 以下保护代码
        print(f"name : {self.name} duration : {self.duration}")
        print("current run() belong to process ID"+str(os.getpid()))
        time.sleep(self.duration)
        print("\n")
        threadLock.release()  # 释放锁


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
    # 结果是顺序执行的，使用锁确保任何时候只有1个线程拿到锁执行任务
    # 其它线程没拿到锁之前必须等待
