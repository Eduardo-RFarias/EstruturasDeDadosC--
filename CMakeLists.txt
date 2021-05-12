cmake_minimum_required(VERSION 3.0.0)
project(estruturas VERSION 0.1.0)

add_library(lib
lib/estruturasEncadeadas/ListaEncadeada.cpp
lib/estruturasEncadeadas/PilhaEncadeada.cpp
lib/estruturasEncadeadas/FilaEncadeada.cpp
lib/estruturasEncadeadas/Abp.cpp
lib/estruturasVetorizadas/ListaVetorizada.cpp
)

add_executable(estruturas main.cpp)

target_link_libraries(estruturas lib)
