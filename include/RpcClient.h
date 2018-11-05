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
/*! \class C
* \brief
*This class contains methods to handle RPC, register services, get services, get method details,
*validate passed parameters, validate requests, validate versions, and check if services are already existed or not
*/
class RpcClient {
private:
  static RpcClient *m_instance;
  string m_address;
  string m_port;
  string m_payload;
  string m_response;
  RpcClient();

public:
  static RpcClient *getInstance();
  virtual ~RpcClient();
  void runClient();
  void setResponse(string);
  string getResponse();
  void setServerAddr(string,string);
  Response execFunc(string, string, string, string);
};
} // namespace coappbrpc

#endif //__ClientRPC_H_INCLUDED_
