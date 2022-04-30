这个文件夹的项目稍微提升了一下难度

在hello_cmake文件夹中其实提到过如何内部构建
--hello_cmake
    --CMakeLists.txt
    --build
    --include
    --src
    --test_cmake.cpp(main.cpp)
    --readme.txt
只不过src,include没有包含东西罢了,同时test_cmake.cpp不是用main命名的
因为只有1个cpp文件,没有单纯的头文件--即include，也没有头文件的实现--即src的定义文件

现在本文件夹header_cmake文件夹的结构树如下
--header_cmake
    --CMakeLists.txt
    --build
    --include hello.h
    --src --main.cpp,hello.cpp,test.cpp
    --readme.txt

因为输出main.exe名字不好看，所以用到了提到的命令
set(SOURCES src/hello.cpp src/test.cpp src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
输出的名称和项目名称将会一致，即header_cmake.exe

此外还新增了target_include_directories命令用于包含头文件
target_include_directories(header_cmake PRIVATE ${PROJECT_SOURCE_DIR}/include)

接下来执行的命令是相同的，假设已经在header_cmake文件夹顶级目录(cd header_cmake)
cd build
cmake ..
cmake --build .
.\Debug\header_cmake.exe

执行成功！