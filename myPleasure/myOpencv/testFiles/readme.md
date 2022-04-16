# 务必阅读本VSCode配置Opencv的步骤

## CSDN的答案不靠谱

## 如果VS Studio配置Opencv

可以在这个笔记doc中的第4章，第4.5节找到答案。

[https://github.com/chenbei97/myLeetCode/imageProcessingV3.docx](https://github.com/chenbei97/myLeetCode/blob/main/imageProcessingV3.docx)

## 配置Git、Mingw

可在这个md文档找到答案，并给出了VsCode配置C++和Python的方法。

[https://github.com/chenbei97/ComputerVision/markdown/配置环境相关/Git和Vscode配置.md](https://github.com/chenbei97/ComputerVision/blob/main/markdown/配置环境相关/Git和Vscode配置.md)

本人的Mingw的路径就在C盘。

```
C:\msys64
```

记得要把bin、include文件夹都加入环境变量。

```
C:\msys64\mingw64\bin
C:\msys64\mingw64\include
```

## 现在VsCode开始配置Opencv

这个过程参考知乎的答案。

[如何优雅地在你的Vscode上使用opencv（C++接口，Windows篇，实则踩坑经历） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/402378383?utm_source=wechat_session&utm_medium=social&utm_oi=1173235761410818048&utm_campaign=shareopn)

答案提供好了Opencv编译好的版本，下载地址在下方。

[opencv编译好的版本](https://gitee.com/kirigaya/opencv_built_by_gcc_on_-windows)

或者见

现在要做的事，下载的文件有lib、include、bin。把里边的内容直接复制到上边Mingw的对应文件夹中。

在c_cpp_properties.json文件中"includePath"字段加上2个地址

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/msys64/mingw64/include",
                "C:/msys64/mingw64/include/opencv2"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.18362.0",
            "compilerPath": "C:/msys64/mingw64/bin/g++.exe",
            "intelliSenseMode": "windows-gcc-x64",
            "cppStandard": "c++20",
            "cStandard": "c17"
        }
    ],
    "version": 4
}
```

tasks.json的内容。

注意G++的命令，先-g，然后某个地址的cpp，-std=c++20，然后列出目录-I，然后列出动态库，这些动态库就是lib文件＋下的。myLeetCode\myPleasure\\myOpencv是我的工作目录。

```c++
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "C:\\msys64\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                //"${workspaceFolder}\\binaryTree\\*.cpp", // ${file},可以构建多个cpp文件而不是单个
                //"${workspaceFolder}\\linearArray\\*.cpp",
                //"${workspaceFolder}\\linkedList\\*.cpp",
                //"${workspaceFolder}\\characterString\\*.cpp",
                //"${workspaceFolder}\\coreAlgorithms\\*.cpp",
                //"${workspaceFolder}\\STLTestCode\\*.cpp",
                "${workspaceFolder}\\myPleasure\\myOpencv\\*.cpp",
                "-std=c++20",
                "-I","C:/msys64/mingw64/include",
                "-I","C:/msys64/mingw64/lib",
                "-l","libopencv_calib3d452",
                "-l","libopencv_core452",
                "-l","libopencv_dnn452",
                "-l","libopencv_features2d452",
                "-l","libopencv_flann452",
                "-l","libopencv_gapi452",
                "-l","libopencv_highgui452",
                "-l","libopencv_imgcodecs452",
                "-l","libopencv_imgproc452",
                "-l","libopencv_ml452",
                "-l","libopencv_objdetect452",
                "-l","libopencv_photo452",
                "-l","libopencv_stitching452",
                "-l","libopencv_video452",
                "-l","libopencv_videoio452",
                "-o",
                //"${workspaceFolder}\\binaryTree\\main.exe", // ${workspaceFolder}\\myProgram.exe 可以替换为硬编码名
                //${fileDirname}\\${fileBasenameNoExtension}.exe
                //"${workspaceFolder}\\linearArray\\main.exe",
                //"${workspaceFolder}\\linkedList\\main.exe",
                //"${workspaceFolder}\\characterString\\main.exe",
                //"${workspaceFolder}\\coreAlgorithms\\main.exe",
                //"${workspaceFolder}\\STLTestCode\\main.exe",
                "${workspaceFolder}\\myPleasure\\myOpencv\\main.exe",
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "编译器: C:\\msys64\\mingw64\\bin\\g++.exe"
        }
    ]
}
```

命令行就是这样的命令了，这里是有个测试代码文件.\myLeetCode\myPleasure\myOpencv\testFiles\test_opencv_for_vscode.cpp

```c++
g++.exe -fdiagnostics-color=always -g C:\Users\chenbei\VscodeItems\myLeetCode\myPleasure\myOpencv\testFiles\*.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 -o C:\Users\chenbei\VscodeItems\myLeetCode\myPleasure\myOpencv\testFiles\test_opencv_for_vscode.exe // 编译命令
    
cd myPleasure\myOpencv\testFiles // 先到输出文件夹
.\test_opencv_for_vscode.exe // 执行
```

luanch.json。

```json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C/C++: g++.exe Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            //"program": "${workspaceFolder}\\binaryTree\\main.exe", // ${fileDirname}\\${fileBasenameNoExtension}.exe
            //"program": "${workspaceFolder}\\linearArray\\main.exe",
            //"program": "${workspaceFolder}\\linkedList\\main.exe",
            //"program": "${workspaceFolder}\\characterString\\main.exe",
            //"program": "${workspaceFolder}\\coreAlgorithms\\main.exe",
            //"program": "${workspaceFolder}\\STLTestCode\\main.exe",
            "program": "${workspaceFolder}\\myPleasure\\myOpencv\\main.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\msys64\\mingw64\\bin\\gdb.exe",
            "logging":{"engineLogging":true},
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "将反汇编风格设置为 Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++.exe 生成活动文件"
        }
    ]
}
```

