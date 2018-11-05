/* ServiceManager.cc -- Handles Service creation, registration, getting and
 * setting Services, handles RPC and validates requests
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file ServiceManager.cc
 * @brief Handles Service creation, registration, getting and setting Services,
 * handles RPC and validates requests
 */
#include "ServiceManager.h"

namespace coappbrpc {

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::ServiceDescriptor;
/**
 * ServiceManger.h This is constructor function
 */
ServiceManager::ServiceManager() {}

ServiceManager::~ServiceManager() { freeServices(); }

void ServiceManager::regService(Service *service) {
  const string &serviceName = service->GetDescriptor()->name();
  _services[serviceName] = RpcService(service);
}

inline const RpcService *
ServiceManager::getServiceRPC(const string &serviceName) const {
  return &_services.at(serviceName);
}

inline Service *ServiceManager::getService(const string &serviceName) const {
  return getServiceRPC(serviceName)->_service;
}

inline const RpcMethod *
ServiceManager::getMethod(const string &serviceName,
                          const string &methodName) const {
  return getServiceRPC(serviceName)->getMethod(methodName);
}

void genResponse(string &ret, Response &rpcResponse, Message *response,
                 ControllerRPC *controller) {
  rpcResponse.set_version(COAP_PBRPC_VERSION);

  if (controller->Failed()) {
    Error error = controller->errorObj();
    rpcResponse.mutable_error()->CopyFrom(error);
  } else {
    // response could be NULL when the response is NOT required (empty)
    if (NULL != response) {
      rpcResponse.set_result(response->SerializeAsString());
    }
  }

  rpcResponse.SerializeToString(&ret);
  controller->Reset();
}

void ServiceManager::handleRPC(const char *data, const size_t len,
                               string &ret) {
  ControllerRPC *controller = new ControllerRPC();

  Response rpcResponse;
  rpcResponse.set_version(COAP_PBRPC_VERSION);

  // check parameters
  if (!isValidParams(data, len, controller)) {
    genResponse(ret, rpcResponse, NULL, controller);
    return;
  }

  Request rpcRequest;
  rpcRequest.ParseFromString(data);

  // validate the request
  if (!isValidRequest(rpcRequest, controller)) {
    genResponse(ret, rpcResponse, NULL, controller);
    return;
  }

  Service *service = getService(rpcRequest.service());
  const RpcMethod *method =
      getMethod(rpcRequest.service(), rpcRequest.method());

  Message *request = method->request->New();
  request->ParseFromString(rpcRequest.params());

  Message *response = method->response->New();

  // call the method for processing
  service->CallMethod(method->descriptor, controller, request, response, NULL);
  // construct rpc response
  rpcResponse.set_id(rpcRequest.id());
  genResponse(ret, rpcResponse, response, controller);
  delete request;
  delete response;
  delete controller;
}

bool ServiceManager::isValidParams(const char *data, const size_t len,
                                   ControllerRPC *controller) const {
  if (NULL == data) {
    controller->SetFailed("RPC received NULL data pointer.");
    return false;
  }

  // data is empty
  if (len == 0) {
    controller->SetFailed("RPC received zero length data.");
    return false;
  }

  return true;
}

bool ServiceManager::isValidRequest(const Request &request,
                                    ControllerRPC *controller) const {
  // check the version is valid
  if (!(isValidVersion(request.version()))) {
    controller->SetFailed(
        "The RPC request version does not qualify: Actual version: " +
        request.version() + " Required version: " + COAP_PBRPC_VERSION);
    return false;
  }

  // check the service is valid
  if (!isExistService(request.service())) {
    controller->SetFailed(
        "The requested RPC service does not exist. Service name: " +
        request.service());
    return false;
  }

  // check the method is valid
  if (!getServiceRPC(request.service())->isExistMethod(request.method())) {
    controller->SetFailed(
        "The requested RPC method does not exist. Method name: " +
        request.method());
    return false;
  }

  return true;
}

bool ServiceManager::isValidVersion(const string &version) const {
  return (COAP_PBRPC_VERSION == version);
}

bool ServiceManager::isExistService(const string &serviceName) const {
  return (_services.find(serviceName) != _services.end());
}

void ServiceManager::freeServices(void) {
  map<string, RpcService>::iterator ite;
  for (ite = _services.begin(); ite != _services.end(); ++ite) {
    delete ite->second._service;
  }
}

} // namespace coappbrpc
