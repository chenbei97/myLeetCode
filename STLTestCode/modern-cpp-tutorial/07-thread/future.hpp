/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 10:29:53
 * @LastEditTime: 2022-05-23 10:40:34
 * @Description: future.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\07-thread\future.hpp
 * @Signature: A boy without dreams
 */
#include <thread>
#include <mutex>
#include <iostream>
#include <future>
using namespace std;
// 期物（Future）表现为 std::future，它提供了一个访问异步操作结果的途径
// 主线程 A 希望新开辟一个线程 B 去执行某个我们预期的任务，并返回我一个结果
// 线程 A 可能正在忙其他的事情，无暇顾及 B 的结果
// 所以我们会很自然的希望能够在某个特定的时间获得线程 B 的结果
// 在封装好要调用的目标后，可以使用 get_future() 来获得一个 std::future 对象，以便之后实施线程同步
void test_future(){
    // 将一个返回值为7的 lambda 表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    std::packaged_task<int()> task([](){return 7;});
    // 获得 task 的期物
    std::future<int> result = task.get_future(); // 在一个线程中执行 task
    std::thread(std::move(task)).detach();
    std::cout << "waiting...";
    result.wait(); // 在此设置屏障，阻塞到期物的完成
    // 输出执行结果
    std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;
}
