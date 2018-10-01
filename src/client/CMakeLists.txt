project(pbrpc_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/local/lib -lprotobuf -pthread -I/usr/local/include/coap")

find_path (COAP_INCLUDE_DIR
           NAMES coap/coap.h
           PATH_SUFFIXES coap
)
mark_as_advanced (COAP_INCLUDE_DIR)

find_library (COAP_LIBRARY NAMES
              coap-2
              libcoap-2
              lcoap-2
              libcoap-2
              coap
              libcoap
)
mark_as_advanced (COAP_LIBRARY)

if(COAP_INCLUDE_DIR AND EXISTS "${COAP_INCLUDE_DIR}/coap/coap.h")
    file(STRINGS "${COAP_INCLUDE_DIR}/coap/coap.h" COAP_VERSION_LINE REGEX "^[ \t]*#[ \t]*define[ \t]+LIBCOAP_PACKAGE_VERSION[ \t]+")
    string(REGEX REPLACE "^[ \t]*#[ \t]*define[ \t]+LIBCOAP_PACKAGE_VERSION[ \t]+(.*)$" "\\1" COAP_VERSION_STRING "${COAP_VERSION_LINE}")
    unset(COAP_VERSION_LINE)
endif()

# Support the REQUIRED and QUIET arguments, and set COAP_FOUND if found.
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args(CoAP
                                  REQUIRED_VARS COAP_LIBRARY COAP_INCLUDE_DIR
                                  VERSION_VAR COAP_VERSION_STRING
)

if (COAP_FOUND)
    set (COAP_LIBRARIES ${COAP_LIBRARY})
    set (COAP_INCLUDE_DIRS ${COAP_INCLUDE_DIR})
else ()
    message (STATUS "No libcoap found")
endif()



set(pbrpc_client_SRCS
    client.cpp
    ClientRPC.cc
    CoapClient.cc
    ClientStub.cc
    ../common/CoapCommon.cc
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)

add_executable(runClient ${pbrpc_client_SRCS})

target_link_libraries(runClient pbrpc coap-2 proto_msg)