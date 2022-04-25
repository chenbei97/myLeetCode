'''
Author: chenbei
Date: 2022-04-25 20:12:38
LastEditTime: 2022-04-25 20:29:14
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\GooleNetMain.py
Description: GooleNet's main.py
Signature: A boy without dreams
'''
import tensorflow as tf
import os
from tensorflow.keras import applications,Input,layers,Model
from VggNetMain import getDataGenerator
from GooleNetModel import GoogLeNet
from tqdm import tqdm
import datetime
import math
import sys
im_height = 224
im_width = 224
batch_size = 32
epochs = 30
def train():
    train_data_gen,validation_data_gen = getDataGenerator()
    # 训练和验证集的总迭代次数
    total_train = train_data_gen.n
    total_val = validation_data_gen.n
    
    model = GoogLeNet(im_height=im_height, im_width=im_width, class_num=5, aux_logits=True)
    model.summary()

    loss_object = tf.keras.losses.CategoricalCrossentropy(from_logits=False)
    optimizer = tf.keras.optimizers.Adam(learning_rate=0.0003)

    train_loss = tf.keras.metrics.Mean(name='train_loss')
    train_accuracy = tf.keras.metrics.CategoricalAccuracy(name='train_accuracy')

    val_loss = tf.keras.metrics.Mean(name='val_loss')
    val_accuracy = tf.keras.metrics.CategoricalAccuracy(name='val_accuracy')

    @tf.function
    def train_step(images, labels):
        with tf.GradientTape() as tape:
            aux1, aux2, output = model(images, training=True)
            loss1 = loss_object(labels, aux1)
            loss2 = loss_object(labels, aux2)
            loss3 = loss_object(labels, output)
            loss = loss1 * 0.3 + loss2 * 0.3 + loss3
        gradients = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))

        train_loss(loss)
        train_accuracy(labels, output)

    @tf.function
    def val_step(images, labels):
        _, _, output = model(images, training=False)
        loss = loss_object(labels, output)

        val_loss(loss)
        val_accuracy(labels, output)
    
    best_val_acc = 0.
    for epoch in range(epochs):
        # 每周期清空历史消息
        train_loss.reset_states()  
        train_accuracy.reset_states()  
        val_loss.reset_states()  
        val_accuracy.reset_states() 

        train_bar = tqdm(range(total_train // batch_size), file=sys.stdout) # 可刷新终端
        for step in train_bar:
            images, labels = next(train_data_gen)
            train_step(images, labels)

            # print train process
            train_bar.desc = "train epoch[{}/{}] loss:{:.3f}, acc:{:.3f}".format(epoch + 1,
                                                                                 epochs,
                                                                                 train_loss.result(),
                                                                                 train_accuracy.result())
        
        # validate
        val_bar = tqdm(range(total_val // batch_size), file=sys.stdout)
        for step in val_bar:
            val_images, val_labels = next(validation_data_gen)
            val_step(val_images, val_labels)

            # print val process
            val_bar.desc = "valid epoch[{}/{}] loss:{:.3f}, acc:{:.3f}".format(epoch + 1,
                                                                               epochs,
                                                                               val_loss.result(),
                                                                             val_accuracy.result())
        # only save best weights,这里不再保存
        # if val_accuracy.result() > best_val_acc:
        #     best_val_acc = val_accuracy.result()
        #     model.save_weights("./save_weights/myGoogLeNet.ckpt")

if __name__ == '__main__':
    train()