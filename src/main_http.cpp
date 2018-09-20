#include <stdio.h>

#include "ServerRPC_http.hh"

using ::pbrpc::ServerRPC;

int main() {
    ServerRPC server;
    server.start();
    getchar();
    return 0;
}
