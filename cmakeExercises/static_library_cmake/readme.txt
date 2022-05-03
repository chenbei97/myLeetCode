static_library_cmake的例子是为了说明如何生成静态链接库

和header_cmake中不同在于，include文件夹还有个static文件夹

也就是头文件不再放置于include文件夹，而是include\static文件夹

这样做的目的是尽可能减少链接不同的库时造成的路径相同而导致的重名

所以在main.cpp,hello.cpp中包含hello.h文件时并不是直接的
#include "hello.h"
而是
#include "stayic/hello.h"

该文件夹的目录结构如下
static_library_cmake
    --include
        --static hello.h
    --src hello.cpp,main.cpp
    --build
    CMakeLists.txt
    readme.txt

现在开始执行命令：(事先已经cd cmakeExercises\\static_library_cmake)
cd build
cmake ..
cmake --build .
.\Debug\static_library_cmake_binary.exe 
这里注意static_library_cmake_binary是指定的输出名字而不是static_library_cmake.exe