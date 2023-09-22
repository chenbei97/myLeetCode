cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE COMPONENT_HEADERS "inc/*.h")
file(GLOB_RECURSE COMPONENT_SOURCES "src/*.cpp")
add_definitions(-DCOMPONENT_LIBRARY=0)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        REQUIRED)



add_library(component SHARED
        ${COMPONENT_SOURCES}
        ${COMPONENT_HEADERS}
        )

target_link_libraries(component
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Network
        )
