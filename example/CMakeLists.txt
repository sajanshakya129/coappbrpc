cmake_minimum_required(VERSION 2.8.4)

project(pingExample)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

find_library(COAP_PBRPC_LIB libcoappbrpc.a)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_library (COAP_LIBRARY NAMES
              coap-2
              libcoap-2
              lcoap-2
              libcoap-2
              coap
              libcoap
)

set(Client_SRCS
    client.cpp
	ClientStub.cc
	rpc_ping.pb.cc
	)

set(Server_SRCS
	server.cpp
	rpc_ping.pb.cc
	)

add_executable(client ${Client_SRCS})
target_link_libraries(client ${Protobuf_LIBRARIES} ${COAP_PBRPC_LIB} ${COAP_LIBRARY})

add_executable(server ${Server_SRCS})
target_link_libraries(server ${Protobuf_LIBRARIES} ${COAP_PBRPC_LIB} ${COAP_LIBRARY})

set_target_properties( client server
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)