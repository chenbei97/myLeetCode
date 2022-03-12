from typing import List
class linearArrayNearbyDuplicatesHashTable:
    def nearbyDuplicates(self,nums:List,k:int)->bool:
        d = dict()
        for idx,val in enumerate(nums): # val in d也可以
            if val in d.keys()and d[val] and idx-d[val] <=k:
                return True
            d[val] = idx
            print(d)
        return False
if __name__ == '__main__':
    a = [0,1,3,1,6,7,1]
    solution = linearArrayNearbyDuplicatesHashTable()
    print(solution.nearbyDuplicates(a,1))
    print(solution.nearbyDuplicates(a,2))