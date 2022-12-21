cmake_minimum_required(VERSION 3.10)

project(network)

set(SOURCES
    app/main.cpp
)
add_executable(network ${SOURCES} )

if(WIN32)
  target_link_libraries(network wsock32 ws2_32)
endif()

target_include_directories(
    network
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
