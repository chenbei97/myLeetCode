cmake_minimum_required(VERSION 3.23.1)

# 生成的VS项目名称
project(install_cmake)

# IF (NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "Release" CACHE STRING
#         "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
# ENDIF()

# set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to release")

# if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
#     set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")
#     message("Debug mode:${CMAKE_C_FLAGS_DEBUG}")

# elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
#     set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3")
#     message("Release mode:${CMAKE_C_FLAGS_RELEASE}")
# else()
#     message("else:${CMAKE_BUILD_TYPE}")
#     message("else:${CMAKE_C_FLAGS_RELEASE}")
# endif()

# 添加动态库
add_library(install_cmake_lib SHARED src/hello.cpp) 
# 指定动态库包含的目录
# 动态库根据之前dynamic_library_cmake的例子,记得要在hello.h加上限定<__declspec(dllexport)>
target_include_directories(install_cmake_lib 
    PUBLIC ${PROJECT_SOURCE_DIR}/include) 

# 可执行的二进制命令
add_executable(install_cmake_binary
    src/main.cpp
)

# 链接二进制文件和动态库
target_link_libraries( install_cmake_binary
    PRIVATE 
    install_cmake_lib
)

# install函数的参数是先TARGRT然后DESTINATION

# 设置安装的二进制文件路径为bin
install (TARGETS install_cmake_binary
    DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# 安装动态库
install (TARGETS install_cmake_lib
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)


# install (TARGETS install_cmake_lib
#     LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
#     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# 安装头文件包含的目录,故指定DIRECTORY
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION ${PROJECT_SOURCE_DIR}/include)

# 要是只安装某个头文件可以这样
# install(FILES "${PROJECT_BINARY_DIR}/include/installing/hello.h"
#     DESTINATION include
# )

# 安装配置文件,指定安装的是文件FILES,安装去向是etc
install (FILES install_cmake.conf
    DESTINATION ${PROJECT_SOURCE_DIR}/etc)