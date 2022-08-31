#include <QtTest>
#include <QString>
// add necessary includes here
#include "area.h"
class TestArea : public QObject
{
    Q_OBJECT
public:
    TestArea();
    ~TestArea();
private slots: // slots函数会被QTest::qExec()自动调用
  void test_case1();
  void testToLower();
  void testToLower_data();
  void testArea();
  void testArea_data();
  void testBenchmark();
};

TestArea::TestArea()
{

}

TestArea::~TestArea()
{

}

void TestArea::test_case1() // （1）简单单元测试
{
    Area area(1.);
    QVERIFY(qAbs(area.countArea()-3.14) < 0.000000001);
    QVERIFY2(true,"Failture");
}

void TestArea::testArea() // （2）数据驱动测试
{
      QFETCH(Area,area);
      QFETCH(double, s);
      QVERIFY(qAbs(area.countArea()-s)<0.0000001);
      QVERIFY2(true,"Failure");
}

void TestArea::testArea_data()
{
       // 添加测试列
      QTest::addColumn<Area>("area"); // 模板T必须是元对象类型
      QTest::addColumn<double>("s");
      // 添加测试数据
      QTest::newRow("1")<<Area(1)<<3.141;
      QTest::newRow("2")<<Area(2)<<12.56;
      QTest::newRow("3")<<Area(3)<<28.26;
}

void TestArea::testToLower()
{
    QFETCH(QString,string);//创建1个类型QString的局部变量string
    QFETCH(QString,result);

    // 如果2个参数不同,值会分别显示出来
    QCOMPARE(string.toLower(),result); // 测试toLower函数
    QVERIFY2(true,"Failure");
}

void TestArea::testToLower_data() // 必须是同名,加个后缀即可给上边函数提供测试数据
{
      // 添加测试列
      QTest::addColumn<QString>("string");
      QTest::addColumn<QString>("result");
      // 添加测试数据
      QTest::newRow("lower")<<"hello"<<"hello"; //无论那种调用了toLower都是hello
      QTest::newRow("mixed")<<"heLLo"<<"hello";
      QTest::newRow("upper")<<"HELLO"<<"hello";
}

void TestArea::testBenchmark() // （3）简单性能测试
{
      QString str("HeLlO");

      QBENCHMARK // 测试性能
      {
          str.toLower();
      }
      QVERIFY2(true,"Failture");
}
QTEST_APPLESS_MAIN(TestArea)

#include "tst_testarea.moc"
