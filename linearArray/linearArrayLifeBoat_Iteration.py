'''
Author: chenbei
Date: 2022-04-01 15:29:01
LastEditTime: 2022-04-01 15:48:49
Description: linearArrayLifeBoat_Iteration.py
FilePath: \myLeetCode\linearArray\linearArrayLifeBoat_Iteration.py
A boy without dreams
'''
from typing import List
class linearArrayLifeBoatIteration:
    def boat(self,people:List[int],limit:int)->int:
        n = len(people)
        people.sort()
        minWeight,maxWeight=0,n-1
        boat = 0
        while minWeight<=maxWeight:
                if minWeight == maxWeight:
                    boat+=1
                    break
                if people[minWeight]+people[maxWeight]>limit:
                    boat += 1
                    maxWeight -= 1
                else :
                    boat += 1
                    maxWeight -= 1
                    minWeight += 1
        return boat
if __name__ == '__main__':
    nums = [2,1,3,9,5,6,1,4,5,7,10] # 0,1,3,0,5,6,0,-2,-5,0,10 3,5,3,4
    solution = linearArrayLifeBoatIteration()
    ans = solution.boat(nums,15)
    print(ans)