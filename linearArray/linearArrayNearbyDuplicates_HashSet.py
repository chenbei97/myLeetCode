from typing import List
class linearArrayNearbyDuplicatesHashSet:
    def nearbyDuplicates(self,nums:List,k:int)->bool:
        s = set()
        for idx,val in enumerate(nums):
            if idx > k:
                s.remove(nums[idx-k-1])
            if val in s:
                return True
            s.add(val)
        return False
if __name__ == '__main__':
    a = [0,1,3,1,6,7,1]
    solution = linearArrayNearbyDuplicatesHashSet()
    print(solution.nearbyDuplicates(a,1))
    print(solution.nearbyDuplicates(a,2))