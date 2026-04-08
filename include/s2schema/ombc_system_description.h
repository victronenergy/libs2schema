/*
 * ombc_system_description.h
 * 
 */

#ifndef _ombc_system_description_H_
#define _ombc_system_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ombc_system_description_t ombc_system_description_t;

#include <s2schema/ombc_operation_mode.h>
#include <s2schema/timer_type.h>
#include <s2schema/transition.h>



typedef struct ombc_system_description_t {
    char *message_type; // string
    char *message_id; // string
    char *valid_from; //date time
    list_t *operation_modes; //nonprimitive container
    list_t *transitions; //nonprimitive container
    list_t *timers; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ombc_system_description_t;

__attribute__((deprecated)) ombc_system_description_t *ombc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
);

void ombc_system_description_free(ombc_system_description_t *ombc_system_description);

ombc_system_description_t *ombc_system_description_parseFromJSON(cJSON *ombc_system_descriptionJSON);

cJSON *ombc_system_description_convertToJSON(ombc_system_description_t *ombc_system_description);

#endif /* _ombc_system_description_H_ */

