/*
 * pebc_power_envelope_element.h
 * 
 */

#ifndef _pebc_power_envelope_element_H_
#define _pebc_power_envelope_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_power_envelope_element_t pebc_power_envelope_element_t;




typedef struct pebc_power_envelope_element_t {
    int *duration; //numeric
    double *upper_limit; //numeric
    double *lower_limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_power_envelope_element_t;

__attribute__((deprecated)) pebc_power_envelope_element_t *pebc_power_envelope_element_create(
    int *duration,
    double *upper_limit,
    double *lower_limit
);

void pebc_power_envelope_element_free(pebc_power_envelope_element_t *pebc_power_envelope_element);

pebc_power_envelope_element_t *pebc_power_envelope_element_parseFromJSON(cJSON *pebc_power_envelope_elementJSON);

cJSON *pebc_power_envelope_element_convertToJSON(pebc_power_envelope_element_t *pebc_power_envelope_element);

#endif /* _pebc_power_envelope_element_H_ */

