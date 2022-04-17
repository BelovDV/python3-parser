cmake_minimum_required(VERSION 3.7)

project("Antlr_python_parser")

set(CMAKE_CXX_STANDARD 11)

file(GLOB DU_SRC "tmp/antlr/*.cpp")
message(STATUS "DU_SRC: ${DU_SRC}")

add_executable(antlr_python_parser src/main.cpp src/visitor.cpp ${DU_SRC})

target_include_directories(antlr_python_parser PUBLIC tmp/antlr)

add_subdirectory(antlr4-cpp-runtime)

target_link_libraries(antlr_python_parser antlr4_cpp_runtime)
