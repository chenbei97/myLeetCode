#%%
# -*- coding UTF-8 -*-
'''
@Project : python学习工程文件夹
@File : Features.py
@Author : chenbei
@Date : 2020/12/23 10:27
@Addess : https://www.cnblogs.com/cwp-bg/p/9488107.html
'''
'''
1、能量的表达式  : 对时间序列的每个点的值平方,然后求和 
2、对EMD熵来说首先对实现序列进行EMD分解,1个样本得到多个imf分量,例如得到1000×10(序列长度*imf分量个数)
   然后对每个imf分量(每列)求能量,即可以得到一个能量行向量(1×10) E = [E1,E2,E3,...,E10]
3、根据能量熵的定义需要先求得每个imf分量在总的imf分量的占比 Pe  1×10  即 Pe = [Pe1,Pe2,Pe3,...,Pe10]
4、能量熵公式为 He = -[Pe1*lg(Pe1)+Pe2*lg(Pe2)+,,,Pe10*lg(Pe10)] 最终1个样本得到1个能量熵
5、合并 241×1 的能量熵矩阵
6、类似的可以得到奇异熵，都是尺度分解 ,1000×10 处理
7、[近似熵、样本熵、排列熵、自相关系数、方差、均值] 不尺度分解 直接对样本的时间序列 列向量1000×1处理
8、上述合并为 1×8 特征矩阵
9、还需要定义一个函数,对所有样本进行处理 得到 241×8 特征矩阵
'''
import numpy as np
import matplotlib.pyplot as plt
class emd_entropy() :
    def __init__(self,array):
        self.array = array
    def get_energy(self):
        '''
        :param array: 时间序列长度*imf个数 参考1000*10
        :return: 行向量 1个样本的每个imf分量的能量 energy=[E1,E2,...Ek]
        '''
        energies = []
        for column in range(self.array.shape[1]):
            energies.append(sum(self.array[:, column] ** 2))
        return np.array(energies)

    def get_pe(self):
        # 返回每个能量的占比
        energy = self.get_energy()
        #print(1,len(energy))
        energysum = sum(energy[0:-1])  # 求得不同imf的总能量 ,行向量
        new = energy[0:-1] / energysum  # 每个imf分量的占比 Pe = [Pe1,Pe2,...,Pek]
        #print(2,len(new))
        return new
    def get_entropy(self):
        pe = self.get_pe() # [Pe1,Pe2,...,Pek]
        Entropy= 0
        for i in range(len(pe)) :
            Entropy = Entropy - pe[i] * np.log10(pe[i])
        return Entropy
class svd_entropy():
    def __init__(self,array):
        self.array = array
    def get_singular_value(self):
        '''
        一个 mxn的矩阵H可以分解为 U(mxm) ,S(mxn) , V(nxn) 三个矩阵的乘积，这就是奇异值分解
        S是一个对角矩阵，一般从大到小排列，S的元素值称为奇异值
        :return: 输入1000×10的单一样本数组 , 返回 奇异值 1×10 [svd1,svd2,...svd10]
        '''
        _, S, _ = np.linalg.svd(self.array) # U , S ,V = np.linalg.svd(example)
        return S
    def get_se(self):
        svd = self.get_singular_value()
        sumsvd = sum(svd[0:-1]) # 奇异值之和
        se = svd[0:-1] / sumsvd  # [Se1,Se2,...,Se10]
        return se
    def get_entropy(self):
        se  = self.get_se()
        Entropy = 0
        for i in range(len(se)):
            if se[i] == 0 :
                tem = 0
                print("存在奇异值为0,程序将跳过该元素防止出错")
            else:
                tem = se[i] * np.log10(se[i])
            Entropy = Entropy - tem
        return Entropy
class permutation_entropy():
    '''
    序列长度、嵌入维数和延迟时间
    m : 5~7比较合适 2~3太小, 12~15太大
    '''
    def __init__(self,vetor):
        self.vetor = vetor
    def get_func(self,n):
        """求阶乘"""
        if n == 0 or n == 1:
            return 1
        else:
            return (n * self.get_func(n - 1))
    def get_probality(self,S):
        """计算每一种 m 维符号序列的概率"""
        _map = {}
        for item in S:
            a = str(item)
            if a in _map.keys():
                _map[a] = _map[a] + 1
            else:
                _map[a] = 1
        freq_list = []
        for freq in _map.values():
            freq_list.append(freq / len(S))
        return freq_list
    def get_Entropy(self,m,t):
        """计算排列熵值"""
        length = len(self.vetor) - (m - 1) * t
        # 重构 k*m 矩阵
        y = [self.vetor[i:i + m * t:t] for i in range(length)]
        # 将各个分量升序排序
        S = [np.argsort(y[i]) for i in range(length)]
        # 计算每一种 m 维符号序列的概率
        freq_list = self.get_probality(S)
        # 计算排列熵
        pe = 0
        for freq in freq_list:
            pe += (- freq * np.log(freq))
        return pe / np.log(self.get_func(m))
    def plot_var_m(self):
        PE_m = []
        ms = [2, 3, 4, 5, 6, 7, 8]
        for m1 in ms:
            pe = self.get_Entropy(m=m1,t=3)  # 固定时延,改变嵌入维数
            PE_m.append(pe)
        plt.plot(PE_m)
        plt.show()
    def plot_var_t(self):
        PE_t = []
        ts = [1, 2, 3, 4, 5, 6, 7, 8]
        for t in ts:
            pe = self.get_Entropy(m=2,t=t)  # 固定时延,改变嵌入维数
            PE_t.append(pe)
        plt.plot(PE_t)
        plt.show()


