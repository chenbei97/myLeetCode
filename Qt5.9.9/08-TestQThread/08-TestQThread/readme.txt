使用线程一般有2个方法。
(1)
第一个方法是，定义一个继承QThread的类，然后重载run()函数
在该函数内定义自己的工作任务，这个自定义的线程类调用start()函数就会执行该任务
这个线程类作为自己业务类的一个私有属性，业务类是主线程
可以在业务类内控制线程的开启和关闭，一般是提供一个函数
例如pushbutton的按钮槽函数，来控制线程的开启或关闭
然后在业务类的析构函数内使用stop()和wait()来停止并阻止子线程启动

这里的例子是，UI想要执行1个掷骰子的功能，点击开始就会掷骰子
然后根据结果在UI的QLabel上显示图片
掷骰子这个功能如果在主线程执行，可能就会造成主窗口卡住，所以定义在子线程中

rollDice.h定义了掷骰子的工作线程类
掷骰子使用随机数完成，得到的点数在子线程中，所以主线程需要能够拿到这个点数才能显示
同时UI界面的QPlainText会显示每次投的点数是多少，所以还需要传递掷骰子的次数。

这个点数和次数可以通过信号与槽机制拿到，也可以定义一个具有指针参数的函数让主线程拿到

UI界面设计了启动、暂停和结束线程，以及开始掷骰子的pushButton。
这些button的槽函数内部可以调用rollDice对应封装好的函数来控制子线程即可

如果通过信号与槽的机制，子线程必须要定义一个信号，这个信号在run()函数发射出去
因为run()函数可以确定点数和次数2个值,用信号函数带出去。
之后主线程就必须把这个信号函数在某个具备相同参数类型的槽函数中接收，就可以拿到这2个值了

现在的调用流程变成了：
pushbutton控制开启线程=>调用start()函数=>执行内部的run()函数=>发射信号=>接收信号的槽函数立即执行
如果pushbutton暂停掷骰子=>标志位pdice=false=>run()函数内部实际什么也没执行=>信号也没有发射=>槽函数也不会执行

(2)
第二个方法是，把Thread作为业务类的私有属性直接使用，但是没重载过run()
这个在官方文档QThread的例子提过
