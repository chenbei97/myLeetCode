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
double totalPrices = 0d; // cc在点击按钮的回调函数中创建
totalPrices = cc.getResult(Convert.ToDouble(txtPrice.Text)
                           *Convert.ToDouble(txtNum.Text)); // 得到该策略要支付的金额  
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

1、**单一职责原则是指，一个类应当只有一个原因会引起它改变**。

2、开发一个产品，需要先构思类承担的职责，如果多于1个动机去改变它，就要考虑拆分这个类。

如果一个类有各种各样的功能，它是无法复用的，可维护性也差，任何变化都要去修改它。

## 四、开放封闭原则

1、**开放封闭原则是指，对软件实体(模块、类和函数)的拓展是开放的，对更改是封闭的**。

举例，弹性工作制就是对工作时间的修改关闭(早来早下班,晚到晚下班)，对时间制度扩展的开放。

2、尽可能的设计好一个类使之满足修改封闭，但是也要对可能发生的变化创造抽象来隔离。

例如第二章的策略模式中，使用了cashContext类管理策略类对象来应对可能发生的具体策略变化，并将这种变化封装在cashContext类的内部，与其它现有的策略类进行了隔离。

3、开发工作不久之后出现了变化，就及时采取措施进行抽象。

例如第一章的运算类对于加减乘除只在一个函数内条件判断完成功能就提示了这种变化，我们要及时的把各类运算都定义自己的类，而不是等到平方、开根、取余等运算都来了才去抽象。不过，**过早的抽象也没有意义，拒绝不成熟的抽象和抽象本身一样重要**。

## 五、依赖倒转原则

1、**依赖倒转原则是指：抽象不应倚赖细节，细节应该依赖抽象，或者说针对接口编程而不是实现**。

例如，无论是主板、CPU、内存还是硬盘都是针对接口设计的，如果是针对实现设计的，内存就是针对具体的某个品牌的主板去设计了，这样如果更换内存可能也要更换主板，这就涉及行业标准的问题。再如，充电器的电线常用的3种类型，苹果的Lighting接口，华为的Type-C接口，以及安卓系列的Micro USB接口，更换任何厂家制造的都可以使用，这就是针对充电器的接口进行设计。

2、**高层模块不应依赖低层模块，两个都应该依赖抽象，各自都不互相依赖**。

一般的设计场景是自顶向下，高层模块被拆分为多个低层模块去实现，然后使用高层模块时需要调用低层模块去执行功能，这就造成了高层模块对底层模块的依赖。

3、**里氏代换原则是指：软件实体使用的是父类的话，那么它一定使用于子类**。换句话说子类有自己的行为之前先是父类，其实就是继承的概念。

这样第2条依据第3条就可以实现，因为**子对象可以被替代为任何其它类型，所以允许高层模块在无需修改时进行扩展**。

## 六、装饰模式

1、**装饰模式是指：动态的给一个对象添加额外的职责，就增加功能而言比生成子类更灵活**。

装饰类也是继承自抽象类，但是和抽象类的具体类实现不同，装饰类不需要被抽象类知道。

现在以Component、ConcreteComponent、Decorator、ConcreteDecorator四个类的例子来说明装饰模式。

```c#
abstract class Component{ // 业务基类
    public abstract void Operation();//抽象函数
}
class ConcreteComponent : Component{// 业务具体类
    public override void Operation(){
        Console.WriteLine("concrete component");
    }
}
abstract class Decorator : Component{ // 装饰器抽象基类也继承于业务基类
    protected Component component;//更像是has-a,用某物实现的组合关系
    public void setComponent(Component component){
        this.component = component;
    }
    public override void Operation(){
        if (component != null){
            component.Operation();//装饰器的操作就是Component的操作,转交
        }
    }
}
class ConcreteDecoratorA:Decorator{
    private string addedState;//A类独有属性
    public override void Operation(){
        base.Operation();//原有功能,base.opt=>Decorator=>Component.opt
    	addedState = "New State";//新功能
 		...
    }
}
class ConcreteDecoratorB:Decorator{
    public override void Operation(){
        base.Operation();//原有功能
    	AddedBehavior();// 新方法
 		...
    }
    private void AddedBehavior(){ // B类独有方法
        ...
    }
}
// 客户端代码
static void Main(string[] args){
    ConcreteComponent c = new ConcreteComponent();//业务具体类对象
    ConcreteDecoratorA d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB d2 = new ConcreteDecoratorB();//装饰具体类对象
    
    d1.setComponent(c);//装饰了c的功能
    d2.setComponent(d1);// 装饰了d1,c的功能
    d2.Operation();
}
```

从上述代码可以看出，**装饰模式的核心就是装饰器类不仅继承业务类，还将业务类对象作为私有进行管理，然后提供和业务对象同样的方法，只是内部直接调用业务对象的方法(这也是为何还要继承业务类)，同样装饰器类的派生类进行复写时只需要先调用基类的方法再执行自己的方法即可**。

小结：总结一下工厂模式、策略模式和装饰器模式。

**工厂模式**：模式成员有基类接口类、基类工厂类和派生具体类。

基类接口类定义接口，派生具体类继承基类的接口类并复写方法；

基类工厂类的构造函数会提供参数，内部判断语句会知道返回哪个派生类的具体对象；

优点是构建新的派生类不会影响其它派生类和基类接口，但是需要修改基类工厂类的构造函数。在客户端来看客户只使用了基类工厂类，它看不到派生类，知道基类接口，因为**基类工厂类没有继承基类接口类**，只在**构造函数中使用了基类对象来初始化为不同的派生类对象**。



**策略模式**：模式成员有基类接口类、管理基类接口对象的类和派生具体类。

**管理基类接口对象的类也没有继承基类接口类**，**只是将其对象作为私有属性(和简单工厂的区别,没有作为私有属性进行管理)**，构造函数负责将该属性初始化；

管理基类接口对象的类可以以基类接口类，也可以使用派生具体类来构造自己，其私有属性相应就可以变成不同类型的对象(简单工厂则是直接实例化成了一个具体的算法对象)；

管理基类接口对象的类可以提供方法，**方法内部调用的实际上是私有属性的方**法，因为私有属性的泛型，所以让这个方法也显得泛型，达到了复用的目的；

客户只用到了管理基类接口对象的类，看不到派生类也看不到基类接口。



**装饰器模式**：模式成员有基类具体类(基类接口类可以没有也可以有)、装饰器具体类(装饰器接口类可以有也可以没有)。

装饰器模式有点像策略模式的提升，因为**装饰器类也将基类对象作为私有属性进行管理(就像策略模式管理基类接口对象)，但是还继承了基类，这就使得装饰器能够覆盖基类的方法**；

**装饰器类要继承基类的原因是因为要提供基类对象的同名方法，内部先调用了基类的同名方法，再添加自己的功能**，就达到了装饰的效果；

装饰器类将基类对象作为私有属性进行管理，即作为被包装的对象**，继承了策略模式中可以将私有属性随意构造成任何派生类对象的优点，达到复用目的；

如果只有基类具体类，则装饰具体类可以直接继承基类具体类并将其作为私有属性管理即可，无需装饰接口类，即将装饰具体类和装饰接口类的责任合并为一个类；

## 七、代理模式

1、代理模式是指：**代理类和被代理类都继承自一个基类，同时被代理类作为代理类的私有属性**。代理模式看起来和装饰器模式非常相似，因为装饰器模式本质上也是一个派生类和装饰器类都继承了基类。区别在于，**装饰器类继承了基类且管理基类的对象，代理类继承了基类但是管理的是另一个继承基类的类对象**。

```c#
abstract class Subject{ // 基类
    public abstract void Request(); // 基类方法
}
class RealSubject:Subject{ // 被代理类,实体类
    public override void Request(){
        Console.WriteLine("真实的请求");
    }
}
class Proxy:Subject{ // 代理类继承基类
    RealSubject realSubject;//管理被代理类的对象
    public override void Request(){
        if (realSubject == null){
            realSubject = new RealSubject();
        }
        realSubject.Request();//实质代替调用实体的方法,但不是装饰
    }
}
// 如果代理类还想修饰被代理类,应当继承被代理类,调用被代理类的方法后再追加自己方法

// 客户端代码
static void Main(String[] args){
    Proxy proxy = new Proxy();
    proxy.Request();//内部执行的是被代理类的方法
}
```

2、代理类的应用有远程代理、虚拟代理、安全代理和智能指引。

远程代理：让对象在不同的地址空间也可以使用。例如客户端程序可以调用代理文件就可以解决远程访问的问题；

虚拟代理：创建一个存放很大实体对象的代理对象，达到性能优化的目的。例如打开一个很大的网页，里边有很多的文字和图片但是不影响打开速度，因为这些实体需要下载以后才能看到，它们在代理内的存在是虚拟的，代理只是存储了真实图片的路径和尺寸，不是真正的图片。

安全代理：用来控制访问真实对象的权限，不同的代理拥有不同的访问权限。

智能指引：调用真实的对象时，代理处理另外一些事。例如计算真实对象的引用次数，在该对象没有引用时释放它；或者访问真实对象时检查是否被锁定，以确保其他对象不能改变它。

## 八、工厂方法模式

1、工厂方法模式是指**工厂也有抽象工厂，然后工厂具体类继承抽象工厂去制造某个派生类的对象**。

和简单工厂模式一样，工厂类没有继承基类接口类，也没有管理基类接口类的对象作为私有属性，而是直接使用基类接口。但是不用一个工厂建造各种类型的派生类对象，而是**不同的工厂建造不同的派生类对象**，这样更灵活，也更符合单一权责原则。因为简单工厂模式意味着这个工厂可能因为任何派生类的对象增加(多因素)而对工厂的构造函数进行修改，同时还违反了开放闭合原则。

以第一章的计算器实现为例。

```c#
interface IFactory{//抽象工厂接口
    Operation CreateOperation();//返回任何可能的抽象运算,只是使用了Operation
}
class AddFactory:IFactory{ // 加法类工厂
    public Operation CreateOperation(){
        return OperationAdd();//返回加法类操作对象
    }
}
class SubFactory:IFactory{ // 减法类工厂
    public Operation CreateOperation(){
        return OperationSub();//返回减法类操作对象
    }
}
class MulFactory:IFactory{ // 乘法类工厂
    public Operation CreateOperation(){
        return OperationMul();//返回乘法类操作对象
    }
}
class DivFactory:IFactory{ // 除法类工厂
    public Operation CreateOperation(){
        return OperationDiv();//返回除法类操作对象
    }
}
// 客户端代码
IFactory F = new AddFactory();//得到加法工厂
Operation opt = F.CreateOperation();//加法工厂创建了加法操作
opt.num1 = 1;
opt.num2 = 2;
double res = opt.getResult();
```

工厂方法模式不需要再对抽象工厂进行修改了，也不会对其他派生的工厂产生影响，真正实现了开放-闭合原则，支持拓展，不支持已有的代码修改。

但是工厂模式还是存在问题，选择何种模式其实是从工厂内部的选择转交给了客户端，另外如果增加一种计算功能就要加一个对应的工厂，开发量比较大，解决这个问题的方法依然是反射技术。

## 九、原型模式

1、原型模式是指，用原型实例指向创建对象的种类，并且通过拷贝这些原型创建新的对象。

可以创建原型类，声明一个克隆自身的接口，原型类的派生类可以继承它实现自己的克隆方式。

```c#
abstract class Prototype{
    public abstract Prototype Clone();//返回Prototype的方法
}
class ConcreteProtype:Prototype{
    public override Prototype Clone(){
        return (Prototype)this.MemberwiseClone();
    }
}
```

MemberwiseClone()方法对值类型的字段会进行复制，但是引用类型的字段只会复制引用而不是引用背后的数据，所以这属于浅拷贝。

2、克隆的方法不需要重新初始化对象，而是基于已初始化的对象。动态的获得该对象运行时的状态，既隐藏了对象创建的细节又提高性能，因为调用new初始化对象需要执行构造函数。

3、深拷贝与浅拷贝，这个概念无需多说，深拷贝是复制真正的数据对象，浅拷贝只复制引用或者指针本身，所以释放内存时特别要注意堆区申请的内存管理。

## 十、模板方法模式

**模板方法是指，把不变的行为搬移到基类，可以去除子类中重复的代码达到复用的目的**。

需要变化的行为由子类自己去覆写重定义，其实这里和C++抽象基类的非虚函数要求不被重定义是相同的。例如STL容器类有一些固定的方法，empty、size、capacity等，这些都定义成非虚函数，因为派生类依然可以使用这些函数进行复用。

```c#
abstract class AbstractClass{
    public abstract void f1(); // f1,f2是可以被覆写体现多态的
    public abstract void f2();
    public void templateMethod(){ // 固定会执行的逻辑不声明为abstract
        f1();
        f2();
    }
}
class ConcreteClassA:AbstractClass{
    public override void f1(){
        Console.WriteLine("A->f1()");
    }
    public override void f2(){
        Console.WriteLine("A->f2()");
    }
}
class ConcreteClassB:AbstractClass{
    public override void f1(){
        Console.WriteLine("B->f1()");
    }
    public override void f2(){
        Console.WriteLine("B->f2()");
    }
}
// 客户端代码
AbstractClass c;
c = new ConcreteClassA(); //templateMethod实现复用
c.templateMethod();
c = new ConcreteClassB();
c.templateMethod();
```

## 十一、迪米特法则

迪米特法则是指，如果两个类不必彼此直接通信，那么这两个类不应发生直接的相互作用。若其中一个类需要调用另外一个类的某个方法时可以借助第三者转发这个调用。

**迪米特法则强调了类之间的松耦合，耦合越弱，越有利于被复用**，且若耦合的类被修改也不会对有关系的类造成波及。

## 十二、外观模式

1、外观模式是指，为子系统的一组接口提供一个一致的界面，此模式定义了一个高层接口，接口使子系统更容易被使用。

容易理解的例子是基金与股票的关系，基金是由众多股票、国债、房地产构成的，对于普通人可能无法同时关注到这些东西的买入卖出信息，但是只需要关心基金即可，真正的风险操作都是基金经理负责搞定的。基金其实就是股票的门面，降低了入门难度。

2、对于外观类，它需要了解所有子系统类的方法或属性，然后将其组合，以便外界调用。

外观类常常用于遗留的大型项目，屎山往往是无法拓展和更改的，但是可以开发一个外观类去和屎山进行交互，然后拓展新功能可以基于外观类，很显然前者非常的狗屎。

## 十三、建造者模式

1、建造者模式是指，**将一个复杂对象的构建过程与它的表示分离，使得同样的构建过程可以创建不同的表示**。

例如，创建各种各样的人，最基本的人都有手有脚有头，可以把这个过程固定下来，作为抽象基类，提供各种各样的抽象方法。然后所有的派生类使用它都必须覆盖这些抽象方法。

```c#
abstract class PersonBuilder{
    public abstract void buildHead();
    public abstract void buildArm();
    public abstract void buildLeg();
    public abstract void buildBody();
}
class PersonThinBuilder{ // 瘦子类
    public override void buildHead(); //必须覆写这些方法
    public override void buildArm();
    public override void buildLeg();
    public override void buildBody();
}
class PersonFatBuilder{ // 胖子类同理
    public override void buildHead(); //必须覆写这些方法
    public override void buildArm();
    public override void buildLeg();
    public override void buildBody();
}
```

2、为了避免客户端忘记调用这些方法去创建人，还可以借助简单工厂模式实现一个指挥建造的类。

简单工厂模式回顾一下，它没有继承业务基类，只是把它作为私有属性进行管理，然后创造基类及其派生类各种各样的对象。指挥者一样，把PersonBuilder作为私有属性管理，但是有一点点区别，就是不直接生成具体的人类，而是固定创建人的过程，这就**结合了策略模式的思想(固定的是如何提供算法的行为而不是算法本身)以及模板方法(派生类都要重复这一人的构建过程，可复用的代码应作为基类的非抽象方法)**。

```c#
class PersonBuilderDirector{
    private PersonBuilder pb;
    public PersonBuilderDirector(PersonBuilder pb){
        this.pb = pb;
    }
    public void CreatePerson(){//注意提供的不是抽象方法而是模板方法
        pb.buildHead();
        pb.buildBody();
        pb.buildArm();
        pb.buildLeg();
    }
}
// 客户端代码
PersonThinBuilder ptb = new PersonThinBuilder();
PersonBuilderDirector pbd = new PersonBuilderDirector(ptb);
pbd.CreatePerson();
```

3、建造者模式是用于创建复杂对象的算法应独立于该对象的组成部分以及它们的装配方式时所使用的模式。换句话说，如果某个产品有固定的流程，就不需要关心它需要什么东西组成以及产品是如何被组装的。

## 十四、观察者模式

1、观察者模式是指：**多个观察者对象可以同时监听一个主题对象(通知者对象)**。这个主题变化时可以通知到所有观察者对象，使观察者自动更新自己的状态。

例如老板可以作为一个通知者的具体类对象，老板类继承了通知者类。同时各个员工都可以看成观察者的具体类对象，它们都继承于观察者类**。关键点在于，抽象观察者类的构造函数需要用到抽象通知者，注意不是继承，也不是作为私有属性管理，而是直接拿来使用(就像简单工厂模式直接把要建造的基类对象直接拿过来用)**。既然如此，观察者的具体类也必须使用通知者的对象来构造，那么所有的员工都可以将老板作为通知者对象，老板一来就停止摸鱼。

2、观察者模式适用于，想要维持维护对象的一致性且要避免紧耦合时的设计场景。**当一个对象的改变需要同时改变其它对象且不知道要改变多少其它对象时考虑使用观察者模式**。

3、更新状态的函数可能名称不相同，可以去除抽象观察者类，每个观察者具体类有自己的方法名，它们的构造函数使用抽象通知类即可。但是这样如何做到观察者具体类可以监视老板呢？在C#中答案是使用委托技术，关键字是delegate。

```c#
delegate void EventHandler();//声明1个委托
class Boss : Subject{//继承抽象通知者
    //声明1个事件Update,类型为委托EventHandler
    public event EventHandler Update;
    public void Notify(){
        Update();
    }
}
// 客户端
Boss boss = new Boss();//具体的通知者老板
StockObserver p1 = new StockObserver("p1",boss);//看股票的同事p1监视老板
NBAObserver p2 = new NBAObserver("p2",boss);//看NBA的同事p2监视老板

boss.Update += new EventHandler(p1,CloseStockMarket);//p1关闭股票市场
boss.Update += new EventHandler(p2,CloseNBAGame);//p2关闭NBA比赛

// 将boss的更新动作(例如出现在办公室)通过授权绑定到2个同事对应的反应函数
```

## 十五、抽象工厂模式

1、抽象工厂模式是对简单工厂模式、工厂方法模式的继续提升，即提供一个创建一系列相关或者相互依赖对象的接口而无需指定它们具体的类。

简单工厂模式只有1个工厂，它可以根据条件判断制造不同的某一类产品，这类产品都属于一个抽象基类。例如工厂棚可以制造葡萄、桃、苹果等产品，它们都属于水果。

工厂方法模式就是有多个工厂，它的定位是做某个类型的产品，但是具体的类型有分厂。例如总部厂是做水果的，它有一堆分厂专门制造某一种水果。

抽象工厂模式加了更深一层的抽象，它可以理解为总厂现在不做水果，做的是水果饮料和水果沙拉。那么这些分厂继承了它也是这种模式，要做饮料和沙拉，但是对应的是苹果沙拉和苹果汁，香蕉沙拉和香蕉汁。。当然抽象可以反复堆叠，但已经尽可能降低了大型项目的耦合性。

2、抽象工厂的好处是，在客户看来它只是知道一个抽象的水果工厂类，这工厂可以制造各种水果沙拉和饮料，但是这些东西创建的过程不会被客户所知，他们只是用了这个抽象接口去操纵实例。产品的具体类名也和具体工厂的实现分离，不会出现在客户代码中。

3、本章提到了依赖注入的反射技术，不过这是C#的内容，所以不予说明，因为我没学过C#。

## 十六、状态模式

1、状态模式是指，**一个对象的内在状态改变时允许改变其行为，这个对象看起来像是改变了其类**。

主要解决的是对象状态转换的条件表达式过于复杂时，把状态的判断逻辑转移到表示不同状态的一系列类当中，就可以把复杂的判断逻辑简化。

2、操作上和策略模式完全一样，使用一个类管理状态的抽象基类对象作为私有属性。各类状态的具体类都继承自抽象状态类，每个具体类来完成那一部分判断分支，然后进入下一轮状态，那么管理类可以依据私有属性的变化而使用不同的状态。这里有2个区别是，**第一是状态类会以管理状态的类进行构造，这是为了可以获知目前管理的状态是什么；第二每个状态都可以转换成下一状态**。

```c#
public abstract class State{
    public abstract void writeProgram(Work w);//以管理State的类Work构造
}
public class ForenoonState:State{
    public override void writeProgram(Work w){
        if (w.hour < 12){ // 上午工作
            ...
        }
        else{
            w.setState(new NoonState());
            w.writeProgram（）；//转入中午工作
        }
    }
}
public class NoonState:State{
    public override void writeProgram(Work w){
        if (w.hour < 13){ // 中午工作
            ...
        }
        else{
            w.setState(new AfternoonState());
            w.writeProgram（）；//转入下午工作
        }
    }
}
public class AfternoonState:State{
    public override void writeProgram(Work w){
        if (w.hour < 17){ // 下午工作
            ...
        }
        else{
            w.setState(new EveningState());
            w.writeProgram（）；//转入晚上工作
        }
    }
}
// ...
public class Work{
    // 减少了连续的分支判断,将各个判断分支置于具体的状态类中实现。
    private State current;//管理抽象状态对象,作为私有属性
    public Work(){
        current = new ForenoonState();//当前工作状态
    }
    private double hour;
    public void setState(State s){
        current = s;
    }
    public void writeProgram(){
        current.writeProgram(this);
    }
}
```

## 十七、适配器模式

1、适配器模式是指，**将一个类的接口转换成客户希望的另外一个接口**，可以解决原本因为接口不兼容而不能一起工作的那些类可以一起工作。

两个类所做的事情相同或相似但是具有不同的接口，适配器模式可以应用。

2、具体操作是一些派生类继承于抽象类，如前锋、后卫、中锋和球员的关系，然后外籍中锋和球员类没有关系，这时需要一个翻译的适配器。翻译者继承了球员类，然后它管理了外籍中锋的对象作为私有属性，那么翻译者使用球员的方法时可以在内部调用的是私有属性的对应方法。例如将球员的attack方法继承下来后内部调用的却是外籍中锋类的"进攻"方法，达到了一种翻译适配的效果。

## 十八、备忘录模式

1、备忘录模式是指，**不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样可将对象恢复到之前的状态**。

业务类内部有2个备忘录方法，一个是创建备忘录(决定备忘哪些成分)，一个是设置备忘录(恢复之前的备忘录)。备忘录类是独立的类，它可以被另一个类管理作为该类的私有属性，所以最终就是用这个类的私有属性来保存业务类创建备忘录返回的备忘录，然后业务类状态变化后，再取出私有属性重置即可。

**所以关键就是要从业务类内部返回备忘录，同时用一个管理备忘录的类去接收**。

```c#
class Originator{
    private string state;//保存的数据状态
    public string State{
        get{return state;}
        set{state = value;}
    }
    public Memento CreateMemento(){
        return (new Memenyo(state));
        // 外部使用Originator.CreateMemento()
        // 即保存了Originator的信息
    }
    public void SetMemento(Memento mem){
        state = mem.State;//可以访问备忘录类的State接口(宽),Originator的state可以被重置恢复到以前的状态
    }
}
class Memento{ //完全独立的类,不继承也不使用别的类属性
    private string state;
    public Memento(string state){
        this.state = state;
    }
    public string State{
        get{return state;}//提供给Originator的宽接口
    }
}
class ManagerMemento{ // 管理备忘录的类
    private Memento mem;//作为私有属性
    public Memento getAndSetMemento{
        get{return mem;}
        set{mem = value;}
    }
}
// 客户端程序
Originator o = new Originator();//业务类
o.State = "on";//设置state="on"

ManagerMemento c= new ManagerMemento();//管理备忘录
c.Memento = o.CreateMemento();//o内部的状态备忘于c

o.State = "off";//改变状态
o.SetMemento(c.Memento);//恢复备忘录
```

2、备忘录模式缺点是可能要保存很多的数据，比较消耗内存。

## 十九、组合模式

1、组合模式是指将对象组合成树形结构以表示"部分-整体"的层次结构。**组合模式使用户对单个对象和组合对象的使用具有一致性**。

例如树具有3个方法，添加节点，移除节点和展示节点值。对于叶子节点没有子节点，所以移除和添加操作是没有意义的。而其它非叶子节点，3个方法都有意义，此时希望对两类节点都可以使用同样的方式去处理，就可以采用组合模式。叶子节点类和非叶子节点类继承同一个类即可。

```c#
abstract class Component{
    protected string name;//声明为保护可被继承
    public Component(string name){
        this.name = name;
    }
    public abstract void Add(Component c);
    public abstract void Remove(Component c);
    public abstract void Display(Component c);
}
class Leaf:Component{
    public Leaf(string name):base(name){}
    public override void Add(Component c){
        Console.WriteLine("canno add to a leaf node"); //透明模式但不安全
    }
    public override void Remove(Component c){
        Console.WriteLine("canno remove from  a leaf node"); //透明模式但不安全
    }
    public override void Display{
        Console.WriteLine("name is ",name);
    }
}
class Composite:Component{
    private List<Component>children = new List<Component>();//存储子节点的列表
    public Composite(string name):base(name){}
    public override void Add(Component c){
		children.Add(c);
    }
    public override void Remove(Component c){
        children.Remove(c);
    }
    public override void Display{
        Console.Display();
    }
}
// 客户端代码
Composite root = new Composite("root");
root.Add(new Leaf("Leaf A"));
root.Add(new Leaf("Leaf B"));

Composite comp = new Composite("composite x");
comp.Add(new Leaf("Leaf XA"));
comp.Add(new Leaf("Leaf XB"));

Composite comp2 = new Composite("composite xy");
comp2.Add(new Leaf("Leaf XYA"));
comp2.Add(new Leaf("Leaf XYB"));

comp.Add(comp2);
root.Add(comp);
Leaf leaf = new Leaf("Leaf C");
root.Add(leaf)
root.Remove(leaf);
root.Display();
```

2、透明模式是基类提供了所有方法，某个子类不能使用某些方法时可以抛出异常或提示信息，这样可以保证接口一致，但是不安全。如果基类只提供子类完全共有的那些函数，可能会导致子类之间有不同的接口。

## 二十、迭代器模式

1、迭代器模式是指，**提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示**。

类似STL容器的迭代器类，既然是迭代，最好把迭代器类嵌套声明在容器类中。如果不嵌套，**容器类可以提供创建迭代器的方法**，类似于备忘录模式内部负责创建备忘录，但是迭代器怎么访问容器类呢，只能是将容器类对象作为私有属性，这样对传入的容器类对象进行迭代即可。容器类也可以有派生类，那么派生类也会继承这个返回迭代器的方法，那么迭代器的派生类去对应容器的派生类即可实现多态且松耦合，因为迭代器可以前向访问也可以反向访问，这个其实是工厂方法模式的体现。

```c#
abstract class Iterator{
    public abstract object First();
    public abstract object Next();
    public abstract boolIsDone();
    public abstract object CurrentItem();
}
abstract class Containter{
    public abstract Iterator CreateIterator();//抽象类返回抽象类,只提供接口
}
class concreteContainter:Containter{
    private IList<object> items=new List<object>();
    public override Iterator CreateIterator(){ //继承的创建迭代器的方法
        return new ConcreteIterator(this);//创建子类迭代器
    }
    public int count{ //返回元素个数
        get{returrn items.Count;}
    }
    public object this(int index){
        get{return items[index];}//返回和设置指定索引元素
        set{items.Insert(index,value);}
    }
}
class ConcreteIterator:Iterator{
    private concreteContainter containter;//迭代器类可直接操作容器类
    prrivate int currrent = 0;
    public ConcreteIterator(concreteContainter con){
        this.containter = con;
    }
    public override object First(){
        return containter[0];
    }
    public override object Next(){
        object ret = null;
        current++;
        if (current < containter.Count){
            ret = containter[current];
        }
        return ret;
    }
    public override bool IsDone(){
        return current>=containte.Count?true:false;
    }
    public override object CurrentItem(){
        return containter[currrent];
    }
}
```

2、迭代器类就是分离了集合对象的遍历行为，可以不暴露集合的内部结构还可以让外部代码透明的访问集合内的数据。

## 二十一、单例模式

1、单例模式是指，保证一个类只有1个实例，并提供一个访问它的全局访问点。

阻止new的使用在C++中就是利用一个类，声明构造函数为私有，然后单例模式的那个子类继承这个类，那么子类就不能进行构造了。对于C#而言可以这样做。

```c#
class Singleton{
    private static Signleton instance;//唯一实例
    private Signleton(){}//阻止new创建新实例
    public static Signleton getInstance(){
        // 静态函数,唯一全局访问点,static函数只存在1份内存
        if (instance == null){
            instance = new Signleton();
        }
        return instance;
    }
}
// 客户端代码
Signleton s1 = Signleton.getInstance();
Signleton s2 = Signleton.getInstance();
if (s1 == s2){ // s1和s2相同
    ...
}
```

2、单例模式可以严格控制客户怎样访问以及何时访问，即对唯一实例的受控访问。

## 二十二、桥接模式



## 二十三、命令模式



## 二十四、职责链模式



## 二十五、中介者模式



## 二十六、享元模式



## 二十七、解释器模式



## 二十八、访问者模式



## 二十九、模式总结