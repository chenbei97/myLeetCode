<!--

 * @Author: chenbei
 * @Date: 2022-03-01 11:46:37
 * @LastEditTime: 2022-03-21 13:46:21
 * @Description: 55 programming suggestions based on Effective C + + Learning
 * @FilePath: \myLeetCode\EffectiveC++.md
 * A boy without dreams
-->
## 〇、导读

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

​		为什么可以使用赋值运算符构造对象呢？因为C++会默认进行隐式转换，调用了类的默认构造函数，p2=10的过程等价于先构造temp(10)，再让p2=10。但是上述一个person对象不仅可以等于const char * ，也可以等于int型，它们之间还能换算，显得不伦不类。为了避免这种情况，可以声明为explicit类型，阻止默认隐式转换。这样，只有两条语句是合法的，其它均不合法。

```c++
person p1(10);
person p3("A");
```

​		现在再来看，为什么要求是默认构造函数或者有参构造函数只带1个参数。因为类构造函数参数大于或等于两个且没有默认参数时时，是不会产生隐式转换的， 所以explicit关键字也就无效，因为person p6 = (1,"A")不存在这种语法。

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
person p6 = (1,"A");//非法
person p6(1,"A"); // 合法
```

​		但大于等于两个参数，如果参数都有默认值的时候，explicit关键字依然有效。

```c++
class person{
  public:
    explicit person(int age){_age=age;}; // 阻止隐式转换
    explicit person(string name){_name=name;}; // 阻止隐式转换
    explicit person(int age, string name){_age=age;_name=name;}; // 加不加都一样
    explicit person(double salary = 18.0,int count=0){_salary=salary;_count=count;};//阻止隐式转换
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

​		具体可以参考[C++ explicit关键字详解](https://blog.csdn.net/guoyunfei123/article/details/89003369)的说明，不过这里有个说法不对，并不是要求第1个参数以外的参数都为默认值才可以，第1个参数也有默认值也是可以的。

​	总结：① 单参数构造，默认支持隐式转换，使用explicit可阻止隐式转换； ② 双参数及以上构造，除第1个参数以外后面的参数都必须有默认值才会默认调用隐式转换，第1个参数可以带默认参数也可以不带，使用explicit可阻止隐式转换。

### 命名习惯

​		使用有意义的字母去描述某个变量。

### 线程

​		对线程不熟悉的话可以忽略。

### TR1和Boost

​		TR1是一份规范，全称是Technical Report 1，描述加入C++标准程序库的诸多新机能，它们以函数模板或者类模板的形式体现，针对的题目有哈希表、引用计数智能指针、正则表达式等，这些组件被置于命名空间tr1内，tr1嵌套于std。

​		Boost是一个组织，或者网站[Boost C++ Libraries](https://www.boost.org/)，提供了源码开放的c++程序库，以前的TR1大多以Boost的工作为基础。

## 一、让自己习惯C++

### 条款01：视C++为一个语言联邦

​		C++支持过程形式(procedural)、面向对象形式(object_oriented)、函数形式(functional)、泛型形式(generic)和元编程形式(meta_programming)，理解这样的语言可以将其看作相关语言组成的联邦语言，而非单一语言。

​		C++的组成部分主要有4部分：

​		C part of C++：古典C，区块(blocks)、语句(statements)、预处理器(preprocessor)、内置数据类型(built-in datat types)、数组(arrays)、指针(pointers)等统统来自于C。C的局限性在于没有模板(template)、没有异常(exceptions)，也没有重载(overloading)；

​		Object_Oriented C++：这部分是真实的C++需求，构造函数class、封装(encapsulation)、继承(inheritance)、多台(polymorphic)、虚函数动态绑定(virtual)等；

​		Template C++：C++的泛型编程风格，威力强大，可以带来崭新的编程范式，也就是元编程(meta_programming)；

​		STL：包括容器(vector、list等)、迭代器(iterator)、算法(algorithm)和函数对象(指针)(functional objects)。

​		记住：内置数据类型，值传递更好；类数据类型，由于构造函数的存在，引用传递更好。

结论：C++高效编程守则视状况而变化，取决于使用C++的哪一部分。

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

结论：

单纯的常量最好以const对象或enums替换#define

对于形似函数的宏(macros)，最好改用inline函数替换#define

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

例如，增加2个成员变量，文字的长度和长度是否有效，显然在length()函数中，这2个成员变量是可以改变的，这与const违背。

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
        textLength = strlen(pText);//私有成员被改变了,这其实不允许
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

结论：

声明为const可以帮助编译器侦测出错误语法，const可以用于任何作用域内的对象、函数参数、函数返回类型和成员函数本体；

编译器强制实施bitwise constness，但你编写程序时应使用概念上的常量性conceptual constness；

const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本可避免代码重复。

### 条款04：确定对象被使用前已被初始化

#### 内置数据对象要手动初始化

C++不保证对无初值对象进行初始化。

```c++
int x,y;
```

#### 初始化不等于赋值操作

除了内置类型，任何数据类型的初始化应当由构造函数完成，然而构造函数可以有2种方式进行初始化。

1种是赋值初始化，这是一种伪初始化，本质上是先调用了默认构造函数，再用新的值来覆盖原来的值。

```c++
class PhoneNumber{
	...
}
class Person{
public:
    Person(const string& name,const int&age,const PhoneNumber& pn){
        this->name = name;
        this->age = age;
        this->pn = pn;
        if (this->age>18) this->isAdult = true;
        else this->isAdult = false;
    }
private:
    string name;
    int age;
    PhoneNumber pn;
    bool isAdult;
}
```

另1种是成员列表初始化，本质上只调用了一次复制构造，直接初始化，而不是覆盖旧值，效率很高。

```c++
class PhoneNumber{
	...
}
class Person{
public:
    Person(const string& name,const int&age,const PhoneNumber& pn)
        :name(name),age(age),pn(pn),isAdult(age>18?1:0){}
private:
    string name;
    int age;
    PhoneNumber pn;
    bool isAdult;
}
```

对于内置类型来说，2种初始化方法的消耗成本相同，但是为了一致性，将内置类型和自定义数据类型同等对待，也就是isAdult也使用成员列表初始化，注意string并不是内置数据类型，是C++基于char实现的新数据类型。

当然上述还可以定义无参构造，内置数据类型记得要手动初始化，因为它没有构造函数。

```c++
class PhoneNumber{
	...
}
class Person{
public:
    Person():name(),age(),pn(),isAdult(age>18?1:0){} // 除了isAdult其它都是调用了默认构造函数
private:
    string name;
    int age;
    PhoneNumber pn;
    bool isAdult;
}
```

#### 成员列表初始化可能重复

类的成员可能很多，构造函数也有很多，每个构造函数可能会初始化某些成员变量，这样就可能导致初始化被重复，这种情况可以让内置数据类型(因为初始化和赋值的成本相同)的成员移入一个函数内使用赋值初始化，这个函数可以被所有构造函数进行调用。而非内置数据类型，使用成员列表初始化更加有效。

#### 成员列表初始化的次序性问题

上述成员列表初始化的构造函数按照name、age、pn和isAdult顺序写的，实际上也可以不按照次序写，例如age先写。因为真正的初始化次序由被声明的顺序决定，显然name先于age被声明，age也先于isAdult被声明，所以它们也相对的先被初始化。为了保证一致性，虽然成员列表初始化的次序不影响，但是也要按照顺序去写。

还有一个问题在于，有的变量初始化依赖于另一个变量的初始化，例如isAdult依赖于age是否大于18，这时候初始化次序的重要性出来了，成员列表初始化时age必须写在isAdult之前。

#### 跨编译单元的初始化次序问题

上边提到的问题还比较简单，是一个类内，自然也在同一个文件中，也可以说是同一个编译单元内初始化次序的问题。有时候2个文件内，分别声明了2个类，第1个文件声明了一个外部对象给第2个类使用，但是这个外部对象没被初始化就被调用就会出问题，例如这样的写法。

```c++
// 文件1
class PhoneNumber{
    int length() const;
}
extern PhoneNumber PN; // 声明外部使用,但未被初始化
// 文件2
class Person{
    ...
    Person(params){
        ...
        int length = PN.length();  
    }  
}
```

实际上，Person内部调用PN时，PN没被初始化，调用length()函数获取长度是错的。除非PN先于Person进行初始化，但是2个文件是在不同时间被不同的人创建，因为C++对不同编译单元内非局部静态对象的初始化相对次序没有明确定义，事实上也无法定义，现实逻辑太复杂，那么避免这个出现，只需要一个小小的设计。

可以不直接操作非局部静态对象，而是将这个对象1个函数内定义，并将其声明为static变量，然后返回其引用。可以这样做，**<u>是因为C++规定函数内的局部静态对象在该函数首次被调用时被初始化，所以一旦调用就先于调用者被初始化，不会引发问题。</u>**

```c++
// 文件1
class PhoneNumber{
    int length() const;
}
PhoneNumber& PN(){
    static PhoneNumber PN;
    return PN; // 静态对象是可以返回的
}
// 文件2
class Person{
    ...
    Person(params){
        ...
        int length = PN().length(); // 可以保证PN()先被初始化 
    }  
}
Person& person(){
    static Person person;
    return person; //Person也可以这样做,给第3个文件使用
}
```

总结，在跨编译单元初始化次序的问题中，使用局部静态对象替换非局部静态对象，可以避免次序错误出现的问题。

结论：

内置型对象进行手工初始化，C++不保证初始化它们；

构造函数最好使用成员初值列而不要在构造函数本体内使用赋值操作。初值列列出的成员变量其排列次序应和class内声明的次序相同；

为免除"跨编译单元之初始化次序"问题，以local static对象替换non-local static对象。

## 二、构造/析构/赋值运算

### 条款05：C++会默认编写并调用哪些函数

直接说结论：如果一个类并没有给出默认构造函数、复制构造函数和赋值运算符重载，则编译器会自动创建这些函数。如果这些函数已经被创建，编译器就不会再创建。

一些特殊情况：

如果基类将赋值运算符重载函数声明为private，那么编译器不会给派生类创建赋值运算符重载函数，因为这样的函数如果被创建，也是可以处理基类的实例对象的，但是这个函数被声明私有，相对于基类而言外部无权使用这样的函数，自然派生类也没有权限。

如果类内有引用或者const对象，赋值运算符操作可以被编译器拒绝。

```c++
class A{
  public:
    A(string&name,const int &age);
  private:
    string & nameVal;
    const int ageVal;
}
string x="a",y="b";
A s1(x,1);
A s2(y,2);
s1 = s2 ;// 编译器拒绝
```

因为这样的操作意味着可以改变s2中nameVal的引用从y指向x，这违背了C++中不允许引用改指向不同对象。同样const对象也不允许重新赋值，所以如果是这样的类，编译器可以拒绝这样的赋值运算符重载。

结论：编译器可以为class创建default构造函数、copy构造函数、copy assignment操作符以及析构函数。

### 条款06：不想使用编译器自动生成的函数就应明确拒绝

由于条款05，编译器会自动创建默认构造、复制构造和析构函数。如果希望阻止复制或默认构造函数的自动创建，可以将这2个函数以private形式给出声明，但不实现，就可以阻止外部使用这2个函数。不过这样的阻止只发生在动态实例生成时才会提示，如果希望能够在编译阶段就提示，可以创建1个父类，使复制和默认构造声明为私有，然后让这个类私有继承这个父类，父类的所有public和protected成员都降级为private，父类的private无法访问，所以子类无法使用父类的这2个函数。

结论：为驳回编译器暗自提供的功能，可将相应的成员函数声明为private且不予实现

### 条款07：为多态基类声明virtual析构函数

简单的一句话概括：父类指针指向子类对象，而子类对象却经由父类指针被删除，当父类有个non-virtual析构函数时，就会引起灾难。引入virtual，就可以让父类指针调用子类的析构函数(因为一般来说父类指针只能调用父类，子类只能调用子类，即使父类指针指向子类，也因为隐式转换的原因还是只能调用父类，所以析构不了子类的成分)。

说的再通俗易懂一些：一般而言基类的对象由基类的析构函数销毁，子类的对象由子类的析构函数销毁。但是因为基类的指针可以指向子类，根据规则"要根据实际对象的类型来选择调用哪一个析构函数"，所以如果删除此时的基类指针，应当调用子类的析构函数，但是如果基类的析构函数没有声明为virtual就会调用基类的析构函数，这样子类的成分并没有被销毁造成内存泄漏。。

另一个结论，带多态性质的base classes应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该拥有一个virtual析构函数。但是如果Classes的设计目的如果不是作为base classes 使用，或不是为了具备多态性，就不该声明virtual析构函数。

结论：

带多态性质polymorphic的基类应声明一个virtual析构函数，如果类带有任何virtual函数，那它应该有个virtual析构函数；

类的设计目的如果不是作为基类使用，或不是为了具备多态性质，就不该声明为virtual函数。

### 条款08：析构函数尽量不要设置异常处理

先说结论。

析构函数最好不要吐出异常，如果析构函数必须要执行某个函数，但是这个函数可能抛出异常的时候，析构函数应当捕捉这种异常，然后吞下它们保证不传播异常或者直接结束程序。析构函数捕捉了这种可能的异常，从设计者的角度来看，是一种保险，也是应当做的，这样可以避免不明确行为，但是应当也要告知使用者析构函数可能会发生的异常，所以应当提供一个普通函数让使用者能够有权处理先处理这种异常，而不是在析构中处理(可能使用者相信不会异常没预先使用普通函数处理可能的异常而倚赖析构函数，这样如果真的出现了异常，使用者也无权抱怨，其实就是甩锅给用户)

现在再来看看为何有这样的结论？

假如有个容器装了10个自定义数据类型的对象，而自定义数据类型可能在析构函数写了个异常处理，那么容器销毁时可能会有不明确行为的发生。容器销毁时应当内部所有的实例都被销毁，现在v有3个A，销毁第1个A时如果有异常，其它2个还是应被销毁，那么v会调用后边2个A的析构函数，结果第2个A又发生异常(C++不能够连续出现2个异常处理，除非异常被吞下或强制执行程序结束)，就会导致不明确行为。所以，析构函数如果可以，不要加入异常处理！

```c++
class A{
	public:
    	...
        ~A(){...};//可能有异常处理
};
vector<A> v={A,A,A};
```

如果析构函数一定要执行某个动作的话，例如数据库连接的例子，类DBC负责数据库连接。

```c++
class DBC{
    public:
    ...
    static DBC create(); // 返回1个DBC对象
    void close();//关闭数据库的函数
};
```

使用者使用DBC对象时，可能会忘记调用DBC的close函数，所以一个设计是用一个类DB来管理这样的DBC对象，并借助析构函数来执行close函数，这样客户即使忘记也无关紧要(前提是没有异常处理的情况下)

```c++
class DB{
  	public:
    	DB(const DBC & dbc): dbc(dbc){}
        ~DB(){
            dbc.close();
        }
   	private:
    	DBC dbc;
};
DB db(DBC::create()); // 用户可能的使用方式,借助DBC返回的对象去调用构造函数得到DB的实例db
// 程序结束时销毁db,会自动调用close函数,即使用户没有自己手动close
```

但是析构函数不能不处理可能的异常，它必须在遇到异常是直接终止程序或者吞下异常。

```c++
DB::~DB()
{
	try{dbc.close();}
    catch(...)
    {
        //log 记录出现的异常
        std::abort(); // 直接终止程序,立刻terminate程序，没有任何清理工作
        // exit也会终止程序,但是它可以释放所有的静态的全局的对象,缓存,关掉所有的I/O通道再终止程序
    }
}
// 或者直接吞下异常
DB::~DB()
{
	try{dbc.close();}
    catch(...)
    {
        //log 记录出现的异常
        // 什么也不做
    }
}
```

即使如此，依然无法让使用者对异常出现时进行反应，所以应当提供一个普通函数让用户有选择权，他们不处理只倚赖析构函数的话，出现问题他们没有理由抱怨。

```c++
class DB{
  public:
    ...
    void close(){
        ddc.close();
        closed = true;
    }

	~DB()
    {
        if (!closed)
        {
            try{db.close();} // 双保险
            catch(...)
            {
                // log 记录出现的异常
                ... // 吞下或者直接终止程序
            }
        }
	}
    private:
    	DBC dbc;
    	bool closed;
};
```

结论：

析构函数不要吐出异常，若析构函数调用的函数可能抛出异常，则析构函数应捕捉任何异常然后吞下它们或终止程序；

客户需要对某个操作函数运行期间抛出的异常做出反应，则类应提供一个普通函数(而非在析构函数)执行该操作。

### 条款09：决不在构造和析构函数调用virtual函数

直接说结论，在构造函数和析构期间不要使用virtual函数。如果基类的构造函数调用了基类的虚函数，假设派生类继承于基类，它自然也会继承基类的同名虚函数。派生类的实例生成时，基类的构造函数会先于派生类的构造函数被调用。那么此时，由于派生类的某些成分可能尚未初始化，包括非静态成员变量和非静态成员函数以及虚函数，C++是不会允许派生类成分还未初始化时就被调用，所以基类的构造函数调用时也必然调用的是基类的虚函数，而不是派生了的同名虚函数。

```c++
class A{
   public:
    	A();
    	virtual void print() const = 0;// 1个虚函数
}；
A::A() // A的构造函数实现
{
    ...
    print(); // 调用了虚函数
}

class B{
    public:
 		virtual void print() const = 0;// 派生类也会继承同名虚函数
};

B b; // B实例化,内部其实调用的是A的print函数而非B的
```

一般的，编译器会对上述代码这样的情况给予警告，换句话说编译阶段还是会提示错误的。如果A未给print函数实现，还是能检测的，但是如果A给出了实现，程序反而不报错，对使用B的人来说他会不明白为何调用的不是B自己的print函数。

解决方案当然是不要在析构或者构造函数内调用虚函数，代替方法是把这个函数声明为普通的非虚函数。派生类想要使用基类的这个非虚函数时，可以传递必要的信息给基类的构造函数，那么派生类的构造函数可以安全的调用基类的这个非虚函数了。

```c++
class A{
   public:
    	explicit A(string & logInfo); // 拒绝隐式转换
    	void print(string & logInfo) const;// 改为非虚函数
}；
A::A(string & logInfo) // A的构造函数实现
{
    ...
    print(logInfo); // 调用了非虚函数
}

class B{
    public:
    	B(parameters) : A(createLogString(parametes)){...};//B的构造函数,会将B的构造信息自动传递给A的构造函数
 	private:
    	static string createLogString(parametes); // 使用单独的函数创建更有可读性
};
```

注意，createLogString函数声明为静态的是必要的，它可以保证在派生的构造函数尚未初始化完时，也能使用这个函数，因为这个函数内部可以保证不会指向任何派生类尚未初始化的成员。

结论：构造和虚构函数不要调用virtual函数，因为这类调用不会下降至派生类。

### 条款10：让operator=的重载返回一个指向*this的引用

目的是为了能够实现连锁赋值，例如这样的赋值。

```c++
int x,y,z;
x = y = z = 5; // 使用右结合律,等价于x=(y=(z=5))
```

对于类，适用于+=，-=，* = 和 /=，以及=。

```c++
class A{
	public:
		A& operator=(const A& a){
            ...
            return *this;//返回*this的引用
        }
    	A& operator=(int a){
            ...
            return * this; //即使参数是int也是可以的
        }
    	A& operator+=(const A& a){
            ...
            return * this; //即使参数是int也是可以的
        }
       	A& operator-=(const A& a){
            ...
            return * this; //即使参数是int也是可以的
        }
};
```

这样的条款并不是强制的，但是该条款被所有内置容器类型都遵循，所以最好遵守。

结论：让赋值操作符assignment能够返回reference to * this。

### 条款11：在operator=中处理"自我赋值"

自我赋值就是这样的，可能有点蠢，但是可能会发生。

```c++
class A{
	...
};
A a;
a = a;
```

有时候也会出现潜在的自我赋值。

```c++
a[i]=a[j]; // i=j时
*px = *py; // 2个指针指向同一地址时
```

由于基类指针或引用可以指向派生类，如果某个函数同时具备形参是基类和派生类的引用或指针，就很可能是一个东西。

例如下边的rb和rd可能是1个东西。

```c++
void doSomething(const base& rb,const derived & rd)
```

所以如果函数需要处理多个对象，需要思考如果对象是同一个时是否能够保证安全性。

假设现在有2个类A和B，B中的私有成员指针指向了A，B提供了运算符=的重载函数，但是这个函数是不安全的。如果rhs和this是同一个对象，删除pa指针的时候就把rhs的pa也删除了，然后pa指向一个并不存在的A指针指向的内存，就会出错。

```c++
class A{...};
class B{
    ...
    private:
    	A * pa;
};
B& B::operator=(const B& rhs)
{
    delete pa;
    pa = new A(*rhs.pa);
    return *this;
}
```

有3个解决方案，改写这个运算符重载函数。

第1个方案加证同测试，这样能够保证自我赋值安全性，但是对异常安全性还有所欠缺。

```c++
B& B::operator=(const B& rhs)
{
    if (this == &rhs) return *this;//可以保证自我赋值安全性
    delete pa;
    pa = new A(*rhs.pa); // 但是不保证异常安全性,可能A的构造函数会有异常抛出,pa依然指向不存在的内存
    return *this;
}
```

第2个方案，只关注异常安全性，一般解决了异常安全性，也就具备了自我赋值安全性。解决方法是晚些删除指针pa。

```c++
B& B::operator=(const B& rhs)
{
    A* t = pa; // 1个指针记住原来的pa
    pa = new A(*rhs.pa);//尝试让A指向新地址,A的构造可能异常也不异常
    delete t; //ab新指向如果没问题,多余的指针t被删除毫无问题;若pa指向失败,pa尚未删除不会影响*this
    return *this;
}
```

方案1和方案2可以一起结合，这样同时具备异常安全性和自我赋值安全性。不过这样的代码会变大，降低执行速度，更好的解决方案是第3个，也就是copy and swap技术。

第3个方案，之所以不安全无非是赋值过程可能导致指针指向的内容二次被删除，所以安全的方法是创建副本，也就是copy，创建副本借助复制构造函数完成。然后在swap函数中实现副本和this的互换。

```c++
B& B::operator=(const B& rhs)
{
	B temp(rhs);// 复制构造
    swap(temp);
    return *this;
}
void swap(B& rhs){
    ...//交换rhs和*this的数据
}
```

还有一种写法，可以无需借助复制构造函数，只需要让操作运算符的参数以值传递的方式传递即可，那么它自动会创建副本。

```c++
B& B::operator=(B rhs)
{
    swap(rhs); // 交换的是值传递的副本
    return *this;
}
```

第2种写法没有第1种写法清晰，但是第2种写法比较高效。

结论：

确保对象自我赋值时operator=有良好行为，技术包括比较来源对象和目标对象的地址、精心周到的语句顺序以及copy_and_swap；

确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确。

### 条款12：复制对象时勿忘每一个成分

定义一个类以后，在copy函数和copy assignment函数中都必须将所有的成员变量进行复制，否则会面临未初始化变量被使用的风险。像下方这样的写法，编译器不会提出警告。

```c++
class A{...};
class B{
    public:
    	...
    private:
    	string name;
    	A myA;
};
B::B(const B& rhs):name(rhs.name)
{
    // this->myA = rhs.myA; //如果不调用A的copy assignment函数
}
B& B::operator=(const B& rhs)
{
    this->name = rhs.name;
    // this->myA = rhs.myA; //如果不调用A的copy assignment函数
    return *this;
}
```

如果类是派生类，还需要注意调用基类的构造函数，来初始化派生类对象的基类成分。

```c++
class newA:public A
{
    newA(const newA& rhs);// copy
    newA& operator=(const newA &rhs); // copy assignment
    ...
    private:
    	int age;
};
newA::newA(const newA& rhs):age(rhs.age),A(rhs)//还应当调用基类的构造函数来初始化rhs的基类成分
{
    ...
}
newA& newA::operator=(const newA &rhs)
{
    this->age = age;
    A::operator=(rhs); // 调用基类的构造函数来初始化rhs的基类成分
    return *this;
}
```

最后1个问题，虽然copy和copy assignment函数很相似，但是不要为了减少重复代码而尝试让其中一个调用另一个，应当使用的方法是，把共同的代码写在一个函数里，设为private函数，这个函数常命名为init函数。理由如下。

如果copy函数调用copy assignment函数：可能的写法如下，this尚不存在，用rhs来构造不存在的对象这没有意义

```c++
newA :: newA(const newA& rhs)
{
	*this = rhs;	
}
```

如果copy assignment函数调用copy函数：因为copy是来初始化新对象，而this已经存在不需要构造函数来借助rhs构造出this。

```c++
newA& newA::operator=(const newA &rhs)
{
    newA *this(rhs);
    return *this;
}
```

总的来说，copy函数是从无到有构造1个对象，而copy assignment更像是把1个已存在的对象从未初始化状态变为初始化对象。

结论：

copy函数应当确保复制"对象内所有的成员变量"和"所有base class"成分；

不要尝试以某个coping函数实现另1个coping函数，应将共同的操作放入第三个函数，由2个copy函数共同调用。

## 三、资源管理

### 条款13：以对象管理资源

假如存在某个模型被一个类所描述，例如投资模型，工厂函数用于返回一个模型给调用者使用。

```c++
class Investment
{
	...
};
Investment* createInvestment();// 工厂函数
void f()
{
    Investment* pInv = createInvestment();
    ...
    delete pInv;//有义务删除这个指针
}
```

但是f()函数很可能因为前边语句过早的return或者某些异常而导致执行不到最后1行，亦或者delete处于某个循环，而continue、goto、break之类的过早结束循环导致pInv没有释放。总是依仗f函数一定会执行delete语句是不现实的，一个想法是把从工厂函数获得的资源绑定在对象上，就可以借助C++的析构函数自动调用机制来确保资源被释放。

以对象管理资源的2个关键想法：

① 获得资源后立刻放进管理对象(资源取得时机便是初始化时机 resource acquisition is initialization RAII对象)；

② 管理对象运用析构函数确保资源释放。

#### 引入auto_ptr

标准程序库提供了一个智能指针auto_ptr，它是个类指针对象，用于管理资源。

在f函数可以这样使用：使用了auto_ptr的模板机制<>和构造函数机制，对返回的资源进行绑定智能指针，那么就无需手动delete就可以在pInv离开作用域后被释放。

```c++
void f()
{
	std::auto_ptr<Investment> pInv(createInvestment());
    ...
    // 无需手动delete
}
```

但是不应当让多个auto_ptr指向同一个资源，否则会被释放2次。为了预防这个问题，auto_ptr被设计时带有一个性质，它的copy构造函数和copy assignment函数被调用时，那么复制所得到的指针会获得对资源的唯一拥有全权，而被复制的指针会置为nullptr。

```c++
std::auto_ptr<Investment> pInv1(createInvestment());
std::auto_ptr<Investment> pInv2（pInv1);// pInv1会置为nullptr,pInv2取得资源的唯一控制权
pInv1 = pInv2; //pInv1再次取得资源的控制权,pInv2置为nullptr
```

如果希望发挥正常的复制行为，不应当使用auto_ptr，替代方案是使用引用计数型智慧指针RCSP，它可以追踪共有多少对象指向某个资源，并在无人指向它时自动删除该资源。RCSP提供的行为类似于垃圾回收，但RCSP无法打破环状引用，例如2个其实没被使用的对象彼此互指，它们就好像还在被使用状态，RCSP是无法删除这2个对象的。

#### 引入shared_ptr

shared_ptr就是一种RCSP指针，它的使用方式和auto_ptr别无二致，不过要注意它是在tr1的命名空间下的。只有PInv2和pInv1都被销毁时资源才会被销毁。

```c++
std::tr1::shared_ptr<Investment> pInv1(createInvestment());
std::tr1::shared_ptr<Investment> pInv2（pInv1); // PInv2和pInv1指向同1个对象
pInv1 = pInv2; // PInv2和pInv1指向同1个对象
```

不过本条款不是针对这2个指针，如果希望了解更多shared_ptr的信息，可以看条款14、18和54。

这2个智能指针类内部的析构函数调用的都是delete，而不是delete []，所以也就是说无法将动态分配的数组类型资源绑定到这2个指针上。虽然不应该这样做，但是如果这样做编译器不会提示任何问题。

```c++
std::auto_prt<int> ap_arr(new int[10]);
std::tr1::shared_ptr<string> sp_arr(new string[10]);
```

不过c++中并没有提供类似于这2个智能指针的去释放数组类型的资源的类，这是因为vector、string等总是可以取到动态分配的数组。如果一定要针对数组涉及的智能指针，可以在Boost中寻找，它提供的函数boost::scoped_array和boost::shared_array 就可以提供类似的行为。

但是这2个指针类也不能处理所有情况的资源管理，因为不是所有资源都是heap_based，这时这两类指针不适用于作为资源掌控者，这时候就必须手动释放资源，也就是自定义资源管理类。

最后总结：为了防止资源泄露，应当使用RAII对象，常用的就是上述2个指针，一般而言shared_ptr更常被使用，因为它的copy行为更直观。

结论：

为防止资源泄露，应使用RII对象，它们在构造函数中获得资源并在析构函数中释放资源；

两个常使用的RAII classes 分别是tr1::shared_ptr和auto_ptr。前者通常是较佳选择，因为copy行为直观，而auto_ptr会使被复制的指针指向nullptr。

### 条款14：自定义资源管理类小心copying行为

假设有2个函数用于管理Mutex的互斥器对象，为了不忘记将一个被锁住的mutex对象解锁，可能希望建立一个类来管理mutex对象。

```c++
void lock(Mutex*pm);//锁定pm指向的互斥器
void unlock(Mutex*pm);// 将pm指向的互斥器解锁
```

建立的互斥器资源管理类Lock。

```c++
class Lock
{
    public:
    	explicit Lock(Mutex*pm) : mutexPtr(pm) // 拒绝隐式转换,列表参数初始化私有变量mutexPtr
        {
            lock(mutexPtr); // 构造时自动给互斥器对象上锁
        }
   ~Lock(){unlock(mutexPtr);} // 析构时自动给互斥器对象去锁
    private:
    	Mutex * mutexPtr;
}
```

客户可能的使用方式。

```c++
Mutex m; //定义了互斥器对象
...
// 在某个区域内{},可能是一段函数
{
  Lock m1(&m); // 锁定了m
  ... //一些操作
};//这里结束后,m会被自动解锁,无需手动解锁
```

现在再来看看关心的问题，如果Lock的对象被复制应当发生什么？

```c++
Lock m11(&m);
Lock m12(m11);//应当发生什么？
```

一种做法是禁止copy操作，条款6给出了禁止自动copy构造函数的创建方式，使用一个类将copy设为private，然后Lock类继承于它即可。之所以禁止，可能是这样的操作并不合理。

还有一种做法是增加引用计数法来管理资源，可以借助shared_ptr将私有变量mutexPtr从使用Mutex * 来定义转为间接的使用tr1::shared_ptr< Mutex >来定义，那么mutexPtr就是一个智能指针。但是这存在一个问题，如果引用次数为0时就删除所指物，而私有变量mutexPtr的目的是锁定对象而非删除对象。

但是可以借助tr1::shared_ptr的第2参数，也就是删除器deleter，这是一个函数或者函数对象，引用次数为0时就自动调用这个函数。

```c++
class Lock{
    public:
    	explicit Lock(Mutex*pm):mutexPtr(pm,unlock)//unlock作为deleter参数
        {
            lock(mutexPtr.get());// lock要求传入的是Mut指针而非ex指针而非mutexPtr,get可以隐式转换
        }
    private:
    	std::tr1::shared_ptr<Mutex> mutexPtr;
}
```

所以资源管理器对象计数为0时会自动调用unlock函数，也就给互斥器对象去锁了。

再来总结一下，自定义资源管理器类对copy的处理方式：

① 可以禁止copy构造函数；

② 复制资源器管理对象时也要复制底部资源，也就是深拷贝；

③ 如果希望只保留一个智能指针指向1个资源类似于auto_ptr，就应当转移底部资源的拥有权。

结论：

复制RAII对象必须一并复制它所管理的资源，所以资源的copy行为决定了RAII对象的copy行为；

普遍常见的RAII class copying行为是：抑制copying、施行引用计数法(reference counting)。

### 条款15：在资源管理类提供对原始资源的访问

资源管理类可以处理和资源的互动，无需手动直接处理原始资源。但是有些API函数会直接访问处理资源，而不是通过类。

例如一个返回投资天数的函数，它要求传入的就是资源的一个指针，但不是智能指针。

```c++
int daysHeld(const Investment *pi);

std::tr1::shared_ptr<Investment>pInv(createInnvestment());
int days = daysHeld(pInv); // 这样使用是错误的
```

如果希望这个函数可以处理pInv的底层资源，可以借助函数将其转换为底层资源，可以使用隐式转换和显示转换。

auto_ptr和shared_ptr都提供一个get函数，用来执行显示转换，也就是它可以返回智能指针内部绑定的原始指针的复件。

所以上边的函数可以这样使用了。

```c++
int days = daysHeld(pInv.get());
```

因为智能指针也算是指针，所以内部也重载了解引用运算符，就像迭代器解引用就是真实的数据，智能指针也一样，可以隐式转换为底部原始指针。现在让Investment类建立一个函数，isTaxFree，演示隐式转换的使用。

```c++
class Investment
{
    public:
    	bool isTaxFree()const;
    	...
};
Investment* createInvestment();//工厂函数
// 使用隐式转换
std::tr1::shared_ptr<Investment> pi1(createInvestment);
bool taxLabel1 = pil->isTaxFree();//operator->隐式转换
bool taxLabel1 = (*pil).isTaxFree(); // operator* 隐式转换
```

不过一般隐式转换比显示转换更好，例如有一个字体资源类Font，处理字体的类FontHandle，然后有大量的函数需要处理FontHandle，但是其实要处理的是底层的Font，这就需要Font->FontHandle很频繁的转换。

可以定义一个Font内的get函数，手动显示转换。

```c++
class Font
{
    public:
    	explicit Font(FontHandle fh): fh(fh){}//Font绑定FontHandle
    	~Font() {releaseFont(fh)};
        FontHandle get() const{return fh} ;//显示转换
    private:
    	FontHandle fh;
};
FontHandle getFont(); //获取资源的API
void releaseFont(FontHandle fh);//释放资源的API
void changeFontSize(FontHandle fh, int newSize);//改变字体大小的API
// 以上的函数都是借助操作FontHandle来间接操作底层的Font

Font f(getFont);//获取资源,构造函数绑定1个管理资源的对象
int newFontSize;
changeFontSize(f.get(),newFontSize);//显式转换Font->FontHandle
```

不过这样的使用方式比较麻烦，一般使用隐式转换。

```c++
class Font
{
    public:
    	explicit Font(FontHandle fh): f(fh){}//Font绑定FontHandle
    	~Font() {releaseFont(fh)};
        //FontHandle get() const{return fh} ;//显示转换
    	operator FontHandle()const{return fh};// 把FontHandle看成一种操作如<<
    private:
    	FontHandle fh;
};

Font f(getFont);//获取资源,构造函数绑定1个管理资源的对象
int newFontSize;
changeFontSize(f,newFontSize);//隐式转换Font->FontHandle,(FontHandle f)把FontHandle看成一种操作
```

不过隐式转换可能增加错误的机会，例如客户可能想复制一个Font对象但是手误，定义时使用了FontHandle。这样f2返回的不是Font对象而是FontHandle。假如f1被销毁，由于隐式转换的原因，f2不是深拷贝，它也是返回了实际f1，但是现在f1已被销毁，f2就成了一个虚吊的东西。

```c++
Font f1(getFont());
FontHandle f2 = f1;//手误,但是程序不会因为类型不同报错
```

结论：

API往往要求直接访问原始资源，所以管理资源的类应当提供一个取得管理的资源的办法；

对原始资源的访问可以通过隐式转换和显式转换。

### 条款16：成对使用delete和new时要采用相同形式

如下方代码。

```c++
string* s1 = new string;
string* s2 = new string [10];

delete s1;
delete [] s2;
```

 如果使用不相同形式的new和delete，例如

```c++
delete [] s1;//未有定义
delete s2;//未有定义且可能有害
```

如果使用typedef，例如addressNums表示具有4个字符串的数组。

```c++
typedef string addressNums[4];
string *p = new addressNums;//等价于new string[4];
delete [] p;//应这样使用
```

 不过最好不要对数组类型取别名，因为C++标准库含有string、vector等模板，可以将对数组的需求降为0。本例中更好的使用方式是

```c++
typedef vector<string> addressNums;
vector<string> *p = new addressNums;
delete p;//it's ok
```

### 条款17：以独立语句将new的对象置入智能指针

假设存在2个函数，一个是返回处理的优先权，一个是对动态分配的资源Widget进行带优先权的处理。

```c++
int priority();
void processWidget(std::tr1::shared_ptr<Widget>pw,int priority);
```

使用processWidget函数的方式1，这种必然不对，因为shared_ptr内部没有隐式转换，它的构造函数使用了explicit。

```c++
processWidget(new Widget,priority()); // 不能通过编译
```

使用processWidget函数的方式2，可能存在一些问题。

```c++
processWidget(std::tr1::shared_ptr<Widget>(new Widget),priority()); // 编译器执行顺序的自由度不同
```

这个方式实际上要执行3个操作，对priority函数调用，调用shared_ptr的构造函数，动态分配一个Widget。显然动态分配一个Widget必须在shared_ptr的构造函数之前调用，而priority函数可以以任何次序被调用。

但是这样存在一个问题，假如priority函数在调用shared_ptr的构造函数之前，那么执行次序是这样的

```c++
动态分配一个Widget
调用priority函数
调用shared_ptr的构造函数
```

如果priority函数发生了异常，动态分配的Widget就遗失，这就会发生资源泄露，避免这样的问题出现，应使用第3种方式。即使用分离语句，分别写出创建Widget，置入智能指针，调用函数priority，再传入函数。

```c++
std::tr1::shared_ptr<Widget>pw(new Widget);
int prior = priority();
processWidget(pw,prior);
```

结论：以独立语句将new出的对象置入智能指针，若不这样做一旦异常抛出可能导致资源泄露。

## 四、设计与声明

### 条款18：让接口容易被正确使用、不易被误用

开发一个类，需要**注意限制类型、限制参数范围，以及正确的资源管理**，而不是让用户去注意这些东西。

例如一个简单的日期类，这样的构造函数可能会导致传入的参数次序不对、范围不对。

```c++
class Date
{
    public:
    	Date(int month,int day,int year);
};
```

更好的方式是创建Month、Day、Year的结构体限制其类型。

```c++
struct Day
{
    explicit Day(int d): val(d){}
    int val;
};
struct Month
{
    explicit Month(int m): val(d){}
    int val;
};
struct Year
{
    explicit Year(int y): val(d){}
    int val;
};
class Date
{
    public:
    	Date(const Month&m,const Day&d,const Year& y);
};
```

 而Month、Day、Year更好的是使用成熟迭代过的类来限制范围。例如对于月份类，除了限制其类型，也要限制其范围，可以使用enum表现月份，但是因为enum可以作为int使用不具备类型安全性，所以应当预先定义有效的months。

这里定义有效的months使用的是static成员函数，而不是非静态成员变量。在条款03中提到了跨编译单元的初始化次序问题，所以使用函数来操作局部静态对象替代直接操作非局部静态对象更好。

```c++
class Month
{
	public:
    	static Month Jan(){return Month(1);}//使用static成员函数而不是直接定义Month(1)
    	static Month Feb(){return Month(2);}
    	...
        static Month Dec(){return Month(12);}
    private:
    	explicit Month(int m);//拒绝可能的隐式转换,例如Month m = 4;
};
```

最后一个，资源正确管理的责任在于设计者而非客户。例如第3章提到的类Investment的工厂函数。

```c++
Investment * createInvestment();
```

这个函数就有一些错误倾向，客户可能忘记对得到的Investment指针进行销毁，所以设计者有义务将创建出来的指针直接绑定到智能指针，借助它来管理，所以工厂函数写成这样更合理，直接返回智能指针，而不是让客户自己去绑定智能指针。

```c++
std::tr1::shared_ptr<Investment> createInvestment();
```

还存在一个问题，例如互斥锁的问题，如果客户并不是想要智能指针自动销毁创建的资源对象，而是将其解锁。那么设计者不仅有责任返回一个智能指针，还应当返回一个带deleter函数作为第2参数的智能指针。deleter函数是客户自己定义的，例如它是unlock函数。那么createInvestment的写法可能如下所示。

```c++
std::tr1::shared_ptr<Investment> createInvestment()
{
    std::tr1::shared_ptr<Investment> investment(
    	static<Investment*>(0),unlock);//绑定unlock函数作为删除器
    return investment;
}
```

shared_ptr还有个好处，它销毁对象会使用创建对象时对应的那个delete去销毁(如果deleter是默认的缺省状态)，可以避免跨动态连接程序库DLL的错误。因为可能某些对象在一个DLL被new，但是在另一个DLL被delete，这可能会导致错误。

还有1个准则，就是**让定义的数据类型和内置数据类型尽可能保持一致的行为**。例如对于整型来说让 a * b = c并不合法，所以自定义的类 Month，它的实例m1 * m2 = m3也不能合法。

结论：

促进正确使用的方法是， 让定义的数据类型和内置数据类型尽可能保持一致的行为；

阻止误用的方法是，建立新类型、限制类型的操作，束缚对象值以及消除客户的资源管理责任；

使用shared_ptr，支持定制型删除器，可防范DLL问题，可被用来自动解除互斥锁。

### 条款19：设计class犹如设计type

设计一个type需要考虑的主题如下，设计class也可以参照其思考方式。

- 新type的对象如何被创建和销毁(关键:operator new 和operator delete的重载函数,条款50-52)?
- 对象的初始化和对象的赋值该有什么样的差别(关键:default构造函数和copy assignment的区别,条款04)?
- 新type的对象若被值传递意味着什么(关键:copy 构造函数的实现)?
- 什么是新type的合法值(关键:构造函数和copy assignment函数)?因为类成员变量可能处于限定范围和类型,所以错误检查工作必须要在构造函数和copy assignment等进行,并抛出合理的异常,函数异常明细也应当被列出
- 新type是否需要配合某个继承体系(关键:继承的基类函数是否存在virtual限定,条款34和36;自身又是否需要定义virtual,条款07)?
- 新type需要什么样的转换(关键:operator dstType()或non-explicit 构造函数,显式or隐式转换,条款15)?类型T1需要转换为类型T2.如果T1只接收explicit构造,说明只接收显式转换即单独定义一个函数来执行操作(条款15的get函数);T1接收隐式转换的话,就可以定义operator T2()隐式转换重载函数;当然也可以在T2类内写接受non-explicit的构造函数
- 什么样的操作符和函数对此新type合理(关键:为class声明的合理函数,哪些是member函数,条款06)?也许type不希望copy,就可以参考条款06的操作来阻止默认生成的copy构造
- 什么样的标准函数需要被驳回(就是条款06)?
- 谁该取用新type的成员函数(关键:访问层级的定义,public,protected,private以及friend)?
- 什么是新type的未声明接口(关键:效率,异常和资源管理是如何保证的,条款29)?
- 新type是否具备一般化的性质(关键:可能定义的不是1个type而是整个types家族,那么应当使用template)?
- 真的需要一个新type吗(可能在基类多定义non_member函数或者引入template就可以达到目的)?



### 条款20：使用passby_reference_const代替passby_value

使用常量引用的方式可以避免大量的构造析构函数被调用，效率比较高。

引用传递还可以避免参数切割问题，这个问题主要发生在派生类对象被传入一个本该是基类对象的函数上。这样基类的构造函数会被默认调用，只保留了派生类中基类的成分。例如具备2个函数的窗口类，分别用于返回窗口名称和打印窗口名称。

```c++
class Windows
{
    public:
    	string name() const;
    	virtual display() const;
};
class WindowsWithScrollBars:public Window
{
    public:
    	virtual display() const;
};
```

现在一个函数用于打印窗口名和显示窗口。

```c++
void printWindowsNameAndDisplay(Window w)
{
    cout<<w.name()<<"\n";
    w.display();
}
```

这个函数传入的是Windows对象，则一点问题没有；但是如果传入的是派生类WindowsWithScrollBars对象，则它会退化成基类对象Windows，内部调用的永远是Windows::display()函数，而不是WindowsWithScrollBars::display()函数。

解决这个问题的办法就是不使用值传递，也就不会调用构造函数，传进来的是什么类型就能展现什么类型，实现动态绑定。

```c++
void printWindowsNameAndDisplay(const Window& w)
{
    cout<<w.name()<<"\n";
    w.display();
}
```

结论：

尽量以const reference代替value传递，可以避免参数切割问题；

该规则不适用于内置类型，对于内置类型或者STL的迭代器和函数对象，value传递可能更好。

### 条款21：必须返回对象时不要返回其reference

虽然说传递参数尽可能使用引用传递，但是返回时并不是这样，考虑一个有理数类。

```c++
class Rational
{
	public:
		Rational(int numerator=0,int denominator=1);//分子分母
    private:
    	int n,d;
    friend const Rational operator*(const Rational&lhs,cosnt Rational &rhs);//为了实现左操作数不是this且能够访问私有属性,要声明为friend函数
};
```

这样的定义其实是合理的，虽然它返回时调用了构造和析构函数造成一些成本，但是它造成的成本远比返回const reference对象造成的麻烦小的多。

第1个麻烦是，reference要知道它其实就是某个变量的别名，这个变量以前就存在。如果operator * 的左操作数是this，返回 * this还是正确的，因为this事先已经存在。但是对于这里的双操作数，返回的一个已经存在的变量引用是啥玩意呢？

创建变量，显然是在stack申请内存，也可以在heap申请内存，还可以使用静态变量static。但是显然返回一个stack申请的变量是错误的，它在函数运行结束后就被销毁。那么返回一个堆的内存呢？虽然是可以，但是引入了资源泄露的风险。static变量会造成多线程安全的问题，还会造成奇怪的逻辑问题。

```c++
const Rational& operator*(const Rational&lhs,cosnt Rational &rhs)
{
    Rational res(lhs.n * rhs.n,lhs.d * rhs.d); // stack创建的,一定错误
    return res;
}

const Rational& operator*(const Rational&lhs,cosnt Rational &rhs)
{
    Rational *res = new Rational (lhs.n * rhs.n,lhs.d * rhs.d); // heap创建的,有资源泄露风险
    return *res; // 返回的指针如何delete?
}
```

有时候未必使用delete就能避免资源泄露，例如下方的代码，本意是实现连乘计算。

```c++
Rational w,x,y,x;
w = x * y * z; // 等价于operator*(operator*(x,y),z),优先级自左向右
```

这样一条语句调用了2次new，那也需要2次delete，然而返回却是1个对象，operator * 背后的指针已经无法获取。

如果使用static变量，确实可以返回引用，但是每次返回的引用地址都是一个东西。假如，存在一些逻辑运算，就会出现奇怪的bug。

operator * (a,b)的调用的确会改变res的值，operator * (c,d)也会改变res的值，但是不会改变res的地址。2次返回的是一个东西，那么比较逻辑总是true，那么else语句永远不会被执行。

```c++
const Rational& operator*(const Rational&lhs,cosnt Rational &rhs)
{
    static Rational res; // 静态变量只有1次初始化,地址永远不会变化
    res.n = lhs.n * rhs.n;
    res.d = lhs.d * rhs.d; 
    return res;
}
// 外部使用
Rational a,b,c,d;
if ((a * b) == (c * d)) // 等价于operator==(operator*(a,b),operator*(c,d))
{
    ...
}
else
{
    ...
}
```

最重要的是，res变量只能被使用存储1个值，但是即使定义静态数组vector也没有意义。声明vector意味着可能要消耗存储空间，就可能需要一些限制，这些额外的成本都不如只调用1次析构和构造消耗的成本。所以回到最开始吧，那样的就是最好的。

结论：

不要试图返回指针或引用指向一个local stack对象、或引用指向heap对象、或指针和引用指向local static对象(而且这样的对象需要很多)。如何在单线程环境中合理返回指向local static对象的引用在条款04可见。

### 条款22：将成员变量声明为private

将成员变量声明为private，通过函数来访问成员变量，函数便可以提供变量的只读、只写、可读可写的区分度。

另外还可提供弹性，成员变量被读被写时可以轻松通知其它对象、验证class的约束性以及和函数的前提和事后状态。

对于public成员变量，如果取消它会有很多客户代码受到影响，而protected则会影响派生类，所以把public和protected都可以看作一类，也就是没有封装性，private视为有封装。

结论：同标题名，另外protected不比public更有弹性。

### 条款23：宁以non-member&non-friend替换member函数

假设有个浏览器的类需要做一些动作，它有3个函数，用于清除缓存、清除浏览历史，移除cookies等。如果用户希望一次性执行这些动作，这个函数可以声明为成员或非成员函数，哪个更好？

```c++
class webBrowser
{
    public:
    	void clearCache();
    	void clearHistory();
    	void removeCookies();
    	
    	void clearEverything();//member函数,内部调用3个函数
};
void clearBrowser(webBrowser& wb)// non-member函数
{
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}
```

面向对象守则认为：那些数据和操作数据的函数应当捆绑在一起，所以认为member函数更好。但是它还认为数据应该尽可能的被封装，member函数带来的封装性低，而non-member函数具有更大的包裹弹性。下边说明其原因。

封装性意味着东西不可见，它的改变只能影响对它可见的那些代码，代码改动的弹性很大，只会影响有限客户；

条款22说明了成员变量应该是private，否则会有无限量的函数去访问它，它们也就毫无封装性，能够访问private的函数只有member函数以及friend函数。现在还要再non-member函数和member函数去选择，显然non-member封装性更好，如果它不是friend，它无法访问类的那些private成员、enum以及typedef等，但是member函数都可以访问。

有两件需要注意的事情：

第一件，这里的注意力是放在member和non-member&non-friend函数，不仅在于是否member，因为friend函数也可访问类的private变量。

第二件，虽然函数可以为了封装性是一个class的non-member函数，但不意味着它不可以是另一个class的member函数。

#### namespace的组织方式

举一个例子来说明如何使用namespace组织同一个类的程序库，它可以降低编译依存度。namespace允许将某个类和及其相关的一些便利函数放在不同的文件，而class是不行的，因为class必须整体定义，不可能一部分成员函数在一个文件，另一些成员函数在其他文件。至于降低编译依存度，就是客户只取用感兴趣的那一部分即可，而不必整体都进行编译。

以标准程序库为例，它不是一个庞大的、单一整体的一个文件，而且都不是写在std命名空间下，而是有数十个头文件。有的客户只对vector感兴趣，有的只对list感兴趣，所以如果不想使用list，也就不必包含list的头文件。降低编译依存度详细可见条款31。

对于上述的浏览器类和那个非成员函数，一般放在一个命名空间里，命名空间在头文件中定义。

```c++
// "WebBrowser.h"头文件,包含了类自身和一些核心机能
namespace WebBrowserStuff{
    class WebBrowser{...};
    void clearBrowser(WebBrowser&wb);
    ...
}
```

然后有大量的函数可能是用于处理WebBrowser的Cache，还有的是专门处理Cookies，那就可以在两个不同头文件下在相同的命名空间内定义这些函数。

```c++
// "WebBrowserCache.h"
namespace WebBrowserStuff{
    ... // 和cache有关的函数
}
```

```c++
// "WebBrowserCookies.h"
namespace WebBrowserStuff{
    ... // 和cookies有关的函数
}//
```

结论：

用non-member&non-friend函数替换member函数增加封装性、包裹弹性；

善于利用namespace组织程序库，降低编译依赖度。

### 条款24：若所有参数需要类型转换，使用non-member函数

 导读中曾提到，最好不支持class的隐式转换，使用关键字explicit可以阻止默认的隐式转换。

所谓隐式转换是，调用默认的构造函数，将一个传入的类型自动转换为构造的类型。

关于隐式转换，只复习下结论。① 单参数构造，默认支持隐式转换，使用explicit可阻止隐式转换； ② 双参数及以上构造，除第1个参数以外后面的参数都必须有默认值才会默认调用隐式转换，第1个参数可以带默认参数也可以不带，使用explicit可阻止隐式转换。

具体关于explicit的内容，见[explicit关键字的作用](#explicit关键字的作用)。

现在设计一个支持隐式转换的有理数类如下。

```c++
class Rational
{
    public:
    	Rational(int numerator=0,int denominator=1);
    	int numerator() const;
    	int denominator() const;
    private:
    	int n, d;
};
```

如果希望能够实现有理数的算术运算，应当采用non-member函数定义，这样左操作数可以不用是this，可以保持加法交换律乘法交换律这样的规则，使之看起来更自然。

non-member函数的定义如下。为何返回const类型可见条款21。

```c++
const Rational operator*(const Rational& lhs,const Rational&rhs)
{
    return Rational(lhs.numerator()*rhs.numerator(),lhs.denominator()*rhs.denominator());
}
```

如果使用member函数的定义，就像这样。这里应当返回引用。

```c++
Rational& operator*(const Rational&rhs)
{
    n = n * rhs.numerator();
    d = d * rhs.denominator();
    return *this;
}
```

但是这样的定义不支持下边第2条这样的运算。

```c++
Rational w,x;
w = x * 2;//成立,为什么?隐式调用了构造函数
w = 2 * x ; // 不成立,左操作数必须是this
```

第1条的运算成立是因为隐式调用了构造函数，如果想阻止这种转换可以让构造函数声明为explicit。

```c++
const Rational temp(2); // 以2构造Rational对象
w = x * temp; 
```

现在回到开头，显然定义最早那样的non-member函数更好，但还有个问题，这个问题是否应该成为friend函数。

答案是不需要，因为内部无需访问私有变量，Rational已提供了2个只读函数，为了封装性，无需声明为friend。

除了上述的一些讨论点，本条款真正想说的是：

结论：如果需要为某个函数的所有参数(包括this指针所指的隐喻参数)进行类型转换，那么这个函数必须是non-member。

### 条款25：考虑写出一个不抛异常的swap函数

典型的swap函数实现如下，只要T类型定义了合理的copy构造函数和copy assignment函数就可以完成交换。

```c++
namespace std{
    template<typename T>
    void swap(T &a, T & b)
    {
        T temp(a);//调用T的copy函数
        a = b ; //调用T的copy assignment函数
        b = temp;//调用T的copy assignment函数
    }
}
```

但是有的类其实无需这样的copy、copy assignment去交换对象，可能只需要交换2个指针，常见于以pimpl手法实现的class。

#### pimpl手法

pimpl是"pointer to implementation"的简称，也就是指向实现的指针，这个实现是一个包含数据的类对象。

例如，Widget类的设计之前会设计一个WidgetImpl类。

```c++
class WidgetImpl
{
    public:
    	...//实现细节不重要
    private:
    	int a,b,c;
    	vector<double> v;//很多的数据,意味着复制时间很长
    	...
};
class Widget
{
    public:
    	Widget(const Widget& rhs);
    	Widget& operator=(const Widget& rhs)
        {
            ...
            *pImpl = *(rhs.pImpl);//只需交换指针就可以交换this和rhs
        }
    private:
    	WidgetImpl* pImpl; // 指向Widget对象本身的指针
};
```

但是swap函数不知道这一点，它正常会调用Widget的构造函数3次，并复制3次pImpl变量，非常缺乏效率。

如果希望swap函数能够知道只需交换pImpl指针，就可以让swap函数针对Widget进行优化。

代码实现目前写成这样，但无法通过编译。

```c++
namespace std
{
    template<> void swap<Widget>(Widget&a,Widget&b)
    {
        swap(a.pImpl,b.pImpl);
    }
}
```

template<>表示它是一个std::swap的一个全特化版本，而函数名称swap< Widget >表示这一版本是针对T=Widget设计的。C++不允许对std命名空间内的任何东西进行改变，但是可以为标准模板template提供全特化版本，使它专属某个类的使用。

无法通过编译的原因是，pImpl指针是private的，但是上述语法是存在的。所以可以把这个特异版本的函数声明为friend函数，但是一般不这样去做。

#### 同时定义member&non-memeber的swap函数

如果不想要使用friend(为了封装性)去修饰特异化版本的std::swap，而且还想访问特异版本的私有成员，可以同时定义member和non-member2个版本的函数，并让non-memebr调用member函数。

```c++
using namespace std // 现在是std命名空间下
{
    class WidgetImpl{...}
    class Widget
    {
        public:
            void swap(Widget& other)
            {
                using std::swap; // 此句的意思是可以使用命名空间std
                swap(pImpl,other.pImpl); //使用特异版本swap
            }
        private:
            WidgetImpl* pImpl;
    };
    template<> void swap<Widget>(Widget&a,Widget&b)// 特异版本swap
    {
        a.swap(b);// 内部调用member函数,避免声明为friend
    }
}
```

#### 不要给std空间添加任何重载的东西

目前这样的写法完全正确，能通过编译。现在希望不仅仅是对Widget特异，还希望对Widget< T >特异，也就是对一批行为特异，还想让特异版本也有弹性，可能的写法像这样。

```c++
using namespace std
{
    template<typename T>
    class WidgetImpl{...}
    
    template<typename T>
    class Widget
    {
        public:
            void swap(Widget<T>& other)
            {
                using std::swap; // 此句的意思是可以使用命名空间std
                swap(pImpl,other.pImpl); //使用特异版本swap,它也具有弹性
            }
        private:
            WidgetImpl<T>* pImpl;
    };
    template<typename T> 
    void swap<Widget<T> >(Widget<T>&a,Widget<T>&b)// 特异版本下的swap还想维持弹性,也就是特异一批行为,偏特化
    {
        a.swap(b);
    }
}
```

但是上述这样的写法是不合法的，因为C++只允许对class templates进行偏特化，不允许对function templates偏特化。上边通过编译写法的是对std::swap的全特化，而不是偏特化，这里的偏是指模板T，是偏向Widget< T>，也就是swap后边跟着的。所以真正应该实现的写法是，将swap好似看成对std::swap的重载版本，只是参数类型不同。

```c++
using namespace std
{
	template<typename T> 
    void swap<T>(Widget<T>&a,Widget<T>&b)// 重载版本,只有参数类型不同
    {
        a.swap(b);
    }
}
```

虽然这样写确实没问题，但是相当于给std的命名空间内添加了新的东西。标准委员会禁止人们自定义东西膨胀内部代码，即使通过编译，但是这样的函数只会导致未定义行为。

#### 使用namespace来实现全/偏特化版本swap的弹性

一个更好的解决方法是，使用自己的命名空间，隔离开std空间，在这里实现自己的特异版本就没什么问题。

上边所有类、函数的实现都相同，使用函数重载版本的swap函数，只是命名空间换了。

```c++
using namespace WidgetStuff // 唯一的区别
{
    template<typename T>
    class WidgetImpl{...}
    
    template<typename T>
    class Widget
    {
        public:
            void swap(Widget<T>& other)
            {
                using std::swap; // 这条语句的意思会说明
                swap(pImpl,other.pImpl); 
            }
        private:
            WidgetImpl<T>* pImpl;
    };
    template<typename T> 
    void swap<Widget<T> >(Widget<T>&a,Widget<T>&b)
    {
        a.swap(b);
    }
}
```

C++的名称查找法则要说明一下，如果你打算使用swap函数。它首先会从标准库的swap函数寻找，然后查找标准库swap的特异化版本，也就是std::swap下的全/偏特化版本，最后会查找是否存在依附于某个命名空间下的swap函数。但是优先会使用特异化版，且优先使用std空间下的特异版本。

从用户的角度来说，他肯定希望有多份保障，如果有最合适的就找最合适的，没有更合适的就使用一般化的，这也是这条语句的含义

```c++
using std::swap;
swap(pImpl,other.pImpl); // 可以使用std或WidgetStuff的

std:: swap(pImpl,other.pImpl);//但不要写成这样,这是指定只能使用std内的
```

#### member版本的swap不要抛出异常

最后1个问题，成员版的swap函数不要抛出异常，因为要求swap帮助class和template class提供强烈的异常安全性保证，条款29对此进行说明。不过这个约束是针对成员版的，非成员版的是可以的，因为非成员版本正常依赖于copy和copy assignment函数实现，它们允许异常抛出，所以不加以限制。如果是内置类型，例如指针、int或者double，这种交换操作是不会抛出异常的，所以成员版本的swap函数(真正的交换操作)去直接面对内置类型，是一定不会抛出异常的，所以不要在这里抛出异常。

结论：

① std::swap对自定义的类执行的操作效率不高时，考虑提供一个swap成员函数，这个函数不能抛出异常；

② 如果提供了member swap函数，由于std空间下的swap函数更容易被人使用，也应当提供std下swap函数的特异版本，它内部调用了memeber swap函数； 

③ 声明自己命名空间下的swap函数也是可以的，但是它没有std::swap的常用，所以最好遵循第2个结论也给出std下的特异版本；

④ C++支持class和function的全特化，支持class template的偏特化，但不支持function template的偏特化，只允许function template的重载，但是不要给std内添加这些东西。

## 五、实现

类的声明完成以后，就是类的实现。

类的实现希望不要太快定义变量造成效率的拖延；希望不要过度使用转型(casts)操作导致代码变慢且难以维护；希望不要返回私有数据变量的引用、指针等导致破坏封装和导致资源泄露的问题；不考虑异常处理，也会导致资源泄露和数据败坏；不要过度使用inline造成代码膨胀；不要过度耦合，会导致冗长的建置时间。本章的这些条款都可以避免这些问题。

### 条款26：尽可能延后变量定义式的出现时间

如果一个变量被定义，程序的控制流到达和离开时都会造成构造和析构成本，无论变量是否被使用。

虽然说很少有人会定义不使用的变量，但是有可能在未使用这个变量之前就出现了异常导致并没有使用，所以即插即用比较好。

此外，定义一个变量最好直接使用copy函数得到它应该有的值。

```c++
string name = "cb"; // 不好的做法
name = password; // 调用2次copy assignment

string name; // 不好的做法
name = "cb";//调用了默认构造+copy assignment

string name(password);//最好的做法,只调用一次copy
```

再来考虑循环，有两种做法进行循环。

```c++
Widget w;
for(int i=0;i<n;++i)
    w = 某个i的值;
```

或

```c++
for(int i=0;i<n;++i)
    Widget w = 某个i的值;
```

第一种做法的成本：

1个构造函数+1个析构函数+n个copy assignment函数

第二种做法的成本：

n个构造函数+n个析构函数

若赋值成本远低于构造，第1种做法高效；若n值很大或者赋值效率低，则第2种可能更好。

结论：尽可能延后变量定义式的出现，可以增加程序的清晰度和改善程序效率。

### 条款27：尽量少做转型动作

C风格的转型相对安全，但是C++的不一定。

C风格的转型动作

```c++
(T)expression
```

其他语言例如Python的转型动作

```c++
T(expression)
```

C++提供的新式转型。

```c++
const_cast<T>(expression);
dynamic_cast<T>(expression);
reinterpret_cast<T>(expression);
static_cast<T>(expression);
```

const_cast用于剔除对象的常量性，也是唯一这样做的转型操作符；

dynamic_cast主要用来执行安全向下转型，也就是用来决定某对象是否归属继承体系的某个类型，它也是唯一旧式语法无法执行的动作，也是唯一可能耗费重大运行成本的转型动作；

reinterpret_cast意图执行低级转型，实际结果取决于编译器，也就表示它不可移植；例如把指向int的指针转为整型，这类转型在低级代码很少见；

static_cast用来强迫隐式转换，例如non-const转为const对象，或者int转为double，也可以执行某些转换的反向转换，例如将void * 指针转为typed指针，将基类指针转为派生类指针，但是不能将const转为non-const，这个需要使用const_cast。

一个转型的例子。

```c++
void doSomeWork(const Widget& w);
doSomeWork(Widget(15));//C风格,调用构造函数
doSomeWork(static_cast<Widget>(15));//C++风格
```

#### 单一对象可能拥有一个以上地址

如果对象是派生类的对象，实际上它会有1个基类地址，1个派生类地址。使用基类指针指向它时，指向的是对象的基类地址，使用派生类指针指向它时，指向的是派生类地址。

只有C++可能发生这种事，尤其在多重继承发生的时候。

#### 不要在派生类内部转型为基类

例如基类有1个virtual函数，派生类也有同名virtual函数，如为了减少代码重复的目的让派生类使用该函数时对自身this转型再调用函数，好像这样可以调用基类的函数，其实并不是！它调用的不仅不是基类的函数，也不是派生类的函数，而是派生类对象自身具有的基类成分的副本函数！

```c++
class Window
{
    public:
    	virtual void reSize(){...}// non-const
};
class specialWindow : public Window
{
    public:
    	virtual void reSize(){
            static_cast<Window>(*this).reSize();//尝试将自身转型为Window来调用基类函数
        }
};
```

实际上调用的reSize函数不是当前对象身上的函数，调用的因为转型动作所建立的this对象的base class成分的副本上的reSize函数。

这样的reSize函数可能会影响其内部可以操作的数据。同时即使基类更改了reSize函数，当前对象实际没有改动，改动的是转型产生的副本，这样基类成分的更改对this而言其实没有落实，也就是reSize函数没有真的执行和影响this对象。

所以正确的方法，直接调用基类的reSize函数即可，拿掉转型动作，不要哄骗编译器this是个基类对象。

```c++
class specialWindow : public Window
{
    public:
    	virtual void reSize(){
            Window::reSize();//拿掉转型动作,声明作用域
        }
};
```

#### 尽可能避免使用dynamic_cast

该转型动作的执行速度很慢，之所以用到这个转型动作可能是因为。客户手上只要基类的指针和引用，但是知道它指向的其实是派生类，现在想要执行派生类的操作函数，所以想要把基类指针能够转型为派生类指针。

有2个方法可以代替使用dynamic_cast。

第1个方法，使用容器存储直接指向派生类对象的指针(通常是智能指针)，就可以避免通过基类接口来处理对象的问题。

不过这个方法更像是预防，也就是容器一开始存储好指向派生类的指针，自然而可以使用派生类的方法。但一开始用容器存储基类的指针不是什么好主意。

```c++
typedef vector<std::tr1::shared_ptr<Window> > VSP;
VSP winPtrs;
for (VSP::iterator it = winPtrs.begin();it!=winPtrs.end();++it)
{
    if (specialWindow * psw = dynamic_cast<specialWindow*>(it->get()))
        psw->reSize();//将基类的底层指针用get获取然后转为派生类指针,再调用其函数
}
```

这样的操作不好，而应当是遍历存放派生类指针的容器，这样只需要1次隐式转换解引用即可。

```c++
typedef vector<std::tr1::shared_ptr<specialWindow> > VSWP;
VSWP winSpePtrs;
for (VSWP::iterator it = winSpePtrs.begin();
     it!=winSpePtrs.end();++it)
{
     （*it）->reSize();//隐式转换,智能指针->底层指针
}
```

另外这种做法只能存储specialWindow这一类型派生类的指针，而不能存储各种类型的派生类指针。

第2个方法可以解决这个问题，那就是在基类中提供虚函数，提供基类相对派生类做的任何事，这样就不必转型操作才能调用派生类的函数，基类同样可以调用此函数。基类只是提供个虚函数，但是可以不给出实现。不过条款34说明了如果不给出实现，缺省代码可能是个馊主意。

第2个代码的解决方案示例。

```c++
class Window{
    public:
    	virtual void reSize(){}//缺省
    	...
}
class specialWindow{
    public:
    	virtual void reSize(){...}//给出实现
}
typedef std::vector<std::tr1::shared_ptr<Window>> VPW;
VPW winPtrs;
...
for(VPW::iterator it = winPtrs.begin();it!=winPtrs.end();++it)
    (*it)->reSize();//没有dynamic_cast
```

最后，即使使用了dynamic_cast，也要避免连串的使用，像下方代码，如果继承体系发生变化，这一类代码都需要重新检查是否修改，且如果有新的派生类加入，可能这些判断还要加入新的条件分支，这样的代码应当基于virtual函数调用来代替。

```c++
class Window{...}
class DW1{...}//派生类1
class DW2{...}//派生类2
class DW3{...}//派生类3
...
typedef std::vector<std::tr1::shared_ptr<Window>> VPW;
VPW winPtrs;
...
for(VPW::iterator it = winPtrs.begin();it!=winPtrs.end();++it)
{
    if (DW1* pdw1 = dynamic_cast<DW1>(it->get())
        {...}//做些事情
    else if (DW2* pdw2 = dynamic_cast<DW2>(it->get())
        {...}//做些事情
    else if (DW3* pdw3 = dynamic_cast<DW3>(it->get())
        {...}//做些事情
    ... // 更多条件分支
}
```

结论：

如果可以，尽量避免转型，注重效率的代码避免使用dynamic_cast，如果有个设计需要转型动作，试着发展无需转型的替代设计；

若转型是必要的，试着把它隐藏于某个函数背后，客户调用该函数不需要将转型放入自己的代码内；

宁可使用C++新式转型，不要使用旧式转型，前者容易辨识且有着分门别类的职责。

### 条款28：避免返回句柄(handles)指向对象内部成分

所谓句柄，是指返回对象的引用、指针或者迭代器等。

看一个场景，矩形类的定义需要点类构造，但是矩形类自身又不想专门定义这样的点类成员去存储它，而是提供点类的指针，真正存放点的数据在对象外。

```c++
class Point
{
    public:
    	Point(int x,int y);
    	void setX(int val);
    	void setY(int val);
};
struct RectData
{
    // 2点可确定矩形大小
    Point upperLeft;//左上角坐标
    Point lowerRight;//右下角坐标
}
class Rectangle
{
    public:
    	Rectangle(const Point&p1,const Point& p2);
    	Point& upperLeft() const{return pData->upperLeft;}
    	Point& lowerRight() const{return pData->lowerRight;}
    private:
    	std::tr1::shared_ptr<RectData> pData;//指向存放数据的指针
}
```

Rectangle的2个函数确实是const类型，它没有改变这样的对象内部成员，符合bitwise constness。但是我们不应该这样去看待它，因为外部调用者可以去改变对象的值，即使对象是const的类型。

```c++
Point p1(0,0);
Point p2(100,100);
const Rectangle rec(p1,p2); // const类型
rec.upperLeft().setX(50);//外部却可以改变const对象的内部数据
```

实际上这不符合真正的const逻辑，避免这样的事情发生，可以将2个函数的返回类型声明为const。

```c++
const Point& upperLeft() const{return pData->upperLeft;}
const Point& lowerRight() const{return pData->lowerRight;}
```

即使返回的const解决了这样的问题，但是2个函数确实还是返回了handles，它们可能在其他场合出现问题，可能handles指向的东西并不存在，但是返回了。因为很可能某些场景，例如局部函数内部借助其它函数得到了一个局部Rectangle对象，函数执行完会被销毁，但是函数内部使用1个指针指向了Rectangle对象调用upperLeft()或lowerRight()返回的引用，并将其返回，那这样就会出现问题，因为返回的指针会因为那个局部Rectangle对象被销毁而导致虚吊。

这里的重点不在于handles是引用，指针还是迭代器，也不在于返回的handles是否为const，也不在于返回handles的那个函数是否const，很简单就是在于它返回了handles是原罪。

结论：不要返回指向对象内部的指针、引用和迭代器，帮助const成员函数像个const，并将发生虚吊handles的可能性降至最低。

### 条款29：为异常安全而努力是值得的

什么是异常安全？异常安全性要求不泄露任何资源，不允许数据败坏。

下边是一个比较糟糕的函数实现，一个GUI切换背景图片的操作。

```c++
class GUI
{
    public:
    	void changeBackGroundImage(std::istream& imgSrc);//一个图像所在地址
    private:
    	Mutex mutex;//互斥器
    	Image* bgImage;// 指向图像的所在地址,GUI自身不存储数据
    	int imageChanges;//图像改变次数
}
void GUI::changeBackGroundImage(std::istream& imgSrc)
{
    lock(&mutex);
    delete bgImage;
    ++imageChanges;
    bgImage = new Image(imgSrc);
    unlock(&mutex);
}
```

显然这里主要存在4个问题。

第一、lock和unlock之间可能发生异常，那么unlock不被执行的话则mutex永远被锁住发生资源泄露；

第二、Image的构造函数可能会有异常；

第三、删除了bgImage之后无法恢复到以前的状态，imageChanges应当成功改变图像后才+1；

第四、即使一切正常，bgImage指向new出的新对象，这个对象的delete也需要手动管理；

所以针对以上问题，可以引入资源管理类Lock，见条款14以及智能指针条款13解决。将代码实现更改如下。

```c++
class Lock{...}//条款14 引入资源管理类
class GUI
{
    public:
    	void changeBackGroundImage(std::istream& imgSrc);//一个图像所在地址
    private:
    	Mutex mutex;
    	std::tr1::shared_ptr<Image> bgImage;// 修改为使用智能指针,条款13
    	int imageChanges;
}
void GUI::changeBackGroundImage(std::istream& imgSrc)
{
    Lock m1(&mutex);
    bgImage.reset(new Image(imgSrc)); // 智能智能重设底层指针的方法reset
    ++imageChanges; // 调整语句位置
}
```

#### copy and swap手法

这段代码还有一个问题，就是Image的构造问题，也就是第2个问题没解决。解决方案可以利用copy and swap手法。也就是把要改变的东西先建立一个副本，在副本上进行改变，如果成功改变，就交换它，否则还是原样。

对于GUI类的2个私有成员bgImage和imageChanges可以考虑转移，用一个结构体或一个类去存储它，这样使用copy and swap手法时比较方便，因为切换图像背景后需要改变的就是这2个私有成员，这样整体进行swap。相应的GUI只需要这样一个数据类型的指针作为私有成员即可，自身不存储任何数据。

```c++
class Lock{...}
class GUI
{
    public:
    	void changeBackGroundImage(std::istream& imgSrc);//一个图像所在地址
    private:
    	Mutex mutex;
    	std::tr1::shared_ptr<PMImpl> pImpl; // 函数会改变的成员
}
struct PMImpl
{
    std::tr1::shared_ptr<Image> bgImage;
    int imageChanges;
}
void GUI::changeBackGroundImage(std::istream& imgSrc)
{
    using std::swap;//见条款25
    Lock m1(&mutex);
	std::tr1::shared_ptr<PMImpl> temp(new PMImpl(*pImpl));//copy pImpl
    temp->bgImage.reset(new Image(imgSrc));//change temp
    swap(pImpl,temp);// swap temp and pImpl
}
```

现在函数的异常安全性提高了很多，现在出现一个问题，异常安全性要满足什么样的要求？

#### 异常安全性的三种保证

第一：基本承诺，保证异常抛出时，程序的任何事物仍然保持在有效状态，没有任何对象或数据结构因此而败坏；例如如果异常抛出，图像可以还使用以前的图像或者某个缺省时用到的图像。

第二、强烈保证，异常抛出后程序状态不变，也就是会恢复到原来的状态。即程序要不完全成功，要不就是失败，返回以前的状态；

第三、保证不抛出任何异常，这对内置数据类型很有用。

异常安全码必须保证上述三种保证之一，否则它不具备异常安全性。

但是即使都保证了，不代表就具有强烈异常安全，举个例子，某个函数内部调用了2个函数f1和f2。

```c++
void f()
{
    f1();
    f2();
}
```

如果f1函数只提供基本承诺，显然f函数的下限其实是被f1拉低的，就像木桶装水只取决于那个最短的木板，那么f函数也只能最多提供基本承诺；除非写下一些代码能够记录f1的状态，f1异常时可以恢复，那么f可以强烈保证异常安全性。

如果f1和f2都是强烈异常安全，f也不一定是强烈异常安全。很可能f1执行完系统发生了一些变化，系统接受了这个状态，因为f1没有异常是正常执行，紧接着f2出现了异常，这下好了，并不能恢复到f调用前的系统状态，只能恢复到f1正常运行结束的状态。

结论：

异常安全函数必须满足三种保证；

强烈保证往往可以通过copy and swap手法实现出来，但强烈保证不是对所有函数都具备实现意义；

函数提供的异常安全保证取决于内部调用的各个函数异常安全性的最弱者。

### 条款30：透彻了解inlining的里里外外

inline看起来像函数，动作像函数，且比宏函数好(条款02)，调用它们也不需要蒙受函数调用所导致的额外开销。

① 编译器可以针对inline函数做出最优优化，但是inline函数可能会导致目标码变大，消耗内存和效率。

② class本体内实现的函数定义都隐式的使用了inline。

③ inline只是对编译器的一个申请，不是强制命令。

例如，带有复杂的递归或者循环逻辑的函数、virtual函数可能会拒绝为inline。因为virtual意味着动态绑定，也就是运行时才知道使用哪个函数，而inline通常是编译器期间就已经知道，因为它要在调用前把函数体代码替换为调用动作。

通过函数指针间接调用的内联函数也可能不执行inline。

```c++
inline void f();
void (*pf)() =f;//函数指针pf指向f
f(); // inline
pf();//不一定inline
```

④ 不要将析构函数或者构造函数声明为inline，即使代码没有任何实现。

代码没有任何实现只是针对设计者而言，实际上对编译器来说，这并不是一段空白代码，它带上了很多的异常处理。

例如某个继承于基类的派生类的构造函数为空白。

```c++
class Base {
    public:
    	...
    private:
    	string bm1,bm2;
}
class Derived
{
    public:
    	Derived(){}
    	...
    private:
    	string dm1,dm2,dm3;
}
```

在编译器眼中，Derived实际上可能是这样的，实际的异常处理可能比这个还要复杂，因为编译器有责任如果基类构造出现异常应当销毁基类的成分，后面的变量构造异常时有责任销毁前边已经构造的东西，显然这一大堆代码会导致代码的无限膨胀。

```c++
class Derived
{
    Base::Base();//基类构造
    try{dm1.std::string::string();}
    catch(...){
        Base::~Base();
        throw;}//有异常要调用基类析构
    try{dm2.std::string::string();}
    catch(...){
        dm1.std::string::~string();//构造dm2异常时就删除dm1
        Base::~Base();
        throw;}
    try{dm3.std::string::string();}
    catch(...){
        dm1.std::string::~string();//构造dm3异常时就删除dm1,dm2
        dm2.std::string::~string();
        Base::~Base();
        throw;}
    
    public:
    	Derived(){}
    	...
    private:
    	string dm1,dm2,dm3;
}
```

⑤ inline函数无法随着程序库的升级而升级，改动inline函数就要重新进行编译，而普通函数可以动态链接更新。

⑥ inline函数是本不存在的函数，只在调用时复制在调用点，这就意味着它不能断点调试。

结论：

将大多数inline限制在小型、频繁被调用的函数身上，可使后序的调试过程和二进制升级更容易，也可使潜在的代码膨胀问题更小化，使程序的速度提升机会最大化；

不要因为function templates出现在头文件就将它们声明为inline。

### 条款31：将文件间的编译依存关系降至最低

考虑一个例子，下方由于三个私有变量其实给出了定义，所以Person在这里不仅给出了class接口，还给出了一些实现。

```c++
#include <string>
#include "Date.h"
#include "Address.h"
class Person
{
    public:
    	Person(const string&name,const Date& birthday,const Address &addr);
        string name() const;
        string birthDate() const;
        string address() const;
    private:
    	// 3个实现条目
    	string theName; // 这3个私有变量都是定义式,不是声明式
    	Date theBirthDate;
    	Address theAddress;
}
```

如果倚赖的2个头文件有所改变，或者这2个头文件倚赖的头文件有所改变，亦或者是Person类的私有东西改变，就要重新进行编译。

可能的方法是去掉Person的实现条目，对Person用到的类进行一些前置声明即可，这样Person的用户只需要在Person接口被修改时才需要重新编译，至于Person的具体实现不会影响接口本身。

```c++
namespace std{
    class string; // 声明std内的string类
}
class Date;
class Address;
class Person
{
    public:
    	Person(const string&name,const Date& birthday,const Address &addr);
        string name() const;
        string birthDate() const;
        string address() const;
}
```

不过上述的想法有些问题。

第一，string不是个类，它其实时basic_string< char >的别名typedef，因此上述关于string的前置声明并不正确。正确的声明比较复杂，因为这里还会涉及到templates，但是也不需要这么做，本就不该声明一些标准库内的某些东西，而应当使用#include来包含你感兴趣的类。

第二，编译器必须在编译器内知道对象的大小，只提供接口的Person无法知道其大小，这个问题应该由Person的定义式来给出答案。为了降低编译依存度，提供2个做法。

#### 将接口定义为handle类

我们要做的是声明提供1个文件，定义提供1个文件，使用Person时其实用的是Person的指针，真正的数据隐藏在指针背后，这样声明类其实可以看成是个handle，定义类是handle真正调用的类。

```c++
#include <string> // 标准组件不该前置声明而直接使用include即可
#include <memory> // 包含shared_ptr
class PersonImpl;//Person的实现类前置声明
class Date; // Person接口用到的class前置声明
class Address;// Date和Address中也和Person一样这么做
class Person
{
    public:
    	Person(const string&name,const Date& birthday,const Address &addr);
        string name() const;
        string birthDate() const;
        string address() const;
    private:
		std::tr1::shared_ptr<PersonImpl> pImpl;//指针,指向Person真正的实现
}
```

这样的设计下，Person的客户完全与Dates、Address以及Person的实现条目实现分离了，核心在于以class声明式代替class定义式。这启示我们，如果可以借助对象的指针或引用来完成任务，就不要使用具体的对象。

如果某个函数的定义需要借助某个类，无需提供类的定义式，只需提供声明式，C++会自动查找。

```c++
class Date;
class Address;//只需要声明式
Date void today();
void clearAddress(Address&addr);
```

现在把这些声明式各自放在某个头文件中，例如Person.h，然后就像这样使用Person类。

```c++
#include "Person.h" // 声明式
#include "PersonImpl.h" // 定义式
// 客户的cpp文件
Person::Person(const string& name, const Date&birthday,const Address&addr)
    :Pimpl(new PersonImpl(name,birthday,addr)){}
string Person::name() const
{
    return pImpl->name();
}
```

不同客户可以给出不同的实现，但是都是利用这个接口，所以这样的handle类不会改变要做的事，只是改变做这件事的方法。

#### 将接口定义为interface类

另一种方法是利用继承机制和virtual机制。

将想要实现的接口类声明为基类，函数均为虚函数，像这样。

```c++
class Person
{
    public:
    	virtual string name() const = 0;
    	virtual birthDate() const = 0;
    	virtual address() const = 0;
        static std::tr1::shared_ptr<Person> create(const string&name,const Date&birthday,const Address& addr);//提供给用户使用的工厂函数
    ...
};
```

客户想要使用这种接口，必须使用它的指针或者引用来调用自己写的派生类的构造函数，也就是说那个派生类必须被定义出来，真正的构造函数必须被调用，这样除非Person的接口改变了否则不需要重新编译。

现在假设有个cpp文件定义了这样的派生类。

```c++
#include "Person.h" //包含了Person基类的头文件
class RealPerson: public Person
{
    public:
        RealPerson(const string&name,const Date&birthday,const Address&adrr):
            theName(name),theBirth(birthday),theAddress(addr){}
        virtual ~RealPerson(){}
        string name() const;
        string birthDate() const;
        string address() const;
    private:
    	string theName;
    	Date theBirth;
    	Address theAddress;
}
// 派生类提供了基类的工厂函数的实现
std::tr1::shared_ptr<Person> Person::create(const string&name,const Date&birthday,const Address&adrr)
{
    return std::tr1::shared_ptr<Person> (new RealPerson(name,birthday,addr));
}
```

客户的使用方式如下。

```c++
string name;
Date birthday;
Address address;
// 客户创建一个接口工厂函数返回的对象,但是内部真正调用的是派生类的构造函数
std::tr1::shared_ptr<Person> pf(Person::create(name,birthday,address));//静态函数直接使用作用域调用
```

也就是说，通过定义interface类继承接口类，然后实现出接口类需要覆盖的函数，定义interface类还有一种方法，见条款40。

但是2种方式都有一定的代价。

对于handle类，handle类可以定义指向实现类的指针，这个指针占据一些内存。同时指针指向一个动态分配而来的实现类对象初始化，故还要经历构造和析构的开销，并可能会遭遇bad_alloc的错误。

对于interface类，每个函数都是virtual，故每次函数调用实际上需要间接跳跃，访问的是它的派生类函数，这个成本需要考虑。同时每个派生类的对象内部都含有一个vptr，也就是虚表指针，这个指针可能会增加存放对象所需的内存数量。

结论：

支持编译依存度最小化的思想是，依赖于声明式而非定义式，存在两个手段，即handle class和interface class；

程序库头文件应该以"完全仅有声明式"的形式存在，这种做法无论是否涉及templates都存在。

## 六、继承与面向对象设计

主要涉及如何采用单一继承还是多重继承？继承使用public、protected还是private继承？成员函数定义为virtual、non-virtual还是pure virtual函数；缺省的参数值对virtual函数有什么影响？继承如何影响C++的名称查找原则？设计选项有哪些？class的行为需要更改时，virtual函数是最佳选择吗？

### 条款32：确定你的public继承塑模出is-a关系

