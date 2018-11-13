#include <coappbrpc/RpcClient.h>

#include "ClientStub.h"
#include "helloworld.pb.h"
#include <iostream>
#include <string>

using ::coappbrpc::RpcClient;
using ::coappbrpc::api::Greeter;
using ::coappbrpc::api::HelloRequest;
using ::coappbrpc::api::HelloReply;
using namespace std;

class GreeterClient {
public:
  string SayHello(const std::string& user) { 
    
    HelloRequest request;
    request.set_name(user);

    HelloReply reply;
    stub.SayHello(request, &reply);

    return reply.message();
  }

private:
    ClientStub stub;
};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  RpcClient *client = RpcClient::getInstance();
  client->setServerAddr("localhost","5683");
  //client->setServerAddr("192.168.56.101","5683");
  std::string user("world");
  GreeterClient greeter;
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;
}
