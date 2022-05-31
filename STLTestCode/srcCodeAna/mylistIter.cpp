/*** 
 * @Author: chenbei
 * @Date: 2022-05-31 08:58:10
 * @LastEditTime: 2022-05-31 10:19:20
 * @Description: mylistIter.cpp
 * @FilePath: \myLeetCode\STLTestCode\srcCodeAna\mylistIter.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
// find函数
template<class InputIterator,class T>
InputIterator find(InputIterator first,InputIterator last,const T&value){
    while (first!=last && *first !=value)
        ++first;
    return first;
}
// 由于find函数比较时左边的first是ListItem<T>类型,value是个T类型,所以不能直接比较,需要转换
template<typename T>
bool operator!=(const ListItem<T>&lhs,const T n){
    return lhs.value() != n;
}
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
// List类（已改造,原书的List缺省了很多函数定义所以无法运行,见书P85页）
template<typename T>
class List{
    public:
        List(){cout<<"List() is called"<<endl;}
        ~List(){cout<<"~List() is called"<<endl;_list.~list();}
        List(const List<T> &other){
            cout<<"List(const List<T> &other) is called"<<endl;
            _list = other._list;
        }
        List<T> &operator=(const List<T> &other){
            if (this != &other){
                cout<<"List<T> &operator=(const List<T> &other) is called"<<endl;
                _list = other._list;
            }
            return *this;
        }
        auto begin()const{return _list.begin();}
        auto end()const{return _list.end();}
        void insert_front(T value){_list.push_front(value);}
        void insert_back(T value){_list.push_back(value);};
        void size(){cout<<"size:"<<_list.size()<<endl;}
        void display(std::ostream &os = std::cout) const{
            for(auto it = _list.begin(); it != _list.end(); ++it){
                os << *it << " ";
            }
            os << endl;
        }
        // ...
    private:
        list<T> _list ;
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

int main(){
    List<int> mylist;
    for(int i = 0; i < 5; i++){
        mylist.insert_front(i);
        mylist.insert_back(i+2);
    }
    mylist.size();
    mylist.display();

    /*
        原书的测试程序:不过这无法运行
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
    */
    return 0;
}
/*
cd STLTestCode\srcCodeAna
g++ -o .\output\mylistIter mylistIter.cpp 
.\output\mylistIter.exe
*/
