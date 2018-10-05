cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

project(CoapPbRpc)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(common)


set(INS_INCLUDE_DIR
    "/coappbrpc"
)

set(INS_TARGETS
    coappbrpc
)

add_library(coappbrpc SHARED)

target_link_libraries(coappbrpc)

install(TARGETS ${INS_TARGETS}  LIBRARY DESTINATION lib COMPONENT libraries)

