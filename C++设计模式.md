## 一、简单工厂模式

1、业务类和界面类分开。

以计算器为例，可以直接根据客户输入的代码然后写一堆代码进行计算，直接得到结果；也可以将计算的代码封装为一个类，客户输入和获取结果的代码作为一个类，这样提高复用性。因为计算的操作还可以提供给别的场景进行使用。

```C#
public class Operation{
    public static doublr getResult(double num1,double num2,string operate){
        double res = 0d;
        switch(operate){
            case "+":
                res = num1+nums2;
                break;
            case "-":
                res = num1 - num2;
                break;
            case "*":
                res = num1*nums2;
                break;
            case "/":
                res = num1 / num2;
                break;
        }
        return res;
    }
}

static void Main(string[] args){
    try{
        Console.Write("please input num1: ");
        string num1Str = Console.ReadLine();
        Console.Write("please input operation(+,-,*,/): ");
        string optStr = Console.ReadLine();
        Console.Write("please input num2: ");
        string num2Str = Console.ReadLine();
        string res = "";
        res = Convert.ToString(Operation.getResult(Convert.ToDouble(num1Str),Convert.ToDouble(num2Str),optStr));
        Console.Write("output = "+res);
        Console.ReadLine();
    }
    catch(Exception ex){
        Console.WriteLine("input is invalid "+ex.Message());
    }
}
```

2、使用多态和继承来实现松耦合

抽象基类只提供2个私有成员代表2个数，一个虚方法getResult，各类操作具体类的实现通过继承抽象基类的接口函数来实现。这样即使增加一个新操作，例如开根、求幂计算等，并不会影响其它类。

```c#
public class Operation{//抽象基类
    private double num1 = 0;
    private double num2 = 0;
    public double getAndSetNum1(){
        get{return num1;}
        set{num1 = value;}
    }
    public double getAndSetNum2(){
        get{return num2;}
        set{num2 = value;}
    }
    public virtual double getResult(){
        double res = 0;
        return res;
    }
}
// 4个具体类
class OperationAdd:Operation{
    public override double getResult(){
        double res = 0;
        res = num1 + num2;
        return res;
    }
}
class OperationSub:Operation{
    public override double getResult(){
        double res = 0;
        res = num1 - num2;
        return res;
    }
}
class OperationMul:Operation{
    public override double getResult(){
        double res = 0;
        res = num1 * num2;
        return res;
    }
}
class OperationDiv:Operation{
    public override double getResult(){
        double res = 0;
        if (num2 == 0)
            throw new DivsionZeroException;
        res = num1 / num2;
        return res;
    }
}
```

3、简单工厂模式。提供一个类来决定实例化的对象是何种运算(用户提供这个参数)，这个类来负责做这个实例的构造过程，也就是工厂的实现类，上边的Operation是接口类。

```c#
public class OperationFactory{
    public static Operation createOperate(string operate){
        Operation oper = null; //基类对象动态绑定为指定的子类对象
        switch{
            case "+":
                oper = new OperationAdd();
                break;
            case "-":
                oper = new OperationSub();
                break;
            case "*":
                oper = new OperationMul();
                break;
            case "/":
                oper = new OperationDiv();
                break;
        }
        return oper;
    }
}
// 客户端的使用方式
Operation oper;
oper = OperationFactory.createOperate("+");
oper.num1 = 1;
oper.num2 = 2;
double res = oper.getResult();
```

4、如何看UML类图

① 矩形框代表1个类。第一行文字表示类的名称，如果是斜体就表示我抽象类；第二行文字表示类的特性，即字段和属性；第三行文字为类的操作，即提供的方法。文字最前边会有三个符号，"+"代表public，"-"表示private，"#"表示protected。

矩形框第一行文字顶端如果带有"<<interface>>"就表示一个接口图，第一行文字依然表示接口名称；第二行文字是接口方法。

矩形框第一行文字和棒棒糖符号相连，也表示一个接口，第一行、第二行文字的含义相同。

② 继承关系使用空心三角+实现来表示，从派生类指向基类。

③ 实现接口使用空心三角+虚线来表示。

④ 关联关系使用实线箭头来表示，例如大雁飞翔与气候有关。

⑤ 聚合关系使用空心菱形+实线箭头来表示，从小概念指向更大的概念，例如大雁和雁群。

⑥ 组合关系用实心菱形+实线箭头来表示，被组合的指向组合，例如鸟与翅膀的关系。

依赖关系使用虚线箭头表示，倚赖者指向依赖物，例如大雁依赖氧气和水。

## 二、策略模式

1、**具有相同属性和功能的对象的抽象集合才是类**。

打折问题中，打一折打两折本质都是打折问题，所以不要单纯的使用简单工厂模式，反复添加各种折数的子类，而应都统一成打折类，提供打折参数；如果有满返的活动也相同，返利多少本质上都是返利，提供返利的参数即可。

现在无论添加什么样的活动，只需要修改抽象类的工厂函数即可(所以这也是简单工厂模式的问题)。

```c#
abstract class cashSuper{ // 超市收钱的抽象类
    public abstract double acceptCash(double money);//抽象方法,类似虚函数
}
class cashNormal : cashSuper{ // 正常收费子类
    public override double acceptCash(double money){
        return money;//原价返回
    }
}
class cashFactory{ // 现金收费工厂类
    public static cashSuper createCashAccept(string type){
        cashSuper cs = null;
        switch (type){
            case "正常收费":
                cs = new cashNormal();
                break;
            case "满300返100":
                CashReturn cr1 = new cashReturn("300","100");
                cs = cr1;
                break;
            case "打八折":
                cashRebate cr2 = new cashRebate("0.8");
                cs = cr2;
                break;
        }
        return cs;
    }
}
class cashRebate : cashSuper{ // 打折收费子类
    private double moneyRebate = 1d;//打折率
    public cashRebate(string moneyRebate){
        this.moneyRebate = double.Parse(moneyRebate);//初始化折扣率
    }
    public override double acceptCash(double money){
        return money * moneyRebate;//打折返回
    }
}
class cashReturn : cashSuper{ // 满返收费子类
    private double moneyCondition = 0.0d;//满多少
    private double moneyReturn = 1d;//返多少
    public cashReturn(string moneyCondition,string moneyReturn){
        this.moneyCondition = double.Parse(moneyCondition);
        this.moneyReturn = double.Parse(moneyReturn);//初始化
    }
    public override double acceptCash(double money){
        double res = money;
        if (money >= moneyCondition)
            res = money - Math.Floor(money / moneyCondition) * moneyReturn;
        return res;//满减返回
    }
}
```

2、使用策略模式，即定义算法家族分别封装起来，让它们可以相互替换。

如果商场打折活动的方式经常需要改变，如更改打折额度，满返的额度发生变化，亦或者添加了新类型的活动，例如买东西可以积累积分，满多少可以换取奖品，这就可能需要经常性的更改工厂类。

策略模式的好处可以在算法发生变化时，不会影响客户的使用。**与简单工厂模式的不同在于，工厂模式直接生成算法对象，策略模式则是提供，所有支持的算法的公共接口**，具体策略类则是继承接口类封装具体的算法。

```c#
abstract class Strategy{ // 提供支持的算法的公共接口,抽象基类
    public abstract void algorithmInterface();// 算法函数
}
class concreteStrategyA:Strategy{ // A类方法
    public override void algorithmInterface(){
        ...
    }
}
class concreteStrategyB:Strategy{ // B类方法
    public override void algorithmInterface(){
        ...
    }
}
class concreteStrategyC:Strategy{ // C类方法
    public override void algorithmInterface(){
        ...
    }
}
```

Strategy类的实例化取决于派生类，这个实例最好单独使用一个类去管理，即该实例作为类的属性。

```c#
class Context{
    Strategy strategy;
    public Context(Strategy strategy){ //构造函数传入具体的策略对象,A,B,C类实例
        this.strategy = strategy;
    }
    public void contextInterface(){
        strategy.algorithmInterface();//调用策略的算法方法
    }
}
// 客户端的使用方式
static void Main(string[] args){
    Context context;
    context = new Context(new concreteStrategyB());//使用B类的方法
    context.contextInterface();//调用方法
    
    context = new Context(new concreteStrategyC());//使用C类的方法
    context.contextInterface();//调用方法
    
    Console.Read();
}
```

3、策略模式的实现。

现在回看打折问题，cashSuper超市收钱的抽象类其实就可以看成一种抽象策略，而不是简单的工厂。正常收费、打折收费和满返收费的模式都看成是一种具体的策略，不要看成是工厂出来的算法具体对象。如果能够让具体的算法和工厂分开，也就是工厂不直接和这些算法进行耦合打交道，就不会因为算法的变化来让工厂发生变化。

具体的实现是让现金收费工厂具体类cashFactory的功能移动到界面上，例如界面的某个按钮点击回调函数，并取缔cashFactory类。同时**使用一个类直接管理cashSuper抽象策略类对象，而不是借助工厂具体类去直接实现抽象类的接口函数，本质上就是对抽象类再加一层抽象**。

cashSuper、cashNormal、cashRebate、cashReturn都不需要修改，cashFactory被取缔，其功能由一个客户端的回调函数完成，增加一个管理cashSuper的类cashContext。

现在如果增加新的策略，只需要更改客户端的回调函数，其它策略具体类、管理策略的类都无需改变

```c#
class cashContext{
    private cashSuper cs;//管理的抽象基类对象
    public cashContext(cashSuper cs){
        this.cs = cs;//构造函数
    }
    public double getResult(double money){
        return cs.acceptCash(money);//cs是策略
    }
}
// 客户端代码
private void btnOk_Click(object sender,EventArgs e){ 
    // 一个界面的回调函数,点击按钮ok就执行本函数
    cashContext cc = null;//管理对象
    switch (Bar.SelectedItem.ToString()){ // 下拉项对应不同的策略
        case "正常收费":
            cc = new cashContext(new cashNormal());
            break;
        case "满300返100":
            cc = new cashContext(new cashReturn("300","100"));
            break;
        case "打8折":
            cc = new cashContext(new CashRebate("0.8"));
            break;
    }
}
double totalPrices = 0d;
totalPrices = cc.getResult(Convert.ToDouble(txtPrice.Text)*Convert.ToDouble(txtNum.Text)); // 得到该策略要支付的金额  
```

4、策略与简单工厂的结合

上述方法虽然在添加新策略时无需重新编译其它策略类和管理策略的类，但是要重新编译客户端代码。现在希望把switch判断语句转移走，让客户端也是一种抽象逻辑，所以可以考虑把这段代码放到管理策略对象的类cashContext中。

客户真正需要了解的从原来简单工厂模式的2个类cashSuper和cashFactory，只需要认识1个类cashContext，客户不会知道cashSuper以及各类具体策略的实现和接口。

```c#
// 改进的cashContext
class cashContext{
    cashSuper cs = null;
    public cashContext(string type){ // 收费类型而不是具体的收费策略
        switch (type){
        	case "正常收费":
            	cashNormal cn = new cashNormal();
                cs = cn;
            	break;
        	case "满300返100":
            	cashReturn cr1 = new cashReturn("300","100");
                cs = cr1;
            	break;
        	case "打8折":
            	CashRebate cr2 = new CashRebate("0.8");
                cs = cr2;
            	break;      
        }
    }
    public double getResult(double money){
        return cs.acceptCash(money);
    }
}
// 客户端代码更抽象的改进
private void btnOk_Click(object sender,EventArgs e){ 
    cashContext cs = new cashContext(Bar.SelectedItem.ToString());
	double totalPrices = 0d;
    totalPrices = cs.getResult(Convert.ToDouble(txtPrice.Text)
                               *Convert.ToDouble(txtNum.Text));
}
```

**策略模式可以以相同的模式调用所有的算法，减少各种算法类与使用算法类之间的耦合。**

**同时策略模式的优点是简化了单元测试，每个算法都有自己的类，可以通过自己的接口单独测试。**

**策略模式可以在客户端去除条件判断语句，将其转嫁给管理策略类的对象去实现。**

但是管理策略类的对象实现switch语句更改比较容易，代价也小，它的改动不会影响具体的策略类

如果能够继续消除管理策略类的类的条件判断，可以使用反射技术，这在抽象工厂模式章节提到。

## 三、单一职责原则



## 四、开放封闭原则



## 五、依赖倒转原则



## 六、装饰模式



## 七、代理模式



## 八、工厂方法模式



## 九、原型模式



## 十、模板方法模式



## 十一、迪米特法则



## 十二、外观模式



## 十三、建造者模式



## 十四、观察者模式



## 十五、抽象工厂模式



## 十六、状态模式



## 十七、适配器模式



## 十八、备忘录模式



## 十九、组合模式



## 二十、迭代器模式



## 二十一、单例模式



## 二十二、桥接模式



## 二十三、命令模式



## 二十四、职责链模式



## 二十五、中介者模式



## 二十六、享元模式



## 二十七、解释器模式



## 二十八、访问者模式



## 二十九、模式总结