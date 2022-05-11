project(subbinary)

# 可执行命令
add_executable(${PROJECT_NAME} main.cpp)

# 链接静态库通过使用别名sub::lib1
# 链接只有头文件的库通过使用别名sub::lib2
# 这将导致该目标的include目录被添加到此项目中
target_link_libraries(${PROJECT_NAME} 
    sub::lib1 # 链接2个库
    sub::lib2
)