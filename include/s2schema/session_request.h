/*
 * session_request.h
 * 
 */

#ifndef _session_request_H_
#define _session_request_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct session_request_t session_request_t;

#include <s2schema/session_request_type.h>



typedef struct session_request_t {
    char *message_type; // string
    char *message_id; // string
    s2_session_request_type__e request; //referenced enum
    char *diagnostic_label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} session_request_t;

__attribute__((deprecated)) session_request_t *session_request_create(
    char *message_type,
    char *message_id,
    s2_session_request_type__e request,
    char *diagnostic_label
);

void session_request_free(session_request_t *session_request);

session_request_t *session_request_parseFromJSON(cJSON *session_requestJSON);

cJSON *session_request_convertToJSON(session_request_t *session_request);

#endif /* _session_request_H_ */

