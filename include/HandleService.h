/* HandleService.h -- Handles RPC service and registry of services
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file HandleService.h
 * @brief Handles RPC service and registry of services
 **/
#ifndef __HandleService_H_INCLUDED
#define __HandleService_H_INCLUDED

#include "ServiceManager.h"
#include <google/protobuf/service.h>
#include <string>

namespace coappbrpc {

using ::google::protobuf::Service;
using ::std::string;

//void initService(void);
string handleService(const char *, const size_t );
void handleRegService(Service *);

} // namespace coappbrpc

#endif
