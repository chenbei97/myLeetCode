/*
 * @Author: chenbei
 * @Date: 2022-04-30 16:55:32
 * @LastEditTime: 2022-04-30 20:21:45
 * @FilePath: \myLeetCode\cmakeExercises\hello_cmake\test_cmake.cpp
 * @Description: test for cmake
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <string>
#include <any>
using namespace std;
int main(int argc,char**argv)
{
    cout<<"hello cmake!"<<endl;
    // 打印终端命令字符串
    // for (int i = 0; i<argc;++i){
    //     cout<<argv[i]<<" ";
    // }
    // cout<<endl;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for (auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<any> v2;
    v2.push_back(1);
    v2.push_back(2.2);
    v2.push_back("hello");
    // 利用any_cast+if判断来遍历不同类型的元素
    for (auto i:v2){
        if (i.type() == typeid(int)){
            cout<<any_cast<int>(i)<<" ";
        }else if (i.type() == typeid(double)){
            cout<<any_cast<double>(i)<<" ";
        }else if (i.type() == typeid(const char*)){ // string会出现问题
            cout<<any_cast<const char*>(i)<<" ";
        }
    }
    cout<<endl;
    return 0;
}
