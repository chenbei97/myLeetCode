#%%
# -*- coding UTF-8 -*-
'''
@Project : PyCharmProjects
@File : algolist.py
@Software: PyCharm
@Author : chenbei
@Email : chenbei_electric@163.com
@Date : 2022/10/5 8:21
'''
from typing import List

#%% 去除可散列列表的重复元素
# 对象是可散列的是指生存期是不可变的,内部存在一个_hash_()函数
# Python中整数、浮点数、字符串和元组都是不可变的
def duplicate_removal(items:List):
    s = set()
    for item in items:
        if item not in s:
            yield item
            s.add(item)

def test_dr():
    a = [1,4,2,2,5,3,4,1,3,2,5,3,4,7]
    print(list(duplicate_removal(a))) # 得到的元素的相对顺序不变

test_dr()
#%%
# 不可散列的比如字典,保持相对顺序不变的程序如下
def duplicate_removal_nonhash(items:List,key=None):
    s = set()
    for item in items:
        print(f"item = {item}, key = {key}")
        # key(item) = key({'x': 2, 'y': 3}) => 把{'x': 2, 'y': 3}看成d变量
        # ({'x': 2, 'y': 3}['x'],{'x': 2, 'y': 3}['y']) => (2,3)
        val = item if key is None else key(item) # 说白了就是把关键字去掉,拿到值(元组)
        print(f"val = {val}")
        if val not in s: # 然后以元组为单位进行去重
            yield item
            s.add(val)
def test_drn():
    a = [
        {'x': 2, 'y': 3},
        {'x': 1, 'y': 4},
        {'x': 1, 'y': 4},
        {'x': 2, 'y': 3},
        {'x': 3, 'y': 4},
    ]
    print(list(duplicate_removal_nonhash(a,key=lambda d:(d['x'],d['y']))))
test_drn()

#%% 找出出现次数最多的元素
from collections import Counter
words = ['int','str','float','tuple','dict','set','list',
         'int','str','float','tuple','dict','set','list',
         'int','str','float','tuple','dict','set','list',
         'int','str','float','tuple','dict','set','list',
         'int','str','float','tuple','dict','set','list',
         'set','list','int']
counter = Counter(words)
print(counter.most_common(3))

#%% 依据特定值对类的实例排序
class User:
    def __init__(self,id):
        self.id = id
    def __repr__(self): # 打印时会出现的字符串内容
        return f'User Id {self.id}'

users = [User(5),User(20),User(15),User(10),User(12)]

print(users)
print(sorted(users,key=lambda x : x.id))
from operator import attrgetter
print(sorted(users,key=attrgetter('id')))

#%% 使用过滤函数处理列表
def test_filter():
    values = ['1','2','w','5','-','N/A']
    def is_int(val):
        try:
            x = int(val)
            return True
        except ValueError:
            return False
    vals = list(filter(is_int,values))
    print(vals)
test_filter()

#%% 使用slice切片
items = [0,1,2,3,4,5,6]
a = slice(2,4) # step = None
print(items[a])
print(items[2:4])
s = 'hello world! hello python and c++!'
print([s[idx] for idx in a.indices(len(s))]) # 2,4,1位置对应的字符
# %%
