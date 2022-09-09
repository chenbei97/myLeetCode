'''
Author: chenbei
Date: 2022-09-09 17:06:12
LastEditTime: 2022-09-09 17:22:50
FilePath: \\myLeetCode\\myPleasure\\Taichi\\test1.py
Description: 使用Taichi加速计算的第1个例子:求所有小于给定正整数n的素数
Signature: A boy without dreams
'''
import taichi as ti
from time import time

# 直接计算


def is_prime_direct(n: int):
    res = True
    for k in range(2, int(n ** 0.5)+1):
        if n % k == 0:
            res = False
            break
    return res


def count_primes_direct(n: int) -> int:
    count = 0
    for k in range(2, n):
        if is_prime_direct(k):
            count += 1
    return count


def count_direct():
    t = time()
    count_primes_direct(10000000)  # 计算1000万以内的素数
    print("直接计算耗时：", time()-t)


# 使用taichi加速
# ti.init()
ti.init(arch=ti.gpu)


@ti.func
def is_prime_taichi(n: int):
    res = True
    for k in range(2, int(n ** 0.5)+1):
        if n % k == 0:
            res = False
            break
    return res


@ti.kernel
def count_primes_taichi(n: int) -> int:
    count = 0
    for k in range(2, n):
        if is_prime_taichi(k):
            count += 1
    return count


def count_taichi():
    t = time()
    count_primes_taichi(10000000)  # 计算1000万以内的素数
    print("使用Taichi加速耗时：", time()-t)


if __name__ == "__main__":
    count_direct()
    count_taichi()
    '''
        不使用gpu结果:
            直接计算耗时： 73.22750091552734
            使用Taichi加速耗时: 0.7614645957946777
        使用gpu结果:
            直接计算耗时： 73.75559830665588
            使用Taichi加速耗时: 0.6888341903686523
    '''
