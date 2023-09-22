import queue
import random
import socket
import json
import time
from collections import defaultdict
import threading
from random import randint
import re
# import chardet


port = 3000

max_delay = 5

# 0x0000涉及的所有字段
fields_0x0000 = ["channel","objective","group","count","duration",
                 "end","is_schedule","view","wellsize","total","start"]
def parse_0x0000(frame:str,conn,**kwargs):
    message = kwargs["message"]
    for field in fields_0x0000:
        if field == "group":
            groups = message[field]
            groupPts = []
            for group in groups:
                # print(group.keys())  # 这里可以拿到组的名称,有必要的话
                for pointlist in group.values():
                    # print(pointlist)
                    pts = [() for _ in range(len(pointlist))]  # 生成指定长度的列表
                    for point in pointlist:
                        x = point["x"]
                        y = point["y"]
                        order = point["order"]
                        pts[order] = (x, y)  # 根据这个点的次序存放到列表的对应位置去
                    # print(pts) # 这里就拿到了这个组的所有点,且排好序
                groupPts.append(pts.copy())  # 大列表拿到所有组的点,注意要深拷贝
            print(groupPts)  # 所有组的所有点
        else:
            print(message[field])
    reponse = defaultdict()
    reponse["frame"] = frame
    reponse["repeat"] = 0
    conn.sendall(json.dumps(reponse).encode("utf-8")) # utf-8发出,这样上位机解析也是根据utf-8来解析

def parse_0x0001 (frame:str,conn,**kwargs):
    reponse = defaultdict()
    reponse["frame"] = frame
    reponse["repeat"] = 0
    reponse["equipment_number"] = 1
    conn.sendall(json.dumps(reponse).encode("utf-8"))

def parse_0x0002 (frame:str,conn,**kwargs):
    print("**kwargs = ",kwargs)
    # if kwargs == {}:
    #     return
    end = kwargs["end_time"]
    message = kwargs["message"]
    print("request msg = ", message)
    reponse = defaultdict()
    path = r"C:/Users/22987/Desktop/EOSI/images/cell.png"  +str(randint(1,100))

    # 这里模拟一个比较耗时的操作,例如点击移动拍图调用算法返回这些
    delay = randint(max_delay-1,max_delay+1)
    time.sleep(delay) # 上位机会等待这次结果,假设拍图时间最多4s就可以完成,上位机会规定等待4s
    diff = time.time() - end
    if diff > 0 :
        reponse["frame"] = frame
        reponse["repeat"] = 1 # 要求重发, 或者不要再发送了,因为超时错误被上位机处理了
        # 然后请求下一个坐标,假设5s超时,这里执行了8s,上位机请求第2次的第3s回复的是第1次的消息会造成整个错乱

    else :
        reponse["frame"] = frame
        reponse["repeat"] = 0
        reponse["point.x"] = message["point.x"]
        reponse["point.y"] = message["point.y"]
        reponse["path"] = path

    text = "超时" if diff > 0 else "没超时"
    response = json.dumps(reponse).encode("utf-8")
    print(f"delay = {delay} {text} response = {response}")
    conn.sendall(response)

parseFunctions = {
    "0x0000":parse_0x0000,
    "0x0001":parse_0x0001,
    "0x0002":parse_0x0002
}

# 写法1 不带线程
def receive_messages1():
    # 创建一个socket对象
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 绑定到指定的地址和端口
    s.bind(('localhost', port))
    # 开始监听连接
    s.listen(1)

    conn, addr = s.accept()  # 接受客户端连接
    print('Connected by', addr)

    while True:
        data = conn.recv(1024)  # 接收客户端发来的消息
        if not data:
            break  # 如果接收到空消息，说明客户端已经退出，退出循环
        # 处理消息
        print("data = ",data)
        # 发送回复消息给客户端
        json_dict = json.loads(data)
        if "frame" in json_dict.keys():
            frame = json_dict["frame"]
            print("hehre1 ",frame, type(frame))
            print(str(frame) == "0x0001")
            if str(frame) == "0x0001":
                path = r"C:\Users\22987\AppData\Local\EOSI"
                print(path)
                reponse = defaultdict()
                reponse["frame"] = "0x0002"
                reponse["result"] = 0
                reponse["path"] = path
                print("message = ",reponse)
                value = json.dumps(reponse)
                print("message = ",value)
                conn.sendall(value.encode("utf-8"))

def splitMessage(string : str) ->list :
    left_indexs = []
    right_indexs = []

    for i in range(len(string)) :
        if string[i] == "{" :
            left_indexs.append(i)
        if string[i] == "}" :
            right_indexs.append(i)

    assert len(left_indexs) == len(right_indexs)

    # print(left_indexs,right_indexs)

    msgs = []

    for start,end in zip(left_indexs,right_indexs):
        msgs.append(string[start:end+1])

    #print(msgs)
    return msgs

# def detect_encoding(data):
#     result = chardet.detect(data)
#     return result['encoding']

# 写法2 带线程
def receive_messages2(conn):
    data_quque = queue.Queue()
    while True:
        data = conn.recv(10240)
        if not data:
            break
        # print("data = ",data)
        # 假设预览时上位机只允许等待3s,但是回消息4s(parse_0x0002),那么上位机就会重发
        # 这样data收到的其实是2条重复的消息,然后json.loads会抛出JSONDecodeError
        # 所以这里是需要队列处理的,每条消息都是{}括起来,splitMessage去做分割处理
        # 后来发现有点问题,有的命令起始是一条命令,但是有多个{},这样就不对了
        # 考虑到都是同步发送和接收,不要队列也可以,起始队列打印log就知道,只要上位机没在下位机回复前不发送新的不会出现多条消息
        # 机制已经保证了是同步一发一收,就不使用队列了

        #requests = splitMessage(data.decode("utf-8")) # 不要用str(),会自动多加字符'/'
        #print("request's count = ", len(requests))
        # for msg in requests:
        #     data_quque.put(msg)
        #print("queue's count = ", len(data_quque.queue))

        msg = data.decode("utf-8") # 上位机传送的是utf-8，要用utf-8先解码
        print("msg = ",msg)
        json_dict = json.loads(msg,encoding="utf-8")
        if "frame" in json_dict.keys():
            frame = json_dict["frame"]

        # 利用函数指针省去frame的判断,不再需要下方的写法
        # if str(frame) == "0x0002": # 预览拿到坐标要回复坐标和路径
        #     # 上位机传输坐标
        #     parse_0x0002(frame,json_dict,conn)
        # if str(frame) == "0x0001": # 通用流程参数不需要回复其他数据
        #     parse_0x0000(frame,conn)

            # 改用函数指针自动根据frame调用函数
            if frame == "0x0002": # 对于预览需要传递额外的参数end_time和请求消息原文
                end_time = time.time() + max_delay # 把应该结束的时间传进去
                pack_params = {"end_time": end_time, "message":json_dict}
                print("0x0002 is called")
                parseFunctions[frame](frame,conn,**pack_params)
            elif frame == "0x0000":
                pack_params = {"message": json_dict}
                parseFunctions[frame](frame, conn, **pack_params)
            else:
                parseFunctions[frame](frame,conn)

def server_loop():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', port))
    s.listen(5)

    while True:
        print('Waiting for a connection...')
        conn, addr = s.accept()
        print('Connected by', addr)
        client_thread = threading.Thread(target=receive_messages2, args=(conn,))
        client_thread.start()

with_thread = True

# 测试收发和解析
message = {
    "channel": "phase",
    "group": [
        {
            "A组": [
                {
                    "order": 0,
                    "x": 3,
                    "y": 5
                },
                {
                    "order": 1,
                    "x": 4,
                    "y": 8
                },
                {
                    "order": 2,
                    "x": 6,
                    "y": 3
                },
                {
                    "order": 3,
                    "x": 4,
                    "y": 2
                }
            ]
        },
        {
            "B组": [
                {
                    "order": 0,
                    "x": 0,
                    "y": 10
                },
                {
                    "order": 1,
                    "x": 1,
                    "y": 0
                },
                {
                    "order": 2,
                    "x": 7,
                    "y": 1
                }
            ]
        },
        {
            "C组": [
                {
                    "order": 0,
                    "x": 5,
                    "y": 9
                },
                {
                    "order": 1,
                    "x": 2,
                    "y": 4
                }
            ]
        },
        {
            "D组": [
                {
                    "order": 0,
                    "x": 3,
                    "y": 2
                }
            ]
        }
    ],
    "objective": "40x",
    "count": 17,
    "duration": 2100,
    "end": "2023/09/05 21:51",
    "is_schedule": 1,
    "start": "2023/09/05 11:51",
    "total": 36000,
    "view": 289,
    "wellsize": 96
}
# 为了方便先通过json的dumps转为文本
text = json.dumps(message)
#print(text)

# 模拟text被json接收
request = json.loads(text)
#print(request)


'''
某次log分析，上位机和下位机可以对照分析
【1】下位机: 
(1) 请求坐标(0,0) => 没超时 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 0, 'point.y': 0}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 0, "point.y": 0, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png98"}'

(2) 请求坐标(1,1) => 超时2次 => 上位机重复请求2次 => 上位机正确显示path
① request msg =  {'frame': '0x0002', 'point.x': 1, 'point.y': 1}
delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
② request msg =  {'frame': '0x0002', 'point.x': 1, 'point.y': 1}
delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
request msg =  {'frame': '0x0002', 'point.x': 1, 'point.y': 1}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 1, "point.y": 1, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png20"}'

(3) 请求坐标(2,2) => 没超时 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 2, 'point.y': 2}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 2, "point.y": 2, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png48"}'

(4) 请求坐标(3,3) => 超时4次 => 上位机重复请求4次(超过3次) => 上位机显示重复请求错误
① request msg =  {'frame': '0x0002', 'point.x': 3, 'point.y': 3}
delay = 6 超时 response = b'{"frame": "0x0002", "repeat": 1}'
② request msg =  {'frame': '0x0002', 'point.x': 3, 'point.y': 3}
delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
③ request msg =  {'frame': '0x0002', 'point.x': 3, 'point.y': 3}
delay = 6 超时 response = b'{"frame": "0x0002", "repeat": 1}'
④ request msg =  {'frame': '0x0002', 'point.x': 3, 'point.y': 3}
delay = 6 超时 response = b'{"frame": "0x0002", "repeat": 1}'

(5) 请求坐标(4,4) => 没超时 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 4, 'point.y': 4}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 4, "point.y": 4, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png64"}'
request msg =  {'frame': '0x0002', 'point.x': 5, 'point.y': 5}

(6) 请求坐标(5,5) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
① delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
request msg =  {'frame': '0x0002', 'point.x': 5, 'point.y': 5}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 5, "point.y": 5, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png27"}'

(7) 请求坐标(6,6) => 没超时 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 6, 'point.y': 6}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 6, "point.y": 6, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png71"}'

(8) 请求坐标(7,7) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
① request msg =  {'frame': '0x0002', 'point.x': 7, 'point.y': 7}
delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
request msg =  {'frame': '0x0002', 'point.x': 7, 'point.y': 7}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 7, "point.y": 7, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png54"}'

(9) 请求坐标(8,8) => 没超时 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 8, 'point.y': 8}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 8, "point.y": 8, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png4"}'

(10) 请求坐标(9,9) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
request msg =  {'frame': '0x0002', 'point.x': 9, 'point.y': 9}
delay = 5 超时 response = b'{"frame": "0x0002", "repeat": 1}'
request msg =  {'frame': '0x0002', 'point.x': 9, 'point.y': 9}
delay = 4 没超时 response = b'{"frame": "0x0002", "repeat": 0, "point.x": 9, "point.y": 9, "path": "C:/Users/22987/Desktop/EOSI/images/cell.png33"}'

【2】上位机: 
(1) 请求坐标(0,0) => 没超时 => 上位机正确显示path
[ "16:33:12:044" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 0,\n    \"point.y\": 0\n}\n"
[ "16:33:16:062" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 0, \"point.y\": 0, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png98\"}"
[ "16:33:16:062" TcpQuery::exec ]  error =  "NoError"

(2) 请求坐标(1,1) => 超时2次 => 上位机重复请求2次 => 上位机正确显示path
[ "16:33:16:066" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 1,\n    \"point.y\": 1\n}\n"
[ "16:33:21:077" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:21:077" TcpQuery::exec ]  error =  "ReceiveResponseError"
[ "16:33:21:077" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 1,\n    \"point.y\": 1\n}\n"  第 1 次
[ "16:33:26:090" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:26:091" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:33:26:092" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 1,\n    \"point.y\": 1\n}\n"  第 2 次
[ "16:33:30:110" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 1, \"point.y\": 1, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png20\"}"

(3) 请求坐标(2,2) => 没超时 => 上位机正确显示path
[ "16:33:30:123" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 2,\n    \"point.y\": 2\n}\n"
[ "16:33:34:141" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 2, \"point.y\": 2, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png48\"}"
[ "16:33:34:143" TcpQuery::exec ]  error =  "NoError"

(4) 请求坐标(3,3) => 超时4次 => 上位机重复请求4次(超过3次) => 上位机显示重复请求错误
[ "16:33:34:154" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 3,\n    \"point.y\": 3\n}\n"
[ "16:33:40:167" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:40:169" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:33:40:169" TcpQuery::exec ]  error =  "ReceiveResponseError"
[ "16:33:40:169" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 3,\n    \"point.y\": 3\n}\n"  第 1 次
[ "16:33:45:179" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:45:179" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:33:45:179" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 3,\n    \"point.y\": 3\n}\n"  第 2 次
[ "16:33:51:182" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:51:182" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:33:51:183" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 3,\n    \"point.y\": 3\n}\n"  第 3 次
[ "16:33:57:189" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:33:57:190" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:33:57:190" TcpQuery::exec ]  多次重发错误 

(5) 请求坐标(4,4) => 没超时 => 上位机正确显示path
[ "16:33:57:204" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 4,\n    \"point.y\": 4\n}\n"
[ "16:34:01:225" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 4, \"point.y\": 4, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png64\"}"
[ "16:34:01:226" TcpQuery::exec ]  error =  "NoError"

(6) 请求坐标(5,5) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
[ "16:34:01:240" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 5,\n    \"point.y\": 5\n}\n"
[ "16:34:06:248" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:34:06:248" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:34:06:249" TcpQuery::exec ]  error =  "ReceiveResponseError"
[ "16:34:06:249" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 5,\n    \"point.y\": 5\n}\n"  第 1 次
[ "16:34:10:255" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 5, \"point.y\": 5, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png27\"}"

(7) 请求坐标(6,6) => 没超时 => 上位机正确显示path
[ "16:34:10:269" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 6,\n    \"point.y\": 6\n}\n"
[ "16:34:14:285" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 6, \"point.y\": 6, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png71\"}"
[ "16:34:14:286" TcpQuery::exec ]  error =  "NoError"

(8) 请求坐标(7,7) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
[ "16:34:14:296" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 7,\n    \"point.y\": 7\n}\n"
[ "16:34:19:317" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:34:19:317" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:34:19:317" TcpQuery::exec ]  error =  "ReceiveResponseError"
[ "16:34:19:317" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 7,\n    \"point.y\": 7\n}\n"  第 1 次
[ "16:34:23:328" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 7, \"point.y\": 7, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png54\"}"

(9) 请求坐标(8,8) => 没超时 => 上位机正确显示path
[ "16:34:23:340" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 8,\n    \"point.y\": 8\n}\n"
[ "16:34:27:354" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 8, \"point.y\": 8, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png4\"}"
[ "16:34:27:355" TcpQuery::exec ]  error =  "NoError"

(10) 请求坐标(9,9) => 超时1次 => 上位机重复请求1次 => 上位机正确显示path
[ "16:34:27:366" TcpQuery::exec ]  request msg =  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 9,\n    \"point.y\": 9\n}\n"
[ "16:34:32:378" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 1}"
[ "16:34:32:379" TcpSocket::exec ]  data =  "ReceiveResponseError"  index =  6
[ "16:34:32:379" TcpQuery::exec ]  error =  "ReceiveResponseError"
[ "16:34:32:379" TcpQuery::exec ]  正在重发  "{\n    \"frame\": \"0x0002\",\n    \"point.x\": 9,\n    \"point.y\": 9\n}\n"  第 1 次
[ "16:34:36:396" TcpDealer::parse ]  response msg =  "{\"frame\": \"0x0002\", \"repeat\": 0, \"point.x\": 9, \"point.y\": 9, \"path\": \"C:/Users/22987/Desktop/EOSI/images/cell.png33\"}"

【3】界面消息栏：
除了(3,3)是超时回复超过3次显示多次重发错误，其它超时3次及以内或者没超时都会显示正确的路径
[2023/0907 16:33:08] 状态: 连接成功!
[2023/0907 16:33:12] 发送: { "frame": "0x0002", "point.x": 0, "point.y": 0 } 
[2023/0907 16:33:16] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png98

[2023/0907 16:33:16] 发送: { "frame": "0x0002", "point.x": 1, "point.y": 1 } 
[2023/0907 16:33:30] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png20

[2023/0907 16:33:30] 发送: { "frame": "0x0002", "point.x": 2, "point.y": 2 } 
[2023/0907 16:33:34] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png48

[2023/0907 16:33:34] 发送: { "frame": "0x0002", "point.x": 3, "point.y": 3 } 
[2023/0907 16:33:57] 错误: MultipleRetransmissionError 

[2023/0907 16:33:57] 发送: { "frame": "0x0002", "point.x": 4, "point.y": 4 } 
[2023/0907 16:34:01] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png64

[2023/0907 16:34:01] 发送: { "frame": "0x0002", "point.x": 5, "point.y": 5 } 
[2023/0907 16:34:10] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png27

[2023/0907 16:34:10] 发送: { "frame": "0x0002", "point.x": 6, "point.y": 6 } 
[2023/0907 16:34:14] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png71

[2023/0907 16:34:14] 发送: { "frame": "0x0002", "point.x": 7, "point.y": 7 } 
[2023/0907 16:34:23] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png54

[2023/0907 16:34:23] 发送: { "frame": "0x0002", "point.x": 8, "point.y": 8 } 
[2023/0907 16:34:27] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png4

[2023/0907 16:34:27] 发送: { "frame": "0x0002", "point.x": 9, "point.y": 9 } 
[2023/0907 16:34:36] 回复: C:/Users/22987/Desktop/EOSI/images/cell.png33
'''
if __name__ == '__main__':
    if with_thread:
        print("start server loop")
        server_loop()
    else:
        receive_messages1()

    def test():
        # "{\n    \"\xE5\x9B\xBD\xE5\xAE\xB6\": \"a\"\n}\n" toJson(可以看出默认是utf-8)
        # "\xB9\xFA\xBC\xD2" toLocal8Bit
        # "\xE5\x9B\xBD\xE5\xAE\xB6" toUft8
        msgs = b'{\n    \"\xE5\x9B\xBD\xE5\xAE\xB6\": \"a\"\n}\n'  # utf-8

        kk = json.loads(msgs.decode("utf-8")) # 要先解码,再加载解码后的字符串,然后load编码用utf-8,gbk,none都可正常显示
        print(kk)
        print("国家".encode("utf-8")) # '\xe5\x9b\xbd\xe5\xae\xb6'
        print("国家".encode("gbk")) # '\xb9\xfa\xbc\xd2'
    #test()

    sys.exit()

