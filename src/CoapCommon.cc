/* CoapCommon.cc -- Common function to resolve address used by both coap client
 * and coap server
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file CoapCommon.cc
 * @brief Common function to resolve address used by both coap client and coap
 *server
 **/

#include "CoapCommon.h"
/*! \fn int CoapCommon::resolveAddress(const char *host, const char *service,
                               coap_address_t *dst)
    \brief Resolves IPv4 and IPv6 addresses and shows error messages in case of
   error
   \param host IPv4 or IPv6(global) address \param service Port number
   \param dst Reference of a address of type coap_address_t, to store the result
   after resolving address
*/
int CoapCommon::resolveAddress(const char *host, const char *service,
                               coap_address_t *dst) {

  struct addrinfo *res, *ainfo;
  struct addrinfo hints;
  int error, len = -1;

  memset(&hints, 0, sizeof(hints));
  memset(dst, 0, sizeof(*dst));
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_family = AF_UNSPEC;

  error = getaddrinfo(host, service, &hints, &res);

  if (error != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
    return error;
  }

  for (ainfo = res; ainfo != NULL; ainfo = ainfo->ai_next) {
    switch (ainfo->ai_family) {
    case AF_INET6:
    case AF_INET:
      len = dst->size = ainfo->ai_addrlen;
      memcpy(&dst->addr.sin6, ainfo->ai_addr, dst->size);
      goto finish;
    default:;
    }
  }

finish:
  freeaddrinfo(res);
  return len;
}
