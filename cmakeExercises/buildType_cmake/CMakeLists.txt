cmake_minimum_required(VERSION 3.23.1)

# 如果未指定任何编译和配置类型，请设置默认生成类型
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  # 将生成类型设置为"RelWithDebInfo"，因为未指定任何类型。    
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # 为cmake gui设置可能的构建类型值
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# 工程名
project (buildType_cmake)

# 命令执行
add_executable(buildType_cmake main.cpp)