本文件夹是用于展示如何生成动态库

为此需要先说明静态库static library和动态库dynamic library的区别

静态库和动态库最本质的区别就是：该库是否被编译进目标（程序）内部

静态库的扩展名一般为".a"或".lib"；动态库的扩展名一般为".so"或".dll"

静态库在编译时会直接整合到目标程序中，编译成功的可执行文件可独立运行
从升级难易度来看明显没有优势，如果函数库更新，需要重新编译

动态库在编译时不会放到连接的目标程序中，即可执行文件无法单独运行
动态函数库在编译的时候，在程序里只有一个"指向"的位置而已
也就是说当可执行文件需要使用到函数库的机制时，程序才会去读取函数库来使用
从产品功能升级角度方便升级，只要替换对应动态库即可，不必重新编译整个可执行文件

link_libraries用在add_executable之前，target_link_libraries用在add_executable之后
link_libraries用来链接静态库，target_link_libraries用来链接导入库，即按照header file + .lib + .dll方式隐式调用动态库的.lib库

同理先说明文件夹文件的结构目录
dynamic_library_cmake
    --CMakeLists.txt
    --src
        main.cpp
        hello.cpp
    --include
        --dynamic hello.h
    --build

cd cmakeExercises/dynamic_library_cmake/build
cmake ..
cmake --build .
.\Debug\dynamic_library_cmake_binary.exe 

遇到的问题：动态库总是提示找不到文件link 1104错误

辅助解决问题链接：
cmake中添加引用动态链接和静态链接库
https://blog.csdn.net/KYJL888/article/details/85109782?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2.pc_relevant_default&utm_relevant_index=5
https://zhuanlan.zhihu.com/p/54253350
link_libraries 和 target_link_libraries 区别
https://blog.csdn.net/jigetage/article/details/84206082?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_default&utm_relevant_index=1
https://blog.csdn.net/Tommy_wxie/article/details/77698627

