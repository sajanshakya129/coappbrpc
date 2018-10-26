#ifndef __ServerRPC_H_INCLUDED_
#define __ServerRPC_H_INCLUDED_

#include "MsgSchema.pb.h"
#include <coap2/coap.h>
#include <google/protobuf/service.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "CoapCommon.h"
#include "HandleService.h"

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;
using ::coappbrpc::Request;
using ::coappbrpc::Response;

using namespace std;
namespace coappbrpc {

class ServerRPC {
public:
  ServerRPC();
  virtual ~ServerRPC();
  int start();
  bool stop(int);
  void runServer();
  void runServer(const char *,const char *);
  void registerService(Service *service);

  coap_context_t *ctx = nullptr;

  const char *port;
  const char *serverAddr;
  bool running = false;
};

} // namespace coappbrpc

#endif //__ServerRPC_H_INCLUDED_
