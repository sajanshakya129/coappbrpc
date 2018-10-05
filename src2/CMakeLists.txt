cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)
project(coappbrpc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
include(GNUInstallDirs)


# Include Boost as an imported target
find_package(Boost REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

find_package(protobuf REQUIRED)

enable_testing()
add_subdirectory(coappbrpc)
add_subdirectory(app)