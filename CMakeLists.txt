

cmake_minimum_required(VERSION 3.10)
project(MemoryRiver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a header-only library
add_library(MemoryRiver INTERFACE)

# Specify the header file
target_include_directories(MemoryRiver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create a dummy executable to ensure the code compiles
# This is needed because we need a 'code' executable for the OJ
add_executable(code main.cpp)
target_link_libraries(code MemoryRiver)

