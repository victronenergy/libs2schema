/*
 * number_range.h
 * 
 */

#ifndef _number_range_H_
#define _number_range_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct number_range_t number_range_t;




typedef struct number_range_t {
    double *start_of_range; //numeric
    double *end_of_range; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} number_range_t;

__attribute__((deprecated)) number_range_t *number_range_create(
    double *start_of_range,
    double *end_of_range
);

void number_range_free(number_range_t *number_range);

number_range_t *number_range_parseFromJSON(cJSON *number_rangeJSON);

cJSON *number_range_convertToJSON(number_range_t *number_range);

#endif /* _number_range_H_ */

