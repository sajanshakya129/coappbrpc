#ifndef __ClientRPC_HH_INCLUDED_
#define __ClientRPC_HH_INCLUDED_

#include <pbrpc/pbrpc.pb.h>
#include <string>
using namespace std;
typedef struct {
  string addr;
  string port;
  int methodType;
  string interface;
  string payload;
} ClientParams;

namespace pbrpc {
class ClientRPC {
public:
  string payload;
  ClientRPC();
  virtual ~ClientRPC();

};

} // namespace pbrpc

#endif //__ClientRPC_HH_INCLUDED_
