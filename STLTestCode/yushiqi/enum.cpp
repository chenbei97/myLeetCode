/*** 
 * @Author: chenbei
 * @Date: 2022-05-16 10:57:23
 * @LastEditTime: 2022-05-16 11:12:01
 * @Description: enum.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\enum.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode\\yushiqi
g++ -o enum enum.cpp
./enum
*/
#include <iostream>
using namespace std;
enum color {WHITE,BLACK,RED,GREEN,YELLOW,PINK,BLUE,ORANGE};
enum datatype {TYPE_INT8=1,TYPE_INT16=2,TYPE_INT32=4,TYPE_INT64=8};
struct Point{
    enum datatype type; 
    union {
        std::int8_t data8[3];
        std::int16_t data16[3];
        std::int32_t data32[3];
        std::int64_t data64[3];
    };
};
size_t datawidth(struct Point pt){
    return size_t(pt.type) * 3;//这里的size_t(pt.type)是一个隐式转换
}
int64_t l1borm(struct Point pt){
    int64_t result = 0;
    switch (pt.type)
    {
        case (TYPE_INT8):
            result = abs(pt.data8[0]) + abs(pt.data8[1]) + abs(pt.data8[2]);
            break;
        case (TYPE_INT16):
            result = abs(pt.data16[0]) + abs(pt.data16[1]) + abs(pt.data16[2]);
            break;
        case (TYPE_INT32):
            result = abs(pt.data32[0]) + abs(pt.data32[1]) + abs(pt.data32[2]);
            break;
        case (TYPE_INT64):
            result = abs(pt.data64[0]) + abs(pt.data64[1]) + abs(pt.data64[2]);
            break;
    }
    return result;
}
int main()
{
    enum color pen_color = RED;
    pen_color = color(3);
    cout << "pen_color = " << pen_color << endl; // 3
    int color_index = pen_color; // 提升为int
    cout << "++color_index = " << ++color_index << endl; // 4

    struct Point pt0 = {TYPE_INT8,{1,3,8}};
    struct Point pt1 = {.type=TYPE_INT32,.data32={1,2,3}};
    struct Point pt2 = {.type=TYPE_INT64,.data64={-1,-3,-3}};
    cout <<"pt0 data width = " << datawidth(pt0) << endl; // 3
    cout<<"pt1 data width = "<<datawidth(pt1)<<endl; // 12
    cout<<"pt2 data width = "<<datawidth(pt2)<<endl; // 24
    
    // 取绝对值相加
    cout<<"l1borm(pt0) = "<<l1borm(pt0)<<endl; // 12
    cout<<"l1borm(pt1) = "<<l1borm(pt1)<<endl; // 6
    cout<<"l1borm(pt2) = "<<l1borm(pt2)<<endl; // 7
    return 0;
}