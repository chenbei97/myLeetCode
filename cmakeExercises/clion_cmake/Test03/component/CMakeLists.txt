SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) # windows下生成.lib文件

find_package(Qt5 COMPONENTS # 为了inc能够使用这些文件还是需要查找包
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB COMPONENT_ALLHEADERS "inc/*.h")
file(GLOB_RECURSE COMPONENT_ALLSOURCES "src/*.cpp")

message("COMPONENT_ALLHEADERS = ${COMPONENT_ALLHEADERS}")
message("COMPONENT_ALLSOURCES = ${COMPONENT_ALLSOURCES}")
add_library(component SHARED ${COMPONENT_ALLSOURCES} ${COMPONENT_ALLHEADERS})

target_link_libraries(component
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
file(COPY ${COMPONENT_ALLHEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/inc/component)
