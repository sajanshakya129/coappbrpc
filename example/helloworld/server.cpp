#include <coappbrpc/RpcServer.h> //for server rpc handling
#include "helloworld.pb.h" //protobuf output file

using ::coappbrpc::RpcServer;

namespace coappbrpc {
namespace api {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;

class GreeterServiceImpl:public Greeter{
public:
  GreeterServiceImpl(){};

  virtual void SayHello(RpcController *controller, const HelloRequest *request,
                    HelloReply *reply, Closure *done) {
    std::string prefix("Hello");
    reply->set_message(prefix + request->name());
  }
};

} // namespace api
} // namespace coappbrpc

int main() {
  RpcServer server;
  server.registerService(new ::coappbrpc::api::GreeterServiceImpl());
  server.runServer("localhost","5683");
  //server.runServer("192.168.56.101","5683");
  return 0;
}
