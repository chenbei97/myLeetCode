/*
 * @Author: chenbei
 * @Date: 2022-04-17 09:27:57
 * @LastEditTime: 2022-04-17 09:31:47
 * @FilePath: \myLeetCode\STLTestCode\ecm1_0_pointer3d_c++_hierarchy.cpp
 * @Description: ecm1_0_pointer3d_c++_hierarchy.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode
g++ -o ecm1_0_pointer3d_c++_hierarchy ecm1_0_pointer3d_c++_hierarchy.cpp 
.\ecm1_0_pointer3d_c++_hierarchy.exe
*/
#include <iostream>
using namespace std;
class Point{
    public:
        Point(float x = 0.0):x(x){}
        void setX(float x){
            this->x = x;
        }
        float getX(){
            return x;
        }
    protected:// 声明保护可被继承
        float x;
};
class Point2D:public Point{
    public:
        // 可以使用基类初始化基类成员,派生类初始化派生类成员
        Point2D(float x = 0.0,float y = 0.0):Point(x),y(y){}
        void setY(float y){
            this->y = y;
        }
        float getY(){
            return y;
        }
    protected: // 声明保护可被继承
        float y;
};
class Point3D:public Point2D{
    public:
        // 可以使用基类初始化基类成员,派生类初始化派生类成员
        Point3D(float x = 0.0,float y = 0.0,float z = 0.0):Point2D(x,y),z(z){}
        void setZ(float z){
            this->z = z;
        }
        float getZ(){
            return z;
        }
    protected:// 声明保护可被继承
        float z;
};
int main()
{
    Point3D p(1.0,2.0,3.0);
    cout << p.getX() << " " << p.getY() << " " << p.getZ() << endl;
    return 0;
}