## 导读

​		EffectiveC++的55个建议主要分成两类，第一类是一般性的设计策略，第二类是带有具体细节的特定语言特性。

### 声明式、签名式和定义式

​		常见的术语有声明式、签名式和定义式。

​		① 声明式(declaration)：告诉编译器某个东西的名称和类型，但略去细节。

​		例如，外部变量声明。

```c++
extern int x;
```

​		函数声明。

```c++
void func(int x);
```

​		类声明。

```c++
class Widget;
```

​		模板类声明。

```c++
template<typename T>
class GraphNode;
```

​		② 签名式(signature)，是针对函数声明来说的，函数的声明应当告诉函数的参数类型和返回类型。官方对签名式的定义不包含返回类型，但本书将其合并，便于理解。

```c++
void (int)
```

​		③ 定义式(definition)，提供编译器一些声明式所遗漏的细节。

​		对变量而言，定义式是编译器为次对象分配内存的地点。

```c++
int x;
```

​		对函数而言，定义时提供了函数代码本体。

```c++
void func(int x){
	printf("x is %d",x);
}
```

​		对结构体或者类、类模板等，定义时给出其成员变量和成员函数。

```c++
struct person{
	int age;
    string name;
};

class person{
  public:
    person(int age);
    person(string name);
    ~person();
  protected:
    int _age ;
    string _name;
};
```

### explicit关键字的作用

​		总的来说，该关键字是对**<u>类的默认构造函数、或者类的有参构造函数的(只有1个参数，或者多个参数但有默认值)</u>**隐式类型转换进行阻止，但是不影响显式类型转换。跟它相对应的另一个关键字是implicit，类构造函数默认情况下即声明为implicit(隐式)。	

​		以上述的person类为例，实例化对象可以有以下方式。

```c++
person p1(10); // √
person p2 = 10; // √
p1 = 20 ; // √
p2 = 20; // √

person p3("A"); // √
person p4 = "A" ; // √
p3 = "B"; // √
p4 = "B"; // √

p1 = "C"; // √ 交叉也是可以的
p3 = 30; // √
person p5; // × 没有默认构造函数
```

​		为什么可以使用赋值运算符构造对象呢？因为C++会默认进行隐式转换，p2=10的过程等价于先构造temp(10)，再让p2=10。但是上述一个person对象不仅可以等于const char * ，也可以等于int型，它们之间还能换算，显得不伦不类。为了避免这种情况，可以声明为explicit类型，阻止默认隐式转换。这样，只有两条语句是合法的，其它均不合法。

```c++
person p1(10);
person p3("A");
```

​		现在再来看，为什么要求是默认构造函数或者有参构造函数只带1个参数。因为类构造函数参数大于或等于两个时，是不会产生隐式转换的， 所以explicit关键字也就无效。

```c++
class person{
  public:
    explicit person(int age){_age=age;}; // 阻止隐式转换
    explicit person(string name){_name=name;}; // 阻止隐式转换
    explicit person(int age, string name){_age=age;_name=name;}; // 加不加都一样
    ~person();
  protected:
    int _age ;
    string _name;
};
```

​		构造函数大于等于2个参数的，explicit加不加都一样。

```c++
person p6(1,"A");
```

​		但大于等于两个参数，如果除了第一个参数以外的其他参数都有默认值的时候，explicit关键字依然有效。

```c++
class person{
  public:
    explicit person(int age){_age=age;}; // 阻止隐式转换
    explicit person(string name){_name=name;}; // 阻止隐式转换
    explicit person(int age, string name){_age=age;_name=name;}; // 加不加都一样
    explicit person(double salary,int count=0){_salary=salary;_count=count;};//阻止隐式转换
    ~person();
  protected:
    int _age ;
    string _name;
    double _salary;
    int _count;
};
```

​		如果不加explicit，下方实例化方式还是正确的，如果有explicit的限制就不会。

```c++
person p7 = 3.4;
```

​		具体可以参考[C++ explicit关键字详解](https://blog.csdn.net/guoyunfei123/article/details/89003369)的说明。

### 命名习惯

​		使用有意义的字母去描述某个变量。

### 线程

​		对线程不熟悉的话可以忽略。

### TR1和Boost

​		TR1是一份规范，全称是Technical Report 1，描述加入C++标准程序库的诸多新机能，它们以函数模板或者类模板的形式体现，针对的题目有哈希表、引用计数智能指针、正则表达式等，这些组件被置于命名空间tr1内，tr1嵌套于std。

​		Boost是一个组织，或者网站[Boost C++ Libraries](https://www.boost.org/)，提供了源码开放的c++程序库，以前的TR1大多以Boost的工作为基础。

## 让自己习惯C++

### 条款01：视C++为一个语言联邦

​		C++支持过程形式(procedural)、面向对象形式(object_oriented)、函数形式(functional)、泛型形式(generic)和元编程形式(meta_programming)，理解这样的语言可以将其看作相关语言组成的联邦语言，而非单一语言。

​		C++的组成部分主要有4部分：

​		C part of C++：古典C，区块(blocks)、语句(statements)、预处理器(preprocessor)、内置数据类型(built-in datat types)、数组(arrays)、指针(pointers)等统统来自于C。C的局限性在于没有模板(template)、没有异常(exceptions)，也没有重载(overloading)；

​		Object_Oriented C++：这部分是真实的C++需求，构造函数class、封装(encapsulation)、继承(inheritance)、多台(polymorphic)、虚函数动态绑定(virtual)等；

​		Template C++：C++的泛型编程风格，威力强大，可以带来崭新的编程范式，也就是元编程(meta_programming)；

​		STL：包括容器(vector、list等)、迭代器(iterator)、算法(algorithm)和函数对象(指针)(functional objects)。

​		记住：内置数据类型，值传递更好；类数据类型，由于构造函数的存在，引用传递更好。

### 条款02：尽量以const,enum,inline替换#define



