/*
 * handshake.h
 * 
 */

#ifndef _handshake_H_
#define _handshake_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct handshake_t handshake_t;

#include <s2schema/energy_management_role.h>



typedef struct handshake_t {
    char *message_type; // string
    char *message_id; // string
    s2_energy_management_role__e role; //referenced enum
    list_t *supported_protocol_versions; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} handshake_t;

__attribute__((deprecated)) handshake_t *handshake_create(
    char *message_type,
    char *message_id,
    s2_energy_management_role__e role,
    list_t *supported_protocol_versions
);

void handshake_free(handshake_t *handshake);

handshake_t *handshake_parseFromJSON(cJSON *handshakeJSON);

cJSON *handshake_convertToJSON(handshake_t *handshake);

#endif /* _handshake_H_ */

