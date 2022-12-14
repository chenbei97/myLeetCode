# -*- coding: utf-8 -*-

import pandas as pd
import os
from typing import Tuple

def export_csv(header:str,content:str) -> Tuple[int,int,int]: # (int,int,int): 2个都可以,但是c++解析必须用"iii"
    if content[-1] != "\n":
        print("导出失败!表格内容格式不正确,每行必须以换行符结束,且各项以逗号分隔.")
        return 0,0,0

    if header[-1] == "\n":
        header = header[:-1]

    lines = content.split("\n")
    lines.pop(-1) # 有个空字符串要删除

    columns = header.split(",")  # 这个是表头可以用来传递导入的表头
    if len(lines[0].split(",")) != len(columns):
        print("导出失败!表头长度和文本列数不匹配!")
        return 0,0,0

    index = range(1,len(lines)+1) # 让行索引从1开始,不过导出不要index标签所以无所谓
    s = pd.Series(lines,index=index) # series不能指定column参数

    df = s.str.split(",",expand=True) # 这样不会文本都是1列,而是以逗号分隔开
    df.columns = columns
    # df.rename(columns=columns, inplace=True) 这种方式columns要传递字典
    df.to_csv("python_test.csv",index=None) # 不要index标签
    print(f"导出成功!表格的尺寸为({df.shape[0]},{df.shape[1]})")
    return 1,df.shape[0],df.shape[1]

def import_csv(path:str) -> bytearray:
    if not os.path.exists(path) or path == '': 
        print("path is not exists!")
        return ''
    
    df = pd.read_csv(path)
    headers = df.columns.to_list()
    header = ",".join(str(i) for i in headers) + "\n" # 姓名,性别,年龄,学历,专业,籍贯,手机号\n

    c = df.to_numpy()
    content = ""
    for line in c:
        s = ",".join(str(i) for i in line) + "\n"
        content += s
    ret = bytearray((header+content),'gb2312') # 要传递字节数组,指定gb2312/gbk均可直接返回str,c++解析后会乱码
    return ret

if __name__ == "__main__":
    header = "姓名,性别,年龄,学历,专业,籍贯,手机号\n"
    content = "A,男,25,硕士,电气,江西,19801279791\n" \
            "B,男,25,硕士,电气,江西,19801279791\n" \
            "C,男,25,硕士,电气,江西,19801279791\n" \
            "D,男,25,硕士,电气,江西,19801279791\n" \
            "E,男,25,硕士,电气,江西,19801279791\n" \
            "F,男,25,硕士,电气,江西,19801279791\n" \
            "G,男,25,硕士,电气,江西,19801279791\n" \
            "H,男,25,硕士,电气,江西,19801279791\n" \
            "K,男,25,硕士,电气,江西,19801279791\n" \
            "L,男,25,硕士,电气,江西,19801279791\n"
    ret,msg,row,col = export_csv(header,content)
    
    header1 = "姓名" # 单个值的测试也ok
    content1 = "A\n"
    ret1,msg1,row1,col1 = export_csv(header1,content1)
    
    print(ret,msg,row,col)
    print(ret1,msg1,row1,col1)
