project (sublibrary2)

# 添加接口库,因为只有头文件没有实现,所以使用INTERFACE
# 并使用一个别名
add_library(${PROJECT_NAME} INTERFACE)
add_library(sub::lib2 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)