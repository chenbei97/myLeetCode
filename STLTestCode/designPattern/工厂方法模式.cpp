/*
 * @Author: chenbei
 * @Date: 2022-06-27 11:45:20
 * @LastEditTime: 2022-06-27 11:45:21
 * @FilePath: \\myLeetCode\\STLTestCode\\designPattern\\工厂方法模式.cpp
 * @Description: 工厂方法模式
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
using namespace std;
class Fruit {
public:
    virtual void what_am_i() { cout << "I am Fruit\n"; }// 缺省实现
};
class Apple : public Fruit {
public:
    void what_am_i() override  { cout << "I am Apple\n"; }
};
class Orange : public Fruit {
public:
    void what_am_i() override  { cout << "I am Orange\n"; }
};
class Banana : public Fruit {
public:
    void what_am_i() override { cout << "I am Banana\n"; }
};
class AbstractFruitsFactory {
    public:
        virtual Fruit* create() const = 0; // 纯虚函数,必须被继承定义
};
class appleFactory :public AbstractFruitsFactory{
public:
    // 这里还可以继续定义不同的苹果类型拓展,这4类苹果可以继承Apple
    // enum class appleType {northApple,southApple,eastApple,westApple};
      Fruit* create()  const override {
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
    Fruit* create() const override {
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
