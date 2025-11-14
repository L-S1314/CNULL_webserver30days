cmake_minimum_required(VERSION 3.12)
project(NetworkProject)

set(CMAKE_CXX_STANDARD 11)

# 直接创建两个可执行文件
add_executable(server server/server.cpp)
add_executable(client client/client.cpp)
add_executable(tools src/tools.cpp)

# 设置输出目录
set_target_properties(server client tools PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)