cmake_minimum_required(VERSION 2.8.4)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

project(coappbrpc)
set(CMAKE_BUILD_TYPE Release)

find_path (PBRPC_INCLUDE_DIR
           NAMES pbrpc/ServiceManager.hh
           PATH_SUFFIXES pbrpc
)
mark_as_advanced (PBRPC_INCLUDE_DIR)

find_library (PBRPC_LIBRARY NAMES
              pbrpc
              )

include(FindLibcoapExt)
include(FindProtobufExt)

include_directories(${PBRPC_INCLUDE_DIR})
include_directories(${COAP_INCLUDE_DIRS})
include_directories(${PROTOBUF_INCLUDE_DIRS})

link_directories(${PBRPC_INCLUDE_DIR})
include_directories(include)
file(GLOB COAP_PBRPC_SRCS "src/*.cc")

 
set(COAP_PBRPC_HDRS
	include/ClientRPC.hh
	include/CoapClient.hh
	include/CoapCommon.hh
	include/handle_pbrpc.hh
	include/ServerRPC.hh
)


set(INS_INCLUDE_DIR
    "/coappbrpc"
)

set(INS_TARGETS
    coappbrpc
)


add_library(coappbrpc STATIC ${COAP_PBRPC_SRCS})
target_link_libraries(coappbrpc PUBLIC ${COAP_LIBRARY} ${PBRPC_LIBRARY} ${PROTOBUF_LIBRARIES})

# Install
install(TARGETS ${INS_TARGETS}
    RUNTIME DESTINATION bin COMPONENT applications
    LIBRARY DESTINATION lib COMPONENT libraries
    ARCHIVE DESTINATION lib COMPONENT libraries
)
install(FILES ${COAP_PBRPC_HDRS} DESTINATION "include${INS_INCLUDE_DIR}" COMPONENT headers)
