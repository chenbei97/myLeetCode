#ifndef linearArrayMergeSortedArrayIteration_
#define linearArrayMergeSortedArrayIteration_
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class linearArrayMergeSortedArrayIteration{
    public:
        void mergeSortedArray(vector<int>&nums1,vector<int>&nums2){
                // 直接合并2个数组,把nums2接在nums1的尾部即可
                for(int i = 0; i< nums2.size();i++){
                    nums1.push_back(nums2[i]);
                }
                sort(nums1.begin(),nums1.end());
        }
};
void _linearArray_mergeSortedArray_iteration(){
    linearArrayMergeSortedArrayIteration solution;
    cout<<"iteration:\n";
    vector<int> v1 ={15,4,3,2};
    vector<int> v2 = {3,1,7,0};
    solution.mergeSortedArray(v1,v2);
    for(int i =0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<"\n";

}
#endif // !linearArrayMergeSortedArrayIteration_