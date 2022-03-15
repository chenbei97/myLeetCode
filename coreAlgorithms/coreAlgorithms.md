<!--
 * @Author: chenbei
 * @Date: 2022-03-15 09:01:11
 * @LastEditTime: 2022-03-15 10:09:13
 * @LastEditors: chenbei
 * @Description: some basic and core algorithms
 * @FilePath: \myLeetCode\coreAlgorithms\coreAlgorithms.md
-->

## 二分查找

​		 查找一个数组的指定元素，如果存在该元素就返回下标，如果不存在就返回-1
        时间复杂度O(logn),数组要求事先是有序的
        从0和n-1开始,反复取中间坐标值,比较target和nums[mid]的大小关系调整left,right的位置
        程序结束条件是left>right为止
