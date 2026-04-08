/*
 * power_forecast_element.h
 * 
 */

#ifndef _power_forecast_element_H_
#define _power_forecast_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_forecast_element_t power_forecast_element_t;

#include <s2schema/power_forecast_value.h>



typedef struct power_forecast_element_t {
    int *duration; //numeric
    list_t *power_values; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} power_forecast_element_t;

__attribute__((deprecated)) power_forecast_element_t *power_forecast_element_create(
    int *duration,
    list_t *power_values
);

void power_forecast_element_free(power_forecast_element_t *power_forecast_element);

power_forecast_element_t *power_forecast_element_parseFromJSON(cJSON *power_forecast_elementJSON);

cJSON *power_forecast_element_convertToJSON(power_forecast_element_t *power_forecast_element);

#endif /* _power_forecast_element_H_ */

