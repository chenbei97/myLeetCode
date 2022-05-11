cmake_minimum_required (VERSION 3.23.1)

# 顶级CMakeLists.txt文件
project(subProjects_cmake)

# 添加子库
add_subdirectory(sublibrary1)
add_subdirectory(sublibrary2)
add_subdirectory(subbinary) # 执行的目录