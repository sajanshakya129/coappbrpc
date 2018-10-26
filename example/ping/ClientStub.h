// This code is automatically generated.
#ifndef __ClientStub_H_INCLUDED_
#define __ClientStub_H_INCLUDED_
#include "rpc_ping.pb.h"
#include <coappbrpc/ClientRPC.h>
using ::coappbrpc::ClientRPC;
using ::coappbrpc::Request;
using ::coappbrpc::Response;
using ::coappbrpc::api::PingRequest;
using ::coappbrpc::api::PingResponse;
using namespace std;
class ClientStub {
public:
void Ping(PingRequest,PingResponse *);
private:
ClientRPC *client = ClientRPC::getInstance();
template<typename R> string serializeMsg(R);
};
#endif


