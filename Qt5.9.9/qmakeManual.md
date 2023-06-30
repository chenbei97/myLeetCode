## PWD

指定指向包含要分析的当前文件的目录的完整路径。在编写项目文件以支持影子生成时，引用源树中的文件可能非常有用。

注意：不要试图覆盖此变量的值。

## OUT_PWD

指定指向qmake放置生成的Makefile的目录的完整路径。

注意：不要试图覆盖此变量的值。

## _ PRO_FILE_PWD _

包含包含正在使用的项目文件的目录的路径。
例如，以下行会将包含项目文件的目录的位置写入控制台：

```
message($$_PRO_FILE_PWD_)
```

## SUBDIRS

当与子目录模板一起使用时，此变量指定包含需要构建的项目部分的所有子目录或项目文件的名称。**使用此变量指定的每个子目录都必须包含自己的项目文件**。
建议每个子目录中的项目文件与子目录本身具有相同的基本名称，因为这样可以省略文件名。例如，如果子目录名为myapp，则该目录中的项目文件应称为myapp.pro。
或者，您可以指定**任何目录中.pro文件的相对路径**。强烈建议您**仅在当前项目的父目录或其子目录中指定路径**。

```
SUBDIRS = kernel \
          tools \
          myapp
```

如果需要确保子目录是按特定顺序构建的，请在相关的SUBDIRS元素上使用.dependent修饰符。

```
SUBDIRS += my_executable my_library tests doc
my_executable.depends = my_library
tests.depends = my_executable
```

上面的配置确保了my_library是在my_executable之前构建的，my_exeexecutable是在测试之前构建的。然而，doc可以和其他子目录并行构建，从而加快了构建过程。

注意：可以列出多个依赖项，它们都将在依赖它们的目标之前构建。

注意：不鼓励使用CONFIG+=ordered，因为它会减慢多核构建的速度。与上面显示的示例不同，所有构建都将按顺序进行，即使它们没有依赖关系。

除了定义构建顺序之外，还可以通过为SUBDIRS元素提供额外的修饰符来修改SUBDIRS的默认行为。支持的修饰符有：

|  修饰符   |                             作用                             |
| :-------: | :----------------------------------------------------------: |
|  .subdir  |             使用指定的子目录，而不是SUBDIRS值。              |
| .depends  |                 此子项目依赖于指定的子项目。                 |
|   .file   |    明确指定子项目专业文件。不能与.subdir修饰符一起使用。     |
| .makefile |       子项目的生成文件。仅在使用makefile的平台上可用。       |
|  .target  | 用于与此子项目相关的生成文件目标的基字符串。仅在使用makefile的平台上可用。 |
|           |                                                              |

例如，定义两个子目录，这两个子目录都位于不同于SUBDIRS值的目录中，并且其中一个子目录必须在另一个子目录之前构建：

```
SUBDIRS += my_executable my_library
my_executable.subdir = app
my_executable.depends = my_library
my_library.subdir = lib
```

## TARGET

指定目标文件的名称。默认情况下包含项目文件的基本名称。

```
TEMPLATE = app
TARGET = myapp
SOURCES = main.cpp
```

上面的项目文件将在unix上生成一个名为myapp的可执行文件，在Windows上生成myapp.exe。

## TEMPLATE

指定生成项目时要使用的模板的名称。允许的值为：

|  选项   |                             描述                             |
| :-----: | :----------------------------------------------------------: |
|   app   | 为构建应用程序创建Makefile（默认设置）。有关详细信息，请参见构建应用程序 |
|   lib   |    创建用于构建库的Makefile。有关详细信息，请参见构建库。    |
| subdirs | 在子目录中创建用于构建目标的Makefile。子目录是使用SUBDIRS变量指定的。 |
|   aux   | 创建不生成任何内容的Makefile。如果不需要调用编译器来创建目标，请使用此选项；例如，因为您的项目是用解释语言编写的。注意：此模板类型仅适用于基于Makefile的生成器。特别是，它将不适用于vcxproj和Xcode生成器。 |
|  vcapp  | 仅限Windows。为Visual Studio创建应用程序项目。有关详细信息，请参见创建Visual Studio项目文件。 |
|  vclib  |           仅限Windows。为Visual Studio创建库项目。           |

```
TEMPLATE = lib
SOURCES = main.cpp
TARGET = mylib
```

可以通过使用-t命令行选项指定新的模板类型来覆盖该模板。处理.pro文件后，这将覆盖模板类型。对于使用模板类型来确定项目构建方式的.pro文件，有必要在命令行上声明template，而不是使用-t选项。

## Config

指定项目配置和编译器选项。这些值由qmake内部识别，并具有特殊意义。

[Variables | config)](https://doc.qt.io/qt-5/qmake-variable-reference.html#config)

|              选项               |                             描述                             |
| :-----------------------------: | :----------------------------------------------------------: |
| release,debug,debug_and_release |                   以发布,调试,2种模式构建                    |
|        warn_on,warn_off         |                        允许和禁止警告                        |
|    exceptions,exceptions_off    |                       默认启用异常支持                       |
|           utf8-source           |     指定源文件使用UTF-8编码(默认情况下使用编译器默认值)      |
|         c99,c11,c17,c18         |                             标准                             |
|   c++11,c++14,c++17,c++latest   |                           C++标准                            |
|       depend_includepath        |       启用将INCLUDEPATH的值附加到DEPENDPATH(默认设置)        |
|           windeployqt           |       链接后自动调用windeployqt，并将输出添加为部署项        |
|         no_include_pwd          |               不要将当前目录添加到INCLUDEPATHS               |
|    compile_included_sources     | 默认qmake不编译包含在其他源文件中的源文件。此选项将禁用此行为。 |
|               qt                | 目标是Qt应用程序或库，需要Qt库和头文件。Qt库的正确包含路径和库路径将自动添加到项目中。这是默认情况下定义的，可以使用\l｛#qt｝｛qt｝变量进行微调 |
|               x11               | 目标是X11应用程序或库。适当的包含路径和库将自动添加到项目中  |
|             windows             | 目标是Win32窗口应用程序（仅限应用程序）。正确的包含路径、编译器标志和库将自动添加到项目中 |
|             console             | 目标是Win32控制台应用程序（仅限应用程序）。正确的包含路径、编译器标志和库将自动添加到项目中。考虑对跨平台应用程序使用cmdline选项 |
|             cmdline             | 目标是一个跨平台的命令行应用程序。在Windows上，这意味着CONFIG+=控制台。在macOS上，这意味着CONFIG-=app_bundle |
|           shared,dll            | 目标是共享对象/DLL。正确的包含路径、编译器标志和库将自动添加到项目中。请注意，dll也可以在所有平台上使用；将创建具有目标平台（.dll或.so）的适当后缀的共享库文件 |
|        static,staticlib         | 目标是静态库（仅限lib）。正确的编译器标志将自动添加到项目中  |
|             plugin              |           目标是一个插件（仅限lib）。这也启用了dll           |
|            designer             |                   目标是Qt Designer的插件                    |
|           app_bundle            |           将可执行文件放入捆绑包中（这是默认设置）           |
|           lib_bundle            |                      将库放入库捆绑包中                      |
|          plugin_bundle          |      将插件放入插件捆绑包中。Xcode项目生成器不支持此值       |

## DependPath

指定qmake要扫描的目录列表，以解析依赖关系。当qmake遍历源代码中#include的头文件时，会使用此变量。

## DistFiles

指定要包含在dist目标中的文件列表。此功能仅受UnixMake规范支持。

```
DISTFILES += ../program.txt
```

## Forms/Headers/Sources

指定编译前要由uic处理的UI文件（请参阅Qt设计器手册）。构建这些UI文件所需的所有依赖项、标头和源文件都将自动添加到项目中

```
FORMS = mydialog.ui \
    mywidget.ui \
        myconfig.ui
HEADERS = myclass.h \
          login.h \
          mainwindow.h
```

## RESOURCES

指定目标的资源集合文件（qrc）的名称。有关资源集合文件的更多信息，请参阅Qt资源系统。

## TRANSLATIONS

指定包含将用户界面文本翻译成非母语的翻译（.ts）文件的列表。
翻译中的翻译文件将由lrelease和Using lupdate工具处理。如果只希望lrelease处理文件，请使用EXTRA_TRANLATIONS。
您可以使用CONFIG+=lrelease在构建期间自动编译文件，并使用CONFIG++=lreleaseembed_translations使它们在Qt资源系统中可用。
有关Qt的国际化（i18n）和本地化（l10n）的更多信息，请参阅Qt语言学家手册。

## Icon

此变量仅在Mac OS上用于设置应用程序图标。有关详细信息，请参阅应用程序图标文档。

## IncludePath

指定编译项目时应搜索的#include目录。

```
INCLUDEPATH = c:/msdev/include d:/stl/include
```

要指定包含空格的路径，请使用空格中描述的技术引用该路径。

```
win32:INCLUDEPATH += "C:/mylibs/extra headers"
unix:INCLUDEPATH += "/home/user/extra headers"
```

## Installs

指定执行make-install或类似安装过程时将安装的资源列表。列表中的每个项目通常都定义有属性，这些属性提供了有关其安装位置的信息。
例如，以下target.path定义描述了生成目标的安装位置，INSTALLS分配将生成目标添加到要安装的现有资源列表中：

```
target.path += $$[QT_INSTALL_PLUGINS]/imageformats
INSTALLS += target
```

INSTALLS有一个.CONFIG成员，该成员可以取几个值：

|         值         |                             描述                             |
| :----------------: | :----------------------------------------------------------: |
|   no_check_exist   | 如果未设置，qmake将查看要安装的文件是否确实存在。如果这些文件不存在，qmake就不会创建安装规则。如果您需要安装在构建过程中生成的文件，如qdoc创建的HTML文件，请使用此配置值。 |
|      nostrip       | 如果设置，典型的Unix剥离功能将被关闭，调试信息将保留在二进制文件中。 |
|     executable     |                在Unix上，这设置了可执行标志。                |
|      no_build      | 当您进行了make-install，但还没有项目的内部版本时，将首先生成项目，然后再进行安装。如果您不希望出现这种行为，请设置此配置值以确保生成目标不会作为依赖项添加到安装目标。 |
| no_default_install | 一个项目有一个顶级项目目标，当您进行make-install时，所有东西都安装在该目标中。但是，如果您有一个设置了此配置值的安装目标，则默认情况下不会安装它。然后，您必须明确地说makeinstall_<file>。 |

## Libs

指定要链接到项目中的库的列表。如果使用Unix-l（库）和-L（库路径）标志，qmake将在Windows上正确处理库（即，将库的完整路径传递给链接器）。qmake必须存在库才能找到-l lib所在的目录。

```
unix:LIBS += -L/usr/local/lib -lmath
win32:LIBS += c:/mylibs/math.lib
```

要指定包含空格的路径，请使用空格中描述的技术引用该路径。

```
win32:LIBS += "C:/mylibs/extra libs/extra.lib"
unix:LIBS += "-L/home/user/extra libs" -lextra
```

## Libs_Private

指定要私下链接到项目中的库的列表。该变量的行为与LIBS相同，只是为Unix构建的共享库项目不会在其链接接口中公开这些依赖项。
这样做的效果是，如果项目C依赖于库B，而库B私下依赖于库A，但C也想直接使用来自A的符号，则需要显式地链接到A。换句话说，私下链接的库在构建时不会以传递方式公开。

## DEFINES

```
DEFINES += QT_NO_DEBUG_OUTPUT #禁用qdebug打印输出
```

## MakeFile

指定生成的Makefile的名称。此变量的值通常由qmake或qmake.conf处理，很少需要修改。

## MOC_DIR

指定应放置所有中间moc文件的目录。

```
unix:MOC_DIR = ../myproject/tmp
win32:MOC_DIR = c:/myproject/tmp
```

## OBJECTS_DIR

指定应放置所有中间对象的目录。

```
unix:OBJECTS_DIR = ../myproject/tmp
win32:OBJECTS_DIR = c:/myproject/tmp
```

## UI_DIR

指定uic中所有中间文件的存放目录。

```
unix:UI_DIR = ../myproject/ui
win32:UI_DIR = c:/myproject/ui
```

## RC_FILE

仅限Windows。指定目标的Windows资源文件（.rc）的名称。请参见添加Windows资源文件。

## RC_ICONS

仅限Windows。指定应包含在生成的.rc文件中的图标。仅当未设置RC_FILE和RES_FILE变量时才使用此选项。有关.rc文件生成的更多详细信息，请参阅平台说明。

## RC_LANG

仅限Windows。指定应在生成的.rc文件中指定的语言。只有在设置了VERSION或RC_ICONS变量且未设置RC_FILE和RES_FILE变量时，才使用此选项。

## RC_INCLUDEPATH

指定传递给Windows资源编译器的包含路径。

## RCC_DIR

指定Qt资源编译器输出文件的目录。

```
unix:RCC_DIR = ../myproject/resources
win32:RCC_DIR = c:/myproject/resources
```

## REQUIRES

指定作为条件计算的值的列表。如果任何条件为false，qmake将在构建时跳过此项目（及其SUBDIRS）。

注意：如果您想在构建时跳过项目或子项目，我们建议您改用requires()函数。

## PRECOMPILED_HEADER

指示用于创建预编译头文件的头文件，以提高项目的编译速度。预编译头目前仅在某些平台上受支持（Windows-所有MSVC项目类型，Apple-Xcode，Makefile，Unix-gcc 3.3及更高版本）。

## QMAKE_CXX

指定在生成包含C++源代码的项目时将使用的C++编译器。只要在处理Makefile时位于path变量中包含的路径上，就只需要指定编译器可执行文件的文件名。

## QMAKE_CXXFLAGS

指定用于生成项目的C++编译器标志。此变量的值通常由qmake或qmake.conf处理，很少需要修改。可通过分别修改QMAKE_CXXFLAGS_debug和QMAKE_XXFLAGS_release变量来调整特定于调试和发布模式的标志。

## QT

指定项目使用的Qt模块。有关每个模块要添加的值，请参阅模块文档。
在C++实现级别，使用Qt模块使其标头可用于包含，并使其链接到二进制文件。
默认情况下，QT包含核心和gui，确保无需进一步配置即可构建标准gui应用程序。
如果您想构建一个没有Qt GUI模块的项目，则需要使用“==”运算符排除GUI值。以下线路将导致正在建设的最小Qt项目。

```
QT -= gui # Only the core module is used.
```

如果您的项目是Qt Designer插件，请使用值uiplugin指定该项目将作为库构建，但要为Qt Designer提供特定的插件支持。有关详细信息，请参阅生成和安装插件。

## QTPLUGIN

指定要与应用程序链接的静态Qt插件的名称列表，以便它们可以作为内置资源使用。
qmake自动添加所用Qt模块通常需要的插件（请参阅Qt）。默认值被调整为最佳开箱即用体验。有关可用插件的列表以及覆盖自动链接的方法，请参见静态插件。
当前，当针对Qt的共享/动态构建进行链接时，或当链接库时，此变量不起作用。它可以用于以后部署动态插件。

## QT_VERSION

QT_MAJOR_VERSION、QT_MINOR_VERSION、QT_PATCH_VERSION

## VERSION

如果指定了应用程序模板，则指定应用程序的版本号；如果指定了库模板，则为库的版本号。
在Windows上，如果未设置rc_file和RES_file变量，则触发.rc文件的自动生成。生成的.rc文件将具有FILEVERSION和PRODUCTVERSION条目，其中填充了major、minor、patch级别和内部版本号。每个数字必须在0到65535之间。有关.rc文件生成的更多详细信息，请参阅平台说明。

```
win32:VERSION = 1.2.3.4 # major.minor.patch.build
else:VERSION = 1.2.3    # major.minor.patch
```

