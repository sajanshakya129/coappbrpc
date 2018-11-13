/* RpcService.h -- RPC Services Handling , adding methods, getting methods and
 * checking if method exists or not.
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcService.h
 * @brief RPC Services Handling , adding methods, getting methods and checking
 * if method exists or not.
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
/*! \class RpcService
 * \brief
 *This class defines service for remote calls. It has methods for adding rpc
 *methods, getting methods, validating if method exists.
 */
class RpcService {
public:
  RpcService() : _service(NULL){};
  /*! \fn  RpcService(Service *service) : _service(service)
   \brief This is constructor function that scans service description, gets
   request prototype & response prototype,loops over numbers of available
   methods and calls addMethod function for each methods defined.
   \param service
   service is of type Service defined in google's protobuf service
*/
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
  /*! \fn  addMethod(const RpcMethod &method, const string &methodName)
  \brief This function is setter function that adds methodName to _method array
  of type map<string, RpcMethod>
*/
  void addMethod(const RpcMethod &method, const string &methodName) {
    _methods[methodName] = method;
  }
  /*! \fn  RpcMethod *getMethod(const string &methodName) const
    \brief This is getter function that gets the methods if they exist in
    _method array
 */
  const RpcMethod *getMethod(const string &methodName) const {
    return &_methods.at(methodName);
  }

  /*! \fn  bool isExistMethod(const string &methodName) const
   \brief This function is for validating if the method name exists or not
*/
  bool isExistMethod(const string &methodName) const {
    return (_methods.find(methodName) != _methods.end());
  }

  Service *_service;               /*!< Instance pointer of Service */
  map<string, RpcMethod> _methods; /*!< The methods in service */
};

} // namespace coappbrpc

#endif //__ServiceRPC_H_INCLUDED_
