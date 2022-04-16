'''
Author: chenbei
Date: 2022-04-16 17:17:32
LastEditTime: 2022-04-16 21:16:27
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\ResNet50ModelMainWithoutFit.py
Description: ResNet50ModelMainWithoutFit.py
Signature: A boy without dreams
'''
from tqdm import tqdm
import os
import tensorflow as tf
from tensorflow.keras import applications,Input,layers,Model
import matplotlib.pyplot as plt
from VggNetMain import getDataGenerator
import sys
import datetime
import math
# 全局参数
num_classes = 5
im_height = 224
im_width = 224
batch_size = 32
epochs = 10
seed = 123
validation_split = 0.2
global_path = 'C:\\Users\\chenbei\\VscodeItems\\myLeetCode\\myPleasure\\myClassification\\cTensorflow\\'
train_dir = os.path.join('',
'C:\\Users\\chenbei\\.keras\\datasets\\flower_photos')
# 不保存tensorboard模型数据,所以注释掉了
# log_dir = global_path+"save_logs\\" + datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
# train_writer = tf.summary.create_file_writer(os.path.join(log_dir, "train"))
# val_writer = tf.summary.create_file_writer(os.path.join(log_dir, "val"))
cbacks_path = global_path+'save_weights'
def myScheduler(epoch): # 自定义学习率
    initial_lr = 0.01
    end_lr = 0.001
    # [(1+cos(epoch/epochs*pi))/2 * (1-end_lr) + end_lr] * initial_lr - lr
    rate = ((1 + math.cos(epoch * math.pi / epochs)) / 2) * (1 - end_lr) + end_lr  # cosine
    new_lr = rate * initial_lr
    return new_lr
def plot_epoch_loss_acu(acu,loss):

    train_loss = loss[0]
    train_accuracy = acu[0]
    val_loss = loss[1]
    val_accuracy = acu[1]
    plt.subplot(2, 1, 1)
    if len(train_accuracy) > 0: # 4个if语句是兼容设置语句,正常应该会有val的acu和loss但是这里没去验证
        plt.plot(range(epochs), train_accuracy, label='Training Accuracy')
    if len(val_accuracy) > 0:
        plt.plot(range(epochs), val_accuracy, label='Validation Accuracy')
    plt.legend(loc='lower right')
    plt.title('Training and Validation Accuracy')

    plt.subplot(2, 1, 2)
    if len(train_loss)> 0:
        plt.plot(range(epochs), train_loss, label='Training Loss')
    if len(val_loss)>0:
        plt.plot(range(epochs), val_loss, label='Validation Loss')
    plt.legend(loc='upper right')
    plt.title('Training and Validation Loss')
    plt.show()

def train_without_fit():
    train_data_gen,validation_data_gen = getDataGenerator()
    pre_model =  applications.ResNet50(include_top=False, 
                                   input_shape=(224, 224, 3),
                                   weights='imagenet') # 使用预训练
    pre_model.trainable = False
    # 函数式编程
    inputs = Input(shape=(224, 224, 3)) # 创建1个输入层
    x = applications.resnet50.preprocess_input(inputs) # 输入,内部调用了imagenet_utils.preprocess_input函数
    x = pre_model(x) # 特征提取层输出
    x = layers.GlobalAveragePooling2D()(x) # 输出是[batch,channels]
    outputs = layers.Dense(num_classes)(x) # 创建1个输出层
    
    model = Model(inputs,outputs) # 输入、输出构造模型
    print(model.summary()) # 可以比较差异

    loss_function = tf.keras.losses.CategoricalCrossentropy(from_logits=True)
    optimizer = tf.keras.optimizers.SGD(learning_rate=0.01, momentum=0.9)

    train_loss = tf.keras.metrics.Mean(name='train_loss')
    train_accuracy = tf.keras.metrics.CategoricalAccuracy(name='train_accuracy')

    val_loss = tf.keras.metrics.Mean(name='val_loss')
    val_accuracy = tf.keras.metrics.CategoricalAccuracy(name='val_accuracy')

    @tf.function
    def train_step(images, labels):
        with tf.GradientTape() as tape:
            output = model(images, training=True)
            loss = loss_function(labels, output)
        gradients = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))

        train_loss(loss)
        train_accuracy(labels, output)
    
    @tf.function
    def test_step(images, labels):
        output = model(images, training=False)
        t_loss = loss_function(labels, output)

        val_loss(t_loss)
        val_accuracy(labels, output)
    
    # best_val_accuracy = 0.
    epoch_loss,epoch_acu = [[],[]],[[],[]]
    for epoch in range(epochs):
        train_loss.reset_states()  # clear history info
        train_accuracy.reset_states()  # clear history info
        # val_loss.reset_states()  # clear history info
        # val_accuracy.reset_states()  # clear history info

        train_bar = tqdm(train_data_gen, file=sys.stdout)
        for images, labels in train_bar:
            train_step(images, labels)
            # 属性设置或者使用方法都可以
            # train_bar.desc = "train_loss:{:.3f}, train_acc:{:.3f}".format(train_loss.result(),train_accuracy.result())
            train_bar.set_description("epoch [{}/{}] loss: {:.3f}, acc: {:.3f}".format(epoch + 1, epochs,
                train_loss.result(), train_accuracy.result()))
        epoch_loss[0].append(train_loss.result())
        epoch_acu[0].append(train_accuracy.result())
        # optimizer.learning_rate = myScheduler(epoch) # 每周期更新学习率

        # 每周期验证,为了提高速度不再验证,家里电脑配置太差。。

        # val_bar = tqdm(validation_data_gen, file=sys.stdout)
        # for test_images, test_labels in val_bar: 
        #     test_step(test_images, test_labels) 
            # val_bar.desc = "epoch [{}/{}] val_loss:{:.3f}, val_acc:{:.3f}".format(epoch + 1, epochs,
            #     val_loss.result(),val_accuracy.result())
        # epoch_loss[1].append(val_loss.result())
        # epoch_acu[1].append(val_accuracy.result())
        # 每周期保存模型则可以消除下方代码注释
        
        # with train_writer.as_default():
            # tf.summary.scalar("loss", train_loss.result(), epoch)
        #     tf.summary.scalar("accuracy", train_accuracy.result(), epoch)
        # with val_writer.as_default():
        #     tf.summary.scalar("loss", val_loss.result(), epoch)
        #     tf.summary.scalar("accuracy", val_accuracy.result(), epoch)

        # if val_accuracy.result() > best_val_accuracy:
        #     best_val_accuracy = val_accuracy.result()
        #     model.save_weights(cbacks_path+"\\model_{}.ckpt".format(epoch), save_format="tf")
        return epoch_acu,epoch_loss
if __name__ == '__main__':
    epoch_acu,epoch_loss = train_without_fit()
    plot_epoch_loss_acu(epoch_acu,epoch_loss)      