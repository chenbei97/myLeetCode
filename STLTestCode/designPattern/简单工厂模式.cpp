/*
 * @Author: chenbei
 * @Date: 2022-06-27 11:44:53
 * @LastEditTime: 2022-06-27 11:45:38
 * @FilePath: \\myLeetCode\\STLTestCode\\designPattern\\简单工厂模式.cpp
 * @Description: 简单工厂模式
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
            case  types::Orange:fruit = new Orange(); break;
            case  types::Banana:fruit = new Banana(); break;
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
