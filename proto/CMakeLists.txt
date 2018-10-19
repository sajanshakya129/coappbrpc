cmake_minimum_required(VERSION 2.8.4)

project(msg_schema)

# The .proto source files
file(GLOB proto_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")

# set PROTOBUF_ROOT to compile protobuf with protobuf-cmake
if(PROTOBUF_ROOT)
    set(PROTOBUF_SRC_ROOT_FOLDER   ${PROTOBUF_ROOT})
    set(PROTOBUF_LIBRARY           ${libprotobuf_BINARY_DIR})
    set(PROTOBUF_PROTOC_EXECUTABLE ${protoc_BINARY_DIR}/protoc)
    set(PROTOBUF_LIBRARIES libprotobuf)
    link_directories(${libprotobuf_BINARY_DIR})
endif()

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Generate the proto message files
PROTOBUF_GENERATE_CPP(proto_SRCS proto_HDRS ${proto_FILES})

set_source_files_properties(${proto_FILES} PROPERTIES GENERATED TRUE)

# Build library, link as object
add_library(msg_schema OBJECT ${proto_SRCS})
target_include_directories(msg_schema PUBLIC "${msg_schema_BINARY_DIR}")


 
set(INS_INCLUDE_DIR "/coappbrpc")

install(FILES ${proto_HDRS} DESTINATION "include${INS_INCLUDE_DIR}" COMPONENT headers)


