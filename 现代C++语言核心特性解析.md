<!--
 * @Author: chenbei
 * @Date: 2022-04-09 19:25:11
 * @LastEditTime: 2022-04-09 19:39:38
 * @FilePath: \myLeetCode\现代C++语言核心特性解析.md
 * @Description: 现代C++新特性
 * @Signature: A boy without dreams
-->
## 1. 新基础类型

整数类型long long。

long表示为1个32整型，表示范围在-2^31~2^31-1，因为最高位为符号为0，所以就是2^30+2^29+...+2^0=(1-2^(30+1))/(1-2)=2^31-1。负数则是因为补码的原因为-2^31。

```c++
0111 1111 1111 1111 _ 1111 1111 1111 1111
```

无符号长整型unsigned long表示范围在[0,2^32]之间。

C++标准定义的long long是1个"至少"64位的长整型，这里是至少。同时还规定了字面量后缀LL和ULL来声明类型，相应的std::printf也可以使用格式化控制符%lld和%llu。

long long 同理表示范围在[-2^63~2^63-1]，unsigned long long则是[0,2^64]。

字面量后缀并非没有意义，例如对于65536，它会被认为是1个32位整型，如果左移16位，因为上限溢出所以实际上移动16次以后变成了0。

```c++
long long x1 = 65536<<16;// 结果是0
//65536表示为{0,...,1}{0,...,0},1左边有15个0,移动15次,1到达最高位,再移动就变成0

long long x2 = 65536LL<<16; // 结果是2^32
//现在1左边其实是32+15个0,所以移动16次,1还不是最高位,1左边还有31个0,右边有32个0
```

long long 和unsigned long long可以通过宏或者模板来查找最大和最小值。

```c++
#define LLONG_MAX 9223372036854775807LL // 2^63-1
#define LLONG_MIN (-9223372036854775807LL-1) // -2^63,加括号防止边际效应
#define UNLONG_MAX 0xffffffffffffffffULL // 16个f对应64个0,1后边64个0是2^64
```

通过宏方法查找类型取值范围，需要包括<cstdio>头文件。

```c++
#include <cstdio>
using namespace std;
cout<<LLONG_MAX<<" "<<LLONG_MIN<<" "<<UNLONG_MAX <<endl;
```

使用模板方法，需要包括<limits>头文件。

```c++
#include <limits>
using namespace std;
cout<<numeric_limits<long long>::max()<<endl;
cout<<numeric_limits<long long>::min()<<endl;
cout<<numeric_limits<unsigned long long>::max()<<endl;
```

printf的格式化控制符。

```c++
printf("long long max = %lld\n",LLONG_MAX);
printf("long long min = %lld\n",LLONG_MIN);
printf("unsigned long long max = %llu\n",ULLONG_MAX);
```

新字符类型char16_t和char32_t。

字符集是指系统支持的所有抽象字符的集合，编码方法表示利用数字和字符建立对应关系的一套方法。例如Unicode字符集可以有3种编码方法，即UTF-32，UTF-16和UTF-8，分别占用4子节、2子节和1字节的内存空间。Unicode字符集根据ISO 10646标准大概有0x10FFFF个字符，也就是大概110多万个字符，所以使用UTF-32标准完全够用，大概43亿个字符。而UTF-16最大可容纳0xFFFF个字符，也就是65535个字符，所以这套编码方法使用了一些非一一线性的映射规则去表示字符。同理UTF8也是如此，这也是目前最常用的编码方法。

其它的字符集ASCII、GB2312等字符集也有自己的编码方法。

除了char可以处理UTF-8，C++11提供了char16_t，char32_t来表达变长的内存空间，字面量u8、u和U分别表示3种编码方法。

```c++
// C++17标准
char utf8c = u8'a';//c++11不能通过,因为c++11的u8只能用于字符串字面量前缀
// char utf8c = u8'好'; // '好'需要3子节,使用u8不能通过编译
char16_t utf16c = u'好';//使用u可以通过编译
char32_t utf32c = U'好';// U可以通过

char utf8[]= u8"你好世界";
char16_t utf16[] = u"你好世界";
cha32_t utf32[] = U"你好世界";
```

char16_t，char32_t也是用于解决wchar_t的问题。因为wchar_t虽然也可以处理宽字符，但是没有规定占用内存的大小，给了实现者充分自由。所以windows wchar_t占用2子节，在linux和macos占用4子节，这样代码不具备可移植性，新字符的出现也是用于解决这个问题。

C++20还提供了char8_t代替char对UTF-8的处理，这是为了库函数需要同时处理多种字符必须采用不同的函数名称以区分普通字符和UTF-8字符。

所以，以下代码在C++17编译正确，但是C++20不可。也就是不带前缀都用char处理，带前缀就分别用char8_t,char16_t,char32_t分别处理u8,u,U。

```c++
char c = u8'c';// 加了字面量前缀c++20必须使用char8_t c = u8'c';
char str[] = u8"text";// 同理,应使用char8_t str[] = u8"text";

char8_t c8 = 'c'; // 不加字面量前缀C++20应使用char c8 = 'c';
char8_t c8str[] = "text";//c++20应使用char c8str[] = "text";
```

关于新字符串的连接和库对新字符类型的支持可见《现代C++语言核心特性解析》P7，这里不赘述。

## 2.内联和嵌套命名空间

命名空间是为了避免函数和类型同名冲突，一般是这样使用的。

```c++
namespace V1{
    void foo();
}
namespace V2{
    void foo();
}
using namespace V1;
int main(){
    foo();//V1版本可以直接使用
    V2::foo();//V2版本使用作用域声明
    return 0;
}
```

**内联嵌套命名空间是为了客户端可以不修改代码的情况下，升级函数的版本**。嵌套命名空间可以不指定子命名空间就可以使用该空间的函数和类型，因为inline的作用让其好似父命名空间下的函数和类型。

```c++
namespace Parent{
    // foo(); 不直接在父命名空间定义foo
    namespace V1{
        void foo();
    }
    inline namespace V2{ // 改使用inline
        void foo();
    }
}
int main(){
    using namespace Parent;
    // 好处在于虽然foo函数从V1升级到V2,但是客户端使用foo()没有什么问题
    // 如果直接父空间定义foo,那么客户端想要使用v2版本的必须使用Parent::V2::foo()
    // 也就是要修改代码
    foo();//其实调用的是Parent::V2::foo();
    return 0;
}
```

如果V2继续升级到V3，只需要将V2版本的inline删除，然后V3命名空间使用inline即可，对客户而言依然不需要修改代码。**注意，只能有1个inline命名空间，否则造成二义性**。

C++17引人了命名空间简洁写法。

```c++
namespace A::B::C{
	int  foo(){return 5;}
}
// 等价于
namespace A{
    namespace B{
        namespace C{
            int foo(){return 5;}
        }
    }
}
```

对于inline的支持在C++20可以实现。

```c++
namespace A::inline B::C{
    void foo(){}
}
// 等价于
namespace A{
    inline namespace B{
        namespace C{
            void foo(){}
        }
    }
}

namespace A::B::inline C{
    void foo(){}
}
// 等价于
namespace A{
    namespace B{
        inline namespace C{
            void foo(){}
        }
    }
}
```

## 3. auto占位符

auto支持自动推断变量类型，以及声明函数时函数返回值的占位符。

```c++
auto i = 5;
auto sum(int a,int b)->int
{
    return a+b;
}
```

但是不支持未初始化变量的推导。

```c++
auto i;//x
```

支持自动推导同一类型的多个变量。

```c++
int i = 5;
auto *p = &i, m = 10;//p为int *类型, m为int可以
auto *p1 = &i, m = 10.0;//类型不统一,不通过
```

auto推导会返回更强类型。

```c++
auto i = true? 5:8.0;// i是double类型
```

auto 声明的变量是按值初始化，则会忽略const和volatile限定符。

```c++
const int a = 5;
auto a1 = a;//a1是int类型,忽略const
const auto a2 = a;//显示const auto推导才是const int类型
auto &b1 = a;//显示引用推导不会忽略const,b1是const int&类型
auto *b2 = &a; // 显示指针推导也不会忽略const,b2是const int*类型
```

auto 声明的变量是引用，引用属性会被忽略。

```c++
int i = 5;
int &j = i;
auto m = j;// m是int类型而非 int&
```

auto 推导数组或者函数时会推导为相应指针类型和函数指针。

```c++
int i[5];
auto m = i;//m是int*类型
int func(int a1,int a2){return a1+a2;}
auto n = func;//n是 int(pf*)(int,int)函数指针
```

auto 结合列表初始化，直接列表初始化花括号内必须单元素，或者使用等号多元素，但元素类型要相同。内部等价于C++17标准使用模板initializer_list< T >。

```c++
auto x1{5};//支持单元素直接列表初始化 initializer_list<int>
auto x2{5,3};//失败,不支持多元素直接列表初始化

auto x3 = {5,6};//使用等号可以多元素 initializer_list<int>
auto x4 = {5,6.0};//失败,元素必须同类型
```

auto 结合lambda表达式初始化。

```c++
auto func = [](auto a1,auto a2){return a1+a2;}
auto ret = func(1,1.5);//ret为double类型

auto func1 = [](int &i)->auto& {return i;};//以引用传参且返回引用
auto x1 = 5;
auto &x2 = func1(x1);
assert(&x1 == &x2);//相同内存地址
```

C++17 支持auto 作为模板参数推导，但是前提推导出来的类型可以作为模板形参。

```c++
template<auto N>
void f(){...}
int main(){
    f<5>();//N为int
    f<'c'>();//N为char
    f<5.0>();//失败,模板参数不能是double
    return 0;
}
```

C++11 auto只支持static&const成员变量的推导。

```c++
// c++11
struct sometype{
	auto i = 5;//不能通过
    const auto i = 5;//不能通过
    static const auto i = 5;//可以
}
```

C++17 可以没有const的限制了。

```C++
// c++17
struct sometype{
    static inline auto i = 5;//可以
}
```

C++20 以前不能在函数参数列表使用auto，现在可以。

```c++
// c++20
void func(auto str){// c++20之前不行
    ...
}
```

## 4. decltype说明符

typeof以前是GCC提供的函数可以获取对象类型，但typeof并非C++标准。

```c++
int a = 10;
typeof(a) b = 5;//b为int
```

C++标准可以使用typeid来获取类型，但是它不能在编译期获取。

```c++
int x1 = 0;
cout<<typeid(x1).name()<<endl;
cout<<typeid(int).name()<<endl;
```

typeid返回的类型是左值，其信息存储在std::type_info中，但是这个删除了复制构造函数，只能使用指针或引用来保存type_info。另外typeid总是忽略CV限定符。

```c++
auto t1 = typeid(int);//失败,无复制构造
auto &t2 = typeid(int);//可以,t2为const std::type_info&类型
auto t2 = &typeid(int);//可以,t3为const std::type_info*类型

auto r = typeid(const int) == typeid(int);// r=true,忽略const&volatile
```

C++14引入了decltype，也可以获取对象或表达式类型，和typeof语法类似。

```c++
int x1 = 0;
decltype(x1) x2 = 0;
decltype(x1+x2) x3 = x1+x2;
// 且不同于auto可以在非静态成员变量使用
struct S{
    int x1;
    decltype(x1) x2;
    double x3;
    decltype(x2+x3) x4;
}
// 可以在函数形参列表使用
decltype(x1) sum(decltype(x1) a1,decltype(x2)a2){
    return a1+a2;
}
// C++11可以在泛化模板中结合auto指定推导返回类型,如果是以前只能返回T1或者T2
template<class T1,class T2>
auto sum(T1 a1,T2 a2)->decltype(a1+a2){
    return a1+a2;
}
// 由于C++14支持了auto完整推导,无需decltype
template<class T1,class T2>
auto sum(T1 a1,T2 a2){
    return a1+a2;
}
// 但是auto说过会对引用类型的去除引用推导,所以此时还是需要decltype
template<class T>
auto return_ref(T& t){
    return t;
}
int x1 = 0;
static_assert(std::is_reference_v<decltype(return_ref(x1))>);//断言失败
// 返回值不为引用类型,代码加个后置返回推导限定
template<class T>
auto return_ref(T& t)->decltype(t){
    return t;
}//此时再次断言会成功
```

decltype一般来说可以同步变量的CV限定符，但如果是没加括号的成员变量不能同步。

```c++
const int i =0;
decltype(i);//const int类型

struct A{
    double x;
}
const A*a = new A(); // a是const类型
decltype(a->x);//未加括号,double类型
decltype((a->x));//加括号,const double&类型
```

关于decltype的推导原则，在书P27页，不赘述。

关于decltype(auto)的使用，即2个关键字结合体，要求必须单独声明，具体使用见P30。

## 5. 函数返回类型后置

这个就是使用箭头符号，在前边已经出现过。

```c++
int func(int x){
    return x;
}
typedef int(*pfunc)(int);//函数指针别名pfunc
pfunc foo(){
    return func;
}
// 有了箭头符号声明返回类型更加简洁,注意这里aut只是占位符
auto foo1()->int(*)(int){
    return func;
}
auto f = foo1();
f(5);
```

## 6. 右值引用

左值是指向一个特定内存的具有名称的值(具名对象)，有一个相对稳定的内存地址，并且有一段较长的生命周期。

右值是不指向稳定内存地址的匿名对象(不具名对象)，生命周期很短。

所以可以通过取址符号来判断左值和右值，而不是简单的等号。

```c++
int a = 1;
int b = a; 
// b,a都是左值,1是右值

int *p1 = &a++;//失败,右值,a++使用了临时变量
int *p2 = &++a;//成功,a直接自增返回自己,是左值
```

常常用的是左值引用，例如将对象以const T&的方式传递给函数，它要求必须是个左值。但是如果使用const可以对右值进行引用。

```c++
int x1 = 0;
int &x2 = x1;//正确
int &x3 = 7;//失败

const int &x4 = 11;//可以,因为const使11的生命周期延长了
```

右值引用符号是&&，  右值引用的主要目的是减少对象复制，提升性能。

```C++
class X{
	X(){}
    X(const X&x){}
    ~X(){}
}
X make_x(){
    X x1;
    return x1;
}
int main(){
    // make_x内部的x1构造1次,return x1会调用复制构造产生临时对象tem
    // 然后main中x2先调用复制构造把tem复制给x2,然后销毁tem,一共3次
    X x2 = make_x();// 接受对象
}
int main(){
    // make_x发生的过程相同,区别在于右值引用延长了tem的使用周期,x2其实就是tem
    // 没有发生x2的复制构造
    X &&x2 = make_x();//右值引用
}
```

 移动语义的内容见P43，值类别内容见P47，左值转化为右值P49，万能引用和引用折叠见P50，完美转发见P52。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

## 7. lambda表达式

暂时跳过，2022.4.10。

## 8.非静态数据成员默认初始化

C++11以前不允许非静态成员变量初始化，只能这样写。

```c++
class X{
    public:
    	X():a(0),b(0.),c("cb"){}
    	X(int a):a(a),b(0.),c("cb"){}
    	X(double b):a(0),b(b),c("cb"){}
    	X(string c):a(0),b(0),c(c){}
    private:
    	int a; // C++11以前只允许在static const int或者enum声明默认初始化
    	double b;
    	string c;
}//这样的写法存在代码冗余不易维护

// C++11之后允许声明初始化
class X{
    public:
    	X(){}
    	X(int a):a(a){}//允许只专注1个参数初始化
    	X(double b):b(b){}
    	X(string c):c(c){}
    private:
    	int a = 0; // 允许使用=或者{}初始化
    	double b{0.};
    	string c{"cb"};  
}
// 但是不要使用()或者auto对非静态数据成员初始化。
struct X{
    int a(5);//错误
    auto b =8 ;//错误
}
int a(5);//不是成员可以用()
```

## 9. 列表初始化

先看看拷贝初始化和直接初始化的使用，必须使用花括号{}。

```c++
int x = {5}; // 拷贝初始化
int x1{8};// 直接初始化

int x2[] = {1,2,3};// 拷贝初始化
int x3[]{1,2,3};//直接初始化

vector<int> v1{1,2,3};//直接初始化
map<string,int> m1 = {{"a",1},{"b",b},{"c",3}};//拷贝初始化
```

而初始化列表用到了，std::initializer_list，例如下方是定义一个支持初始化列表的类，其实就是利用了begin、end函数，但要注意begin和end并不是迭代器对象，而是常量对象指针const T *。

```c++
struct C{
    C(std::initializer_list<std::string>a){ // 借助initializer_list实现
        for (const std::string *it = a.begin();it!=a.end();++it){
            data.push_back(*it);
        }
    }
    std::string data;
}
C c{"hello","c++","world"};//支持初始化列表
```

C++20引入了指定初始化，但不是什么类型都可以初始化，对象必须是聚合类型。

```c++
struct Point{
    int x;
    int y;
    int z;
}
Point p{.x=4,.y=5}; //成功指定初始化
Point p1{.x=4,.x=4};//失败,只能初始化1次
Point p2{.z=4,.y=2};//失败,必须按照声明顺序初始化
Point p3{.x=1,3,4};//失败,不能混用初始化方法

struct Point{
    Point(){}//现在不是聚合类型
    int x;
    int y;
    int z;
}
Point p{.z=3};//失败

// 联合体的数据成员只能初始化1次,不能同时指定
union u{
    int a;
    const char* b;
}
u a = {.a=1};//成功
u b = {.b="abc"};//成功
u c = {.a=1,.b="abc"};//失败

// 不能嵌套初始化
struct Line{
    Point a;
    Point b;
};
Line L1{.a.y=5};//失败
Line L2{.a{.y=5}};//允许
```

## 10. 默认和删除函数

跳过。

## 11. 非受限联合类型

跳过。

## 12.委托构造函数

类似于这样的写法，说实话我觉得还是挺恶心的。

每个构造函数都可以委托另一个构造函数为代理，即可能存在一个构造函数，它既是委托构造函数也是代理构造函数。

```c++
class X{
    public :
        X():X(0,1.0){} // 委托构造函数
        X(int a):X(a,1.0){}// 委托构造函数
        X(double b):X(0,b){}// 委托构造函数
        X(int a,double b):a(a),b(b){commonInit();}// 代理构造函数
    private:
    	void commonInit();//代理构造函数的主体
    	int a;
    	double b;
}

class X{
    public :
        X():X(0){} // 委托构造函数
        X(int a):X(a,1.0){}// 委托构造函数,还是X()的代理构造函数
        X(double b):X(0,b){}// 委托构造函数
        X(int a,double b):a(a),b(b){commonInit();}// 代理构造函数
    private:
    	void commonInit();//代理构造函数的主体
    	int a;
    	double b;
}
```

其它特性。。诸如委托模板构造函数、捕获委托构造函数的异常等(真TMD闲的)看书P111页

## 13.继承构造函数

派生类是隐式继承基类的构造函数，所以程序中使用了这些构造函数才会为派生类生成继承构造函数的代码；

派生类不会继承基类的默认构造函数和复制构造函数，因为执行派生类之前一定会先执行基类的默认构造和复制构造，这里继承是多余的；

继承构造函数不会影响派生类默认构造函数的隐式声明；

派生类如果声明了签名相同的构造函数就会自动禁止继承相应的构造函数，即覆盖基类；

派生类继承多个签名相同的构造函数会导致编译失败；

继承构造函数的基类构造函数不能为私有，否则不能被继承。

```c++
class Base{
    public:
    	Base():x(0),y(0.){}
    	Base(int x,double y):x(x),y(y){}
    	Base(int x):x(x),y(0.){}
    	Base(double y):x(0),y(0.){}
    private:
    	int x;
    	double y;
}
class Derived : public Base{
    public:
    	using Base::Base;//代替了冗余的重定义转发父类的构造
}
// 即无需这样写
class Derived : public Base{
    public:
    	Derived(){};
    	Derived(int x,double y):Base(x,y){}
		Derived(int x):Base(x){}
    	Derived(double y):Base(y){}
}
```

## 14. 强枚举类型

。。跳过。

## 15.扩展的聚合类型

。。跳过。

## 16.override和final说明符

首先明确重写override、重载overload和隐藏overwrite的概念。

override是指C++的派生类覆盖了基类继承而来的虚函数，这里要求函数签名和返回类型，以及常量性都一致。

overload是函数重载，函数名字是相同的，但是函数签名不同。至于返回类型没有相同不相同的要求，因为函数重载不以返回类型区分。

overwrite是指基类成员函数被继承时，无论它是否为虚函数，只要派生类的函数签名和继承来的函数签名不同就叫隐藏，如果相同那就是override。

如果想要使用基类的成员函数，可以使用using声明基类的函数暴露在子类的作用域中。

重写非常容易出错，如下所示。

```c++
class Base{
    virtual void some_func(){}
    virtual void foo(int x){}
    virtual void bar()const{}
    void non_virtual();
}
class Drived:public Base{
    public:
    	virtual void sone_func(){};//打字错误,这其实是派生类自己定义的虚函数
    	virtual void foo(int &x){};//签名不一致,同理
    	virtual void bar(){};//常量性没被继承
    	virtual void non_virtual();//这是派生类自己的虚函数,基类的不是虚函数
}
```

所以C++11之后提供了override关键字，告诉编译期这个虚函数需要覆盖基类的虚函数，如果发现不符合重写规则就会给出提示。

```c++
class Base{
    virtual void some_func(){}
    virtual void foo(int x){}
    virtual void bar()const{}
    void non_virtual();
}
class Drived:public Base{
    public:
    	virtual void sone_func()override{};//报错,4个函数都不能重写
    	virtual void foo(int &x)override{};
    	virtual void bar()override{};
    	virtual void non_virtualoverride();
}
```

final关键字是被用来阻止派生类继承自己的虚函数，告诉这个函数不能被重写。

```c++
class Base{
    public:
    	virtual void log(const char*)const{...}//定义自己的日志函数打印到终端
    	virtual void foo(int x){}//其它函数
}
class BaseWithFileLog: public Base{
    public:
    	virtual void log(const char*)const override final{...}//为了更好的保存日志，将函数重写改为保存到文件中，不要求后面的继承者不要改变日志的行为
}
class Derived:public BaseWithFileLog{
    public:
    	void foo(int x){};//只允许foo函数被重写
}
```

final也可以用在类上，这是告知这个类不能作为基类被其他类继承。

```c++
class Base final{
    public:
    	virtual void foo(int x){}
};
class Derived:public Base{ //报错,不允许被继承
    public:
    	void foo(int x){} 
}
```

记住，为了与过去的代码兼容，override和final不作为保留的关键字，override只在虚函数的尾部才有意义，final只有在虚函数的尾部及类声明的时候才有意义。

## 17. 基于范围的for循环

这个改法就像Python那么好用，可以基于范围遍历而不是提供索引值或者迭代器才能遍历。不过要求对象类型必须定义了begin和end成员函数，或者定义了以对象类型为参数的begin和end普通函数。

以前的写法。

```c++
std::map<int,std::string> m ={{1,"hello"},{2,"C++"},{3,"World"}};
std::map<int,std::string>::iterator it = m.begin();
for(;it!=m.end();++it){
    std::cout<<"key = "<<(*it).first
        <<" val = "<<(*it).second<<std::endl;//比较啰嗦
}
// 可以使用标准库的for_each的方法，自定义仿函数
void print(std::map<int,std::string>::const_conference element){
        std::cout<<"key = "<<element.first
        <<" val = "<<element.second<<std::endl;
}
std::for_each(m.begin(),m.end(),print);
```

C++11之后可以这样写。

```c++
for(const auto&e : m){//复杂对象最好使用引用
     std::cout<<"key = "<<e.first
        <<" val = "<<e.second<<std::endl;
}
// 不是容器,普通数组也可以
int a[]={0,1,2,3,4};
for(auto e:a){ //基础类型最好使用值
    std::cout<<e<<std::endl;
}
```

C++20对范围循环增加了对初始化语句的支持，还可以这样写。

```c++
for (vector<int> v = { 1,2,3 }; auto & x:v) {//c++20
    cout << x << " ";
}
cout << "\n";
```

## 18. 支持初始化语句的if和switch

C++17以后增加了对if和switch初始化语句的支持。

初始化语句的生命周期伴随其下方的整个判断结构if，包括else和else if，但不能作用于上。

```c++
bool foo(){
    return false;
}
bool bar(){
    return true;
}
int main(){
    if (bool b=foo();b){
        ...//做些事
    }
    else if (bool c=bar();c){ // c的生命周期不在else if上边,只在下边
        ... //做些事
    }
    else{
        ... //做些事
    }
    return 0;
}
```

switch语句也可以。

```c++
#include <condition_variable>
#include <chrono>
using namespace std::chrono_literals;
std:: condition_variable cv;//一个条件变量
std::mutex cv_m;//一个锁
int main(){
    switch (std::unique_lock<std::mutex> lk(cv_m);//构造独一无二的锁
           cv.wait_for(lk,100ms))//真正的判断条件
    { // lk生命周期贯穿整个switch语句，可作用于任何case分支
        case std::cv_status::timeout:
            break;
        case std::cv_status::no_timeout:
            break;
    }
    return 0;

```

## 19.static_assert声明

静态断言出现之前都是运行时断言，即程序跑起来才会触，所以处于debug时才会使用，因为它比较粗暴直接终止程序。而关键字static_assert就可在编译期内触发断言，而不是运行。它要求传入2个实参，常量表达式和诊断信息字符串，常量表达式是因为编译期无法计算运行时才能确定结果的表达式。

```c++
#include <type_traits>
class A{};
class B:public A{};
class C{};
template<class T>
class E{
    static_assert(std::is_base_of<A,T>::value,"A is not base of T");
    // A是不是T的基类
};
int main(int argc,char*argv[]){
    static_assert(argv>0,"argv > 0");//错误,argv>0不是常量表达式
    E<C> x;//通过编译,A不是C的基类,触发断言
    static_assert(sizeof(int)>=4,"sizeof(int) >=4");//通过编译,返回真不触发断言
    E<B> y;//通过编译,不会触发断言
}
```

因为诊断字符串是个常量字符串，所以它可以被定义成宏，无需第二个参数。故C++17以后，可以不指定第二参数。

```c++
// C++17
template<class T>
class E{
    static_assert(std::is_base_of<A,T>::value);//不加第二参数
};
int main(int argc,char*argv[]){
    E<C> x;//通过编译,触发断言
    static_assert(sizeof(int)<4);//通过编译,触发断言,不加第二参数
    E<B> y;//通过编译,不触发断言
}
```

## 20. 结构化绑定

python可以实现结构化绑定的就是tuple，C++11以后也引入，但是不够简洁，这是因为必须要指定返回类型，而python可以自动做到泛型。

```C++
// c++11
#include <tuple>
tuple<int,int> func(){
    return tuple(11,2);
}
int x=0,y=0;
std::tie(x,y)=func();//必须用tie绑定2个参数
```

C++17以后可以使用auto[x,y]表达tuple，[x,y]是绑定标识符列表。

```c++
// c++17
#include <tuple>
auto func(){
    return tuple(11,2);
}
auto[x,y]=func();// auto[x,y]

// 绑定到结构体
struct S{
    int a = 43;
    string b = "cb";
}
S st;
auto[x,y]=st;//自动绑定x=a,y=b
//遍历循环的时候也很好用
vector<S> st={{1,"A"},{2,"b"},{3,"f"}};
for(const auto&[x,y]:st){ //很像for x,y in zip(a,b)..
    ...
}

// 绑定到原生数组
int a[3]={1,2,3};
auto[x,y,z]=a;

//绑定到类对象
class A{
    public: //必须是公有
    	int a=1;
    	string b="c";
}

// 且必须都定义在基类或者派生类不能桥接
class B{
    public :
    	int a=1;
}
class C : public B{
    public :
    	string b="c";
}
C ct;
auto[x,y]=ct;//不能通过编译

// 绑定到元组或者类元组,map就是类元组,pair也是
map<int,sring> m={{1,"str"}};
auto[x,y]=m;
```

## 21. noexcept关键字

暂时跳过，2022年4月10日。

## 22. 类型别名和别名模板

C++11之后，使用using替代typedef。

```c++
typedef void(*func1)(int,int);
using func2 = void(*)(int,int);
```

别名模板是把模板T也可以作为别名。

```c++
template<class T>
using int_map = std::map<int,T>;
int_map<std::string> int2string;
int2string[11]="7"; // 11作为key,"7"是val
```

## 23. 指针字面量nullptr

C++中0可以是整型常量也可以是空指针常量。

```c++
#ifndef NULL
	#ifdef _cpluscplus
		#define NULL 0
	#else
		#define NULL((void*)0)
	#endif
#endif
```

C标准认为0是整型常量或者空指针常量void * 。

为了避免二义性，C++11引入了关键字nullptr取代NULL专门表示空指针，nullptr是纯右值

## 24.三向比较

三向比较可以有三种可能的比较，但是他只能和0比或者自身。

```c++
bool b = 7 <=> 11 <0; //true
bool b = 7 <=> 11 =0; //false
bool b = 7 <=> 11 >0; //false
```

更多内容见书P203页。

## 25. 线程局部存储

跳过。。

## 26. 扩展的inline说明符

C++17之前定义类的非常量静态成员要求变量的声明和定义必须分开，除非是const类型。

```c++
class X{
    public :
    	static int a;
}
int X::a=1;
```

如果定义在头文件被其它cpp文件反复包括就造成重定义。

```c++
#ifdef X_H
#define X_H
class X{
    public :
    	static int a;
}
int X::a=1;
#endif
```

C++17之后可以使用inline。

```c++
class X{
    public :
    	inline static int a = 1;
}
```

## 27.常量表达式

内容太多，暂时跳过，书P221~P252，2022.4.10。

## 28.确定的表达式求值顺序

跳过，用处不大。

## 29.字面量优化

跳过，用处不大。

## 30. aligns和alignof

主要用于数据对齐问题，暂时跳过，2022.4.10。P268~P279。

## 31. 属性说明符和标准属性

跳过，用处不大。

## 32. 新增预处理器和宏

跳过，用处不大。

## 33. 协程

跳过，用处不大。

## 34.基础特性的其他优化

跳过，用处不大。

## 35. 可变参数模板

跳过，用处不大。

## 36. typename优化

跳过，用处不大。

## 37. 模板参数优化

跳过，用处不大。

## 38. 类模板的模板实参推导

跳过，用处不大。

## 39. 用户自定义推导指引

跳过，用处不大。

## 40. SFINE(C++11)

跳过，用处不大。

## 41. 概念和约束

跳过，用处不大。

## 42. 模板特性的其他优化

。。。咋说呢，跳过，用处不大。

