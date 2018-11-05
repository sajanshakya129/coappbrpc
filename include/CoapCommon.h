/* CoapCommon.h -- Common function to resolve address used by both coap client
 * and coap server
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file CoapCommon.h
 * @brief Common function to resolve address used by both coap client and coap
 *server
 **/
#ifndef __CoapCommon_H_INCLUDED_
#define __CoapCommon_H_INCLUDED_

#include <coap2/coap.h>
#include <cstdio>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
/*! \def COAP_INTERFACE_NAME
    \brief A macro containing name of URI to be used in COAP request
*/
#define COAP_INTERFACE_NAME "rpc"
/* \class CoapCommon
 * \brief
 *This class contains a function named resolveAddress. This file is used and
 *shared by both client and server side to verify ip addresses.
 */
class CoapCommon {
public:
  static int resolveAddress(const char *, const char *, coap_address_t *);
};

#endif