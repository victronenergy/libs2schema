/*
 * frbc_usage_forecast.h
 * 
 */

#ifndef _frbc_usage_forecast_H_
#define _frbc_usage_forecast_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_usage_forecast_t frbc_usage_forecast_t;

#include <s2schema/frbc_usage_forecast_element.h>



typedef struct frbc_usage_forecast_t {
    char *message_type; // string
    char *message_id; // string
    char *start_time; //date time
    list_t *elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_usage_forecast_t;

__attribute__((deprecated)) frbc_usage_forecast_t *frbc_usage_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
);

void frbc_usage_forecast_free(frbc_usage_forecast_t *frbc_usage_forecast);

frbc_usage_forecast_t *frbc_usage_forecast_parseFromJSON(cJSON *frbc_usage_forecastJSON);

cJSON *frbc_usage_forecast_convertToJSON(frbc_usage_forecast_t *frbc_usage_forecast);

#endif /* _frbc_usage_forecast_H_ */

