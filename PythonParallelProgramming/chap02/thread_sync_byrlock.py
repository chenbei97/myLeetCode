'''
Author: chenbei
Date: 2022-09-14 09:53:45
LastEditTime: 2022-09-14 10:05:23
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap02\\thread_sync_byrlock.py
Description: 使用递归锁的线程同步,递归锁可以被同一线程获取多次,但是也只能同一线程释放多次才能被其他线程使用
Signature: A boy without dreams
'''
# rlock和lock的区别是lock释放之前只能获取1次,而rlock可以同一线程获得多次,而且必须释放同样的次数才能释放rlock
# 另一个区别是lock可以由任意的线程释放,但rlock如果被某个线程锁定就必须被同一线程释放相同的次数

import time
import threading
import random


class Box:
    def __init__(self) -> None:
        self.lock = threading.RLock()
        self.total = 0

    def execute(self, value: int):
        with self.lock:
            self.total += value

    def add(self):
        with self.lock:
            self.execute(1)

    def remove(self):
        with self.lock:
            self.execute(-1)


def adder(box: Box, num: int):
    print(f"共{num}个项要被添加\n")
    while num:
        box.add()
        time.sleep(1)
        num -= 1
        print(f"已添加1个项=>还有{num}个项等待添加")


def remover(box: Box, num: int):
    print(f"共{num}个项要被移除\n")
    while num:
        box.remove()
        time.sleep(1)
        num -= 1
        print(f"已移除1个项=>还有{num}个项等待移除")


def main():
    num = 10
    box = Box()

    t1 = threading.Thread(target=adder, args=(box, random.randint(10, 20)))
    t2 = threading.Thread(target=remover, args=(box, random.randint(1, 10)))

    t1.start()
    t2.start()

    t1.join()
    t2.join()


if __name__ == "__main__":
    main()
