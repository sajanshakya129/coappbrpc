cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

project(CoapPbRpc)

set (CoapPbRpc_VERSION_MAJOR 0)
set (CoapPbRpc_VERSION_MINOR 1)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )


add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(common)