cmake_minimum_required(VERSION 3.12)
project(NetworkProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

# 直接创建两个可执行文件
add_executable(server server/server.c)
add_executable(client client/client.c)

# 设置输出目录
set_target_properties(server client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)