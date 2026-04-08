/*
 * ddbc_system_description.h
 * 
 */

#ifndef _ddbc_system_description_H_
#define _ddbc_system_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_system_description_t ddbc_system_description_t;

#include <s2schema/ddbc_actuator_description.h>
#include <s2schema/number_range.h>



typedef struct ddbc_system_description_t {
    char *message_type; // string
    char *message_id; // string
    char *valid_from; //date time
    list_t *actuators; //nonprimitive container
    struct number_range_t *present_demand_rate; //model
    int *provides_average_demand_rate_forecast; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_system_description_t;

__attribute__((deprecated)) ddbc_system_description_t *ddbc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    number_range_t *present_demand_rate,
    int *provides_average_demand_rate_forecast
);

void ddbc_system_description_free(ddbc_system_description_t *ddbc_system_description);

ddbc_system_description_t *ddbc_system_description_parseFromJSON(cJSON *ddbc_system_descriptionJSON);

cJSON *ddbc_system_description_convertToJSON(ddbc_system_description_t *ddbc_system_description);

#endif /* _ddbc_system_description_H_ */

