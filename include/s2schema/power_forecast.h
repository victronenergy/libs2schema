/*
 * power_forecast.h
 * 
 */

#ifndef _power_forecast_H_
#define _power_forecast_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_forecast_t power_forecast_t;

#include <s2schema/power_forecast_element.h>



typedef struct power_forecast_t {
    char *message_type; // string
    char *message_id; // string
    char *start_time; //date time
    list_t *elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} power_forecast_t;

__attribute__((deprecated)) power_forecast_t *power_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
);

void power_forecast_free(power_forecast_t *power_forecast);

power_forecast_t *power_forecast_parseFromJSON(cJSON *power_forecastJSON);

cJSON *power_forecast_convertToJSON(power_forecast_t *power_forecast);

#endif /* _power_forecast_H_ */

