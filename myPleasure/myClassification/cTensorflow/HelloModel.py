'''
Author: chenbei
Date: 2022-04-11 15:57:32
LastEditTime: 2022-04-12 09:12:54
Description: HelloModel.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\HelloModel.py
Signature: A boy without dreams
'''
from typing import Any
from tensorflow.keras import Model
from tensorflow.keras.layers import Dense,Flatten,Conv2D
class HelloModel(Model):
    def __init__(self) -> Any:
        super(HelloModel,self).__init__()
        self.conv1 = Conv2D(32,3,activation='relu') # 32 kernels,kernel size=3
        self.flatten = Flatten()
        self.dense1 = Dense(128,activation='relu')
        self.dense2 = Dense(10,activation='softmax') # 10 classifications,[0,1]
    def call(self,x,**kwargs):
        # input=>[batch,28,28,1] output=>[batch,26,26,32]
        # N2=[(N1-k+2*p)/s]+1=[(28-3+2*0)/1]+1=26=>[batch,26,26,32]
        # flatten=>26*26*32=21632
        x = self.conv1(x) #[batch,26,26,32]
        x = self.flatten(x) # [batch,21632]
        x = self.dense1(x) # [batch,128]
        return self.dense2(x) # [batch,10]
if __name__ == '__main__':
    model = HelloModel()
    model.build(input_shape=(None,28,28,1))
    model.summary()