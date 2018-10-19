#ifndef __CoapCommon_H_INCLUDED_
#define __CoapCommon_H_INCLUDED_

#include <coap2/coap.h>
#include <cstdio>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

class CoapCommon {
public:
  static int resolveAddress(const char *, const char *, coap_address_t *);
};

#endif