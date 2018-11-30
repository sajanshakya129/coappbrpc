#include <coappbrpc/RpcClient.h> // To Create client you must include this file: coappbrpc/RpcClient.h

#include "ClientStub.h" //including ClientStub.h generated when you run "coappbrpc.sh <protofile>" in command prompt.
#include "helloworld.pb.h" //including rpc_ping.pb.h generate when you run "coappbrpc.sh <protofile>" 
    //in command prompt. <filename.proto> will generate "filename.pb.h" and "filename.pb.cc"
#include <iostream>
#include <string>

using ::coappbrpc::RpcClient; //Must be included in code
using ::coappbrpc::api::Greeter;//Must be included in code
using ::coappbrpc::api::HelloRequest;//Must be included in code : User defined request in protofile
using ::coappbrpc::api::HelloReply;//Must be included in code : User defined reply in protofile
using namespace std;

class GreeterClient { //Defining Client Class
public:
  string SayHello(const std::string& user) { //Defining method ping where we use RPC call
    
    HelloRequest request;
    request.set_name(user);//Setting user msg to request.
    //Note: In set_name, name is the parameter that we defined in protofile request.
    HelloReply reply;
    stub.SayHello(request, &reply);// This is where actual RPC call is done.
    //Note: SayHello is the method that we defined in protofile.
    return reply.message();
  }

private:
    ClientStub stub; //creating instance of Client Stub
};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION; //verifiying protocol buffers version
  RpcClient *client = RpcClient::getInstance(); //creating a client instance
  client->setServerAddr("localhost","5683");//setting up Server address. Default is "localhost:5683". 
  //Note: must be in format <server_address>:<port_no>
  //client->setServerAddr("192.168.56.101","5683");
  std::string user("world");//defining msg to be sent to Server.
  GreeterClient greeter;
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  std::string user1("Harry Porter");
  std::string reply2 = greeter.SayHello(user1);
  std::cout << "User 1 Greeter received: " << reply2 << std::endl;

}
