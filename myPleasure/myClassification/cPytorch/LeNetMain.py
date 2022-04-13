'''
Author: chenbei
Date: 2022-04-12 16:44:52
LastEditTime: 2022-04-13 09:09:20
Description: LeNetMain.py
FilePath: \myLeetCode\myPleasure\myClassification\cPytorch\LeNetMain.py
Signature: A boy without dreams
'''
import torch
import torchvision
import torch.nn as nn
from LeNetModel import LeNetModel
import torch.optim as optim
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
root = r"C:\Users\chenb\.torch"
batch_size = 36
def getDataGenerator():
    transform = transforms.Compose( # 图片数据numpy->tensor并标准化
        [transforms.ToTensor(),
         transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])
    train_set = torchvision.datasets.CIFAR10(root=root, train=True,
                                             download=False, transform=transform)
    train_loader = torch.utils.data.DataLoader(train_set, batch_size=batch_size,
                                               shuffle=True, num_workers=0)
    val_set = torchvision.datasets.CIFAR10(root=root, train=False,
                                           download=False, transform=transform)
    val_loader = torch.utils.data.DataLoader(val_set, batch_size=5000, # 验证集多一些,1次验证5000张
                                             shuffle=False, num_workers=0)
    return train_loader,val_loader

def train(train_loader,val_loader,epochs=10):
    val_data_iter = iter(val_loader) # 将启动器转为可迭代的启动器
    val_image, val_label = val_data_iter.next() # 图像、标签成对迭代器next

    model = LeNetModel()
    loss_function = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.001)
    train_epoch_acu,train_epoch_loss = [],[]
    for epoch in range(epochs):
        running_loss = 0.0 # 每个周期的累积运行损失
        # step取决于样本数量和批次的商
        for step, data in enumerate(train_loader, start=0): # 从训练数据的启动器获取每步和数据,start为下标的起始位置,可指定遍历的起始位置
            inputs, labels = data # data是列表 [inputs, labels]
            # forward + backward + optimize
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = loss_function(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item() # 取出损失
            if step % 500 == 499:    # 每500步打印一次信息
                with torch.no_grad(): # 验证集不进行梯度计算
                    # 验证集是每次验证5000个
                    outputs = model(val_image)  # [batch, 5000],val_image自动可迭代,就无需自己写循环了
                    # print(outputs.size()) # 5000×10
                    # torch.max函数返回values,indices,即最大值所在索引,恰好就是预测的标签
                    predict_y = torch.max(outputs, dim=1)[1] # max在第2个维度比较,某行列元素之间,可用argmax代替
                    # print(predict_y.size()) # (5000,)
                    accuracy = torch.eq(predict_y, val_label).sum().item() / val_label.size(0) # 标签相等的数目之和除总的标签数
                    running_loss = running_loss / 500
                    print('[epoch=%d, step=%5d] loss: %.3f  test_acu: %.3f' %
                          (epoch + 1, step + 1, running_loss, accuracy)) # 准确来说是每每500步acu,loss的值,其中loss是平均值,acu是实时渐变值
                    train_epoch_acu.append(accuracy)
                    train_epoch_loss.append(running_loss)
                    running_loss = 0.0 # 每500步计算损失值然后清零
    save_path = r'C:\Users\chenb\VscodeItems\myLeetCode\myPleasure\myClassification\cPytorch\save_weights\myLeNet.pt'
    torch.save(model.state_dict(), save_path) # 保存模型
    return train_epoch_acu,train_epoch_loss
def plot_acu_loss(acu,loss):
    plt.subplot(1, 2, 1)
    plt.plot(range(len(acu)), acu, label='acu')
    plt.legend(loc='lower right')
    plt.xlabel("global steps")
    plt.ylabel("acu")
    plt.title('Training  Accuracy')

    plt.subplot(1, 2, 2)
    plt.plot(range(len(acu)), loss, label='loss')
    plt.xlabel("global steps")
    plt.ylabel("acu")
    plt.legend(loc='upper right')
    plt.title('Training  Loss')
    plt.show()
if __name__ == '__main__':
    epochs = 20
    acu,loss = train(*(getDataGenerator()),epochs=epochs)
    plot_acu_loss(acu,loss)



