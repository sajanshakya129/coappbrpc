#include "HandleService.h"

namespace coappbrpc {
ServiceManager __srv_man;

//void initService(void) { __srv_man.init(); }

string handleService(const char *data, const size_t len) {
  string ret;
  __srv_man.handleRPC(data, len, ret);
  return ret;
}

void handleRegService(Service *service) { __srv_man.regService(service); }

} // namespace coappbrpc
