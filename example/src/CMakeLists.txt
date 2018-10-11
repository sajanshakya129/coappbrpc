cmake_minimum_required(VERSION 2.8.4)

project(test)

find_path (COAP_PBRPC_INCLUDE_DIR
           NAMES coappbrpc/ServerRPC.hh
           PATH_SUFFIXES caoppbrpc
)

find_library (COAP_PBRPC_LIBRARY NAMES
              coappbrpc
              lcoappbrpc
              libcoappbrpc
)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

include_directories(
    ${PROTOBUF_ROOT}/src
    ${pbrpc_proto_BINARY_DIR}
    ${pbrpc_BINARY_DIR}
)

link_directories(
    ${libprotobuf_BINARY_DIR}
)

include_directories(${COAP_PBRPC_INCLUDE_DIR})
include_directories(${proto_msg_BINARY_DIR})

add_executable(server server.cpp)
target_link_libraries(server proto_msg ${COAP_PBRPC_LIBRARY})

