#include <stdio.h>

#include <coappbrpc/ServerRPC.hh> //for server rpc handling
#include "sum.pb.h" //protobuf output file

using namespace std;
using ::pbrpc::ServerRPC;

namespace pbrpc {
namespace api {

using ::google::protobuf::Closure;
using ::google::protobuf::RpcController;

class SumServiceImpl : public SumService {
public:
  SumServiceImpl(){};

  virtual void Add(RpcController *controller, const AddRequest *request,
                    AddResponse *response, Closure *done) {
    // Do your processing here
    int op1=request->operand1();
    int op2=request->operand2();
    // Fill response
    response->set_result(op1+op2);
  }
};

} // namespace api
} // namespace pbrpc

int main() {
  ServerRPC server;
  server.registerService(new ::pbrpc::api::SumServiceImpl());
  server.runServer();
  // server.runServer("localhost:5683");
  return 0;
}
