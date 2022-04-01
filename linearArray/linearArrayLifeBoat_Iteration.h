/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 15:28:56
 * @LastEditTime: 2022-04-01 15:41:06
 * @Description: linearArrayLifeBoat_Iteration.h
 * @FilePath: \myLeetCode\linearArray\linearArrayLifeBoat_Iteration.h
 * @A boy without dreams
 */
#ifndef linearArrayLifeBoatIteration_
#define linearArrayLifeBoatIteration_
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class linearArrayLifeBoatIteration{
    public:
        int boat(vector<int>&people,int limit){
            int boat = 0;
            sort(people.begin(),people.end());
            int minWeight=0,maxWeight=people.size()-1;
            while (minWeight<=maxWeight){
                if (minWeight == maxWeight){
                    ++boat;//只有1个人了直接走
                    break;
                }
                if (people[minWeight]+people[maxWeight]>limit){
                    ++boat;
                    --maxWeight;//体重大的先走
                }
                else{
                    ++boat; // 一起走
                    ++minWeight;
                    --maxWeight;
                }
            }
            return boat;
        }
};
void _linearArray_lifeBoat_iteration(){
    linearArrayLifeBoatIteration solution;
    vector<int> nums = {3,5,3,4};
    cout<<"the life boat's num is "<<solution.boat(nums,5)<<"\n";
}
#endif//!linearArrayLifeBoatIteration_