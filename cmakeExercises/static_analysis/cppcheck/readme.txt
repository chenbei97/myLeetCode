准备工具:cppcheck
1. http://cppcheck.sourceforge.net/ 下载
2. 下载版本为Source code (.tar.gz)
3. 找到readme.txt阅读提示
依据其中说明的命令，执行以下命令，不过需要修改第4条命令
否则默认生成Debug模式会报错，无法访问的代码
mkdir build
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Release 
// 和cmake --build .相比加了要求是Release版本

4. 执行二进制文件，测试是否编译成功
cd bin\Release
testrunner.exe

执行结果：
Testing Complete
Number of tests: 4178
Number of todos: 340
Tests failed: 0

cppcheck.exe 
会打印一些信息

5. 在系统环境变量中添加路径
C:\cppcheck-2.8\build\bin\Release
然后重启vscode,再次输入cppcheck.exe能打印信息
说明全局可用了，cppcheck的准备工作完成

6. cppcheck的简单用法
如果不借助CMakeLists.txt,直接使用就像g++命令行一样
    6.1 cppcheck file1.c
    6.2 cppcheck path 如果path是文件夹则会检查文件夹下所有cpp文件,或者path=src/file.cpp只检查1个文件
    6.3 cppcheck src/a src/b 可以连续的2个path,指定检查2个目录
    6.4 cppcheck -isrc/c src 加上-i可以指定src下的c文件不被检查
    6.5 cppcheck -isrc/b -isrc/c 忽略2个文件夹下各自的2个文件当然也是可以的
其它命令可以见./cppcheck_manual.pdf查看

7. 文件结构目录
--cppcheck
    --cmake
        --modules --FindCppCheck.cmake
        --analysis.cmake
    --subproject1
        --CMakeLists.txt,main1.cpp
    --subproject2
        --CMakeLists.txt,main2.cpp
    --cppcheck_manual.pdf
    --CMakeLists.txt
    --readme.txt
    --build

8. 修改的地方
在--CMakeLists.txt中
find_package(CppCheck)修改为find_package(CPPCHECK)
同理在--analysis.cmake中，将find_package(CppCheck)也修改为find_package(CPPCHECK)
否则cmake .. 执行会有一些警告信息

9. 执行编译命令
cd cmakeExercises\static_analysis\cppcheck\build
cmake .. // cmake -DCMAKE_CXX_CPPCHECK:FILEPATH=cppcheck ..

打开生成的cppcheck_analysis.sln文件，在VS Studio中右击项目生成，就会提示错误
也就是说这里cmake .. 不能直接给出信息，如果在linux平台make analysis命令可以给出信息
但是windows下没有找到类似的命令，所以只能打开VS手动检查

进一步测试：如果没有添加set(CMAKE_CXX_CPPCHECK "cppcheck")
使用cmake ..也可以生成cppcheck_analysis.sln
所以结论是，只要cppcheck配置好，analysis.cmake配置好就自动会生成，只是不能终端显示检查信息

继续尝试执行命令： cmake --build .
会得到提示信息 warning C4789: 缓冲区“tmp”(大小为 10 字节)将溢出；1 字节将在偏移 11
./subproject1/Debug/subproject1.exe // it's ok
./subproject2/Debug/subproject2.exe // it's error

10. 关于CMAKE_LANG_CPPCHECK，可见2个网址的说明
https://www.it1352.com/1791725.html
示例：
set(CMAKE_CXX_CPPCHECK "cppcheck")
add_executable(${PROJECT_NAME} "main.cpp")

命令行：cmake -DCMAKE_CXX_CPPCHECK:FILEPATH=cppcheck ..

其它例子：
find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inconclusive"
            "--force" 
            "--inline-suppr"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
    )
endif()
https://cmake.org/cmake/help/latest/prop_tgt/LANG_CPPCHECK.html 
CMAKE_LANG_CPPCHECK 仅当<LANG> 为 C 或 CXX成立