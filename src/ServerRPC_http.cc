#include <string.h>
#include <stdlib.h>
#include <string>
#include<iostream>

#include "ServerRPC.hh"
#include "http_def.h"
#include "server_cfg.h"
#include "handle_pbrpc.hh"

using ::std::string;

namespace pbrpc {

void sendResponseCORS(struct mg_connection *conn, const string &response) {
    std::cout<<"from send ResposneCORS"<<std::endl;
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            HEADER_Access_Control_Allow_Origin ": *\r\n"
            HEADER_Content_Type ": " CONTENT_APPLICATION_PROTOBUF "\r\n"
            HEADER_Content_Length ": %d\r\n",
            (int)response.length()
    );

    mg_write(conn, response.c_str(), (int) response.length());
}

void sendResponsePROTO(struct mg_connection *conn, const string &response) {
    std::cout<<"from send ResposnePROTO"<<std::endl;
    sendResponseCORS(conn, response);
}

void sendResponseOPTIONS(struct mg_connection *conn) {
    std::cout<<"from send ResposneOPTIONS"<<std::endl;
    mg_printf(conn,
            "HTTP/1.1 200 OK\r\n"
            HEADER_Access_Control_Allow_Origin ": *\r\n"
            HEADER_Access_Control_Allow_Methods ": " HTTP_POST ", " HTTP_OPTIONS "\r\n"
            HEADER_Access_Control_Allow_Headers ": %s\r\n"
            HEADER_Content_Length ": %d\r\n",

            mg_get_header(conn, HEADER_Access_Control_Request_Headers),
            0
    );
}

int handleRPC(struct mg_connection *conn) {
    std::cout<<"from send handleRPC"<<std::endl;
    mg_request_info *request_info = mg_get_request_info(conn);

    // only process "POST" request
    if (IS_METHOD_POST(request_info->request_method)) {
        std::cout<<"method post"<<std::endl;
        // check the content type
        const char *contentType = mg_get_header(conn, HEADER_Content_Type);
        if (IS_CONTENT_TYPE_PROTOBUF(contentType)) {
            std::cout<<"content type is protobuf"<<std::endl;
            const char* size_header = mg_get_header(conn, HEADER_Content_Length);
            int len = 0;
            sscanf(size_header, "%d", &len);

            char *buff = (char*) malloc(sizeof(char) * (len + 1));
            mg_read(conn, buff, len);
            sendResponsePROTO(conn, handle_pbrpc(buff, len));
            free(buff);
        } else {
            std::cout<<"content type not protobuf"<<std::endl;
            // empty or unknown content type, ignore
        }
    } else if (IS_METHOD_OPTIONS(request_info->request_method)) {
        std::cout<<"from method options"<<std::endl;
        // received HTTP OPTIONS
        sendResponseOPTIONS(conn);
    } else {
         std::cout<<"not using post options"<<std::endl;
        // received HTTP OPTIONS
        // should be other POST messages
        sendResponsePROTO(conn, "The RPC request is not using POST.");
    }

    return 0;   // Mark as processed
}

int handleHTTP(struct mg_connection *conn) {
    std::cout<<"from send handleHTTP"<<std::endl;
    // the URI starts with /rpc
    if (IS_URI_RPC(mg_get_request_info(conn)->uri)) {
        return handleRPC(conn);
    }
}

ServerRPC::ServerRPC() {
    std::cout<<"from send serverRPC constructor"<<std::endl;
    init();
}

ServerRPC::~ServerRPC() {
    std::cout<<"from send destructor"<<std::endl;
}

int ServerRPC::start(void) {
    std::cout<<"from send start ServerRPC"<<std::endl;
    if (running) {
        return 0;
    }

    struct mg_callbacks callbacks;
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = handleHTTP;

    char port[6];
    char threads[6];
    snprintf(port,    sizeof(port),    "%d", this->port);
    snprintf(threads, sizeof(threads), "%d", this->threads);

    const char *options[] = {"listening_ports", port, "num_threads", threads, "document_root", DOC_ROOT, NULL};

    ctx = this->ctx = mg_start(&callbacks, this, options);

    if (nullptr == ctx) {
        // failed to create the server
        return 1;
    }

    running = true;

    return 0;
}

void ServerRPC::init(void) {
    std::cout<<"from send ServerRPC init"<<std::endl;
    running = false;
    // init the PBRPC system
    init_pbrpc();
}


bool ServerRPC::stop(void) {
    std::cout<<"from send ServerRPC stop"<<std::endl;
    if (running) {
        mg_stop(ctx);
        running = false;
        ctx = nullptr;
    }

    return !running;
}

}
