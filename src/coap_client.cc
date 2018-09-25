#include "coap_client.hh"
#include "ClientRPC.hh"
#include "coap_common.hh"
#include <coap/coap.h>
#include <iostream>
#include <string>
using namespace std;
using ::pbrpc::ClientRPC;

// cog regeneration of handlers//
void CoapClient::client_handler(struct coap_context_t *ctx,
                                coap_session_t *session, coap_pdu_t *sent,
                                coap_pdu_t *received, const coap_tid_t id) {
  unsigned char *data;
  size_t data_len;
  if (COAP_RESPONSE_CLASS(received->code) == 2) {
    if (coap_get_data(received, &data_len, &data)) {
      ClientRPC clientrpc;
      clientrpc.receiveResponse(data,data_len);

      // cout << "datalength:" << data_len << endl;
      // cout << "Received:" << data_len << data << endl;
    }
  }
}

int CoapClient::runClient(ClientParams params) {
  CoapCommon common;
  coap_context_t *ctx = nullptr;
  coap_session_t *session = nullptr;
  coap_address_t dst;
  coap_pdu_t *pdu = nullptr;
  int result = EXIT_FAILURE;

  const char *payload_data =
      params.payload.c_str(); // converting binary encoded data to const char*
  size_t data_length = strlen(payload_data); // length of payload_data

  coap_startup();
  /* resolve destination address where server should be sent */
  if (common.resolve_address(params.addr.c_str(), params.port.c_str(), &dst) <
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

  coap_register_response_handler(ctx, client_handler);

  /* construct CoAP message */
  pdu = coap_pdu_init(COAP_MESSAGE_CON, params.methodType, 0 /* message id */,
                      coap_session_max_pdu_size(session));
  if (!pdu) {
    coap_log(LOG_EMERG, "cannot create PDU\n");
    goto finish;
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

  return result;
}