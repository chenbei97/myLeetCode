/*
 * @Author: chenbei
 * @Date: 2022-08-09 08:11:52
 * @LastEditTime: 2022-08-09 08:31:08
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap02\\parallel_accumulate.cpp
 * @Description: accumulate的并行方式
 * @Signature: A boy without dreams
 */
#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template<typename Iterator,typename T>
struct accumulate_block
{
    void operator()(Iterator first,Iterator last,T& result)// 重载()是当作函数对象使用可以传入thread
    {
        result=std::accumulate(first,last,result); // 后一块以前一块的结果作为初始值继续计算累加值
    }
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
    unsigned long const length=std::distance(first,last);

    if(!length) // 如果容器没有元素直接返回
        return init;

    unsigned long const min_per_thread=25; // 每个线程至少处理25个元素
    unsigned long const max_threads=
        (length+min_per_thread-1)/min_per_thread; // 只有超过25个元素max_threads才会大于1 => (x-1)/25+1

    unsigned long const hardware_threads=
        std::thread::hardware_concurrency(); // 当前硬件支持的线程数 16

    unsigned long const num_threads=//hardware_threads!=0为true,所以选hardware_threads,再取它和max_threads的最小值,一般情况就是max_threads
        std::min(hardware_threads!=0?hardware_threads:2,max_threads);

    unsigned long const block_size=length/num_threads; // 所以实际每个线程处理的元素个数就是 x/num_threads

    std::vector<T> results(num_threads); // 容器的size就是线程的个数num_threads
    std::vector<std::thread>  threads(num_threads-1); // 有1次计算是主线程进行完成

    Iterator block_start=first; // 最开始的块是从first开始
    for(unsigned long i=0;i<(num_threads-1);++i) // 每个线程处理的方式相同
    {
        Iterator block_end=block_start;
        std::advance(block_end,block_size); // 每次循环[block_start,block_end)都会平移block_size个距离
        threads[i]=std::thread( // 当前线程处理这部分[block_start,block_end)的数据
            accumulate_block<Iterator,T>(),//函数对象构造线程
            block_start,block_end,std::ref(results[i]));//参数[block_start,block_end)和结果,结果必须是results所以是引用
        block_start=block_end; // 更新block_start的位置,平移
    }
    accumulate_block<Iterator,T>()(block_start,last,results[num_threads-1]);// 最后1块的计算主线程完成即可
    
    std::for_each(threads.begin(),threads.end(), // 把所有新线程都加入,主线程会等待子线程结束
        std::mem_fn(&std::thread::join));// mem_fnn可以传入要执行的策略(函数指针,函数对象,匿名函数等)

    return std::accumulate(results.begin(),results.end(),init);//这些块的结果还要加在一起
}

int main()
{
    std::vector<int> vi;
    for(int i=0;i<1000000000;++i)
    {
        vi.push_back(10);
    }
    int sum=parallel_accumulate(vi.begin(),vi.end(),5);
    std::cout<<"sum="<<sum<<std::endl;
}

/*
cd C++HighConcurrency/chap02
g++ parallel_accumulate.cpp -o parallel_accumulate
.\parallel_accumulate
*/