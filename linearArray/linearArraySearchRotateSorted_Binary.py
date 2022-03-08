from typing import List
class linearArraySearchRotateSortedBinary:
    def search(self,nums:List,target:int)->int:
        n = len(nums)
        if n<1:return -1
        if n==1:return 0 if target==nums[0] else -1
        left,right = 0,n-1
        while left<=right:
            mid = (left+right)//2 # 整除
            if nums[mid] == target : return mid
            if nums[0]<=nums[mid]: # [0,mid]内可以保证是升序的,升序条件才能二分
                if nums[0]<=target and target<nums[mid]: 
                    right = mid-1 # target在区间[0,mid-1]
                else: left=mid+1 # target在区间[mid+1,n-1]
            else : # [mid+1,n-1]内可以保证是升序的,升序条件才能二分
                if nums[mid+1]<=target and target<=nums[n-1]: 
                    left = mid+1 # target在区间[mid+1,n-1]
                else :right = mid-1 # target在区间[0,mid-1]
        return -1
if __name__ == '__main__':
    a = [7,8,9,10,0,-1,-2,1,2,3,4,5,6]
    solution = linearArraySearchRotateSortedBinary()
    idx = solution.search(a,1)
    print("binarySearch => the target(1)'s idx is ",idx)
