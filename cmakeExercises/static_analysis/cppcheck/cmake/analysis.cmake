# 确保cppcheck二进制文件可用
if( NOT CPPCHECK_FOUND )
    # set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules
    #                     ${CMAKE_MODULE_PATH})
    find_package(CPPCHECK)
endif()

# 添加目标用于检查
# _target - 用于此操作的项目名称. 会生成相应的${_target}_analysis分析文件
# _sources - 代表源列表的变量的名称，This is the name of the variable not the actual list
#宏替代函数能够使PARENT_SCOPE stuff easier
macro(add_analysis _target _sources)
    if( CPPCHECK_FOUND )

        # 获取要同时馈送到cppcheck的include文件
        get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
        foreach(dir ${dirs})
            LIST(APPEND cppcheck_includes "-I${dir}")
        endforeach()

        # 添加到所有目标中，以进行高级别的分析
        LIST(APPEND ALL_ANALYSIS_TARGETS "${_target}_analysis")
        set(ALL_ANALYSIS_TARGETS "${ALL_ANALYSIS_TARGETS}" PARENT_SCOPE)

        # 这用于使命令在命令行上正确运行。
        # 命令参数需要一个列表，这会进行更改
        # 我需要检查哪个版本适用于3.23.1
        if (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VESION} GREATER 3.23.1)
            separate_arguments(tmp_args UNIX_COMMAND ${CPPCHECK_ARG})
        else ()
            # cmake 2.6 has different arguments 
            string(REPLACE " " ";" tmp_args ${CPPCHECK_ARG})         
        endif ()

        # 添加自定义_target_analysis分析目标
        add_custom_target(${_target}_analysis)
        set_target_properties(${_target}_analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
        
        # add the cppcheck command to the target
        add_custom_command(TARGET ${_target}_analysis PRE_BUILD
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMAND ${CPPCHECK_BIN} ${tmp_args} ${cppcheck_includes} ${${_sources}}
            DEPENDS ${${_sources}}
            COMMENT "Running cppcheck: ${_target}"
            VERBATIM)
        message("adding cppcheck analysys target for ${_target}")
    endif()

endmacro()