#ifndef HANDLE_PB_RPC_HH_INCLUDED
#define HANDLE_PB_RPC_HH_INCLUDED

#include "ServiceManager.hh"
#include <google/protobuf/service.h>
#include <string>

namespace pbrpc {

using ::google::protobuf::Service;
using ::std::string;

void init_pbrpc(void);
string handle_pbrpc(const char *data, const size_t len);
void handle_regService(Service *service);

} // namespace pbrpc

#endif
