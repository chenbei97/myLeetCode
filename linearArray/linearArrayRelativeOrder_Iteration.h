#ifndef linearArrayRelativeOrderIteration_
#define linearArrayRelativeOrderIteration_
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class linearArrayRelativeOrderIteration{
    public:
        vector<int> relativeSort(vector<int>&arr1,vector<int>&arr2){
            int upper = *max_element(arr1.begin(), arr1.end()); // 优化空间利用率
            vector<int> frequency(upper + 1); //所有可能的元素都留个位置,[0,1000]
            for (int x: arr1) {
                ++frequency[x]; // 每个数出现1次就+1次
            }
            vector<int> ans;
            for (int x: arr2) {// 把arr1共有的元素先加进答案,按照arr2的顺序添加
                for (int i = 0; i < frequency[x]; ++i) { // arr1有几次重复就添加几次
                    ans.push_back(x); // 有多少个就加多少
                }
                frequency[x] = 0; // 记得清零,后边用于继续判断,这样frequency只有arr2没出现的元素不为0
            }
            for (int x = 0; x <= upper; ++x) { //遍历frequency,因为frequency记录的就是从小到大元素出现的次数
                for (int i = 0; i < frequency[x]; ++i) {
                    ans.push_back(x); //把arr1中不与arr2重复的元素添加进答案,也算按照升序进的
                }
            }
            return ans; // 那么答案就是计数排序后的结果
        }
};
void _linearArray_relativeOrder_iteration(){
    linearArrayRelativeOrderIteration solution;
    vector<int>arr1={0,2,3,1,3,2,4,6,7,9,2,19};
    vector<int>arr2={2,1,4,3,9,6};
    solution.relativeSort(arr1,arr2);
    cout<<"iteration=>\n";
    for (auto num:arr1){
        cout<<num<<" ";
    }
    cout<<"\n";
}
#endif // !linearArrayRelativeOrderIteration