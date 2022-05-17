cmake_minimum_required(VERSION 3.23.1)
project (code_generation)

# 设置项目版本
set (code_generation_VERSION_MAJOR 0) # 当前版本
set (code_generation_VERSION_MINOR 2) # 最低版本
set (code_generation_VERSION_PATCH 1) # 打包版本
set (code_generation_VERSION "${code_generation_VERSION_MAJOR}.${code_generation_VERSION_MINOR}.${code_generation_VERSION_PATCH}")

# 要在文件中进行变量替换，可以使用CMake中的configure_file()函数
# 这个函数的核心参数是源文件和目标文件
# 允许使用${VARIABLE}语法或@VARIABLE@来定义变量,就像定义CMake变量一样
# 例如ver.h.in会生成新文件ver.h,包含于目录PROJECT_BINARY_DIR中

# 在ver.h.in中调用配置文件设置版本
# 在文件中使用标准符号 ${VARIABLE}
configure_file(ver.h.in ${PROJECT_BINARY_DIR}/ver.h)

# 在文件中配置path.h.in
# 这个文件只能使用@VARIABLE@符号,因为@ONLY限定了
configure_file(path.h.in ${PROJECT_BINARY_DIR}/path.h @ONLY)

# 添加执行脚本
add_executable(code_generation
    main.cpp
)

# 包含目录
target_include_directories( code_generation
    PUBLIC
        ${CMAKE_BINARY_DIR}
)