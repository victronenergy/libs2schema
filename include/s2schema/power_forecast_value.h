/*
 * power_forecast_value.h
 * 
 */

#ifndef _power_forecast_value_H_
#define _power_forecast_value_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_forecast_value_t power_forecast_value_t;

#include <s2schema/commodity_quantity.h>



typedef struct power_forecast_value_t {
    double *value_upper_limit; //numeric
    double *value_upper_95_ppr; //numeric
    double *value_upper_68_ppr; //numeric
    double *value_expected; //numeric
    double *value_lower_68_ppr; //numeric
    double *value_lower_95_ppr; //numeric
    double *value_lower_limit; //numeric
    s2_commodity_quantity__e commodity_quantity; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} power_forecast_value_t;

__attribute__((deprecated)) power_forecast_value_t *power_forecast_value_create(
    double *value_upper_limit,
    double *value_upper_95_ppr,
    double *value_upper_68_ppr,
    double *value_expected,
    double *value_lower_68_ppr,
    double *value_lower_95_ppr,
    double *value_lower_limit,
    s2_commodity_quantity__e commodity_quantity
);

void power_forecast_value_free(power_forecast_value_t *power_forecast_value);

power_forecast_value_t *power_forecast_value_parseFromJSON(cJSON *power_forecast_valueJSON);

cJSON *power_forecast_value_convertToJSON(power_forecast_value_t *power_forecast_value);

#endif /* _power_forecast_value_H_ */

