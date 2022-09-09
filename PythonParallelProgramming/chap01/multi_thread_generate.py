'''
Author: chenbei
Date: 2022-09-09 14:49:53
LastEditTime: 2022-09-09 15:10:41
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap01\\multi_thread_generate.py
Description: 演示多线程花费的时间
Signature: A boy without dreams
'''
import threading
from time import time
from generate_random_numbers import *

start_t = time()
count = 10000000
n_thread = 10  # 10个线程,每个线程执行1个任务
thread_containter = []  # 方便管理线程的容器

for i in range(n_thread):
    out_list = list()  # 输出的列表
    thread = threading.Thread(target=generate_random_number(
        count, out_list))  # 指定线程要执行的函数来创建新线程
    thread_containter.append(thread)  # 管理线程
for thread in thread_containter:
    thread.start()  # 启动线程
for thread in thread_containter:
    thread.join()  # 加入子线程

print("花费的总时间为 %.3f s" % (time()-start_t))

# 花费的总时间为 10.172 s, 可以看出来相比串行没快多少
# 这是因为线程是一个一个执行的，存在优先级，直到最后1个线程
