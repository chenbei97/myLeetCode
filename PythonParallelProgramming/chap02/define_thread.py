'''
Author: chenbei
Date: 2022-09-09 16:49:13
LastEditTime: 2022-09-09 16:55:22
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap02\\define_thread.py
Description: 如何定义线程?
Signature: A boy without dreams
'''
import threading


def func(thread_id):
    print("func函数正在被线程{}调用".format(thread_id))


def main():
    threads = []
    for i in range(10):
        t = threading.Thread(target=func, args=(i+1,))
        threads.append(t)
        t.start()
        t.join()


if __name__ == "__main__":
    main()
