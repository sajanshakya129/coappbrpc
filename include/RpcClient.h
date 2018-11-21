/* RpcClient.h -- Sets Client parameters to be passed as Coap Parameters and
 * calls for execution of CoAP protocol
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file RpcClient.h
 * @brief Sets Client parameters to be passed as Coap Parameters and calls for
 * execution of CoAP protocol **/
#ifndef __ClientRPC_H_INCLUDED_
#define __ClientRPC_H_INCLUDED_

#include "CoapClient.h"
#include "MsgSchema.pb.h"
#include <iostream>
#include <string>
using namespace std;

namespace coappbrpc {
/*! \class RpcClient
 * \brief
 *This class contains methods to run client, set responses, get responses, setup
 *server addresses and execute function which is called from client stubs.
 */
class RpcClient {
private:
  static RpcClient *m_instance; /*!<static instance pointer of RPC client to store address so that this instance can be manipulated in various levels.*/
  string m_address;/*!<string variable to store IP address */
  string m_port;/*!<string variable to store port address*/
  string m_response;/*!<string varibale to store response sent back by server  */
public:
  static RpcClient *getInstance();
  RpcClient();
  virtual ~RpcClient();
  void createCoapPayload(string);
  void setResponse(string);
  string getResponse();
  void setServerAddr(string, string);
};
} // namespace coappbrpc

#endif //__ClientRPC_H_INCLUDED_
