/* HandleService.cc -- Handles RPC service and registry of services
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file HandleService.cc
 * @brief Handles RPC service and registry of services
 **/
#include "HandleService.h"

namespace coappbrpc {
ServiceManager __srv_man;

/*! \fn string handleService(const char *data, const size_t len)
    \brief Uses handleRPC function of ServiceManager instance.
   error 
   \param data Data reference to be sent to Service Manager, of type char 
   \param len length of data of type size_t
*/
string handleService(const char *data, const size_t len) {
  string ret;
  __srv_man.handleRPC(data, len, ret);
  return ret;
}
/*! \fn void handleRegService(Service *service)
    \brief Uses register Service function of ServiceManager instance.
   error 
   \param service Service reference to be sent to Service Manager
*/
void handleRegService(Service *service) { __srv_man.regService(service); }

} // namespace coappbrpc
