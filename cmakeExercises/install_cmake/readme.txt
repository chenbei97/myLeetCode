这个文件夹是用于说明如何安装install的

注意在linux命令是make install，在indows是cmake --install .

参考链接为官方文档：
https://cmake.org/cmake/help/latest/guide/tutorial/index.html
关于install的例子：
https://cmake.org/cmake/help/latest/guide/tutorial/Installing%20and%20Testing.html
不过本例是来源于：
https://github.com/ttroy50/cmake-examples/tree/master/01-basic/E-installing

本例的文件结构目录为：
install_cmake 
    CMakeLists.txt
    readme.txt
    install_cmake.conf
    --src hello.cpp,main.cpp
    --include hello.h
    --build
    --install
    --lib
    --etc

conf是配置文件，可以用txt打开，只有以下内容
"# Sample configuration file that could be installed"
即"可以安装的示例配置文件"

CMake提供了添加make安装目标的功能，允许用户安装二进制文件、库和其他文件
安装位置由命令<CMAKE_INSTALL_PREFIX>指定，这个前缀可以使用CMAKE或通过使用CMAKE调用CMAKE来设置
linux命令格式为：<cmake .. -DCMAKE_INSTALL_PREFIX=/install/location>
windows命令格式为：<cmake --install . --prefix "/install/location">

安装的文件由install()函数控制 ，前边是TARGET、FILES或者DIRECTORY，指定安装的目标、文件或是目录，然后DESTINATION是按照去向

现在开始执行命令
cd cmakeExercises/install_cmake/build
cmake ..
[cmake -D CMAKE_BUILD_TYPE=Release .. ]
cmake --build . --target ALL_BUILD --config Release
cmake --build . --target ALL_BUILD --config Debug
.\Debug\install_cmake_binary.exe
.\Release\install_cmake_binary.exe
cmake --install . --prefix "C:/Users/chenb/VscodeItems/myLeetCode/cmakeExercises/install_cmake/" 
..\bin\install_cmake_binary.exe


// 一下是尝试解决问题的链接但是都不行，最后把命令cmake --build .变为cmake --build . --target ALL_BUILD --config Release就可以了
https://qa.1r1g.com/sf/ask/1331698161/

// 1、设置默认Realease：https://blog.csdn.net/qq_41961459/article/details/113945069
IF (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
ENDIF()

// 2、如何设置Debug和Release编译模式 ： https://blog.csdn.net/while0/article/details/89175247?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_default&utm_relevant_index=2
cd Release  
cmake -D CMAKE_BUILD_TYPE=Release ..  
cmake --build .

// 3、设置Build Type (Debug/Release) https://blog.csdn.net/CaspianSea/article/details/41442421?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-4.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-4.pc_relevant_default&utm_relevant_index=8
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
set(CMAKE_BUILD_TYPE "Debug")
cmake  -D CMAKE_BUILD_TYPE=Debug ..

// 4、Debug和Release编译方式的本质区别 https://blog.csdn.net/stf1065716904/article/details/74197393?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-2
Debug和Release编译方式的本质区别
Debug 通常称为调试版本，它包含调试信息，并且不作任何优化，便于程序员调试程序。
Release 称为发布版本，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用。
Debug 和 Release 的真正秘密，在于一组编译选项。
实际上，Debug 和 Release 并没有本质的界限，他们只是一组编译选项的集合，编译器只是按照预定的选项行动
事实上，我们甚至可以修改这些选项，从而得到优化过的调试版本或是带跟踪语句的发布版本


// 5、CMAKE 指定编译调试版本或者发布版本 https://blog.csdn.net/su_787910081/article/details/45335091?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2.pc_relevant_paycolumn_v3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2.pc_relevant_paycolumn_v3&utm_relevant_index=5
<span style="font-size:18px;"># CMAKE 中可以像Windows 一样指定编译成Debug 版本还是Release 版本
# 这个在使用cmake 命令时指定
# 如：cmake -DCMAKE_BUILD_TYPE=Debug/Release ../source_code
IF (CMAKE_BUILD_TYPE MATCHES "Debug" 
        OR CMAKE_BUILD_TYPE MATCHES "None")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Debug")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Release")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "RelWitchDebInfo")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is RelWitchDebInfo")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is MinSizeRel")
ELSE ()
    MESSAGE(STATUS "unknown CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
ENDIF ()</span>

// 6、博客cmake的使用 http://www.cppblog.com/tx7do/archive/2010/08/19/124000.html




