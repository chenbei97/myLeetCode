'''
Author: chenbei
Date: 2022-09-09 15:21:54
LastEditTime: 2022-09-09 16:08:11
FilePath: \\myLeetCode\\PythonParallelProgramming\\chap01\\test_threading.py
Description: 测试threading的API
Signature: A boy without dreams
'''
import threading

print(threading.active_count())  # 返回当前存活的 Thread 对象的数量

# 返回当前对应调用者的控制线程的 Thread 对象。如果调用者的控制线程不是利用 threading 创建，会返回一个功能受限的虚拟线程对象
current_thread = threading.current_thread()
print(current_thread.getName())  # MainThread
print(current_thread.is_alive())  # True 检查线程是否存活
print(current_thread.isDaemon())  # False 是否被标记成一个守护线程
print(current_thread.daemon)  # False 主线程一定不是守护线程
print(current_thread.name)  # MainThread，线程有名字。名字可以传递给构造函数，也可以通过 name 属性读取或者修改

print(threading.get_native_id())  # 返回内核分配给当前线程的原生集成线程 ID(非负整数)(含义同下)
print(threading.get_ident())  # 返回当前线程的线程标识符(非零整数),每次不一定相同(含义同上)

# 返回当前所有存活的 Thread 对象的列表
# 该列表包括守护线程以及 current_thread() 创建的空线程，它不包括已终结的和尚未开始的线程
thread_list = threading.enumerate()
print(len(thread_list))  # 1

# 返回主 Thread 对象。一般情况下，主线程是Python解释器开始时创建的线程
main_thread = threading.main_thread()
main_thread.setName("主线程")
print(main_thread.name)  # "主线程"

# threading.settrace(func) 为所有 threading 模块开始的线程设置追踪函数
# 在每个线程的 run() 方法被调用前，func 会被传递给 sys.settrace()
# threading.gettrace() 返回由 settrace() 设置的跟踪函数
threading.settrace(lambda x: [j ^ 2 for j in range(x)])

# threading.setprofile(func)为所有 threading 模块开始的线程设置性能测试函数
# 在每个线程的 run() 方法被调用前，func 会被传递给 sys.setprofile()
# threading.getprofile() 返回由 setprofile() 设置的性能分析函数

# 返回创建线程时使用的堆栈大小。可选参数 size 指定之后新建的线程的堆栈大小，而且一定要是0（根据平台或者默认配置）
# 或者最小是32,768(32KiB)的一个正整数。如果 size 没有指定，默认是0
# 如果不支持改变线程堆栈大小，会抛出 RuntimeError 错误
# 如果指定的堆栈大小不合法，会抛出 ValueError 错误并且不会修改堆栈大小
# 32KiB是当前最小的能保证解释器有足够堆栈空间的堆栈大小
# 4KiB页面比较普遍，在没有更具体信息的情况下，建议的方法是使用4096的倍数作为堆栈大小
size = 4096
threading.stack_size([size])

# 线程本地数据是特定线程的数据。管理线程本地数据，只需要创建一个 local （或者一个子类型）的实例并在实例中储存属性
# local是一个类,该类的信息不详述
mydata = threading.local()
mydata.x = 1


# Thread类代表在独立控制线程运行的活动，有两种方式指定活动：
# 传递一个可调用对象给构造函数
# 或者在子类重载 run() 方法，但其它方法不应该在子类被（除了构造函数）重载。换句话说，只能重载这个类的 __init__() 和 run() 方法
# 线程对象一但被创建，应当通过调用线程的 start() 方法来控制线程调用 run() 方法
# 一旦线程活动开始，该线程被认为是存活的。当它的 run()方法终结（不管是正常还是抛出未被处理的异常），就不是存活的，is_alive() 方法用于检查线程是否存活
# 其他线程可以调用一个线程的 join() 方法。这会阻塞调用该方法的线程，直到被调用 join() 方法的线程终结
# 线程有名字。名字可以传递给构造函数，也可以通过 name 属性读取或者修改
# 如果 run() 方法引发了异常，则会调用 threading.excepthook() 来处理它。 在默认情况下，threading.excepthook() 会静默地忽略 SystemExit
# 线程可以被标记成一个守护线程。意义是当剩下的线程都是守护线程时，整个Python程序将会退出。这个标识可以通过 daemon 特征属性或者 daemon 构造器参数来设置
'''
class threading.Thread(group=None, target=None, name=None, args=(), kwargs={}, *, daemon=None)
应当始终使用关键字参数调用此构造函数。 参数如下：
group 应该为 None；为了日后扩展 ThreadGroup 类实现而保留
target 是用于run() 方法调用的可调用对象。默认是 None，表示不需要调用任何方法
name 是线程名称。 在默认情况下，会以 "Thread-N" 的形式构造唯一名称，其中 N 为一个较小的十进制数值，或是 "Thread-N (target)" 的形式，其中 "target" 为 target.__name__，如果指定了 target 参数的话
args 是用于调用目标函数的参数元组。默认是 ()
kwargs 是用于调用目标函数的关键字参数字典。默认是 {}
如果不是 None，daemon 参数将显式地设置该线程是否为守护模式。 如果是 None (默认值)，线程将继承当前线程的守护模式属性
如果子类型重载了构造函数，它一定要确保在做任何事前，先发起调用基类构造器(Thread.__init__())

方法：
start()
开始线程活动
它在一个线程里最多只能被调用一次。它安排对象的 run() 方法在一个独立的控制进程中调用。
如果同一个线程对象中调用这个方法的次数大于一次，会抛出 RuntimeError

run()
代表线程活动的方法
你可以在子类型里重载这个方法，标准的 run() 方法会对作为 target 参数传递给该对象构造器的可调用对象（如果存在）发起调用
并附带从 args 和 kwargs 参数分别获取的位置和关键字参数

join(timeout=None)
等待，直到线程终结。这会阻塞调用这个方法的线程，直到被调用 join() 的线程终结 
-- 不管是正常终结还是抛出未处理异常 -- 或者直到发生超时，超时选项是可选的
当 timeout 参数存在而且不是 None 时，它应该是一个用于指定操作超时的以秒为单位的浮点数或者分数
因为 join() 总是返回 None ，所以你一定要在 join() 后调用 is_alive() 才能判断是否发生超时 -- 如果线程仍然存活，则 join() 超时
当 timeout 参数不存在或者是 None ，这个操作会阻塞直到线程终结
一个线程可以被 join() 很多次
如果尝试加入当前线程会导致死锁， join() 会引起 RuntimeError 异常。如果尝试 join() 一个尚未开始的线程，也会抛出相同的异常

name
只用于识别的字符串。它没有语义。多个线程可以赋予相同的名称。 初始名称由构造函数设置

getName()
setName()
已被弃用的 name 的取值/设值 API；请改为直接以特征属性方式使用它，3.10 版后已移除

ident
这个线程的线程标识符，如果线程尚未开始则为 None 。这是个非零整数
参见 get_ident() 函数。当一个线程退出而另外一个线程被创建，线程标识符会被复用。即使线程退出后，仍可得到标识符

native_id
此线程的线程 ID (TID)，由 OS (内核) 分配。 这是一个非负整数，或者如果线程还未启动则为 None
请参阅 get_native_id() 函数。 这个值可被用来在全系统范围内唯一地标识这个特定线程 (直到线程终结，在那之后该值可能会被 OS 回收再利用)

is_alive()
返回线程是否存活。当 run() 方法刚开始直到 run() 方法刚结束，这个方法返回 True

enumerate() 
返回包含所有存活线程的列表

daemon
一个布尔值，表示这个线程是否是一个守护线程（True）或不是（False）。 这个值必须在调用 start() 之前设置，否则会引发 RuntimeError 
它的初始值继承自创建线程；主线程不是一个守护线程，因此所有在主线程中创建的线程默认为 daemon = False。
当没有存活的非守护线程时，整个Python程序才会退出

isDaemon()
setDaemon()
已被弃用的 daemon 的取值/设值 API；请改为直接以特征属性方式使用它。3.10 版后已移除
'''

# 锁对象(互斥量)
'''
class threading.Lock
实现原始锁对象的类。一旦一个线程获得一个锁，会阻塞随后尝试获得锁的线程，直到它被释放；任何线程都可以释放它
需要注意的是 Lock 其实是一个工厂函数，返回平台支持的具体锁类中最有效的版本的实例

acquire(blocking=True, timeout=- 1)
可以阻塞或非阻塞地获得锁
当调用时参数 blocking 设置为 True （缺省值），阻塞直到锁被释放，然后将锁锁定并返回 True 
在参数 blocking 被设置为 False 的情况下调用，将不会发生阻塞
当参数 timeout 使用设置为正值的浮点数调用时，最多阻塞 timeout 指定的秒数，在此期间锁不能被获取
设置 timeout 参数为 -1 指定无限等待。阻塞为 False 时禁止指定超时
如果成功获得锁，则返回 True，否则返回 False (例如发生超时的时候)

release()
释放一个锁。这个方法可以在任何线程中调用，不单指获得锁的线程
当锁被锁定，将它重置为未锁定，并返回。如果其他线程正在等待这个锁解锁而被阻塞，只允许其中一个允许
当在未锁定的锁上发起调用时，会引发 RuntimeError
没有返回值

locked()
当锁被获取时，返回 True
'''


# 条件对象
'''
条件变量总是与某种类型的锁对象相关联，锁对象可以通过传入获得，或者在缺省的情况下自动创建
当多个条件变量需要共享同一个锁时，传入一个锁很有用。锁是条件对象的一部分，你不必单独地跟踪它

条件变量遵循 上下文管理协议 ：使用 with 语句会在它包围的代码块内获取关联的锁。 acquire() 和 release() 方法也能调用关联锁的相关方法
其它方法必须在持有关联的锁的情况下调用

wait() 方法释放锁，然后阻塞直到其它线程调用 notify() 方法或 notify_all() 方法唤醒它
一旦被唤醒， wait() 方法重新获取锁并返回。它也可以指定超时时间

notify() 方法唤醒等待条件变量的线程之一（如果有的话）。 notify_all() 方法唤醒所有等待条件变量的线程
注意： notify() 方法和 notify_all() 方法并不会释放锁，这意味着被唤醒的线程不会立即从它们的 wait() 方法调用中返回
而是会在调用了 notify() 方法或 notify_all() 方法的线程最终放弃了锁的所有权后返回

使用条件变量的典型编程风格是将锁用于同步某些共享状态的权限，那些对状态的某些特定改变感兴趣的线程，它们重复调用 wait() 方法，直到看到所期望的改变发生
而对于修改状态的线程，它们将当前状态改变为可能是等待者所期待的新状态后，调用 notify() 方法或者 notify_all() 方法
例如，下面的代码是一个通用的无限缓冲区容量的生产者-消费者情形：
# Consume one item
with cv:
    while not an_item_is_available():
        cv.wait()
    get_an_available_item()

# Produce one item
with cv:
    make_an_item_available()
    cv.notify()

class threading.Condition(lock=None)
实现条件变量对象的类。一个条件变量对象允许一个或多个线程在被其它线程所通知之前进行等待。
如果给出了非 None 的 lock 参数，则它必须为 Lock 或者 RLock 对象，并且它将被用作底层锁。否则，将会创建新的 RLock 对象，并将其用作底层锁

acquire(*args)
请求底层锁。此方法调用底层锁的相应方法，返回值是底层锁相应方法的返回值

release()
释放底层锁。此方法调用底层锁的相应方法。没有返回值

wait(timeout=None)
等待直到被通知或发生超时。如果线程在调用此方法时没有获得锁，将会引发 RuntimeError 异常
这个方法释放底层锁，然后阻塞，直到在另外一个线程中调用同一个条件变量的 notify() 或 notify_all() 唤醒它，或者直到可选的超时发生
一旦被唤醒或者超时，它重新获得锁并返回
当提供了 timeout 参数且不是 None 时，它应该是一个浮点数，代表操作的超时时间，以秒为单位（可以为小数）
当底层锁是个 RLock ，不会使用它的 release() 方法释放锁，因为当它被递归多次获取时，实际上可能无法解锁
相反，使用了 RLock 类的内部接口，即使多次递归获取它也能解锁它。 然后，在重新获取锁时，使用另一个内部接口来恢复递归级别
返回 True ，除非提供的 timeout 过期，这种情况下返回 False

wait_for(predicate, timeout=None)
等待，直到条件计算为真。 predicate 应该是一个可调用对象而且它的返回值可被解释为一个布尔值。可以提供 timeout 参数给出最大等待时间
这个实用方法会重复地调用 wait() 直到满足判断式或者发生超时。返回值是判断式最后一个返回值，而且如果方法发生超时会返回 False 

notify(n=1)
默认唤醒一个等待这个条件的线程。如果调用线程在没有获得锁的情况下调用这个方法，会引发 RuntimeError 异常
这个方法唤醒最多 n 个正在等待这个条件变量的线程；如果没有线程在等待，这是一个空操作
当前实现中，如果至少有 n 个线程正在等待，准确唤醒 n 个线程。但是依赖这个行为并不安全。未来，优化的实现有时会唤醒超过 n 个线程
注意：被唤醒的线程并没有真正恢复到它调用的 wait() ，直到它可以重新获得锁。 因为 notify() 不释放锁，其调用者才应该这样做

notify_all()
唤醒所有正在等待这个条件的线程。这个方法行为与 notify() 相似，但并不只唤醒单一线程，而是唤醒所有等待线程。如果调用线程在调用这个方法时没有获得锁，会引发 RuntimeError 异常
notifyAll 方法是此方法的已弃用别名
'''

# 信号量
'''
class threading.Semaphore(value=1)
该类实现信号量对象。信号量对象管理一个原子性的计数器，代表 release() 方法的调用次数减去 acquire() 的调用次数再加上一个初始值
如果需要， acquire() 方法将会阻塞直到可以返回而不会使得计数器变成负数。在没有显式给出 value 的值时，默认为1。
可选参数 value 赋予内部计数器初始值，默认值为 1 。如果 value 被赋予小于0的值，将会引发 ValueError 异常

acquire(blocking=True, timeout=None)
获取一个信号量。在不带参数的情况下调用时：
如果在进入时内部计数器的值大于零，则将其减一并立即返回 True
如果在进入时内部计数器的值为零，则将会阻塞直到被对 release() 的调用唤醒
一旦被唤醒（并且计数器的值大于 0），则将计数器减 1 并返回 True
每次对 release() 的调用将只唤醒一个线程。 线程被唤醒的次序是不可确定的
当 blocking 设置为 False 时调用，不会阻塞。 如果没有参数的调用会阻塞，立即返回 False；否则，做与无参数调用相同的事情时返回 True
当发起调用时如果 timeout 不为 None，则它将阻塞最多 timeout 秒。 请求在此时段时未能成功完成获取则将返回 False。 在其他情况下返回 True

release(n=1)
释放一个信号量，将内部计数器的值增加 n。 当进入时值为零且有其他线程正在等待它再次变为大于零时，则唤醒那 n 个线程

class threading.BoundedSemaphore(value=1)
该类实现有界信号量。有界信号量通过检查以确保它当前的值不会超过初始值。如果超过了初始值，将会引发 ValueError 异常
在大多情况下，信号量用于保护数量有限的资源。如果信号量被释放的次数过多，则表明出现了错误。没有指定时， value 的值默认为1

'''

# 事件
'''
这是线程之间通信的最简单机制之一：一个线程发出事件信号，而其他线程等待该信号
一个事件对象管理一个内部标识，调用 set() 方法可将其设置为 true ，调用 clear() 方法可将其设置为 false ，调用 wait() 方法将进入阻塞直到标识为 true

class threading.Event
实现事件对象的类。事件对象管理一个内部标识，调用 set() 方法可将其设置为true。调用 clear() 方法可将其设置为 false 
调用 wait() 方法将进入阻塞直到标识为true。这个标识初始时为 false 

is_set()
当且仅当内部标识为 true 时返回 True 
isSet 方法是此方法的已弃用别名

set()
将内部标识设置为 true 。所有正在等待这个事件的线程将被唤醒。当标识为 true 时，调用 wait() 方法的线程不会被被阻塞

clear()
将内部标识设置为 false 。之后调用 wait() 方法的线程将会被阻塞，直到调用 set() 方法将内部标识再次设置为 true

wait(timeout=None)
阻塞线程直到内部变量为 true 。如果调用时内部标识为 true，将立即返回。否则将阻塞线程，直到调用 set() 方法将标识设置为 true 或者发生可选的超时
当提供了timeout参数且不是 None 时，它应该是一个浮点数，代表操作的超时时间，以秒为单位（可以为小数）
当且仅当内部旗标在等待调用之前或者等待开始之后被设为真值时此方法将返回 True，也就是说，它将总是返回 True 除非设定了超时且操作发生了超时
'''

# 定时器对象
'''
定时器对象
此类表示一个操作应该在等待一定的时间之后运行 --- 相当于一个定时器。 Timer 类是 Thread 类的子类，因此可以像一个自定义线程一样工作。
与线程一样，通过调用 start() 方法启动定时器。而 cancel() 方法可以停止计时器（在计时结束前）
定时器在执行其操作之前等待的时间间隔可能与用户指定的时间间隔不完全相同

例如：
def hello():
    print("hello, world")

t = Timer(30.0, hello)
t.start()  # after 30 seconds, "hello, world" will be printed

class threading.Timer(interval, function, args=None, kwargs=None)
创建一个定时器，在经过 interval 秒的间隔事件后，将会用参数 args 和关键字参数 kwargs 调用 function。如果 args 为 None （默认值），则会使用一个空列表
如果 kwargs 为 None （默认值），则会使用一个空字典

cancel()
停止定时器并取消执行计时器将要执行的操作。仅当计时器仍处于等待状态时有效
'''
