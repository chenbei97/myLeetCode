/*
 * @Author: chenbei
 * @Date: 2022-05-02 19:01:15
 * @LastEditTime: 2022-05-02 19:21:31
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\do_while.cpp
 * @Description: test do while
 * @Signature: A boy without dreams
 */
/*
g++ -o do_while do_while.cpp
./do_while
*/
#include <iostream>
using namespace std;
int main()
{
    // 使用while语句
    int m1 = 5;
    while (m1>0) 
    {
        cout << m1 << " "; // 5 4 3 2 1
        m1--;
    }
    cout << endl;
    
    // m1可以作为条件
    m1 = 5;
    while (m1--) cout << m1 << " ";
    cout << endl; // 4 3 2 1 0
    // 注意上述2个while的区别,m1--意味着此时表达式还是5
    // 但是一旦进入while语句,m1的值就会减1,所以m1从4开始
    // m1--还是1的时候依然执行,进入循环m1变成0了

    m1 = 5;
    // --m1也是一样,不过这里的表达式已经变成了4,故从4开始
    // 当--m1的值为0时,结束循环,m1最后是0
    while (--m1) cout << m1 << " ";
    cout << endl; // 4,3,2,1
    cout<< "m = " << m1 << endl; // 0

    // 现在再来看看do_while语句和上述哪个while语句一致
    m1 = 5;
    do
    {
        cout << m1 << " "; // 5 4 3 2 1
        m1--;
    } while (m1>0);
    cout << endl;
    cout <<"m = " << m1 << endl; // 0
    // 从结果来看是和while一样的,只不过do-while至少会执行一次循环体

    // 例如m1=0的时候
    m1 = 0;
    while (m1>0)
    {
        cout << m1 << " "; // 不会执行这条语句
        m1--;
    }
    cout << endl;
    m1 = 0;
    do
    {
        cout << m1 << " "; // 0,至少会执行1次m1=0
        m1--;
    } while (m1>0);
    return 0;
}