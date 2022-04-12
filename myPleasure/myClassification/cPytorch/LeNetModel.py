'''
Author: chenbei
Date: 2022-04-12 16:31:55
LastEditTime: 2022-04-12 16:44:30
Description: LeNetModel.py
FilePath: \myLeetCode\myPleasure\myClassification\cPytorch\LenetModel.py
Signature: A boy without dreams
'''
import torch.nn as nn
from torch.nn import functional
from torchsummary import summary
class LeNetModel(nn.Module):
    def __init__(self):
        super(LeNetModel,self).__init__()
        self.conv1 = nn.Conv2d(3,16,5)
        self.pool1 = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(16, 32, 5)
        self.pool2 = nn.MaxPool2d(2, 2)
        self.fc1 = nn.Linear(32*5*5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
    def forward(self, x):
        x = functional.relu(self.conv1(x))      # input(3, 32, 32) output(16, 28, 28)
        x = self.pool1(x)                       # output(16, 14, 14)
        x = functional.relu(self.conv2(x))      # output(32, 10, 10)
        x = self.pool2(x)                       # output(32, 5, 5)
        x = x.view(-1, 32*5*5)                  # output(32*5*5)
        x = functional.relu(self.fc1(x))        # output(120)
        x = functional.relu(self.fc2(x))        # output(84)
        x = self.fc3(x)                         # output(10)
        return x
if __name__ == '__main__':
    model = LeNetModel()
    summary(model, (3,32,32))
    