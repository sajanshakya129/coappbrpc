/** \page Ping Examples
 *
 * \section Ping
 *
 * This example will demonstrate how to create client and server using
 * coappbprpc library.
 */
#include <coappbrpc/RpcClient.h>

#include "ClientStub.h"
#include "rpc_ping.pb.h"
#include <iostream>
#include <string>

using ::coappbrpc::RpcClient;
using ::coappbrpc::api::PingRequest;
using ::coappbrpc::api::PingResponse;
using ::coappbrpc::api::PingService;
using namespace std;

class PingClient {
public:
  string ping(const string &msg) {

    PingRequest request;
    request.set_msg(msg);

    PingResponse response;
    stub.Ping(request, &response);

    return response.result();
  }

private:
  ClientStub stub;
};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  RpcClient *client = RpcClient::getInstance();
  client->setServerAddr("localhost", "5683");
  // client->setServerAddr("::1","5683");
  std::string msg("Hello world");
  PingClient pclient;
  std::string reply = pclient.ping(msg);
  std::cout << "Ping received: " << reply << std::endl;
}
