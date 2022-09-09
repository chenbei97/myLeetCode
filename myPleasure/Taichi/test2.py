'''
Author: chenbei
Date: 2022-09-09 17:23:41
LastEditTime: 2022-09-09 17:37:15
FilePath: \\myLeetCode\\myPleasure\\Taichi\\test2.py
Description: 使用Taichi加速计算的第2个例子:使用动态规划最长公共子序列问题
Signature: A boy without dreams
'''
import taichi as ti
from time import time
import numpy as np
ti.init(arch=ti.cpu)  # 需要cpu,gpu会错
N = 15000
benchmark = True

f = ti.field(dtype=ti.i32, shape=(N+1, N+1))

if benchmark:
    a_numpy = np.random.randint(0, 100, N, dtype=np.int32)
    b_numpy = np.random.randint(0, 100, N, dtype=np.int32)
else:
    a_numpy = np.array([0, 1, 0, 2, 4, 3, 1, 2, 1], dtype=np.int32)
    b_numpy = np.array([4, 0, 1, 4, 5, 3, 1, 2], dtype=np.int32)


@ti.kernel
def compute(a: ti.types.ndarray(), b: ti.types.ndarray()) -> ti.i32:
    len_a, len_b = a.shape[0], b.shape[0]

    ti.loop_config(serialize=True)
    for i in range(1, len_a+1):
        for j in range(1, len_b+1):
            f[i, j] = max(f[i-1, j-1]+(a[i-1] == b[j-1]),
                          max(f[i-1, j], f[i, j-1]))
    return f[len_a, len_b]


if __name__ == "__main__":
    t = time()
    ret = compute(a_numpy, b_numpy)
    print(f"t = {time()-t} s, ret = {ret}")
