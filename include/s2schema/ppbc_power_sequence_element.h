/*
 * ppbc_power_sequence_element.h
 * 
 */

#ifndef _ppbc_power_sequence_element_H_
#define _ppbc_power_sequence_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_sequence_element_t ppbc_power_sequence_element_t;

#include <s2schema/power_forecast_value.h>



typedef struct ppbc_power_sequence_element_t {
    int *duration; //numeric
    list_t *power_values; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_sequence_element_t;

__attribute__((deprecated)) ppbc_power_sequence_element_t *ppbc_power_sequence_element_create(
    int *duration,
    list_t *power_values
);

void ppbc_power_sequence_element_free(ppbc_power_sequence_element_t *ppbc_power_sequence_element);

ppbc_power_sequence_element_t *ppbc_power_sequence_element_parseFromJSON(cJSON *ppbc_power_sequence_elementJSON);

cJSON *ppbc_power_sequence_element_convertToJSON(ppbc_power_sequence_element_t *ppbc_power_sequence_element);

#endif /* _ppbc_power_sequence_element_H_ */

