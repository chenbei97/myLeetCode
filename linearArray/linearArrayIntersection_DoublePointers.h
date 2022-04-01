/*** 
 * @Author: chenbei
 * @Date: 2022-04-01 08:52:31
 * @LastEditTime: 2022-04-01 09:15:45
 * @Description: linearArrayIntersection_DoublePointers.h
 * @FilePath: \myLeetCode\linearArray\linearArrayIntersection_DoublePointers.h
 * @A boy without dreams
 */
#ifndef linearArrayIntersectionDoublePointers_
#define linearArrayIntersectionDoublePointers_
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class linearArrayIntersectionDoublePointers{
    public:
        vector<int> intersect(vector<int>&nums1,vector<int>&nums2){
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            vector<int> ans;
            int p1=0,p2=0;
            while (p1<nums1.size() && p2<nums2.size()){
                if (nums1[p1] < nums2[p2])
                    ++p1;
                else if(nums1[p1] > nums2[p2])
                    ++p2;
                else{
                    ans.push_back(nums1[p1]);
                    ++p1;
                    ++p2;
                }
            }
            return ans;
        }
};
void _linearArray_intersection_doublePointers(){
    linearArrayIntersectionDoublePointers solution;
    vector<int> nums1 = {9,4,9,8,4};
    vector<int> nums2 = {4,9,5};
    auto ans = solution.intersect(nums1,nums2);
    ostream_iterator<int> os(cout," ");
    copy(ans.begin(),ans.end(),os);
    cout<<"\n";
}
#endif//!linearArrayIntersectionDoublePointers_