/*
 * frbc_operation_mode_element.h
 * 
 */

#ifndef _frbc_operation_mode_element_H_
#define _frbc_operation_mode_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_operation_mode_element_t frbc_operation_mode_element_t;

#include <s2schema/number_range.h>
#include <s2schema/power_range.h>



typedef struct frbc_operation_mode_element_t {
    struct number_range_t *fill_level_range; //model
    struct number_range_t *fill_rate; //model
    list_t *power_ranges; //nonprimitive container
    struct number_range_t *running_costs; //model

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_operation_mode_element_t;

__attribute__((deprecated)) frbc_operation_mode_element_t *frbc_operation_mode_element_create(
    number_range_t *fill_level_range,
    number_range_t *fill_rate,
    list_t *power_ranges,
    number_range_t *running_costs
);

void frbc_operation_mode_element_free(frbc_operation_mode_element_t *frbc_operation_mode_element);

frbc_operation_mode_element_t *frbc_operation_mode_element_parseFromJSON(cJSON *frbc_operation_mode_elementJSON);

cJSON *frbc_operation_mode_element_convertToJSON(frbc_operation_mode_element_t *frbc_operation_mode_element);

#endif /* _frbc_operation_mode_element_H_ */

