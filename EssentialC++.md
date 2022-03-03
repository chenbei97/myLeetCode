## 一、C++编程基础

### 什么是命名空间？

命名空间是一种将库名称封装起来的办法，通过这种方法可以避免和应用程序发生命名冲突的问题。例如想使用cin和cout对象需要包含头文件< string >和< iostream>的同时，必须使用标准命名空间std。

### 为何要允许构造函数语法？

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

### 运算符的优先级

只列举常见的运算符，最高的优先级是非，也就是!；

最低的优先级是赋值运算符，也就是=；

其次较高优先级的运算符为算术运算符的乘除，然后加减；

再其次是关系运算符，大于、小于，大宇等于和小于等于，这4个优先级比关系运算符==和!=高；

最后是逻辑运算符，&&优先级高于||。

```c++
[!] => [*,/] => [+,-] => []>,<,>=,<=] => [==,!=] => [&&] => [||] => [=] 
```

  ### switch语句加break的原因?

因为不加break，case语句和小括号内的表达式值匹配后 ，在这条case语句后面的所有case语句都会执行，所以为了只执行1条语句，即多选一的逻辑需要加break语句。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

### for循环的三个组成部分

其中condition部分是循环开始之前被计算出来，如果不满足条件，1次也不会执行。

expression部分是在循环结束之后被计算出来。

```c++
for( init_statement ; condition ; expression)
    statement;
```

### ++i和i++的区别

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

### srand与rand

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

### 输入输出流 fstream

需要包含头文件，fstream，其内部包含输入流和输出流的类。

#### 输出流ofstream

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

#### 输入流ifstream

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

### cerr和cout的区别？

cerr代表标准错误设备(standard error)，和cout一样可以将输出结果定向到用户终端。唯一i的差别是cerr对的输出结果没有缓冲情形，会立即显示于用户终端。

## 二、面向过程的编程风格

### 如何编写函数？

函数需要4个部分，返回类型、函数名、参数列表和函数体。其中返回类型、函数名、参数列表又构成了函数原型，它可以在编译阶段让机器明白这个函数有多少参数，输入和返回类型是否正确等。

一个函数可能因为输入的数字返回错误的结果，例如某些数列不存在第0个位置，这样需要对参数设置一些控制。当参数不满足条件时可以抛出异常，也可以使用exit()函数终止，必须传1个值给exit，这个值是程序结束时的状态值，exit()函数在< stdlib.h>库中。

### 某个数据类型的最小最大值

一个函数的参数很可能超过该数据类型的限制，可以引入头文件< limits>查找。

```c++
#include <limits>
int max_int = numeric_limits<int>::max();
double min_dbl = numeric_limits<double>::min();
```

 ### 调用函数程序的行为?

调用1个函数时弧在内存中建立起一块特殊区域，称为"程序堆栈"，这块区域提供了每个函数参数需要的储存空间，它也提供了函数内部所定义的每个对象的内存空间，这些对象称为局部对象，一旦函数完成这个内存会被释放掉，即从程序堆栈中被pop出来。

### 引用传递

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

### 地址传递

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

### 动态内存管理

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

 ### 提供默认参数值

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

### 使用inline函数

一个函数可以拆成多个独立的小函数，这样可以增加函数的可读性和复用性。但是想实现一个功能从调用1个函数变成调用3个函数才能实现，这成了一个缺点。

这样的缺点可以使用inline解决，如果函数A调用了2个函数B、C，A声明为inline以后，**编译器就会将函数的调用操作改为一份函数代码副本**，这可以让性能得到一些改善，但是这适用于B、C的函数代码比较简单，否则不一定可以改善性能。

另外inline只是像编译器申请而不是强制性的，inline函数的定义一般放在头文件中，且定义必须是有效的，因为编译器必须在函数被调用的时候加以展开。

### 使用重载函数       

只需要知道，同名函数可以以参数列表的个数或者参数类型不同来重载，但不能以返回类型重载。

### 使用模板函数

如果重载函数的参数个数、名称和参数相对位置没有变化，且函数主体的代码没有变化，只有参数的类型不同时就可以使用模板来替代重载，关键字为class或者typename。模板函数还可以进一步重载，如vector改为list也是可以的。                                                                                                                    

```c++
template<typename T>
void print_message(const string &msg, vector<T> &vec);

template<typename T>
void print_message(const string &msg, list<T> &vec);
```

模板函数出现的目的是：如果一个函数需要被不同的函数调用，例如这个函数的功能是打印一段信息，不同的函数可能打印的信息数据类型不同，那这个函数需要用不同类型的参数声明。

如果那些调用它的函数具备的参数形式相似，这个输出信息的函数可能只需要函数模板就可以解决。例如函数A、B、C的参数只有1个且分别为int、double和string，那么输出函数为模板函数就可以同时为A、B、C函数使用，减少代码的重复性。

### 函数指针的妙用

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

### 设定头文件

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

### extern变量的使用

分3个情况来说明：

外部变量在本文件定义：该全局变量的作用域从变量的定义开始到文件末尾，如果在定义之前有函数引用了这个全局变量，就会报未定义标识符的错误，所以可在调用之前先声明这个变量为外部的，那么编译器就会优先从本文件去寻找，如果没找到，会在同一目录下的文件寻找。全局函数和全局变量的含义类似，如果在调用前没有声明过也会报错，同样可以使用extern+函数原型的办法去声明，本文件找不到就去其他文件寻找。

外部变量在其他文件定义：假如A文件定义了全局变量a=10，在B文件声明a为外部变量后，打印a的值就是10，因为B优先从B文件寻找没找到就会从其它文件寻找，在A文件可以找到。但是B文件不能再次定义a=5，无论在B文件的哪个位置定义，记住定义只能有一次。

外部变量在头文件定义：唯一的区别是，因为头文件可以被多次包含，这个外部变量可以在任何文件中被首次定义，但是一经定义，其他文件不能够再定义，只能够使用。所以如果非必要，不是常量表达式/数组的话不要在头文件中定义全局变量/外部变量。

## 三、泛型编程风格

标准库STL由两部分组成，一个是容器container，包括顺序性容器vector和list和关联性容器set、map等，一个是算法，包括find、sort、replace和merge等通用算法。

map是key/value组合，也可以叫字典、哈希表等；set是只有关键字，且不重复，也可以用于查询。

### 指针的算术运算

 问题：给定vector或者array，查找指定的元素值并返回它的地址。

#### 容器元素泛型

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

#### 连续容器类型泛型

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

#### 连续容器首尾指针泛型

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

#### 非连续容器类型泛型

线性容器很容易找到首尾指针，是因为内存是一段连续的地址，如果是链表，例如list容器，又该如何更改find函数呢？链表是不连续的，还有关联容器map和set，不仅非连续也不是线性的。这就需要引入泛型指针iterator的概念，也就是迭代器。

### 泛型指针Iterator

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

 #### 泛型指针的运算符操作泛型

现在有了泛型指针，find函数的通用性非常高。还需要考虑指针的运算符重载操作，运算符重载可以默认使用STL内部给出的方式，也可以让用户传入自己定义的运算方式，所以这个问题如果能解决泛型的问题，find函数通用性会大大增加，这将在第四章说明。STL提供的find_if函数能够接收函数指针或者函数对象来取代底部元素的==/!=运算符。

### 容器的共通操作

先介绍容器的共通操作，再介绍各个容器自己独有的操作，第四章再回过头讲泛型。

通用操作，实际上定义在抽象类，也就是empty、size、clear，insert、erase等函数，赋值运算符=，关系运算符!=和==，同时每个容器类都提供begin()和end()迭代器。

不过insert和erase在顺序性和关联性容器的实现上略有不同。

### 使用顺序性容器

#### vector容器

删除和插入操作效率低，因为需要覆盖操作，尾删和尾插效率尚可。随机访问元素效率很高，因为只需要做一次指针运算即可。

#### list容器

双端链表，删除和插入的效率高，因为每个元素都有三个字段，front、back和value，即指向前后元素的指针以及真正的数据value。插入和删除操作只需要衔接好或者断开节点的指针和前后节点的指针即可。

#### queue容器

单端队列，先进先出的数据结构，可以删除和获取队首元素，插入到队尾元素。但是获取中间的元素效率比较低，需要迭代器。

#### deque容器

双端队列，可以头插，也可以尾删，那么deque的效率很高。

#### 常用构造函数

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

#### 常用函数

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

### 使用泛型算法

find函数，搜索无序集合是否存在指定元素，找到目标返回指向目标的迭代器，否则返回end()；

binary_search函数，用于有序集合搜索，找到目标返回true否则false，比find更有效率；

count函数，返回指定元素的数目；

search函数，比对某个容器是否存在某个子序列，找到则会返回一个指向子序列首位的迭代器，否则返回end()；

max_element函数，将容器的begin和end传入，会返回最大值的指针，解引用即可得到最大值；

copy函数：指定容器的begin和end，另一个容器的begin，就可以复制过去；

sort函数：传入begin和end，就可以进行排序(升序)。

### 设计一个泛型算法

​                                                                                                                                                                                                                                                                                                                                                                                                                                                         

### 使用关联性容器





​                                                                                                                                                                                                                                                 






