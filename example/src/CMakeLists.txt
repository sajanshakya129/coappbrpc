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

find_package(Protobuf REQUIRED)

include(FindLibcoapExt)
include(GenerateExportHeader)


include_directories(
    ${coappbrc_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROTOBUF_INCLUDE_DIRS}
    ${PROTOBUF_ROOT}/src
	${COAP_INCLUDE_DIRS}
	${proto_msg_BINARY_DIR}
	${COAP_PBRPC_INCLUDE_DIR}
)

message(${COAP_LIBRARIES})
message(${COAP_INCLUDE_DIRS})

link_directories(${libprotobuf_BINARY_DIR})

add_executable(server server.cpp)
target_link_libraries(server proto_msg ${COAP_PBRPC_LIBRARY} ${COAP_LIBRARIES} ${PROTOBUF_LIBRARIES})

add_executable(client client.cpp)
target_link_libraries(server proto_msg ${COAP_PBRPC_LIBRARY} ${COAP_LIBRARIES} ${PROTOBUF_LIBRARIES})