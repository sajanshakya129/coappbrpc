project(mongoose)
set(MONGOOSE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
if(NOT MONGOOSE_ROOT_DIR)
  message(FATAL_ERROR "MONGOOSE_ROOT_DIR must be set to the location of mongoose sources.")
else()
  message(STATUS "mongoose sources in ${MONGOOSE_ROOT_DIR}")
endif()

# set output
set(LIBRARY_OUTPUT_PATH ${mongoose_BINARY_DIR}/lib)

# set header files
set(mongoose_HDRS
    ${MONGOOSE_ROOT_DIR}/mongoose.h
)

# set source files
set(mongoose_SRCS
    ${MONGOOSE_ROOT_DIR}/mongoose.c
)

# set lib
add_library(mongoose STATIC ${mongoose_SRCS})

target_include_directories(mongoose PUBLIC "${MONGOOSE_ROOT_DIR}")

target_link_libraries(mongoose pthread dl)

