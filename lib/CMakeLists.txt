add_library(lib
estruturasEncadeadas/ListaEncadeada.cpp
estruturasEncadeadas/PilhaEncadeada.cpp
estruturasEncadeadas/FilaEncadeada.cpp
estruturasVetorizadas/ListaVetorizada.cpp
)

target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
