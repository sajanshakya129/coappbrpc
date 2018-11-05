/* RpcService.h -- RPC Services Handling , adding methods, getting methods and checking if method exists or not.
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcService.h
 * @brief RPC Services Handling , adding methods, getting methods and checking if method exists or not.
 */
#ifndef __ServiceRPC_H_INCLUDED_
#define __ServiceRPC_H_INCLUDED_

#include <map>
#include <string>

#include "RpcMethod.h"

namespace coappbrpc {

using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;
using ::std::map;
using ::std::string;

class RpcService {
public:
  RpcService() : _service(NULL){};

  RpcService(Service *service) : _service(service) {
    const ServiceDescriptor *serviceDesc = _service->GetDescriptor();
    const MethodDescriptor *methodDesc = NULL;
    const Message *request = NULL;
    const Message *response = NULL;

    // loop methods
    for (int i = 0; i < serviceDesc->method_count(); ++i) {
      methodDesc = serviceDesc->method(i);
      request = &_service->GetRequestPrototype(methodDesc);
      response = &_service->GetResponsePrototype(methodDesc);
      addMethod(RpcMethod(methodDesc, request, response), methodDesc->name());
    }
  }

  void addMethod(const RpcMethod &method, const string &methodName) {
    _methods[methodName] = method;
  }

  const RpcMethod *getMethod(const string &methodName) const {
    return &_methods.at(methodName);
  }

  bool isExistMethod(const string &methodName) const {
    return (_methods.find(methodName) != _methods.end());
  }

  Service *_service;               /**< The service */
  map<string, RpcMethod> _methods; /**< The methods in service */
};

} // namespace coappbrpc

#endif //__ServiceRPC_H_INCLUDED_
