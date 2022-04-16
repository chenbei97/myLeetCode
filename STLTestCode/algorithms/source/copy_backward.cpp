/*
 * @Author: chenbei
 * @Date: 2022-04-16 09:32:11
 * @LastEditTime: 2022-04-16 10:07:36
 * @FilePath: \myLeetCode\STLTestCode\algorithms\c++11\source\copy_backward.cpp
 * @Description: test copy_backward.cpp
 * @Signature: A boy without dreams
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>
using namespace std;
int main()
{
    // 注意要放在dst的end,因为是从src的[begin,end)开始复制到dst的[end-(begin-end),end)
    // 例如[1,2,3,4,5]复制前3个到[0,0,0,0,0]其实是[0,0,1,2,3]
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2(5,0);
    copy_backward(v1.begin(),v1.begin()+3,v2.end());
    ostream_iterator<int> out(cout," ");
    copy(v2.begin(),v2.end(),out);// 0 0 1 2 3 
    cout<<endl;

    // 把v1的[2,3,4]元素复制到了v2的[,3)的范围内,也就是[2,3,4,2,3],原来的1被覆盖,2,3没有
    copy_backward(v1.begin()+1,v1.begin()+4,v2.end()-2);
    copy(v2.begin(),v2.end(),out);// 2,3,4,2,3
    cout<<endl;

    // 但是如果使用默认情况,复制的结构不会有区别
    copy(v1.begin(),v1.end(),v2.begin());
    copy(v2.begin(),v2.end(),out);// 1 2 3 4 5
    cout<<endl;
    copy_backward(v1.begin(),v1.end(),v2.end()); 
    copy(v2.begin(),v2.end(),out);// 1 2 3 4 5
    cout<<endl;

    // 现在再来比较下copy和copy_backward的速度
    vector<int> src;
    int i = 0;
    while (i++<100000000){
        src.push_back(i);
    }
    //copy(src.begin(),src.begin()+1000,ostream_iterator<int>(cout," "));
    //cout<<endl;
    vector<int> dst1(src.size());
    vector<int> dst2(src.size());
    time_t start = clock();
    copy_backward(src.begin(),src.end(),dst1.end());
    time_t finish = clock();
    printf("copy_backward() copy 10000,0000 elements cost time = %f \n",(double)(finish-start)/CLOCKS_PER_SEC);//0.04s
    
    start = clock();
    copy(src.begin(),src.end(),dst2.begin());
    finish = clock();
    printf("copy() copy 10000,0000 elements cost time = %f \n",(double)(finish-start)/CLOCKS_PER_SEC);//0.049s
    return 0;
}