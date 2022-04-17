/*
 * @Author: chenbei
 * @Date: 2022-04-17 09:34:19
 * @LastEditTime: 2022-04-17 09:58:27
 * @FilePath: \myLeetCode\STLTestCode\ecm1_0_pointer3d_c++_template.cpp
 * @Description: ecm1_0_pointer3d_c++_template.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode
g++ -o ecm1_0_pointer3d_c++_template ecm1_0_pointer3d_c++_template.cpp 
.\ecm1_0_pointer3d_c++_template.exe
*/
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
template<class valueType,int dim> // 允许模板参数化
class Point{
    public:
        Point(){}
        Point(valueType coords[dim]){ // 传入的也是数组
            for(int idx = 0;idx < dim;idx++){
                this->coords[idx] = coords[idx];
            }
        }

        // 此版本允许外部对实例化对象赋值
        valueType& operator[](int idx){ // 重载[]运算符 non_const版本
            // 不要使用static_assert,因为idx步数常量表达式
            assert(idx >= 0 && idx < dim); // 不能超过坐标范围
            return coords[idx];
        }

        // 此版本是为了得到属性值
        valueType operator[](int idx)const{ // 重载[]运算符 const版本
            assert(idx >= 0 && idx < dim); // 不能超过坐标范围
            return coords[idx];
        }

    private:
        valueType coords[dim]; // 一个d维数组用来存储valueType类型的数据
};
template<class ValueType,int dim>
inline ostream& operator<<(ostream& os,const Point<ValueType,dim>& p){
    for(int idx = 0;idx < dim;idx++){
        os << p[idx] << " ";
    }
    return os;
}
int main()
{
    Point<int,5> p1;
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 3;
    p1[3] = 4;
    p1[4] = 5;
    cout << p1 << endl;
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    const Point<int,5> p2(p);
    cout << p2 << endl;
    return 0;
}