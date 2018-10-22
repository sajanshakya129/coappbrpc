#ifndef HANDLE_Service_H_INCLUDED
#define HANDLE_Service_H_INCLUDED

#include "ServiceManager.h"
#include <google/protobuf/service.h>
#include <string>

namespace coappbrpc {

using ::google::protobuf::Service;
using ::std::string;

//void initService(void);
string handleService(const char *, const size_t );
void handleRegService(Service *);

} // namespace coappbrpc

#endif
