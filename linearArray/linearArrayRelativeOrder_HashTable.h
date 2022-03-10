#ifndef linearArrayRelativeOrderHashTable_
#define linearArrayRelativeOrderHashTable_
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class linearArrayRelativeOrderHashTable{
    public:
        vector<int> relativeSort(vector<int>&arr1,vector<int>&arr2){
            unordered_map<int,int> m;
            for(int i=0;i<arr2.size();i++){
                m[arr2[i]] = i;
            }
            int n = arr1.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(m.count(arr1[i]) && m.count(arr1[j])){//2个元素都存在于arr2
                        if (m[arr1[i]]>m[arr1[j]]){//按照原本的次序比较
                            swap(arr1[i],arr1[j]);
                        }
                    }
                    else if (!m.count(arr1[i]) && !m.count(arr1[j])){// 2个元素都不存在于arr2
                        if (arr1[i]>arr1[j]) // 按照实际大小比较
                            swap(arr1[i],arr1[j]);
                    }
                    else{
                        if (m.count(arr1[j])){ // 如果x在arr2,y不在不动
                            swap(arr1[i],arr1[j]); // x不在,y在arr2,交换
                        }
                    }
                }
            }
            return arr1;
        }
};
void _linearArray_relativeOrder_hashTable(){
    linearArrayRelativeOrderHashTable solution;
    vector<int>arr1={0,2,3,1,3,2,4,6,7,9,2,19};
    vector<int>arr2={2,1,4,3,9,6};
    solution.relativeSort(arr1,arr2);
    cout<<"hashTable=>\n";
    for (auto num:arr1){
        cout<<num<<" ";
    }
    cout<<"\n";
}
#endif // !linearArrayRelativeOrderHashTable