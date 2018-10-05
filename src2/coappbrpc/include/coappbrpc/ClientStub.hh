#ifndef __ClientStub_HH_INCLUDED_
#define __ClientStub_HH_INCLUDED_

#include "../../build/proto/rpc_ping.pb.h"
#include "ClientRPC.hh"

using ::pbrpc::ClientRPC;
using ::pbrpc::Request;
using ::pbrpc::Response;
using ::pbrpc::api::PingRequest;
using ::pbrpc::api::PingResponse;
using namespace std;

class ClientStub {
public:
  void Ping(PingRequest, PingResponse *);
   /// autogeneration
private:
  ClientRPC *client = ClientRPC::getInstance();
  string Serialize(PingRequest);
};
#endif