#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "ServerRPC.hh"
#include "handle_pbrpc.hh"
#include "server_cfg.h"
#include <pbrpc/pbrpc.pb.h>

using ::google::protobuf::Message;
using ::google::protobuf::MethodDescriptor;
using ::google::protobuf::ServiceDescriptor;

using ::pbrpc::Request;
using ::pbrpc::Response;

#define UNUSED_PARAM
namespace pbrpc {

void return_handler(coap_context_t *ctx UNUSED_PARAM,
                    struct coap_resource_t *resource UNUSED_PARAM,
                    coap_session_t *session UNUSED_PARAM,
                    coap_pdu_t *request UNUSED_PARAM,
                    coap_binary_t *token UNUSED_PARAM,
                    coap_string_t *query UNUSED_PARAM, coap_pdu_t *response) {
  unsigned char buf[3];
  const char *response_data;
  
  unsigned char *data;
  size_t data_len;
  coap_get_data(request, &data_len, &data); // data must be unsigned char *

  string rpcResponse;
  rpcResponse=handle_pbrpc(reinterpret_cast<const char *>(data), data_len);
  std::cout<<"REPONSE TO BE SENT BACK USING COAP"<<std::endl;
  std::cout<<rpcResponse<<std::endl;
  response_data = rpcResponse.c_str();
  response->code = COAP_RESPONSE_CODE(205);
  coap_add_option(response, COAP_OPTION_CONTENT_TYPE,
                  coap_encode_var_safe(buf, sizeof(buf),
                                       COAP_MEDIATYPE_APPLICATION_OCTET_STREAM),
                  buf);
  coap_add_option(response, COAP_OPTION_MAXAGE,
                  coap_encode_var_safe(buf, sizeof(buf), 0x2ffff), buf);
  coap_add_data(response, strlen(response_data),
                (const uint8_t *)response_data);
}

ServerRPC::ServerRPC() {
  //std::cout << "from send serverRPC constructor" << std::endl;
  init();
}

ServerRPC::~ServerRPC() { 
//std::cout << "from send destructor" << std::endl; 
}

int ServerRPC::start(void) {
  //std::cout << "from send start ServerRPC" << std::endl;
  if (running) {
    return 0;
  }
  CoapCommon common;

  char port[6];
  snprintf(port, sizeof(port), "%d", this->port);

  coap_address_t dst;
  coap_resource_t *resource = nullptr;
  coap_endpoint_t *endpoint = nullptr;

  coap_str_const_t ruri = {3, (const uint8_t *)"rpc"};

  coap_startup();

  /* resolve destination address where server should be sent */
  if (common.resolve_address("localhost", port, &dst) < 0) {
    coap_log(LOG_CRIT, "failed to resolve address\n");
    this->stop(EXIT_FAILURE);
  }

  /* create CoAP context and a client session */
  ctx = this->ctx;
  ctx = coap_new_context(nullptr);

  if (!ctx || !(endpoint = coap_new_endpoint(ctx, &dst, COAP_PROTO_UDP))) {
    coap_log(LOG_EMERG, "cannot initialize context\n");
    this->stop(EXIT_FAILURE);
  }

  // This code is automatically generated.
  resource = coap_resource_init(&ruri, 0);
  coap_register_handler(resource, COAP_REQUEST_POST, return_handler);
  coap_add_resource(ctx, resource);

  while (true) {
    coap_run_once(ctx, 0);
  }
  running = true;
  this->stop(EXIT_SUCCESS);
}

void ServerRPC::init(void) {
  std::cout << "from send ServerRPC init" << std::endl;
  running = false;
  // init the PBRPC system
  init_pbrpc();
}

bool ServerRPC::stop(int result) {
  std::cout << "from send ServerRPC stop" << std::endl;
  if (running) {
    // mg_stop(ctx);
    coap_free_context(ctx);
    coap_cleanup();
    running = false;
    // ctx = nullptr;
  }

  return !running;
}

} // namespace pbrpc