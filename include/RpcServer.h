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
using ::coappbrpc::Request;
using ::coappbrpc::Response;
using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;

using namespace std;
namespace coappbrpc {
/*! \class RpcServer
 * \brief
 *This class consists of methods to registerService and initiateServer.
 */
class RpcServer {
public:
  RpcServer();
  virtual ~RpcServer();
  int startServer();
  bool stopServer(int);
  void initiateServer();
  void initiateServer(const char *, const char *);
  void registerService(Service *service);

private:
  coap_context_t *ctx = nullptr; /*!< Coap context pointer variable */
  const char *port;              /*!< const char variable to store port no */
  const char *serverAddr;        /*!< const char variable to store IP address */
  bool running =
      false; /*!< boolean variable to flag whether RPC is running or not */
};

} // namespace coappbrpc

#endif //__ServerRPC_H_INCLUDED_
