/*
 * @Author: chenbei
 * @Date: 2022-06-21 08:22:09
 * @LastEditTime: 2022-06-21 14:58:58
 * @FilePath: \\myLeetCode\\STLTestCode\\struct_memory_align.cpp
 * @Description: 
 * @Signature: A boy without dreams
 */
#pragma pack(2)
#include <stdio.h>
void test_struct_size1();
void test_struct_size2();
int main()
{
    printf("sizeof(char) = %d, sizeof(int) = %d\n",
        sizeof(char),sizeof(int)); // 1 and 4字节
    test_struct_size1();
    test_struct_size2();
    struct STU{
        int a;
        char b;
    }ss;
    // &a(char) = 0000002d445ff6aa, &b(int) = 0000002d445ff6ac char低位,int高位
    // printf("&a(char) = %p, &b(int) = %p",&ss.a,&ss.b);
    // &a(int) = 000000fbdf3ffb2a, &b(char) = 000000fbdf3ffb2e int低位,char高位
    printf("&a(int) = %p, &b(char) = %p",&ss.a,&ss.b);
    return -1;
    int a1=1,a2=2,a3=3;
    int *a[]={&a1,&a2,&a3};
    int **p1 = a;
    int *(*p2)[3] = &a;
}
/*
g++ struct_memory_align.cpp -o struct_memory_align
.\struct_memory_align.exe
*/
void test_struct_size1(){
    /*
        不加#pragma pack(2)的输出结果:
            sizeof(stu1) = 8
            sizeof(stu2) = 16
            sizeof(stu3) = 8
            sizeof(stu4) = 12
            sizeof(stu5) = 8
        加#pragma pack(2)的输出结果:
            sizeof(stu1) = 6 // char b占据2字节,1字节空,int a占据4字节
            sizeof(stu2) = 12 // char b占据2字节,int a占据4字节,STU1 stu占据6字节
            sizeof(stu3) = 6 // char b和char c占据2字节,int a占据4字节
            sizeof(stu4) = 8 // char b占据2字节，int a占据4字节,char c占据2字节
            sizeof(stu5) = 6 // int a占据4字节,char b和char c占据2字节
    */

    struct STU1{
        char b = 'b'; // 1字节,3字节空
        int a = 1; // 4字节
    } stu1;
    printf("sizeof(stu1) = %d\n",sizeof(stu1)); // 8字节而非5字节
    struct STU2{
        char b = 'b'; // 1字节,3字节空
        int a = 1; // 4字节
        STU1 stu; // 8字节
    } stu2;
    printf("sizeof(stu2) = %d\n",sizeof(stu2)); // 16字节
    struct STU3{
        int a = 1; // 4字节
        char b = 'b'; // 1字节
        char c = 'c'; // 1字节
    } stu3;
    printf("sizeof(stu3) = %d\n",sizeof(stu3)); // 8字节
    struct STU4{
        char b = 'b'; // 1字节，3字节空
        int a = 1; // 4字节
        char c = 'c'; // 1字节,3字节空
    } stu4;
    printf("sizeof(stu4) = %d\n",sizeof(stu4)); // 12字节
    struct STU5{
        char b = 'b'; // 1字节
        char c = 'c'; // 1字节,2字节空
        int a = 1; // 4字节
    } stu5;
    printf("sizeof(stu5) = %d\n",sizeof(stu5)); // 8字节
}
void test_struct_size2(){
    /*
        某次输出结果如下:
            &stu1.b = 0000006e5a9ffd6c &stu1.a = 0000006e5a9ffd68 &stu1 = 0000006e5a9ffd68
            sizeof(stu1) = 8
            char,int结构,地址依次是d6c,d68,d68->d6c(int4字节),d6c(char1+3空字节),共分配8字节
            &stu2.b = 0000006e5a9ffd54 &stu2.a = 0000006e5a9ffd50 &stu2.stu = 0000006e5a9ffd58 &stu2 = 0000006e5a9ffd50
            sizeof(stu2) = 16
            char,int,stu1结构地址依次是d50,d54,d58,d50->d54(int4字节),d54->d68(char1+3空字节),stu1(8字节),共分配16字节
            &stu3.a = 0000006e5a9ffd48 &stu3.b = 0000006e5a9ffd4c &stu3.c = 0000006e5a9ffd4d &stu3 = 0000006e5a9ffd48
            sizeof(stu3) = 8
            int,char,char结构,地址依次是d48,d4c,d4d,d48->d4c(int4字节),d4c->d4d(char1字节)+d4d(char1+2空字节),共8字节
            &stu4.b = 0000006e5a9ffd30 &stu4.a = 0000006e5a9ffd34 &stu4.c = 0000006e5a9ffd38 &stu4 = 0000006e5a9ffd30
            sizeof(stu4) = 16
            char,int,char结构,地址依次是d30,d34,d38,d30->d34(char1+3空字节),d34->d38(int4字节),d38(char1+7空字节),共16字节
            &stu5.b = 0000006e5a9ffd28 &stu5.c = 0000006e5a9ffd29 &stu5.a = 0000006e5a9ffd2c &stu5 = 0000006e5a9ffd28
            sizeof(stu5) = 8
            char,char,int结构,地址依次是d28,d29,d2c,d28->d29(char1字节)+d29(char1+2空字节),d2c(int4字节),共8字节

        如果还结合了#pragma pack(2),略去结构体地址,某次输出结果如下
            &stu1.b = 0000004538fffcda &stu1.a = 0000004538fffcd8
            sizeof(stu1) = 8 
            &stu2.b = 0000004538fffcc2 &stu2.a = 0000004538fffcc0 &stu2.stu = 0000004538fffcc6
            sizeof(stu2) = 16 
            &stu3.a = 0000004538fffcb8 &stu3.b = 0000004538fffcbc &stu3.c = 0000004538fffcbd
            sizeof(stu3) = 8
            &stu4.b = 0000004538fffcb0 &stu4.a = 0000004538fffcb2 &stu4.c = 0000004538fffcb6
            sizeof(stu4) = 8
            &stu5.b = 0000004538fffca8 &stu5.c = 0000004538fffca9 &stu5.a = 0000004538fffcaa
            sizeof(stu5) = 8
    */
    printf("-----------------------------------\n");
    struct __attribute__((aligned(8)))STU1{
        char b = 'b'; 
        int a = 1;  
    } stu1;
    printf("&stu1.b = %p &stu1.a = %p &stu1 = %p\n",&stu1.a,&stu1.b,&stu1);
    // printf("sizeof(stu1.b) = %d sizeof(stu1.a) = %d\n",sizeof(stu1.b),sizeof(stu1.a));
    printf("sizeof(stu1) = %d\n",sizeof(stu1)); // 8字节
    struct __attribute__((aligned(8)))STU2{
        char b = 'b'; 
        int a = 1; 
        STU1 stu; 
    } stu2;
    printf("&stu2.b = %p &stu2.a = %p &stu2.stu = %p &stu2 = %p\n",&stu2.a,&stu2.b,&stu2.stu,&stu2);
    printf("sizeof(stu2) = %d\n",sizeof(stu2)); // 16字节
    struct __attribute__((aligned(8)))STU3{
        int a = 1; 
        char b = 'b'; 
        char c = 'c'; 
    } stu3;
    printf("&stu3.a = %p &stu3.b = %p &stu3.c = %p &stu3 = %p\n",&stu3.a,&stu3.b,&stu3.c,&stu3);
    printf("sizeof(stu3) = %d\n",sizeof(stu3)); // 8字节
    struct __attribute__((aligned(8)))STU4{
        char b = 'b'; 
        int a = 1; 
        char c = 'c'; 
    } stu4;
    printf("&stu4.b = %p &stu4.a = %p &stu4.c = %p &stu4 = %p\n",&stu4.b,&stu4.a,&stu4.c,&stu4);
    printf("sizeof(stu4) = %d\n",sizeof(stu4)); // 16字节
    struct __attribute__((aligned(8)))STU5{
        char b = 'b'; 
        char c = 'c'; 
        int a = 1; 
    } stu5;
    printf("&stu5.b = %p &stu5.c = %p &stu5.a = %p &stu5 = %p\n",&stu5.b,&stu5.c,&stu5.a,&stu5);
    printf("sizeof(stu5) = %d\n",sizeof(stu5)); // 8字节
}
