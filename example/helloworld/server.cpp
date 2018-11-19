#include <coappbrpc/RpcServer.h> //To create server you must include this file: coappbrpc/RpcServer.h
#include "helloworld.pb.h" //including rpc_ping.pb.h generate when you run "coappbrpc.sh <protofile>" in command prompt.
            //<filename.proto> will generate "filename.pb.h" and "filename.pb.cc"
using ::coappbrpc::RpcServer; //Must be included in code

namespace coappbrpc {
namespace api {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;

class GreeterServiceImpl:public Greeter{//User defined class name GreeterServiceImpl which inherits from Greeter class.
public:
  GreeterServiceImpl(){};

  virtual void SayHello(RpcController *controller, const HelloRequest *request,
                    HelloReply *reply, Closure *done) {
     //Defining Function named "SayHello" which is defined as method in protobuf file. This is where you do 
    //processing and generate result and set result. 
    std::string prefix("Hello");
    reply->set_message(prefix + request->name());//Setting  message and accessing request parameter "name".
  }
};

} // namespace api
} // namespace coappbrpc

int main() {
  RpcServer server; //Creating instance of server
  server.registerService(new ::coappbrpc::api::GreeterServiceImpl()); //Registering service
  //server.runServer(); //running server
  server.runServer("localhost","5683");// You can run server by providing server_address and port no.
  return 0;
}
