#include <stdio.h>

#include "ServerRPC.hh"

using ::pbrpc::ServerRPC;

int main() {
    ServerRPC server;
    server.start();
    return 0;
}
