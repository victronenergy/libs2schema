/*
 * frbc_actuator_description.h
 * 
 */

#ifndef _frbc_actuator_description_H_
#define _frbc_actuator_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_actuator_description_t frbc_actuator_description_t;

#include <s2schema/commodity.h>
#include <s2schema/frbc_operation_mode.h>
#include <s2schema/timer_type.h>
#include <s2schema/transition.h>

// Enum  for frbc_actuator_description

// typedef enum  { s2_frbc_actuator_description__NULL = 0, s2_frbc_actuator_description__GAS, s2_frbc_actuator_description__HEAT, s2_frbc_actuator_description__ELECTRICITY, s2_frbc_actuator_description__OIL } s2_frbc_actuator_description__e;

// char* frbc_actuator_description_supported_commodities_ToString(s2_frbc_actuator_description__e supported_commodities);

// s2_frbc_actuator_description__e frbc_actuator_description_supported_commodities_FromString(char* supported_commodities);



typedef struct frbc_actuator_description_t {
    char *id; // string
    char *diagnostic_label; // string
    list_t *supported_commodities; //nonprimitive container
    list_t *operation_modes; //nonprimitive container
    list_t *transitions; //nonprimitive container
    list_t *timers; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_actuator_description_t;

__attribute__((deprecated)) frbc_actuator_description_t *frbc_actuator_description_create(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodities,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
);

void frbc_actuator_description_free(frbc_actuator_description_t *frbc_actuator_description);

frbc_actuator_description_t *frbc_actuator_description_parseFromJSON(cJSON *frbc_actuator_descriptionJSON);

cJSON *frbc_actuator_description_convertToJSON(frbc_actuator_description_t *frbc_actuator_description);

#endif /* _frbc_actuator_description_H_ */

