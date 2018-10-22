#ifndef __ServiceRPC_H_INCLUDED_
#define __ServiceRPC_H_INCLUDED_

#include <map>
#include <string>

#include "MethodRPC.h"

namespace coappbrpc {

using ::google::protobuf::Service;
using ::google::protobuf::ServiceDescriptor;
using ::std::map;
using ::std::string;

class ServiceRPC {
public:
  ServiceRPC() : _service(NULL){};

  ServiceRPC(Service *service) : _service(service) {
    const ServiceDescriptor *serviceDesc = _service->GetDescriptor();
    const MethodDescriptor *methodDesc = NULL;
    const Message *request = NULL;
    const Message *response = NULL;

    // loop methods
    for (int i = 0; i < serviceDesc->method_count(); ++i) {
      methodDesc = serviceDesc->method(i);
      request = &_service->GetRequestPrototype(methodDesc);
      response = &_service->GetResponsePrototype(methodDesc);
      addMethod(MethodRPC(methodDesc, request, response), methodDesc->name());
    }
  }

  void addMethod(const MethodRPC &method, const string &methodName) {
    _methods[methodName] = method;
  }

  const MethodRPC *getMethod(const string &methodName) const {
    return &_methods.at(methodName);
  }

  bool isExistMethod(const string &methodName) const {
    return (_methods.find(methodName) != _methods.end());
  }

  Service *_service;               /**< The service */
  map<string, MethodRPC> _methods; /**< The methods in service */
};

} // namespace coappbrpc

#endif //__ServiceRPC_H_INCLUDED_
