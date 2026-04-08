/*
 * power_measurement.h
 * 
 */

#ifndef _power_measurement_H_
#define _power_measurement_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_measurement_t power_measurement_t;

#include <s2schema/power_value.h>



typedef struct power_measurement_t {
    char *message_type; // string
    char *message_id; // string
    char *measurement_timestamp; //date time
    list_t *values; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} power_measurement_t;

__attribute__((deprecated)) power_measurement_t *power_measurement_create(
    char *message_type,
    char *message_id,
    char *measurement_timestamp,
    list_t *values
);

void power_measurement_free(power_measurement_t *power_measurement);

power_measurement_t *power_measurement_parseFromJSON(cJSON *power_measurementJSON);

cJSON *power_measurement_convertToJSON(power_measurement_t *power_measurement);

#endif /* _power_measurement_H_ */

