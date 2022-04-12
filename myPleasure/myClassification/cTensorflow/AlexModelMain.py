'''
Author: chenbei
Date: 2022-04-12 08:45:19
LastEditTime: 2022-04-12 12:41:31
Description: AlexModelMain.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\AlexModelMain.py
Signature: A boy without dreams
'''
from AlexnetModel import AlexnetModel
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras import optimizers,losses,callbacks
import matplotlib.pyplot as plt
import tensorflow as tf
import os
import numpy as np
def pre_function(img: np.ndarray):
    # from PIL import Image as im
    # import numpy as np
    # img = im.open('test.jpg')
    # img = np.array(img).astype(np.float32)
    img = img / 255.
    img = img - [0.485, 0.456, 0.406]
    img = img / [0.229, 0.224, 0.225]

    return img
def getDataGenerator(batch_size=32):
        image_generator = ImageDataGenerator(rescale=1. / 255,
                                            horizontal_flip=True,
                                            validation_split=0.2,
                                            preprocessing_function=pre_function) # 通过实时数据增强生成批量张量图像数据
        # 创建数据生成器,从指定的文件夹中提取数据
        batch_size = batch_size
        im_height = 224
        im_width = 224
        train_dir = os.path.join('','C:\\Users\\chenb\\.keras\\datasets\\flower_photos')
        print(train_dir)
        train_data_gen = image_generator.flow_from_directory(directory=train_dir,
                                                               batch_size=batch_size,
                                                               shuffle=True,
                                                               seed=123,
                                                               target_size=(im_height, im_width),
                                                               class_mode='categorical',
                                                               subset='training') # 标签是二维独热编码
        validation_data_gen = image_generator.flow_from_directory(directory=train_dir,
                                                               batch_size=batch_size,
                                                               shuffle=True,
                                                               seed=123,
                                                               target_size=(im_height, im_width),
                                                               class_mode='categorical',
                                                               subset='validation') # 标签是二维独热编码
        return train_data_gen,validation_data_gen,batch_size
def train(epochs=10):
    train_data_gen,validation_data_gen,batch_size = getDataGenerator()
    model = AlexnetModel(num_classes=5) # 花数据集是5分类问题['sunflowers','dandelion','roses','daisy','tulips']
    model.compile(optimizer=optimizers.Adam(learning_rate=0.0005),
                  loss=losses.CategoricalCrossentropy(from_logits=False),
                  metrics=["accuracy"])
    cbacks_path = 'C:\\Users\\chenb\\VscodeItems\\myLeetCode\\myPleasure\\myClassification\\cTensorflow'
    cbacks = [callbacks.ModelCheckpoint(filepath=cbacks_path+'\\save_weights\\myAlex.h5',
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
def plot_acu_loss(epochs:int,history:dict):
    history_dict = history
    train_loss = history_dict["loss"]
    train_accuracy = history_dict["accuracy"]
    val_loss = history_dict["val_loss"]
    val_accuracy = history_dict["val_accuracy"]
    plt.subplot(1, 2, 1)
    plt.plot(range(epochs), train_accuracy, label='Training Accuracy')
    plt.plot(range(epochs), val_accuracy, label='Validation Accuracy')
    plt.legend(loc='lower right')
    plt.title('Training and Validation Accuracy')

    plt.subplot(1, 2, 2)
    plt.plot(range(epochs), train_loss, label='Training Loss')
    plt.plot(range(epochs), val_loss, label='Validation Loss')
    plt.legend(loc='upper right')
    plt.title('Training and Validation Loss')
    plt.show()


if __name__ == '__main__':
    epochs = 20
    history = train(epochs)
    plot_acu_loss(epochs,history)

