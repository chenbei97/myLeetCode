/*
 * @Author: chenbei
 * @Date: 2022-04-17 08:37:52
 * @LastEditTime: 2022-04-17 08:47:33
 * @FilePath: \myLeetCode\STLTestCode\ecm1.0_pointer3d_c.cpp
 * @Description: ecm1.0_pointer3d_c.cpp
 * @Signature: A boy without dreams
 */
#include <cstdio>
using namespace std;
typedef struct point3d{
        float x;
        float y;
        float z;
}Point3D; // 别名
void print_pd(const Point3D* pd);
int main(){
    // for c
    Point3D * pd = new Point3D();
    pd->x = 1.0;
    pd->y = 2.0;
    pd->z = 3.0;
    print_pd(pd);
    return 0;
}
void print_pd(const Point3D* pd){
    printf("%f %f %f\n", pd->x, pd->y, pd->z);
}