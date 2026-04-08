/*
 * revoke_object.h
 * 
 */

#ifndef _revoke_object_H_
#define _revoke_object_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct revoke_object_t revoke_object_t;

#include <s2schema/revokable_objects.h>



typedef struct revoke_object_t {
    char *message_type; // string
    char *message_id; // string
    s2_revokable_objects__e object_type; //referenced enum
    char *object_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_object_t;

__attribute__((deprecated)) revoke_object_t *revoke_object_create(
    char *message_type,
    char *message_id,
    s2_revokable_objects__e object_type,
    char *object_id
);

void revoke_object_free(revoke_object_t *revoke_object);

revoke_object_t *revoke_object_parseFromJSON(cJSON *revoke_objectJSON);

cJSON *revoke_object_convertToJSON(revoke_object_t *revoke_object);

#endif /* _revoke_object_H_ */

