import socket
import json
from collections import defaultdict
import threading

port = 3002

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
            print(tr(frame) == "0x0001")
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

# 写法2 带线程
def receive_messages2(conn):
    while True:
        data = conn.recv(1024)
        if not data:
            break
        print(data)
        json_dict = json.loads(data)
        if "frame" in json_dict.keys():
            frame = json_dict["frame"]
            print(frame, type(frame))
            reponse = defaultdict()
            if str(frame) == "0x0002":
                path = r"C:\Users\22987\AppData\Local\EOSI"
                reponse["frame"] = "0x0002"
                reponse["repeat"] = 0
                reponse["path"] = path
                conn.sendall(json.dumps(reponse).encode("utf-8"))
            if str(frame) == "0x0001":
                reponse["frame"] = "0x0001"
                reponse["repeat"] = 0
                reponse["equipment_number"] = 1
                conn.sendall(json.dumps(reponse).encode("utf-8"))


def server_loop():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('localhost', port))
    s.listen(1)

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
print(text)

# 模拟text被json接收
request = json.loads(text)

# 0x0000涉及的所有字段
fields_0x0000 = ["channel","objective","group","count","duration",
                 "end","is_schedule","view","wellsize","total","start"]
# 如果is_schedule = false， 忽略start和end，立即执行

for field in fields_0x0000:
    if field == "group":
        groups = request[field]
        groupPts = []
        for group in groups:
            #print(group.keys())  # 这里可以拿到组的名称,有必要的话
            for pointlist in group.values():
                # print(pointlist)
                pts = [() for _ in range(len(pointlist))]  # 生成指定长度的列表
                for point in pointlist:
                    x = point["x"]
                    y = point["y"]
                    order = point["order"]
                    pts[order] = (x,y) # 根据这个点的次序存放到列表的对应位置去
                #print(pts) # 这里就拿到了这个组的所有点,且排好序
            groupPts.append(pts.copy()) # 大列表拿到所有组的点,注意要深拷贝
        print(groupPts) # 所有组的所有点
    else:
        print(request[field])


if __name__ == '__main__':
    if with_thread:
        server_loop()
    else:
        receive_messages1()