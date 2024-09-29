cmake_minimum_required(VERSION 3.5)

project(Goida LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo 
)

set(SOURCE_EXE src/Goida.cpp)
set(LEXER_SOURCE src/Lexer.cpp)
set(TOKEN_SOURCE src/Token.cpp)

add_library(mylib STATIC ${LEXER_SOURCE} include/Lexer.hpp ${TOKEN_SOURCE} include/Token.hpp)

add_executable(Goida ${SOURCE_EXE})

target_link_libraries(Goida mylib)
