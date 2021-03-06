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
       	// A的友元类和函数
    	friend class A_iterator;//最省事的写法
    
    	friend int operator*(const A_iterator&); // ②让非成员函数版本能访问A的elems
    
    	friend int A_iterator::operator*();//③让A_iterator的成员函数版本能够访问A的elems
    	friend void A_iterator::check_integrity();//④让A_iterator的成员函数版本能够访问A的max_elems
    
        class A_iterator
    	{
        public:
            friend int operator*(const A_iterator &);//①让非成员函数版本能访问 A_iterator的check_integrity()函数
            
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
    
    	// ①成员函数的写法
    	inline A_iterator:: int operator*() const // 带作用域A_iterator:: 
        {
            check_integrity(); // this隐式的指针
            return A::elems[idx]; // 静态成员变量可以直接用作用域使用该函数
        }
    	// ②非成员函数的写法
    	inline int operator*(const A_iterator&rhs) //不带作用域A_iterator::
        {
            // 此函数是重载版本且不作为类的成员函数,它是友元函数
            rhs.check_integrity(); // check_integrity()是A_iterator的私有函数
            return A::elems[idx]; // elems是A的私有成员
            // 所以为了本非成员函数能访问2类私有成员
            // 必须声明本函数为A_iterator的friend且也是A的friend函数
        }
    	
    	inline void A_iterator::check_integrity()const
        {
            if (idx >= A::max_elems)
                throw iterator_overflow(); // 抛出异常
            if (idx >= A::elems.size()) // 如果elems暂时没存到这个上界的元素
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

现在回过头来看看，解引用运算符的2个函数有何区别。

第1个是迭代器类的成员函数，它可以访问迭代器类的私有成员，但是不能访问A类的私有成员。operator * 函数和check_integrity函数都访问了A的私有成员，为了能通过编译，必须让这2个函数作为A的friend函数。

```c++
inline A_iterator:: int operator*() const // 带作用域A_iterator:: 
{
    check_integrity(); // this隐式的指针
    return A::elems[idx]; // 静态成员变量可以直接用作用域使用该函数
}
```

在A的任何地方都可以，给出这2个声明即可。

```c++
class A
{
	public:
        friend int A_iterator::operator*();//③让A_iterator的成员函数版本能够访问A的elems
    	friend void A_iterator::check_integrity();//④让A_iterator的成员函数版本能够访问A的max_elems
    	...
};
```

第2个写法是写成迭代器类的非成员函数，那么它要同时声明为迭代器类和A类的友元函数。

```c++
inline int operator*(const A_iterator&rhs) //不带作用域A_iterator::
{
    // 此函数是重载版本且不作为类的成员函数,它是友元函数
    rhs.check_integrity(); // this在rhs内
    return A::elems[idx]; // 共享1份内存
}
```

因为这个函数既要访问A_iterator的check_integrity()，也要访问A的elems，所以在两个类内都要声明为友元函数才能通过编译，声明如下。

```c++
class A_iterator
{
    public:
    	friend int operator*(const A_iterator &);// ①让非成员函数版本能访问 A_iterator的check_integrity()函数
    	...
};
class A
{
	public:
    	friend int operator*(const A_iterator&); // ②让非成员函数版本能访问A的elems
    	...
};
```

以上第1个个写法是指定迭代器类的特定函数来作为A类的友元函数，第2个写法是纯粹的非成员函数都声明为2个类的友元函数。如果希望迭代器类的所有函数都是A类的友元函数，可以这样写，直接声明迭代器类为A的友元类，就省事的多。

```c++
class A
{
	public:
    	friend class A_iterator;//最省事的写法
    	...
};
```

如果不借助friend函数也不是不能实现，以check_integrity()函数来说明，之所以需要friend无非是因为函数内部访问了私有静态成员max_elems和elems，那么可以在A类的公有方法增加2个用于返回max_elems和elems.size()，而generate_elements是公有方法可以正常调用，通过使用2个公有方法来代替直接放有私有变量elems是个好主意。

```c++
inline void A_iterator::check_integrity()const
{
    if (idx >= A::max_elems)
    throw iterator_overflow(); // 抛出异常
    if (idx >= A::elems.size()) // 如果elems暂时没存到这个上界的元素
    A::generate_elements(idx+1);// 就增加elems存储的元素
    // 这2个函数实现不写,知道要做什么就可
}
```

A类增加2个方法。

```c++
class A
{
	public:
    	static int elems_size(){return elems.size();}//提供读方法
    	static int elems_max(){return max_elems;}//提供读方法
    	// friend void A_iterator::check_integrity();//此友元函数声明不再必要
    	...
};
```

那么check_integrity()函数可以改写如下。

```c++
inline void A_iterator::check_integrity()const
{
    if (idx >= A::elems_max()) // 使用公有方法elems_max()
    throw iterator_overflow();
    if (idx >= A::elems_size()) // 使用公有方法elems_size()
    A::generate_elements(idx+1);// 使用公有方法generate_elements()
}
```

### 4.8 实现一个copy assignment operator

这里其实讨论过，如果不给定copy assignment的实现，默认会成员逐一复制操作。但是注意，如果构造函数申请了堆的内存，析构时要给定相应的回收处理，同时复制要实现深拷贝而不是浅拷贝。深拷贝是也申请一段内存，而不是简单对的复制2个指向同一块内存的指针，免于析构函数重复释放同一份内存。

### 4.9 实现一个function object

在[3.6.1 Function Object](#3.6.1 Function Object)章节已经介绍过函数对象，那些可以传递给泛型算法作为参数，例如less_than等，标准库实现的函数对象都在< functional >中，本节是来告诉如何实现自己的函数对象。

在[3.6.1 Function Object](#3.6.1 Function Object)章节，其实给出了一个简单的例子。

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

所谓函数对象，就是实现了对函数调用符号()重载的类。

如果实现一个小于某个数的函数对象，可以这样写。

```c++
class LessThan
{
    public:
    	LessThan(int val):reVal(val){}
		int getReVal(){return reVal;}
    	void resetReval(int val){reVal=val;}
    	bool operator()(int val)const;
    private:
    	int reVal;
};
inline bool LessThan::operator()(int val)const
{
    return val<reVal;//返回的是bool值
}
```

单独使用这个类可以这样使用，定义一个可以找到一个容器内小于指定数的的元素个数的函数。

```c++
int count_lessThan_(const vector<int>& vec, int comp)//comp是要比较的基准数
{
    LessThan LT(comp);//()是构造
    int count = 0;
    for(int x=0;x<vec.size();++x)
    {
        if (LT(vec[x])) //()是调用重载函数,如果返回true就++count
            ++count;
    }
    return count;
}
```

如果希望返回满足条件的元素集合，而不是元素个数可以这样写。

```c++
vector<int> get_lessThan_(const vector<int>& vec, int comp)
{
    vector<int> ans;
    LessThan LT(comp);//()是构造
    vector<int>::const_iterator it = vec.begin();
    vector<int>::const_iterator it_end = vec.end();
    while ((it = find_if(it,it_end,LT)) != it_end){
        ans.push_back(*it);//不断缩小区间寻找符合条件的数
        ++it;
    }
    return ans;   
}
```

### 4.10 重载iostream运算符

如果希望输出class object的信息，需要借助ostream，但是因为输出流对象必须在左边，即<<是二元运算符，如果想要作为类的成员函数，就必须声明为友元函数。因为成员函数左操作数必须是this自身，但是ostream对象必须在左边。

```c++
class A
{
    public:
    	friend ostream&<<(ostream&o ut,const A& rhs);
};
ostream& <<(ostream&out,const A& rhs)
{
    cout<<..<<endl;//打印一些信息
}
```

### 4.11 指向成员函数的函数指针

指向成员函数和指向非成员函数的函数指针并没有太大区别，后者在[2.11 函数指针的妙用](#2.11 函数指针的妙用)已经详细叙述过。前者只是还需要声明作用域，这样能够知道是引用哪个类的成员函数。

pm表明它是一个函数指针，指向的是num_sequence类里的函数，返回值是void，且只接收单参数，是个int类型，初始值为0表示不指向任何成员函数。

```c++
void(num_sequence::*pm)(int) = 0;
```

可以使用别名，这样没有麻烦。

```c++
typedef void(num_sequence::*PtrType)(int);
PtrType pm = 0;
```

现在使用一个通用数列类来描述各种数列，它们除了计算方式不同，其它没有任何区别。

```c++
class num_sequence // 通用数列类
{
    public:
    	typedef void(num_sequence::*PtrType)(int);
    	
    	// PtrType可以指向任何一个下边的函数
    	void fibonacci(int);
    	void pell(int);
        void lucas(int);
        void triangular(int);
        void sequare(int);
        void pentagonal(int);
    	...
    private:
    	PtrType pmf;
};
// 外部使用函数指针应当取函数地址
PtrType pm = &num_sequence::pell;
```

为了避免重复计算每个数列元素，也是声明一个 静态的容器，不过由于要计算6个容器，每个数列都需要一个容器存储元素，所以定义一个容器的容器，但是大小为7，第0个容器为空。因为函数指针可以不指向任何容器。然后定义一个存放函数指针的数组，这样方便调用，改变pm的值。还需要一个临时容器，指向当前正在使用的数列容器。

```c++
class num_sequence
{
    public:
    	typedef void(num_sequence::*PtrType)(int);
    	...
    private:
    	PtrType pmf; //当前指向的函数指针
    	vector<int>* whichVec;//当前指向的数列容器地址
    	static const int num_seq = 7;
    	static const vector<vector<int> > seq; //真正存放数列元素的静态容器
    	static PtrType func_seq[num_seq]; // 函数指针的数组,方便pmf取用
};
```

这里需要说明的，类内如何使用pmf这样的函数指针。因为pmf是指针，真正要使用的是具体的函数，也就是 * pmf，对于num_sequence的实例或者指针应当这样使用函数指针指向的函数。

```c++
num_sequence ns;
(ns.*pm)(pos);//(ns.*pm)就是某个具体的函数,例如pell,那么这句等价于ns.pell(pos);
```

如果是指向num_sequence的指针使用pmf也是一样。

```c++
num_sequence * pns = &ns;
(pns->*pm)(pos);//和pns->pell(pos)等价
```

之后还需要给出静态成员函数/变量的定义，可以在头文件中定义也可以在代码文件定义。

```c++
const int num_sequence::num_seq;//定义,但是无需再次初始化
vector<vector<int> > num_sequence::seq(num_seq);//可以看出定义是类型+作用域+变量名构成

// 同理函数指针数组也是如此,它是个num_sequence::PtrType类型
num_sequence::PtrType num_sequence::func_seq[num_seq]=
{
    0,
    &num_sequence::fibonacci,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular,
    &num_sequence::square,
    &num_sequence::pentagonal
}
```

设想的外部通过整型编号0到6记为x来传递给func_seq，让pmf=func_seq[x]，那么pmf指向了一个计算数列的函数，数列函数内部会依据要计算的数列位置pos决定是否更新静态变量seq。这些操作事先定义在函数set_sequence中，该函数接收1个参数，因为要知道改变的是哪个数列，但是这里不用x去区分，而是一个函数将x转为一个类型ns_type，它比整型x更好区分是哪个数列类型(其实利用的是枚举,ns_type定义了枚举类型)，可以直接用在set_sequence函数上，在第五章会具体说明，这个函数名为ns_type()，是静态类型。至于返回指定位置的数列元素由elem函数实现，elem函数内部其实就是访问了seq[x] [pos-1]。类内还会定义一个静态成员函数，返回可用数列计算类型，这里给定是6个，但是可以更多，这个函数为num_of_sequence()。

设想的外部程序。

```c++
int main
{
    num_sequence ns;//通用类的实例
    const int pos = 8;//想要访问的数列元素位置
    for(int x=1;x<ns.num_of_sequence();++x){ // 找出所有数列位置8上的元素
        ns.set_sequence(num_sequence::ns_type(x)); // x->ns_type[x]->set_sequence
        int val = ns.elem(pos);//ns内部此时指向某个数列类型的容器,打印pos位置的元素
        display(cout,ns,pos,val);// 展示函数   
    }
    return 0;
}
```

由于elem函数比较简单，这里给出其实现，其他函数在下一章给出实现。

```c++
int num_sequence::elem(int pos)
{
    if (!check_integrity(pos)) // 检查要计算的pos位置是否合理,它不能≤0也不能≥max_elem
        return 0;
    if (pos > this->whichVec->size() ) // which是当前指向的容器地址
        (this->*pmf)(pos); // 如果pos位置的元素暂时未被计算过,就调用pmf指向的函数来更新seq的对应容器
    return (*whichVec)[pos-1];// <=> seq[x] [pos-1]
}
```

## 五、面向对象编程风格

### 5.1 面向对象编程概念

#### 5.1.1 继承和多态

面向对象编程概念的最主要两项特质是：继承和多态。

第四章的内容虽然可以提供一个类来描述一类东西，例如一本书Book，但是很可能有不同类型的书，它们有共同点也有不同点，可能存在依赖关系。

继承可以将一群相关的类组织起来，可以分享其间的共通数据和操作行为，多态可以在这些类上编程时如同操纵单一个体，而非相互独立的类，赋予更多弹性来加入或移除任何特定类。其实上一章提到的num_sequence类就是多态行为，它可以变成任何一个数列之一，不过这种多态是因为编程技巧获得的，而不是程序语言先天赋予。

继承和多态最重要的是抽象基类的定义，它定义的越好越抽象，随着继承的复杂，它可应付的也越好。由此引出动态绑定和静态绑定的概念。

#### 5.1.2 静态和动态绑定

写下这样一句代码，mat是某个具体的类对象。编译器在编译时就会依据mat所属的类来决定执行哪一个check_in函数，由于程序执行前就知道调用哪个，这叫静态绑定。

```c++
mat.check_in();
```

面向对象的编程方法中，编译器无法预知是哪一份check_in函数被调用，仅在执行时依据mat所指的实际对象来调用哪一个，这叫的动态绑定。mat其实就是抽象基类的指针或引用，而且只能是指针或引用才能发挥动态绑定的作用。

### 5.2 面向对象编程思维

假设图书的抽象基类LibMat如下。

```c++
class LibMat
{
    public:
    	LibMat(){cout<<"LibMat is constructor\n";}
    	virtual ~LibMat(){cout<<"LibMat is destructor\n";}
    	virtual print()const{cout<<"LibMat's print is call\n";}
    
};
void print(const LibMat& mat)//抽象基类的引用/指针
{
    mat.print();//调用何种版本?
}
```

主程序这样。

```c++
LibMat libmat;
print(libmat);//调用的是LibMat的print版本
// 跟踪结果
LibMat is constructor;
LibMat's print is call;
LibMat is destructor;    
```

假若Book是LibMat的衍生类，基类和派生类的构造和析构的都会被执行。

```c++
Book book;
print(book);//调用的是Book的print版本
// 跟踪结果
LibMat is constructor;
Book is constructor;
Book's print is call;
Book is destructor; 
LibMat is destructor; 
```

如果Book还有子类AudoBook，也是如此。

```c++
AudoBook audobook;
print(audobook);//调用的是AudoBook的print版本
// 跟踪结果
LibMat is constructor;
Book is constructor;
AudoBook is constructor;
Book's print is call;
Book is destructor; 
AudoBook is destructor; 
LibMat is destructor; 
```

### 5.3 不带继承的多态

再想想[4.11 指向成员函数的函数指针](#4.11 指向成员函数的函数指针)关于num_sequence的实现，num_sequence类就是多态行为，它可以变成任何一个数列之一，不过这种多态是因为编程技巧获得的，而不是程序语言先天赋予。

现在把这个类补充完整，如下。

```c++
class num_sequence
{
    public:
    	typedef void(num_sequence::*PtrType)(int);
    	void fibonacci(int);
    	void pell(int);
        void lucas(int);
        void triangular(int);
        void square(int);
        void pentagonal(int);
    	
    	enum ns_type {ns_unset,ns_fibonacci,ns_pell,ns_lucas,ns_triangular,
                     ns_square,ns_pentagonal};//定义的枚举类型
    	static ns_type nstype(int num){ //一个提升整型记号num为枚举类型的强制转换
            // 内部调用了static_cast强制转换 num∈[1,6]有效,否则为0
            return num<=0 || num>= num_seq ? ns_unset:static_cast<ns_type>(num);
        }
    	int elem(int pos);
    	void set_sequence(ns_type nst);
    	const char* what_am_i()const;

    private:
    	PtrType pmf; //当前指向的函数指针
    	vector<int>* whichVec;//当前指向的数列容器地址
    	static const int num_seq = 7;
    	static const vector<vector<int> > seq; //真正存放数列元素的静态容器
    	static PtrType func_seq[num_seq]; // 函数指针的数组,方便pmf取用
    	
    	ns_type whichFunc;// 当前指向的数列枚举类型
    	
};
const int num_sequence::num_seq;//定义,但是无需再次初始化
vector<vector<int> > num_sequence::seq(num_seq);//可以看出定义是类型+作用域+变量名构成

// 同理函数指针数组也是如此,它是个num_sequence::PtrType类型
num_sequence::PtrType num_sequence::func_seq[num_seq]=
{
    0,
    &num_sequence::fibonacci,
    &num_sequence::pell,
    &num_sequence::lucas,
    &num_sequence::triangular,
    &num_sequence::square,
    &num_sequence::pentagonal
}
// elem访问函数
int num_sequence::elem(int pos)
{
    if (!check_integrity(pos)) // 检查要计算的pos位置是否合理,它不能≤0也不能≥max_elem
        return 0;
    if (pos > this->whichVec->size() ) // which是当前指向的容器地址
        (this->*pmf)(pos); // 如果pos位置的元素暂时未被计算过,就调用pmf指向的函数来更新seq的对应容器
    return (*whichVec)[pos-1];// <=> seq[x] [pos-1]
}

// 调整序列的函数
void num_sequence:: set_sequence(ns_type nst)
{
    switch(nst)
    {
        default:
            cerr<<"invalid type: setting to 0\n";
            //刻意让他执行下去,不作break
        case ns_unset:
            pmf = 0; //不指向任何函数
            whichVec = 0; // 不指向任何容器
            whichFunc = ns_unset; // 数列枚举类型是ns_unset
            break;
        case ns_fibonacci: case pell: case lucas: 
        case triangular: case square: case pentagonal:
            pmf = func_seq[nst]; //通用的操作,nst是这些枚举类型时
            whichVec = &seq[nst];
            whichFunc = nst;
            break;
    }
}

// 还提供的display函数,这是非成员函数
inline void display(ostream&os,const num_sequence & ns, int pos)
{
    os << "The element at position "<<pos
        <<" for the "<<ns.what_am_i()<<" sequence is "
        <<ns.elem(pos)<<endl;
}

const char* num_sequence:: what_am_i()const //返回字符串数组
{
    static char*names[num_seq]={
        "notSet",
        "fibonacci","pell",
        "lucas","triangular",
        "square","pentagonal"
    };
    return names[whichFunc];//会自动降为整型
}
```

### 5.4 定义一个抽象基类

第一步：找出所有子类共通的行为；

第二步：让操作行为与类型相关的函数声明为虚函数；

第三步：确定每个操作行为的访问层级。

对于num_sequence目前抽象出来的共同函数有6个。

```c++
class num_sequence
{
    public:
    	int elem(int pos);//返回pos位置上的元素
    	void generate_elems(int pos);//产生直到pos位置的所有元素
    	const char* what_am_i() const;//返回数列类型的字符串
    	ostream& print(ostream&os = cout)const;//打印类的信息
    	bool check_integrity(int pos); //检查pos的合理性
    	static int max_elems();//返回支持的最大位置值
    	...
};
```

其中check_integrity和max_elems函数不会因为类型不同而不同，而其它函数可能会因为具体对的派生类导致实现有所不同，这些函数应当声明为虚函数。但是要注意，静态成员函数无法声明为虚函数。

然后还要确定函数的访问层级，显而易见elem、max_elems和what_am_i函数的都应该能够被类外进行使用，它们要声明为public。而check_integrity和generate_elems应当声明为protected成员，因为它们还要被继承的派生类所使用。故上述抽象类的设计应当更改为如下。

```c++
class num_sequence
{
    public:
    	virtual ~num_sequence(){}//不建议设为纯虚函数
    	
    	virtual int elem(int pos)const = 0;
    	virtual const char* what_am_i() const = 0;
    	virtual ostream& print(ostream&os = cout)const=0;
    	static int max_elems(){return elems_max};//静态成员不能声明为virtual
    protected:
    	bool check_integrity(int pos); //完全相同的操作不必声明为虚的
    	virtual void generate_elems(int pos);
    	const static int elems_max = 1024;
};
bool num_sequence::check_integrity(int pos) const
{
    if (pos<=0 || pos> elems_max){
        cerr<<"!! invalid position: "<<pos <<" cannot honor request\n";
        return false;
    }
    return true;
}
ostream& operator<<(ostream&os,const num_sequence &ns)
{
    return ns.print(os);
}
```

上述const=0表明这些函数是纯虚函数，没有给出定义，那么它们的派生类必须提供给所有虚函数确切对的定义，否则程序不能为它产生任何对象。

这个抽象类并没有声明任何成员变量，因为成员变量相比一组行为没有那么抽象，派生类负责定义自己的成员变量。因为没有成员变量需要被初始化，所以构造函数也没有价值，使用默认的即可。析构函数，根据规则"如果基类定义了一个或多个虚函数，析构函数也应当定义为virtual"。

析构函数声明为virtual的具体原因见EffectiveC++的条款07，这里再重复一遍原因。

一般而言基类的对象由基类的析构函数销毁，子类的对象由子类的析构函数销毁。但是因为基类的指针可以指向子类，根据规则"要根据实际对象的类型来选择调用哪一个析构函数"，所以如果删除此时的基类指针，应当调用子类的析构函数，但是如果基类的析构函数没有声明为virtual就会调用基类的析构函数，这样子类的成分并没有被销毁造成内存泄漏。。

### 5.5 定义一个派生类

定义一个斐波那契数列的类，它必须为基类继承来的每个纯虚函数提供对应的实现，还必须声明它自己专属的成员变量。因为是公有继承，基类的public和protected对象在派生类依然是public和protected，但是基类的private不能被派生类使用。保护继承和私有继承的方式另说。

```c++
class Fibonacci:public num_sequence
{
    public:
        Fibonacci(int len=1,int pos =1):len(len),pos(pos){}
        virtual int elem(int pos) const;
        virtual const char* what_am_i const{return "Fibonacci";}
        virtual ostream& print(ostream&os = cout) const;
        int length() const{return len;};
        int position()const{return pos;}
   	protected:
    	virtual void generate_elems(int pos) const;
    	int len;
    	int pos;
    	static vector<int> elems;   
}
int Fibonacci::elem(int pos) const
{
    if (!check_integrity(pos)) // 调用派生类的，但是它存在一个大问题！
        return 0;
    if (pos > elems.size())
        Fibonacci::generate_elems(pos);//这里必须明确作用域,这样可以编译阶段就知道调用哪个版本而不是运行时解析,这样继承发生的虚拟机制可以被掩盖
    return elems[pos-1];
}
void Fibonacci::generate_elems(int pos) const
{
    if (elems.empty())
    {elems.push_back(1);elems.push_back(1);} 
    if (elems.size()<=pos)
    {
        int ix = elems.size();
        int n_2 = elems[ix-2];
        int n_1 = elems[ix-1];
        for(:ix<=pos;++ix)
        {
            int e = n_2 + n_1;
            elems.push_back(e);
            n_2 = n_1;
            n_1 = e;
        }
    }
}
ostream& Fibonacci:: print(ostream& os) const
{
    int elem_pos = pos - 1;
    int end_pos = eelem_pos + len;
    if (end_pos > elems.size())
        Fibonacci::generate_elems(end_pos);
    while (elem_pos < end_pos)
        os << elems[elem_pos++]<<" ";
    return os;
}
```

派生类新增加的2个成员，length和position函数不能被基类指针访问，其它的可以。

generate_elems和prrint函数都可以检查elems的元素是否足够。

现在再来看看check_integrity函数，基类中没有声明为虚函数，它直接被派生类继承。

如果派生类给出了check_integrity的定义，毫无疑问，如果不加作用域，check_integrity函数调用的是Fibonacci下的check_integrity函数而不是num_sequence下的check_integrity函数，这相当于递归的调用自己，因为同名函数子类会覆盖基类。

```c++
//基类的版本
bool num_sequence::check_integrity(int pos) const
{
    if (pos<=0 || pos> elems_max){
        cerr<<"!! invalid position: "<<pos <<" cannot honor request\n";
        return false;
    }
    return true;
}
// 派生类的版本
inline bool Fibonacci::check_integrity(int pos)const
{
    if (!num::sequence::check_integrity(pos))//必须加作用域否则成递归的调用自身
        return false;
    if (pos > elems.size()) // 派生类版本独有的检查
        Fibonacci::generate_elems(pos);
    return true;
}
```

现在存在一个问题，如果基类指针指向子类，调用的还是基类的函数，而没有遵从"要根据实际对象的类型来选择调用哪一个函数"，这是因为这个函数不是虚函数，不遵从这个机制。那么即使基类指针指向子类，但是调用的依然是基类的函数。

```c++
num_sequence *ns = new Fibonacci(12,8);
ns->elem(1024);//elem是虚函数,会遵从规则,解析为调用Fibonacci的elem函数
ns->check_integrity(pos);//check_integrity不是虚函数,不遵从动态绑定,调用的是num_sequence的check_integrity函数
```

这样看起来，似乎把check_integrity函数也声明为virtual才能解决问题，也就是基类所有的函数都应该声明为virtual，其实不一定正确。好的设计是一步步演进的，基类的check_integrity函数可以改写。

```c++
//基类的版本
bool num_sequence::check_integrity(int pos,int size) const
{
    if (pos<=0 || pos> elems_max){
        cerr<<"!! invalid position: "<<pos <<" cannot honor request\n";
        return false;
    }
    if (pos>size)
        generate_elems(pos); // 借助generate_elems是个虚函数
    return true;
}
```

这其实利用了一个技巧，如果不想把函数声明为虚的，但是又希望拥有虚函数的机制，可以让函数定义妥当的参数，使之能够调用其它的虚函数，那么该函数就不会因为基类指向子类但是不执行子类的函数版本。因为这个函数无论是基类版本还是子类版本，内部都使用了虚函数机制，依然可以保证调用的是指向对象的版本。

如果check_integrity函数被Fibonacci的对象调用，前边是一样的，内部调用的是Fibonacci的generate_elems函数，因为它是虚函数遵从规则，不声明作用域也可以。如果是num_sequence调用check_integrity函数，同样，内部会调用num_sequence版本的generate_elems函数。

### 5.6 运用继承体系

现在假设其它5个数列类都继承了num_sequence，现在如何使用呢？

因为虚函数的性质，实际上，取决于指针指向的实际对象，就知道何种类的函数。

```c++
inline  void display(ostream&os,const num_sequence &ns,int pos){
    os<<"the element at position "<<pos<<" for the"
        << ns.what_am_i()<<" sequence is "
        << ns.elem(pos) << endl;
}
```

使用它们，就会动态绑定至具体的派生类对象。

```c++
const int pos =8;
Fibonacci fib;
Pell pell;
Lucas lucas;
Square square;
...
display(cout,fib,pos);
display(cout,pell,pos);
display(cout,lucas,pos);
display(cout,square,pos);
```

### 5.7 基类的抽象程度

基类的抽象程度，决定了派生类继承基类的难度，现在把之前的基类num_sequence和之前的派生类Fibonacci共有的部分再次抽象，并定义为虚函数，所以也要定义虚析构。

```c++
class num_sequence
{
    public:
    	virtual ~num_sequence(){}
    	virtual const char* what_am_i() const = 0;//纯虚可展现多态,没有缺省实现
    	int elem(int pos);//non-virtual要求派生类不重定义它
    	int length() const{return len;}
    	int position() const {return pos;}
    	ostream& print(ostream&os = cout)const;
    	static int max_elems(){return 64;};
    protected:
    	virtual void generate_elems(int pos)const = 0
    	bool check_integrity(int pos,int size) const; 
    	num_sequence(int len,int pos,vector<int>&vec):
    		len(len),pos(pos),elems(vec){}//构造函数
    	int pos;
    	int len;
    	vector<int>& elems;//是个引用就必须被初始化,初始化后就不能指向其它
};
```

现在派生类Fibonacci只需要重定义个别函数即可，即2个虚函数、构造函数和析构函数。

```c++
class Fibonacci : public num_sequence{
    public:
    	Fibonacci(int len=1,int pos=1);//定义自己的构造函数
    	virtual const char* what_am_i()const{
            return "Fibonacci";//虚函数依然还是虚函数
        }
   	protected:
    	virtual void generate_elems(int pos) const;//以自己数列公式定义
    	static vector<int> elems;//自己的静态容器
}
```

如何初始化、定义析构和构造函数见下一节。

### 5.8 初始化、析构和复制

Fibonacci对象初始化会调用基类的构造，然后调用派生类自己的构造，所以派生类实际有2个成分。这里基类声明的构造函数是必须执行的，也就是必须初始化那个基类的elems，所以定义派生类的构造函数应当这样写。

```c++
inline Fibonacci::Fibonacci(int len,int pos):num_sequence(len,pos,elems){}
```

所以整体的写法是这样。

```c++
class Fibonacci : public num_sequence{
    public:
    	Fibonacci(int len=1,int pos=1);//定义自己的构造函数
    	virtual const char* what_am_i()const{
            return "Fibonacci";//虚函数依然还是虚函数
        }
   	protected:
    	virtual void generate_elems(int pos) const;//以自己数列公式定义
    	static vector<int> elems;//自己的静态容器
}
inline Fibonacci::Fibonacci(int len,int pos):num_sequence(len,pos,elems){}//必须调用基类构造
```

由于这里的copy、copy_assignment的默认提供已经可以达到效果(成员逐一复制)，可以不提供，如果要提供，大概也是这样子。它们都是借助了基类的实现，为何可以这样？因为派生类只定义了唯一的成员变量elems，还是静态的，所以初始化的时候不必自己逐一构造，调用基类的已经够用。

```c++
Fibonacci::Fibonacci(const FibonacciFibonacci&rhs)
    :num_sequence(rhs)){} //rhs的成员逐一复制过去
Fibonacci& Fibonacci::operator=(const Fibonacci&rhs){
    if (this!=&rhs)
        num_sequence::operator=(rhs);
    return *this;
}
```

还有一个做法是，基类提供public构造，同时elems不是引用，而是指针，那么它可以不需要初始化，但是每次访问这个容器时都需要判断指针是否为空。

```c++
class num_sequence
{
    public:
    	num_sequence(int len=1,int pos=1,vector<int>*pe=0);//提供构造
    	virtual ~num_sequence(){}
    	virtual const char* what_am_i() const = 0;
    	int elem(int pos);
    	int length() const{return len;}
    	int position() const {return pos;}
    	ostream& print(ostream&os = cout)const;
    	static int max_elems(){return 64;};
    protected:
    	virtual void generate_elems(int pos)const = 0
    	bool check_integrity(int pos,int size) const; 
    	num_sequence(int len,int pos,vector<int>&vec):
    		len(len),pos(pos),elems(vec){}//构造函数
    	int pos;
    	int len;
    	vector<int>* elems;//改为指针就不必一定初始化
};
inline num_sequence::num_sequence(int len,int pos,vector<int>*pe):
	len(len),pos(pos),elems(pe){}
```

### 5.9 派生类中定义一个虚函数

派生类可以继承基类的虚函数不做任何事情，那么它还是抽象基类，但是也可以覆盖继承来的虚函数，但是切记要严格按照原型定义，否则动态绑定时只会执行基类的函数，即使const也要完全继承下来。返回类型和输入类型都要一致。

```c++
class Fibonacci:public num_sequence{
    public:
    	virtual const char* what_am_i(){return "Fibonacci";}//不正确
    	virtual char* whta_am_i()const{return "Fibonacci";}//也不正确
}
```

返回类型必须一致有个例外，那就是返回自身的指针时。

```c++
class num_sequence{
    public:
    	virtual num_sequence* clone()=0;//返回一个可指向任何派生类的指针
}
class Fibonacci:public num_sequence{
    public:
    	Fibonacci* clone(){return new Fibonacci(*this);}//例外,且virtual并非必要
}
```

虚函数的动态绑定在两个情况不会出现，它们都是静态解析。

第一：基类的构造函数和析构函数内；

第二：使用基类的对象而不是基类的指针或引用时 。

因为如果基类的构造函数调用了某个虚函数，它一定调用的是基类的那一份。因为派生类对象构造时会先调用基类构造，此时派生类的一些成员尚未初始化，此时调用虚函数的话不能调用派生类的那一份，因为很可能用到了未初始化的变量，所以才要求基类构造只调用自己的那一份，那也就是静态解析不会变。

另外使用基类的对象时就已经固定了大小，即使传入派生类对象也会被切割成基类的那一份。使用基类的指针或引用时，就取决于它实际指向的对象类型了。

### 5.10 运行时的类型鉴定机制

现在每个类都有自己的what_am_i函数，但是现在希望派生类不用再自己编写这个函数，也通过继承，一个方法是基类增加一个成员变量name，然后构造函数也增加一个初始化参数即可。然后派生类就可以传入这个值给基类的构造即可。

```c++
inline Fibonacci::Fibonacci(int len,int pos)
    :num_sequence(len,pos,elems,"Fibonacci")
```

另一种实现是通过typeid，它可以给出多态化的指针或引用类型，包含于< typeinfo>头文件，typeid可以返回type_info对象，关联到实际类型。

```c++
#include <typeinfo>
inline const char* num_sequence::what_am_i const{
    return typeid(*this).name();
}
```

type_info也支持相等和不等比较操作。

```c++
num_sequence * ps= &fib;
if (typeid(*ps) == typeid(Fibonacci))//ps确实是Fibonacci对象
    ps->Fibonacci::generate_elems(64);//编译错误！因为ps毕竟不是Fibonacci指针，需要执行强转才正确
```

强转操作如下。

```c++
if (typeid(*ps) == typeid(Fibonacci)){//这也是为何先判断为真才如此
    Fibonacci*pf =static_cast<Fibonacci*>(ps);//无条件转换有潜在危险
    pf->generate_elems(64);
}    
```

或者直接使用有条件强转。

```c++
if( Fibonacci* pf = dynamic_cast<Fibonacci*>(ps))
    pf->generate_elems(64);
```

dynamic_cast可以检验ps所指对象是否属于Fibonacci类，如果是就发生强转并执行调用函数，否则返回0，if条件不成立也就不会执行。

## 六、以template进行编程

 以二叉树类的模板类实现，包含两个类，一个是节点类，也就是树节点，另一个是二叉树类。

主要实现的功能：插入、元素、查找元素，清除所有元素、前中后序遍历二叉树。

对于插入要求，一个值只能在树中出现1次，但是可以记录重复值插入的次数，同时值比根节点小就置于左子树，否则置于右子树。

### 6.1 实现一个Class Template

这节内容实际上把原书6.1节到6.5节包含。

以树节点的类为例，令它支持模板，即可以参数化的类型T。    

```c++
template<class T>
class binaryTree;//前置声明

template<class T>
class TreeNode{
    public:
    	friend class binaryTree<T>;//友元类
    	TreeNode(const T& val) : val(val),cnt(1),left(nullptr),right(nullptr) {}
    	void insert_value(const T&elem);
    	void remove_value(const T&elem,TreeNode*prev);
    	void preorder(TreeNode*rt,ostream&os) const;
        void inorder(TreeNode*rt,ostream&os) const;
        void postorder(TreeNode*rt,ostream&os) const;
    private:
        T val;
    	int cnt;
      	TreeNode *left;
    	TreeNode *right;
    	void display(TreeNode*rt,ostream&os);
    	static void leftToLeaf(TreeNode*leaf,TreeNode*subtree);//重复且相同的操作可声明为static
}
template<class T>
void TreeNode<T>::insert_value(const T&val){
    if (val == this->val)
    {++cnt;return;}
    if (val < this->val)//这个操作需要在外部给出如何比较
    {
        if (!left)
            left = new TreeNode(val);
        else left->insert_value(val);//递归调用自己
    }
    else{
        if (!right)
            right = new TreeNode(val);
        else right->insert_value(val);
    }
}
template<class T>
void TreeNode<T>::remove_value(const T&val,TreeNode*&prev){
    // 使用引用的指针传递可以更改指针本身而不仅仅是指针指向的东西
    if (val < this->val){
        if (!left)
            return;//不在此二叉树
        else left->remove_value(val,left);//递归调用自己改变left及其left指向的东西
    }
    else if (val > this->val){
        if (!right)
            return;//不在此二叉树
        else right->remove_value(val,right);//递归调用
    }
    else {
        // 找到val后重置此树
        if (!right){
            prev = right;
            if (!prev->left){
                prev->left = left;
            }
            else TreeNode<T>::leafToLeft(left,prev->left);
        }
        else prev = left;
        delete this;
    }
}
template<class T>
inline void TreeNode<T>::leftToLeaf(TreeNode*leaf,TreeNode*subtree){
    while (subtree->left)
        subtree = subtree->left;
    subtree->left = leaf;//把节点leaf作为最左节点的子节点
}
template<class T>
void TreeNode<T>::preorder(TreeNode*rt,ostream&os) const{
    if (rt){
        display(rt,os);
        if (rt->left) preorder(rt->left);
        if (rt->right) preorder(rt->right);
    }
}
template<class T>
void TreeNode<T>::inorder(TreeNode*rt,ostream&os) const{
    if (rt){
        if (rt->left) preorder(rt->left);
        display(rt,os);
        if (rt->right) preorder(rt->right);
    }
}
template<class T>
void TreeNode<T>::postorder(TreeNode*rt,ostream&os) const{
    if (rt){
        if (rt->left) preorder(rt->left);
        if (rt->right) preorder(rt->right);
        display(rt,os);
    }
}
template<class T>
void TreeNode<T>::display(TreeNode*rt,ostream&os){
    os<<rt->val<<" ";
}
```

但是不建议构造函数这样做，如果T是个自定义类型而不是内置类型，这样的操作实际上执行了2次操作，第一个是调用了T类型的构造函数给this->val，然后再调用copy assignment将val复制给this->val。如果采用成员初值列的方法就可以避免这2个步骤，只需要一个复制构造即可解决问题。

尽量使用成员初值列去初始化变量，虽然值传递或者在构造函数内使用assignment对成员初始化也是正确的，但是缺乏效率。

```c++
template<typenmae T>
inline TreeNode<T>::TreeNode(const TreeNode&val){
    this->val = val;
    left = right = 0;
    cnt = 1;
}
```

二叉树的类。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

```c++
template<class T>
class binaryTree{
    public:
    	...//
    private:
    	TreeNode<T> * root;
}
```

对二叉树类的声明和部分定义进行完善。

```c++
template<class T>
class binaryTree{
    public:
    	binaryTree();
    	binaryTree(const binaryTree&);
    	~binaryTree();
    	binaryTree& operator=(const binaryTree<T>&);
    	bool empty(){return root==nullptr;}//自动inline
    	void clear(){if (root){clear(root);root=nullptr;}};
    	void insert(const T&elem);
		void preorder()const{root.preorder(root,cout);};
        void inorder()const{root.inorder(root,cout);};
        void postorder()const{root.postorder(root,cout);};
    	friend ostream& operator<><<(ostream&,const binaryTree<T>&);
    private:
    	TreeNode<T> * root;
    	void copy(TreeNode<T>*target,TreeNode<T>*source);//把src的树复制到tar上
    	void remove_root();
    	void clear(TreeNode<T>*);//真正用于clear的工作函数
    	void print(ostream& os);
}
template<class T>
inline binaryTree<T>::binaryTree():root(0){} // 类外定义声明为inline

template<class T>
inline binaryTree<T>::binaryTree(const binaryTree&rhs){
    copy(this->root,rhs.root);//不clear,表示以rhs为准
}

template<class T>
inline binaryTree<T>::~binaryTree(){clear();}

template<class T>
inline binaryTree<T>& binaryTree<T>::operator=(const binaryTree&rhs){
    if (this != &rhs){
        clear();// 要求相等,可能this会包含rhs
        copy(this->root,rhs.root);
    }
    return *this;
}

template<class T>
inline void binaryTree<T>::insert(const T&elem){
    if (!root)
        root = new TreeNode<T>(elem);//作为根节点
    else root->insert_value(elem);//调用插入值的函数做真正的工作
}

template<class T>
inline void binaryTree<T>::remove(const T& elem){
    if (root){
        if(root->val == elem)
            remove_root();//根节点的移除以特例处理,要将左子树变为右节点的左子树
        else 
            root->remove_value(elem,root);//删除目前的root上要删除的elem,内部root会向下移动
    }
}

template<class T>
void binaryTree<T>::remove_root(){
    if (!root) return;
    TreeNode<T>* tem = root;//多1个临时指针指向它
    if (root->right){//存在右节点时就继续
        root = root->right; // root下移到右节点
        if (tmp->left){ // 从全局root开始,存在左节点时就把左节点想办法接到下移右节点的左子树上
            TreeNode<T> * leftchild = tmp->left;//指向这个左孩子的指针
            TreeNode<T> * newleftchild = root->left; // 下移的右节点的左子树
            if (!newleftchild)//下移的右节点是否有左子树,没有直接接上
                root->left = leftchild;
            else // 下移的右节点存在左子树,调用静态函数
                TreeNode<T>::leafToLeft(leftchild,newleftchild);//把leftchild作为newleftchild的左叶子节点
        }
    }
    else root = root->left;
    delete tmp;
}
template<class T>
void binaryTree<T>::clear(TreeNode<T>*rt){
     if (rt){
         clear(pt->left);//递归删除自己
         clear(pt->right);
         delete rt;
     }
}
template<class T>
void binaryTree<T>::print(ostream& os){
    ...
}
template<class T>
ostream& operator<><<(ostream&os,binaryTree<T>& bt){
    os<<"tree is \n";
    bt.print(os);
    return os;
}
```

对插入函数的说明：插入的实际操作是借助TreeNode类内的insert_value函数，内部借助了递归操作。

对移除函数的说明：如果是移除根节点，就调用自身的remove_root函数，否则移除实际操作借助TreeNode类内的remove_value函数。但无论是哪个函数，它们存在一个共同操作就是移除左子节点到右子节点的左子树的叶子节点，这部分操作可以剥离出来成为TreeNode的静态成员函数leftToLeaf，大大提高效率。

对遍历算法：这里使用递归算法。

### 6.2 常量表达式与默认参数值

模板参数不一定是T，还可以是表达式，现在可以重新设计num_sequence及其继承的类。

```C++
template<int len,int pos = 1> //没有T类型,像表达式
class num_sequence{
    public:
    	num_sequence(int len,int pos);
    // ...
}
template<int len, int pos>
class Fibonacci: public num_sequence<len,pos>
{
    public:
    	Fibonacci(int len,int pos);
    //...
}
```

### 6.3 以Template参数作为一种设计策略

曾提过的LessThan函数可以引入模板。

```c++
template<typename T>
class LessThan{
    public:
    	LessThan(const T&val):val(val){}
    	bool operator()(const T&val)const{return val<this->val;}
    	void setVal(const T&newVal){this->val=newVal;}
    	T getVal()const {return this->val;}
    private:
    	T val;
}
LessThan<int> lt1(1024);
LessThan<string> lt2("pooh");//存在问题,如果T类型不支持比较运算就有错误
```

一个方法是将比较运算符剥离出来，另定义一个模板类，成为LessThanPred，然后提供比较的函数对象，类型和值类型一致。

```c++
template<typename valType,typename compType = less<valType> >//默认基于less函数对象的比较方式
class LessThanPred{
   public:
    	LessThanPred(const valType& val):val(val){}
    	bool operator()(const valType&val) const{return compType(val,this->val)}
    	void setVal(valType&newVal){this->val = newVal;}
    	valType getVal() const{return this->val;}
    private:
    	valType val;
}
// 另一个提供比较功能的函数对象,就可以作为compType传入,这个对象定义了自己的比较方式
class StringLen{
    public:
    	bool operator()(const string&s1,const string&s2){
            return s1.size()<s2.size();
        }
};
LessThanPred<int> lt1(1024);//使用默认的less比较
LessThanPred<string,StringLen> lt2("pooh");//使用string类型的比较函数对象
```

也可以定义一个更加弹性的类，它可以支持任何类型的比较操作，也就不再需要对string单独的比较操作函数对象StringLen。

这个类可以作为基类，只提供接口函数。任何比较类型可以基于它派生。

```c++
template<typename valType,typename compType> // 区别在于不再指定less,也无需指定以valType为基准
class Compare{
    public:
    	//...一些虚函数,派生类必须继承它,可以只继承也可以覆盖
}
```

### 6.4 成员模板函数

在EffectiveC++的条款45< 运用成员函数接受所有兼容类型 >曾提到过成员函数模板的使用方法。

这里给出一个例子再来说明如何使用，A专门用来输出T类型数据，只要它可以被os所输出。

有了这个类，就无需在各个类中定义自己的print函数，借助这个类即可实现。

```C++
class A{
 	public:
    	A(ostream& os):os(os){}
        template<typename T>
        void print(const T&val,char sep = '\n'){
            os << val << sep;
        }
    private:
    	ostream& os; //意味着必须初始化
}
A out(cout);
out.print("123"); // ok
out.print(123); // ok
```

当然这个A类还可以进一步模板化，这意味os被模板化，可以传入各式各样的os。

```c++
template<typename Ostream>
class A{
 	public:
    	A(Ostream& os):os(os){}
        template<typename T>
        void print(const T&val,char sep = '\n'){
            os << val << sep;
        }
    private:
    	Ostream& os; //意味着必须初始化
}
A<ostream> out(cout);
out.print("123"); // ok
out.print(123); // ok
```

## 七、异常处理

### 7.1 抛出异常

异常是某种对象，最简单的异常可以设计为整数或者字符串。

```c++
throw 43;
throw "panic:no buffer!";
```

也可以设计为异常类。

```c++
class iterator_overflow{
    public:
    	iterator_overflow(int idx,int max):idx(idx),max(max){}
    	int index(){return idx;}
    	int getmax(){return max;}
    	void what_happend(ostream &os =cerr){
            os<<...<<endl;
        }
    private:
    	int idx;
    	int max;
}
```

### 7.2 捕获异常

类似于这样的写法。

```c++
try{...}
catch (int e){...}
catch (const char* e){...}
catch (iterator_overflow &iof){iof.what_happend();throw;}//可以重新抛出异常,让其他catch语句接手
```

### 7.3 提炼异常

语句要被放置在合适的try块内，否则如果语句异常，而他不在try块内，很可能异常不能被捕捉到，这样C++会要求terminate()函数来处理这个异常。

同时要注意局部资源管理，下面这样的写法不能保证资源被回收，可能process会出现异常。

```c++
extern Mutex m;
void f(){
    int *p = new int;
    m.acquire();
    process(p);
    
    m.release();
    delete p;
}
```

应当导入try块处理和捕捉异常再将其抛出。

```c++
void f(){
    try{
        int *p = new int;
        m.acquire();
        process(p);
        m.release();
        delete p;
    }
	catch(...){
        m.release();
        delete p;
    }
}
```

但是这样的写法会导致代码重复，同时再次抛出异常的操作会导致程序变复杂，异常处理程序搜寻时间变长。

更好的做法是定义一个专属异常管理类。

```c++
#include <memory>
extern Mutex m;
class MutexLock{
    public:
    	MutexLock(Mutex m):lock(m){lock.acquire();}
    	~MutexLock(){lock.release;}
    private:
    	Mutex &lock;
}
void f(){
    auto_ptr<int> p(new int);//智能指针自动管理
    MutexLock m1(m);//管理这个资源
    process(p);
}//程序结束后MutexLock会自动释放那些资源
```

### 7.4 标准异常

如果new不能分配空间，那么会抛出bad_alloc异常，bad_alloc是个class而不是object。

标准库定义了一套异常类体系，根部都是exception的抽象基类，它声明了一个what虚函数，返回一个const char *，用于被抛出异常的文字描述。bad_alloc继承自它，有自己的what函数，定义在头文件< exception>。

定义自己的类最好继承exception，好处是可以被任何打算捕获抽象基类的exception的程序代码所捕获。所以捕捉异常可以这样写。

```c++
catch (const exception&e){
	cerr<<e.what()<<endl;
}
```

它可以捕获所有exception的派生类的异常，因为是引用，符合动态绑定的要求。

## 八、泛型参考手册

### accumulate元素累加

默认情况会将容器内的元素累加，第三个参数作为初值。

```c++
#include <numeric>
res = accumulate(ia,ia+8,10);
res = accumulate(ia.begin(),ia.end(),10,plus<int>());//传入二元运算
```

### adjacent_difference相邻元素差额

产生一个新数列，它的第一个元素是原来数列的元素，后面的每个元素都是原来数列对应位置元素与前一个的差值。

例如{0,1,1,2,3,5,8}会得到{0,1,0,1,1,2,3}，也可传入二元运算，例如乘法，就会得到{0,0,1,2,6,15,40}。

```c++
#include <numeric>
adjacent_difference(ia.begin(),ia.end(),res.begin());//res是目标容器
adjacent_difference(ia.begin(),ia.end(),res.begin(),multiplies<int>());
```

### adjacent_find搜索相邻重复元素

默认会返回指向第一组相邻且重复的元素的第一个的迭代器，也可以使用二元运算符。

```c++
#include <algorithm>
class TwiceOver{
    public:
    	bool operator()(int val1,int val2){return val1==val2/2?true:false;}
};
iter = adjacent_find(ia,ia+8);
iter = adjacent_find(vec.begin(),vec.end(),TwiceOver());//第一组倍增的元素(4,8)
```

### count计数

返回容器和指定值相等的元素个数

```C++
#include <algorithm>
int cnt = count(vec.begin(),vec.end(),value);
```

### binary_search二叉搜索

假设处理对象已经以less_than运算符处理过，也就是升序序列，就可以使用该方法，否则要指定第三个参数。

```C++
#include <algorithm>
bool it = binary_search(v.begin(),v.end(),value,greater<int>());
```

### copy复制

把第1个容器的值赋值到第2个容器。

```c++
#include <algorithm>
ostream_iterator<int> os(cout," ");
copy(v.begin(),v.end(),os);
vector<int> tar(v.size());
copy(v.begin(),v.end(),tar.begin());
```

### copy_backward逆向复制

行为相同，但从右边到坐标依次复制v的每个值到tar的右边。

```c++
#include <algorithm>
vector<int> tar(v.size());
copy_backward(v.begin(),v.end(),tar.begin());
```

### count_if特定条件下计数

返回满足某个条件的元素的计数。

```c++
#include <algorithm>
class Even{
	public:
    	bool operator()(int val){return !(val%2);}//偶数返回true
}
int cnt = count_if(ia,ia+8,bind2nd(less<int>(),10));//小于10的
cnt = count_if(v.begin().v.end(),Even());//偶数的
```

### euqal判断是否相等

若两容器元素值都相等返回true，第二列元素多的话多出来的不考虑，默认使用equality，但也可以使用其它函数对象或函数指针。

```C++
#include <algorithm>
class other{
    public:
    	bool operator()(int v1,int v2){return (v1==v2)&&(v1%2);}//v1==v2且v1是奇数
}
int a[]={1,1,2,3,5,8,13};
int b[]={1,1,2,3,4,8,13,21,34};
bool res = equal(a,a+7,b);//true
res = equal(a,a+7,b,other());//false
```

### fill填充值

```c++
#include <algorithm>
fill(v.begin(),v.end(),value);
```

### fill_n填充n次

将容器一一设为某个值，只设定n个元素。

```c++
#include <algorithm>
fill_n(a,n,value);
fill_n(a.begin(),n,value);
```

### find搜索

和特定值比较，返回找到的第一个元素迭代器，否则返回end()

```c++
#include <algorithm>
iter =find(a,a+8,value);
iter = find(a.begin(),a.end().value);
```

### find_end搜索某个子序列最后一次出现地点

接受两组迭代器，第一组表示搜索范围，第二组是要搜索的子序列，成功返回b，不成功返回a+7。

```c++
#include <algorithm>
int a[] ={7,3,3,7,6,5,8,3,7,6};
int b[] = {3,7,6};
it = find_end(a,a+7,b,b+3);
```

### find_first_of搜索某些元素首次出现地点

也是两组迭代器，找到就返回那个位置，没找到也是返回end。

```c++
#include <algorithm>
string a[]={"Ee","eE","ee","Oo","oo","ee"};
string b[]={"oo","gg","ee"};
it = find_first_of(a,a+6,b,b+3);//返回&a[2]
```

### find_if特定条件搜索

传递给定的二元运算符即可，没找到返回end。

```c++
#include <algorithm>
find_if(v.begin().v.end(),greater_than(int)());
```

### for_each对范围内的第一个元素应用某个曹祖

第三参数表示应用于每个元素的运算，不得更改元素值，需要更改值使用transform，指定的运算有返回值就会被忽略。

```c++
#include <algorithm>
template<typename T>
void print_elements(T elem){cout<<elem<<" ";}
for_each(v.begin(),v.end(),print_elements);
```

### generate以指定操作填充元素

```c++
#include <algorithm>
class op{
    public:
    	void operator()(){static int seed=-1;return seed+=2;}
}
vector<int> v(6);
generate(v.begin(),v.end(),op);//[1,3,5,7,9,11]
```

### includes涵盖于

若第二序列每个元素都在第一序列，返回true。两个序列都必须事先经过排序，排序可以使用less_than(默认)

```c++
#include <algorithm>
int a[]={1,2,3,4};
int b[]={2,3};
bool res = includes(a,a+4,b,b+2);//true
```

### inner_product内积

两个序列相乘并累加，再加上某个初始值。允许回避默认的累加和相乘行为，也可以先相加再相减。

```c++
#include <algorithm>
int a[] = {2,3,5,8};
int b[]={1,2,3,4};
int res = inner_product(a,a+4,b,0);//2+6+15+32
res = inner_product(a,a+4,b,0,minus<int>(),plus<int>());
```

### inplace_merge合并并取代

接受三个迭代器，fist、middle和last，2个输入序列表示为[first,middle)和[middle,last)。这2个序列必须连续，产生的新序列会覆盖原有内容，并以first为起点开始放置，第四参数可以指定less_than以外的比较操作。

```c++
#include <algorithm>
int a[8]={4,3,2,1,8,7,6,5};
int *mid = a+4,*last=a+8;
sort(ia,mid);sort(mid,last);
inplace(ia,middle,last);
```

### iter_swap元素呼唤

将两个迭代器指向的值交换。

```c++
#include <algorithm>
typedef list<int>::iterator iter;
iter it1=v.begin(),it2=v.begin()+4;
iter_swap(it1,it2);
```

### lexicographical_compare以字典排列方式比较

默认使用less_than进行排序，若设定第五参数，可指定其它排序方式。若第一序列小于第二序列就返回true。

```c++
#include <algorithm>
class op{
    public:
    	bool operator()(const string&a,const string&b){return a.length()<=b.length();}
};
string a[]={"A","BB","CCC"};
string b[]={"A","BBC","CCC"};
res = lexicographical_compare(a,a+3,b,b+3,op);//true
```

### max&min 最值

```c++
#include <algorithm>
int r = max(3,4);//4
```

### max_element&min_element最值所在处

```c++
#include <algorithm>
iter = max_element(v.begin(),v.end());
```

### merge合并两个序列

将已排序的2个序列合并为1个，结果已排序。

```c++
#include <algorithm>
int a[]={3,2,1};
int b[]={9,8,7};
vector<int> c(3);
merge(a,a+3,b,b+3,c.begin(),greater<int>());
```

### nth_element重排序列第n个元素左右两端

小于第n个元素的都在前边，大于第n个元素的都在后边，但不保证结果有序。

```c++
#include <algorithm>
int a[]={1,4,5,6,7,-2,9};
nth_element(a,a+7,&a[3]);//小于6的
```

### partial_sort&partial_sort_copy局部排序(复制到它处)

partial_sort有三个参数，first、mid和last，第四个指定排序方式，partial_sort_copy还会多2个参数存放排序结果

```c++
#include <algorithm>
int a[]={4,3,2,1,0};
partial_sort(a,a+3,a+5);//序列前3个元素被排序,后边不一定[2,3,4,1,0]
```

### partial_sum局部总和

产生新序列，每个元素都是对应为止元素和前边所有元素的和。

```c++
#include <algorithm>
int a[]={1,2,3};
int res[3];
partial_sum(a,a+3,res);//目标
```

### partion&stable_partion切割(并保持元素相对排序)

```c++
#include <algorithm>
int a[]={1,2,3,4,5};
stable_partion(a,a+5);
```

### random_shuffle随机重排

```c++
#include <algorithm>
random_shuffle(v.begin(),v.end());
```

### remove&remove_copy移除某种元素(并复制)

```c++
#include <algorithm>
int a[]={1,2,3};
vector<int> v(a,a+3);
iter = remove(v.begin(),v.end(),1);
int b[3];
remove_copy(a,a+3,b,0);
```

### remove_if&reomve_copy_if有条件移除某种元素(并复制)

```c++
#include <algorithm>
class op{
    public:
    	bool operator()(int v1,int v2){return (v1==v2)&&(v1%2);}//v1==v2且v1是奇数
}
int a[] = {1,2,3};
int b[3];
remove_copy_if(a,a+3,op);
```

### replace&replace_copy取代某种元素(并复制)

```c++
#include <algorithm>
int a[] = {1,2,3};
replace(a,a+3,oldval,newval);
int b[3];
replace_copy(a,a+3,inserter(r,r.begin()),oldval,newval);//替换到r容器
```

### replace_if&replace_copy_if有条件取代(并复制)

```c++
#include <algorithm>
int a[] = {1,2,3};
replace(a,a+3,bind2nd(less<int>(),10),newval);
```

### reverse&reverse_copy反转元素(并复制)

```c++
#include <algorithm>
int a[] = {1,2,3};
int b[3];
reverse(a,a+3);
reverse_copy(a,a+3,b);
```

### rotate&rotate_copy旋转(并复制)

```c++
#include <algorithm>
int a[] = {1,2,3,4,5,6,7};
int b[7];
rotate(a,a+3,a+7);
rotate(a,a+3,a+7,b);
```

### search搜索某个子序列

寻找第2个序列在第1个序列首次出现的位置。

```c++
#include <algorithm>
int a[] = {1,2,3,4,5,6,7};
int b[] ={4,5,6};
search(a,a+7,b,b+3)
```

### search_n 搜索连续发生n次的子序列

```c++
#include <algorithm>
int a[] = {1,2,3,4,5,6,7,1,2,3};
int b[]={1,2,3};
int * p = search_n(a,a+10,2,b);
```

### set_difference差集

出现在第一序列但是没出现在第二序列的元素。

### set_intersection交集

两个序列都出现的元素。

### set_symmetric_difference对称差集

出现在第一序列但是没出现在第二序列的元素，以及出现在第二序列但是没出现在第一序列的元素都拿出来，然后排序取出。

例如{0,1,2,3}h额{0,2,4,6}的对称差集是{1,3,4,6}。

### set_union并集

产生的序列包含原有2个序列的所有元素，去重并排序。

```c++
#include <algorithm>
string str1[] = {"A","B","C"};
string str2[] = {"B","C","D"};
set<string> set1(str1,str1+3),set2(str2,str2+3);
set<string> res;
set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(res,res.begin()));
res.clear();
set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(res,res.begin()));
res.clear();
set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(res,res.begin()));
res.clear();
set_symmetric_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(res,res.begin()));
```

### sort&stavle_sort(稳定)排序

稳定排序可以保持相同元素的相对次序。

```c++
#include <algorithm>
stable_sort(a,a+8,greater<int>());
```

### transform以两个序列为基础交叉作用生成第三个序列

调用某个运算作用在容器的每个元素上。

```c++
#include <algorithm>
int double_val(int val){return val+val;}
int difference(int val1,int val2){return abs(val1-val2);}
transform(a,a+5,res.begin(),double_val);
transform(a,a+5,res.begin(),difference);
```

### unique&unique_copy去重(并复制)

unique不适用于数组，因为提供了erase函数。unique_copy适合数组。

```c++
#include <algorithm>
sort(a.begin(),a.end());
iter = unique(a.begin(),a.end());
a.erase(iter,a.end());

int b[5];
sort(a,a+5);
unique_copy(a,a+5,b);
```



正式完结撒花~2022年3月30日上午8.30，这本书比EffectiveC++稍晚几天看完，比这本书要简单一些，下一本书就是STL源码剖析了。这本书重点在于熟悉STL的使用，原理的话掌握基本说法就可以，毕竟这玩意会了不看也得忘。
