/*
 * frbc_leakage_behaviour_element.h
 * 
 */

#ifndef _frbc_leakage_behaviour_element_H_
#define _frbc_leakage_behaviour_element_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_leakage_behaviour_element_t frbc_leakage_behaviour_element_t;

#include <s2schema/number_range.h>



typedef struct frbc_leakage_behaviour_element_t {
    struct number_range_t *fill_level_range; //model
    double *leakage_rate; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_leakage_behaviour_element_t;

__attribute__((deprecated)) frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_create(
    number_range_t *fill_level_range,
    double *leakage_rate
);

void frbc_leakage_behaviour_element_free(frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element);

frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_parseFromJSON(cJSON *frbc_leakage_behaviour_elementJSON);

cJSON *frbc_leakage_behaviour_element_convertToJSON(frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element);

#endif /* _frbc_leakage_behaviour_element_H_ */

