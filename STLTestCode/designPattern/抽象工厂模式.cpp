/*
 * @Author: chenbei
 * @Date: 2022-06-27 11:45:58
 * @LastEditTime: 2022-06-27 11:46:22
 * @FilePath: \\myLeetCode\\STLTestCode\\designPattern\\抽象工厂模式.cpp
 * @Description: 抽象工厂模式
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
using namespace std;
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
class AbstractFruitsFactory {public:
    virtual Fruit* createApple() const = 0;
    virtual Fruit* createBanana() const = 0;
    virtual Fruit* createOrange() const = 0;
};                
class eastFactory: public AbstractFruitsFactory {
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
class westFactory : public AbstractFruitsFactory {
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
    eastFactory fac1; // 西部or东部工厂
    westFactory fac2;
    eastApple * apple = fac1.createApple();
    westOrange* orange = fac2.createOrange();
    apple->what_am_i();
    orange->what_am_i();
    return 0;
}
