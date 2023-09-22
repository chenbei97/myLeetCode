cmake_minimum_required(VERSION 3.25)

set(DLLNAME "interface")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_definitions(-DINTERFACE_LIBRARY=0) # 添加预定义宏,=号不能有空格,用于指定类导出或导入

file(GLOB_RECURSE INTERFACE_HEADERS  "inc/*.h")
file(GLOB_RECURSE INTERFACE_SOURCES "src/*.cpp")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        Concurrent
        REQUIRED)

add_library(${DLLNAME} SHARED
        ${INTERFACE_SOURCES}
        ${INTERFACE_HEADERS}
        )

target_include_directories(${DLLNAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Component/inc
        )

target_link_libraries(${DLLNAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
        Qt5::Concurrent
        component
        )

#file(GLOB flow_headers "inc/flow/*.h")
#file(COPY ${flow_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/flow)
#
#file(GLOB main_headers "inc/main/*.h")
#file(COPY ${main_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/main)
#
#file(GLOB login_headers "inc/login/*.h")
#file(COPY ${login_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/login)
#
#file(GLOB sql_headers "inc/sql/*.h")
#file(COPY ${sql_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/sql)













