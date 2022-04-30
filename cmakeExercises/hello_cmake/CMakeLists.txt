# 设定最小的cmake编译版本

# $ cmake --version
cmake_minimum_required(VERSION 3.2)

# 设置编译目录这里是hello_cmake
project (hello_cmake)

# 不想使用msvc,指定g++也可以,不过这里不推荐,有时候g++不能编译某些东西
# SET(CMAKE_C_COMPILER C:/msys64/mingw64/bin/gcc.exe)
# SET(CMAKE_CXX_COMPILER C:/msys64/mingw64/bin/g++.exe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#配置DEBUG模式 编译参数
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g  -D Debug")

#配置RELEASE模式 编译参数
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -Wall")

#配置可执行文件输出存放路径
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

#配置生成链接库输出存放路径
#set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#指定额外头文件路径，相对路径
#include_directories(${CMAKE_SOURCE_DIR}/include)

#添加编译参数


#添加源文件到变量SRC
#aux_source_directory(${CMAKE_SOURCE_DIR}/src/. SRC)

#生成链接库文件
#add_library(swso SHARED ${SRC})
#add_library(static_swso STATIC ${SRC})

#配置生成链接库版本号
#set_target_properties(swso PROPERTIES OUTPUT_NAME "swso_1.0.0")
#set_target_properties(static_swso PROPERTIES OUTPUT_NAME "static_swso_1.0.0")

# 添加一个执行命令的文件,生成二进制可执行文件
add_executable(test_cmake test_cmake.cpp)