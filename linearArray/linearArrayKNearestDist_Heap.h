/*** 
 * @Author: chenbei
 * @Date: 2022-04-14 15:47:50
 * @LastEditTime: 2022-04-14 16:09:27
 * @Description: linearArrayKNearestDist_Heap.h
 * @FilePath: \myLeetCode\linearArray\linearArrayKNearestDist_Heap.h
 * @Signature: A boy without dreams
 */
#ifndef linearArrayKNearestDistHeap_
#define linearArrayKNearestDistHeap_
#include <iostream>
#include <vector>
#include <iterator>
#include <queue> // include priority_queue
#include <tuple>
using namespace std;
class linearArrayKNearestDistHeap{
    public:
        vector<vector<int>> kNearestDist(vector<vector<int>>&points,int k){
            priority_queue<tuple<int,int>> q; // 大根堆
            for (int i = 0; i < k; ++i) {
                // 存储前k个距离平方和编号,会自动按照大根堆的定义插入,顶点是最大的距离值
                q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            }
            int n = points.size(); // n个点
            for (int i = k; i < n; ++i) {
                // 从第k+1个点
                int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
                // 取出元素可以使用get函数也可以使用tie函数解包操作
                // https://www.jb51.net/article/191040.htm
                if (dist < std::get<0>(q.top())) { // 比大根堆最大的值小说明有整体更小的k个
                    q.pop(); // 最大的距离点那个不要
                    q.emplace(dist, i); // 插入大根堆
                }
            }

            vector<vector<int>> ans;
            while (!q.empty()) { // 把大根堆的这些点转移到vector返回
                ans.push_back(points[std::get<1>(q.top())]); // 注意取出编号second,取出元素是points[seconds]
                q.pop();
            }
            return ans;
        }
};
void _linearArray_kNearestDist_heap(){
    linearArrayKNearestDistHeap solution;
    vector<vector<int>> nums = {{3,4},{6,8},{1,1},{-3,4},{5,5},{7,9},{4,4}};
    auto ans = solution.kNearestDist(nums,3); // 最近的3个{3,4},{1,1},{-3,4}
    ostream_iterator<int> os(cout," ");
    cout<<"get k nearest distance by heap as follows\n";
    for (auto& vec:ans){
        copy(vec.begin(),vec.end(),os);
        cout<<"\n";
    }
}
#endif//!linearArrayKNearestDistHeap_