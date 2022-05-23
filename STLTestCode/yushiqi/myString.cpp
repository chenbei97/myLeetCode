/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 14:14:43
 * @LastEditTime: 2022-05-23 14:49:09
 * @Description: myString.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\myString.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o myString myString.cpp
./myString
*/
#include <iostream>
#include <string.h>
using namespace std;
class MyString{
    private:
        int buf_size;
        char * characters;
    public:
        MyString(int buf_size=64,const char* data=nullptr){
            cout<<"constructor(int,char*) is called"<<endl;
            this->buf_size= 0; // 先初始化
            this->characters=nullptr;
            this->create(buf_size,data);
        }
        MyString(const MyString& other){
            cout<<"constructor(const MyString&) is called"<<endl;
            this->buf_size=0;
            this->characters=nullptr;
            this->create(other.buf_size,other.characters);
        }
        MyString& operator=(const MyString& other){
            cout<<"operator=(const MyString&) is called"<<endl;
            if(this!=&other){ // 如果不是自身
                this->release();
                this->create(other.buf_size,other.characters); // 申请新空间深拷贝
            }
            return *this;
        }
        void release(){
            cout<<"release() is called"<<endl;
            this->buf_size=0;
            if (this->characters!=nullptr){ // 不为空的话先释放
                delete[] this->characters;//先释放掉自己的空间
                this->characters=nullptr;
            }
        }
        bool create(int buf_size,const char*data){
            this->release(); // 先释放掉自己的空间
            this->buf_size=buf_size;
            if (this->buf_size !=0){ // 如果申请的空间不为0
                this->characters=new char[this->buf_size]{};
            }
            // 如果data不为空,就拷贝数据
            if(data) strncpy(this->characters,data,this->buf_size);
            return true;
        }
        ~MyString(){
            cout<<"destructor() is called"<<endl;
            this->release();
        }
        friend ostream& operator<<(ostream& os,const MyString& other){
            os<<"characters = "<<other.characters
                <<"("<<&other.characters<<") "
                << "buf_size = "<<other.buf_size;
            return os;
        }
};
int main(){
    cout<<"s1-------------------->\n";
    MyString s1(10,"hello");
    cout<<"s1="<<s1<<endl;
    cout<<"s2-------------------->\n";
    MyString s2(s1);
    cout<<"s2="<<s2<<endl;
    cout<<"s3-------------------->\n";
    MyString s3 = s2;
    cout<<"s3="<<s3<<endl;
    cout<<"leave scope-------------------->\n";
    return 0;
}