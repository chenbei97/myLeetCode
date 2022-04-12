'''
Author: chenbei
Date: 2022-04-12 16:44:52
LastEditTime: 2022-04-12 17:00:41
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
    for epoch in range(epochs):
        running_loss = 0.0
        for step, data in enumerate(train_loader, start=0): # 从训练数据的启动器获取每步和数据
            inputs, labels = data # data是列表 [inputs, labels]
            # forward + backward + optimize
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = loss_function(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item()
            if step % 500 == 499:    # print every 500 mini-batches
                with torch.no_grad():
                    outputs = model(val_image)  # [batch, 10]
                    predict_y = torch.max(outputs, dim=1)[1] # 最大值那个是预测值
                    accuracy = torch.eq(predict_y, val_label).sum().item() / val_label.size(0)
                    print('[%d, %5d] train_loss: %.3f  test_accuracy: %.3f' %
                          (epoch + 1, step + 1, running_loss / 500, accuracy))
                    running_loss = 0.0 # 每500步计算损失值然后清零
    save_path = r'C:\Users\chenb\VscodeItems\myLeetCode\myPleasure\myClassification\cPytorch\save_weights'
    torch.save(model.state_dict(), save_path)
if __name__ == '__main__':
    train(*(getDataGenerator()))



