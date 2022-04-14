'''
Author: chenbei
Date: 2022-04-14 16:44:41
LastEditTime: 2022-04-14 16:56:32
Description: VggNetMain.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\VggNetMain.py
Signature: A boy without dreams
'''
from VggNetModel import vgg
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import matplotlib.pyplot as plt
from tensorflow.keras import optimizers,losses,callbacks
import numpy as np
import os
# 全局参数
im_height = 224
im_width = 224
batch_size = 32
epochs = 10
seed = 123
validation_split = 0.2
train_dir = os.path.join('',
'C:\\Users\\chenb\\.keras\\datasets\\flower_photos')# 花数据集是5分类问题['sunflowers','dandelion','roses','daisy','tulips']
cbacks_path = 'C:\\Users\\chenb\\VscodeItems\\myLeetCode\\myPleasure\\myClassification\\cTensorflow\\save_weights'
# 处理数据并返回数据启动器
def pre_function(img: np.ndarray):
    img = img / 255.
    img = img - [0.485, 0.456, 0.406]
    img = img / [0.229, 0.224, 0.225]
    return img
def getDataGenerator():
        image_generator = ImageDataGenerator(rescale=1. / 255,
                                            horizontal_flip=True,
                                            validation_split=validation_split,
                                            preprocessing_function=pre_function) # 通过实时数据增强生成批量张量图像数据
        # 创建数据生成器,从指定的文件夹中提取数据
        train_data_gen = image_generator.flow_from_directory(directory=train_dir,
                                                               batch_size=batch_size,
                                                               shuffle=True,
                                                               seed=seed,
                                                               target_size=(im_height, im_width),
                                                               class_mode='categorical',
                                                               subset='training') # 标签是二维独热编码
        validation_data_gen = image_generator.flow_from_directory(directory=train_dir,
                                                               batch_size=batch_size,
                                                               shuffle=True,
                                                               seed=seed,
                                                               target_size=(im_height, im_width),
                                                               class_mode='categorical',
                                                               subset='validation') # 标签是二维独热编码
        return train_data_gen,validation_data_gen
def train():
    train_data_gen,validation_data_gen = getDataGenerator()
    model = vgg(num_classes=5) 
    model.compile(optimizer=optimizers.Adam(learning_rate=0.0001),
                  loss=losses.CategoricalCrossentropy(from_logits=False),
                  metrics=["accuracy"])
    
    cbacks = [callbacks.ModelCheckpoint(filepath=cbacks_path+'\\myVgg.h5',
                                                    save_best_only=True,
                                                    save_weights_only=True,
                                                    monitor='val_loss')]
    history = model.fit(x=train_data_gen,
                        steps_per_epoch=train_data_gen.n // batch_size,
                        epochs=epochs,
                        validation_data=validation_data_gen,
                        validation_steps=validation_data_gen.n // batch_size,
                        callbacks=cbacks)
    return history.history

def plot_acu_loss(history:dict):
    history_dict = history
    train_loss = history_dict["loss"]
    train_accuracy = history_dict["accuracy"]
    val_loss = history_dict["val_loss"]
    val_accuracy = history_dict["val_accuracy"]
    plt.subplot(2, 1, 1)
    plt.plot(range(epochs), train_accuracy, label='Training Accuracy')
    plt.plot(range(epochs), val_accuracy, label='Validation Accuracy')
    plt.legend(loc='lower right')
    plt.title('Training and Validation Accuracy')

    plt.subplot(2, 1, 2)
    plt.plot(range(epochs), train_loss, label='Training Loss')
    plt.plot(range(epochs), val_loss, label='Validation Loss')
    plt.legend(loc='upper right')
    plt.title('Training and Validation Loss')
    plt.show()
if __name__ == '__main__':
    model = vgg()
    history = train()
    plot_acu_loss(history)
