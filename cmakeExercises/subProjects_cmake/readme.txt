此示例演示如何设置包含子项目的CMake项目
顶级CMakeLists.txt称之为CMakeLists。在子目录中创建以下内容：
sublibrary1 - 一个静态库
sublibrary2 - 只有头文件的库
subbinary - 可执行文件所在处

文件结构目录为：
├── CMakeLists.txt
├── subbinary
│   ├── CMakeLists.txt
│   └── main.cpp
├── sublibrary1
│   ├── CMakeLists.txt
│   ├── include
│   │   └── sublib1
│   │       └── sublib1.h
│   └── src
│       └── sublib1.cpp
└── sublibrary2
    ├── CMakeLists.txt
    └── include
        └── sublib2
            └── sublib2.h

cd cmakeExercises\\subProjects_cmake\\build
cmake ..
cmake --build .
./subbinary/Debug/subbinary
https://github.com/ttroy50/cmake-examples/tree/master/02-sub-projects/A-basic