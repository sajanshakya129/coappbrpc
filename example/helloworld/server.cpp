#include <coappbrpc/ServerRPC.h> //for server rpc handling
#include "helloworld.pb.h" //protobuf output file

using ::coappbrpc::ServerRPC;

namespace coappbrpc {
namespace api {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;

class GreeterServiceImpl:public Greeter{
public:
  GreeterServiceImpl(){};

  virtual void SayHello(RpcController *controller, const HelloRequest *request,
                    HelloReply *reply, Closure *done) {
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
  }
};

} // namespace api
} // namespace coappbrpc

int main() {
  ServerRPC server;
  server.registerService(new ::coappbrpc::api::GreeterServiceImpl());
  server.runServer("localhost","5683");
  return 0;
}
