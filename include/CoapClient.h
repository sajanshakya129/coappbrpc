/* CoapClient.h -- Client Handling for CoAP protocol
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file CoapClient.h
 * @brief Client Handling for CoAP protocol
 */
#ifndef __CoapClient_H_INCLUDED_
#define __CoapClient_H_INCLUDED_
#include <coap2/coap.h>
#include <string>

#include "CoapCommon.h"
using namespace std;
/**! \struct ClientParams
 *  \brief A structure that defines parameters to be passed to CoapServer
 *
 */
typedef struct {
  string addr;      /*!< IP address either IPv4 or global IPv6 */
  string port;      /*!< Port number, Default is port number 5683 */
  int methodType;   /*!< Method Name defined in proto file*/
  string interface; /*!< Interface is "rpc" defined as COAP_INTERFACE_NAME in
                       CoapCommon.h file*/
  string payload;   /*!< Payload is encoded stringified data to be sent to coap
                       server*/
  unsigned char tokenData[8]; /*token  is upto 8 byte random integer number*/
} ClientParams;

namespace coappbrpc {

/*! \class CoapClient
 * \brief
 *This class contains two methods to clientHandler and executeClient
 *client Handler is a callback function which returns response back to RPC
 *client excuteClient handles coap client request. It creates a coap context,
 *uses UDP as transport controller, registers, adds options  and creates PDU and
 *sends to server.
 */
class CoapClient {
public:
  string payload; /*!< string to hold value of payload */
  static void clientHandler(struct coap_context_t *, coap_session_t *,
                            coap_pdu_t *, coap_pdu_t *, const coap_tid_t);
  int executeClient(ClientParams);
};
} // namespace coappbrpc
#endif //__CoapClient_H_INCLUDED_