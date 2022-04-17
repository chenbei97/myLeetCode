/*
 * @Author: chenbei
 * @Date: 2022-04-17 08:37:52
 * @LastEditTime: 2022-04-17 09:02:44
 * @FilePath: \myLeetCode\STLTestCode\ecm1_0_pointer3d_c.cpp
 * @Description: ecm1.0_pointer3d_c.cpp
 * @Signature: A boy without dreams
 */
#include <cstdio>
#define Point3DPrint( pd ) printf("(%g, %g, %g )",pd->x,pd->y,pd->z);
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

    // 使用函数,也可以使用宏
    printf("by function =>\n");
    print_pd(pd);
    printf("by define =>\n");
    Point3DPrint(pd);
    return 0;
}
void print_pd(const Point3D* pd){
    printf("%f %f %f\n", pd->x, pd->y, pd->z);
}