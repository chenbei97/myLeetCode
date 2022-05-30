# 子项目名称
project (subproject1)
# set(CMAKE_CXX_CPPCHECK "cppcheck") # 貌似单独添加没用
# 创建1个变量链接所有cpp文件
set(SOURCES
    main1.cpp
)

# 包含宏目录，并调用宏
include(${CMAKE_SOURCE_DIR}/cmake/analysis.cmake)
add_analysis(${PROJECT_NAME} SOURCES)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})