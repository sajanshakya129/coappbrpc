include(FindProtobuf)
find_package(Protobuf REQUIRED)
if(NOT Protobuf_FOUND)
	message("Protobuf is not found installed in your system. Now installing Protobuf compiler and dev tools")
	execute_process(
	  COMMAND bash -c "sudo apt-get install libprotobuf-dev"
      OUTPUT_VARIABLE libprotobuf-dev-output
     )
    execute_process(
	  COMMAND bash -c "sudo apt-get install protobuf-compiler"
      OUTPUT_VARIABLE libprotobuf-compiler-output
     )
endif()