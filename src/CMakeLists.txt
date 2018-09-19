project(pbrpc_srv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/local/lib -lprotobuf -pthread")

set(pbrpc_srv_SRCS
    main.cpp
    ServerRPC.cc
    handle_pbrpc.cc
)
add_executable(pbrpc_srv ${pbrpc_srv_SRCS})

target_link_libraries(pbrpc_srv pbrpc mongoose  proto_msg)
