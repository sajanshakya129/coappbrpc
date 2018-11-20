#include <coappbrpc/RpcServer.h> //for server rpc handling
#include "rpc_ping.pb.h" //protobuf output file

using ::coappbrpc::RpcServer;

namespace coappbrpc {
namespace api {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;

class PingServiceImpl : public PingService {
public:
  PingServiceImpl(){};

  virtual void Ping(RpcController *controller, const PingRequest *request,
                    PingResponse *response, Closure *done) {
    // Do your processing here

    // Fill response
    response->set_result("I got your message: " + request->msg());
  }
};

} // namespace api
} // namespace coappbrpc

int main() {
  RpcServer server;
  server.registerService(new ::coappbrpc::api::PingServiceImpl());
  //server.initiateServer();
  server.initiateServer("localhost","5683");
  //server.initiateServer("::1","5683"); //Ipv6
  return 0;
}
