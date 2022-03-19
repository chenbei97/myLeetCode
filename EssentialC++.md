<!--
 * @Author: chenbei
 * @Date: 2022-02-28 07:54:12
 * @LastEditTime: 2022-03-16 08:32:03
 * @Description: learning the essence and origin of C + + based on essential C + +
 * @FilePath: \myLeetCode\EssentialC++.md
 * A boy without dreams
-->
## 一、C++编程基础

### 1.1 什么是命名空间？

命名空间是一种将库名称封装起来的办法，通过这种方法可以避免和应用程序发生命名冲突的问题。例如想使用cin和cout对象需要包含头文件< string >和< iostream>的同时，必须使用标准命名空间std。

### 1.2 为何要允许构造函数语法？

例如，下方的2种变量初始化方式都是正确的。

```c++
int a = 1;
int b(0);
```

因为对象可能需要多个初值，例如复数，如果是第1种使用"="初始化，只能赋1个值。

```c++
#include <complex>
complex<double> a(3,4); // 3+4j
```

### 1.3 运算符的优先级

只列举常见的运算符，最高的优先级是非，也就是!；

最低的优先级是赋值运算符，也就是=；

其次较高优先级的运算符为算术运算符的乘除，然后加减；

再其次是关系运算符，大于、小于，大宇等于和小于等于，这4个优先级比关系运算符==和!=高；

最后是逻辑运算符，&&优先级高于||。

```c++
[!] => [*,/] => [+,-] => []>,<,>=,<=] => [==,!=] => [&&] => [||] => [=] 
```

  ### 1.4 switch语句加break的原因?

因为不加break，case语句和小括号内的表达式值匹配后 ，在这条case语句后面的所有case语句都会执行，所以为了只执行1条语句，即多选一的逻辑需要加break语句。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

### 1.5 for循环的三个组成部分

其中condition部分是循环开始之前被计算出来，如果不满足条件，1次也不会执行。

expression部分是在循环结束之后被计算出来。

```c++
for( init_statement ; condition ; expression)
    statement;
```

### 1.6 ++i和i++的区别

如果是单独的语句，并没有区别。得到的结果是一样的。在for循环中i++和--i作为expression也是没有区别的，因为expression是循环结束后计算出来，最后结果不会改变。

不过i++语句是需要一个临时变量取存储返回自增前的值，而++i不需要。这样就导致使用i++时系统需要先申请一段内存空间，然后将值塞进去，最后不用了才去释放。

```c++
i++;
--j;
```

如果是表达式，就会有所区别。i++是表达式先用i的值，再让i自增，所以n的值为1；++j是先把j增加1，所以表达式的值变为2，故m=2。

```c++
int i,j = 1;
int n = i++;
int m = ++j;
```

### 1.7 srand与rand

srand是随机数种子，可以传入整数代表1个种子生成伪随机数，也可以传入随时间变化的随机种子为真随机数。srand包含于 <stdlib.h>头文件中。

```c++
#include <stdlib.h>
srand(6);

#include <time.h>
srand(time(NULL));
```

rand会生成0和int所能到达的最大整数之间的1个整数，如果需要限定范围，可以使用取余的方式得到。

```c++
int n = rand() % 6 ; // 生成0-5的随机数 
```

### 1.8 输入输出流 fstream

需要包含头文件，fstream，其内部包含输入流和输出流的类。

#### 1.8.1 输出流ofstream

输出流的对象，是指把文件打开后，把用户想要写入的数据输出到文件中，即用户是主动，文件是被动，被输出的，所以叫输出流对象。

```c++
ofstream outFile("data.txt"); // 默认以覆盖方式打开文件
// 如果希望以追加数据而不是覆盖数据的形式打开文件
// ofstream outFile("data.txt",ios_base:app);
if (!outFile){
    cerr <<"failed to open file!"; // 提示失败
}
else {
    outFile<<"hello world"<<endl; // 写入数据会覆盖以前对的数据
}
```

#### 1.8.2 输入流ifstream

输入流的对象，是指文件打开以后，把文件的数据输入到用户(的终端)，即用户是被动，文件是主动输入对的，故叫输入流对象。

```c++
ifstream inFile("data.txt");
if (!inFile){
    cerr <<"failed to open file!"; // 提示失败
}
string name;
while (inFile >> name){ // 循环读取文件的每1行内容直到文件末,读到结尾符就为false
    if (name == user_name){
        cout<<"name is exists"<<endl;
    }
}
```

如果希望同时能够读写文件，且是追加模式写入，可以如下所示。

追加模式打开文档，文件光标的定位在文件末尾，所以可以用seekg重新定位到开头。

```c++
fstream ioFile("data.txt", ios_base::in | ios_base :: app);
if (!ioFile){
    cerr <<"failed to open file!";
}
else {
    ioFile.seekg(0); // 把文件重新定位到起始处
}
```

### 1.9 cerr和cout的区别？

cerr代表标准错误设备(standard error)，和cout一样可以将输出结果定向到用户终端。唯一i的差别是cerr对的输出结果没有缓冲情形，会立即显示于用户终端。

## 二、面向过程的编程风格

### 2.1 如何编写函数？

函数需要4个部分，返回类型、函数名、参数列表和函数体。其中返回类型、函数名、参数列表又构成了函数原型，它可以在编译阶段让机器明白这个函数有多少参数，输入和返回类型是否正确等。

一个函数可能因为输入的数字返回错误的结果，例如某些数列不存在第0个位置，这样需要对参数设置一些控制。当参数不满足条件时可以抛出异常，也可以使用exit()函数终止，必须传1个值给exit，这个值是程序结束时的状态值，exit()函数在< stdlib.h>库中。

### 2.2 某个数据类型的最小最大值

一个函数的参数很可能超过该数据类型的限制，可以引入头文件< limits>查找。

```c++
#include <limits>
int max_int = numeric_limits<int>::max();
double min_dbl = numeric_limits<double>::min();
```

 ### 2.3 调用函数程序的行为?

调用1个函数时弧在内存中建立起一块特殊区域，称为"程序堆栈"，这块区域提供了每个函数参数需要的储存空间，它也提供了函数内部所定义的每个对象的内存空间，这些对象称为局部对象，一旦函数完成这个内存会被释放掉，即从程序堆栈中被pop出来。

### 2.4 引用传递

引用传递的定义如下。

```c++
int a = 1;
int *pa = &a; // 指针
int &ra = a; // 引用
```

引用必须从一而终，不能更改引用新对象。

```c++
int b = 2;
ra = b ; // 这样写的含义不是改变ra为引用b,而是把b的值给了ra的引用对象a

// 同理
pa = &ra; // 把ra的引用对象a的地址给了pa
```

引用可以真实的交换2个函数传入的对象，而不是复制一份再交换。

```c++
void swap(int & val1, int & val2){
    int t = val1;
    val1 = val2 ;
    val2 = t ;
}
void display(const vector<int> &vec){
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
```

### 2.5 地址传递

效率和引用传递是一样的，区别在于传入的是变量的地址。但是地址可能不指向某个实际对象，所以一定要确定其地址是否为0，至于引用必定是1个对象。

所以如果是传递内置数据类型，使用引用传递最好，地址传递主要是为了传递类对象。 

```c++
void display(const vector<int> *vec){
    if (!vec){
        cout<<"the vector pointer is 0\n"; //先判断不为空
        return ;
    }
    for(int i = 0;i<vec->size();i++){
        cout<<(*vec)[i]<<" ";
    }
    cout<<endl;
}
```

### 2.6 动态内存管理

使用new和delete动态分配内存，new的对象是从内存空闲区或者说堆内存分配来的，这样分配来的默认是没有经过初始化的。

```c++
int * pi;
pi = new int ; //不初始化

int * pa = new int (4); // 初始化

int * pb = new int [4] ;//数组

delete pi;
delete pa;
delete [] pb;
```

 ### 2.7 提供默认参数值

默认参数值只能提供1次，可以在函数原型也可以在函数的实现处。 

例如display函数可以改写为：

```c++
void display(const vector<int> &vec, ostream &os = cout){
    for(int i = 0; i <vec.size();i++)
        os<<vec[i]<<" ";
    os<<"\n";
}
```

          ### 使用局部静态对象

使用局部静态对象的目的是，多次复用1个变量，节省因为赋值和拷贝占据的内存和花费时间。

不同于普通局部变量，静态对象不会在函数结束后被销毁，所以可以返回这个静态变量的地址，因为static变量一经定义，地址不会发生变化。

例如一个计算斐波那契数列的函数fibon_seq()，通过给定要计算到的位置loc，来返回这个数列。

```c++
vector<int> fibon_seq(int loc){
    const int maxLoc = 1024; // 数列的第10024个元素大小超过了int所能表示的最大值
    if (loc<=0 || loc >= maxLoc)
    {
        cerr<<"the loc > 1024 is not supported -- resetting to 8\n";
        loc = 8;
    }
    vector<int> ans(loc);
    for(int i =0;i<loc;i++){
        if (i == 0 || i== 1)
            ans[i] = 1;
        else ans[i] = ans[i-1]+ans[i-2];      
    }
    return ans; // 局部对象只能值传递拷贝,不能传递地址
}
```

 这样的函数如果反复调用，会造成很多不必要的重复计算，完全可以在第1次计算时存储起来，后边的2次计算只需要返回实际值即可。故将fibon_seq函数改写如下：

```c++
const vector<int>* fibon_seq(int loc) {
    const int maxLoc = 1024;
    static vector<int> ans; // 只会在首次调用初始化,之后不会
    cout << "ans addr is " << &ans << endl;
    if (loc <= 0 || loc >= maxLoc)
    {
        cerr << "the loc > 1024 or <0 is not supported -- resetting to 8\n";
        return nullptr;
    }
    for (int i = ans.size(); i < loc; i++) { //如果想计算的loc<an.size()就不必再计算
        if (i == 0 || i == 1)
            ans.push_back(1);
        else ans.push_back(ans[i - 1] + ans[i - 2]);
    }
    return &ans;
}
```

测试代码：

```c++
// 普通局部变量值传递
auto ans1 = fibon_seq1(20);
for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
    if ((i + 1) % 5 == 0)
        cout << "\n";
}

// 静态局部变量地址返回
const vector<int>* ans2 = fibon_seq2(20);
for (int i = 0; i < ans2->size(); i++) {
    cout << (*ans2)[i] << " ";
    if ((i + 1) % 5 == 0)
        cout << "\n";
}
cout << "ans2 addr is " << ans2 << endl; // 地址没变
ans2 = fibon_seq2(10);
for (int i = 0; i < ans2->size(); i++) {
    cout << (*ans2)[i] << " ";
    if ((i + 1) % 5 == 0)
        cout << "\n"; //打印的话依然是20个
}
cout << "ans2 addr is " << ans2 << endl; // 地址没变
ans2 = fibon_seq2(40);
for (int i = 0; i < ans2->size(); i++) {
    cout << (*ans2)[i] << " ";
    if ((i + 1) % 5 == 0)
        cout << "\n"; //变成40个
}
cout << "ans2 addr is " << ans2 << endl; // 地址没变
```

### 2.8 使用inline函数

一个函数可以拆成多个独立的小函数，这样可以增加函数的可读性和复用性。但是想实现一个功能从调用1个函数变成调用3个函数才能实现，这成了一个缺点。

这样的缺点可以使用inline解决，如果函数A调用了2个函数B、C，A声明为inline以后，**编译器就会将函数的调用操作改为一份函数代码副本**，这可以让性能得到一些改善，但是这适用于B、C的函数代码比较简单，否则不一定可以改善性能。

另外inline只是像编译器申请而不是强制性的，inline函数的定义一般放在头文件中，且定义必须是有效的，因为编译器必须在函数被调用的时候加以展开。

### 2.9 使用重载函数       

只需要知道，同名函数可以以参数列表的个数或者参数类型不同来重载，但不能以返回类型重载。

### 2.10 使用模板函数

如果重载函数的参数个数、名称和参数相对位置没有变化，且函数主体的代码没有变化，只有参数的类型不同时就可以使用模板来替代重载，关键字为class或者typename。模板函数还可以进一步重载，如vector改为list也是可以的。                                                                                                                    

```c++
template<typename T>
void print_message(const string &msg, vector<T> &vec);

template<typename T>
void print_message(const string &msg, list<T> &vec);
```

模板函数出现的目的是：如果一个函数需要被不同的函数调用，例如这个函数的功能是打印一段信息，不同的函数可能打印的信息数据类型不同，那这个函数需要用不同类型的参数声明。

如果那些调用它的函数具备的参数形式相似，这个输出信息的函数可能只需要函数模板就可以解决。例如函数A、B、C的参数只有1个且分别为int、double和string，那么输出函数为模板函数就可以同时为A、B、C函数使用，减少代码的重复性。

### 2.11 函数指针的妙用

函数指针出现的目的正好与模板函数不同：可能一个函数需要多次调用，内部每次调用不同的函数，其它的代码都是相同的，那么可以把这个函数增加一个函数指针类型的参数，这样可以根据不同的函数来执行本函数。

例如，打印函数和打印5种信息的函数，但是这5种信息的参数列表和返回类型是一致的，例如参数类型为int，返回类型为const vector< int > *，就可以让打印函数多一个函数指针参数。

函数指针，需要具备的形式是指定这个函数应该具备的参数列表和返回类型，同时又看起来像个指针，还需要一个单独的星号 * ，所以看起来可以写成下方所示。

```c++
const vector<int>* *getPrintMessageMethod(string);
```

但是很明显，由于优先级的原因，编译器只会把这样的函数看成是输入int，返回const vector< int> * * 类型的指针，是一个指针的指针，所以可以加入小括号来指定print_message是1个函数指针而不是一个普通函数，定义修改如下。

```c++
const vector<int>* (*getPrintMessageMethod)(string);
```

函数指针作为函数参数时，也可以初始化为0，表明不指向任何函数。

```c++
const vector<int>* (*getPrintMessageMethod)(string) = 0;
```

然后再定义一个打印信息print_message的函数，它的参数就是函数指针。

```c++
void print_message(string & msg,const vector * (*getPrintMessageMethod)(string)= 0){
    if (! getPrintMessageMethod){
        cerr <<"you should give an function to implement\n";
        return;
    }
	const vector * ans = getPrintMessageMethod(msg);
    ....
}
```

主程序使用这个print_message函数时，可以事先把所有函数的地址存放到函数指针数组，就可以对这个数组遍历，来调用print_message函数。

现在给出一个例子，来展示如何使用使用函数指针。定义这个print_message函数，和它会调用的三个函数，打印的方式会有所不同。

```c++
void print_message(const string& msg, void (*getPrintMessageMethod) (const string&)) {
	getPrintMessageMethod(msg);
}
void display_with_hello(const string& msg) {
	cout << "hello :  msg => " << msg << endl;
}
void display_with_world(const string& msg) {
	cout << "world :  msg => " << msg << endl;
}
void display_with_hello_world(const string& msg) {
	cout << "hello world :  msg => " << msg << endl;
}
```

主程序，可以直接指定print_message使用哪个函数调用，但显而易见借助数组更好，这样可以直接遍历3个函数，函数指针的数组和调用过程如下。

```c++
void (*funcs[]) (const string&) = { display_with_hello,
                                   display_with_world,display_with_hello_world };
for (int i = 0; i < 3; ++i) {
    print_message("chenbei", funcs[i]);
}
```

还可以定义枚举变量，这样无需记住索引值就可以调用某个函数，内部是按照0,1,2访问的，这样也可以借助数组去使用某个函数。

```c++
enum PrintMessageMethod{hello,world,hello_world};
print_message("chenbei", funcs[hello_world]);
```

### 2.12 设定头文件

调用1个函数需要先声明它，如果很多文件都需要调用这个函数，那么就要需要多次声明，虽然说声明可以很多次，但是为了提高可维护性，将所有函数的声明放在一个头文件即可，这样只需要维护一份声明。

与函数的定义不同，函数的定义只能存在一次，所以放入头文件的话可能其他文件都会调用这个头文件的函数造成多重定义，所以函数的定义应当放在另一个文件中。

不过函数的定义可以有2个例外，一个是inline函数的定义可以放在头文件，另一个是const类型的常量定义也可以放在头文件。

为了能够拓展inline函数的内容，每个调用点上编译器都要取得其定义，所以inline函数的定义必须放在头文件中，而不是把它放在各个不同的程序代码文件中；

const常量能够放在头文件是为了某些常量数组能够被不同代码文件方便的调用；

但是普通变量的定义不可以放在头文件，为了表示它是一个声明，需要加关键字extern使用。

```c++
// 某头文件a.h
// const int knn ; // 不允许，必须初始化
const int knn = 6;
// int knp = 6;// 不允许
extern int knp ; // 允许
// extern int kpp = 6;  // 不允许
const int vec[3] = { 1,2,3 };// 允许
```

头文件可以使用双引号和尖括号，区别是如果头文件包含的函数定义与函数的实现在同一目录下就使用双引号，否则可能是在其它磁盘目录下，一般是IDE的安装目录下会包含编译器必要的头文件，如标准库文件。

### 2.13 extern变量的使用

分3个情况来说明：

外部变量在本文件定义：该全局变量的作用域从变量的定义开始到文件末尾，如果在定义之前有函数引用了这个全局变量，就会报未定义标识符的错误，所以可在调用之前先声明这个变量为外部的，那么编译器就会优先从本文件去寻找，如果没找到，会在同一目录下的文件寻找。全局函数和全局变量的含义类似，如果在调用前没有声明过也会报错，同样可以使用extern+函数原型的办法去声明，本文件找不到就去其他文件寻找。

外部变量在其他文件定义：假如A文件定义了全局变量a=10，在B文件声明a为外部变量后，打印a的值就是10，因为B优先从B文件寻找没找到就会从其它文件寻找，在A文件可以找到。但是B文件不能再次定义a=5，无论在B文件的哪个位置定义，记住定义只能有一次。

外部变量在头文件定义：唯一的区别是，因为头文件可以被多次包含，这个外部变量可以在任何文件中被首次定义，但是一经定义，其他文件不能够再定义，只能够使用。所以如果非必要，不是常量表达式/数组的话不要在头文件中定义全局变量/外部变量。

## 三、泛型编程风格

标准库STL由两部分组成，一个是容器container，包括顺序性容器vector和list和关联性容器set、map等，一个是算法，包括find、sort、replace和merge等通用算法。

map是key/value组合，也可以叫字典、哈希表等；set是只有关键字，且不重复，也可以用于查询。

### 3.1 指针的算术运算

 问题：给定vector或者array，查找指定的元素值并返回它的地址。

#### 3.1.1 容器元素泛型

如果vector是一个整型的，那么这样的代码很容易实现。

```c++
int * find(const vector<int>&vec, int val){
    for(int i =0;i<vec.size();i++){
        if (vec[i] == val)
            return &vec[i];
    }
    return 0;
}
```

现在为了这个算法的通用性，引人容器的元素泛型，这样可以查找任何数据类型的元素，前提是重载过这样的数据类型操作运算符"=="。代码如下，使之更通用。

```c++
template<typename T>
T * find(const vector<T>&vec, const T& val){
    for(int i =0;i<vec.size();i++){
        if (vec[i] == val)
            return &vec[i];
    }
    return 0;
}
```

#### 3.1.2 连续容器类型泛型

上边的问题解决了容器元素可以是任何类型的，但是不同的容器可就需要重载函数。因为find函数的参数列表要求是vector类型，如果是arrray类型就得重载。

这就要求find函数的参数能够剥离array和vector的限制，参数不要写死类型，它本身也是个泛型。

所以可以引入T类型的容器指针，同时还需要告诉传入的数组大小，改写函数如下。声明为const指针是要求指针操作不能改变原有数组的元素。

```c++
template<typename T>
T * find(const T*array,int size, const T& val){
    if (!arrray || size < 1)
        return 0;
    for(int i =0;i<size;i++){
        if (array[i] == val)
            return &array[i];
    }
    return 0;
}
```

也可以不指定size和array，完全剥离出array的属性，而是传入2个指针first和last分别指向array首元素和尾元素的后1位，只要不对指针进行读写操作就是安全的，所以也用const限定。

```c++
template<typename T>
T * find(const T*first,const T * last, const T& val){
    if (!first || ！last)
        return 0;
    for(; first!=last; first++){
        if (*first == val)
            return first;
    }
    return 0;
}
```

#### 3.1.3 连续容器首尾指针泛型

上述find函数还有个问题如果find函数传入的first指针可能是空的，对用户来说操作的是vector或array的实体而不是地址，所以用户定义一个指向实体的指针后总是需要自己先判断不为空，所以为了能够抽离出这部分代码逻辑，引入begin和end函数。这2个函数可以返回实体的首尾指针。

```c++
template<typename T>
inline T * begin(const vector<T> &vec){
    return vec.empty() ? 0 : &vec[0];
}
template<typename T>
inline T * end(const vector<T> &vec){
    return vec.empty() ? 0 : &vec[0]+vec.size();
}
```

#### 3.1.4 非连续容器类型泛型

线性容器很容易找到首尾指针，是因为内存是一段连续的地址，如果是链表，例如list容器，又该如何更改find函数呢？链表是不连续的，还有关联容器map和set，不仅非连续也不是线性的。这就需要引入泛型指针iterator的概念，也就是迭代器。

### 3.2 泛型指针Iterator

要知道，在获取首尾元素指针这点上，list和vector、array没有区别，只是对指针的操作有所不同，所以可以再加一层抽象，begin和end函数不直接对指针操作，而是再加一个抽象层，这个抽象层包含了底层指针的操作，而begin和end只是调用抽象层得到即可。                                                                                                                                                                                                                                                                                                                                                                                                                                

那么begin和end 的共性是什么？它两都可以看作是一种指针，只是指向首尾元素，对上边的函数来说是指向vector的一种指针，那么如果泛型，不就可以让这种指针也是指向list类型的指针了？而且这种指针泛型不仅可以指向首尾元素，且可以指向任意位置的元素。

即Iterator的目标是实现一个可以指向任意数据类型的指针，这个指针的内部要实现对运算符的重载，如++、--，!=和==，解引用 * ，告诉指针这样操作怎么实现。

iterator需要知道的信息是，它在迭代哪个容器？vector还是list？它迭代的容器类型是谁？int、float还是string？

一个可能的解法是，定义使用模板指定2个类型，也就是

```c++
template<T1,T2>
class iterator{
    
};

// 实例化
iterator<string,int> iter;
```

  但是STL不是这样做的，它是在某个容器类内部再定义iterator类型，这样做比较高校，可以直接利用到容器类的T类型以及相关的属性。是的，每个容器类都是这么做的，内部会定义iterator类，实例化方法类似于

```c++
vector<string>::iterator iter=svec.begin();
```

  现在find函数可以改为如下。

```c++
template<typename T1, typename T2>
T1 find(T1 first,T2 last, const T2 & val){
    for(; first!=last;first++){
        if (val == *first)
            return first;
    }
    return last; // 没找到就返回尾指针
}
```

   现在无论是list还是vector、array都可以使用find函数。

```c++
const int size = 5;
int a[size] ={1,2,3,4,5} ;
vector<int> b(a,a+size); // 1种构造
list<int> c(a,a+size); // 1种构造

int * pa = find(a,a+size,3); // T1是int类型,T2也是int类型
if (pa != a+size){
    // 找到该元素
}

vector<int>::iterator pb; // T1是vector<int>类型,T2是int类型
pb = find(b.begin(),b.end(),3);
if (pb != b.end()){
    // 找到该元素
}

list<int>::iterator pc; // T1是list<int>类型,T2是int类型
pc = find(c.begin(),c.end(),3);
if (pc != c.end()){
    // 找到该元素
}
```

 #### 3.2.1 泛型指针的运算符操作泛型

现在有了泛型指针，find函数的通用性非常高。还需要考虑指针的运算符重载操作，运算符重载可以默认使用STL内部给出的方式，也可以让用户传入自己定义的运算方式，所以这个问题如果能解决泛型的问题，find函数通用性会大大增加，这将在第四章说明。STL提供的find_if函数能够接收函数指针或者函数对象来取代底部元素的==/!=运算符。

### 3.3 容器的共通操作

先介绍容器的共通操作，再介绍各个容器自己独有的操作，第四章再回过头讲泛型。

通用操作，实际上定义在抽象类，也就是empty、size、clear，insert、erase等函数，赋值运算符=，关系运算符!=和==，同时每个容器类都提供begin()和end()迭代器。

不过insert和erase在顺序性和关联性容器的实现上略有不同。

### 3.4 使用顺序性容器

#### 3.4.1 vector容器

删除和插入操作效率低，因为需要覆盖操作，尾删和尾插效率尚可。随机访问元素效率很高，因为只需要做一次指针运算即可。

#### 3.4.2 list容器

双端链表，删除和插入的效率高，因为每个元素都有三个字段，front、back和value，即指向前后元素的指针以及真正的数据value。插入和删除操作只需要衔接好或者断开节点的指针和前后节点的指针即可。

#### 3.4.3 queue容器

单端队列，先进先出的数据结构，可以删除和获取队首元素，插入到队尾元素。但是获取中间的元素效率比较低，需要迭代器。

#### 3.4.4 deque容器

双端队列，可以头插，也可以尾删，那么deque的效率很高。

#### 3.4.5 常用构造函数

产生特定大小的容器，指定size

```c++
vector<int> a(32);
```

产生特定大小的容器，指定size和初值

```c++
vector<string> b(32,"123");
```

通过一对指针产生容器

```c++
int a[4]={1,2,3,4};
vector<int> vec(a,a+4);
```

通过某个容器产生容器(复制构造)

```c++
list<string> s1;
list<string> s2(s1);
```

#### 3.4.6 常用函数

vector有push_back和pop_back函数，用于尾插和尾删。

list和deque还有头插和头删，push_front和pop_front函数。

读取首尾元素可以使用front()和back()

insert函数有以下几个重载。

```c++
iterator insert(iterator position); // 指定位置前插入默认值
iterator insert(iterator position,elemType val); // 指定位置插入val
void insert(iterator position,int count,elemType val);//在指定位置之前插入n个val
void insert(iterator position,iterator first,iterator last);//在指定位置之前插入[first,last)的各个元素
```

erase函数有以下几个重载。

```c++
iterator erase(iterator position); // 删除指定位置元素
void erase(iterator first,iterator last);// 删除[first,last)范围的元素                 
```

### 3.5 使用泛型算法

find函数，搜索无序集合是否存在指定元素，找到目标返回指向目标的迭代器，否则返回end()；

binary_search函数，用于有序集合搜索，找到目标返回true否则false，比find更有效率；

count函数，返回指定元素的数目；

search函数，比对某个容器是否存在某个子序列，找到则会返回一个指向子序列首位的迭代器，否则返回end()；

max_element函数，将容器的begin和end传入，会返回最大值的指针，解引用即可得到最大值；

copy函数：指定容器的begin和end，另一个容器的begin，就可以复制过去；

sort函数：传入begin和end，就可以进行排序(升序)。

transform函数：传递5个参数，2个迭代器指明想要转换的元素范围，指定要转换的元素迭代器，指定要存放转换后元素存放位置的迭代器，以及想要执行的转换操作，例如使用后面的function object的函数。

使用find函数找到数组内指定元素的个数，以下程序可以不查看同一个元素两次以上找到指定元素的个数。

find如果能找到这个值val，就会返回指向val的迭代器，它肯定不是end()，所以会继续寻找。直到再也找不到，就会返回end()，此时while也就退出，记录的c就是val出现的次数。

```c++
int count(const vector<int> &nums, int val){
    vector<int>::const_iterator iter = vec.begin(); //常量指针,指针所指物不可更改
    int c = 0;
    while ((iter = find(iter,nums.end(),val)) != nums.end()){
        ++c;
        ++iter;//指针指向的地址可以移动
    }
    return c;
}
```

### 3.6 设计一个泛型算法

  假如想要实现一个数组中找到所有小于10的数，一个快速但是缺乏弹性的写法如下。

```c++
vector<int> less_than_10(const vector<int> &nums){
    vector<int> ans;
    for (auto num:nums){
        if(num<10)
            ans.push_back(num);
    }
    return ans;
}
```

  更好的版本是，可以指定小于的值，所以可增加1个参数val，如下。

```c++
vector<int> less_than(const vector<int> &nums,int val){
    vector<int> ans;
    for (auto num:nums){
        if(num<val)
            ans.push_back(num);
    }
    return ans;
}
```

 现在还希望不止能够实现小于val，也能实现其他比较操作，例如大于，等等于，可以引入函数指针参数。函数指针指向的函数具有2个参数，都是int型，返回类型为bool，相应的函数名改为filter。现在就可以根据num和val的关系来决定添加什么样的num。op指向的2个函数可以单写，如less_than和greater_than函数。

```c++
vector<int> filter(const vector<int> &nums,int val,bool (*op)(int,int)){
    vector<int> ans;
    for (auto num:nums){
        if(op(num,val))
            ans.push_back(num);
    }
    return ans;
}
bool less_than(int x, int y){return x<y?true:false;}
bool greater_than(int x, int y){return x>y?true:false;}
// 调用
auto ans = filter(vec,val,less_than);
```

 这个函数还可以继续泛型，例如支持的op函数能够不受参数限制，而是使用自定义的函数规则来实现，把这样一组行为函数来传递给filter函数作为参数。这就需要先引入函数对象的概念，函数对象比函数指针更有效率。

#### 3.6.1 Function Object

函数对象，标准库在< functional> 中预定义了许多函数对象，它们是某种class的实例，因为这些类对操作运算符()进行了重载，所以使得实例具有函数的性质，可以被调用。这些函数可以被一些算法所使用，例如sort或者find_if，当然函数对象也可以自定义实现。

函数对象主要为三大类，算术运算、关系运算和逻辑运算。

6个算术运算：除了加减乘除，modules是取模运算，negate是取相反数运算。

```c++
plus<type>;
minus<type>;
negate<type>;
multiplies<type>;
divides<type>;
modules<type>;
```

  6个关系运算：

```c++
less<type>;
less_equal<type>;
greater<type>;
greater_equal<type>;
equal_to<type>;
not_equal_to<type>;
```

  3个逻辑运算：

```c++
logical_and<type>;
logical_or<type>;
logical_not<type>;
```

举例，sort函数默认是升序操作，如果希望降序操作，就可以使用greater< type >，记得要加括号，因为是函数对象，加括号才表示调用。

```c++
sort(vec.begin(),vec.end(),greater(int)());
```

如果自定义升序，也可以实现。

```c++
template<typename T>
class greater{
	public:
		bool operator()(T v1,T v2){
            return v1>v2;
        }
};
sort(vec.begin(),vec.end(),greater());//升序
```

再如使用find_if函数，定义一个找到<10元素的函数怎么写呢？

首先定义一个类，重载()运算符。

```c++
template<class T>
class lessthan_ten{
    public:
    	bool operator()(T val){
            return val<10;
        }
};
```

那么就可以把这个类的实例作为函数对象传递给find_if函数。

```c++
auto iter = find_if(vec.begin(),vec.end(),lessthan_ten());
```

最后1个例子，使用transform函数对数组的某个元素进行操作，例如该元素和自身相加或者相乘。这里相当于是把容器vec的第2个元素和自己相加转换到ans.begin()上。

```c++
transform<vec.begin(),vec.end(),vec.begin()+1,ans.begin(),plus<int>()>;
```

#### 3.6.2 Function Object Adapter

##### 3.6.2.1 bind1st and bind2nd

上述find_if的例子，find_if要求传入的是个一元运算符，所以重载的函数对象可以带入找到小于10的元素。现在如果希望利用标准库已有的操作，例如less，它显然是个二元操作符，如何将其转为一元运算符可以为find_if函数使用呢？答案是STL标准库的函数对象适配器，主要是2个函数，一个是bind1st，另一个是bind2nd，分别可以把指定值绑定到函数对象的第1或者第2操作数。

例如less，原本是如果前1个元素小于后1个元素就返回true，现在将指定值val绑定到less的第2个参数，就可以实现如果元素小于val就返回true。

```c++
bind2nd(less<int>,val);
```

现在回过头来看filter函数，将其重写如下。改动在于不是返回计数，而是返回满足条件的元素，存放在一个数组。将less第2操作数绑定后，就可以实现当nums的元素小于val就返回不是end的迭代器，那么就把这个元素加入答案，while继续运行，如果找不到了就会返回end，终止运行。

```c++
vector<int> filter(const vector<int>&nums,int val, less<int> &op){
    vector<int> ans;
    vector<int> :: const_iterator iter = nums.begin();
    while ((iter = find_if(iter,nums.end(),
                          bind2nd(op,val))) != nums.end()){
        ans.push_back(*iter);
        iter++;
    }
    return ans;
}
```

 现在的函数，还受限于val只能是int类型，同时也受限于数组是vector类型，返回也是vector类型 。

将其继续泛型化，可以引入函数模板，声明4个类型，输入迭代器、输出迭代器、元素类型，函数对象类型。

```c++
template <typename InputIterator,typename OutputIterator,
		typename ElemType,typename Comp>
OutputIterator filter(InputIterator first, InputIterator last,
                     OutputIterator at, const ElemType &val, Comp op)
{
   while ((first = find_if(first,last,bind2nd(op,val))) != last){
       *at++ = *first++;
   }
   return at;
}
// 现在可以进行的调用
const int size=8;
int a[size]={44,22,3,13,8,2,91,-2};
vector<int>b(a,a+size);
int ra[size];
vector<int> rb(size);
filter(a,a+size,ra,size,less<int>());
filter(b.begin(),b.end(),rb.begin(),size,less<int>());
```

  输出迭代器的at参数指定的是要存放的位置at存放符合条件的first，然后2个指针都前进。     

 ##### 3.6.2.2 not1 and not2

这2个适配器函数是另一种适配器。 not1是针对一元运算符的，unary function object，也就是比较运算、逻辑非运算和算术运算的取反，not2是针对二进制函数对象进行取反，也就是binary function object。

例如，要找到所有大于等于10的元素，可以将函数对象less< int >()的结果取反，

```c++
while ((iter = find_if(iter,vec.end(),not1(bind2nd(less<int>,10))))!= vec.end())
```

 bind2nd绑定后返回的对象也是函数对象，也可以作为not1函数的参数。  

当然，解决问题的方法有很多，不一定这样使用find_if，也可以使用vec的副本排好序后，找到第1个大于指定值的元素位置，再删除该位置后的所有元素，返回该副本即可。

```c++
vector<int> sub_vec(const vector<int> &vec, int val){
    vector<int> ans(vec);
    sort(ans.begin(),ans.end());//升序
    vector<int>::iterator iter = 
        find_if(ans.begin(),ans.end(),bind2nd(greater<int>(),val));//找到大于val第1个值
    ans.erase(iter,ans.end()); // 返回的迭代器到end之间被删除
    return ans;
}
```

设计泛型算法的思路如下：

首先写了一个函数，找出vector内小于10的所有元素，不过函数比较死板，没有弹性；

然后给函数加了一个参数，这个参数可以和vector的元素作比较，以此可以返回大于10，等于10之类的元素；

继续泛型，加入新参数op，也就是函数指针，可以让用户自定义一些函数来指定比较的方式；

紧接着引入function object的概念，它比函数指针更有效率，可以将一组行为用类对函数调用符号()进行重载，使之具有函数的性质，可以替代函数指针作为函数的参数；

最后，这样的函数再以函数模板的方式实现，为了支持多种容器，将输入和输出使用泛型指针代替，为了支持容器元素的不同类型，也对指定的元素类型使用模板，最后函数对象也可参数化，可以同时支持函数指针和函数对象。

现在这个函数于元素类型、依赖的容器类型、函数指针/函数对象类型都无关，是一个真正的泛型算法。                                                                                                                                                                                                                         

### 3.7 使用关联性容器

 #### 3.7.1 使用map

map被定义为一对pair数值，输入key时，如果它不存在于map就会自动加入并给定默认初值0。

```c++
map<string,int> words;
words["chenbei"] = 1;
```

遍历map的方法，使用迭代器。

```c++
map<string,int> ::iterator it = words.begin();
for(; it!= words.end();it++){
    cout<<"key = "<<it->first<<" val = "<<it->second<<endl;
}
```

  查询key有3种方法。

第一种是把key当成索引使用，查询即可。

```c++
if ((!words["chenbei"] = 0)){ // 说明chenbei不存在于map
    ... // 这种写法的缺点是查询完,wordds就把这个key加进去了
}    
```

第二种可以利用map的find函数，如果找到会返回这个key和val的迭代器，没找到就会返回end。

```c++
map<string,int> ::iterator it = words.find("chenbei");
if (it != words.end()){
    cout<<it->second<<endl;
}
```

第三种利用count函数，不过key的val至多1份，所以count只是返回0或1，返回0说明不存在。

```c++
if (words.count("chenbei"))
	cout<<words["chenbei"]<<endl;
```

  如果需要key存储多份值，需要使用multimap。

#### 3.7.2 使用set

 set只有key，且key只能存储1份，需要存储多份就使用multiset。 set也有count函数，可以用于判断key是否存在于集合，同样返回0或1。

集合可以用来去重，默认集合内部元素的排列是升序，可以借助容器vector数组来构造。

```c++
int a[6]={2,1,2,3,6,4};
vector<int> v(a,a+6);
set<int> s(v.begin(),v.end());
```

 遍历的方式也是使用迭代器，输出的结果是1、2、3、4、6。

```c++
set<int> :: iterator it = s.begin();
for(; it!=s.end();it++){
	cout<<*it<<endl;
}
```

 集合插入元素，可以插入单元素，也可以插入批量元素。

```c++
s.insert(10);
vector<int> vv={9,10};
s.insert(vv.begin(),vv.end());
```

 其它和set有关的算法有：

```c++
set_intersection();
set_union();
set_difference();
set_symmetric_difference();
```

 ### 3.8 使用Iterator Inserter

回过头看之前的filter函数以及测试程序。

```c++
template <typename InputIterator,typename OutputIterator,
		typename ElemType,typename Comp>
OutputIterator filter(InputIterator first, InputIterator last,
                     OutputIterator at, const ElemType &val, Comp op)
{
   while ((first = find_if(first,last,bind2nd(op,val))) != last){
       *at++ = *first++;
   }
   return at;
}
// 现在可以进行的调用
const int size=8;
int a[size]={44,22,3,13,8,2,91,-2};
vector<int>b(a,a+size);
int ra[size];
vector<int> rb(size);//目标容器必须指定容器大小
filter(a,a+size,ra,size,less<int>());
filter(b.begin(),b.end(),rb.begin(),size,less<int>());
```

注意到，目标容器要实现指定容器的大小，因为filter函数无法知道at++之后的位置是否有效，因为这调用的是assign(赋值)运算符。

现在在头文件< iterator >中定义了插入适应器，也就是Iterator adapter。

有3个函数。

第1个是back_inserter函数，传入的参数就是容器，可以以push_back的形式来给目标容器插入元素，自适应拓展容量而无需事先指定容器大小，具有更好的灵活性，此函数适用于尾插，效率较高。

```c++
vector<int> res; // 未指定容器大小
unique_copy(b.begin(),b.end(),back_inserter(res));//赋值操作可以自动尾插
```

第2个函数是inserter()会以容器的insert函数代替assign运算符，接收2个参数，一个是目标容器，一个是迭代器，执行容器内插入操作起点，例如可以指定end()，表示在这之前插入，也就是相当于尾插   。

```c++
vector<int> res; // 未指定容器大小
unique_copy(b.begin(),b.end(),inserter(res,res.end()));//赋值操作可以自动插入指定位置之前
```

第3个函数是front_inserter()，只适用于list或者deque，也就是头插，会使用容器的push_frnt函数来代替assign函数。

```c++
list<int> res; // 未指定容器大小
copy(b.begin(),b.end(),front_inserter(res);//自动头插
```

不过这些函数要注意只适合特定容器，而纯粹的array不支持任何插入操作，所以使用filter函数时有所区别。

```c++
const int size=8;
int a[size]={44,22,3,13,8,2,91,-2};
vector<int>b(a,a+size);
int ra[size]; // array类型必须指定大小
vector<int> rb;//目标容器无需指定容器大小
filter(a,a+size,ra,size,less<int>());// array类型依然只能如此
filter(b.begin(),b.end(),
       back_inserter(rb),size,less<int>());//现在可以借助Inserter adapter
```

### 3.9 使用iostream Iterator

 输入输出流迭代器就是依据插入迭代器实现的。如果需要终端读取一些字符串和输出一些字符串，可能需要先指定容器，然后反复push_back输入的字符串，最后遍历输出字符串。

```c++
string word;
vector<string> text; 
while(cin>>word){
    text.push_back(word);
}
for(int i=0;i<text.size();i++)
    cout<<text[i]<<" ";
cout<<"\n";
```

 这样的方法略显笨拙，可以借助  iostream Iterator，包含在头文件 < iteratorr>中。有2个迭代器类，一个是istream_iterator，另一个是ostream_iterator ，可以将其分别绑定到cin和cout，就可以输出。

```c++
istream_iterator<string> st(cin);
istream_iterator<string> eof;//默认指向要读取的最后一个元素的下一个位置

vector<string> text;//可不指定size
copy(st,eof,back_inserter(text)); // 把终端的输入以尾插形式存入text

ostream_iterator<string> os(cout," ");//绑定到输出流对象cout,第2个参数是分隔符,默认不分隔
copy(text.begin(),text.end(),os);// 输出到终端
```

如果希望是读取文件，存入文件 ，可以把cin和cout替换成输入输出流对象。                                                                                                   

```c++
ifstream in_file("1.txt");
ofstream out_file("2.txt");
istream_iterator<string> st(in_file); // 把cin替换
istream_iterator<string> eof;//默认指向要读取的最后一个元素的下一个位置

vector<string> text;//可不指定size
copy(st,eof,back_inserter(text)); // 把终端的输入以尾插形式存入text

ostream_iterator<string> os(out_file," ");//把cout替换
copy(text.begin(),text.end(),os);// 输出到终端
```

## 四、基于对象的编程风格

### 4.1 实现一个Class

由于内容简单，不再给出原书的一些代码，只强调成员函数的inline性质。

对于成员函数来说，如果在类内完成其定义，就会自动视为inline函数，这样类的每个实例对象都包含了这样一份代码，在调用点处可以直接执行代码，所以inline函数只有代码体量小才有意义，这样才会比通过调用函数带来的花销更值得。

如果在类外声明，也想声明为类的inline函数，加上关键字即可。类的声明和inline函数的定义应当包含在头文件中，这样才能保证每处调用inline函数都是相同的。

非inline成员函数一般在程序代码文件cpp中定义。

### 4.2 何为构造函数和析构函数

构造函数分为默认构造函数和copy构造函数。

关于默认构造函数只说明成员列表初始化的问题，类的成员变量可以直接这样的方式初始化。

```C++
class A
{
  public:
    A(int age,string name):_age(age),_name(name){}
  private:
    int _age;
    string _name;
};
```

也可使用在函数括号内，逐一赋值初始化，不过前者更好，未进入构造时就先于初始化。

逐一初始化的方式如下。

```c++
A::A(int age,string name){
    this->_age = age;
    this->_name = name;
}
```

再来看看copy构造函数，默认情况下如果不提供该函数的实现，编译器也会默认提供一个版本，它的实现就是采用逐一初始化这样的方式。

```c++
A::A(const A &rhs)
{
    this->_age = rhs._age;
    this->_name = rhs._name;
}
```

这样的方式对于一般的成员变量没有什么问题，但是如果默认构造函数使用过动态分配内存，例如

```c++
class A
{
  public:
    A(int age,string name)
    {
        this->_age = age;
    	this->_name = name;
        this->_p = new double [this->_age];
    }
    ~A()
    {
        delete [] this->_p; //借助析构函数自动管理/释放堆申请的内存
    }
  private:
    int _age;
    string _name;
    double* _p;
};
```

如果仍然使用编译器提供的copy构造函数，它其实是这么复制的。

```c++
A::A(const A &rhs)
{
    this->_age = rhs._age;
    this->_name = rhs._name;
    this->_p = rhs._p; // 浅拷贝,只是简单的把2个指针指向同一份内存
}
```

在用户的使用视觉来看，因为a1内部的_p指针已经被释放，a2指向的是同1个内存再次释放就会出错。

```c++
A a1(8,"b");
A a2(a1); // 调用编译器提供的copy构造
// a1被释放
// a2被释放就会出现问题
```

对于堆申请内存给指针类型的成员变量，copy的构造函数不能再使用默认的成员逐一初始化，而是应当手动提供深拷贝的操作，将函数实现改写如下。

```c++
A::A(const A &rhs)
{
    this->_age = rhs._age;
    this->_name = rhs._name;
    this->_p = new double [this->_age];//深拷贝
    for (int i=0;i<this->_age;i++)
        this->_p[i]=rhs._p[i]; // 这样去复制每个元素
}
```

### 4.3 何谓mutable(可变)和const(不变)

关于const的作用其实在EffectiveC++的条款03说明过，在这里就再简要叙述一下结论。

第一，如果成员函数声明为const类型，返回的是指针或者引用类型时也必须加const，否则如果返回私有变量的引用，这意味着它可以在类的外部修改，也是不满足const的含义。

第二，成员函数可以由于const常量性不同而发生重载，所以可以声明一个非const对的同名函数，返回值可以是const对的也可以不const，但是不能同时存在，因为重载不能只以返回类型区分；

第三、如果有因const重载的成员函数，调用何种版本取决于类的实例的常量性，const类对象调用const版本的成员函数，non-const的类对象调用non-const成员函数；

第四条，其实就和mutable有关系。如果成员函数被声明为const，它不能改变类的任何成员变量，但是有时候希望成员变量能够被改变，且能在该成员函数内使用，那怎么办呢？可以对成员变量使用mutable修饰，它可以释放掉const对它的约束，这样const成员函数是可以修改mutable成员变量的。

### 4.4 什么是this指针

this指针是用于指向调用者自身的指针，常用于copy操作和copy assignment操作被体现。

this指针可以访问调用者对的一切，如果调用者既是调用者也是接收者，那么应当返回一个this指针。

```c++
class A
{
	public:
    	A& copy(const A& rhs)
        {
            age = rhs.age;// 隐式使用this指针
            name = rhs.name;
            return *this;// 既是调用者也是接收者
        }
    private:
    	int age;
    	string name;
};
```

其实上述代码等价于

```c++
class A
{
	public:
    	A& copy(const A& rhs)
        {
            if (this == &rhs) // 判断是否为自我赋值是个好习惯
                retun *this;
            this->age = rhs.age; // 显式使用this指针
            this->name = rhs.name;
            return *this;// 既是调用者也是接收者
        }
    private:
    	int age;
    	string name;
};
```

### 4.5 静态类成员

#### 4.5.1 静态成员变量

静态类成员分为静态成员变量和静态成员函数。

静态成员变量是同一类的所有对象唯一的、可以共享的成员，类内声明了这个成员变量后，就必须在程序代码cpp文件中给出明确的定义，有点像全局变量的声明，别的cpp文件也想使用这个变量时先是从本文件找，找不到再去别的文件找，无论如何，定义只有一份。

非静态成员函数可以访问静态成员变量，静态成员变量如果是const类型的，还可以在声明时明确指定初值，而且是必须给定初值。

#### 4.5.2 静态成员函数

静态成员函数不能访问非静态成员变量，这样这个函数与任何类的实例对象都毫无瓜葛。

普通成员函数的调用是依赖于this指针的，this指针又绑定在具体的类实例，所以每个类的实例想要调用普通成员函数，其实都是调用它自己携带的普通成员函数成分。

静态成员函数因为不与任何非静态成员变量有瓜葛，也就不和任何类的实例对象有瓜葛，因为静态成员变量是与任何对象无瓜葛的，所以如果使用类的静态成员函数，就可以以作用域的形式来调用。

```c++
class A
{
    ...
    static void printNames();
    private:
    	int age;
    	string name;
    	static vector<int> elems;
};
void A::printNames()// 只要声明给出了static,类外定义不声明static也可以
{
	// cout<<"age = "<<age<<" name = "<<name<<endl; 不可以访问任何非静态成员
    ostream_iterator<int> os(cout," ");
    copy(elems.begin(),elems.end(),os);
    cout<<"\n";
}
// 外部程序使用静态成员函数
A::printName();//无需绑定任何对象可以直接使用
```

### 4.6 类内部打造一个迭代器类

迭代器类要完成的操作主要是：提供==，!=，++(前+后+2个版本)，--(类似2个版本)，以及解引用操作符 * 的运算符重载函数。而被嵌套的类，需要提供指向begin()和end()函数，方便用户使用。++和--的后置版本也就是i++和i--必须跟上int参数，返回值因为是旧的this指针，所以返回的不是引用，前置版本返回的是引用。

迭代器类的大致写法如下，它被定义在类A的内部，用于访问A的静态成员变量elems，A是一个描述数列的类，从数列的指定位置开始访问，位置必须正整数(≥1)，但是内部是用elems存储的，所以它的访问必须是位置-1，也就是实际位置，这里用nextPos描述。A对迭代器的取名可以使用别名，外部用户可以直接使用iterator作为迭代器名称使用。

```c++
class A
{
    public:
    	typedef A_iterator iterator;//起别名,用户无需知道真实名字
    	A(int len,int loc){
            // length 和 pos都必须>=1
            length = len>0?len:1;// 从起始位置开始想要访问数列的长度
            pos = loc>0?loc:1;
            nextPos = pos - 1;//下一个操作元素的真正位置
        }
        A_iterator begin() const // 类A要提供begin和end函数
        {
            return A_iterator(pos); //注意是绑定到数列的位置,所以解引用*重载时要记得-1
        }
    	A_iterator end() const
        {
            return A_iterator(pos+length);
        }
    	//其它A的函数,自动inline
    	int length()const {return length;}//返回数列长度
    	int pos() const {return pos}; // 返回数列要开始访问的位置(从数列的该位置进行访问)
    	int elem(int pos) {return elems[pos-1]}//用户是从pos=1开始使用的
    	void next_reset() const (nextPos = pos-1;)//可以修改mutable变量,重置nextPos
    	bool next(int &val)const{
            //每调用1次next,nextPos要++,通过引用传递将val改变为数列的下1个元
            // 使用next函数之前nextPos要借助next_reset重置为pos-1,nextPos可能已被使用过
            if (nextPos < pos + length -1){ // 指定访问[pos,pos+length-1]的数列元素
                // 对应elems的[pos-1,pos+length-2]
                val = elems[nextPos++];//因为是引用传递,外部传入的val可以改变
                return true; // 能访问下1元素返回true
            }
            return false;//不能返回false
        }
    	int sum(const A& series){ //定义next_reset,next的原因,求数列指定段的元素之和
            if (!series.length()) // series在外部已经给好要求的长度length和起始位置pos
                return 0;
            int val=0,sum=0;
            series.next_reset()
            while (series.next(val)) // 引用传递val依次等于elems[pos-1],..elems[pos]
                sum += val;
            // while结束后nextPos的位置改变了,所以下次还要正确使用sum必须使用next_reset重置
            return sum;
        }
        class A_iterator
    	{
        public:
            A_iterator(int pos):idx(pos-1){};//访问从[0]开始,begin,end给的pos不是实际位置
            bool operator==(const A_iterator&) const; // 重载==
            bool operator!=(const A_iterator&) const; // 重载!=
            A_iterator& operator++(); // ++it版本(前置),it是调用者也是接收者,需返回this指针
            A_iterator operator++(int); //it++版本(后置),返回的只是以前的this版本
            A_iterator& operator++(); // --it
            A_iterator operator++(int);// it--
            // 后置版本必须跟上int参数,这是编译器自动配置的,且值必为0,记住即可
            int operator*() const;// 解引用操作,这里迭代器指向的是int类型
        private:
            void check_integrity() const;//检查迭代器指向是否为int类型
            int idx;//迭代器的指向位置,也就是pos-1,这是elems的实际位置
    	}
        inline bool A_iterator:: operator==(const A_iterator&rhs)const
        {
            return idx == rhs.idx;//指向的元素位置相等就认为迭代相等
        }
    	inline bool A_iterator:: operator!=(const A_iterator&rhs)const
        {
            //return idx != rhs.idx; 一般不这么写了,因为很可能指向的数据类型不同,这也是不同
            return !(*this == rhs); // 比较的是所指内容,用到了*运算符重载
            // 也就是比较elems[idx] != rhs.elems[rhs.idx]
        }
    	inline A_iterator:: int operator*() const // 带作用域A_iterator:: 
        {
            check_integrity(); // this隐式的指针
            return A::elems[idx]; // 静态成员变量可以直接用作用域使用该函数
        }
        inline int operator*(const A_iterator&rhs) const//不带A_iterator::
        {
            // 此函数是重载版本且不作为类的成员函数
            rhs.check_integrity(); // this在rhs内
            return A::elems[idx]; // 共享1份内存
        }
    	inline void A_iterator::check_integrity()const
        {
            if (idx >= A::max_elems)
                throw iterator_overflow(); // 抛出异常
            if (idx >= A::max_elems.size()) // 如果elems暂时没存到这个上界的元素
                A::generate_elements(idx+1);// 就增加elems存储的元素
            // 这2个函数实现不写,知道要做什么就可
        }
    	inline A_iterator& A_iterator::operator++(){
            // ++it版本
            ++idx;//状态先更新
            check_integrity();
            return *this;//返回更新的this
        }
    	inline A_iterator A_iterator::operator++(int)
        {
            // it++版本,表达式还没更新
            A_iterator old = *this;//先记录旧的this
            ++idx;
            check_integrity();
            return old; // 这也是为何返回的不是引用的原因
        }
        inline A_iterator& A_iterator::operator--(){
            // --it版本
            --idx;//状态先更新
            check_integrity();
            return *this;//返回更新的this
        }
    	inline A_iterator A_iterator::operator--(int)
        {
            // it--版本,表达式还没更新
            A_iterator old = *this;//先记录旧的this
            --idx;
            check_integrity();
            return old;// 这也是为何返回的不是引用的原因
        }
    
    private:
    	int pos;//用于访问数列的起始位置(从数列的该位置进行访问),必须>0,数列索引是正整数1开始的
    	mutable int nextPos; // //下一个操作元素的真正位置,可在const成员函数使用
        int length; // 从起始位置开始想要访问数列的长度
    	static const int max_elems = 1024;//数列如果递增的话,elems[max_elems]存储的数可能会超过INT_MAX,1024还在int可以表示的最大范围内
    	static vector<int> elems; // 存储数列是从下标0开始的
}
```

外部用户的使用方式，和容器类对的iterator如出一辙。

```c++
A m(10,3);//length=10,pos=3
A::iterator it = m.begin();
```

### 4.7 合作关系要建立在友谊基础上

