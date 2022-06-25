<!--
 * @Author: chenbei
 * @Date: 2022-03-30 08:35:39
 * @LastEditTime: 2022-03-30 08:37:01
 * @Description: STL_Source_Code_Analysis
 * @FilePath: \myLeetCode\STLSourceCodeAnalysis.md
 * A boy without dreams
    -->

## 一、STL概论

STL是一个以抽象概念为主体而非以实际类为主体的结构，形成了一个严谨的接口标准。在此接口下，任何组件都有最大的独立性，并以迭代器iterator胶合起来，或者使用配接器adapter配接，或者以仿函数functor动态选择某种策略。  

STL的组件分为

容器containers：vector、list、deque、set和map等，是一种class template

算法algorithms：sort、search、copy和erase等，可以看出function template

迭代器iterators：扮演容器和算法之间的胶合剂，即泛型指针，可以看成是对operator * ,operator->,operator++,operator--重载的class template，每个STL容器有自己专属的迭代器

仿函数functors：行为类似函数，可作为某种算法的莫种策略，看成是重载operator()的class或class template

适配器adapters：一种修饰容器或仿函数或迭代器接口的东西，可以叫containers adapters、function adapter、iterator adapter。分例如queue和stack看似是容器其实是配接器，真正的容器是deque

配置器：负责空间配置和管理，实现的角度来看是一个实现了动态空间配置、空间管理和空间释放的class template

```mermaid
graph TD
A[Allocator]
I[Iterators]
AD[Adapters]
C[Containers]
AL[Algorithms]
F[Functors]
A==>C
I==>C
I==>AL
AD-->|container adapters|C
AD-->|iterator adapters|I
AD-->|function adapters|AL
F==>|as policy|AL
```

## 二、空间配置器

allocator提供的标准接口。

```c++
allocator::value_type;
allocator::pointer;
allocator::const_pointer;
allocator::reference;
allocator::const_reference;
allocator::size_type;
allocator::difference_type;
allocator::rebind; // 拥有唯一成员other
allocator::allocator();// 默认构造
allocator::allocator(const allocator&); // 复制构造
template<class U> allocator::allocator(const allocator<U>&);//泛化的复制构造函数
~allocator(); // 析构
pointer allocator::address(reference x)const; // 返回地址.&x
const_pointer allocator::address(const_reference x)const ;// 返回const对象地址
pointer allocator::allocate(size_type n,const void*=0);//配置n个T对象所需空间,第2参数是个提示可以用来增进区域性
void allocator::deallocate(pointer p,const T& x); // 归还空间
size_type allocator::construct(pointer p,const T&x); // 返回可成功配置的最大量
void allocator::destroy(pointer p);//等同于p->~T()
```

一个简单的空间配置器设计如下，可见代码文件JJAlloc.h。

```c++
#ifndef _JJALLOC_
#define _JJALLOC_
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
#endif // !_JJALLOC_
```

std::allocator是SGI标准的空间配置器，但是效率不高，只是把C++的new和delete函数做一层薄薄的封装，一般使用std::alloc。默认的情况下，容器指定的缺省空间配置器就是alloc。

```c++
template<class T,class Alloc = alloc>
class vector{...};
```

std::alloc把空间配置拆成了4个过程，即分配内存、构造、析构、释放内存。配置器定义于< memory >，内部包含3个头文件。

```c++
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
```

<stl_construct.h> 定义了全局函数construct()和destroy()用于构造和析构函数。

<stl_alloc.h> 定义了一、二级配置器，彼此合作

<stl_uninitialized.h>是用于填充和复制大块内存数据，一些全局函数被定义，un_initialized_copy()、un_initialized_fill()、un_initialized_fill_n()等

其它的内容暂时跳过。

## 三、迭代器概念和traits编程技法

设计模式中提到Iterator设计模式，即提供一种方法使之能够按照顺序访问某个聚合物容器所含的各个元素，又无需暴漏该聚合物的内部表述方式。STL的中心思想就是将数据容器和算法分开，类模板和函数模板可以分别实现，但是设计出两者之间的胶合剂比较困难。

在STL的find函数是这样定义的，它可以接受2个迭代器和一个搜寻目标，如果找到就返回指向该模板的迭代器否则返回end()。

```c++
template<class InputIterator,class T>
InputIterator find(InputIterator first,InputIterator last,const T&value){
    while (first!=last && *first !=value)
        ++first;
    return first;
} 
vecto<int> arr={1,2,3};
vector<int>:iterator it = find(arr.begin(),arr.end(),3);
```

从上述例子来看，好像迭代器依附于容器，其实并非如此，只是容器类内部的嵌套了迭代器类，并提供了begin和end两种方法，之所以嵌套只是更容易访问容器的元素。

迭代器其实是个智能指针，它也可以解引用和成员访问，所以关键在于重载opertor * 和operaotr->函数。

现在以List为例设计一个迭代器。

```c++
// ListItem类,是List的节点
template<typename T>
class ListItem{
    public:
        T value()const{return _value;}
        ListItem<T> *next()const{return _next;}
        ListItem<T> *prev()const{return _prev;}
        // ...
    private:
        T _value;
        ListItem<T> *_next; // 单向链表
        ListItem<T> *_prev; // 双向链表
};

// 原书定义的List类(P85)
template<typename T>
class myList{
    public:
        void insert_front(T value); // 缺省定义
        void insert_back(T value); // 缺省定义
        void size(); // 缺省定义
        void display(std::ostream &os = std::cout) const; // 缺省定义
        // ...
    private:
        ListItem<T> *_head;
        ListItem<T> *_tail;
        long _size;
};

// 用于List的迭代器类,胶合剂
template<typename Item> // Item是ListItem的类型
struct ListIter
{
    Item * ptr; // 保持与链表节点的联系,一个原生的指向链表节点的指针
    ListIter(Item *p = nullptr) : ptr(p) {} // 默认构造函数
    // copy构造函数和operator=可以缺省，默认已足够

    // 解引用函数operator*重载
    Item & operator*() const {return *ptr;}
    // 成员访问函数operator->重载
    Item * operator->() const {return ptr;}

    // 前置++
    ListIter & operator++() {ptr = ptr->next(); return *this;} // ++iter,先改变指针,再返回
    // 后置++,其中++*this借助了前置++的返回值
    ListIter operator++(int) {ListIter tmp = *this; ++*this; return tmp;} // iter++,先返回,再改变指针
    // 前置--
    ListIter & operator--() {ptr = ptr->prev(); return *this;} // --iter,先改变指针,再返回
    // 后置--,其中--*this借助了前置--的返回值
    ListIter operator--(int) {ListIter tmp = *this; --*this; return tmp;} // iter--,先返回,再改变指针

    // 比较运算符operator==和operator!=重载
    bool operator==(const ListIter &rhs) const {return ptr == rhs.ptr;}
    bool operator!=(const ListIter &rhs) const {return ptr != rhs.ptr;}

    // 重载operator<<函数
    friend std::ostream & operator<<(std::ostream &os, const ListIter &iter)
    {
        os << *iter;
        return os;
    }
};
```

由于find函数比较时左边的first是ListItem<T>类型,value是个T类型,所以不能直接比较,需要转换

```c++
template<typename T>
bool operator!=(const ListItem<T>&lhs,const T n){
  return lhs.value() != n;
}
```

测试程序：

```c++
myList<int> mylist;
for(int i = 0; i < 5; i++){
    mylist.insert_front(i);
    mylist.insert_back(i+2);
}
mylist.display(); // 输出: 4 3 2 1 0 2 3 4 5 6 

ListIter<ListItem<int>> begin(mylist.begin());
ListIter<ListItem<int>> end(mylist.end()); // default nullptr
ListIter<ListItem<int>> it; // default nullptr
it = find(begin, end, 3); // 查找3
if (it != end)
	cout << *it << endl; // 输出: 3
else
	cout << "not found" << endl;
it = find(begin, end, 10); // 查找10
if (it != end)
	cout << *it << endl; // 输出: not found
else
	cout << "not found" << endl;
```

