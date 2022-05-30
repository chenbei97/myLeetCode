cmake_minimum_required (VERSION 3.23.1)

project(cppcheck_analysis)

# set(CMAKE_CXX_CPPCHECK "cppcheck") # 这条命令加不加好像都可以

# 添加寻找cppcheck的路径
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

# 寻找该二进制文件的路径
find_package(CPPCHECK)

# 再添加子目录之前必须先使用以下命令
set (ALL_ANALYSIS_TARGETS)

# 添加子目录
add_subdirectory(subproject1)
add_subdirectory(subproject2)


# 添加分析的目标
if( CPPCHECK_FOUND )
    add_custom_target(analysis)
    ADD_DEPENDENCIES(analysis ${ALL_ANALYSIS_TARGETS})
    set_target_properties(analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message("analysis analysis targets are ${ALL_ANALYSIS_TARGETS}")
endif()