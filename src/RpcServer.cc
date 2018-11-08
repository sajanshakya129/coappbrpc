/* RpcServer.cc -- Server Handling for CoAP protocol
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcServer.cc
 * @brief Server Handling for CoAP protocol
 */
#include "RpcServer.h"
/*! \def UNUSED_PARAM
    \brief A macro that defines if parameter is not used.
*/
#define UNUSED_PARAM
namespace coappbrpc {
/*! \fn void return_handler(coap_context_t *ctx,
                    struct coap_resource_t *resource,
                    coap_session_t *session,
                    coap_pdu_t *request,
                    coap_binary_t *token,
                    coap_string_t *query, coap_pdu_t *response)

    \brief Callback function that sets response data to be sent back to RPC
   client
   \param ctx Coap context variable reference of type struct
   coap_context_t.
   \param resource Coap resource referece.
   \param session Coap Session variable reference of type
   coap_session_t
   \param request CoAP PDU request received by server
   \param token CoAP unique token references
   \param query CoAP query reference
   \param response CoAP PDU response reference for storing data to be returned
   from Server
*/
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
  rpcResponse = handleService(reinterpret_cast<const char *>(data), data_len);
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


/*! \fn RpcServer::RpcServer()
    \brief Constructor function which sets variable "running" to false for every instance 
*/
RpcServer::RpcServer() { running = false; }

/*! \fn RpcServer::_RpcServer()
    \brief Destructor Function
*/
RpcServer::~RpcServer() {}

/*! \fn void RpcServer::runServer(const char *ipAddr, const char *port)
    \brief Setter function to set server ip address and port number and calls for "start" function to run Server.
      Default address is localhost and port is 5683. Function overloading used for handling default values incase parameters are not passed.
    \param ipAddr Ip Address reference variable
    \param port port reference variable
*/
void RpcServer::runServer(const char *ipAddr, const char *port) {
  this->serverAddr = ipAddr;
  this->port = port;
  this->start();
}
/*! \fn RpcServer::RpcServer()
    \brief Getter function to get response stored in m_response variable
*/
void RpcServer::runServer() {
  this->serverAddr = "localhost";
  this->port = "5683";
  this->start();
}
/*! \fn RpcServer::start()
    \brief creates context 
*/
int RpcServer::start() {
  if (running) {
    return 0;
  }

  CoapCommon common;

  coap_address_t dst;
  coap_resource_t *resource = nullptr;
  coap_endpoint_t *endpoint = nullptr;

  coap_str_const_t ruri = {3, (const uint8_t *)COAP_INTERFACE_NAME};

  coap_startup();
  std::cout << this->serverAddr << std::endl;
  /* resolve destination address where server should be sent */
  if (common.resolveAddress(this->serverAddr, this->port, &dst) < 0) {
    coap_log(LOG_CRIT, "failed to resolve address\n");
    this->stop(EXIT_FAILURE);
  }

  /* create CoAP context */
  ctx = this->ctx;
  ctx = coap_new_context(nullptr);

  if (!ctx || !(endpoint = coap_new_endpoint(ctx, &dst, COAP_PROTO_UDP))) {
    coap_log(LOG_EMERG, "cannot initialize context\n");
    this->stop(EXIT_FAILURE);
  }

  resource = coap_resource_init(&ruri, 0);
  coap_register_handler(resource, COAP_REQUEST_POST, return_handler);
  coap_add_resource(ctx, resource);

  while (true) {
    coap_run_once(ctx, 0);
  }
  running = true;
  this->stop(EXIT_SUCCESS);
}

bool RpcServer::stop(int result) {
  if (running) {
    coap_free_context(ctx);
    coap_cleanup();
    running = false;
  }

  return !running;
}

void RpcServer::registerService(Service *service) { handleRegService(service); }

} // namespace coappbrpc
