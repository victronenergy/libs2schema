/*
 * power_range.h
 * 
 */

#ifndef _power_range_H_
#define _power_range_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct power_range_t power_range_t;

#include <s2schema/commodity_quantity.h>



typedef struct power_range_t {
    double *start_of_range; //numeric
    double *end_of_range; //numeric
    s2_commodity_quantity__e commodity_quantity; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} power_range_t;

__attribute__((deprecated)) power_range_t *power_range_create(
    double *start_of_range,
    double *end_of_range,
    s2_commodity_quantity__e commodity_quantity
);

void power_range_free(power_range_t *power_range);

power_range_t *power_range_parseFromJSON(cJSON *power_rangeJSON);

cJSON *power_range_convertToJSON(power_range_t *power_range);

#endif /* _power_range_H_ */

