#include <coap2/coap.h>
#include <iostream>
#include <cstdio>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

class CoapCommon {
public:
  static int resolve_address(const char *, const char *, coap_address_t *);
};
