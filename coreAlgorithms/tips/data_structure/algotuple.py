#%%
# -*- coding UTF-8 -*-
'''
@Project : PyCharmProjects
@File : algotuple.py.py
@Software: PyCharm
@Author : chenbei
@Email : chenbei_electric@163.com
@Date : 2022/10/6 11:33
'''
from _collections import deque

def search(lines,text,history=5):
    container = deque(maxlen=history)
    for line in lines:
        # print("① => ",line) 打印的就是文本流的每一行
        if text in line:
            # print("② => ",line) 打印的是存在'python'的行
            # print("③ => ",container)
            yield line, container # 这个产生的东西可以被外边接收
            # print("④ => ", container) 其实和③一样,只不过外部yield执行完才会执行④
        container.append(line) # 如果有yield后程序要先去外部,当外部程序执行完才回到这里,或者该行没有'python'就会直接执行到⑤
        print("⑤ => ", container) # 回到⑤之后是一次执行,又回到①开始新的,不过不管有没有'python'这里的container都是添加了进去

with open('123.txt') as f:
     for line, container in search(f,'python',5): # 接收的是内部yield产生的东西,也就是存在'python'的文本
         # print("⑥ => ",line) 和②一样
         # print("⑦ => ",container) 和③一样
         for pline in container:
             print("⑧ => ",pline)
         print("⑨ => ",line) # 和②一样
         print('-'*100)
f.close()
#%% 优先级队列

import heapq
class PriorityQueue:
    def __init__(self):
        self.queue = []
        self.index = 0
    def push(self,item,priority):
        heapq.heappush(self.queue,(-priority,self.index,item))
        self.index += 1
    def pop(self):
        return heapq.heappop(self.queue)[-1]
class Item:
    def __init__(self,name):
        self.name = name
    def __repr__(self):
        return 'Item({!r})'.format(self.name)
q = PriorityQueue()
q.push(Item("AAA"),1)
q.push(Item("BBB"),4)
q.push(Item("CCC"),5)
q.push(Item("DDD"),2)
q.push(Item("EEE"),2)
print(q.pop())
print(q.pop())
print(q.pop())
# %%
