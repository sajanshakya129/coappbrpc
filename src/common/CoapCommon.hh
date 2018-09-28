#include <coap/coap.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

class CoapCommon {
public:
  static int resolve_address(const char *, const char *, coap_address_t *);
};
