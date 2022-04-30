cmake_minimum_required(VERSION 3.2)
project (header_cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 创建一个源变量，其中包含要编译的所有cpp文件的链接
set(SOURCES
    src/hello.cpp
    src/test.cpp
    src/main.cpp
)

# 输出二进制文件的名称为${PROJECT_NAME},编译的文件目录为${SOURCES}
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置应包含在此目标的生成命令中的目录
# 在运行g++或cl时，这些将作为包含的目录
# ${PROJECT_SOURCE_DIR}是顶级目录，即header_cmake
target_include_directories(header_cmake
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)