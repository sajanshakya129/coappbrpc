# Define an executable
add_executable(app
    src/client.cpp
    src/server.cpp)

# Define the libraries this project depends upon
target_link_libraries(app
    coappbrpc)