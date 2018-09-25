#include "ClientRPC.hh"
#include <iostream>

#include "../proto/rpc_ping.pb.h"
#include <curl/curl.h>
#include <pbrpc/pbrpc.pb.h>
#include <stdio.h>
#include <string>

using ::pbrpc::ClientRPC;
using ::pbrpc::Request;
using ::pbrpc::Response;
using ::pbrpc::api::PingRequest;
using ::pbrpc::api::PingResponse;
using ::pbrpc::api::PingService;
using namespace std;

class PingClient {
public:
  string ping(const string &msg) {
    cout << "inside ping" << endl;
    PingRequest request;
    request.set_message(msg);

    PingResponse response;
    // clientcontext
    // Status status=PingService.Ping(request, &response);
    // if (status.ok()) {
    //      return response.result();
    //    } else {
    //      cout << status.error_code() << ": " << status.error_message()
    //                << std::endl;
    //      return "RPC failed";
    //    }
  }
};

int main(void) {
GOOGLE_PROTOBUF_VERIFY_VERSION;
  ClientRPC client;
  Request req;
  req.set_pbrpc("1.1");
  req.set_service("PingService");
  req.set_method("Ping");
  req.set_params("testparams");
  req.set_id(123);
  std::string data;
  req.SerializeToString(&data);
  client.sendPayload(data);
  client.runClient();
  
  cout<<"getting response"<<endl;
  cout<<client.getResponse()<<endl;
  // resp.ParseFromString(client.getResponse());

  // cout<<"RESPONSE_VERSION"<<resp.pbrpc()<<endl;
  // cout<<"REPONSE_ID"<<resp.id()<<endl;
}
