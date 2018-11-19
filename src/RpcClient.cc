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

/*! \fn RpcClient::RpcClient()
    \brief RPC Client constructor
*/
RpcClient::RpcClient() {

}

/*! \fn RpcClient::~RpcClient()
    \brief RPC Client Destructor
*/
RpcClient::~RpcClient() {
}

/*! \fn RpcClient *RpcClient::getInstance()
    \brief getting new clientRPC instance
*/

RpcClient *RpcClient::getInstance() { 
  if (m_instance == 0) {
    m_instance = new RpcClient();
  }

  return m_instance;
}

/*! \fn void RpcClient::runClient()
    \brief Creates data structure to be sent to Coap Client and executes coap
   client's executeClient function
*/
void RpcClient::runClient(string payload) {
  // creates structure to run coap
  CoapClient coapclient;
  ClientParams params;
  params.addr = this->m_address;
  params.port = this->m_port;
  params.methodType = COAP_REQUEST_POST;
  params.interface = COAP_INTERFACE_NAME;
  params.payload = payload;
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

} // namespace coappbrpc
