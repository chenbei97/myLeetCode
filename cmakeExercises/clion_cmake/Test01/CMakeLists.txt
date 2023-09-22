cmake_minimum_required(VERSION 3.25)
project(Test01)

message(${CMAKE_C_COMPILER})
message(${CMAKE_CXX_COMPILER})
message(${CMAKE_C_COMPILER_ID})
message(${CMAKE_CXX_COMPILER_ID})
message(${CMAKE_C_COMPILER_VERSION})
message(${CMAKE_CXX_COMPILER_VERSION})
if (MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/msvc2017_64")
else()
    set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64")
endif ()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#include_directories(${Qt5Widgets_INCLUDE_DIRS})
#include_directories(${Qt5Network_INCLUDE_DIRS})
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

message(${CMAKE_PREFIX_PATH})
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
#set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${CMAKE_CURRENT_SOURCE_DIR}/bin/debug)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_CURRENT_SOURCE_DIR}/bin/release)
#set(CMAKE_ARCHIEVE_OUTPUT_DIRECTORY_DEBUG  ${CMAKE_CURRENT_SOURCE_DIR}/bin/debug)
#set(CMAKE_ARCHIEVE_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_CURRENT_SOURCE_DIR}/bin/release)

#message(${CMAKE_TOOLCHAIN_FILE})

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        REQUIRED)

add_subdirectory (component)
add_subdirectory(interface)

add_executable(${PROJECT_NAME}  main.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/component/inc
        ${PROJECT_SOURCE_DIR}/interface/inc
        )

target_link_libraries(Test01
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
        component
        interface
        )
#message(${DEBUG_SUFFIX})
message(${CMAKE_BUILD_TYPE})
message(${CMAKE_COMMAND}) # D:/CLion 2023.1.3/bin/cmake/win/x64/bin/cmake.exe
message("$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#message(QT_LIB)
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d") # 因为mingw不会有这个带尾缀d的dll
    endif () # 如果是MSVC编译器且是Debug类型，让这个变量等于"d"
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}") # 前缀路径
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..") # ${CMAKE_PREFIX_PATH}/..
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin") # 相当于${CMAKE_PREFIX_PATH}/../bin
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..") # ${CMAKE_PREFIX_PATH}/../..
        endif ()
    endif () # 对于qt这里不会进入if判断 C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\bin
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/") # 创建一个目录
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/") # $<TARGET_FILE_DIR:${PROJECT_NAME}其实就是bin
    endif ()
    foreach (QT_LIB Core Gui Widgets Sql Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy # bin/Qt5Cored.dll拷贝进来
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>") # 拷贝到bin目录
    endforeach (QT_LIB)
endif ()

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
