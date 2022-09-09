'''
Author: chenbei
Date: 2022-09-09 17:38:18
LastEditTime: 2022-09-09 17:50:34
FilePath: \\myLeetCode\\myPleasure\\Taichi\\test3.py
Description: 使用Taichi加速计算的第3个例子:计算反应-扩散方程
Signature: A boy without dreams
'''
from os import kill
import taichi as ti
from time import time
import numpy as np
ti.init()

W, H = 800, 600
uv = ti.Vector.field(2, float, shape=(2, W, H))

uv_grid = np.zeros((2, W, H, 2), dtype=np.float32)
uv_grid[0, :, :, 0] = 1.0
row = np.random.choice(range(W), 50)
col = np.random.choice(range(H), 50)
uv_grid[0, row, col, 1] = 1.0
uv.from_numpy(uv_grid)

# 随便给点数
Du = 110.0
Dv = 120.0
feed = 21.1
kill = 0.19


@ti.kernel
def compute(phase: int):
    for i, j in ti.ndrange(W, H):
        cen = uv[phase, i, j]
        lap1 = uv[phase, i+1, j]+uv[phase, i, j+1] + \
            uv[phase, i-1, j]+uv[phase, i, j-1]-4.0*cen
        du = Du * lap1[0]-cen[0]*cen[1]*cen[1]+feed * (1-cen[0])
        dv = Dv * lap1[1]+cen[0]*cen[1]*cen[1]-(feed+kill)*cen[1]
        val = cen + 0.5 * 1  # tm.vec2(du,dv) = 1代替
        uv[1-phase, i, j] = val


if __name__ == "__main__":
    t = time()
    compute(3)
    print(f"t = {time()-t} s")
