'''
Author: chenbei
Date: 2022-04-11 15:59:00
LastEditTime: 2022-04-12 13:13:21
Description: HelloMain.py
FilePath: \myLeetCode\myPleasure\myClassification\cTensorflow\HelloMain.py
Signature: A boy without dreams
'''
import tensorflow as tf
from tensorflow.keras import losses,optimizers
from tensorflow.keras import datasets
from tensorflow.keras import metrics
from HelloModel import HelloModel
import matplotlib.pyplot as plt
from tqdm import tqdm
def getDataGenerator():
    mnist = datasets.mnist
    (x_train,y_train),(x_test,y_test) = mnist.load_data()
    x_train,x_test = x_train/255.0,x_test/255.0

    # 添加新通道
    x_train = x_train[...,tf.newaxis]
    x_test = x_test[...,tf.newaxis]
    train_ds = tf.data.Dataset.from_tensor_slices(
        (x_train,y_train)).shuffle(10000).batch(32)
    test_ds = tf.data.Dataset.from_tensor_slices((x_test,y_test)).batch(32)
    return train_ds,test_ds
def train(train_ds,test_ds,epochs=5):
    model = HelloModel()
    lossFunction = losses.SparseCategoricalCrossentropy() # (y_true,y_pred)
    optimizer = optimizers.Adam()

    train_loss = metrics.Mean(name='train_loss')
    train_acu = metrics.SparseCategoricalAccuracy(name='train_accuracy') # update_state,reset_state
    test_loss = metrics.Mean(name='test_loss')
    test_acu = metrics.SparseCategoricalAccuracy(name='test_accuracy')

    @tf.function
    def train_step(images,labels):
        with tf.GradientTape() as tape:
            preditions = model(images)
            loss = lossFunction(labels,preditions)
        # 更新梯度
        gradients = tape.gradient(loss,model.trainable_variables)
        optimizer.apply_gradients(zip(gradients,model.trainable_variables))
        train_loss(loss) # 计算损失和准确率
        train_acu(labels,preditions)
    
    @tf.function
    def test_step(images,labels):
        predictions = model(images)
        loss = lossFunction(labels,predictions)
        test_loss(loss)
        test_acu(labels,predictions)
    
    train_loss_list = []
    train_acu_list = []
    val_loss_list = []
    val_acu_list = []

    def mytrain():
        for epoch in tqdm(range(epochs)):
            train_loss.reset_states()
            train_acu.reset_states()
            test_loss.reset_states()
            test_acu.reset_states()
            
            for images,labels in train_ds:
                train_step(images,labels)
            for test_images,test_labels in test_ds:
                test_step(test_images,test_labels)
            
            train_acu_list.append(train_acu.result())
            train_loss_list.append(train_loss.result())
            val_acu_list.append(test_acu.result())
            val_loss_list.append(test_loss.result())

            printLog = 'epoch={}, train_loss = {}, train_acu = {}, test_loss = {}, test_acu = {}'
            print(printLog.format(epoch+1,
                                  train_loss.result(),
                                  train_acu.result(),
                                  test_loss.result(),
                                  test_acu.result()))
    def plot_acu_loss():
        plt.subplot(2, 1, 1)
        plt.plot(range(epochs), train_acu_list, label='Training Accuracy')
        plt.plot(range(epochs), val_acu_list, label='Validation Accuracy')
        plt.legend(loc='lower right')
        plt.title('Training and Validation Accuracy')

        plt.subplot(2, 1, 2)
        plt.plot(range(epochs), train_loss_list, label='Training Loss')
        plt.plot(range(epochs), val_acu_list, label='Validation Loss')
        plt.legend(loc='upper right')
        plt.title('Training and Validation Loss')
        plt.show()
   
    mytrain()
    plot_acu_loss()


if __name__ == '__main__':
    train_ds,test_ds = getDataGenerator()
    train(train_ds,test_ds)