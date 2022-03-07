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

#### 宏常量可能不被编译器看到

​		宏定义是预处理器处理的，可能不会被编译器看见，这样假如某个头文件定义一个宏常量，但是这个常量可能事先被预处理器转移，这样编译的时候会提示使用的名称未计入记号表。宏常量没有地址。

```c++
#define PI  3.1415926
```

​		而且提示的错误信息是3.1415926，而不是名称PI，这样会花费很多时间去追踪这个宏在哪里。可以使用常量表达式代替它，这样的定义一定会被编译器看到。

```c++
const int PI = 3.1415926;
```

​		宏定义会把所有PI记号都替换为数字，这样会导致目标文件出现多份数字3.1415926，但是常量不会，因为定义只会出现一次，内存也只有1个，对常量取地址是可以的。

	#### const string优于const char

​		尽量使用string对象而不是char对象。

```c++
const char * author("chenbei");
const string author("chenbei"); // 更好
```

#### 宏不能创建类的专属常量

​		宏定义没有作用域，一旦被定义，在它后边的编译过程都是有效的，除非遇见#undef。这样宏定义不能定义class的专属常量，也不提供封装性，没有私有宏定义的概念。

​		使用const常量是可以的，假如想要所有类的实例都共享一个常量，一个内存，那么需要声明变量为static const类型。不过类的声明中，这是1个声明式，为何要被初始化呢？因为常量必须要被初始化。

```c++
class person{
    static const int age = 18; // 声明式,常量必须被初始化（旧式编译器不允许static变量声明式初始化）
};
```

​		以前的编译器可能要这么写。

```c++
class person{ // 头文件中
	static const int age; // 不允许初始化
}
const int person :: age = 18; // 实现文件内
```

​		现在编译器，这个常量只需要声明即可使用了，不过有的编译器一定要看到定义式，那就在代码文件中给出。

```c++
person :: age; // 无需基于数值,因为静态变量只初始化1次
```

#### enum更像define

​		假如，现在是一个旧式编译器，person需要一个常量声明数组的大小，但是又没有被初始化，解决方案是enum。

```c++
class person{
	static const int age; //旧式编译器不能初始化
	int ages[age];// 这样就会出错
}
```

​		使用enum声明1个记号age，让它成为数字18的一个名称，就可使用age。

```c++
class person{
	enum {age = 18};
	int ages[age];
}
```

​		理论基础是"基于一个属于枚举类型的数值可以被当作整型使用"。

​		enum是不能取地址的，这点和define一致。同时enum也会禁止对这个常量创建指针或者引用，和define也是一致的，因为enum和define都不会创建内存。

#### 宏函数加了小括号也不能避免运行的错误

宏定义有括号边界效应，因为宏定义的时候，各个分量未加括号，传递的参数是变量表达式，系统展开后可能由于括号优先级的问题结果不一定是正确的。

例如，在头文件定义了宏函数。

```c++
#define MUL(A,B) A*B
```

使用宏时，代码文件传入了这样的参数。

```c++
int a=1,b=2,c=3,d=0;
d=MUL(a+b,c)
```

实际上编译过程展开为

```c++
d=a+b*c
```

这时传入的是表达式，并没有把括号一起传进去

解决方法是给每个分量都加上括号，就可以避免此类问题

```c++
#define MUL(A,B) ((A)*(B))
```

再如，宏定义一个结构体指针类型，结尾没有分号。

```c++
#define dps struct s *
```

使用的时候，如下

```c++
dps p1,p2;
```

编译阶段实际展开为

```c++
struct s * p1,p2;
```

因为宏定义只是单纯的替换dps，这样p2就是普通的结构体类型，而不是指针类型了。

这种解决方法是不使用宏定义，而是使用别名typedef，注意是有分号的。

```c++
typedef  struct * dps ;
```

宏定义加了括号也不一定保证结果正确；

例如，宏定义比较函数。

```c++
#define MIN(A,B) ((A)<(B)?(A):(B))
```

调用宏。

```c++
int a=1,b=3,min=0;
min=MIN(a++,b);
```

经过编译替换展开后，就成了

```c++
min=((a++)< (b)?(a++):(b));
```

先计算a++的表达式为1，计算逻辑表达式1<3是成立的，此时a已经为2，然后返回的是a++，等号右侧结束运算，a变成了3，并不是想要的结果1。

解决方案是使用template inline函数替代宏函数。因为这里的MAX是真正的函数，它遵守作用域和访问规则，还可以进行类型检查，还可以写出限制在class内的私有inline函数，而宏定义是无法做到的。

```c++
template<typename T>
inline T MAX(const T&x, const T&y){
    return x+y;
}
```

### 条款03：尽可能使用const

#### 常量指针与指针常量

首先明确常量指针和指针常量。

指针常量，是指针不能移动，定义时的写法是const写在星号'*'之后。对这样的指针赋值新地址是非法的。

```c++
int * const p;
```

STL中的迭代器类型加const就可以声明为迭代器常量类型。

```c++
vector<int> vec;
const vector<int>::iterator it = vec.begin();
*it = 10; //合法
++it;//非法
```

因为迭代器本身是以指针做的泛型，所以it可以看成是个指针，所以const it是修饰指针不能移动。

如果希望得到常量迭代器，可以使用const_iterator，指向的值不能改变，但是可以移动。

```c++
vector<int>::const_iterator it = vec.begin();
*it = 10; //非法
++it;//合法
```

#### const修饰函数返回类型

一般来说，对于内置数据类型修饰返回类型为const的操作其实不必要的，但是可能自定义数据类型会有一些不必要的操作。

例如，一个有理数类，重载了乘法运算符。

```c++
class Rational{
  public:
    	const Rational operator*(const Rational & a, const Rational &b);
};
```

可能有些人会想对两个数的乘积再做一次赋值。

```c++
Rational a,b,c;
(a*b) = c; // 怪异的写法
```

a * b的结果是一个Rational类型，这个结果再被c赋值，似乎很难理解，这是个"没意思的赋值动作"，如果加入const限定，就可以避免这种看起来很蛋疼的写法。

可能有的时候，只是想做一个比较，即a * b是否等于c，但是因为手误，少写了一个等号，写成这样

```c++
if (a*b = c)...
```

使用const就可以检查出这个错误，不然确实看着很蛋疼但是没报错，这会让人抓狂。

#### const修饰函数参数

如果是引用，可以避免修改原来主程序的参数。如果不是引用，那么只是单独的限制参数不能修改。例如在需要打印一些值的函数，常常这样去做。

```c++
void func(const int & val);
```

#### const修饰成员函数

即在函数声明后面再多加个const限定，隐式的限定了this指针。

主要目的是为了使class接口更容易理解，这样可以知道函数是否可以改动对象的内容；其次是是成员函数可以操作const对象，因为改善C++程序效率的一个根本方法是以常量引用来传递自定义数据对象，这个前提是有const成员函数。

#### 常量性不同的成员函数可以被重载

这是一个C++的重要特性，如下方的类用于输出一些文字。

```c++
class TextBlock{
	public:
    	TextBlock(string s) { text = s; }
    	const char& operator[](size_t position) const{return text[position];}
    	char& operator[](size_t position) {return text[position];}
    	//const char& operator[](size_t position) {return text[position];}
    private:
    	string text;
};
```

注意，const的位置可以导致4种写法，但是有一种写法是不能写的，限定成员函数为const，但是返回值不加const，这可能导致外部可以修改这个引用的值，与成员函数的const限定违背。

```c++
char& operator[](size_t position) const{return text[position];} // 这种写法编译不通过
```

所以，如果成员函数加了const限定，则返回值如果是引用或者指针之类的也必须加const限定。

还有一种成员函数不是const，那么返回值可以是const也可以是不const的，但是这两个不能同时存在，因为重载不以返回类型进行区分。所以常量性不同是指成员函数的const限定。

对这三种情况分别进行测试。

① 成员函数和返回类型均不限定。

```c++
char& operator[](size_t position) {return text[position];}
```

实例对象不是const类型。

```c++
TextBlock t("123");
t[1]='4'; // 可以写入
char *p = &t[1]; // 可以定义指针
*p = '5'; // 指针写入操作也可以,也会改变原有值
p++; // *p是t[2]的值
```

实例对象是const类型。

```c++
const TextBlock t("123");
t[1]='4'; // 非法,提示没有匹配的操作符
char *p = &t[1]; // 非法,提示没有匹配的操作符
const char *p = &t[1]; // 仍然非法,也就是不能用指针指向const实例的内部成员
*p = '5'; // 不能使用指针指向,后2个也非法
p++; // 非法
```

② 成员函数不限定，返回类型限定。

```c++
const char& operator[](size_t position) {return text[position];}
```

实例对象不是const类型。

```c++
TextBlock t("123");
t[1] = '4'; // 非法,提示必须是可修改的左值,t[1]是const char&类型的
char *p = &t[1];//非法
const char* p = &t[1]; // 合法
*p = 5; //非法
p++; // *p是t[2]的值 合法
```

实例对象是const类型。

```c++
const TextBlock t("123");
t[1] = '4'; // 非法,提示没有匹配的操作符
char *p = &t[1]; // 非法,提示没有匹配的操作符
const char *p = &t[1]; // 仍然非法,也就是不能用指针指向const实例的内部成员
*p = 5; //不能使用指针指向,后2个也非法
p++; // 非法
```

③ 成员函数限定，返回类型也是限定的。

```c++
const char& operator[](size_t position) const{return text[position];}
```

实例对象不是const类型。

```c++
TextBlock t("123");
t[1] = '4'; // 非法,提示必须是可修改的左值,t[1]是const char&类型的
char *p = &t[1];//非法
const char* p = &t[1]; // 合法
*p = 5; //非法
p++; // *p是t[2]的值 合法
```

实例对象是const类型。

```c++
const TextBlock t("123");
t[1] = '4'; // 非法,提示必须是可修改的左值,t[1]是const char&类型的,而不是没有匹配的操作符
char *p = &t[1];//非法
const char* p = &t[1]; // 合法
*p = 5; //非法
p++; // *p是t[2]的值 合法
```

以上总结如下。

① 返回和成员函数都没有const限定：非const实例，可读可写；const实例，可读不可写，没有匹配的操作符。

② 返回限定，成员函数没有限定：非const实例，可读不可写，左值不可修改；const实例，可读不可写，没有匹配的操作符。

③ 返回、成员函数均限定：非const实例和const实例都是可读不可写，且原因是左值不可修改，原因相同。

可以看出，对成员函数加const限定，才能在const实例中不报没有匹配的操作符这个错误。

#### 使用mutable的原因

现在再来看看，为何成员函数加了限定，返回类型不加限定会导致编译错误？这起源于早期对于const的理解问题，有2种流派。

第一种流派认为，const的含义是bitwise constness，认为成员函数不更改实例对象的任何成员变量时才可以说是const，也就是不更改对象内的任何一个bit，编译器只需要禁止成员变量的赋值动作即可。对于返回引用类型的成员函数

```c++
char& operator[](size_t position) const{return text[position];}//其实不能通过编译
```

这个函数确实没有改变实例的成员变量text，但是显然它暴露的是原有成员变量的引用，可以在外部进行改变，这其实违反const的直觉。再如，如果不使用引用，而是指针，也是限定了成员函数const，但是不限定返回了const。

```c++
class CTextBlock{
	public:
    	TextBlock(char *s) { pText = s; }
    	char& operator[](size_t position) const {return text[position];}
    private:
    	char* pText; // 改string为char*
};
```

那么外部也可以定义一个指针，改变原有成员变量，即使成员函数没有改变这个值。

```c++
const CTextBlock ctb("hello");
char * pc = &ctb[0];
*pc = 'J';
```

由于第1种流派违反直觉，所以有第2种流派，也就是logical constness，一个成员函数可以修改成员变量的某些bit。

例如，增加2个成员变量，文字的长度和长度是否有效，显然在length()函数中，这2个函数是可以改变的，这与const违背。

```c++
class CTextBlock{
	public:
		size_t length() const;
    private:
    char* pText;
    size_t textLength;
    bool lengthIsValid;
}
size_t CTextBlock::length()const{
    if (!lengthIsValid){
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}
```

但是编译器还是会要求不能修改这2个变量，那就可以声明这2个变量是可变的，关键字mutable可以释放掉const的约束。

```c++
class CTextBlock{
	public:
		size_t length() const;
    private:
    	char* pText;
    mutable size_t textLength;
    mutable bool lengthIsValid;
}
size_t CTextBlock::length()const{
    if (!lengthIsValid){
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}
```

#### 非const实例调用const版本函数避免代码重复

实际上2个成员函数返回的代码完全一样，为了避免代码重复，可以让其中一个调用另一个。由于非const实例是可以改变的，所以应当在非const成员函数中调用const成员函数，而不是反过来，因为const成员函数本来就要求不能改变实例对象。

```c++
class TextBlock{
	public:
    	TextBlock(string s) { text = s; }
    	const char& operator[](size_t position) const{
            ...各种函数判断
            return text[position];}
    	char& operator[](size_t position) {
            ...各种函数判断
            return text[position];}
    private:
    	string text;
};
```

第2个函数调用第1个函数有两个条件，必须是const实例才能调用const函数，所以第一步可以用static_cast来改变非const实例的常量性，也就是将自身(* this)TextBlock类型转化为const TextBlock&类型。然后调用的是const函数，返回是const类型，所以还需要const_cast来将返回值从const char&转为char &类型，于是这个类可以写为如下。

```c++
class TextBlock{
	public:
    	TextBlock(string s) { text = s; }
    	const char& operator[](size_t position) const{
            ...各种函数判断
            return text[position];}
    	char& operator[](size_t position) {
            return const_cast<char&> (static_cast<const TextBlock&>(*this)[position]);
            }
    private:
    	string text;
};
```

### 条款04：确定对象被使用前已被初始化

