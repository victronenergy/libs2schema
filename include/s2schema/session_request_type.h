/*
 * session_request_type.h
 * RECONNECT: Please reconnect the WebSocket session. Once reconnected, it starts from scratch with a handshake. TERMINATE: Disconnect the session (client can try to reconnecting with exponential backoff)
 */

#ifndef _session_request_type_H_
#define _session_request_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct session_request_type_t session_request_type_t;


// Enum  for session_request_type

typedef enum { s2_session_request_type__NULL = 0, s2_session_request_type__RECONNECT, s2_session_request_type__TERMINATE } s2_session_request_type__e;

char* session_request_type_session_request_type_ToString(s2_session_request_type__e session_request_type);

s2_session_request_type__e session_request_type_session_request_type_FromString(char* session_request_type);

cJSON *session_request_type_convertToJSON(s2_session_request_type__e session_request_type);

s2_session_request_type__e session_request_type_parseFromJSON(cJSON *session_request_typeJSON);

#endif /* _session_request_type_H_ */

