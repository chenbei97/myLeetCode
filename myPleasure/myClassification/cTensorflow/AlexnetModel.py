'''
Author: chenbei
Date: 2022-04-12 08:44:46
LastEditTime: 2022-04-12 09:11:23
Description: AlexnetModel.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\AlexnetModel.py
Signature: A boy without dreams
'''
from tensorflow.keras import layers,Model,Sequential
class AlexnetModel(Model):
    def __init__(self, num_classes=1000,*args, **kwargs):
        super(AlexnetModel,self).__init__(*args, **kwargs)
        # 输入[batch,224,224,3]
        # 特征层
        self.features = Sequential([
            # ((top_pad, bottom_pad), (left_pad, right_pad)),零拓展，左上拓展1列1行,右下2列2行
            layers.ZeroPadding2D(((1, 2), (1, 2))),                                 # output(batch, 227, 227, 3)
            layers.Conv2D(48, kernel_size=11, strides=4, activation="relu"),        # output[batch,55,55,48]  (227-11)/4+1=55
            layers.MaxPool2D(pool_size=3, strides=2),                               # output(batch, 27, 27, 48) 池化尺寸减半
            layers.Conv2D(128, kernel_size=5, padding="same", activation="relu"),   # output(batch, 27, 27, 128) padding="same"尺寸不变
            layers.MaxPool2D(pool_size=3, strides=2),                               # output(batch, 13, 13, 128) 池化尺寸减半
            layers.Conv2D(192, kernel_size=3, padding="same", activation="relu"),   # output(batch, 13, 13, 192) padding="same"尺寸不变
            layers.Conv2D(192, kernel_size=3, padding="same", activation="relu"),   # output(batch, 13, 13, 192) padding="same"尺寸不变
            layers.Conv2D(128, kernel_size=3, padding="same", activation="relu"),   # output(batch, 13, 13, 128) padding="same"尺寸不变
            layers.MaxPool2D(pool_size=3, strides=2)                                # output(batch, 6, 6, 128) 池化尺寸减半
            ])
        # 展平层
        self.flatten = layers.Flatten() # input(batch,4608) 6*6*128=4608
        # 分类层
        self.classifier = Sequential([
            layers.Dropout(0.2),                                                    # 降低过拟合
            layers.Dense(1024, activation="relu"),                                  # output(batch, 1024)
            layers.Dropout(0.2),
            layers.Dense(128, activation="relu"),                                   # output(batch, 128)
            layers.Dense(num_classes),                                              # output(batch, num_classes)
            layers.Softmax()                                                        # 归一化
            ])
    def call(self, inputs, **kwargs):
        x = self.features(inputs)
        x = self.flatten(x)
        x = self.classifier(x)
        return x
if __name__ == '__main__':
    model = AlexnetModel()
    model.build(input_shape=(None,224,224,3))
    model.summary()