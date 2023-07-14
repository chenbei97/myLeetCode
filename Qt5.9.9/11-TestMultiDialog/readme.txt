QWidget有4个函数，setVisible、show、hide和setHidden()
show = setVisible(true)
hide = setVisible(false)
setHidden = setVisible(false)
也就是说只有setVisible函数是独立的,其它只是一层封装

show：会调用closeEvent事件函数，如果关闭实际上调用的是hide函数不会删除，如果不关闭则返回什么也不做
如果为closeEvent设置标志位Qt::WA_DeleteOnClose，就会关闭时删除，除了调用hide以外还会调用deleteLater
设置这个标志位可以借助setAttribute函数设定

QDialog相比QWidget多了5个函数： exec()、open()、done()、reject ()和 accept ()
QDialog::show()：非模态窗口显示，但如果在窗口中显示设置为模态对话框setModal (true)，则显示半模态对话框
QDailog::open()：模态(窗口级)窗口显示
QDialog::exec()：模态(应用程序级)窗口显示，exec() 先设置modal属性，而后调用 show() 显示对话框，最后启用事件循环等待响应结果
                                在用户关闭这个对话框之前，不能和同一应用程序中的其它窗口交互
QDialog::done(int)：和close比较类似，因为它调用了close所调用的 close_helper 函数。
                                只不过不同于close函数，它始终会先让Widget不可见，然后close操作，最后根据参数发射信号
QDialog::reject()：调用done()函数，源码为done(Rejected)，隐藏模式对话框并将结果代码设置为 Rejected
QDialog::accept()：调用done()函数，源码为done(Accepted)，隐藏模式对话框并将结果代码设置为 Accepted


主窗口的对话框进行交互的方法有2种
第一种是对话框可以实现定义一些公共函数提供给主窗口操作对话框时使用
第二种是借助信号与槽机制，对话框可以进行一些操作时发射出信号传出信息，主窗口定义和此信号连接的槽函数获取信息，然后执行一些操作

对话框操作主窗口也是可以的，也是2种方法
第一种，对话框类需要具备主窗口的指针，所以需要引入主窗口的头文件
然后主窗口需要提供一些公共函数能够设置UI或者一些私有属性，因为对话框无法直接访问
第二种，主窗口可以定义信号，传递出信息被对话框使用，这样也是可以的

连接信号必须至少有一方的指针，才能连接2个窗口
但是在哪里连接都是ok的
