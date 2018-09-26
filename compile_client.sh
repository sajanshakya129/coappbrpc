#! /bin/bash
echo compiling client for testing
c++ -o client build/proto/rpc_ping.pb.cc build/deps/libpbrpc/proto/pbrpc.pb.cc src/ClientRPC.cc src/coap_common.cc src/coap_client.cc src/client.cpp `pkg-config --cflags --libs protobuf` -I/usr/local/include/pbrpc -lcoap-2

