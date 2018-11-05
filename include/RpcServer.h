/* RpcServer.h -- Server Handling for CoAP protocol
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcServer.h
 * @brief Server Handling for CoAP protocol
 */
#ifndef __RpcServer_H_INCLUDED_
#define __RpcServer_H_INCLUDED_

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

class RpcServer {
public:
  RpcServer();
  virtual ~RpcServer();
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
