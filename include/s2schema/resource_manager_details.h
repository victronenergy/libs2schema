/*
 * resource_manager_details.h
 * 
 */

#ifndef _resource_manager_details_H_
#define _resource_manager_details_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct resource_manager_details_t resource_manager_details_t;

#include <s2schema/commodity_quantity.h>
#include <s2schema/control_type.h>
#include <s2schema/currency.h>
#include <s2schema/role.h>

// Enum  for resource_manager_details

// typedef enum  { s2_resource_manager_details__NULL = 0, s2_resource_manager_details__POWERENVELOPEBASEDCONTROL, s2_resource_manager_details__POWERPROFILEBASEDCONTROL, s2_resource_manager_details__OPERATIONMODEBASEDCONTROL, s2_resource_manager_details__FILLRATEBASEDCONTROL, s2_resource_manager_details__DEMANDDRIVENBASEDCONTROL, s2_resource_manager_details__NOTCONTROLABLE, s2_resource_manager_details__NOSELECTION } s2_resource_manager_details__e;

// char* resource_manager_details_available_control_types_ToString(s2_resource_manager_details__e available_control_types);

// s2_resource_manager_details__e resource_manager_details_available_control_types_FromString(char* available_control_types);

// Enum  for resource_manager_details

// typedef enum  { s2_resource_manager_details__NULL = 0, s2_resource_manager_details__ELECTRICPOWERL1, s2_resource_manager_details__ELECTRICPOWERL2, s2_resource_manager_details__ELECTRICPOWERL3, s2_resource_manager_details__ELECTRICPOWER3PHASESYMMETRIC, s2_resource_manager_details__NATURALGASFLOWRATE, s2_resource_manager_details__HYDROGENFLOWRATE, s2_resource_manager_details__HEATTEMPERATURE, s2_resource_manager_details__HEATFLOWRATE, s2_resource_manager_details__HEATTHERMALPOWER, s2_resource_manager_details__OILFLOWRATE } s2_resource_manager_details__e;

// char* resource_manager_details_provides_power_measurement_types_ToString(s2_resource_manager_details__e provides_power_measurement_types);

// s2_resource_manager_details__e resource_manager_details_provides_power_measurement_types_FromString(char* provides_power_measurement_types);



typedef struct resource_manager_details_t {
    char *message_type; // string
    char *message_id; // string
    char *resource_id; // string
    char *name; // string
    list_t *roles; //nonprimitive container
    char *manufacturer; // string
    char *model; // string
    char *serial_number; // string
    char *firmware_version; // string
    int *instruction_processing_delay; //numeric
    list_t *available_control_types; //nonprimitive container
    s2_currency__e currency; //referenced enum
    int *provides_forecast; //boolean
    list_t *provides_power_measurement_types; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} resource_manager_details_t;

__attribute__((deprecated)) resource_manager_details_t *resource_manager_details_create(
    char *message_type,
    char *message_id,
    char *resource_id,
    char *name,
    list_t *roles,
    char *manufacturer,
    char *model,
    char *serial_number,
    char *firmware_version,
    int *instruction_processing_delay,
    list_t *available_control_types,
    s2_currency__e currency,
    int *provides_forecast,
    list_t *provides_power_measurement_types
);

void resource_manager_details_free(resource_manager_details_t *resource_manager_details);

resource_manager_details_t *resource_manager_details_parseFromJSON(cJSON *resource_manager_detailsJSON);

cJSON *resource_manager_details_convertToJSON(resource_manager_details_t *resource_manager_details);

#endif /* _resource_manager_details_H_ */

