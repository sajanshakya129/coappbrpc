#include "ClientRPC.hh"
#include "ClientStub.hh"

#include <iostream>

#include "../../build/proto/rpc_ping.pb.h"

#include <string>

using ::pbrpc::ClientRPC;
using ::pbrpc::api::PingRequest;
using ::pbrpc::api::PingResponse;
using ::pbrpc::api::PingService;
using namespace std;

class PingClient {
public:
  string ping(const string &msg) {
    cout << "inside PingClient:ping" << endl;
    
    PingRequest request;
    request.set_message(msg);

    PingResponse response;
    stub.Ping(request, &response);

    return response.result();
  }

private:
    ClientStub stub;
};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ClientRPC *client = ClientRPC::getInstance();
  client->SetServerAddr("localhost:5683");
  

  std::string msg("Testing User Msg");
  PingClient pclient;
  std::string reply = pclient.ping(msg);
  std::cout << "Ping received: " << reply << std::endl;
}
