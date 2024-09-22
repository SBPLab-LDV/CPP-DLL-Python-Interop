cmake_minimum_required(VERSION 3.10)
project(cpp_dll_project)

# 設置 C++ 標準
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加庫
add_library(example SHARED
    example.cpp
    math_operations.cpp
)

# 包含头文件目录
target_include_directories(example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 设置输出名称
set_target_properties(example PROPERTIES OUTPUT_NAME "example")

# 如果是 Windows，添加 WIN32 定义
if(WIN32)
    target_compile_definitions(example PRIVATE WIN32)
endif()