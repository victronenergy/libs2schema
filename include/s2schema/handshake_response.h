/*
 * handshake_response.h
 * 
 */

#ifndef _handshake_response_H_
#define _handshake_response_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct handshake_response_t handshake_response_t;




typedef struct handshake_response_t {
    char *message_type; // string
    char *message_id; // string
    char *selected_protocol_version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} handshake_response_t;

__attribute__((deprecated)) handshake_response_t *handshake_response_create(
    char *message_type,
    char *message_id,
    char *selected_protocol_version
);

void handshake_response_free(handshake_response_t *handshake_response);

handshake_response_t *handshake_response_parseFromJSON(cJSON *handshake_responseJSON);

cJSON *handshake_response_convertToJSON(handshake_response_t *handshake_response);

#endif /* _handshake_response_H_ */

