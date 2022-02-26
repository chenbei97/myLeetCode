from typing import List
class linearArrayRemoveDuplicatesDoublePointers:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 1 : return 0
        n = len(nums)
        nums.sort()
        fast,slow = 1,1
        while fast < n:
            if (nums[fast] != nums[fast-1]):
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow
if __name__ == '__main__':
    index = 0
    a = []
    for i in range(200):
        a.append(index)
        if (i+1) % 7 == 0:
            index +=1
    for i in range(200):
        print(a[i],end= " ")
        if (i+1) % 10 == 0 :
            print()
    solution = linearArrayRemoveDuplicatesDoublePointers()
    ans = solution.removeDuplicates(a)
    # a可以被改变
    for i in range(200):
        print(a[i],end= " ")
        if (i+1) % 10 == 0 :
            print()
    print("the ans is ",ans)
    for i in range(ans):
        print(a[i],end=" ")