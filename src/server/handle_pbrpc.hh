#ifndef HANDLE_PB_RPC_HH_INCLUDED
#define HANDLE_PB_RPC_HH_INCLUDED

#include <string>
#include <google/protobuf/service.h>
using ::google::protobuf::Service;
namespace pbrpc {

using ::std::string;

// the only external APIs
void   init_pbrpc(void);
string handle_pbrpc(const char *data, const size_t len);
void  handle_regService(Service *service);

}

#endif
