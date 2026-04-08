/*
 * ddbc_average_demand_rate_forecast.h
 * 
 */

#ifndef _ddbc_average_demand_rate_forecast_H_
#define _ddbc_average_demand_rate_forecast_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_average_demand_rate_forecast_t ddbc_average_demand_rate_forecast_t;

#include <s2schema/ddbc_average_demand_rate_forecast_element.h>



typedef struct ddbc_average_demand_rate_forecast_t {
    char *message_type; // string
    char *message_id; // string
    char *start_time; //date time
    list_t *elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_average_demand_rate_forecast_t;

__attribute__((deprecated)) ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
);

void ddbc_average_demand_rate_forecast_free(ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast);

ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_parseFromJSON(cJSON *ddbc_average_demand_rate_forecastJSON);

cJSON *ddbc_average_demand_rate_forecast_convertToJSON(ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast);

#endif /* _ddbc_average_demand_rate_forecast_H_ */

