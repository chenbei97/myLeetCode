'''
Author: chenbei
Date: 2022-09-09 14:37:51
LastEditTime: 2022-09-09 14:44:25
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap01\\generate_random_numbers.py
Description: 1个生成随机数的简单函数
Signature: A boy without dreams
'''
import random
from typing import List
def generate_random_number(count:int,out_list:List)->None:
    '''
        count : 要生成的随机数个数
        out_list: 输出的列表对象
    '''
    for i in range(count):
        out_list.append(random.random())