## C++新特性

### 命名空间支持inline

父命名空间内内联多个子命名空间时，如果希望使用父命名空间就可以直接使用某个子命名空间的函数，可以使用inline，就无需作用域了。好处在于，如果此函数需要升级，可以新增命名空间改为inline，同时去除原来版本命名空间的inline(因为inline空间只能有1个)。

```c++
namespace V{
    inline namespace v1{
        void foo();
    }
}
using namespace V;
foo(); // 等价于使用V::v1::foo()函数

// 当需要版本升级时
namespace V{
    namespace v1{
        void foo();
    }
    inline namespace v2{
        void foo(); // 升级版
    }
}
using namespace V;
foo(); // 等价于使用V::v2::foo()函数,客户端并不会察觉出异常
```

### auto关键字

一、**可以作为返回类型**，只要函数使用箭头→声明返回类型即可。

```c++
auto sum(int a,int b)->int;
```

二、auto是按值初始化，所以会**忽略const和volatile限定符**，以及引用。

三、auto推导数组或函数时会推导为相应的指针类型和函数指针。

```c++
int arr[5];
int func(int x,int y){return x+y;}
auto p1 = arr; // int*类型
auto p2 = func; // int(*)(int,int)类型
```

四、c++11中auto不能用于结构体成员变量初始化，但是可以加上static const可以；c++17之后取消了const限制改为inline即可。

```c++
struct S{
    // auto i = 5; error
    // const auto i = 5; error
    static const auto i = 5; // >c++11
    static inline auto j = 5; // >c++17
}
```

五、C++20之前auto不可用于函数的参数列表。

六、C++14之后auto返回类型推导强化。

```c++
template<class T1,classT2>
auto sum(T1 x,T2 y){ // c++14之后无需声明返回类型,auto进行了强化
	return x+y;
}
```

### decltype关键字

一、decltype也可以获取类型信息，相比于typeid可以在编译器获取类型，还可以获取表达式的整体类型。

```c++
int x = 0;
decltype(x) y = 0; // 可以直接作为类型使用
decltype(x+y) z = x + y ;
```

二、不同于auto，decltype可以用于**结构体中非静态成员常量**，可以在**函数形参列表**、**箭头声明返回类型**，可以**同步CV限定符**。

```c++
struct S{
    int x1;
    decltype(x1) x2; // 非static const变量,ok
}

int x1 = 0;
delctype(x1) sum(decltype(x1) x,decltype(x2) y){ // 函数参数列表
    return a1+a2;
}//或
auto sum(decltype(x1) x,decltype(x2) y) ->decltype(x+y){ // 箭头后置声明配合auto
    return x+y;
}//或
template<class T>
auto return_ref(T& t)->decltype(t){ // 返回引用的话这里要加后置声明否则auto会去除引用
    return t;
}
```

### 右值引用

右值分为纯右值和将亡值。

关联的默认成员函数有默认移动构造函数和默认移动赋值函数。**默认移动构造函数的参数必须是纯右值或将亡值，因为参数类型是2个引用符号的右值引用类型**。移动构造可以把纯右值或者将亡值直接接管过来，无需申请新的内存，提高效率，如果是默认赋值构造值传递，返回实际是局部对象，这个对象被其他对象接收时又会发生一次拷贝构造，相当于多进行了一次复制，移动构造则直接把局部对象拿过来给接收的对象。**移动赋值和移动构造同理，默认情况下，如果一个即将构造的对象赋值给已存在的对象，就会优先使用移动赋值而不是默认赋值**。

### lambda关键字

分为按值捕获、按引用捕获，捕获的变量作用域可以在**匿名函数的函数体内也可以在匿名函数所在的作用域**，所以**静态局部变量不能够被捕获**。

表达式依次是**中括号、小括号、可选限定符、可选异常抛出符、可选返回值类型以及函数体**。

可选限定符可以使用mutable，那么**按引用捕获的变量会视为按值捕获，函数体内不会影响外部**，但还是会影响函数体内部，下次还调用匿名函数时，这个**捕获的变量在函数体内部会保留上次调用产生的变化**；

异常抛出符可以使用**noexcept**表明不抛出异常；

返回值类型可以配合decltype和auto关键字，实现编译期间进行推导。

匿名函数的**中括号参数可以是this**，这样匿名函数可以使用this类型的成员变量和函数；参数**可以是“=“等号**，会捕获匿名函数所在作用域的**所有变量的值**，包括this;参数**可以是"&"引用符号**，这样捕获的是所在作用域**全部变量的引用**;如果什么参数也没有，等同于**空的函数指针，即void( * )()**。

### 支持列表初始化

STL的容器都支持**花括号列表初始化**，内部实现实际上用到了模板函数std::initializer_list< T>，该模板函数具备迭代器函数begin和end。如果希望自定义的类支持列表初始化，就可以在**构造函数中使用该模板函数**。

C++20还支持指定初始化，不过对象必须是聚合类型，且只能按照顺序初始化一次。初始化的时候使用**句点运算符跟上聚合类型的成员**进行赋值即可，但是不能混用初始化方法，即要不都用句点运算符要不都不用，不能混用。

### default和delete关键字

用于默认的特殊成员函数的添加和删除，如果想要默认生成的函数又不想要其他默认生成的或者删除析构函数等就可以在2个函数后边跟上赋值运算符等号加关键字即可

default只能用于编译器自动生成的6个默认函数(**默认构造、默认析构、默认拷贝构造、默认赋值运算函数、默认移动构造和默认移动赋值**)，例如构造函数不想自定义新的版本但是又想保留编译器生成的版本进行使用就可以使用该关键字，让编译器完成变量的初始化工作。

default可以在类的成员函数在其它文件定义时使用，但是delete不可以；

delete最好不要和禁止隐式转换关键字explicit混用，它的常见用法是如果想要禁止拷贝构造可以使用delete删除复制构造函数和operator赋值运算符函数，或者不想该函数被定义时使用。**以前的做法是声明构造函数为私有，或者只有声明没有定义**。

```c++
struct A{
    A() = default;
    int x = 0;
    int y = 1;
};
class B{
public:
    B() = default;
};
A a(); // error
A a; // ok
B b(); // error
B b; // ok
```

### 委托构造函数

以前构造函数有个缺点，就是如果有多个版本的构造函数，**可能初始化时造成不必要的大量重复代码**。即使抽离出重复代码作为一个共用函数，构造函数调用时**未必是初始化过程，实际上是个赋值过程**，进行了两次操作也会造成效率底下。

现在委托构造函数引入后，每个构造函数都可以委托另一个构造函数代理，它自己也可以是代理构造函数被别的构造函数调用。要注意，**代理构造函数先执行，然后是委托构造函数执行**。

**避免循环委托**，会产生未定义行为且编译器不会报错。

委托构造函数**不能使用参数列表初始化**，这可能会造成多次初始化。

### 构造函数继承

派生类本不需要继承基类的构造函数，这是因为初始化派生类对象必然会调用基类的构造函数。

有几个事项要注意：

**派生类声明签名相同的构造函数会自动禁止继承基类的构造函数**；

**派生类不能继承多个签名相同的构造函数**；

**基类的构造函数不能为私有**，否则不能被继承；

派生类的构造函数继承通过使用using即可实现。

```c++
class Base{
    public:
    	Base():x(0),y(.0){}
    private:
    	int x;
    	double y;
}
class Derived: public Base{
    public:
    	using Base::Base; // 关键一步
    	// Derived(int x, double y):Base(x,y){} 等价
}
```

### 枚举类型加强

强枚举类型是在enum关键字后边加上class即可。

以前的枚举类型**可以隐式提升为整型，现在不可以隐式转换**，但是可以指定枚举类型的底层类型(默认是int)；

以前的枚举类型会有**作用域问题**，如果2个枚举类型部分成员重合会导致重定义，只能通过命名空间来隔离开，现在的枚举类型自带作用域，通过作用域符号就可以分为2个名称一样的枚举类型。

```c++
enum class School{
    student;
    teacher;
}
enum class Company{
    student;
    manager;
}
School sch = School::student; // 2个student不会冲突
Company cpy = Company::student;
```

以前和现在的都可以指定类型。

```c++
enum Q1{a,b,c};
enum Q1:int{a,b,c};
enum Q1:short{a,b,c};
enum Q1:long{a,b,c};

enum class Q1{a,b,c};
enum class Q1:int{a,b,c};
enum class Q1:short{a,b,c};
enum class Q1:long{a,b,c};
```

### override和final关键字

override**可以告诉编译器当前的函数需要重载基类的某个虚函数，会检查重写规则**，有助于避免打字错误、函数签名不一致例如漏写引用传递符号、函数的const常量性没被继承。

final则是告知不能被派生类继承这个虚函数，防止派生类的同名函数意外的重载了自己的虚函数；如果是用在类上，就是说不能被继承。

### 基于范围的for循环

这个是基于拥有begin、end迭代器机制的容器类来说的，可以在for语句内使用**auto配合冒号**遍历容器元素。C++20之后，for语句还增加了对**初始化语句的支持**。

```c++
for (vector<int> v = { 1,2,3 }; auto & x:v) {//c++20
    cout << x << " ";
}
```

### 静态断言函数

不同于常规的assert函数会在程序运行时检查条件，不满足时直接暴力终止程序，静态断言static_assert可以在编译期反馈出问题。

要求传入2个实参，**第1个参数是常量表达式**例如某个参数大于0或者恒等于某个数等等，**第2个参数是诊断信息字符串**，也就是断言失败的反馈信息。

### 结构化绑定

结构化绑定的数据类型就是元组tuple，这个类型在**C++11时需要指定类型并使用tie函数解包**；

```c++
tuple<int,int> func(){return tuple(11,2);} // 必须指定返回类型
int x,y;
std::tie(x,y) = func(); // 使用tie解包
```

新特性时可以使用**auto自动推导结构化数据类型**，并使用**中括号自动解包元素**。

```c++
auto func(){return tuple(11,2);} // c++17
auto[x,y]=func();
```

**聚合类型的结构体或类对象**、**原生数组或者是Map类型**的话可以使用auto和中括号自动解包。

### noexcept关键字

noexcept引入的一个原因是有时候**不关心异常类型，只是关系是否有异常**，而throw关键字必须要带上异常列表参数；

noexcept不仅是说明符也是运算符。说明符的功能上可以**指示函数是不抛出异常的但不是一定不抛出异常**，只是一种承诺；运算符的功能是因为**noexcept可以接受bool类型的常量表达式**，依据某条件决定是否承诺不出异常。

```c++
T copy(const T& rhs)noexcept(std::is_fundamental<T>::value){ 
    // T是基础类型的话不跑出异常
    ...
}
```

noexcept默认在构造函数、复制构造函数、移动构造函数，赋值函数，移动赋值函数都声明为true；**析构函数比较特殊，即使是自定义的也声明为不抛出异常，除非显示的指定false**。

### constexpr关键字

c++11之前，除非是const的纯常量才能作为数组的大小，如果某个函数返回常量值5，这个函数整体的调用被使用在数组大小的声明上是不能通过编译的，但是**使用constexpr代替const**就可以。

```c++
int x = 5; const int y = 10;
int arr[x];// error
int arr[y]; // ok

int func(){return 5;} // or
const int func(){return 5;}
int arr[func()]; // error

constexpr int func(){return 5;}
constexpr int x = 5;
int arr[x]; //ok
int arr[func()]; // ok
```

constexpr函数中**必须有返回值且用constexpr修饰，必须是常量表达式，必须只有1条语句，函数形参有的话替换到语句中也必须是常量表达式**，否则都可能导致constexpr失败；

**constexpr还可以和if判断语句结合使用**，但是这个条件必须是编译期能确定结果的常量表达式，常常用于模板函数或者依据条件编译某段代码否则编译另一段代码；

```c++
void f(){
    if constexpr(sizeof(int)>sizeof(char))
        cout<<"sizeof(int)>sizeof(char)\n";
    else cout<<"sizeof(int)<=sizeof(char)\n";
}
```

## 设计模式

### UML图的常见关系

继承关系；空心三角+实线

实现接口；空心三角+虚线

组合关系；实心菱形+实线箭头

聚合关系；空心菱形+实线箭头

关联关系；实线箭头表示

依赖关系；虚线箭头表示

### 简单工厂模式

首先所有的策略抽象出一个**策略基类**，每种**策略具体类**都是该基类的派生类；

然后定义一个**工厂类**，工厂函数作为其成员函数，它会返回客户要求的策略具体类的实例。

缺点在于，工厂函数可能具有比较复杂的逻辑，很可能**违反高内聚责任分配的原则**。策略变多时可能**难以依据条件去返回不同的实例**，从而导致模块功能拓展难以维护，这种缺点在[工厂方法模式](#工厂方法模式)得到克服。

下方的例子：具体的产品是3种水果，都继承自水果抽象类；还有一个工厂，工厂函数返回水果类型，依据客户段代码提供的枚举值来返回这样的水果。

涉及的问题很明显：switch-case逻辑不好维护；**客户端需要同时知道工厂类、水果抽象类和水果具体类**。

```c++
class Fruit {
public:
    enum class fruitType { Apple, Orange, Banana };
    virtual void what_am_i() { cout << "I am Fruit\n"; }// 缺省实现
};
class Apple : public Fruit {
    public:
        void what_am_i() override{ cout << "I am Apple\n"; }
};
class Orange : public Fruit {
    public:
        void what_am_i() override{ cout << "I am Orange\n"; }
};
class Banana : public Fruit {
    public:
        void what_am_i() override{ cout << "I am Banana\n"; }
};
class FruitsFactory {
public:
    Fruit* createFruit(Fruit::fruitType type) {
        typedef Fruit::fruitType types;
        Fruit* fruit = nullptr;
        switch (type) {
            case types::Apple:fruit = new Apple(); break;
            case types::Orange:fruit = new Orange(); break;
            case types::Banana:fruit = new Banana(); break;
        }
        return fruit;
    }
};
int main()
{
    FruitsFactory factory;
    Orange* orange = dynamic_cast<Orange*>(factory.createFruit(Fruit::fruitType::Orange));
    orange->what_am_i();
    return 0;
}
```

### 工厂方法模式

工厂方法模式在于，**工厂本身也有抽象工厂**，它是一个**某一类策略的超级工厂，只是提供一些规范，真正的创建动作留给派生类完成**。这样不同策略的制造分给不同的工厂具体类去完成，分摊开高内聚的逻辑，更符合**单一权责原则**，同时也真正实现了**开放-闭合原则**，支持拓展，不支持已有的代码修改。

客户端**使用create()不再需要枚举值形参指定创建的类型**，所以无需知道水果抽象类中定义的水果枚举值，但是仍然需要知道具体的工厂类型。

```c++
// Apple、Banana和Orange没有变化，Fruit类可以去除fruitType枚举类型的定义
// FruitsFactory去掉,改为以下4个工厂类
class AbstractFruitsFactory {
    public:
        virtual Fruit* create() const = 0; // 纯虚函数,必须被继承定义
};
class appleFactory :public AbstractFruitsFactory{
public:
    // 这里还可以继续定义不同的苹果类型拓展,例如按照地区分类，这4类苹果可以继承Apple
    // enum class appleType {northApple,southApple,eastApple,westApple};
      Fruit* create()  const override{
          Apple* apple = new Apple; // 如果有更多的苹果类型,这里就可以增加逻辑
                                    // 每个水果类型都是如此,不同的水果被不同的工厂接管
          return apple;
    }
};
class orangeFactory : AbstractFruitsFactory {
public:
    Fruit* create() const override{
        Orange* orange = new Orange;
        return orange;
    }
};
class bananaFactory : AbstractFruitsFactory {
public:
    Fruit* create() const override{
        Banana* banana = new Banana;
        return banana;
    }
};
int main()
{
    appleFactory aFactory;
    Apple* apple = dynamic_cast<Apple*>(aFactory.create());
    apple->what_am_i();
    return 0;
}
```

### 抽象工厂模式

抽象工厂模式是对工厂方法模式进一步抽象，工厂方法模式是一个产品系列一个工厂类，抽象工厂模式是**多个产品系列一个工厂类**；

工厂方法中不同的水果统一使用create方法创建，但是交给不同的工厂执行。现在如果有更复杂的逻辑，例如每种水果还分为东部和西部产地的区别，即苹果、香蕉和橘子还会各自有2个子类继承。

```c++
class Fruit {public:virtual void what_am_i() { cout << "I am Fruit\n"; }};

class Apple : public Fruit {public: void what_am_i() override { cout << "I am Apple\n"; }};
class eastApple :public Apple { public: void what_am_i() override final{ cout << "I am East Apple\n"; } };
class westApple :public Apple { public: void what_am_i() override final { cout << "I am West Apple\n"; } };

class Orange : public Fruit {public: void what_am_i() override { cout << "I am Orange\n"; }};
class eastOrange :public Orange { public: void what_am_i() override final { cout << "I am East Orange\n"; } };
class westOrange :public Orange { public: void what_am_i() override final { cout << "I am West Orange\n"; } };

class Banana : public Fruit {public:void what_am_i() override { cout << "I am Banana\n"; }};
class eastBanana :public Banana { public: void what_am_i() override final { cout << "I am East Banana\n"; } };
class westBanana :public Banana { public: void what_am_i() override final { cout << "I am West Banana\n"; } };
```

现在客户想要获取一个西部产的苹果，如果还使用工厂方法模式，要创建3×2共6个工厂，加上原有的3个工厂，显然数目太多不好维护，而且客户使用的时候还必须知道这6个具体工厂。

现在提供新的方法，把3个水果可以看成3种不同的产品系列，抽象工厂不是只定义1个create函数，而是定义3个create函数，分别用于创建不同的水果，然后东部和西部各有1个工厂继承抽象工厂，客户端就无需再了解6个具体工厂类，只需要了解2个东西部工厂即可，降低了工厂的复杂度。

```c++
class AbstractFruitsFactory {public:
    virtual Fruit* createApple() const = 0;
    virtual Fruit* createBanana() const = 0;
    virtual Fruit* createOrange() const = 0;
};                
class eastFactory: public AbstractFruitsFactory {
public:
    eastApple* createApple() const override final {
        eastApple* apple = new eastApple;
        return apple;
    }
    eastOrange* createOrange() const override final {
        eastOrange* orange = new eastOrange;
        return orange;
    }
    eastBanana* createBanana() const override final {
        eastBanana* banana = new eastBanana;
        return banana;
    }
};
class westFactory : public AbstractFruitsFactory {
public:
    westApple* createApple() const override final {
        westApple* apple = new westApple;
        return apple;
    }
    westOrange* createOrange() const override final {
        westOrange* orange = new westOrange;
        return orange;
    }
    westBanana* createBanana() const override final {
        westBanana* banana = new westBanana;
        return banana;
    }
};
int main()
{
    eastFactory fac1; // 只需要了解存在西部or东部工厂即可
    westFactory fac2;
    eastApple * apple = fac1.createApple();
    westOrange* orange = fac2.createOrange();
    apple->what_am_i();
    orange->what_am_i();
    return 0;
}
```

## 转型动作

### const_cast

const_cast<T>(expression)，用于剔除对象的常量性，但是只能将const type * 转换为type * ，将const type&转换为type&，其它的完全一致。

```c++
int a = 1;
int *ptr = const_cast<int *>(&a);
```

### dynamic_cast

dynamic_cast<T>(expression)，作用是将**基类对象指针（或引用）转换到派生类指针**，dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理。**T类型必须是类的指针或引用或void * 指针**；

使用**dynamic_cast检查时要求基类必须有虚函数**，否则编译出错。这是因为此**转型动作会检查类的信息**，而类的信息储存在虚函数表，而虚函数表必须有虚函数；

dynamic_cast**允许交叉转换，**即2个继承同一基类的子类可以互相转换；

类层次间进行**上行转换**时，dynamic_cast和**static_cast的效果是一样的**；进行**下行转换**时，dynamic_cast具有**类型检查**的功能，比static_cast**更安全**，**如果不能进行转换会返回空指针**，而后者直接转换基类指针为派生类指针就造成这个**指针访问派生类特有的成员时出现问题**；

下方的例子，如果func实际传入的是D类型，2种方法都是安全的，p1和p2都成功转为D类型，D->D不会有问题；如果传入的是B类型，p1虽然可以使用static_cast转换为D类型但是不安全，它无法访问D的成员m_szName。

```c++
class B{
    public:
        int m_iNum;
        virtual void foo() const{
            cout<<"c++"<<endl;
        }
};
class D : public B{
    public:
        virtual void foo() const override final{
            cout<<"python"<<endl;
        }
        string m_szName;
};
void func(B* p){
    D* p1 = static_cast<D*>(p);
    D* p2 = dynamic_cast<D*>(p);
    cout<<boolalpha<<(p2==nullptr)<<endl;
    cout<<"p1: num = "<<p1->m_iNum<<" name = "<<p1->m_szName<<endl;
    cout<<"p2: num = "<<p2->m_iNum<<" name = "<<p2->m_szName<<endl;
}
int main()
{
    string name = "cb";
    B b;b.m_iNum = 10;
    D d;d.m_iNum = 20;d.m_szName = name;
    func(&d); 
    /*
    	false
        p1: num = 20 name = cb
        p2: num = 20 name = cb
    */
    func(&b);
    /*
        true
        p1: num = 10 name =  p1本是B指针转换为D指针无法访问D的成员
        					 p2直接没输出,p2是空指针	
    */
}
```

### reinterpret_cast

reinterpret_cast<T> (expression)，T必须是一个指针、引用、算术类型、函数指针或者成员指针；

reinterpret_cast可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针；

reinterpret_cast只是提供一个不同的解释方式，但是位层面并没有进行二进制转换；

例如下方**多重继承**的例子，**static_cast计算了父子类指针转换的偏移量**，并将之转换到正确的地址（D里面有m1,m2，转换为B2*指针后指到m2处，偏移4个字节），而**reinterpret_cast却不会做这一层转换**。

```c++
class B1 {
public:
    int m1;
};
class B2 {
public:
    int m1;
};
class D : public B1,public B2 {};
int main()
{
    D d;
    printf("%p, %p, %p\n", &d, reinterpret_cast<B1*>(&d), static_cast <B1*>(&d));
    printf("%p, %p, %p\n", &d, reinterpret_cast<B2*>(&d), static_cast <B2*>(&d));
    /*
    	000000161AD4F648, 000000161AD4F648, 000000161AD4F648  (指向int m1处)
		000000161AD4F648, 000000161AD4F648, 000000161AD4F64C  (指向int m2处)
    */
    return 0;
}
```

### static_cast

static_cast<T>(expression)，用来进行强迫隐式转换，因为**不进行类型检查**，所以对基类是否有虚函数没有限制，所以也不安全；

static_cast**不能用于交叉转换**；

static_cast可以用于空指针转换为目标类型的空指针；

static_cast可以用于基本类型进行转换，例如int和char、int和enum等，需要自行检查类型安全；

static_cast可以转换任何类型到void * 类型；

static_cast不**能去除限定符**，例如const、volatile属性；

static_cast在多重继承中可以**计算父子指针的偏移量使之指向正确的位置**。

## 资源管理

### RAII的含义

获得资源后立刻放入管理对象，也就是资源取得时机就是管理类对象的初始化时机；

管理类内部运用析构函数来确保资源可以被释放。

### 智能指针

auto_ptr已被弃用，它的性质是**调用拷贝和赋值函数时获得资源的专有权**，被复制的指针则成为空指针，也就是说它不能进行引用计数；

shared_ptr，可以让**多个指针共享同一份资源，相应的增加引用计数**，当引用计数为0时会自动销毁资源。缺点在于2个指针互指会导致**环状引用，引用计数变成了2**，当指针离开作用域时它们都不能被析构导致内存泄漏；构造shared_ptr最好**使用make_shared()<>而不是默认构造函数创建**，这样可以保证new和delete是对称使用的。该指针**只有箭头、解引用和逻辑运算符**，没有加减，加加，减减和索引运算符。常见的成员函数**use_count()**获取引用次数，**reset()**取消与原指针的关联，**get()**获取绑定的底层指针等；

unique_ptr，

weak_ptr，

## 类的性质

### 继承、多态

**多态可以不依赖于继承**，可以通过**定义一个枚举类型，作为一个外部接口函数的参数，内部依据参数定义具有不同性质的实例**。外部使用这个外部接口口函数传入不同的枚举值就会得到不同的实例，这是一种编程技巧得到的多态；

多态利用继承实现的关键前提是**找出所有子类共通的行为，让这些行为函数声明为虚函数并确定每个操作行为的访问权限**；

多态基类的析构函数**一定要声明为vritual函数**，又因为析构函数不要定义为纯虚函数，所以要声明一个非纯虚函数；基类的对象应由基类的析构函数销毁，但是因为基类的指针可以指向子类，所以**指向子类的基类指针真正销毁时应调用子类的析构函数**，但是只有**析构函数是虚的才能保证销毁时动态的调用子类的析构函数**，否则调用的是基类的析构函数导致子类成分未被销毁。

类只要**有任何虚函数就应该有一个虚析构函数**，且如果类不作为基类使用就不要声明虚析构函数。

基类的虚函数如果有缺省参数值，派生类不要重定义这个缺省参数，因为缺省参数是静态绑定，基类指向派生类对象的指针使用的时候依然使用基类的缺省参数。

### 访问权限public、private和protected



### 纯虚函数、非纯虚函数和非虚函数

纯虚函数的含义是指明**类的接口必须被继承，派生类必须给出接口的定义**。**基类不能给出纯虚函数的缺省实现，但是可以提供一份定义**，如果子类的接口定义仍然想**继承基类的实现使用using声明**声明父基类作用域或者直接使用作用域符号来**转交给基类提供的定义**进行实现；

非纯虚函数的含义是**类的接口和定义都被继承，且派生类的定义能(不强制)覆盖基类的定义**。不强制是因为基类可以**提供缺省的实现**，此函数可以直接被派生类继承不做任何改动；

非虚函数的含义是**类的接口和定义都被继承**，但不**希望派生类去重定义它**，只会使用基类提供的唯一一份定义；

**析构函数不要定义为纯虚函数，多态性质的话也不能声明为非虚函数**；

析构函数**不要抛出异常**，如果有应当直接捕捉然后终止程序；

析构函数和构造函数中**不要调用虚函数**；

**静态成员函数不能声明为虚函数**；

```c++
class A{
    public:
    	virtual ~A(){} // 析构函数不要设为纯虚函数
    	virtual const char* className() const = 0; // 纯虚函数
    	virtual const char* baseName() const{ // 非纯虚函数,缺省实现
            return "A";
        }
    	int vec_size(){return vec.size();} // 不希望派生类重载它
    	const static int max_size(){return max_size;} // 静态函数不能声明为虚函数
    private:
    	static vector<int> vec;
    	const static int max_size = 1024; // const static允许声明时即定义
}
```



### 成员模板函数

可以了解一下，类可以具有模板，成员函数也可以有自己的模板。

```c++
template<typename Ostream>
class A{
 	public:
    	A(Ostream& os):os(os){}
        template<typename T> // T类型的成员模板函数
        void print(const T&val,char sep = '\n'){
            os << val << sep;
        }
    private:
    	Ostream& os; //意味着必须初始化
}
A<ostream> out(cout); // 定义ostream类型的A
out.print("123"); // const char* ok
out.print(123); // int ok
```

## 关键字

### const关键字

修饰指针，可分为指针常量和常量指针；

修饰成员函数，**可以声明为常量性函数，同时也要修饰返回类型为const，否则与函数的常量性违背，因为如果返回的是引用或者指针类型，类外就可以修改指向的地址内容**。返回类型用const修饰本其实是个好习惯，因为返回类型不是const的话就是可赋值的，可能会有人写成a*b = c的形式。意思是operator * 函数返回的类型(a * b )整体是可以赋值的，所以才有这种写法，但是这样的写法没什么意思，所以可以用const修饰来阻止这种写法；如果**不是常量性函数，返回类型可以修饰const也可以不修饰**，不过加上const修饰是个不错的习惯。

修饰**函数参数，配合引用传递**，可以不改变原有变量且提高传递效率；

### mutable关键字

这个关键字可以用于去除变量的常量性。

在**匿名函数的可选限定符出现**过，它表示的含义是**捕获的变量视为按值捕获的按引用捕获的中间状态**。按值捕获是不会改变外部变量，多次调用匿名函数时也不会改变捕获的值；按引用捕获会改变外部变量值，同时每次调用匿名函数的结果不同，这是外部变量改变的影响导致；还有就是中间状态，**视为按值捕获不改变外部变量，但是每次调用匿名函数的结果还是不同的，会保留上次调用匿名函数的影响**；

另一个就是类的常量性成员函数，按照const的要求这个函数不能修改类的任何成员，但是**如果又希望某些变量不受此限制**，就可以使用该关键字。

```c++
class Text{
    public:
    	int length() const{//常量性函数
            if (!lengthIsValid){ // 如果长度无效
                textLength = strlen(text);// 计算长度
                lengthIsValid = true;// 有效状态
            }
            return textLength;
        }
    private:
    	char * text;
    	// 如果不加mutable,上边的函数体是不能修改这2个成员的
    	mutable int textLength;
    	mutable bool lengthIsValid;
}
```



### static关键字



### explicit和implicit关键字

默认情况下，类的构造函数都是implicit，如果不希望隐式转换可以使用explicit声明；

隐式转换是指**类的实例被类构造函数的参数类型对象进行赋值时**会发生隐式转换，例如某个类A的构造函数参数为int类型，这个A的实例a就可以直接a=1，这可能产生误解a是个int类型；

使用explict之后，就只能通过**小括号参数列表来构造**实例，**不能通过等号**进行隐式转换；

构造函数有**2个参数及以上(如果是2个参数,第2个参数不能有默认参数)**，那么就不会产生隐式转换；

### inline关键字

inline函数适用于短小型、反复需要调用的函数，这样的函数会在**调用点处直接复制一份函数体代码执行**，节省调用操作的成本；

inline函数的定义一般直接放在头文件，如果**类的成员函数声明时即定义就会自动成为inline函数**；

**class本体内实现的函数定义**都隐式的使用了inline；

 inline只是对编译器的一个申请，不是强制命令；

不要将析构函数或者构造函数声明为inline，即使代码没有任何实现；

### extern关键字

extern变量的**声明和定义可以不在同一文件，但是记住定义只有一次**；例如，如果a文件声明变量k，b文件进行定义需要这样写。如果当前工作文件是b.cpp，从b.cpp的角度是**变量在外部声明在本文件定义**，该**全局变量作用域从变量的定义开始到文件末尾**，若在定义之前出现引用就会报错；

```c++
// a.cpp
extern int k; // 声明
// extern int k = 6; //error

// b.cpp
extern int k = 5; // 定义
int main()
{
    printf("k=%d\n",k);
}
// g++ a.cpp -o a
```

如果a.cpp定义了一个全局变量，b.cpp想要引用这个变量，对b.cpp来说这个变量就是**外部文件定义的，本文件是声明拿来用的**；

```c++
// a.cpp
int k = 10; // 定义

// b.cpp
int main()
{
    extern int k; // 声明
    printf("k=%d\n",k);
}
// g++ -c a.cpp; g++ -c b.cpp; g++ a.o b.o -o out; /.out.exe
```

外部变量还可以在头文件中定义，因为头文件可以被多次包含，可能出现重定义的情况。非必要，**不要在头文件中定义全局常量或者外部变量**。

## 杂项知识点

### STL迭代器分类

**输入、输出和前向迭代器**，istream_iterators和ostream_iterators是其代表，每次只能单向向前移动，且**只能读或者写一次**；前向迭代器区别是可以多次读写；

双向迭代器，**2个方向都可以走**，例如双向链表的迭代器；

随即存储迭代器，可以**常量时间前后跳跃任意距离**，在map和set使用；

关联比较密切的函数是**advance**函数，**可以将某个迭代器移动某个距离**。

### 结构体字节对齐

**结构体的大小一定要为有效对齐值的整数倍，当没有明确指明时，以结构体中最长的成员的长度来对齐**。

当用**#pragma pack(n)指定时，以n和最长成员中长度较小的值来对齐**，这里n是字节数。

也可以使用**__ attribute __((aligned(n)))**分配字节。

**结构体成员变量是从低位到高位的**。

经典的例子。

```c++
struct s1{
	char a; // 1
    // 3空字节
    int b; // 4
} ss1;sizeof(ss1) = 8;

struct s2{
    char a; // 4
    int b; // 4
    char c; // 4
} ss2;sizeof(ss2) = 12;

struct s3{
    char a; // 1
    char b; // 1
    // 2空字节
    int c; // 4, c在2个char之前也可以
} ss3;sizeof(ss3) = 8;
```

### 常量指针和指针常量

常量指针是指向常量的指针，指针本身可以移动；

指针常量本身不可以移动，指向的值可以改变；

引用本质上就是1个指针常量，一经初始化便不可再更改。

```c++
int a = 1;
// 以下为常量指针
const int *pa1 =&a; 
int const *pa2 = &a; 

// 以下为指针常量
int * const pa3 = &a;
```

### 指针与数组的关系

首先总结：

一维值数组int[]指针类型是 **int * 也可以是 int (*)[]**，分别指向一维值数组的本身和地址；

一维指针数组int* [] 指针类型是 **int * * 或者int * (*)[]类型**，分别指向一维指针数组的本身和地址；

二维值数组int[] []指针类型是 **int (*)[] 或 int ( *)[] []类型**，分别指向二维值数组的本身和地址；

二维指针数组int* ( *[])[]指针类型是 **int * ( * * )[]类型或int ( * ( * ) [])[]**，分别指向二维指针数组的本身和地址。

一维**值**数组的2种指针：

```c++
int a[3]; // 一维值数组 int[]类型
int * p = a; // 指向数组名,p的地址就是&a[0],是int*类型,p可以访问数组元素
int (*q)[3] = &a; // 指向数组名的地址,q代表了这样一串连续的内存,也就是指向具备3个元素的数组,是int(*)[]类型,当q移动时一次性移动3个int的长度,q不能访问元素
```

一维**指针**数组的2种指针：

```c++
int a1=1,a2=2,a3=3;int* a[3] ={&a1,&a2,&a3}; // 一维指针数组 int*[]类型
int ** p = a; // p的地址是&a[0]也就是&&a1,是int**类型,p可以访问数组元素
int *(*q)[3] = &a; // 指向数组名的地址,也就是具备3个指针的数组,也就是int *(*)[]类型,q不能访问元素,q移动时一次性移动3个int*的长度
```

二维**值**数组的2种指针：

```C++
int a[3][5]; // 二维值数组int[][]类型
int (*p)[5] = a; //把二维数组看成是具备3个指针元素的一维指针数组,只不过每个指针指向具有5个元素的数组,p又指向数组名,所以p的指针类型也是int(*)[],p移动可以指向二维数组每行首元素

int (*q)[3][5] = &a; // 这是升级版,把a视为1个整体,q指向了这样的内存布局,q移动不能访问元素,而是跳过了这样的连续内存,q是int(*)[][]类型
```

二维**指针**数组的2种指针：

```c++
int a1=1,a2=2,a3=3;
int b1=1,b2=2,b3=3;
int * a[3] = {&a1,&a2,&a3}; // 一维指针数组, int*[]类型
int * b[3] = {&b1,&b2,&b3}; 
int *(*k[2])[3] = {&a,&b}; // 二维指针数组, int*(*[])[]类型

int *(**p)[3] = k; // p是int*(**)[]类型,指向具有2个指针元素的一维指针数组,只不过每个指针元素还指向了具有3个元素的数组,所以p移动可以访问那2个指针元素

int (*(*q)[2])[3] = &k; // 或者直接把k具有的内存布局作为整体看待,q指向了这样的布局,不能访问元素,是int(*(*)[])[]类型
```



### 函数对象

函数对象定义在头文件<functional>中，是某个类对**小括号符号重载**函数的对象实例，它和**函数指针、匿名函数一样可以作为某种策略的实现**；

函数对象类型主要分为算术运算、关系运算和逻辑运算类型。例如算术运算定义了**加减乘除取模取相反数**，关系运算则是**小于大于等于小于等于大于等于和不等于**，逻辑运算就是**与或非**了；

```c++
plus<T>();minus<T>();negate<T>();multiplies<T>();divides<T>();modules<T>();
less<T>();less_equal<T>();greater<T>();
greater_equal<T>();equal_to<T>();not_equal_to<T>();
logical_and<T>();logical_or<T>();logical_not<T>();
```

函数对象还涉及**适配器**的问题，引入2个函数**bind1st和bind2nd，可以把指定值绑定到函数对象的第1或第2操作数**，可以把二元函数对象当成一元函数对象使用；

```c++
inline binder2nd<_Operation> bind2nd(const _Operation& __fn, const _Tp& __x){
    typedef typename _Operation::second_argument_type _Arg2_type;
    return binder2nd<_Operation>(__fn, _Arg2_type(__x));
} 
bind2nd(less<int>,val); // x<y变成x<val的用法
```

另外2个适配器函数是not1和not2。not1针对一元运算，也就是逻辑运算与或非；not2针对二进制函数对象比较多；

```c++
while ((iter = find_if(iter,vec.end(),not1(bind2nd(less<int>,10))))!= vec.end());// 代码的意思采取所有小于10的元素相反的策略,也就是找到所有≥10的元素
```



