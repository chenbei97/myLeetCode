'''
Author: chenbei
Date: 2022-09-09 14:41:02
LastEditTime: 2022-09-09 15:10:09
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap01\\serial_generate.py
Description: 演示串行编程花费的时间
Signature: A boy without dreams
'''
from itertools import count
from time import time
from generate_random_numbers import *

start_t = time()
exec = 10  # 一共执行10次
count = 10000000  # 每次生成1000万个数

for i in range(exec):
    out_list = list()  # 输出的列表
    generate_random_number(count, out_list)
    print(f"第{i+1}次串行生成随机数结束...")

print("花费的总时间为 %.3f s" % (time()-start_t))

'''
花费的总时间为 10.905 s
'''
