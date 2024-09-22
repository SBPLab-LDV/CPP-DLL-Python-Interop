cmake_minimum_required(VERSION 3.10)
project(CppDllExample)

# 設置 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加庫
add_library(example SHARED example.cpp)

# 如果需要，可以添加額外的包含目錄
# include_directories(${CMAKE_SOURCE_DIR}/include)

# 鏈接 Windows 庫
if(WIN32)
    target_link_libraries(example PRIVATE user32)
endif()

# 設置輸出目錄
set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)