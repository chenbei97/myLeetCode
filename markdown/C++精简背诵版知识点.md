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

纯右值，可以是**纯粹的字面量**，例如10、true、nullptr；要么是右值表达式，例如10+20；还可以是**值传递时返回的临时变量**、运算表达式产生的临时变量、 原始字面量、**Lambda 表达式**等都属于纯右值。

**字符串**字面量只有在**类中才是右值**，当其位于普通函数中是左值。

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

```c++
class MagicFoo {
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) { // 允许初始化列表构造
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
};
```



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

### enum类型加强

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

### function函数对象包装器

std::function是一个函数容器，需要头文件<functional>，可以包装函数指针也可以包装lambda表达式，c++11使用这个函数统一了这些概念，比直接使用它们更加安全。

```c++
int get_para(int para) {return para;}
std::function<int(int)> func1 = get_para; // 使用func1比使用get_para更加安全
int val = 10;
std::function<int(int)> func2 = [&](int value) -> int {
        return 1+value+val; // lambda表达式也可以被封装,func2比lambda更加安全
};
```







### tuple结构化绑定

结构化绑定的数据类型就是元组tuple，这个类型在**C++11时需要指定类型并使用tie函数解包**；

```c++
tuple<int,int> func(){return tuple(11,2);} // 必须指定返回类型
int x,y;
std::tie(x,y) = func(); // 使用tie解包
```

新特性时可以使用**auto自动推导结构化数据类型**，并使用**中括号自动解包元素**。如果使用std::get<T>函数也是可以的，需要指定获取的元素类型，但对有多个相同类型元素的tuple是不能使用的。

```c++
auto func(){return tuple(11,2);} // c++17
auto[x,y]=func();

std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
std::get<std::string>(t); // ok
// std::get<double>(t); // 错误
```

**聚合类型的结构体或类对象**、**原生数组或者是Map类型**的话可以使用auto和中括号自动解包。

构造元组对象可以使用make_tuple函数。

```c++
std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}
```

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

### 支持template变长参数

就是在**模板参数使用省略号...**，如果需要解包参数，可以使用**sizeof...**来计算参数的个数。

```c++
template<typename T, typename... Ts>
void print(T value, Ts... args); // Ts是变长参数

template<typename... Args> void myPrint(const std::string &str, Args... args){
	std::cout << sizeof...(args) << " "; // 计算参数个数
    print(str, args...);
    printf("\n");
}
```

## 设计模式

### UML图的常见关系

**继承关系**：空心三角+实线；

**实现接口**：空心三角+虚线；

**组合关系**：实心菱形+实线箭头；

**聚合关系**：空心菱形+实线箭头；

**关联关系**：实线箭头表示；

**依赖关系**：虚线箭头表示。

### 常见设计原则

**单一职责原则**：一个类应当只有一个原因会引起它改变。

**开放封闭原则**：对软件实体(模块、类和函数)的拓展是开放的，对更改是封闭的。

**依赖倒转原则**：抽象不应倚赖细节，细节应该依赖抽象，或者说针对接口编程而不是实现。**应用此原则的典型模式有迭代器模式和命令模式**，我们熟知的是容器类管理迭代器，发布者类管理命令，但是造成紧耦合。现在反过来让容器类、发布者类作为迭代器类和命令类的私有属性，并提供设置容器类和发布者类的方法。

**迪米特法则**：如果两个类不必彼此直接通信，那么这两个类不应发生直接的相互作用。若其中一个类需要调用另外一个类的某个方法时可以借助第三者转发这个调用。典型的应用模式是**中介者模式**。

**里氏代换原则**：软件实体使用的是父类的话，那么它一定可以用于子类，因为子类有自己的行为之前先是父类。

------

**更像设计原则说明的模式。**

### 策略模式

策略模式是指把一系列有共性的但是又独立的方法分别封装成类，它们共同继承一个抽象类，**调用函数的参数可以使用基类指针**，这样可以保证调用方法的接口是一致的，无需因为不同方法导致调用的方式不同。策略模式在工厂模式可以结合使用。

### 外观模式

是一种通过为多个复杂的子系统提供一个一致的接口，而使这些子系统更加容易被访问的模式。2个优点，第一降低**子系统与客户端之间的耦合度**，使得子系统的变化不会影响调用它的客户类。第二**降低大型软件系统中的编译依赖性**，因为编译一个子系统不会影响其他的子系统，也不会影响外观。

### 模板方法模式

模板方法是指，**把不变的行为搬移到基类**，可以去除子类中重复的代码达到复用的目的。例如STL容器类有一些固定的方法，empty、size、capacity等，这些都定义成非虚函数，派生类依然可以使用这些函数进行复用。

### 桥接模式

优先**利用聚合和组合(has-a)而不是继承**来实现功能。聚合是弱的拥有关系，两方虽然有联系但是不是另一方的一部分(例如1个男人和一群男人的关系)；组合是强的拥有关系，一方是另一方的一部分(例如1个男人和他的家庭的关系)。

桥接模式的核心就是，把一个基类作为私有属性**被另一个基类管理**，这在后边涉及的装饰、代理、适配器、建造者、状态、命令、中介者、组合、职责链、迭代器模式都使用过，组合和职责链模式则是**把自己作为私有属性**进行管理。

### 享元模式

可以运用共享技术来有效地支持大量细粒度对象的复用，通过共享已经存在的对象来大幅度减少需要创建的对象数量。核心技术就是**享元工厂定义一个哈希表私有属性，键值是享元基类**，所以可以存储任何享元具体类。哈希表可以检查这个对象是否已经存在，不存在则创建，已存在直接返回已存在的实例。

### 解释器模式

给要分析的对象定义一个语言，并定义该语言的文法表示，再设计一个解析器来解释语言中的句子。常用于对简单语言的编译或分析实例中，必须先了解编译原理中的"文法、句子、语法树"等相关概念，比较少使用。

------

**工厂系列的模式。**

### 简单工厂模式

首先所有的策略抽象出一个**策略基类**，每种**策略具体类**都是该基类的派生类；

然后定义一个**工厂类**，它会返回客户要求的策略具体类的实例，**需要负责所有产品的构建**。

缺点在于，工厂函数可能具有比较复杂的逻辑，很可能**违反高内聚责任分配的原则**。策略变多时可能**难以依据条件去返回不同的实例**，从而导致模块功能拓展难以维护，这种缺点在[工厂方法模式](#工厂方法模式)得到克服。

下方的例子：具体的产品是3种水果，都继承自水果抽象类；还有一个工厂，工厂函数返回水果类型，依据客户段代码提供的枚举值来返回这样的水果。

涉及的问题很明显：switch-case逻辑不好维护；**客户端不仅需要知道工厂类，还要知道所有水果具体类**。

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

工厂方法模式在于，工厂本身也有抽象工厂，它只是提供一些规范，真正的创建动作**留给派生类工厂完成**。不同产品的制造分给不同的工厂具体类去完成，**每个工厂负责一种产品的构建**，分摊开高内聚的逻辑，更符合**单一权责原则**，同时也真正实现了**开放-闭合原则**，支持拓展，不支持已有的代码修改。

客户端**使用create()不再需要枚举值形参指定创建的类型，只需要知道具体的工厂类型就可以创建自己想要的水果，因为一个工厂对应一个水果**，所以水果抽象类无需再定义水果枚举值类型。

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

抽象工厂模式是对工厂方法模式进一步抽象，工厂方法中不同的水果统一使用create方法创建，但是交给不同的工厂执行。现在如果有更复杂的逻辑，例如每种水果还分为东部和西部产地的区别，即苹果、香蕉和橘子还会各自有2个子类继承。

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

现在客户想要获取一个西部产的苹果，如果还使用工厂方法模式，要创建3×2共6个工厂，显然数目太多不好维护，而且客户使用的时候还必须知道这6个具体工厂类。所以可以不用每种水果都一个工厂，当有了新的形容词限定时可以**按照形容词来作为工厂**，每个工厂都可以生产3种水果，**即每个工厂负责一类产品的构建**。

这里的形容词就是东部和西部，所以可以使用2个类继承抽象工厂类，抽象工厂不是只定义1个create函数，而是定义3个create函数，分别用于创建不同的水果，负责水果一类的产品构建，后面有利于别的产品类型进行拓展。客户端就无需再了解6个具体水果工厂类，只需要了解2个东西部工厂即可，降低了工厂的复杂度。

```c++
class AbstractFruitsFactory {
public: 
    virtual Fruit* createApple() const = 0;// 3个水果的工厂函数
    virtual Fruit* createBanana() const = 0;
    virtual Fruit* createOrange() const = 0;
};                
class eastFactory: public AbstractFruitsFactory { // 西部风格
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
class westFactory : public AbstractFruitsFactory { // 东部风格
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

------------------------------------------------------------------------------------------------------------------------------------------------------

**不仅需要继承业务基类，且要将业务基类或业务派生类指针作为私有属性进行管理的模式。**

### 装饰模式

这个模式用于动态的给对象增加额外的职责，而不用生成子类去实现。

假定一个装饰器类要修饰业务类。那么可以先定义**装饰器基类，它也继承自业务类的基类**，并把**业务基类的指针或对象**作为**装饰基类的私有属性**，也就是用某物实现的组合关系。这个业务基类的指针可以**对外提供一个设置函数，可以传入任意的业务派生类指针**，这样装饰器类只需要**定义和业务派生类的同名函数即可**，函数内部一方面转交业务派生类的同名函数功能，另一方面还可以写自己的装饰代码。

对外部而言，不仅保留了原有业务类的功能还新增了其他功能。

### 代理模式

和装饰模式是很相似的，**代理类**和业务具体类都**继承自业务基类**。不过装饰模式是装饰类把**业务基类的指针**作为私有属性，代理类则是把**业务具体类的指针**作为私有属性。这样相当于代理类绑定到了某个具体业务，不像装饰模式可以装饰任何具体业务，失去了一些弹性。

代理模式可以用于远程代理，让对象可以在不同的地址空间使用；可以用于虚拟代理，存储真实的实体对象的路径和地址，提高性能节省内存；还可以用于安全代理，不同的代理拥有不同的权限，提供灵活性。

### 适配器模式

和代理模式一样，**适配器类继承了业务基类**，但不是把业务基类指针作为私有属性，而是把**业务具体类的指针作为私有属性**。然后适配器类就可以**定义和业务具体类的同名方法**，这个方法可以自定义新的实现达到其他目的；当然也可以什么都不做只是做一个转发并增加一些代码，这就像装饰模式，但该适配器类只能装饰这个业务具体类，而装饰模式可以装饰任何业务具体类，这是因为管理的私有属性指针是业务具体类而不是业务基类的缘故。

------------------------------------------------------------------------------------------------------------------------------------------------------

**无需继承业务基类，仅仅把业务基类指针作为私有属性进行管理的模式。**

### 建造者模式

**将一个复杂对象的构建过程与它的表示分离**，可以固定好构建行为(借助**模板方法模式**)，这个用于管理构建行为的类是**指挥构建者类**，它把**业务基类的指针作为私有属性**。但是不同于装饰和代理模式，它**不继承自业务基类，管理的是业务基类指针而非业务具体类指针**。

### 状态模式

此模式在设计上和建造者模式完全一样，使用了一个状态类去管理**业务基类的指针**，**将其作为私有属性**。

该状态类也**不继承自业务基类**，它提供了个**设置业务(状态)的函数**，可以让私有属性业务基类指针动态的表示各类派生类业务指针(改变状态)，同时还可以定义和业务基类同名的函数，**内部实现一个转发功能**。

所以状态类使用上就是先设置业务(状态)，然后调用业务函数(调用的就是该业务的函数)。**建造者模式强调固定相同的行为，指挥者用来固定这个流程**；**状态模式强调可以切换状态，但调用的接口仍然保持一致**。

### 命令模式

设计上和建造者模式一致，只是多了一层嵌套管理关系，是一种**层层包含的聚合关系**。

命令基类**没有继承业务基类**，而是**将其作为私有属性进行管理**，提供设置业务的函数，参数是业务基类指针，这样可以传递任何业务具体类。**现在多加一层嵌套**，一个管理命令的类(就像建造者模式的指挥者类)又将**命令基类作为私有属性**，提供设置命令的函数，参数是命令基类指针，这样可以传递任何具体命令。这样层层嵌套，而且使用的使用达到一种松耦合的状态，用户使用的时候只需要业务实例、命令实例和发布命令实例，然后命令示例设置好业务实例，发布命令的实例设置命令，就可以调用发布命令实例的方法了。

### 中介者模式

设计上和建造者模式一致，只是这里是相互嵌套。**中介者基类将业务基类对象作为私有属性管理**，并且管理的是2个对象，因为中介者需要2个目标；而**业务基类又将中介者基类作为私有属性管理**，并提供设置中介者的方法(可以是任何中介者具体类)，所以任意2个业务派生类都可以认识同一个中介者，而每个中介者可以管理任意2个业务对象，**相互嵌套**，这样2个业务具体类都可以借助中介者传递信息，符合迪米特原则。

------------------------------------------------------------------------------------------------------------------------------------------------------

**业务基类需要定义特定方法的模式。**

### 备忘录模式

备忘录模式独立于任何类，不管理任何业务类，相反它是被业务类使用。

**业务基类需要定义2个方法，创建和恢复备忘录**，业务具体类重载2个函数即可。

创建备忘录返回的对象可以被另一个单独的管理备忘录的类接受，也就是备忘录类作为管理备忘录的私有属性。恢复备忘录时，业务具体类获取管理备忘录类的备忘录属性即可。

### 观察者模式

如果多个对象间存在**一对多的依赖关系**，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新，这时可以使用观察者模式。

业务类分为基类和具体类，业务基类有**增加观察者、移除观察者、通知3个函数**和一个**观察者基类容器对象作为私有属性(可以存储观察者)**，这些方法和属性用的参数是**观察者基类指针**，可以处理各式的具体观察者，增加或删除的观察者在观察者容器对象进行储存和管理。且**只有通知函数是虚函数需要被重载**，业务具体类只需要重载通知函数，这个函数里**遍历观察者容器**，然后**调用它们都具备的响应函数即可**。

观察者也分为基类和具体类，**观察者基类有个响应虚函数**，具体类需要重载它。

客户端使用时可以new一个通知者，new出多个观察者，通知者使用add方法添加所有观察者，然后调用notify方法即可，内部自动遍历观察者并调用它们的response函数。

### 组合模式

没有第三方类参与。

业务基类定义增加和移除2个函数，**函数的参数列表是业务基类自身**，这样增加和移除时**可以是任何业务具体类**。业务派生类继承业务基类并重载2个函数即可，可以分为2种派生类。

第1种业务派生类单纯的重载即可，它**只能添加非组合类型对象**；第2种业务派生类额外定义了业务基类容器对象，可以储存各种业务具体类对象，所以**可以添加组合类型对象**。

### 职责链模式

职责处理者基类需要定义设置职责处理的继任者、处理请求2个函数，**函数的参数列表是职责处理者基类自身**，这样设置职责的继任者时可以是任何继任者。

这样每个职责处理者可以判断是否可以处理请求，处理完之后可以交给继任者继续处理。

### 迭代器模式

涉及4个角色：迭代器的基类和具体类，容器类的基类和具体类，更像是Java风格的迭代器，而非STL的嵌套。

迭代器基类需要提供begin、end和next函数，迭代器具体类**把容器具体类作为私有属性管理(1个迭代器管理1个容器单一权责,所以不要把容器基类作为私有属性)**，此时重定义begin、end和next函数就可以直接使用容器类提供的一些函数了，例如容器元素个数size，容器的索引访问符号[]可用等等。

容器基类需要提供一些标准函数，例如empty、size等，取决于容器类型；容器具体类则是具体的设计，可以提供用于迭代器能够遍历容器的接口函数，例如公有的next方法被迭代器类进行一个转发操作。

### 访问者模式

涉及5个角色，抽象访问者和具体访问者，抽象元素和具体元素，对象结构元素。

抽象访问者类，每个具体元素都提供1个接口函数visit，**参数列表是对应的具体元素**。

具体访问者类**继承这些visit函数**，每个具体访问者都可以访问所有定义过的具体元素。

抽象元素类，定义接受何种访问者的accept函数，为了可以是任意具体访问者，**accept参数列表是抽象访问者**。

具体元素类，除了继**承accept函数**，还可以定义自己的一些特定功能函数。

对象结构元素类，定义一个**抽象元素容器对象作为私有属性，用于存储各类型的元素**，并提供添加、移除元素的方法。这个类也要定义accept函数，确定是何种访问者，这个访问者可以被容器的所有元素的accept函数调用。

这样在外界来看，只要设置好访问者，就可以遍历对象结构元素类的所有具体类元素，并且显示的是针对该访问者的内容，不同的访问者显示的内容不相同。

------

**面试最常考的模式。**

### 单例模式

核心在于**禁止默认构造、拷贝构造函数**，声明它们为私有，并定义一个static静态对象实例，可以被创建实例的函数返回，可以保证**类只有1个实例**。

根据静态对象被初始化的时机可以有以下模式。

饿汉模式：

**静态成员变量的写法**。

```c++
class SingleHungry{
    protected:
        static SingleHungry instance; // 静态成员变量声明
    public:
    	... // 声明为delete或private的操作省略
        static SingleHungry* getInstance();
};
SingleHungry SingleHungry::instance; // 静态成员变量定义
SingleHungry* SingleHungry::getInstance(){ 
    return &instance;
}
```

Meyer**返回局部静态对象**的写法。

```c++
class SignleHungryMeyer{
    public:
		... // 声明为delete或private的操作省略
        static SignleHungryMeyer& getInstance();
};
SignleHungryMeyer& SignleHungryMeyer::getInstance(){
    static SignleHungryMeyer instance; // 局部静态对象
    return instance;
}
```

懒汉模式：**实例用到时才创建，会有线程安全问题**。

```c++
// 有线程安全问题写法
class SingleSlacker{
    protected:
        static SingleSlacker* instance; // 静态成员变量指针声明
    public:
    	... // 声明为delete或private的操作省略
        static SingleSlacker* getInstance();
        static void deleteInstance();
};
SingleSlacker * SingleSlacker::instance = nullptr; // 静态成员变量指针声明定义
void SingleSlacker::deleteInstance(){ 
    if (instance != nullptr){
        delete instance;
        instance = nullptr;
    }
}
SingleSlacker* SingleSlacker::getInstance(){
    if (instance == nullptr){
        instance = new SingleSlacker(); 
    }
    return instance;
}
// 无线程安全问题写法
class SingleSlackerGC{
    protected:
        static SingleSlackerGC* instance; // 静态成员变量指针声明
    private: // 定义嵌套类用于释放资源
        class Garbage{
            public:
                ~Garbage(){
                    if (SingleSlackerGC::instance != nullptr){
                        delete SingleSlackerGC::instance;
                        SingleSlackerGC::instance = nullptr;
                    }
                }
        };
    public:
		... // 声明为delete或private的操作省略
        static SingleSlackerGC* getInstance();
};
std::mutex resource_mtx; // 进一步改进方法
SingleSlackerGC * SingleSlackerGC::instance = nullptr; // 静态成员变量指针声明定义
SingleSlackerGC* SingleSlackerGC::getInstance(){
    if(instance == nullptr){ 
        std::unique_lock<std::mutex> lck(resource_mtx); // 自动上锁,线程竞争时避免出错
        if (instance == nullptr){
            instance = new SingleSlackerGC();
            static Garbage gar; // 程序结束时会调用gar的析构函数从而释放new的实例
        }
    }
    return instance;
}
```

------------------------------------------------------------------------------------------------------------------------------------------------------

### 设计模式总结

(1) 策略模式、外观模式、模板方法模式、桥接模式、享元模式、解释器模式**更像设计原则**的说明；

(2) 简单工厂、工厂方法、抽象工厂模式=>1个工厂类**负责所有产品的构建**、每个工厂**负责一种产品的构建**、每个工厂**负责一类产品的构建**；

(3) 装饰模式、代理模式、适配器模式都**继承了业务基类**，内部管理了**业务基类指针**(装饰模式)或**业务具体类指针(**代理和适配器模式)作为私有属性；

(4) 建造者模式、状态模式、命令模式、中介者模式**不继承业务基类**，仅将**业务基类的指针作为私有属性管理**；

(5) 备忘录模式、观察者模式、组合模式、职责链模式、迭代器模式、访问者模式需要**业务基类定义特殊方法**。

备忘录模式不管理业务基类/派生类对象，相反它被业务类和管理备忘录的类使用，业务基类需要定义**创建和返回备忘录2个函数**；

观察者模式的业务基类需要构建**增加、移除和通知观察者3个函数**和**一个观察者基类的容器对象**作为私有属性，**观察者基类定义响应函数**；

组合模式的业务基类需要定义**增加和移除函数**，没有第三方类参与；

迭代器模式的迭代器基类需要定义begin、end和next函数，并将**容器具体类对象作为私有属性**管理；

访问者模式，抽象访问者需要定义visit函数，抽象元素类需要定义accept函数，对象数据类需要定义accept函数和**元素基类的容器对象作为私有属性**。

(6) 单例模式需要禁止默认和拷贝构造函数，返回**类的唯一静态实例**。常见的写法有饿汉模式和懒汉模式，饿汉模式可以返回静态成员变量也可以返回局部静态对象，**懒汉式会有线程安全问题**，可以考虑使用互斥锁+嵌套一个类专门用于释放资源的技术保证线程安全。

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

### auto_ptr

auto_ptr已被弃用，它的性质是**调用拷贝和赋值函数时获得资源的专有权**，被复制的指针则成为空指针，也就是说它会剥夺另一个指针的所有权。

### shared_ptr

shared_ptr，可以让**多个指针共享同一份资源，相应的增加引用计数**，当引用计数为0时会自动销毁资源。它的实现过程就是在默认构造中初始化计数为1；拷贝构造时+1；赋值运算时，等号左边的对象-1，右边的对象+1；析构函数中-1；如果赋值和析构函数中引用次数检测为0，就调用delete函数释放。

缺点在于2个指针互指会导致**环状引用，引用计数变成了2**，当指针离开作用域时它们都不能被析构导致内存泄漏。

构造shared_ptr最好**使用make_shared()<>而不是默认构造函数创建**，这样可以保证new和delete是对称使用的。

该指针**只有箭头、解引用和逻辑运算符**，没有加减，加加，减减和索引运算符。

常见的成员函数**use_count()**获取引用次数，**reset()**取消与原指针的关联，**get()**获取绑定的底层指针等。

### unique_ptr

unique_ptr，独占式智能指针，同一时间只能有一个智能指针可以指向该对象。

**无法进行拷贝构造和拷贝赋值**，但可以进行移动构造和移动赋值，即可以使用**move**函数对所有权进行转移。

构造独占指针时可以使用make_unique，这个函数可以自己定义，函数参数列表就是为模板参数Args...的右值引用，构造时借用forward函数构造。

```c++
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args ) {
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}
```

### weak_ptr

weak_ptr，解决shared_ptr相互引用时，两个指针的引用计数永远不会下降为0的死锁问题。

该类型指针通常**不单独使用**（没有实际用处），只能和 shared_ptr 类型指针搭配使用，可以获取 shared_ptr 指针的一些状态信息，例如引用计数，指向的内存是否已被释放等。

该指针**不会影响所指内存空间的引用计数**，也就是weak_ptr 类型指针的指向和某一 shared_ptr 指针相同时，weak_ptr 指针并不会使所指堆内存的引用计数加 1。

没有**重载解引用符号和箭头符号**，所以只能访问堆内存而无法修改它。

主要有2个成员函数，expired说明资源是否被释放，如果是返回true；lock函数则是返回指向原始对象的shared_ptr指针。

## 类的性质

### 继承、多态

**类是空类不意味着类的大小是0**，因为为了区分空类的不同实例会分配1个字节使每个实例有不同的地址；

**多态可以不依赖于继承**，可以通过定义一个枚举类型，作为一个外部接口函数的参数，内部依据参数定义具有不同性质的实例。外部使用这个外部接口口函数传入不同的枚举值就会得到不同的实例，这是一种编程技巧得到的多态；

多态利用继承实现的关键前提是**找出所有子类共通的行为，让这些行为函数声明为虚函数并确定每个操作行为的访问权限**；

静态多态是函数重载，动态多态是虚函数机制实现，运行期间基类指针可以指向派生类对象；

### public、private和protected

public：可以被该类中的函数、子类的函数、友元函数访问，也可以由该类的对象访问。

protected：可以被该类中的函数、子类的函数、友元函数访问，但**不可以由该类的对象访问**。

private：可以被该类中的函数、友元函数访问，但**不可以由子类的函数、该类的对象访问**。

公有继承：派生类的成员函数可以访问基类的公有成员和保护成员，派生类的对象只可以访问基类的公有成员。

保护继承：派生类的成员函数可以访问基类的公有成员和保护成员；而派生类的对象不可以访问基类的任何成员。

私有继承：派生类的成员函数可以访问基类的公有成员和保护成员；而派生类的对象不可以访问基类的任何成员。

总结：

**基类的私有成员仍然是私有的，只能被本类成员函数和友元访问**，**不能被派生类访问**。

**基类的保护成员可以被派生类访问**，但**不能被派生类的对象访问**。

### 纯虚函数、非纯虚函数和非虚函数

有虚函数的类，类的最开始部分是一个虚函数表的指针，指针指向一个虚函数表，表中放了虚函数的地址。子类继承父类时也会继承虚函数表，当子类重写父类中虚函数时，会将其继承到的虚函数表中的地址替换为重定义后的函数地址；

纯虚函数的含义是指明**类的接口必须被继承，派生类必须给出接口的定义**。拥有纯虚函数的类不能够被实例化，只能被继承。**基类不能给出纯虚函数的缺省实现，但是可以提供一份定义**，如果子类的接口定义仍然想**继承基类的实现使用using声明**声明父基类作用域或者直接使用作用域符号来转交给基类提供的定义进行实现；

非纯虚函数的含义是**类的接口和定义都被继承，且派生类的定义能(不强制)覆盖基类的定义**。不强制是因为基类可以**提供缺省的实现**，此函数可以直接被派生类继承不做任何改动；

非虚函数的含义是**类的接口和定义都被继承**，但不**希望派生类去重定义它**，只会使用基类提供的唯一一份定义；

**静态成员函数不能声明为虚函数**；

**构造函数不能声明为虚函数**；因为虚函数的调用依赖虚函数表，而虚函数表的指针vptr需要在构造函数中被初始化，如果构造函数也是虚的就无法使用其它虚函数；

基类的虚函数如果有缺省参数值，派生类不要重定义这个缺省参数，因为缺省参数是静态绑定，基类指向派生类对象的指针使用的时候依然使用基类的缺省参数。

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

### 虚析构函数

**析构函数不要定义为纯虚函数，多态性质的话也不能声明为非虚函数**；

析构函数**不要抛出异常**，如果有应当直接捕捉然后终止程序；

析构函数和构造函数中**不要调用虚函数**；

多态基类的析构函数**一定要声明为vritual函数**，又因为析构函数不要定义为纯虚函数，所以要声明一个非纯虚函数；基类的对象应由基类的析构函数销毁，但是因为基类的指针可以指向子类，所以**指向子类的基类指针真正销毁时应调用子类的析构函数**，但是只有**析构函数是虚的才能保证销毁时动态的调用子类的析构函数**，否则调用的是基类的析构函数导致子类成分未被销毁。

类只要**有任何虚函数就应该有一个虚析构函数**，且如果类不作为基类使用就不要声明虚析构函数。

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

## 常见关键字

### define关键字

宏定义在**预处理阶段展开**，不能进行调试，**不分配内存**，**没有类型和安全检查**，只是进行一个字符串替换，可以存在于多份代码段中，可能会因为**没加小括号导致括号边际效应，即因为括号优先级问题展开时运算符匹配变量错误**错误。如果可以的话，定义常量时尽量使用const代替define，定义别名时尽量使用typedef。

宏定义**不受定义域限制**。

宏定义语句**不需要分号**结束。

宏定义可以用于条件编译，满足条件时才会编译某段代码，例如Windows 有专有的宏_ WIN32，Linux 有专有的宏 _ linux _。条件编译语句主要是**#if、#elif、#else和#endif**。

```c++
int main(){
    #if _WIN32
        printf("win32\n");
    #elif __linux__
        printf("linux\n);
    #else
        printf("macos or other\n");
    #endif
               
    #if NUM == 10 || NUM == 20
        printf("NUM: %d\n", NUM);
    #else
        printf("NUM Error\n");
    #endif
    return 0;
}
```

**#ifdef**(#ifdef 可以认为是 #if defined的缩写)、**#ifndef**(和#ifdef意思相反)的一个用法如下，VS有两种编译模式，Debug 和 Release，当以 Debug 模式编译程序时，**宏 _DEBUG 会被定义**，执行相应的代码，否则执行下一行代码。

```c++
#define NUM1 10
#define NUM2 20
int main(){
    #ifdef _DEBUG
        printf("Debug mode\n");
    #else
        printf("Release mode\n");
    #endif
    
    #if (defined NUM1 && defined NUM2)
        printf("NUM1: %d, NUM2: %d\n", NUM1, NUM2);
    #else
        printf("Error\n");
    return 0;
}
```

#if语句可以跟上整型常量表达式，但是#ifdef和#ifndef只能跟上宏名字。

### typedef关键字

typedef 用来定义一种数据类型的别名，增强程序的可读性。

typedef可以进行**类型安全检查**，受到**定义域**的限制，是一种语句，定义别名时要**加分号**。

### const关键字

const常量只会维持一份拷贝，编译阶段可以进行类型**安全检查**，受到**定义域**的限制，定义常量时尽可能使用const替换define。

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

分为5个方面来说。

(1) 修饰局部变量，会在静态存储区分配内存，会在函数首次调用时初始化，之后不能再初始化，生命周期和程序相同，但是作用域限于局部，只可在函数内被访问。

(2) 修饰全局变量，也是静态存储区，作用域是文件内，文件外不可见。

(3) 修饰普通函数：函数作用域文件内，文件外不可见。

(4) 修饰成员变量：所有**类的实例只能共享一份拷贝**，**无需实例化可以使用**，一般在类外初始化，初始化的时候不需要强调static，声明好类的作用域即可。

(5) 修饰成员函数：不接受this指针，无需实例化即可使用，故内部也只能访问类的静态成员，否则和需要实例化违背。

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

**不要将析构函数或者构造函数声明为inline**，即使代码没有任何实现；

使用inline时要和函数的定义连在一起而不是声明，否则不起作用。

### extern关键字

extern变量的**声明和定义可以不在同一文件，但是记住定义只有一次**；例如，如果a文件声明变量k，b文件进行定义需要这样写。如果当前工作文件是b.cpp，从b.cpp的角度是**变量在外部声明在本文件定义**，该**全局变量作用域从变量的定义开始到文件末尾**，若在定义之前出现引用就会报错；

```c++
// a.cpp
extern int k; // 声明,告知定义在外部
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
    extern int k; // 声明引用的是外部定义
    printf("k=%d\n",k);
}
// g++ -c a.cpp; g++ -c b.cpp; g++ a.o b.o -o out; /.out.exe
```

外部变量还可以在头文件中定义，因为头文件可以被多次包含，可能出现重定义的情况。非必要，**不要在头文件中定义全局常量或者外部变量**。

## 标准库内容

### std::bind和std::placeholders

std::bind和std::placeholders可以用于函数参数绑定与参数占位。

```c++
void print_age_sex_name(int age, bool boy, const char* name) {
    printf("age = %d boy? %d name = %s\n",age,boy,name);
}
auto bindFoo = std::bind(print_age_sex_name, std::placeholders::_1, true,"chenbei"); // 把后2个参数绑定,第1个参数占位
bindFoo(25); // 当成具有1个参数的函数使用
```

### std::move

std::move 这个方法将左值参数无条件的转换为右值，可以方便的获得一个右值临时对象。

### std::forward

普通函数传递参数，实际参数无论是左值还是右值，都会当作左值转发；

使用move函数再传递给函数，总是接受1个左值并当作右值进行转发；

std::forward函数就是用于解决这个问题的，为了完美转发，左引用能够保持左引用，右引用继续保持右引用，所以传递的时候可以使用std::forward<T>(v)传递给函数，而不是直接把v传递给函数。

如果一个**函数的参数是左引用**T&，传递的参数无论是左引用还是右引用都会推导为T&左引用，也就是**保持不变**；

若函数的参数是右引用，实参是左引用，依然推导为左引用；

**只有函数的参数和实际传入的参数都是右引用类型，才能推导为右引用**。

### array和vector

array是固定size的数组，相比于普通数组更现代化，封装了一些可用的函数，如empty、size、front、back等，支持迭代器访问，实例化时指定2个模板参数，例如array<int, 5> a = {1, 2, 3, 4, 5}。

vector底层是一个**动态数组**，包含三个迭代器，start、finish和end_of_storage。其中start和finish之间是已被使用的空间范围，end_of_storage是整块连续空间包括备用空间的尾部。当空间不够装下数据时，会自动申请另一片更大的空间(1.5倍或者2倍)。但是当进行删除的时候，这些**内存不会归还**，需要使用shrink_to_fit函数释放。

常见的API函数有size、capacity、empty、front、back，操作元素的API有push_back、pop_back、emplace_back、**emplace**、insert，清除元素的有erase、clear，操作内存的有resize重设大小、**reserve**预留空间、**shrink_to_fit**释放不必要的空间。

### unordered_map和map

unordered_map的底层是一个防冗余的哈希表，构造函数上需要hash函数map一般采用红黑树实现。

unordered_map查找速度比 map 快，查找速度基本和数据数据量大小无关，属于常数级别，而map是对数级别即log(n)。

### 迭代器类型

**输入、输出和前向迭代器**，istream_iterators和ostream_iterators是其代表，每次只能单向向前移动，且**只能读或者写一次**；前向迭代器区别是可以多次读写；

双向迭代器，**2个方向都可以走**，例如双向链表的迭代器；

随即存储迭代器，可以**常量时间前后跳跃任意距离**，在map和set使用；

关联比较密切的函数是**advance**函数，**可以将某个迭代器移动某个距离**。

## 线程知识

### thread

一个可执行程序运行起来了就叫一个进程，每个进程中只能有唯一的主线程，有进程必然有线程。**多进程是多个可执行程序**，即电脑后台，它们之间可以依据**管道、文件、消息队列和共享内存**等进行通信，如果是不同的电脑可以利用网络socket技术进行通信。多线程是一个进程除了主线程以外可以有多个子线程，所有的线程**共享相同的地址空间**，全局变量、指针和引用可以线程中进行传递，内存开销比多进程小。

std::thread 用于创建一个执行的线程实例，使用时需要包含 <thread> 头文件。使用 join() 加入阻塞主线程加入一个子线程；detach()不会阻塞主线程，而是分离主线程和子线程，如果**主线程先执行完，子线程会停在后台继续执行**，结束后会有库专门去清理子线程相关的资源。

t**his_thread::get_id()获取线程id**。

thread的构造函数可以接受一个函数指针、类对象和成员函数指针、智能指针、lambda 函数，但是**不接受一个函数对象**。

```c++
void myprint1(const int &id, char * buf);
thread t1(myprint, id, buf); // 函数指针
t1.join();

class TA{
    public:
    	void printValue(int num);
}; 
TA ta;
void myprint2(const TA& ta); // 类对象
thread t21(myprint3,std::ref(ta)); // 要配合ref
t21.join();

thread t22(&TA::printValue,ta,15); //成员函数指针,绑定ta,和成员函数的num
t22.join();

auto *p = new int(100);
unique_ptr<int> up(p);
void myprint3(const unique_ptr<int> &up);
thread t3(myprint3,std::move(up)); // 配合move
t3.join();
```

### std::ref

可以在线程中传递引用而不是传递值。

### std::mutex

std::mutex是个类，可以使用lock成员函数加锁，unlock成员函数解锁。

在关键代码处先lock然后unlock，这样就可以保证数据的安全，必须成对使用。

```c++
mutex mtx;
mtx.lock();
// ... 关键代码
mtx.unlock();
```

### std::lock_guard

std::lock_guard是个类模板，可以自动锁定和解除锁定，不需要自己去解锁。

**std::lock_guard 不能显式的调用 lock 和 unlock**，在关键代码前边使用。

如果已经上过锁，可以使用std::adopt_lock进行一个标记。

```c++
std::lock(mtx); // 已上过锁
std::lock_guard<std::mutex> lck_guard(mtx,std::adopt_lock);//告知无需再上锁
// ...关键代码
```

### std::unique_lock

std::unique_lock 的对象会以独占所有权的方式管理 mutex 对象上的上锁和解锁的操作。**std::lock_guard 不能显式的调用 lock 和 unlock**， 而 std::unique_lock 可以在声明后的任意位置调用。

unique_lock第2参数可以传递3个值，std::adopt_lock、std::try_to_lock和std::defer_lock。表示的含义是，无需再加锁、尝试上锁(要求事先未上锁,没锁定成功时不会阻塞会立即返回)、std::defer_lock初始化一个不加锁的unique_lock对象。

unique_lock有4个成员函数，lock()、unlock()、try_lock()、release()

### std::condition_variable

条件变量 std::condition_variable 用于唤醒等待线程避免死锁。notify_one() 用于唤醒一个线程，notify_all() 则是通知所有线程。

### std::async

std::async用于启动一个异步任务，希望线程返回一个结果，是个函数模板，它会返回一个std::future<T>对象，可以获取异步任务的结果。

std::async的默认枚举值是std::launch::async。

```C++
int mythread(){return 5;} // 普通函数指针
std::future<int> result = std::async(std::launch::async,mythread);
int val = result.get();  // 线程在这里卡住直到拿到结果

class A{
    public:
        int my_thread(int a){return a;}; // 成员函数指针
};
std::future<int> result = std::async(std::launch::async,&A::my_thread,std::ref(a),25);
int val = result.get(); // 也是卡住直到拿到结果为止
```

### std::future

是std::async异步任务的返回值，可以拿到异步任务的结果。在std::packaged_task中还可以使用 get_future() 来获得一个 std::future 对象。

std::future可以调用get成员函数获取结果，但是get函数只能使用1次。

```c++
void func(std::future<int> &fut){
    auto res = fut.get(); // get只能使用1次
}
```

std::future有3种状态，定义在枚举值std::future_status中。

```c++
enum class future_status
{
    ready, // 表示future对象已经被设置，并且可以使用get()获取其值
    timeout, // 表示future对象在指定的时间内没有被设置，超时
    deferred // 对应std::async第1个参数为launch::deferred的情况
};
```

### std::launch

std::launch类型可以作为async的参数，launch是枚举类型。

```c++
enum class launch
{
    async = 1, // 会创建一个新线程,并且立即执行线程入口函数,线程函数的返回值会立即被拿到
    deferred = 2 // 延迟调用,线程入口函数不会立即执行,只有在get()或者wait()调用后才会执行
};
```

### std::packaged_task

打包任务，是个类模板，**模板参数是各种可调用对象**，可以是函数，可以是函数对象，可以是lambda表达式，也就是把各种可调用对象包装起来方便作为线程入口函数被调用。

它**自身也是可调用对象**，可以通过get_future()获取std::future，然后再用get()成员函数获取结果。

```c++
int myprint(int async);
std::packaged_task<int(int)> task(myprint);//将函数mythread绑定到task
int async = 255;
thread t(std::ref(task),async);//创建线程,以打包的方式调用myprint
t.join();//等待线程结束
std::future<int> result = task.get_future();//获取打包任务的返回值
int val = result.get();//获取任务的返回值
```

### std::promise

能在某个线程中赋值,然后在其它线程拿到这个结果。

```c++
void mypromise(std::promise<int> &p , int async)
{
    async += 10; // 做些运算
    async * 2;
    int result = async;
    p.set_value(result); // 把计算结果放入promise中
};
int async = 25;
std::promise<int> p;
std::thread t(mypromise,std::ref(p),async);
t.join();
std::future<int> result = p.get_future();// 获取结果值可以在这里(主线程)
int res = result.get(); // 70
```

### 原子操作

互斥量针对一个代码段，而原子操作只对变量有效，特别是基础数据类型。

原子操作是一种不可分割的操作，要么完成要么没完成，不存在半完成的情况，例如deferre的情况。

```c++
std::atomic<int> g_atomic(0); // 原子类型
std::atomic<bool> g_bool(false); // 原子类型
```

原子操作支持++,--,+=,-=,|=，不支持i=i+1,i=i-1,i=i&1,i=i^1,i=i<<1,i=i>>1等。

## 杂项知识点

### 结构体字节对齐

结构体内成员按照声明顺序存储，**第一个成员地址和整个结构体地址相同**。

**结构体的大小一定要为有效对齐值的整数倍，当没有明确指明时，以结构体中最长的成员的长度来对齐**，若有double成员，按8字节对齐。

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

### 编译过程

编译分为3个过程：**编译，汇编和链接过程**。

编译过程分为编译预处理和正式编译，编译预处理就是**处理宏定义的展开**，正是编译是将cpp文件编译为.s的**汇编代码**。

汇编过程生成机器指令.o文件。

链接过程，是几个文件之间可能存在关联，需要进行动态或者静态链接。

静态链接就是把代码从**静态库拷贝出来放到最终的可执行程序**中，这些代码会被放到该进程的虚拟地址空间，如果代码有改动需要重新编译。动态链接是在程序执行的时候，才会把代码映射到执行的虚拟地址，**内存中只有一份拷贝**。

### 内存分区

栈区：存放函数的局部变量、函数参数列表、调用时的返回地址等。

堆区：动态申请的内存空间。

静态存储区：存放全局变量和静态变量，C语言中还会细分为.bss和.data段，.data段存放的是已初始化过的变量，C++不再区分。

常量存储区：存放的是常量，例如常量字符串和数字等，不允许修改。

代码区：存放代码，编译后的二进制文件存放在这里，可以执行。

**栈区到代码区的地址从高到低**。

栈区由于先进后出的性质，**不会存在内存碎片问题**，堆区会产生。

堆的地址分配时从**内存的低地址到高地址增长**，栈区正好相反。

要求只能在**堆上分配内存**，就是不能静态建立类对象，即不能直接调用类的构造函数，可以**将析构函数声明为private**，就不能在栈空间上为类对象分配内存；只能在栈上生成对象，**可将new声明为private**，这样就不能在堆上申请内存。

### C和C++的区别

C++是面向对象的，C是面向过程的。

C++有函数重载以及引用的概念。

C++引入了new和delete替换了C的malloc/free函数。new和delete类型是安全的，可以进行**类型检查**，会自动调用构造和析构函数。同时它们是可以重载的，自定义内存分配和释放策略。malloc可能**会返回空指针**但不提示错误，所以需要事先判断，而new失败的话会抛出bad_alloc或其它异常，**可以进行异常捕获**，默认使用abort或者exit函数终止程序。

















