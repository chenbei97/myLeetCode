# This Python file uses the following encoding: utf-8

# test_python.py 测试了python是否引入成功

# test_plot 测试了引入 matplotlib、numpy是否成功

''' 这里集中测试几类函数
 （1）没有参数也没有返回值的函数
 （2）没有参数但是有返回值的函数
        对于返回值类型这里不作测试，在（4）集中测试
 （3）有参数没有返回值的函数
        对于参数类型这里不做测试，在（4）集中测试
 （4）有参数且有返回值的函数
        输入：int、tuple、list、dict  返回：int tuple、list、dict
        测试输入int，返回int、tuple、list、dict 4种情况
        以及输入tuple、list、dict返回int的3种情况，返回其它的数据类型是类似的不再测试
        即常规的一共8种情况：
        int -> int(float/double)
        int -> str
        int -> tuple
        int -> list/np.ndarray
        str -> int(float/double)
        tuple -> int(float/double)
        list -> int(float/double)
        dict -> int(float/double)
 （5）类的成员函数
'''
import numpy as np
from typing import List,Tuple,Dict

def void_void() -> None:
        x,y = np.random.random((3,3)),np.random.random((3,3))
        print("void_void is called => ",np.sum(np.dot(x,y)))

def nvoid_void() -> float:
        x,y = np.random.random((3,3)),np.random.random((3,3))
        ret = np.sum(np.dot(x,y))
        print("\nnvoid_void is called => ",ret)
        return ret

def void_nvoid(size:int) -> float:
        x,y = np.random.random((size,size)),np.random.random((size,size))
        print("\nvoid_nvoid is called => ",np.sum(np.dot(x,y)))

# 这里讨论8种组合情况
def nvoid_nvoid_if(size:int) -> float:
        x,y = np.random.random((size,size)),np.random.random((size,size))
        ret = np.sum(np.dot(x,y))
        print("\nnvoid_nvoid(int)->float is called => ",ret)
        return ret

def nvoid_nvoid_is(size:int) -> str:
        x,y = np.random.random((size,size)),np.random.random((size,size))
        ret = str(np.sum(np.dot(x,y)))
        print("\nnvoid_nvoid(int)->str is called => ",ret)
        return ret

def nvoid_nvoid_it(size:int) -> tuple:
      x,y = np.random.random((size,size)),np.random.random((size,size))
      ret = (np.sum(np.dot(x,y)),np.random.randint(0,100))
      print("\nnvoid_nvoid(int)->tuple is called => ",ret)
      return ret

def nvoid_nvoid_il(size:int) -> np.ndarray: #list
    x,y = np.random.random((size,size)),np.random.random((size,size))
    # ret = list(np.sum(np.dot(x,y),axis=0)) # 返回可以是np的数组类型也可以是列表不影响外部的解析因为都是可迭代类型
    ret = np.sum(np.dot(x,y),axis=0)
    print("\nnvoid_nvoid(int)->list is called => ",ret)
    return ret

def nvoid_nvoid_id(size:int)->dict:
    def c():
        return np.sum(np.random.random((size,size)))
    x,y = c(), c()
    print("\nnvoid_nvoid(int)->dict is called => {'x':%f,'y':%f}" %(x,y))
    return {"x": x, "y": y}

def nvoid_nvoid_si(a:str) -> int:
    print(f"arg's type is str is called, arg is {a}")
    return len(a)

def nvoid_nvoid_ti(a:Tuple) -> int:
    print("arg's type is tuple is called")
    return len(a) + sum(a)

def nvoid_nvoid_di(a:Dict) -> int:
    print("arg's type is dict is called")
    ret = 0
    for _,val in a.items():
        ret += val
    return ret

def nvoid_nvoid_li(a:List) -> int:
    print("arg's type is list is called")
    return sum(a)

def nvoid_nvoid_iii(a:int,b:int,c:int) -> int:
    t = (a,b,c)
    return sum(t) + len(t)

if __name__ == "__main__":
    print(nvoid_nvoid_ti((1,2,3,4,5)))
    print(nvoid_nvoid_di({'x':7,'y':3,'z':10}))
