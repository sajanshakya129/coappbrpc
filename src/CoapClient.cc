/* CoapClient.cc -- Client Handling for CoAP protocol
 *
 * Copyright (C) 2018 Sajan SHAKYA <sajanshakya129@gmail.com>
 *
 * This file is part of the CoAPPBRPC library. Please see
 * README for terms of use.
 */

/**
 * @file CoapClient.cc
 * @brief Client Handling for CoAP protocol
 */
#include "CoapClient.h"
#include "RpcClient.h"

using ::coappbrpc::RpcClient;

namespace coappbrpc {

static unsigned char _token_data[8];
coap_string_t the_token = {0, _token_data};

/*! \fn void CoapClient::clientHandler(struct coap_context_t *ctx,
                                coap_session_t *session, coap_pdu_t *sent,
                                coap_pdu_t *received, const coap_tid_t id)
    \brief Callback function that sets response data to be sent back to RPC
   client
   \param ctx Coap context variable reference of type struct
   coap_context_t.
   \param session Coap Session variable reference of type
   coap_session_t
   \param sent CoAP PDU sent to the server
   \param received CoAP PDU received back from server
   \param id CoAP transaction Id of type const  coap_tid_t
*/
static inline int check_token(coap_pdu_t *received) {
  return received->token_length == the_token.length &&
         memcmp(received->token, the_token.s, the_token.length) == 0;
}

void CoapClient::clientHandler(struct coap_context_t *ctx,
                               coap_session_t *session, coap_pdu_t *sent,
                               coap_pdu_t *received, const coap_tid_t id) {
  unsigned char *data;
  size_t data_len;
  if (!check_token(received)) {
    /* drop if this was just some message, or send RST in case of notification
     */
    if (!sent && (received->type == COAP_MESSAGE_CON ||
                  received->type == COAP_MESSAGE_NON))
      coap_send_rst(session, received);
    return;
  }

  if (received->type == COAP_MESSAGE_RST) {
    info("got RST\n");
    return;
  }
  std::string strData(reinterpret_cast<char *>(data));
  RpcClient *client_ret = RpcClient::getInstance();

  if (COAP_RESPONSE_CLASS(received->code) == 2) {
    if (coap_get_data(received, &data_len, &data)) {
      client_ret->setResponse(strData);
    }
  } else if (COAP_RESPONSE_CLASS(received->code) == 4) {
    coap_log(LOG_CRIT, "Client side error: check parameters");

  } else if (COAP_RESPONSE_CLASS(received->code) == 3) {
    coap_log(LOG_CRIT, "Server Error");
  }
}

/*! \fn int CoapClient::executeClient(ClientParams params)
    \brief Handles coap client request, creates context, PDUs, uses UDP
   transport protocol, registers and adds coap option and sends request to coap
   server
   \param params Parameters of struct type ClientParams that comprises of all
   values required to sent to server
*/

int CoapClient::executeClient(ClientParams params) {
  CoapCommon *common = new CoapCommon();
  coap_context_t *ctx = nullptr;
  coap_session_t *session = nullptr;
  coap_address_t dst;
  coap_pdu_t *pdu = nullptr;
  int result = EXIT_FAILURE;

  the_token.length = min(sizeof(_token_data), strlen((char *)params.tokenData));
  if (the_token.length > 0) {
    memcpy((char *)the_token.s, params.tokenData, the_token.length);
  }

  const char *payload_data =
      params.payload.c_str(); // converting binary encoded data to const char*
  size_t data_length = strlen(payload_data); // length of payload_data

  coap_startup();
  /* resolve destination address where server should be sent */
  if (common->resolveAddress(params.addr.c_str(), params.port.c_str(), &dst) <
      0) {
    coap_log(LOG_CRIT, "failed to resolve address\n");
    goto finish;
  }

  /* create CoAP context and a client session */
  ctx = coap_new_context(nullptr);

  if (!ctx || !(session = coap_new_client_session(ctx, nullptr, &dst,
                                                  COAP_PROTO_UDP))) {
    coap_log(LOG_EMERG, "cannot create client session\n");
    goto finish;
  }

  coap_register_response_handler(ctx, clientHandler);

  /* construct PDU for COAP message */
  pdu = coap_new_pdu(session);
  pdu->type = COAP_MESSAGE_CON;
  pdu->tid = coap_new_message_id(session);
  pdu->code = params.methodType;

  if (!pdu) {
    coap_log(LOG_EMERG, "cannot create PDU\n");
    goto finish;
  }
  /* Adding Token */

  if (!coap_add_token(pdu, the_token.length, the_token.s)) {
    coap_log(LOG_DEBUG, "cannot add token to request\n");
  }

  /* add a Uri-Path option */
  coap_add_option(pdu, COAP_OPTION_URI_PATH,
                  (unsigned)strlen(params.interface.c_str()),
                  reinterpret_cast<const uint8_t *>(params.interface.c_str()));

  coap_add_data(pdu, data_length,
                reinterpret_cast<const uint8_t *>(payload_data));

  /* and send the PDU */
  coap_send(session, pdu);

  coap_run_once(ctx, 0);
  result = EXIT_SUCCESS;

finish:

  coap_session_release(session);
  coap_free_context(ctx);
  coap_cleanup();
  delete common;

  return result;
}
} // namespace coappbrpc