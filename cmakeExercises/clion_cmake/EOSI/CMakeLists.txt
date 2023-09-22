cmake_minimum_required(VERSION 3.25)

project(EOSI)

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
else(GNU)
    set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64")
endif ()

message(${CMAKE_PREFIX_PATH})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

#set(CMAKE_SQLDRIVERS_PATH "${CMAKE_PREFIX_PATH}/plugins/sqldrivers")
#file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/sqldrivers")
#file(COPY ${CMAKE_SQLDRIVERS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # 整个文件夹要复制过来否则找不到驱动
#set(CMAKE_IMAGEFORMATS_PATH "${CMAKE_PREFIX_PATH}/plugins/imageformats")
#file(REMOVE_RECURSE "${EXECUTABLE_OUTPUT_PATH}/imageformats")
#file(COPY ${CMAKE_IMAGEFORMATS_PATH} DESTINATION ${EXECUTABLE_OUTPUT_PATH}) # qpixmap加载jpg会失败

include_directories(${CMAKE_SQLDRIVERS_PATH} ${CMAKE_IMAGEFORMATS_PATH})

add_subdirectory(Component)
add_subdirectory(Interface)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        Concurrent
        REQUIRED)

#qt5_add_resources(QRC_SOURCE_FILE ${PROJECT_SOURCE_DIR}/bin/images.qrc)
#QT5_ADD_RESOURCES(QRC_SOURCE_FILE ${PROJECT_SOURCE_DIR}/bin/images.qrc)
set(QRC_SOURCE_FILE bin/images.qrc bin/app.rc)

add_executable(${PROJECT_NAME}  main.cpp initapp.h initapp.cpp
        ${QRC_SOURCE_FILE}
        ${PROJECT_SOURCE_DIR}/bin/theme/dark/darkstyle.qrc)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Component/inc
        ${PROJECT_SOURCE_DIR}/Interface/inc
        )

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

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
        Qt5::Concurrent
        component
        interface
        )



if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Sql Network Concurrent)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"# bin/Qt5Cored.dll拷贝进来
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>") # 拷贝到bin目录
    endforeach (QT_LIB)
endif ()

