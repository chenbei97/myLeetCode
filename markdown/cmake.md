## find_package

```cmake
find_package(<PackageName> [version] [EXACT] [QUIET] [MODULE]  
             [REQUIRED] [[COMPONENTS] [components...]]  
             [OPTIONAL_COMPONENTS components...]  
             [NO_POLICY_SCOPE])
```

- `<PackageName>`：要查找的软件包名称。

- `version`：可选参数，指定要查找的软件包的版本。

- `EXACT`：可选参数，表示必须完全匹配指定的版本。

- `QUIET`：可选参数，表示如果软件包没有找到，不产生错误或警告信息。

- `MODULE`：可选参数，表示使用 Find<PackageName>.cmake 模块来查找软件包。这个模块是由 Find<PackageName>.cmake 文件提供的。只有在模块模式找不到对应的 `Find<PackageName>.cmake` 文件，且又使用了 `CONFIG` 关键字或者没有使用任何关键字的情况下，`find_package` 才会尝试配置模式，这时它会搜索名为 `<PackageName>Config.cmake` 或 `<lowercasePackageName>-config.cmake` 的文件。默认使用的Config模式

- `REQUIRED`：可选参数，表示如果软件包没有找到，会产生一个致命错误，并停止配置过程。

- `COMPONENTS`：可选参数，指定要查找的软件包的组件。可以列出多个组件，用空格分隔。

- `OPTIONAL_COMPONENTS`：可选参数，指定可选的组件。这些组件即使没有找到，也不会产生错误。

- `NO_POLICY_SCOPE`：可选参数，表示不将 find_package 的策略范围设置为当前作用域。这可以在调用 find_package 时避免策略冲突。

  ------

简化常用版本：

```cmake
find_package(<PackageName>  [[COMPONENTS] [components...]]  [REQUIRED]
```

例子：

```cmake
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt4 4.7.0 REQUIRED) # CMake provides a Qt4 find-module
find_package(Qt5Core 5.1.0 REQUIRED) # Qt provides a Qt5 package config file.
find_package(Qt5 5.1.0 COMPONENTS Widgets OPTIONAL_COMPONENTS Xml Sql)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        Charts
        Concurrent
        #NO_MODULE
        CONFIG
        REQUIRED) # 使用NO_MODULE和CONFIG是相同的，默认使用CONFIG
      # C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\lib\cmake这个路径可以看到都是Config.cmake构成的
```

## set

`set()` 命令用于设置变量的值。它可以将值赋给一个或多个变量，并可以选择性地设置变量的属性。

```cmake
set(MY_VARIABLE "Hello, World!")
set(MY_VARIABLE "Hello, World!" CACHE STRING "Description of MY_VARIABLE") #将变量存储在缓存中,指定类型STRING,后边是描述文本
set(MY_LIST "item1" "item2" "item3") # 设置列表
list(APPEND MY_LIST "item4") # 追加变量

if(condition)  
  set(MY_VARIABLE "Value A")  
else()  
  set(MY_VARIABLE "Value B")  
endif()
```

常见命令

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
```

## message

打印变量值，注意要使用${}，否则打印的是字面字符串

```cmake
message(${MY_VARIABLE})
message(${MY_LIST})
message("CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")
message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
```

## target_include_directories

```cmake
target_include_directories(<target> [SYSTEM] [AFTER|BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
```

- `<target>`：指定目标的名称。可以是库或可执行文件的名称。
- `SYSTEM`：可选参数，指定包含目录是系统包含目录。在编译时，编译器将不会在这些目录中搜索头文件。
- `BEFORE`：可选参数，指定在目标的其他包含目录之前添加这些包含目录。
- `<INTERFACE|PUBLIC|PRIVATE>`: 指定包含目录的可见性。可以选择以下选项之一：
  - `INTERFACE`：包含目录对于目标及其使用者都是可见的。
  - `PUBLIC`：包含目录对于目标及其使用者都是可见的，但不适用于目标本身。
  - `PRIVATE`：包含目录仅对目标本身可见。
- `<directory>`：指定一个或多个包含目录的路径。可以使用相对路径或绝对路径。

```cmake
add_executable(my_program main.cpp)  
target_include_directories(my_program PRIVATE include)
```

`add_executable` 命令创建了一个名为 `my_program` 的可执行文件，源文件为 `main.cpp`。然后，`target_include_directories` 命令指定了 `my_program` 的私有包含目录为 `include` 目录。这意味着，在编译 `my_program` 时，编译器将在 `include` 目录中搜索头文件。

## include_directories

```cmake
include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
```

`include_directories` 并不是 CMake 的命令，而是 C++ 的预处理器命令。它用于在编译时告诉编译器在哪里查找头文件。在这个例子中，预处理器除了在常规位置查找头文件外，还会在 "path/to/my/headers" 中查找。这就是 `include_directories` 的基本用法。

```
#include <iostream>  
#include_directories("path/to/my/headers")  
  
#include <myheader.h>  
  
int main() {  
    std::cout << "Hello, World!";  
    return 0;  
}
```

include_directories是全局命令，影响所有目标及其子目录中的目标，只要这些目标在调用点之后添加。这意味着，无论添加多少个目标，只要在相同的CMakeLists.txt文件中使用了include_directories命令，那么这些目标都会拥有相同的头文件搜索路径。

相比之下，target_include_directories是针对特定目标的命令，只对添加的目标有效，对其他目标没有影响。它允许你为每个目标单独设置头文件搜索路径，不会影响其他目标。使用target_include_directories可以让你更加灵活地管理不同目标的头文件搜索路径。

另外，无论是include_directories还是target_include_directories，都可以通过添加参数来设置不同的行为。例如，你可以在include_directories命令中使用AFTER或BEFORE参数来指定头文件搜索路径的相对顺序，也可以在target_include_directories命令中使用SYSTEM参数来指定是否为系统头文件搜索路径。

## add_executable

```cmake
add_executable(<name> [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL] [source1] [source2 ...])
```

- `<name>`：表示生成的可执行文件的名称。
- `[WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL]`：可选参数，对生成的可执行文件进行一些特定设置。例如，如果添加了WIN32，那么在创建的可执行文件上会设置WIN32_EXECUTABLE属性。
- `[source1] [source2 ...]`：指定了生成可执行文件的源文件。

例如，如果你想将main.cpp和helper.cpp编译成一个可执行文件myapp，你可以使用下面的代码:

```cmake
add_executable(myapp main.cpp helper.cpp)
```

在默认情况下，生成的可执行文件会在与调用命令的源树目录相对应的构建树目录中创建。可以使用RUNTIME_OUTPUT_DIRECTORY目标属性来更改此位置，也可以使用OUTPUT_NAME目标属性更改`<name>`到最终文件名。如果给定了WIN32，则将在创建的目标上设置WIN32_EXECUTABLE属性。

## add_library

```cmake
add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] [source1] [source2] [...])
```

- `<name>`：表示库文件的名字，该库文件会根据命令里列出的源文件来创建。它对应于逻辑目标名称，并且在项目中必须是全局唯一的。构建的库的实际文件名是基于本机平台的约定（如lib<name>.a或<name>.lib）构建的。
- `[STATIC | SHARED | MODULE]`：指定要创建的库的类型。
  - STATIC：静态库，在链接其他目标时使用的目标文件存档。.a/.lib
  - OBJECT：创建一个目标对象源，文件编译成目标文件，不将其文件存档或链接为库文件
  - SHARED：动态库，动态链接并在运行时加载的库。如果库不导出任何符号，则不能将其声明为SHARED库。.so/.dll
  - MODULE：模块库，没有链接到其他目标的插件，但可以在运行时使用类似dlopen的功能动态加载。在使用的系统中有效，如果不支持dyld，则被当作SHARED对待。
- `[EXCLUDE_FROM_ALL]`：这个库不会被默认构建（排除到默认目标all之外），除非有其他的组件依赖或者手工构建。
- `[source1] [source2] [...]`：指定生成库的源文件。

在构建SHARED和MODULE库时，CMake会自动设置POSITION_INDEPENDENT_CODE目标属性为ON。这个属性表示生成的库是否包含了位置无关代码（Position Independent Code），这对于共享库和动态链接库是必要的。位置无关代码的特点是可以在内存中的任意位置加载和执行，这使得共享库能够在不同的进程地址空间中重用。

## target_link_directories

“target_link_directories”是一种指令，用于将链接库的目录添加到一个特定的CMake目标中。

具体来说，当你使用CMake来构建一个项目时，你可以用“target_link_directories”指令将一个目标与一个或多个库目录链接起来。例如，假设你的项目需要链接一个名为“mylib”的库，而这个库在“/path/to/mylib”目录中。那么，你可以使用以下指令将这个目录添加到你的目标中：

```cmake
target_link_directories(mytarget PUBLIC/path/to/mylib)
```

这样做可以告诉CMake在链接“mytarget”目标时搜索“/path/to/mylib”目录中的库文件。注意，这只是告诉CMake搜索库文件的路径，实际上还需要使用“target_link_libraries”指令来将库链接到目标中，例如：

```cmake
target_link_libraries(mytarget PUBLIC mylib)
```

## link_directories

```cmake
link_directories([AFTER|BEFORE] directory1 [directory2 ...])
```

添加路径使链接器应在其中搜索库。提供给此命令的相对路径被解释为相对于当前源目录。该命令只适用于在它被调用后创建的target。这些目录将添加到当前CMakeLists.txt文件的LINK_DIRECTORIES目录属性中，并根据需要将相对路径转换为绝对路径。

注意：

1. 如果没有将CMAKE_LINK_DIRECTORIES_BEFORE设置为ON，指定的目录将追加到当前目录列表中。
2. 通过显式使用AFTER或BEFORE，你可以在追加和前置之间进行选择，而与默认值无关。

## add_subdirectory

```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])
```

- source_dir：指定源CMakeLists.txt和代码文件所在的目录。如果它是相对路径，则将相对于当前目录进行评估，但它也可能是绝对路径。
- binary_dir：指定放置输出文件的目录。如果它是相对路径，则将相对于当前输出目录进行评估，但它也可能是绝对路径。如果未指定binary_dir，则将在扩展任何相对路径之前使用source_dir的值。
- EXCLUDE_FROM_ALL：可选参数，如果提供，则默认情况下，子目录中的target将不包括在父目录的ALL target中，并且将从IDE项目文件中排除。用户必须在子目录中显式构建target。这适用于子目录包含有用但不是必须的项目的单独部分的情况。
- SYSTEM：可选参数，如果提供，则子目录的SYSTEM目录属性将设置为true。此属性用于初始化在该子目录中创建的每个target的SYSTEM属性。

注意：在子目录的CMakeLists.txt文件中，必须显式添加自己的project命令调用，以便在子目录中生成完整的构建系统。

## 预定义变量

```cmake
message(${CMAKE_CURRENT_LIST_DIR}) # D:/ClionProjects/Test/test5/label
message(${PROJECT_BINARY_DIR})#D:/ClionProjects/Test/test5/cmake-build-debug
message(${PROJECT_SOURCE_DIR})# D:/ClionProjects/Test/test5
message(${CMAKE_SOURCE_DIR}) # ClionProjects/Test/test5
message(${CMAKE_BINARY_DIR}) # D:/ClionProjects/Test/test5/cmake-build-debug
message(${CMAKE_CURRENT_SOURCE_DIR}) # D:/ClionProjects/Test/test5/label
message(${CMAKE_CURRENT_BINARY_DIR})# D:/ClionProjects/Test/test5/cmake-build-debug/label
```

### CMAKE_CURRENT_SOURCE_DIR、CMAKE_CURRENT_LIST_DIR

如果有个子目录label，这个路径是`# D:/ClionProjects/Test/test5/label`

### CMAKE_CURRENT_BINARY_DIR

如果有个子目录label，这个路径是`# D:/ClionProjects/Test/test5/cmake-build-debug/label`

### CMAKE_SOURCE_DIR、PROJECT_SOURCE_DIR

如果有个子目录label，这个路径是 `D:/ClionProjects/Test/test5`

工程顶级目录，`D:/ClionProjects/Test/test5`

### CMAKE_BINARY_DIR、PROJECT_BINARY_DIR

如果有个子目录label，这个路径是 `D:/ClionProjects/Test/test5/cmake-build-debug`

工程的exe输出目录，`D:/ClionProjects/Test/test5/cmake-build-debug`

### PROJECT_NAME

工程名

## 定义变量

### EXECUTABLE_OUTPUT_PATH，CMAKE_RUNTIME_OUTPUT_DIRECTORY

指定exe生成的目录，含义相同

```cmake
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
```

### CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS

```cmake
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
```

### LIBRARY_OUTPUT_PATH

```cmake
SET(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/../bin)
```

