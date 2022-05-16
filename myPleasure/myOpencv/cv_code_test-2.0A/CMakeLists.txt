cmake_minimum_required(VERSION 3.23.1)

project (cv_code_test-2.0A)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g  -D Debug")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -Wall")

# 创建一个源变量，其中包含要编译的所有cpp文件的链接
set(SOURCES
    src/bilateral_filter.cpp
    src/calc_homography.cpp
    src/has_overlap.cpp
    src/point_on_line.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(cv_code_test-2.0A
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
