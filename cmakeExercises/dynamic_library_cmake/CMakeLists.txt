cmake_minimum_required(VERSION 3.23.1)
project(hello_library_dll) # 随便取个名字就可以
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(myDll SHARED src/hello.cpp)# 唯一的区别,将STATIC改为SHARE
target_include_directories(hello_library_dll PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_executable(hello_binary_dll src/main.cpp)
target_link_libraries(hello_binary_dll PUBLIC ${PROJECT_SOURCE_DIR}/myDll)
