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

#include <random>
namespace coappbrpc {
RpcClient *RpcClient::m_instance = 0; // initializing instance

/*! \fn RpcClient::RpcClient()
    \brief RPC Client constructor
*/
RpcClient::RpcClient() {}

/*! \fn RpcClient::~RpcClient()
    \brief RPC Client Destructor
*/
RpcClient::~RpcClient() {}

/*! \fn RpcClient *RpcClient::getInstance()
    \brief getting new clientRPC instance
*/

RpcClient *RpcClient::getInstance() {
  if (m_instance == 0) {
    m_instance = new RpcClient();
  }

  return m_instance;
}

/*! \fn void RpcClient::createCoapPayload()
    \brief Creates data structure to be sent to Coap Client and executes coap
   client's executeClient function, generates random token using Mersenne
   Twister pseudo-random generator and uniform discrete distribution
*/
void RpcClient::createCoapPayload(string rpc_payload) {
  // creates structure to run coap
  // Generating TOKEN
  std::mt19937 rng; // A Mersenne Twister pseudo-random generator
  rng.seed(std::random_device()()); // random seed used
  std::uniform_int_distribution<std::mt19937::result_type> dist16(
      1, 65536); // uniform discrete distribution in range [1, 65536] 16 bit
                 // integer
  int randomToken = dist16(rng);
  CoapClient *coap_client = new CoapClient();
  ClientParams coap_client_payload;
  coap_client_payload.addr = this->m_address;
  coap_client_payload.port = this->m_port;
  coap_client_payload.methodType = COAP_REQUEST_POST;
  coap_client_payload.interface = COAP_INTERFACE_NAME;
  coap_client_payload.payload = rpc_payload;
  memcpy(coap_client_payload.tokenData, (char *)&randomToken, 8);
  coap_client->executeClient(coap_client_payload);
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
