/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 14:57:12
 * @LastEditTime: 2022-05-24 15:02:43
 * @Description: rand.cpp
 * @FilePath: \myLeetCode\STLTestCode\random\source\rand.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> // include time
using namespace std;
int main()
{
    /*
        包含于头文件<cstdlib>,返回 ​0​ 与 RAND_MAX （包含 0 与 RAND_MAX ）的随机数
        std::srand() 播种 rand() 所用的伪随机数生成器
        任何到 srand() 的调用前使用 rand() ，则 rand() 表现如同它以 srand(1) 播种
        每次以 srand() 播种 rand() ，它必须在后续调用上产生相同的值数列
        不保证生成的随机数列质量，过去，一些 rand() 在随机性、分布和产生的序列周期上有严重缺陷
        对于严肃的随机数生成需求不推荐 rand() 。推荐用 C++11 的随机数生成设施替换 rand() 
    */
    // 示例
    std::srand(std::time(nullptr)); // 以当前时间为随机生成器的种子
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // 扔 6 面色子 20 次
    for (int n = 0; n != 20; ++n) {
        int x = 7;
        while(x > 6) 
            x = 1 + std::rand() / ((RAND_MAX + 1u) / 6);  // 注意： 1 + rand() % 6 有偏差！
        std::cout << x << ' ';
    }
    return 0;
}
/*
g++ -o ..\output\rand_g++ rand.cpp
..\output\rand_g++.exe
cl /Fo"..\output\rand_cl" /Fe"..\output\rand_cl.exe" /std:c++latest ".\rand.cpp"
..\output\rand_cl.exe
*/