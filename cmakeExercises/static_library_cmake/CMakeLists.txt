cmake_minimum_required(VERSION 3.2)
project(static_library_cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 这里的不同点,多了add_libary命令,用于从源文件创建库
# 这里要指定源文件的目录在哪里
# 添加的是src目录的cpp文件,没有main
# 与add_library调用的源代码关联,指定生成的库名字为static_library_cmake.lib
add_library(static_library_cmake STATIC 
    src/hello.cpp
)

# 指定要包含的目录,去生成动态库static_library_cmake.lib
# PUBLIC的含义是当编译这个lib或者任何链接到这个库的程序时都可以包含此目录
# PRIVATE-该目录被添加到此目标的include目录中
# INTERFACE-该目录被添加到链接此库的任何目标的包含目录中
# PUBLIC-如上所述,它包括在此库中,也包括链接此库的任何目标
# PUBLIC相当于PRIVATE+INTERFACE

target_include_directories(static_library_cmake
    PUBLIC  # 这里的区别是变成了public,而非private
        ${PROJECT_SOURCE_DIR}/include
)

# 添加执行命令,指定生成的二进制文件为static_library_cmake_binary
# 为了避免和static_library_cmake.lib冲突,这里指定了一个名字,加上了_binary
add_executable(static_library_cmake_binary
    src/main.cpp
)

# 当创建一个将使用你的库的可执行文件时,你必须告诉编译器关于库的信息
# 这可以使用target_link_libraries函数完成
# 将static_library_cmake.lib库目标与static_library_cmake_binary二进制目标链接起来
# 它还将从链接库目标传播任何具有公共或接口作用域的include目录
# 相当于告诉编译器作以下的等同命令
# /usr/bin/c++ CMakeFiles/static_library_cmake.dir/src/main.cpp.o -o static_library_cmake_binary -rdynamic static_library_cmake.lib
target_link_libraries(static_library_cmake_binary
    PRIVATE 
    static_library_cmake
)