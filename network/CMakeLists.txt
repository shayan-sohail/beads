cmake_minimum_required(VERSION 3.10)

project(network)

set(SERVER
    app/server.cpp
)

set(CLIENT
  app/client.cpp
)

add_executable(server ${SERVER} )
add_executable(client ${CLIENT} )

if(WIN32)
  target_link_libraries(server wsock32 ws2_32)
  target_link_libraries(client wsock32 ws2_32)
endif()


target_include_directories(
  client
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(
  server
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)
