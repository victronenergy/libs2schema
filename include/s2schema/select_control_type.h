/*
 * select_control_type.h
 * 
 */

#ifndef _select_control_type_H_
#define _select_control_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct select_control_type_t select_control_type_t;

#include <s2schema/control_type.h>



typedef struct select_control_type_t {
    char *message_type; // string
    char *message_id; // string
    s2_control_type__e control_type; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} select_control_type_t;

__attribute__((deprecated)) select_control_type_t *select_control_type_create(
    char *message_type,
    char *message_id,
    s2_control_type__e control_type
);

void select_control_type_free(select_control_type_t *select_control_type);

select_control_type_t *select_control_type_parseFromJSON(cJSON *select_control_typeJSON);

cJSON *select_control_type_convertToJSON(select_control_type_t *select_control_type);

#endif /* _select_control_type_H_ */

