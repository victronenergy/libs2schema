/*
 * ddbc_average_demand_rate_forecast_element.h
 * 
 */

#ifndef _ddbc_average_demand_rate_forecast_element_H_
#define _ddbc_average_demand_rate_forecast_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_average_demand_rate_forecast_element_t ddbc_average_demand_rate_forecast_element_t;




typedef struct ddbc_average_demand_rate_forecast_element_t {
    int *duration; //numeric
    double *demand_rate_upper_limit; //numeric
    double *demand_rate_upper_95_ppr; //numeric
    double *demand_rate_upper_68_ppr; //numeric
    double *demand_rate_expected; //numeric
    double *demand_rate_lower_68_ppr; //numeric
    double *demand_rate_lower_95_ppr; //numeric
    double *demand_rate_lower_limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_average_demand_rate_forecast_element_t;

__attribute__((deprecated)) ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_create(
    int *duration,
    double *demand_rate_upper_limit,
    double *demand_rate_upper_95_ppr,
    double *demand_rate_upper_68_ppr,
    double *demand_rate_expected,
    double *demand_rate_lower_68_ppr,
    double *demand_rate_lower_95_ppr,
    double *demand_rate_lower_limit
);

void ddbc_average_demand_rate_forecast_element_free(ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element);

ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_parseFromJSON(cJSON *ddbc_average_demand_rate_forecast_elementJSON);

cJSON *ddbc_average_demand_rate_forecast_element_convertToJSON(ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element);

#endif /* _ddbc_average_demand_rate_forecast_element_H_ */

