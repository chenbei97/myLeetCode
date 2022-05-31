/*** 
 * @Author: chenbei
 * @Date: 2022-04-15 14:54:58
 * @LastEditTime: 2022-05-31 08:39:32
 * @Description: JJAlloc.cpp
 * @FilePath: \myLeetCode\STLTestCode\srcCodeAna\JJAlloc.cpp
 * @Signature: A boy without dreams
 */
#include <new> // 用于placement new重载
#include <cstddef> // 使用ptrdiff_t,size_t类型
#include <cstdlib> // 使用exit
#include <climits> //使用UINT_MAX
#include <iostream> // 使用cerr
#include <vector> // for test
using namespace std;
namespace JJ
{
    // 用于分配内存的内联函数,inline有利于版本更迭且提高执行速度
    // 此函数在后面的allocator类调用
    template<class T>
    inline T*_allocate(ptrdiff_t size, T*){
        set_new_handler(0);//初始化内存分配函数
        T* tmp = (T*)(::operator new((size_t)(size* sizeof(T))));
        if (tmp == 0){
            cerr <<"out of memory"<<endl;
            exit(1);
        }
        return tmp; // 返回指向分配的内存的指针
    }

    // 释放内存的inline函数,频繁调用同样inline
    template<class T>
    inline void _deallocate(T*buffer){
        ::operator delete(buffer);
    }

    // 以p指向的内存构造类型为value的函数
    template<class T1,class T2>
    inline void _construct(T1 *p,const T2& value){
        new(p) T1(value);//value转为T1类型被new构造
    }

    // 析构T类型的内存
    template<class T>
    inline void _destroy(T*ptr){
        ptr->~T();
    }

    template<class T>
    class allocator{ // 分配内存的类
        public:
            // 起一些别名方便
            typedef T value_type;
            typedef T* pointer;
            typedef const T* const_pointer;
            typedef T& reference;
            typedef const T& const_reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;

            template<class U> //允许模板成员函数
            struct rebind{
                typedef allocator<U> other;//绑定其他类型的内存分配器
            };

            pointer allocate(size_type n,const void* hint = 0){
                return _allocate((difference_type)n,(pointer)0); // _allocate函数的参数
            }

            void deallocate(pointer p,size_type n){
                _deallocate(p);} // 调用_deallocate函数

            void construct(pointer p,const T& value){
                _construct(p,value);
            }

            void destory(pointer p){
                _destroy(p);
            }

            pointer address(reference x){
                return (pointer)&x;//取地址转为指针返回
            }

            const_pointer const_address(const_reference x){
                return (const_pointer)x;
            }

            size_type max_size() const{
                return size_type(UINT_MAX/sizeof(T));
            }
    };

} // namespace JJ
void _jj_allocate_testcode(){
    int ia[5]={1,2,3,4,5};
    unsigned int i ;
    vector<int,JJ::allocator<int>> iv(ia,ia+5);
    for(i = 0;i<iv.size();++i){
        cout<<iv[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    _jj_allocate_testcode();
    return 0;
}
/*
cd STLTestCode\srcCodeAna
g++ -o .\output\JJAlloc JJAlloc.cpp 
.\output\JJAlloc.exe
*/
