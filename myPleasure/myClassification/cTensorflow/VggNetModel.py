'''
Author: chenbei
Date: 2022-04-14 16:31:14
LastEditTime: 2022-04-14 16:47:33
Description: VggNetModel.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\VggNetModel.py
Signature: A boy without dreams
'''
from typing import List
from tensorflow.keras import layers, Model, Sequential

# 卷积核初始化的设置
CONVD_KERNEL_INITIALIZER = {
    'class_name': 'VarianceScaling',
    'config': {
        'scale': 2.0,
        'mode': 'fan_out',
        'distribution': 'truncated_normal'
    }
}

# 全连接层初始化的设置
DENSE_KERNEL_INITIALIZER = {
    'class_name': 'VarianceScaling',
    'config': {
        'scale': 1. / 3.,
        'mode': 'fan_out',
        'distribution': 'uniform'
    }
}

# 定义VGG的特征层,因为VGG有多个版本,现在把不同版本定义的简称给出
vgg_versions = {
    'vgg11': [64, 'M', 128, 'M', 256, 256, 'M', 512, 512, 'M', 512, 512, 'M'],
    'vgg13': [64, 64, 'M', 128, 128, 'M', 256, 256, 'M', 512, 512, 'M', 512, 512, 'M'],
    'vgg16': [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 'M', 512, 512, 512, 'M', 512, 512, 512, 'M'],
    'vgg19': [64, 64, 'M', 128, 128, 'M', 256, 256, 256, 256, 'M', 512, 512, 512, 512, 'M', 512, 512, 512, 512, 'M'],
}

# 依据vgg_version指定的关键字来构造不同版本VGG的特征层
def make_feature(vgg_verson:List[int or str]):
    feature_layers = []
    for v in vgg_verson:
        if v == "M":
            # M 表示要加入的是池化层,默认降采样尺寸减半
            feature_layers.append(layers.MaxPool2D(pool_size=2, strides=2))
        else:
            # 否则数字都是指定卷积核的数量
            conv2d = layers.Conv2D(v, kernel_size=3, padding="SAME", activation="relu",
                                   kernel_initializer=CONVD_KERNEL_INITIALIZER) # 核初始化设置在上述字典已经定义
            feature_layers.append(conv2d)
    return Sequential(feature_layers, name="feature") # 返回序列模型作为特征层

# 特征层+分类层的完整VGG模型
def VGG(feature, im_height=224, im_width=224, num_classes=1000):
    # tensorflow中的tensor通道排序是NHWC Batch高宽通道数
    input_image = layers.Input(shape=(im_height, im_width, 3), dtype="float32")
    # 采用函数式编程
    x = feature(input_image)
    x = layers.Flatten()(x)
    x = layers.Dropout(rate=0.5)(x)
    x = layers.Dense(2048, activation='relu',
                     kernel_initializer=DENSE_KERNEL_INITIALIZER)(x)
    x = layers.Dropout(rate=0.5)(x)
    x = layers.Dense(2048, activation='relu',
                     kernel_initializer=DENSE_KERNEL_INITIALIZER)(x)
    x = layers.Dense(num_classes,
                     kernel_initializer=DENSE_KERNEL_INITIALIZER)(x)
    output = layers.Softmax()(x)
    model = Model(inputs=input_image, outputs=output)
    return model

# 提供给外界的使用函数
def vgg(vgg_version="vgg16",im_height=224,im_width=224,num_classes=1000):
    assert vgg_version in vgg_versions.keys(), "not support model {}".format(vgg_version) # assert expression,exception
    vgg_version = vgg_versions[vgg_version]
    model = VGG(make_feature(vgg_version), im_height=im_height, im_width=im_width, num_classes=num_classes)
    return model
if __name__ == '__main__':
    model = vgg()
    model.summary()