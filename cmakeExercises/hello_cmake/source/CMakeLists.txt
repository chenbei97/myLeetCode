# 设定最小的cmake编译版本

# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# 设置编译目录这里是hello_cmake
project (hello_cmake)

# 添加一个执行命令的文件
add_executable(hello_cmake test_cmake.cpp)