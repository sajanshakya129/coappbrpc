// This code is automatically generated.
#ifndef __ClientStub_HH_INCLUDED_
#define __ClientStub_HH_INCLUDED_
#include "rpc_ping.pb.h"
#include "ClientRPC.hh"
using ::pbrpc::ClientRPC;
using ::pbrpc::Request;
using ::pbrpc::Response;
using ::pbrpc::api::PingRequest;
using ::pbrpc::api::PingResponse;
using namespace std;
class ClientStub {
public:
void Ping(PingRequest,PingResponse *);
void Add(PingRequest,PingResponse *);
private:
ClientRPC *client = ClientRPC::getInstance();
string Serialize(PingRequest);
string Serialize(PingResponse);
};
#endif


