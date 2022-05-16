/*** 
 * @Author: chenbei
 * @Date: 2022-05-16 10:41:32
 * @LastEditTime: 2022-05-16 10:48:01
 * @Description: union.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\union.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o union union.cpp
.\union.exe
*/
#include <iostream>
using namespace std;
union ipv4address{
    std::uint32_t address32; // 4字节,内部可以按32位解读也可以1个个字节按8位解读
    std::uint8_t address8[4]; // 共享1份内存,4个字节
};
int main(){
    union ipv4address ipv;
    cout <<"sizeof(ipv4address) = " << sizeof(ipv) << endl; // 4
    
    ipv.address8[0] = 1;
    ipv.address8[1] = 0;
    ipv.address8[2] = 0;
    ipv.address8[3] = 127;

    cout<<"The address is :";
    cout<<+ipv.address8[3]<<".";
    cout<<+ipv.address8[2]<<".";
    cout<<+ipv.address8[1]<<".";
    cout<<+ipv.address8[0]<<endl; // 127.0.0.1

    cout<<std::hex;
    cout<<"in hex "<<ipv.address32<<endl; // 0x7f000001
    return 0;
}