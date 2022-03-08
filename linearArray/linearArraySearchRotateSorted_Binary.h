#ifndef linearArraySearchRotateSortedBinary_
#define linearArraySearchRotateSortedBinary_
#include <vector>
#include <iostream>
using namespace std;
class linearArraySearchRotateSortedBinary{
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            if (n<1) return -1;
            if (n==1) return nums[0]==target?1:0;
            int left=0,right=n-1;
            while(left<=right){ // 数组长度奇数的时候会相等
                int mid = (left+right)/2; // 中间位置
                if (nums[mid]==target) return mid; // 直接找到就返回位置
                if (nums[0]<=nums[mid]){ // [0,mid]内可以保证是升序的,升序条件才能二分
                    if(nums[0]<=target && target<nums[mid]){ // 且target还在[0,mid-1]的区间内
                        right = mid-1; // 调整右区间,缩小二分范围至[0,mid-1]
                    }
                    else{ // 否则target不在区间[0,mid-1]内,也不是nums[mid],在[mid+1,n-1]范围
                        left = mid+1; // 调整左区间,缩小二分范围至[mid+1,n-1]
                    }
                }
                else{ // [mid+1,n-1]内可以保证是升序的,升序条件才能二分
                    if (nums[mid+1]<= target && target<=nums[n-1]) // target确实在[mid+1,n-1]区间
                        left = mid+1; // 调整左区间,缩小二分范围至[mid+1,n-1]
                    else right = mid-1; // 否则target在[0,mid-1]区间,调整右区间,缩小二分范围至[0,mid-1]
                }
            }
            return -1; //没找到返回-1
        }
};
void _linearArray_searchRotateSorted_binary(){
    linearArraySearchRotateSortedBinary solution;
    vector<int> nums={7,8,9,10,0,1,2,3,4,5,6};
    int idx = solution.search(nums,1);
    cout<<"binarySearch => the target(1)'s idx is "<<idx<<endl;
}
#endif // !linearArraySearchRotateSortedBinary_