/*
 * frbc_usage_forecast_element.h
 * 
 */

#ifndef _frbc_usage_forecast_element_H_
#define _frbc_usage_forecast_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_usage_forecast_element_t frbc_usage_forecast_element_t;




typedef struct frbc_usage_forecast_element_t {
    int *duration; //numeric
    double *usage_rate_upper_limit; //numeric
    double *usage_rate_upper_95_ppr; //numeric
    double *usage_rate_upper_68_ppr; //numeric
    double *usage_rate_expected; //numeric
    double *usage_rate_lower_68_ppr; //numeric
    double *usage_rate_lower_95_ppr; //numeric
    double *usage_rate_lower_limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_usage_forecast_element_t;

__attribute__((deprecated)) frbc_usage_forecast_element_t *frbc_usage_forecast_element_create(
    int *duration,
    double *usage_rate_upper_limit,
    double *usage_rate_upper_95_ppr,
    double *usage_rate_upper_68_ppr,
    double *usage_rate_expected,
    double *usage_rate_lower_68_ppr,
    double *usage_rate_lower_95_ppr,
    double *usage_rate_lower_limit
);

void frbc_usage_forecast_element_free(frbc_usage_forecast_element_t *frbc_usage_forecast_element);

frbc_usage_forecast_element_t *frbc_usage_forecast_element_parseFromJSON(cJSON *frbc_usage_forecast_elementJSON);

cJSON *frbc_usage_forecast_element_convertToJSON(frbc_usage_forecast_element_t *frbc_usage_forecast_element);

#endif /* _frbc_usage_forecast_element_H_ */

