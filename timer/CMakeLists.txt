cmake_minimum_required(VERSION 3.10)

project(timer)

set(SOURCES
    app/main.cpp
)
add_executable(timer ${SOURCES} )

target_include_directories(
    timer
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
