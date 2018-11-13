/* RpcClient.cc -- Sets Client parameters to be passed as Coap Parameters and
 * calls for execution of CoAP protocol
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcClient.cc
 * @brief Sets Client parameters to be passed as Coap Parameters and calls for
 * execution of CoAP protocol **/
#include "RpcClient.h"

namespace coappbrpc {
RpcClient *RpcClient::m_instance = 0; // initializing instance

/*! \fn RpcClient *RpcClient::getInstance()
    \brief getting new clientRPC instance
*/

RpcClient *RpcClient::getInstance() { 
  if (m_instance == 0) {
    m_instance = new RpcClient();
  }

  return m_instance;
}

/*! \fn RpcClient::RpcClient()
    \brief RPC Client constructor
*/
RpcClient::RpcClient() {}

/*! \fn RpcClient::~RpcClient()
    \brief RPC Client Destructor
*/
RpcClient::~RpcClient() {}

/*! \fn void RpcClient::runClient()
    \brief Creates data structure to be sent to Coap Client and executes coap
   client's executeClient function
*/
void RpcClient::runClient() {
  // creates structure to run coap
  CoapClient coapclient;
  ClientParams params;
  params.addr = this->m_address;
  params.port = this->m_port;
  params.methodType = COAP_REQUEST_POST;
  params.interface = COAP_INTERFACE_NAME;
  params.payload = this->m_payload;
  coapclient.executeClient(params);
}

/*! \fn void RpcClient::setResponse(string resp)
    \brief Setter function to store response to m_response variable
    \param resp  Response string to be stored in member variable m_response
*/
void RpcClient::setResponse(string resp) { this->m_response = resp; }

/*! \fn string RpcClient::getResponse()
    \brief Getter function to get response stored in m_response variable
*/
string RpcClient::getResponse() { return this->m_response; }

/*! \fn void RpcClient::setServerAddr(string ipAddr, string port)
    \brief Setter function to store ip address and port  to m_address and m_port
   respectively \param ipAddr  Ip Address may be IPv4 or IPv6 to be stored in
   m_address variable \param port Port no to be stored in m_port variable
*/
void RpcClient::setServerAddr(string ipAddr, string port) {
  this->m_address = ipAddr;
  this->m_port = port;
}

/*! \fn Response RpcClient::execFunc(string vers, string serviceName, string method,
                             string msg)
    \brief Creates protocol buffer data structure containing version number,
   services, methods, method parameters, unique Random ids. Then it serializes
   the data into string and stores it in m_payload variable. This function calls
   runClient function. And after it receives response, it returns response as
   type Response.

   \param vers  version number defined in Config.h file
   \param serviceName Name of Service to be used for RPC calls
   \param method Method name to be called when executing RPC
   \param msg Serialized message to be sent to Server, contains defination of
   various parameters to a particular method.
*/
Response RpcClient::execFunc(string vers, string serviceName, string method,
                             string msg) {
  // sets request that is to be sent
  RpcClient *client = RpcClient::getInstance();
  Request req;
  req.set_version(vers);
  req.set_service(serviceName);
  req.set_method(method);
  req.set_params(msg);
  req.set_id((rand() % 9999 + 1));
  req.SerializeToString(&this->m_payload);
  client->runClient();

  Response resp;
  resp.ParseFromString(client->getResponse());
  return resp;
}

} // namespace coappbrpc
