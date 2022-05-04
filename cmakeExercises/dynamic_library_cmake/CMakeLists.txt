# 方法1、2编译用注释的
# cmake_minimum_required(VERSION 3.23.1)
# project(dynamic_library_cmake) # 随便取个名字就可以
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# add_library(dynamic_library_cmake SHARED src/hello.cpp)# 唯一的区别,将STATIC改为SHARE
# target_include_directories(dynamic_library_cmake PUBLIC ${PROJECT_SOURCE_DIR}/include)
# add_executable(out src/main.cpp)
# target_link_libraries(out PUBLIC dynamic_library_cmake)

# 方法3用下方的
cmake_minimum_required(VERSION 3.23.1)
project(dynamic_library_cmake) # 随便取个名字就可以
option(BUILD_SHARED_LIBS "Specifies the type of libraries (SHARED or STATIC) to build" ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if (BUILD_SHARED_LIBS)
    add_library(dynamic_library_cmake SHARED src/hello.cpp)
    target_compile_definitions(dynamic_library_cmake PUBLIC -DMY_LIB_SHARED_BUILD)
    target_compile_definitions(dynamic_library_cmake PRIVATE -DMY_LIB_EXPORTS)
else()
    add_library(dynamic_library_cmake STATIC ${SrcFiles})
endif()
target_include_directories(dynamic_library_cmake PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_executable(out src/main.cpp)
target_link_libraries(out PUBLIC dynamic_library_cmake)
