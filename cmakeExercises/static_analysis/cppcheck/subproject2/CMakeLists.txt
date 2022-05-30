# 设置项目名称
project (subproject2)
# set(CMAKE_CXX_CPPCHECK "cppcheck") # 貌似单独添加没用
# 链接cpp文件
set(SOURCES
    main2.cpp
)

# i将cmake中宏函数包含尽量并调用
include(${CMAKE_SOURCE_DIR}/cmake/analysis.cmake)
add_analysis(${PROJECT_NAME} SOURCES)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})