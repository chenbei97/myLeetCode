/*** 
 * @Author: chenbei
 * @Date: 2022-05-15 17:47:28
 * @LastEditTime: 2022-05-16 19:25:34
 * @Description: bilateral_filter.cpp
 * @FilePath: \myLeetCode\myPleasure\myOpencv\cv_code_test-2.0A\src\bilateral_filter.cpp
 * @Signature: A boy without dreams
 */
#include "../include/bilateral_filter.h"
/**
 * Project2: 使用双边滤波处理给定图像
 * 要求： 
 *  1） 输入 ker_radius 为滤波内核半径，因为内核大小为正奇数，内核直径为 (2*ker_radius+1)
 *  2） 扩充边界的类型使用复制法，即外插的类型使用 BORDER_REPLICATE，滤波实现过程不允许使用第三方库
 *  如：ker_radius=1 时    矩阵输入：           复制法结果:
 *                                      1   1   2   3   3
 *                      1   2   3       1   1   2   3   3
 *                      4   5   6       4   4   5   6   6
 *                      7   8   9       7   7   8   9   9
 *                                      7   7   8   9   9
 *  3） 计算过程不可直接使用第三方库
 *  4） 除计算过程外，图像读取、显示、输出可使用第三方库
 *  5） 求取过程思路可在注释中说明
 * 输入： 图像路径名            in_img_name
 *       滤波后图像路径名       out_img_name
 *       内核半径              ker_radius
 *       颜色空间滤波器的sigma值 sigma_color
 *       坐标空间滤波器的sigma值 sigma_space
 * 输出： 生成滤波后图片
 * */
void bilateral_filter(const char* in_img_name, const char* out_img_name, 
                      const int ker_radius, const float sigma_color, const float sigma_space)
{
    Mat src = imread(in_img_name);
    Mat temp; // 用于计算的临时对象
    CV_Assert(src.channels() == 3); // 假设是三通道图像

    // 1.计算空间模板系数和颜色模板系数
    double space_coeff = -0.5 / ((double)sigma_space * (double)sigma_space);
    double color_coeff = -0.5 / ((double)sigma_color * (double)sigma_color);
    
    // 使用赋值法填充边界,到图像的上、下、左和右边界距离均为核半径ker_radius
    // 注：这里手动实现copyMakeBorder函数对我确实有些难度,不知道怎么去做,我想了一个自己的思路
    // 如果是int[rows][cols]的二维数组,填充边界,可以先构建一个int[rows+2*ker_radius][cols+2*ker_radius]的二维数组
    // 之后使用循环填充边界位置即可,例如填充左边界时,行循环条件为0<i<rows+2*ker_radius,列循环条件为0<j<ker_radius
    // 左边界填充值时,要填充的值为当前元素的列索引+ker_radius,行索引不变,右、上、下同理
    // 填充中心位置也利用循环,行循环条件为ker_radius<i<rows+ker_radius,列循环条件为ker_radius<j<ker_radius+cols
    copyMakeBorder(src, temp, ker_radius, ker_radius, ker_radius, ker_radius, BORDER_REPLICATE);
    
    // 2. 用于预存放的颜色权重、空间权重和模板窗口坐标的数组
    double _color_weight[3 * 256]; // 存放差值的平方,最多3*256
    double _space_weight[50]; // 空间模板权重
    int  _space_ofs[50]; // 模板窗口的坐标,预留长度50,可供核半径为4时使用
    // 定义指向数组的指针便于操作
    double* color_weight = &_color_weight[0];
    double* space_weight = &_space_weight[0];
    int* space_ofs = &_space_ofs[0];

    for (int i = 0; i < 3 * 256; i++) 
        color_weight[i] = exp((double)i * (double)i * color_coeff); // 对颜色权重进行赋值,依据高斯公式e^(σ*x^2)
    
    // 3.生成空间模板
    int maxk = 0; // 用于记录最大的空间模板权重
    // 二维高斯公式
    for (int i = -ker_radius; i <= ker_radius; i++) // [-ker_radius,ker_radius]
    {
        for (int j = -ker_radius; j <= ker_radius; j++) // [-ker_radius,ker_radius]
        {
            double r = sqrt(i * i + j * j); // 计算半径
            if (r > ker_radius)  // 如果半径大于了核半径就跳过不处理
                continue;
            space_weight[maxk] = exp(r * r * space_coeff); // 计算模板系数
            space_ofs[maxk++] = i * temp.step + j * 3; // 存放模板的位置，和模板系数相对应
        }
    }
    // 4.滤波过程,就是让核与图像进行卷积,元素对应相乘求和,用于归一化
    Mat dst = Mat(temp.size(), temp.type()); // 创建目标图像
    for (int i = 0; i < src.rows; i++)
    {
        // 定义指向数据的行指针
        const uchar* sptr = temp.data + (i + ker_radius) * temp.step + ker_radius * src.channels();
        uchar* dptr = dst.data + i * dst.step; // 目标数据指针
        for (int j = 0; j < src.cols * 3; j += 3) // 连续存放,只需要多遍历3次即可
            {
                double sum_b = 0, sum_g = 0, sum_r = 0, wsum = 0;  // 用于计算不同沟道总的像素值
                int b0 = sptr[j]; // 不同沟道的像素值
                int g0 = sptr[j + 1];
                int r0 = sptr[j + 2];
                for (int k = 0; k < maxk; k++) // 遍历每个模板
                {
                    const uchar* sptr_k = sptr + j + space_ofs[k];
                    int b = sptr_k[0];
                    int g = sptr_k[1];
                    int r = sptr_k[2];
                    double w = space_weight[k] * color_weight[abs(b - b0) + abs(g - g0) + abs(r - r0)];
                    sum_b += b * w; // 累加求和操作
                    sum_g += g * w;
                    sum_r += r * w;
                    wsum += w; // 权重的累计求和
                }
                wsum = 1.0f / wsum; // 归一化
                b0 = cvRound(sum_b * wsum); // 向上取整
                g0 = cvRound(sum_g * wsum);
                r0 = cvRound(sum_r * wsum);
                dptr[j] = (uchar)b0; // 记得转为uchar类型
                dptr[j + 1] = (uchar)g0;
                dptr[j + 2] = (uchar)r0;
            }
    }
    // 保存dst图片
    cv::imwrite(out_img_name, dst);
}