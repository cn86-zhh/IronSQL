cmake_minimum_required(VERSION 3.16)
project(IronSQL VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 包含路径
include_directories(
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/release
    ${CMAKE_SOURCE_DIR}/src/kernel
    ${CMAKE_SOURCE_DIR}/src/test
    ${CMAKE_SOURCE_DIR}/src/logsystem
    ${CMAKE_SOURCE_DIR}/src/stdiostreams
    ${CMAKE_SOURCE_DIR}/src/.include
    ${CMAKE_SOURCE_DIR}/src/loads
    ${CMAKE_SOURCE_DIR}/src/.path
    ${CMAKE_SOURCE_DIR}/src/.windows
    ${CMAKE_SOURCE_DIR}/src/.linux
    ${CMAKE_SOURCE_DIR}/src/.ironfsystem
    ${CMAKE_SOURCE_DIR}/src/psystem
    ${CMAKE_SOURCE_DIR}/src/fsystem
)

# 源文件列表
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/iron_main.cpp
    ${CMAKE_SOURCE_DIR}/src/test/iron_test.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_server.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_server_settings.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_handle.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_status.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_fmtout.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_parser.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_help.cpp
    ${CMAKE_SOURCE_DIR}/src/library/iron_pathfs.cpp
    ${CMAKE_SOURCE_DIR}/src/release/iron_object.cpp
    ${CMAKE_SOURCE_DIR}/src/kernel/iron_proces.cpp
    ${CMAKE_SOURCE_DIR}/src/kernel/iron_keywds.cpp
    ${CMAKE_SOURCE_DIR}/src/kernel/iron_verify.cpp
    ${CMAKE_SOURCE_DIR}/src/kernel/iron_syntax.cpp
    ${CMAKE_SOURCE_DIR}/src/logsystem/iron_logsystem.cpp
    ${CMAKE_SOURCE_DIR}/src/stdiostreams/iron_stdout.cpp
    ${CMAKE_SOURCE_DIR}/src/loads/iron_load_settings_conf.cpp
    ${CMAKE_SOURCE_DIR}/src/.path/iron_path_manage.cpp
    ${CMAKE_SOURCE_DIR}/src/.path/iron_path_windows.cpp
    ${CMAKE_SOURCE_DIR}/src/.path/iron_path_linux.cpp
    ${CMAKE_SOURCE_DIR}/src/.ironfsystem/iron_file_system.cpp
    ${CMAKE_SOURCE_DIR}/src/.path/iron_path_init.cpp
    ${CMAKE_SOURCE_DIR}/src/.linux/iron_linux_systempath.cpp
    ${CMAKE_SOURCE_DIR}/src/.windows/iron_windows_systempath.cpp
    ${CMAKE_SOURCE_DIR}/src/psystem/iron_path_system.cpp
    ${CMAKE_SOURCE_DIR}/src/fsystem/iron_read_help_info.cpp
)

# 可执行文件
add_executable(ironsql ${SOURCE_FILES})

# 平台特定处理
if(WIN32)
    # Windows 平台 - 添加图标资源
    set(ICON_RESOURCE ${CMAKE_SOURCE_DIR}/src/resource.rc)
    configure_file(${CMAKE_SOURCE_DIR}/src/resource.rc.in ${ICON_RESOURCE} @ONLY)
    target_sources(ironsql PRIVATE ${ICON_RESOURCE})
    # 静态链接
    set_target_properties(ironsql PROPERTIES
        LINK_FLAGS "-static"
    )
else()
    # Linux 平台
    set_target_properties(ironsql PROPERTIES
        LINK_FLAGS "-static"
    )
endif()

# 复制配置文件
add_custom_command(TARGET ironsql POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/.config
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/.config
    COMMENT "Copying config files to binary directory"
)
