cmake_minimum_required(VERSION 3.10)

project(logger)

set (MODULES_PATH "D:/Projects/beads")

set(SOURCES
    main.cpp
    other.h
    other.cpp
    ../../logger/logger.cpp
)
add_executable(logger ${SOURCES} )

target_include_directories(
    logger
    PUBLIC
    ${MODULES_PATH}/logger/logger.h
)

target_compile_options(logger PRIVATE -std=c++20)