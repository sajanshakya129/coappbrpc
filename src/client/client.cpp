#include "ClientRPC.hh"
#include <cstdlib>
#include <iostream>

#include "../../build/proto/rpc_ping.pb.h"

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
    cout << "inside PingClient:ping" << endl;
    PingRequest request;
    request.set_message(msg);

    PingResponse response;

    // Status status = PingService.Ping(request, &response);
    // if (status.ok()) {
    //   return response.result();
    // } else {
    //   cout << status.error_code() << ": " << status.error_message()
    //        << std::endl;
    //   return "RPC failed";
    // }
  }
private:

};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ClientRPC *client = ClientRPC::getInstance();
  client->createChannel("localhost:5683");
  std::string msg("Testing User Msg");
  //std::string reply = PingClient.ping(msg);
  //std::cout << "Ping received: " << reply << std::endl;
}
// int main(void) {
//   GOOGLE_PROTOBUF_VERIFY_VERSION;
//   ClientRPC *client = ClientRPC::getInstance();
//   client->createChannel("localhost:5683");

//   std::string msg("Testing User Msg");
//   std::string reply = PingClient.ping(msg);
//   std::cout << "Ping received: " << reply << std::endl;

//   // setting ping request and serializing it
//   std::string msg;
//   PingRequest request;
//   request.set_message("Testing User Msg");
//   request.SerializeToString(&msg);

//   // Preparing RPC Generic request

//   Request req;
//   req.set_pbrpc("1.1");
//   req.set_service("PingService");
//   req.set_method("Ping");
//   req.set_params(msg);
//   req.set_id((rand() % 9999 + 1));
//   std::string data;
//   req.SerializeToString(&data);
//   client->sendPayload(data);
//   client->runClient();

//   // Getting response and deserializing
//   Response resp;
//   resp.ParseFromString(client->getResponse());

//   if (resp.id() != 0) {
//     cout << "RESPONSE_VERSION::  " << resp.pbrpc() << endl;
//     cout << "REPONSE_ID::  " << resp.id() << endl;

//     // Deserializing PingResponse

//     PingResponse response;
//     response.ParseFromString(resp.result());
//     cout << "RESPONSE_message:: " << response.result() << endl;
//   }else{
//     cout<<"RPC ERROR"<<endl;
//   }
// }

