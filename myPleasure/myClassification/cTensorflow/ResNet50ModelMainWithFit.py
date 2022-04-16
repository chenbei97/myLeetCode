'''
Author: chenbei
Date: 2022-04-16 15:51:22
LastEditTime: 2022-04-16 18:37:23
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\ResNet50ModelMainWithFit.py
Description: ResNet50ModelMainWithFit.py
Signature: A boy without dreams
'''
import tensorflow as tf
import os
from tensorflow.keras import applications,Input,layers,Model
from VggNetMain import getDataGenerator,plot_acu_loss
import datetime
import math
# 全局参数
num_classes = 5
im_height = 224
im_width = 224
batch_size = 32
epochs = 5
seed = 123
validation_split = 0.2
global_path = 'C:\\Users\\chenbei\\VscodeItems\\myLeetCode\\myPleasure\\myClassification\\cTensorflow\\'
# train_dir = os.path.join('',
# 'C:\\Users\\chenb\\.keras\\datasets\\flower_photos')
# cbacks_path = 'C:\\Users\\chenb\\VscodeItems\\myLeetCode\\myPleasure\\myClassification\\cTensorflow\\save_weights'

train_dir = os.path.join('',
'C:\\Users\\chenbei\\.keras\\datasets\\flower_photos')
cbacks_path = global_path+'save_weights'
log_dir = global_path+"save_logs\\" + datetime.datetime.now().strftime("%Y%m%d-%H%M%S")

def myScheduler(epoch): # 自定义学习率
    initial_lr = 0.01
    end_lr = 0.001
    # [(1+cos(epoch/epochs*pi))/2 * (1-end_lr) + end_lr] * initial_lr - lr
    rate = ((1 + math.cos(epoch * math.pi / epochs)) / 2) * (1 - end_lr) + end_lr  # cosine
    new_lr = rate * initial_lr
    return new_lr

# 使用compile、fit版本
def train_with_fit():
    train_data_gen,validation_data_gen = getDataGenerator()
    # 使用的模型是Resnet50
    pre_model =  applications.ResNet50(include_top=False, 
                                   input_shape=(224, 224, 3),
                                   weights='imagenet') # 使用预训练
    pre_model.trainable = False
    print(pre_model.summary())
    # 函数式编程
    inputs = Input(shape=(224, 224, 3)) # 创建1个输入层

    # 对编码一批图像的张量或Numpy数组进行预处理，处理数据格式,caffe,tf,torch是不一样的
    x = applications.resnet50.preprocess_input(inputs) # 输入,内部调用了imagenet_utils.preprocess_input函数

    x = pre_model(x) # 特征提取层输出
    x = layers.GlobalAveragePooling2D()(x) # 输出是[batch,channels]
    outputs = layers.Dense(num_classes)(x) # 创建1个输出层
    
    model = Model(inputs,outputs) # 输入、输出构造模型
    print(model.summary()) # 可以比较差异

    model.compile(optimizer=tf.keras.optimizers.SGD(learning_rate=0.001, momentum=0.9),
                  loss=tf.keras.losses.CategoricalCrossentropy(from_logits=True),
                  metrics=[tf.keras.metrics.CategoricalAccuracy("accuracy")])
    callbacks = [tf.keras.callbacks.ModelCheckpoint(filepath=cbacks_path+"\\ResNet50Model_{epoch}.h5",
                                                    save_best_only=True,
                                                    save_weights_only=True,
                                                    monitor=tf.keras.metrics.CategoricalAccuracy("accuracy").name),
                 tf.keras.callbacks.TensorBoard(log_dir=log_dir, 
                                                write_graph=True,
                                                histogram_freq=1),
                # 进入log_dir文件夹,会生成20220416-170723文件夹,终端执行tensorboard --logdir=20220416-172712
                # 保存上传,tensorboard dev upload --logdir \ '20220416-172712'
                # 打开端口http://localhost:6006/即可查看
                 tf.keras.callbacks.LearningRateScheduler(schedule=myScheduler)]
    history = model.fit(x=train_data_gen,
              epochs=epochs,
              validation_data=validation_data_gen,
              callbacks=callbacks)
    return history.history
if __name__ == '__main__':
    history = train_with_fit()
    plot_acu_loss(history,epochs)
