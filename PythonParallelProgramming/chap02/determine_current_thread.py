'''
Author: chenbei
Date: 2022-09-09 16:54:25
LastEditTime: 2022-09-09 17:03:30
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap02\\determine_current_thread.py
Description: 如何确定当前线程?
Signature: A boy without dreams
'''
import threading
import time


def funcA():
    print(f'当前线程{threading.current_thread().name} ---> 正在启动\n')
    time.sleep(2)
    print(f'当前线程{threading.current_thread().name} ---> 正在结束\n')


def funcB():
    print(f'当前线程{threading.current_thread().name} ---> 正在启动\n')
    time.sleep(2)
    print(f'当前线程{threading.current_thread().name} ---> 正在结束\n')


def funcC():
    print(f'当前线程{threading.current_thread().name} ---> 正在启动\n')
    time.sleep(2)
    print(f'当前线程{threading.current_thread().name} ---> 正在结束\n')


def main():
    t1 = threading.Thread(name="FuncA", target=funcA)
    t2 = threading.Thread(name="FuncB", target=funcB)
    t3 = threading.Thread(name="FuncC", target=funcC)

    t1.start()
    t2.start()
    t3.start()

    t1.join()
    t2.join()
    t3.join()


if __name__ == "__main__":
    main()
'''
某2次运行结果,不一定A先启动,也不一定C最后结束
当前线程FuncA ---> 正在启动
当前线程FuncC ---> 正在启动
当前线程FuncB ---> 正在启动
当前线程FuncA ---> 正在结束
当前线程FuncC ---> 正在结束
当前线程FuncB ---> 正在结束
-------------------------
当前线程FuncA ---> 正在启动
当前线程FuncB ---> 正在启动
当前线程FuncC ---> 正在启动
当前线程FuncA ---> 正在结束
当前线程FuncC ---> 正在结束
当前线程FuncB ---> 正在结束
'''
