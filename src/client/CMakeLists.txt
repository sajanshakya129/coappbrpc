cmake_minimum_required(VERSION 2.8.4)

project(coappbrpc_client)

set(coappbrpc_client_SRCS
    ClientRPC.cc
    CoapClient.cc
)

set(coappbrpc_client_HDRS
    ClientRPC.hh
    CoapClient.hh
    )

add_library(coappbrpc_client STATIC ${coappbrpc_client_SRCS})

set(INS_INCLUDE_DIR
    "/coappbrpc"
)

set(INS_TARGETS
    coappbrpc_client
)

# Install
install(TARGETS ${INS_TARGETS}
    RUNTIME DESTINATION bin COMPONENT applications
    LIBRARY DESTINATION lib COMPONENT libraries
    ARCHIVE DESTINATION lib COMPONENT libraries
)

install(FILES ${coappbrpc_client_HDRS} DESTINATION "include${INS_INCLUDE_DIR}" COMPONENT headers)
