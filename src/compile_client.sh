#! /bin/bash
echo compiling client for testing
c++ -o client ../proto/rpc_ping.pb.cc ../deps/libpbrpc/proto/pbrpc.pb.cc client.cpp `pkg-config --cflags --libs protobuf` -lcurl -I/usr/local/include/pbrpc

