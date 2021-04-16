cmake_minimum_required(VERSION 3.0.0)
project(estruturas VERSION 0.1.0)

add_subdirectory(lib)

add_executable(estruturas main.cpp)

target_link_libraries(estruturas lib)
