cmake_minimum_required(VERSION 2.8.4)

project(coappbrpc)

set(coappbrpc_SRCS
    ServerRPC.cc
)

set(coappbrpc_HDRS
    handle_pbrpc.hh handle_pbrpc.cc
    ServerRPC.hh ServerRPC.cc
)
add_library(coappbrpc_server ${coappbrpc_SRCS})

if(NOT BUILD_SHARED_LIBS)
add_definitions(-DCOAPPBRPC_BUILT_AS_STATIC)
endif()


set(INS_INCLUDE_DIR
    "/coappbrpc"
)

set(INS_TARGETS
    coappbrpc_server
)

# Install
install(TARGETS ${INS_TARGETS}
    RUNTIME DESTINATION bin COMPONENT applications
    LIBRARY DESTINATION lib COMPONENT libraries
    ARCHIVE DESTINATION lib COMPONENT libraries
)

install(FILES ${coappbrpc_HDRS} DESTINATION "include${INS_INCLUDE_DIR}" COMPONENT headers)
