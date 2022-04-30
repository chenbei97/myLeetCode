1、先到当前的顶级目录
cd cmakeExercises\\hello_cmake 
采用内部构建的方式，有build、include、src等文件夹，2个txt和1个主cpp文件

2、准备好cmake，下载cmake
https://cmake.org/download/

把cmake的bin加入电脑环境变量
C:\cmake-3.23.1-windows-x86_64\bin

重启终端输入cmake出现提示说明成功
cmake --help可以获取命令帮助
  -S <path-to-source>          = Explicitly specify a source directory.
  -B <path-to-build>           = Explicitly specify a build directory.
  -C <initial-cache>           = Pre-load a script to populate the cache.
  -D <var>[:<type>]=<value>    = Create or update a cmake cache entry.
  -U <globbing_expr>           = Remove matching entries from CMake cache.
  -G <generator-name>          = Specify a build system generator.
  -T <toolset-name>            = Specify toolset name if supported by
                                 generator.
  -A <platform-name>           = Specify platform name if supported by

常见的命令选项
cmake [options] <path-to-source>
cmake [options] -S <path-to-source> -B <path-to-build>
例如【cmake -S .\source -B .\output】,不过这里不使用这种结构

3、这是一个关于如何使用cmake最简单的例子
source只有2个文件，CMakeLists.txt和test_cmake.cpp
output是输出目录

3.1、CMakeLists.txt的主要内容：
cmake_minimum_required(VERSION 3.5)
使用CMake创建项目时，可以指定支持的CMake的最低版本

project (hello_cmake)
CMake构建可以包含一个项目名称，以便在使用多个项目时更容易引用某些变量

add_executable(test_cmake test_cmake.cpp)
add_executable命令指定应从指定的源文件生成可执行文件
在本例中为test_cmake.cpp
add_executable函数的第一个参数是要生成的可执行文件的名称，第二个参数是要编译的源文件列表

# 可以指定g++编译加入2个语句也可以使用默认的cl.exe
SET(CMAKE_C_COMPILER "C:\msys64\mingw64\bin\gcc.exe")
SET(CMAKE_CXX_COMPILER "C:\msys64\mingw64\bin\g++.exe")

3.2、有些人使用的一种简写方法是将项目名称和可执行文件名称相同
这里就是hello_cmake是项目名称,也就是PROJECT_NAME,那么还可以这样写
cmake_minimum_required(VERSION 2.6)
project (hello_cmake)
add_executable(${PROJECT_NAME} test_cmake.cpp)

3.3、运行cmake命令的根文件夹或顶级文件夹称为cmake_BINARY_DIR，是所有二进制文件的根文件夹
CMake支持就地和异地构建和生成二进制文件

可以采取就地生成在与源代码相同的目录结构中生成所有临时生成文件
这意味着所有的makefile和object文件都和普通代码在一起
要创建就地构建目标，请在【根目录】中运行cmake命令，例如
cmake .
但是这样生成的文件很乱，一般都会指定一个输出目录，这里是build

---------------------------------------------
3.4、一般使用的命令是
cd cmakeExercises\\hello_cmake
cd build
cmake ..
cmake --build .
.\Debug\test_cmake.exe
其中..就是顶级目录文件夹hello_cmake
要注意的是如果安装过VS2019就会自动使用MSVC作为默认的环境，而不是GNU
所以针对GNU的命令不会是cmake --build .  而是mingw32-make.exe
---------------------------------------------

执行命令之后，就会产生一些输出结果如下：
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.18362.0 to target Windows 10.0.19044.
-- The C compiler identification is MSVC 19.29.30143.0
-- The CXX compiler identification is MSVC 19.29.30143.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/visual studio/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/visual studio/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/chenbei/VscodeItems/myLeetCode/cmakeExercises/hello_cmake/build

cmake --build .  用于生成二进制文件会自动生成Debug目录
.\Debug\test_cmake.exe 执行二进制文件

4、mingw32-make.exe和来源
如果一开始使用的是GNU的平台而不是MSVC进行编译，则应该使用make代替cmake --build .命令
使用make.exe编译产生二进制文件，但是原本的名称是mingw32-make.exe
这个东西位于C:\msys64\mingw64\bin下，可以手动改名为make方便，但是这里不改
但是这里改不了默认使用的VS2019的MSVC环境编译的，故mingw32-make.exe不需要再使用了

mingw32-make.exe --help 出现以下信息
Usage: mingw32-make [options] [target] ...
Options:
  -b, -m                      Ignored for compatibility.
  -B, --always-make           Unconditionally make all targets.
  -C DIRECTORY, --directory=DIRECTORY
                              Change to DIRECTORY before doing anything.
  -d                          Print lots of debugging information.
  --debug[=FLAGS]             Print various types of debugging information.
  -e, --environment-overrides
                              Environment variables override makefiles.
  -E STRING, --eval=STRING    Evaluate STRING as a makefile statement.
  -f FILE, --file=FILE, --makefile=FILE
                              Read FILE as a makefile.
  -h, --help                  Print this message and exit.
  -i, --ignore-errors         Ignore errors from recipes.
  -I DIRECTORY, --include-dir=DIRECTORY
                              Search DIRECTORY for included makefiles.
  -j [N], --jobs[=N]          Allow N jobs at once; infinite jobs with no arg.
  -k, --keep-going            Keep going when some targets can't be made.
  -l [N], --load-average[=N], --max-load[=N]
                              Don't start multiple jobs unless load is below N.
  -L, --check-symlink-times   Use the latest mtime between symlinks and target.
  -n, --just-print, --dry-run, --recon
                              Don't actually run any recipe; just print them.
  -o FILE, --old-file=FILE, --assume-old=FILE
                              Consider FILE to be very old and don't remake it.
  -O[TYPE], --output-sync[=TYPE]
                              Synchronize output of parallel jobs by TYPE.
  -p, --print-data-base       Print make's internal database.
  -q, --question              Run no recipe; exit status says if up to date.
  -r, --no-builtin-rules      Disable the built-in implicit rules.
  -R, --no-builtin-variables  Disable the built-in variable settings.
  -s, --silent, --quiet       Don't echo recipes.
  --no-silent                 Echo recipes (disable --silent mode).
  -S, --no-keep-going, --stop
                              Turns off -k.
  -t, --touch                 Touch targets instead of remaking them.
  --trace                     Print tracing information.
  -v, --version               Print the version number of make and exit.
  -w, --print-directory       Print the current directory.
  --no-print-directory        Turn off -w, even if it was turned on implicitly.
  -W FILE, --what-if=FILE, --new-file=FILE, --assume-new=FILE
                              Consider FILE to be infinitely new.
  --warn-undefined-variables  Warn when an undefined variable is referenced.

解决本问题参考的解决办法链接：
1、实际解决的命令在下边这个网址出现
https://www.csdn.net/tags/NtTaggzsMTk4NzAtYmxvZwO0O0OO0O0O.html 
2、其他辅助理解的网址列如下，这些都是解决GNU编译的问题不是MSVC
https://zhuanlan.zhihu.com/p/448884264
https://blog.csdn.net/qq_23023937/article/details/123639114
https://blog.csdn.net/Millet827/article/details/26447095
file:///C:/cmake-3.23.1-windows-x86_64/doc/cmake/html/manual/cmake-gui.1.html
https://blog.csdn.net/weixin_42660446/article/details/119650036
https://github.com/ttroy50/cmake-examples/tree/master/01-basic/A-hello-cmake
