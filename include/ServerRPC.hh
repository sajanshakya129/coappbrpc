#ifndef __ServerRPC_HH_INCLUDED_
#define __ServerRPC_HH_INCLUDED_

#include "pbrpc.pb.h"
#include <coap2/coap.h>
#include <google/protobuf/service.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "CoapCommon.hh"
#include "HandlePbrpc.hh"

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;
using ::pbrpc::Request;
using ::pbrpc::Response;

using namespace std;
namespace pbrpc {

class ServerRPC {
public:
  ServerRPC();
  virtual ~ServerRPC();
  void init(void);
  int start();
  bool stop(int);
  void runServer();
  void runServer(string);
  void registerService(Service *service);

  coap_context_t *ctx = nullptr;

  int port;
  string serverAddr;
  bool running = false;
};

} // namespace pbrpc

#endif //__ServerRPC_HH_INCLUDED_
