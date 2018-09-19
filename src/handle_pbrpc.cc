#include "handle_pbrpc.hh"

#include <pbrpc/ServiceManager.hh>

#include "service/Ping.hh"

namespace pbrpc {

using std::string;

ServiceManager __srv_man;

void init_pbrpc(void) {
	std::cout<<"inside handle pbrpc.cc init_pbrpc"<<std::endl;
    __srv_man.init();
    __srv_man.regService(new ::pbrpc::api::PingServiceImpl());
}

string handle_pbrpc(const char *data, const size_t len) {
    string ret;
    std::cout<<"inside handle pbrpc.cc handle_pbrpc"<<std::endl;
    __srv_man.handleRPC(data, len, ret);
    return ret;
}

}
