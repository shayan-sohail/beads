cmake_minimum_required(VERSION 3.10)

project(demo)

set(SOURCES
    app/main.cpp
)
add_executable(demo ${RFFE_SOURCES} ${SOURCES} )

target_include_directories(
    demo
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(demo PRIVATE -std=c++20)
