/*** 
 * @Author: chenbei
 * @Date: 2022-04-18 15:33:13
 * @LastEditTime: 2022-04-18 16:05:38
 * @Description: for_each_n.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\for_each.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o for_each for_each.cpp
.\for_each.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 遍历元素,把某种策略应用在每个元素上
    vector<int> src = {-5,-4,4,7,8};
    int i=0,j=0;
    // 找到>0和<0的数字数量
    auto it = for_each(src.begin(),src.end(),[&i,&j](int x){
        if (x>0) ++i;
        else ++j;
        cout<<"the num of elements < 0 = "<<j<<" and > 0 = "<<i<<endl;});
    int sum = 0;
    for_each(src.begin(),src.end(),[&sum](int x){sum += x;});
    cout<<"vector's sum = "<<sum<<endl;
    // 遍历整个容器
    for_each(src.begin(),src.end(),[](int x){printf("%d ",x);});
    cout<<"\n";
    return 0;
}