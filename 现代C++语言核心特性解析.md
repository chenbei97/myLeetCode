<!--
 * @Author: chenbei
 * @Date: 2022-04-09 19:25:11
 * @LastEditTime: 2022-04-09 19:39:38
 * @FilePath: \myLeetCode\现代C++语言核心特性解析.md
 * @Description: 现代C++新特性
 * @Signature: A boy without dreams
-->
## 1. 新基础类型(C++11~C++20)

### 1.1 整数类型long long

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

### 1.2 新字符类型char16_t和char32_t

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

## 2.内联和嵌套命名空间(C++11~C++20)

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



## 3. auto占位符(C++11~C++17)



## 4. decltype说明符(C++11~C++17)



## 5. 函数返回类型后置(C++11)



## 6. 右值引用(C++11,C++17,C++20)



## 7. lambda表达式(C++11~C++20)



## 8.非静态数据成员默认初始化(C++11,C++20)



## 9. 列表初始化(C++11,C++20)



## 10. 默认和删除函数(C++11)



## 11. 非受限联合类型(C++11)



## 12.委托构造函数(C++11)



## 13.继承构造函数(C++11)



## 14. 强枚举类型(C++11,C++17,C++20)



## 15.扩展的聚合类型(C++17,C++20)



## 16.override和final说明符(C++11)



## 17. 基于范围的for循环(C++11,C++17,C++20)



## 18. 支持初始化语句的if和switch(C++17)



## 19.static_assert声明(C++11,C++17)



## 20. 结构化绑定(C++17,C++20)



## 21. noexcept关键字(C++11,C++17,C++20)



## 22. 类型别名和别名模板(C++11,C++14)



## 23. 指针字面量nullptr(C++11)



## 24.三向比较(C++20)



## 25. 线程局部存储(C++11)



## 26. 扩展的inline说明符(C++17)



## 27.常量表达式(C++11~C++20)



## 28.确定的表达式求值顺序(C++17)



## 29.字面量优化(C++11~C++17)



## 30. aligns和alignof(C++11,C++17)



## 31. 属性说明符和标准属性(C++11~C++20)



## 32. 新增预处理器和宏(C++17,C++20)



## 33. 协程(C++20)



## 34.基础特性的其他优化(C++11~C++20)



## 35. 可变参数模板(C++11,C++17,C++20)



## 36. typename优化(C++17,C++20)



## 37. 模板参数优化(C++11,C++17,C++20)



## 38. 类模板的模板实参推导(C++17,C++20)



## 39. 用户自定义推导指引(C++17)



## 40. SFINE(C++11)



## 41. 概念和约束(C++20)



## 42. 模板特性的其他优化(C++11,C++14)

