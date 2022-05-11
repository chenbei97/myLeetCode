CMake有许多内置配置，可用于编译项目
它们指定了优化级别，以及二进制文件中是否包含调试信息

在Visual Studio的编译模式选项中，一般有四个模式：Debug, Release, RelWithDebInfo, MinSizeRel
Debug版本是调试版本，对代码不做任何优化，可以debug项目中的任意文件
Release版本是发行版本，顾名思义就是当程序开发完成后，程序的一个发布版，它对代码做了优化，因此速度会非常快，但是遗憾的是，release版本无法跟踪代码
RelWithDebInfo版本是一种含有调试信息的Release版本。那么它相当于是结合了Debug和Release版本的优点的一个版本
MinSizeRel是最小体积版本

在CMakeLists.txt中设置：
    SET(CMAKE_BUILD_TYPE "Debug/Release/...”) * 注意：选项需要加上双引号才能生效。
命令行设置：
    cmake  -DCMAKE_BUILD_TYPE=Debug ..
不过在Windows下可能不是这样的，命令行应当这样做：
    cmake --build . --target ALL_BUILD --config RelWithDebInfo

Release - 可指定 the -O3 -DNDEBUG 标记设定Release模式
Debug - 可指定 -g 标记设定Debug模式
MinSizeRel - 可指定 -Os -DNDEBUG 标记设定最小
RelWithDebInfo - 可指定 -O2 -g -DNDEBUG 标记设定

CMake提供的默认构建类型不包括用于优化的编译器标志
对于某些项目，您可能需要设置默认的生成类型，这样就不必记得设置它
要做到这一点，可以将以下内容添加到CMakeLists.txt
```
# 如果未指定任何编译和配置类型，请设置默认生成类型
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  # 将生成类型设置为"RelWithDebInfo"，因为未指定任何类型。    
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # 为cmake gui设置可能的构建类型值
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()
```

cd cmakeExercises/buildType_cmake/build
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build . --target ALL_BUILD --config RelWithDebInfo
.\RelWithDebInfo\buildType_cmake

https://blog.csdn.net/qazw9600/article/details/115267688