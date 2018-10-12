#include "ServiceManager.hh"
#include "Config.h"
#include "iostream"

namespace pbrpc {

using ::google::protobuf::ServiceDescriptor;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::Message;

ServiceManager::ServiceManager() {}

ServiceManager::~ServiceManager() {
    dest();
}

void ServiceManager::init(void) {
     std::cout<<"inside Service Manager initialized"<<std::endl;
}

void ServiceManager::dest(void) {
    freeServices();
}

void ServiceManager::regService(Service *service) {
    std::cout<<"inside Service Manager reg Service"<<std::endl;
    const string& serviceName = service->GetDescriptor()->name();
    std::cout<<"serviceName--->"<<serviceName<<std::endl;
    _services[serviceName] = ServiceRPC(service);
}

inline const ServiceRPC *ServiceManager::getServiceRPC(const string &serviceName) const {
    std::cout<<"inside Service Manager getService name"<<std::endl;
    return &_services.at(serviceName);
}

inline Service *ServiceManager::getService(const string &serviceName) const {
     std::cout<<"inside Service Manager get Service"<<std::endl;
    return getServiceRPC(serviceName)->_service;
}

inline const MethodRPC* ServiceManager::getMethod(const string &serviceName, const string &methodName) const {
     std::cout<<"inside Service Manager get Method"<<std::endl;
     std::cout<<"returning"<<getServiceRPC(serviceName)->getMethod(methodName)<<std::endl;

    return getServiceRPC(serviceName)->getMethod(methodName);
}

void genResponse(string &ret, Response &rpcResponse, Message *response, ControllerRPC *controller) {
     std::cout<<"inside Service Manager generate response"<<std::endl;
    rpcResponse.set_pbrpc(PBRPC_VERSION);

    if (controller->Failed()) {
        std::cout<<"inside Service Manager failed response"<<std::endl;
        Error error = controller->ErrorObj();
        rpcResponse.mutable_error()->CopyFrom(error);
    }
    else {
        // response could be NULL when the response is NOT required (empty)
        std::cout<<"inside Service Manager  not failed response"<<std::endl;
        if (NULL != response) {
            std::cout<<"inside Service Manager not NULL response"<<std::endl;
            rpcResponse.set_result(response->SerializeAsString());
        }
    }

    rpcResponse.SerializeToString(&ret);
    controller->Reset();
}

// totally functional and thread safe, use local storage
void ServiceManager::handleRPC(const char *data, const size_t len, string &ret) {
 std::cout<<"inside Service Manager handling RPC"<<std::endl;
    ControllerRPC *controller = new ControllerRPC();

    Response rpcResponse;
    rpcResponse.set_pbrpc(PBRPC_VERSION);

    // check parameters
    if (!isValidParams(data, len, controller)) {
         std::cout<<"inside Service Manager not Valid Parameters"<<std::endl;
        genResponse(ret, rpcResponse, NULL, controller);
        return;
    }

    Request rpcRequest;
    std::cout<<"data------>>>>Server<<"<<data<<std::endl;

    rpcRequest.ParseFromString(data);
    //rpcRequest.ParseFromArray(data, len);
     std::cout<<"data------version<<"<<rpcRequest.pbrpc()<<std::endl;
    // assert(rpcRequest.pbrpc() == "1.1");

    // validate the request
    if (!isValidRequest(rpcRequest, controller)) {
         std::cout<<"inside Service Manager not Valid Request"<<std::endl;
        genResponse(ret, rpcResponse, NULL, controller);
        return;
    }else{
         std::cout<<"VALID REQUEST"<<std::endl;
    }


    std::cout<<rpcRequest.service()<<std::endl;
    std::cout<<rpcRequest.method()<<std::endl;
    std::cout<<rpcRequest.service()<<std::endl;
    std::cout<<rpcRequest.params()<<std::endl;

    Service *service = getService(rpcRequest.service());
    const MethodRPC *method = getMethod(rpcRequest.service(), rpcRequest.method());
    
    Message *request  = method->request->New();
    request->ParseFromString(rpcRequest.params());
    
    Message *response = method->response->New();

    // call the method for processing
    service->CallMethod(method->descriptor, controller, request, response, NULL);
    std::cout<<"Testing4"<<std::endl;
    // construct rpc response
    rpcResponse.set_id(rpcRequest.id());
    std::cout<<"Testing5"<<std::endl;
    genResponse(ret, rpcResponse, response, controller);
    std::cout<<"Testing6"<<std::endl;
    delete request;
    delete response;
    delete controller;
}

bool ServiceManager::isValidParams(const char *data, const size_t len, ControllerRPC *controller) const {
     std::cout<<"inside Service Manager checking valid paramaters"<<std::endl;
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

bool ServiceManager::isValidRequest(const Request &request, ControllerRPC *controller) const {
     std::cout<<"inside Service Manager checking valid Request"<<std::endl;
    // check the version is valid
    std::cout<<"version no"<<request.pbrpc()<<std::endl;

    if (!(isValidVersion(request.pbrpc()))) {
         std::cout<<"ERROR:version no"<<request.pbrpc()<<std::endl;
        controller->SetFailed("The RPC request version does not qualify: Actual version: " + request.pbrpc() + " Required version: " + PBRPC_VERSION);
        return false;
    }

    // check the service is valid
    if (!isExistService(request.service())) {
        std::cout<<"ERROR:Service Name"<<request.service()<<"doesnotexist"<<std::endl;
        controller->SetFailed("The requested RPC service does not exist. Service name: " + request.service());
        return false;
    }

    // check the method is valid
    if (!getServiceRPC(request.service())->isExistMethod(request.method())) {
        std::cout<<"ERROR:Method Name-->"<<request.method()<<" does not exist"<<std::endl;
        std::cout<<"method-->"<<request.method()<<std::endl;
        controller->SetFailed("The requested RPC method does not exist. Method name: " + request.method());
        return false;
    }

    return true;
}

bool ServiceManager::isValidVersion(const string &version) const {
     std::cout<<"inside Service Manager checking valid version"<<std::endl;
    return (PBRPC_VERSION == version);
}

bool ServiceManager::isExistService(const string &serviceName) const {
     std::cout<<"inside Service Manager check if service Exist"<<std::endl;
    return (_services.find(serviceName) != _services.end());
}

void ServiceManager::freeServices(void) {
    // loop services
     std::cout<<"inside Service Manager freeing services"<<std::endl;
    map<string, ServiceRPC>::iterator ite;
    for (ite = _services.begin(); ite != _services.end(); ++ite) {
        delete ite->second._service;
    }
}

}
