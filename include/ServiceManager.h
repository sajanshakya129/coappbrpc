#ifndef __ServiceManager_H_INCLUDED_
#define __ServiceManager_H_INCLUDED_

#include <map>
#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>

#include "Config.h"
#include "ControllerRPC.h"
#include "MethodRPC.h"
#include "ServiceRPC.h"
#include "MsgSchema.pb.h"

namespace coappbrpc {

using ::google::protobuf::RpcController;
using ::google::protobuf::Service;
using ::std::map;
using ::std::string;

class ServiceManager {
public:
  ServiceManager();
  virtual ~ServiceManager();
  void handleRPC(const char *data, const size_t len, string &ret);
  void regService(Service *service);

private:
  void freeServices(void);
  inline Service *getService(const string &serviceName) const;
  inline const ServiceRPC *getServiceRPC(const string &serviceName) const;
  inline const MethodRPC *getMethod(const string &serviceName,
                                    const string &methodName) const;

  bool isValidParams(const char *data, const size_t len,
                     ControllerRPC *controller) const;
  bool isValidRequest(const Request &request, ControllerRPC *controller) const;
  bool isValidVersion(const string &version) const;
  bool isExistService(const string &serviceName) const;

  // services in a map
  map<string, ServiceRPC> _services;
};

} // namespace coappbrpc

#endif //__ServiceManager_H_INCLUDED_
