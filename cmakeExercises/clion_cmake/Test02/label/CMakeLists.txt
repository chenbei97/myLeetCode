set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件
SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin) # 这个要和exe始终在一起否则找不到dll
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
message(${CMAKE_CURRENT_LIST_DIR}) # D:/ClionProjects/Test/test5/label
message(${PROJECT_BINARY_DIR})#D:/ClionProjects/Test/test5/cmake-build-debug
message(${PROJECT_SOURCE_DIR})# D:/CionProjects/Test/test5
message(${CMAKE_SOURCE_DIR}) # ClionProjects/Test/test5
message(${CMAKE_BINARY_DIR}) # D:/ClionProjects/Test/test5/cmake-build-debug
message(${CMAKE_CURRENT_SOURCE_DIR}) # D:/ClionProjects/Test/test5/label
message(${CMAKE_CURRENT_BINARY_DIR})# D:/ClionProjects/Test/test5/cmake-build-debug/label

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(label SHARED label.cpp label.h)

target_link_libraries(label
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

## 设置动态库输出目录
#set_target_properties(label PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
