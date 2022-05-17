代码生成对于从公共描述文件创建不同语言的源代码非常有用
这可以减少手动编写代码的数量，并提高互操作性。

示例显示了使用CMake中的变量以及一些常用工具生成代码。
配置文件-使用CMake configure_file函数注入CMake变量。
协议缓冲区-使用谷歌协议缓冲区生成C++源代码。

要在文件中进行变量替换，可以使用CMake中的configure_file()函数
这个函数的核心参数是源文件和目标文件
允许使用${VARIABLE}语法或@VARIABLE@来定义变量,就像定义CMake变量一样
例如ver.h.in会生成新文件ver.h,包含于目录PROJECT_BINARY_DIR中

configure-files文件夹文件目录结构：
    --build
    --main.cpp
    --ver.h.in
    --path.h.in
    --CMakeLists.txt

cd cmakeExercises\\codeGeneration_cmake\\configure-files\\build
cmake .. 
cmake --build .
./Debug/code_generation # Hello Version 0.2.1!

编译结束后可以看到build目录下自动生成了path.h和ver.h文件