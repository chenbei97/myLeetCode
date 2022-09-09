'''
Author: chenbei
Date: 2022-09-09 14:58:02
LastEditTime: 2022-09-09 15:21:39
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap01\\multi_process_generate.py
Description: 演示多进程花费的时间
Signature: A boy without dreams
'''
import multiprocessing
from multiprocessing.dummy import freeze_support
from time import time
from generate_random_numbers import *

if __name__ == "__main__":  # 测试多进程必须要有主函数
    freeze_support()  # 可以更快

    start_t = time()
    count = 10000000
    n_process = 10  # 10个进程,每个进程执行1个任务
    process_containter = []  # 进程管理容器

    for i in range(n_process):
        out_list = list()
        process = multiprocessing.Process(
            target=generate_random_number, args=(count, out_list))
        process_containter.append(process)

    for process in process_containter:
        process.start()
    for process in process_containter:
        process.join()

    print("花费的总时间为 %.3f s" % (time()-start_t))  # 2.707s 明显非常的块
