from typing import List
class linearArrayRemoveElementDoublePointers:
     def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        left,right = 0,0
        while (right < n):
            if nums[right] != val :
                 nums[left] = nums[right]
                 left += 1
            right += 1
        return left
if __name__ == '__main__':
    a = [1,2,2,3,3,6,3,7,9,10,4,3,2,3]
    solution = linearArrayRemoveElementDoublePointers()
    size = solution.removeElement(a,3)
    for i in range(size):
        print(a[i],end=" ")
    print()