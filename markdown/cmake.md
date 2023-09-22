## cmake命令总结

### cmake --help

```cmake
  --help-full [<file>]         = Print all help manuals and exit.
  --help-manual <man> [<file>] = Print one help manual and exit.
  --help-manual-list [<file>]  = List help manuals available and exit.
  --help-command <cmd> [<file>]= Print help for one command and exit.
  --help-command-list [<file>] = List commands with help available and exit.
  --help-commands [<file>]     = Print cmake-commands manual and exit.
  --help-module <mod> [<file>] = Print help for one module and exit.
  --help-module-list [<file>]  = List modules with help available and exit.
  --help-modules [<file>]      = Print cmake-modules manual and exit.
  --help-policy <cmp> [<file>] = Print help for one policy and exit.
  --help-policy-list [<file>]  = List policies with help available and exit.
  --help-policies [<file>]     = Print cmake-policies manual and exit.
  --help-property <prop> [<file>]
```

### cmake --help-module-list

```
AddFileDependencies
AndroidTestUtilities
BundleUtilities
CMakeAddFortranSubdirectory
CMakeBackwardCompatibilityCXX
CMakeDependentOption
CMakeDetermineVSServicePack
CMakeExpandImportedTargets
CMakeFindDependencyMacro
CMakeFindFrameworks
CMakeFindPackageMode
CMakeForceCompiler
CMakeGraphVizOptions
CMakePackageConfigHelpers
CMakeParseArguments
CMakePrintHelpers
CMakePrintSystemInformation
CMakePushCheckState
CMakeVerifyManifest
CPack
CPackArchive
CPackBundle
CPackComponent
CPackCygwin
CPackDMG
CPackDeb
CPackFreeBSD
CPackIFW
CPackIFWConfigureFile
CPackNSIS
CPackNuGet
CPackProductBuild
CPackRPM
CPackWIX
CSharpUtilities
CTest
CTestCoverageCollectGCOV
CTestScriptMode
CTestUseLaunchers
CheckCCompilerFlag
CheckCSourceCompiles
CheckCSourceRuns
CheckCXXCompilerFlag
CheckCXXSourceCompiles
CheckCXXSourceRuns
CheckCXXSymbolExists
CheckCompilerFlag
CheckFortranCompilerFlag
CheckFortranFunctionExists
CheckFortranSourceCompiles
CheckFortranSourceRuns
CheckFunctionExists
CheckIPOSupported
CheckIncludeFile
CheckIncludeFileCXX
CheckIncludeFiles
CheckLanguage
CheckLibraryExists
CheckLinkerFlag
CheckOBJCCompilerFlag
CheckOBJCSourceCompiles
CheckOBJCSourceRuns
CheckOBJCXXCompilerFlag
CheckOBJCXXSourceCompiles
CheckOBJCXXSourceRuns
CheckPIESupported
CheckPrototypeDefinition
CheckSourceCompiles
CheckSourceRuns
CheckStructHasMember
CheckSymbolExists
CheckTypeSize
CheckVariableExists
Dart
DeployQt4
Documentation
ExternalData
ExternalProject
FeatureSummary
FetchContent
FindALSA
FindASPELL
FindAVIFile
FindArmadillo
FindBISON
FindBLAS
FindBZip2
FindBacktrace
FindBoost
FindBullet
FindCABLE
FindCUDA
FindCUDAToolkit
FindCURL
FindCVS
FindCoin3D
FindCups
FindCurses
FindCxxTest
FindCygwin
FindDCMTK
FindDart
FindDevIL
FindDoxygen
FindEXPAT
FindEnvModules
FindFLEX
FindFLTK
FindFLTK2
FindFontconfig
FindFreetype
FindGCCXML
FindGDAL
FindGIF
FindGLEW
FindGLUT
FindGSL
FindGTK
FindGTK2
FindGTest
FindGettext
FindGit
FindGnuTLS
FindGnuplot
FindHDF5
FindHSPELL
FindHTMLHelp
FindHg
FindICU
FindITK
FindIce
FindIconv
FindIcotool
FindImageMagick
FindIntl
FindJNI
FindJPEG
FindJasper
FindJava
FindKDE3
FindKDE4
FindLAPACK
FindLATEX
FindLTTngUST
FindLibArchive
FindLibLZMA
FindLibXml2
FindLibXslt
FindLibinput
FindLua
FindLua50
FindLua51
FindMFC
FindMPEG
FindMPEG2
FindMPI
FindMatlab
FindMotif
FindMsys
FindODBC
FindOpenACC
FindOpenAL
FindOpenCL
FindOpenGL
FindOpenMP
FindOpenSP
FindOpenSSL
FindOpenSceneGraph
FindOpenThreads
FindPHP4
FindPNG
FindPackageHandleStandardArgs
FindPackageMessage
FindPatch
FindPerl
FindPerlLibs
FindPhysFS
FindPike
FindPkgConfig
FindPostgreSQL
FindProducer
FindProtobuf
FindPython
FindPython2
FindPython3
FindPythonInterp
FindPythonLibs
FindQt
FindQt3
FindQt4
FindQuickTime
FindRTI
FindRuby
FindSDL
FindSDL_gfx
FindSDL_image
FindSDL_mixer
FindSDL_net
FindSDL_sound
FindSDL_ttf
FindSQLite3
FindSWIG
FindSelfPackers
FindSquish
FindSubversion
FindTCL
FindTIFF
FindTclStub
FindTclsh
FindThreads
FindUnixCommands
FindVTK
FindVulkan
FindWget
FindWish
FindX11
FindXCTest
FindXMLRPC
FindXalanC
FindXercesC
FindZLIB
Findosg
FindosgAnimation
FindosgDB
FindosgFX
FindosgGA
FindosgIntrospection
FindosgManipulator
FindosgParticle
FindosgPresentation
FindosgProducer
FindosgQt
FindosgShadow
FindosgSim
FindosgTerrain
FindosgText
FindosgUtil
FindosgViewer
FindosgVolume
FindosgWidget
Findosg_functions
FindwxWidgets
FindwxWindows
FortranCInterface
GNUInstallDirs
GenerateExportHeader
GetPrerequisites
GoogleTest
InstallRequiredSystemLibraries
MacroAddFileDependencies
ProcessorCount
SelectLibraryConfigurations
SquishTestScript
TestBigEndian
TestCXXAcceptsFlag
TestForANSIForScope
TestForANSIStreamHeaders
TestForSSTREAM
TestForSTDNamespace
UseEcos
UseJava
UseJavaClassFilelist
UseJavaSymlinks
UsePkgConfig
UseSWIG
Use_wxWindows
UsewxWidgets
WriteBasicConfigVersionFile
WriteCompilerDetectionHeader
```



### cmake --help-manual-list

```
ccmake(1)
cmake(1)
cmake-buildsystem(7)
cmake-commands(7)
cmake-compile-features(7)
cmake-developer(7)
cmake-env-variables(7)
cmake-file-api(7)
cmake-generator-expressions(7)
cmake-generators(7)
cmake-gui(1)
cmake-language(7)
cmake-modules(7)
cmake-packages(7)
cmake-policies(7)
cmake-presets(7)
cmake-properties(7)
cmake-qt(7)
cmake-server(7)
cmake-toolchains(7)
cmake-variables(7)
cpack(1)
cpack-generators(7)
```



### cmake --help-command-list

单个命令的帮助

```cmake
cmake --help-command include_directories
```

```cmake
add_compile_definitions
add_compile_options
add_custom_command
add_custom_target
add_definitions
add_dependencies
add_executable
add_library
add_link_options
add_subdirectory
add_test
aux_source_directory
block
break
build_command
build_name
cmake_host_system_information
cmake_language
cmake_minimum_required
cmake_parse_arguments
cmake_path
cmake_policy
configure_file
continue
create_test_sourcelist
ctest_build
ctest_configure
ctest_coverage
ctest_empty_binary_directory
ctest_memcheck
ctest_read_custom_files
ctest_run_script
ctest_sleep
ctest_start
ctest_submit
ctest_test
ctest_update
ctest_upload
define_property
else
elseif
enable_language
enable_testing
endblock
endforeach
endfunction
endif
endmacro
endwhile
exec_program
execute_process
export
export_library_dependencies
file
find_file
find_library
find_package
find_path
find_program
fltk_wrap_ui
foreach
function
get_cmake_property
get_directory_property
get_filename_component
get_property
get_source_file_property
get_target_property
get_test_property
if
include
include_directories
include_external_msproject
include_guard
include_regular_expression
install
install_files
install_programs
install_targets
link_directories
link_libraries
list
load_cache
load_command
macro
make_directory
mark_as_advanced
math
message
option
output_required_files
project
qt_wrap_cpp
qt_wrap_ui
remove
remove_definitions
return
separate_arguments
set
set_directory_properties
set_property
set_source_files_properties
set_target_properties
set_tests_properties
site_name
source_group
string
subdir_depends
subdirs
target_compile_definitions
target_compile_features
target_compile_options
target_include_directories
target_link_directories
target_link_libraries
target_link_options
target_precompile_headers
target_sources
try_compile
try_run
unset
use_mangled_mesa
utility_source
variable_requires
variable_watch
while
write_file
```



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

## find_dependency



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
add_library(${DLLNAME} SHARED
        ${INTERFACE_SOURCES}
        ${INTERFACE_HEADERS}
        )

target_include_directories(${DLLNAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Component/inc
        )
        
add_executable(${PROJECT_NAME}  main.cpp initapp.h initapp.cpp
        ${QRC_SOURCE_FILE}
        ${PROJECT_SOURCE_DIR}/bin/theme/dark/darkstyle.qrc)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Component/inc
        ${PROJECT_SOURCE_DIR}/Interface/inc
        )
```

interface可以引用component的头文件，这样interface的头文件在使用的时候，不需要这样

```c++
#include "../../../include/widgets/gradienthiddenwidget.h"
```

可以改用

```c++
#include "widgets/gradienthiddenwidget.h"
```

不再需要通过复制头文件目录来实现引用，比较方便。

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

## add_definitions

添加宏定义，常用于声明某些类导出或者导入使用。

```cmake
add_definitions(-DCOMPONENT_LIBRARY=0) # 添加预定义宏,=号不能有空格,用于指定类导出或导入
```

```c++
#if defined(COMPONENT_LIBRARY) // 这个宏在component的cmakelist定义过,不能直接使用Q_DECL_EXPORT,因为main.cpp需要导入符号才能使用
# define COMPONENT_IMEXPORT Q_DECL_EXPORT
#else
# define COMPONENT_IMEXPORT Q_DECL_IMPORT
#endif
```

## qt5_add_resources、QT5_ADD_RESOURCES

必须带前缀5，这3行命令都可以，然后在add_executable进行引用，或者直接引用也是可以的

这个设置只需要在顶层设置过就行，无需在子目录继续设置

```cmake
qt5_add_resources(QRC_SOURCE_FILE ${PROJECT_SOURCE_DIR}/images.qrc)
QT5_ADD_RESOURCES(QRC_SOURCE_FILE ${PROJECT_SOURCE_DIR}/images.qrc)
set(QRC_SOURCE_FILE ${PROJECT_SOURCE_DIR}/images.qrc)

add_executable(${PROJECT_NAME}  main.cpp initapp.h initapp.cpp
        ${QRC_SOURCE_FILE}
        app.rc
        ${PROJECT_SOURCE_DIR}/bin/theme/dark/darkstyle.qrc) # 直接引用
```

## add_custom_command

用于向目标添加自定义规则，并通过执行命令生成输出。

```cmake
add_custom_command(  
  OUTPUT output_file [MAIN_DEPENDENCY input_file]  
  COMMAND command [COMMAND_EXPAND_LISTS] [COMMAND1 [COMMAND2 ...]]  
  [COMMAND_OUTPUT cmd_output]  # 命令输出，可能是要拷贝的文件
  [COMMAND_INPUT cmd_input]  # 命令输入，要拷贝的目标地址
  [BYPRODUCTS byproducts]  
  [WORKING_DIRECTORY dir]  
  [DEPENDENCIES dep1 dep2 ...]  
  [IMPLICIT_DEPENDENCIES dep1 dep2 ...]  
  [VARIABLES var1 var2 ...]  
  [CMAKE_COMMAND_LINE_ADVANCED]  
  [USES_TERMINAL]  
)
```

- `OUTPUT`指定命令预期生成的输出文件。 如果输出名是相对路径，它将相对于当前源目录相对应的构建树目录进行解释。

- `COMMAND` 是一个可选项，表示要执行的命令行。 如果指定了多个 `COMMAND`，它们将按顺序执行，但不一定组成有状态的shell或batch脚本。

- `MAIN_DEPENDENCY` 指定命令的主输入源文件。 每个源文件最多可以有一个命令将其指定为其主要依赖项。 编译命令(即用于库或可执行文件)算作隐式主要依赖项，它会被自定义命令规范悄悄覆盖。

  ```cmake
  add_custom_command(  
    OUTPUT hello-world.o  
    COMMAND echo "Hello, World!" > ${CMAKE_CURRENT_BINARY_DIR}/hello-world.c  
    DEPENDENCIES world.c  
  )
  ```

  这个例子中，我们添加了一个自定义命令，该命令生成一个名为`hello-world.o`的输出文件。 命令行是`echo "Hello, World!" > ${CMAKE_CURRENT_BINARY_DIR}/hello-world.c`，它将一个字符串写入到一个文件中。 该命令依赖于`world.c`文件。

  ```cmake
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD # 目标建立后执行
      COMMAND ${CMAKE_COMMAND} -E make_directory # 创建目录的命令
      "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
      # $<TARGET_FILE_DIR:Test01>/plugins/platforms/ => bin/plugins/platforms/
  ```

  - `TARGET ${PROJECT_NAME} POST_BUILD`：表示这个命令是在构建目标`${PROJECT_NAME}`之后执行的。
  - `COMMAND ${CMAKE_COMMAND} -E make_directory`：这表示执行的命令是使用CMake的命令行工具**创建一个目录**。${CMAKE_COMMAND} =  D:/CLion 2023.1.3/bin/cmake/win/x64/bin/cmake.exe
  - `\"$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/\"`：这是要创建的目录的路径。`$<TARGET_FILE_DIR:${PROJECT_NAME}>`是一个CMake变量，它会被替换为`${PROJECT_NAME}`的构建输出目录，也就是**bin目录**。所以这个命令会在构建输出目录下创建一个`plugins/platforms/`的目录。

  

```cmake
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy # 执行拷贝操作
    "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/"
)  # 有了目录把这个文件拷贝
```

```cmake
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy # bin/Qt5Cored.dll拷贝进来
    "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
) # 拷贝到bin目录
```

**这里给出将sql和image插件文件夹复制的命令**，这个要放在最后边执行。

```cmake
set(CMAKE_SQLDRIVERS_PATH "${CMAKE_PREFIX_PATH}/plugins/sqldrivers")
set(CMAKE_IMAGEFORMATS_PATH "${CMAKE_PREFIX_PATH}/plugins/imageformats")
message(${CMAKE_SQLDRIVERS_PATH})
message(${CMAKE_IMAGEFORMATS_PATH})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory # 执行拷贝操作
        "${CMAKE_SQLDRIVERS_PATH}"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/sqldrivers"
        )
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory # 执行拷贝操作
        "${CMAKE_IMAGEFORMATS_PATH}"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/imageformats"
        )
```

这个命令有效的替代了直接使用file命令的写法。

```cmake
set(CMAKE_SQLDRIVERS_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/plugins/sqldrivers")
file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/sqldrivers")
file(COPY ${CMAKE_SQLDRIVERS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # 整个文件夹要复制过来否则找不到驱动
set(CMAKE_IMAGEFORMATS_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/plugins/imageformats")
file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/imageformats")
file(COPY ${CMAKE_IMAGEFORMATS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # qpixmap加载jpg会失败
```



## utf-8

这2行命令只需要在主工程设置一次即可，也就是顶层的CMakeList.txt，要在add_executable之前

```cmake
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
```

如果是clion还有一个方法，就是在cmake 编译选项这里添加

```cmake
-D CMAKE_CXX_FLAGS="/utf-8" CMAKE_C_FLAGS="/utf-8"
```

参考：[解决 CLion + MSVC 下的字符编码问题](https://www.cnblogs.com/Chary/p/13608011.html#:~:text=解决办法也简单，加上命令行开关就行了： utf-8 或者 source-charset%3Autf-8 %2Fexecution-charset%3Autf-8,参见MSVC文档>> 默认创建的项目是 CMake 的，在 CMakeList.txt 中加入如下内容即可)

以下不起作用：

```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /source-charset:utf-8")

set(CMAKE_CXX_STANDARD_ENCODED_FILES ON)

add_compile_options(-fexec-charset=UTF-8 -finput-charset=UTF-8)

if(MSVC)
    set(CMAKE_RC_CHARSET utf8)
    set(CMAKE_RC_SOURCE_CHARSET utf8)
    set(CMAKE_RC_STRING_CHARSET utf8)
endif()
```



## file

第一种用来递归取到指定目录的所有文件，支持通配符。

```cmake
file(GLOB_RECURSE COMPONENT_HEADERS "inc/*.h")
file(GLOB_RECURSE COMPONENT_SOURCES "src/*.cpp")
```

第二种可以用来复制文件。

```cmake
file(GLOB public_headers "inc/*.h")
file(COPY ${flow_headers} DESTINATION ${PROJECT_SOURCE_DIR}/Interface/inc)

file(GLOB flow_headers "inc/tables/*.h")
file(COPY ${flow_headers} DESTINATION ${PROJECT_SOURCE_DIR}/Interface/inc/tables)

set(CMAKE_SQLDRIVERS_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/plugins/sqldrivers")
file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/sqldrivers")
file(COPY ${CMAKE_SQLDRIVERS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # 整个文件夹要复制过来否则找不到驱动
set(CMAKE_IMAGEFORMATS_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/plugins/imageformats")
file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/imageformats")
file(COPY ${CMAKE_IMAGEFORMATS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # qpixmap加载jpg会失败
```

第三种删除文件：

```cmake
file(GLOB files_to_remove "${CMAKE_CURRENT_SOURCE_DIR}/dir_to_remove/*")  
foreach(file ${files_to_remove})  
    file(REMOVE ${file})  
endforeach()
#这段代码首先使用file(GLOB ...)命令获取dir_to_remove文件夹中的所有文件，然后使用foreach循环遍历这些文件，并使用file(REMOVE ...)命令删除每个文件。

#请注意，这种方法只能删除文件，而不能删除文件夹本身。如果你需要删除整个文件夹，包括其中的所有文件和子文件夹，可以使用file(REMOVE_RECURSE ...)命令
file(REMOVE_RECURSE "${CMAKE_CURRENT_SOURCE_DIR}/dir_to_remove")
```

## EXISTS

判断某个文件或者路径是否存在

```cmake
if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
    set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..") # ${CMAKE_PREFIX_PATH}/..
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin") # 相当于${CMAKE_PREFIX_PATH}/../bin
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..") # ${CMAKE_PREFIX_PATH}/../..
    endif ()
endif () # 对于qt这里不会进入if判断 C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\bin
```

```cmake
if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
	...
endif ()
```

## foreach

循环操作

```cmake
    foreach (QT_LIB Core Gui Widgets Sql Network) # QR_LIB是遍历元素
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy # bin/Qt5Cored.dll拷贝进来
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>") # 拷贝到bin目录
    endforeach (QT_LIB)
```



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

### CMAKE_C_COMPILER、CMAKE_CXX_COMPILER

编译器路径

```cmake
message(${CMAKE_C_COMPILER})
message(${CMAKE_CXX_COMPILER})
```

### CMAKE_C_COMPILER_ID、CMAKE_CXX_COMPILER_ID

编译器的类型，例如 "GNU"、"Clang"、"MSVC" 等。

```cmake
message(${CMAKE_C_COMPILER_ID})
message(${CMAKE_CXX_COMPILER_ID})
```

### CMAKE_C_COMPILER_VERSION、CMAKE_CXX_COMPILER_VERSION

编译器版本号

```cmake
message(${CMAKE_C_COMPILER_VERSION})
message(${CMAKE_CXX_COMPILER_VERSION})
```

### POST_BUILD

POST_BUILD是CMake中的一个指令，表示在构建后执行特定的命令。

```cmake
TARGET ${PROJECT_NAME} POST_BUILD
```

### CMAKE_BUILD_TYPE

编译类型Debug或Release，这里含义是如果是MSVC编译器且是Debug类型，让这个变量等于"d"

```cmake
set(DEBUG_SUFFIX)
if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
	set(DEBUG_SUFFIX "d")
endif ()
```

### CMAKE_COMMAND

**CMAKE_COMMAND是CMake的路径**。它指向的是CMake的安装位置或者在命令行中可以执行CMake命令的位置。在构建过程中，可以通过该路径执行CMake命令，例如进行构建参数的指定等。

```cmake
message(${CMAKE_COMMAND}) # D:/CLion 2023.1.3/bin/cmake/win/x64/bin/cmake.exe
```

其支持的命令如下。

```cmake
chdir <dir>: 更改当前工作目录到 <dir>。
compare_files <file1> <file2>: 比较两个文件 <file1> 和 <file2>，如果不同则返回非零退出状态。
【copy <source> <destination>: 将 <source> 复制到 <destination>。】
【copy_directory <source_dir> <destination_dir>: 将 <source_dir> 目录及其内容复制到 <destination_dir>。】
【copy_if_different <source> <destination>: 如果 <source> 和 <destination> 不同，则将 <source> 复制到 <destination>。】
echo [<string>]: 打印 <string> 到标准输出。
env: 设置环境变量。
execute_process: 执行一个外部进程。
extract_dir <path>: 从 <path> 中提取目录部分。
extract_filename <path>: 从 <path> 中提取文件名部分。
extract_first_argument <command>: 从 <command> 中提取第一个参数。
glob <globbing_expression>: 执行文件路径的通配符匹配。
glob_directory <directory> <globbing_expression>: 在 <directory> 中执行文件路径的通配符匹配。
【list_directories <directory>: 列出 <directory> 中的子目录。】
【list_files <directory>: 列出 <directory> 中的文件。】
load_cache <cache_file> <entry1> <entry2> ...: 从 <cache_file> 中加载缓存条目。
【make_directory <dir>: 创建目录 <dir>。】
md5sum <file>: 计算文件的 MD5 哈希值。
【remove [-f] <file1> <file2> ...: 删除指定的文件或目录。】
【remove_directory <dir>: 删除目录及其内容。】
rename <oldname> <newname>: 将文件或目录 <oldname> 重命名为 <newname>。
shorten_path <path> [<output_variable>]: 缩短路径 <path>，并可选地将结果存储在 <output_variable> 中。
tar [cxtzhv] <archive_name> [<file1> <file2> ...]: 创建或提取 tar 归档文件。
time [<command>]: 测量指定命令的执行时间。
touch_nocreate <file1> <file2> ...: 如果文件不存在，则创建指定的文件，但不修改现有文件的时间戳。
【touch <file1> <file2> ...: 创建指定的文件，或更新现有文件的时间戳。】
write_regv <data_type> <key_path> <value>: 将注册表项写入 JSON 文件。
write_regv_list <data_type> <key_path> <value1> <value2> ...: 将注册表项列表写入 JSON 文件。
write_regv_keys <data_type> <key_path> <key1> <key2> ...: 将注册表键写入 JSON 文件。
write_regv_keyset <data_type> <key_path> <keyset1> <keyset2> ...: 将注册表键集写入 JSON 文件。
write_regv_values <data_type> <key_path> <value1> <value2> ...: 将注册表值写入 JSON 文件。
```



## 定义变量

### CMAKE_TOOLCHAIN_FILE

定义工具链

```cmake
set(TOOLCHAIN_PATH /opt/sdk/android-aarch64)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-linux-android-gcc)
```

一般不需要手动配置，clion中已经配置好。

### EXECUTABLE_OUTPUT_PATH，CMAKE_RUNTIME_OUTPUT_DIRECTORY

指定exe生成的目录，含义相同

```cmake
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
```

### CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS

解决windows下动态库不生成lib的方法

```cmake
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
```

### LIBRARY_OUTPUT_PATH

动态库的输出目录

```cmake
SET(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/../bin)
```

### CMAKE_ARCHIVE_OUTPUT_DIRECTORY

动态库的输出目录，可以在库的cmakelist也可以顶层cmakelist来设置，和LIBRARY_OUTPUT_PATH功能一样

```cmake
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
```

### CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS

```cmake
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
```

### CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG、CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE

指定debug/release的输出目录

```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${CMAKE_CURRENT_SOURCE_DIR}/bin/debug)
```

```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_CURRENT_SOURCE_DIR}/bin/release)
```

### CMAKE_ARCHIVE_OUTPUT_DIRECTORY

用于设置生成静态库后，库文件的默认存放文件夹的位置

```cmake
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib)
```



