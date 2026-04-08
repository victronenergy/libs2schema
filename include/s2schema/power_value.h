/*
 * power_value.h
 * 
 */

#ifndef _power_value_H_
#define _power_value_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_value_t power_value_t;

#include <s2schema/commodity_quantity.h>



typedef struct power_value_t {
    s2_commodity_quantity__e commodity_quantity; //referenced enum
    double *value; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} power_value_t;

__attribute__((deprecated)) power_value_t *power_value_create(
    s2_commodity_quantity__e commodity_quantity,
    double *value
);

void power_value_free(power_value_t *power_value);

power_value_t *power_value_parseFromJSON(cJSON *power_valueJSON);

cJSON *power_value_convertToJSON(power_value_t *power_value);

#endif /* _power_value_H_ */

