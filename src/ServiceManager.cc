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
/*! \fn ServiceManager::ServiceManager()
    \brief ServiceManager Constructor function
*/
ServiceManager::ServiceManager() {}

/*! \fn ServiceManager::~ServiceManager()
    \brief ServiceManager Destructor function, calls freeServices method
*/
ServiceManager::~ServiceManager() { freeServices(); }

/*! \fn void ServiceManager::regService(Service *service)
    \brief Registers services
    \param service
    instance of service pointer
*/
void ServiceManager::regService(Service *service) {
  const string &serviceName = service->GetDescriptor()->name();
  _services[serviceName] = RpcService(service);
}

/*! \fn RpcService *ServiceManager::getServiceRPC(string &serviceName)
    \brief inline const function that gets ServiceName that are registered
    \param serviceName

*/
inline const RpcService *
ServiceManager::getServiceRPC(const string &serviceName) const {
  return &_services.at(serviceName);
}

/*! \fn Service *ServiceManager::getService(const string &serviceName)
    \brief inline function that calls getServiceRPC function
    \param serviceName string

*/
inline Service *ServiceManager::getService(const string &serviceName) const {
  return getServiceRPC(serviceName)->_service;
}

/*! \fn RpcMethod *ServiceManager::getMethod(const string &serviceName,const
   string &methodName)
   \brief inline function that gets method of a particular
   service
   \param serviceName string \param methodName string

*/
inline const RpcMethod *
ServiceManager::getMethod(const string &serviceName,
                          const string &methodName) const {
  return getServiceRPC(serviceName)->getMethod(methodName);
}

/*! \fn void genResponse(string &ret, Response &rpcResponse, Message *response,ControllerRPC *controller)
   \brief inline function that gets method
   of a particular service
   \param ret pointer address to store returned string
   \param rpcResponse response from RPC of type Response
   \param response  response message
   \param controller instance of ControllerRPC

*/
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

/*! \fn void ServiceManager::handleRPC(const char *data, const size_t len,
                               string &ret)
   \brief This is important function that checks the validity of  the parameters
   passed and actual method calling takes place inside this function. If
   received parameters are not valid then error messages are sent back to
   client.
   \param data data sent to RPC
   \param len length of variable data
   \param ret output variable for response.

*/
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

/*! \fn bool ServiceManager::isValidParams(const char *data, const size_t len,
                                   ControllerRPC *controller) const
   \brief This function checks if paramters sent is not Null. This function
   compares data with Null and O. If data is Null or O it sets failed RPC and
   stores the reason for failure
   \param data data sent to RPC
   \param len length
   of variable data \param ret output variable for response.

*/
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

/*! \fn bool ServiceManager::isValidRequest(const Request &request,
                                    ControllerRPC *controller) const
   \brief This function checks if request received has valid version or not,
   checks if the service exists within registered service or not and finally
   checks if the method exists within a particular service or not.
   \param request request sent by client and received by server
   \param controller instance of ControllerRPC to handle error messages if
   validation fails

   */
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

/*! \fn bool ServiceManager::isValidVersion(const string &version) const
   \brief This function compares and checks if the version is valid or not
   \param version string value of version which is compared to macro value
   COAP_PBRPC_VERSION
   */
bool ServiceManager::isValidVersion(const string &version) const {
  return (COAP_PBRPC_VERSION == version);
}

/*! \fn bool ServiceManager::isExistService(const string &serviceName) const
   \brief This function checks if the service exists or not.
   \param serviceName string value name of service which is checked within
   registerd services.
   */
bool ServiceManager::isExistService(const string &serviceName) const {
  return (_services.find(serviceName) != _services.end());
}
/*! \fn void ServiceManager::freeServices(void)
   \brief This method is called from destructor function and it deletes all the
   services and release memory allocated by these services.
   */
void ServiceManager::freeServices(void) {
  map<string, RpcService>::iterator ite;
  for (ite = _services.begin(); ite != _services.end(); ++ite) {
    delete ite->second._service;
  }
}

} // namespace coappbrpc
