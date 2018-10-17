cmake_minimum_required(VERSION 2.8.4)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

project(coappbrpc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(proto)

include(FindPythonInterp)
if(NOT PYTHONINTERP_FOUND)
  message(FATAL_ERROR" Python doesnot exist in your system.Please download and install Python3 in your System")
else(PYTHONINTERP_FOUND)
  message("Python version " ${PYTHON_VERSION_STRING} " exists in your system")
endif(NOT PYTHONINTERP_FOUND)


include(FindProtobuf)
find_package(Protobuf REQUIRED)

include(FindLibcoapExt)
include(GenerateExportHeader)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROTOBUF_INCLUDE_DIRS}
    ${PROTOBUF_ROOT}/src
    ${pbrpc_proto_BINARY_DIR}
    ${COAP_INCLUDE_DIRS}
    include
    generator
)

link_directories(${PROTOBUF_LIBRARIES})

set(py_cmd "generator/checkPyLibs.py")
execute_process(
                  COMMAND ${PYTHON_EXECUTABLE} ${py_cmd}
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  RESULT_VARIABLE py_result
               )

file(GLOB COAP_PBRPC_SRCS "src/*.cc")
 
set(COAP_PBRPC_HDRS
  include/Config.h
  include/ControllerRPC.hh
  include/MethodRPC.hh
  include/ServiceManager.hh
  include/ServiceRPC.hh
	include/ClientRPC.hh
	include/CoapClient.hh
	include/CoapCommon.hh
	include/HandlePbrpc.hh
	include/ServerRPC.hh
)


add_library(coappbrpc STATIC ${COAP_PBRPC_SRCS} $<TARGET_OBJECTS:pbrpc_proto>)
target_link_libraries(coappbrpc PUBLIC  ${COAP_LIBRARIES} ${PROTOBUF_LIBRARIES})

GENERATE_EXPORT_HEADER(coappbrpc)

set(INS_INCLUDE_DIR
    "/coappbrpc"
)

set(INS_TARGETS
    coappbrpc
)

# Install
install(TARGETS ${INS_TARGETS}
    RUNTIME DESTINATION bin COMPONENT applications
    LIBRARY DESTINATION lib COMPONENT libraries
    ARCHIVE DESTINATION lib COMPONENT libraries
)
# python scripts
set(COAPPBRPC_TEMPLATES_FILES
  generator/templates/ClientStubTemplate.cc
  generator/templates/ClientStubTemplate.hh
  generator/cogFiles.txt
  
)

set(COAPPBRPC_COMPILER
  generator/coappbrpc.sh
)

set(COAPPBRPC_PLUGIN
  generator/coappbrpcPlugin.py)


install(FILES 
        ${COAP_PBRPC_HDRS} ${proto_HDRS}
        ${PROJECT_BINARY_DIR}/coappbrpc_export.h
  DESTINATION "include${INS_INCLUDE_DIR}" COMPONENT headers)

install(FILES ${COAPPBRPC_TEMPLATES_FILES} 
   DESTINATION "include${INS_INCLUDE_DIR}/templates" COMPONENT headers)

install(FILES ${COAPPBRPC_COMPILER} 
   DESTINATION bin 
   PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
   COMPONENT applications)

install(FILES ${COAPPBRPC_PLUGIN} 
    DESTINATION "include${INS_INCLUDE_DIR}/templates" 
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    COMPONENT headers)