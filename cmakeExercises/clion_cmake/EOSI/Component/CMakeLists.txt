cmake_minimum_required(VERSION 3.25)

set(DLLNAME "component")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_definitions(-DCOMPONENT_LIBRARY=0) # 添加预定义宏,=号不能有空格,用于指定类导出或导入

file(GLOB_RECURSE COMPONENT_HEADERS "inc/*.h")
file(GLOB_RECURSE COMPONENT_SOURCES "src/*.cpp")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        Concurrent
        REQUIRED)

add_library(${DLLNAME} SHARED
        ${COMPONENT_SOURCES}
        ${COMPONENT_HEADERS}
        )

target_link_libraries(${DLLNAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
        Qt5::Concurrent
        )

#file(GLOB public_headers "inc/*.h")
#file(COPY ${public_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include)
#
#file(GLOB tables_headers "inc/tables/*.h")
#file(COPY ${tables_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/tables)
#
#file(GLOB tcp_headers "inc/tcp/*.h")
#file(COPY ${tcp_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/tcp)
#
#file(GLOB widgets_headers "inc/widgets/*.h")
#file(COPY ${widgets_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/widgets)
#
#file(GLOB utilities_headers "inc/utilities/*.h")
#file(COPY ${utilities_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include/utilities)









