#include <stdio.h>

#include "ServerRPC.hh"

#include "../../build/proto/rpc_ping.pb.h"

using namespace std;
using ::pbrpc::ServerRPC;
namespace pbrpc {
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
} // namespace pbrpc

int main() {
  ServerRPC server;
  server.registerService(new ::pbrpc::api::PingServiceImpl());
  server.start("localhost:5683");
  return 0;
}
