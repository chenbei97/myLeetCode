/*** 
 * @Author: chenbei
 * @Date: 2022-03-28 16:48:24
 * @LastEditTime: 2022-03-31 08:12:34
 * @Description: radixSort.h
 * @FilePath: \myLeetCode\coreAlgorithms\radixSort.h
 * @A boy without dreams
 */
#ifndef radixSort_
#define radixSort_
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iterator> // include ostream_iterator
using namespace std;
int maxBitsOfRadix(const vector<int>&nums,int radix=10);
int whichBucket(const int&nums,int which_bit,int radix=10);
void radixSort(vector<int> &nums,int radix=10,bool reverse=false){
    // 基数排序因为要求低位到高位的数字,只适用于整数排序
    int maxbit = maxBitsOfRadix(nums,radix);//指定进制的最大位数                                                                                                       
    // cout<<"maxbit = "<<maxbit<<endl;
    for (int i = 0;i<maxbit;++i){ //从低位到高位,让数字的该位和桶的编号对应,例如6进制时低位是5,就放入buckets[5]
        vector<vector<int>> buckets(radix);//每个位都在[0,raidx-1]之间,需要radix个桶 
        for (const int &num : nums){ // 遍历每个数字
            int which_bucket = whichBucket(num,i,radix);// 找出数字在指定进制以及当前位属于的桶编号
            if (reverse)
                which_bucket = radix - 1 - which_bucket; //降序的话桶0不和数字0对应,而是与数字radix-1对应
            buckets[which_bucket].push_back(num); // 把符合条件的数字移入这个桶
        }
        nums.clear();//清空nums,把每个桶的元素放回去,用于下一次判断,继续判断高位
        for (auto &bucket:buckets){
            for(const int& num:bucket){
                nums.push_back(num);
            }
        }
    }
}
int whichBucket(const int&num, int which_bit,int radix){
        // 找出数字在指定进制以及指定位属于的进制桶编号
        int radix_n = 1;// r^0
        while (which_bit--){
            radix_n *= radix; // 计算r^n
        }
        // // (x%r^(n+1))/r^n可以计算数字x第n位的数字是多少,进而知道属于哪个桶
        // int which_bucket = (num % (radix*radix_n)) / radix_n;
        // return which_bucket;
        return num/(radix_n)%radix; // 2个方法都可以 num/(radix^which_bit)%radix
}
int maxBitsOfRadix(const vector<int>&nums,int radix){
    // 用于找到数组中最大元素在指定进制radix下的最大位数
    int maxVal = *max_element(nums.begin(),nums.end());
    int maxbit = 1;//至少1位
    int p = radix;
    while (maxVal >= p) //满radix进1,常见基数排序的进制可取2,3,4,5...10
    {
        p *= radix;//例如6进制,[0,5]可以用1位表示,[6,35]可以用6进制数10~55表示
        // 36就必须用3位即100来表示
        ++maxbit;//只要满足条件就说明进1位,初始radix=6,若num<6,则maxbit=1不变
    }
    return maxbit;
}
void _radixSort_testCode(){
    //cout<<"which bucket = "<<whichBucket(27,2,7)<<endl;
    vector<int> nums={5,4,3,2,1,0,9};// 15,4,3,322,1,0,36
    radixSort(nums,2,true);
    ostream_iterator<int> os(cout," "); 
    cout<<"radixSort => \n";
    copy(nums.begin(),nums.end(),os);
    cout<<"\n";
}
#endif // !radixSort_