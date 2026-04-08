/*
 * ddbc_actuator_description.h
 * 
 */

#ifndef _ddbc_actuator_description_H_
#define _ddbc_actuator_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_actuator_description_t ddbc_actuator_description_t;

#include <s2schema/commodity.h>
#include <s2schema/ddbc_operation_mode.h>
#include <s2schema/timer_type.h>
#include <s2schema/transition.h>

// Enum  for ddbc_actuator_description

// typedef enum  { s2_ddbc_actuator_description__NULL = 0, s2_ddbc_actuator_description__GAS, s2_ddbc_actuator_description__HEAT, s2_ddbc_actuator_description__ELECTRICITY, s2_ddbc_actuator_description__OIL } s2_ddbc_actuator_description__e;

// char* ddbc_actuator_description_supported_commodites_ToString(s2_ddbc_actuator_description__e supported_commodites);

// s2_ddbc_actuator_description__e ddbc_actuator_description_supported_commodites_FromString(char* supported_commodites);



typedef struct ddbc_actuator_description_t {
    char *id; // string
    char *diagnostic_label; // string
    list_t *supported_commodites; //nonprimitive container
    list_t *operation_modes; //nonprimitive container
    list_t *transitions; //nonprimitive container
    list_t *timers; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_actuator_description_t;

__attribute__((deprecated)) ddbc_actuator_description_t *ddbc_actuator_description_create(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodites,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
);

void ddbc_actuator_description_free(ddbc_actuator_description_t *ddbc_actuator_description);

ddbc_actuator_description_t *ddbc_actuator_description_parseFromJSON(cJSON *ddbc_actuator_descriptionJSON);

cJSON *ddbc_actuator_description_convertToJSON(ddbc_actuator_description_t *ddbc_actuator_description);

#endif /* _ddbc_actuator_description_H_ */

