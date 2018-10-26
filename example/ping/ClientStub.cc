// This code is automatically generated.
#include "ClientStub.h"
void ClientStub::Ping(PingRequest request,PingResponse *response)
{ Response resp;
resp=client->execFunc("1.1","PingService","Ping",serializeMsg(request));
response->ParseFromString(resp.result());
}

template <typename R>
string ClientStub::serializeMsg(R request) {
  std::string msg;
  request.SerializeToString(&msg);
  return msg;
}