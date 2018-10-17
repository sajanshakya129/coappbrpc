#include "HandlePbrpc.hh"

namespace pbrpc {
ServiceManager __srv_man;

void init_pbrpc(void) { __srv_man.init(); }

string handle_pbrpc(const char *data, const size_t len) {
  string ret;
  __srv_man.handleRPC(data, len, ret);
  return ret;
}

void handle_regService(Service *service) { __srv_man.regService(service); }

} // namespace pbrpc
