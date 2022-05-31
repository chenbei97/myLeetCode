/*
 * @Author: chenbei
 * @Date: 2022-04-17 09:03:28
 * @LastEditTime: 2022-04-17 09:27:35
 * @FilePath: \myLeetCode\STLTestCode\ecm1_0_pointer3d_c++_adt.cpp
 * @Description: ecm1_0_pointer3d_c++_adt.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode
g++ -o ecm1_0_pointer3d_c++_adt ecm1_0_pointer3d_c++_adt.cpp 
.\ecm1_0_pointer3d_c++_adt.exe
*/
#include <iostream>
using namespace std;
class Point3D{
    public:
        Point3D(float x = 0.0, float y = 0.0, float z = 0.0)
            :x(x),y(y),z(z){}
        float getX() const { return this->x; }
        float getY() const { return this->y; }
        float getZ() const { return this->z; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
        void setZ(float z) { this->z = z; }

    private:
        float x;
        float y;
        float z;
};
inline ostream& operator<<(ostream& os, const Point3D &pd) {
    cout<<"x = "<<pd.getX()<<" y = "<<pd.getY()<<" z = "<<pd.getZ()<<endl;
    return os;
}
int main()
{
    Point3D pd(1.0,2.0,3.0);
    cout<<pd<<endl;
    return 0;
}