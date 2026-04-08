/*
 * frbc_storage_description.h
 * 
 */

#ifndef _frbc_storage_description_H_
#define _frbc_storage_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_storage_description_t frbc_storage_description_t;

#include <s2schema/number_range.h>



typedef struct frbc_storage_description_t {
    char *diagnostic_label; // string
    char *fill_level_label; // string
    int *provides_leakage_behaviour; //boolean
    int *provides_fill_level_target_profile; //boolean
    int *provides_usage_forecast; //boolean
    struct number_range_t *fill_level_range; //model

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_storage_description_t;

__attribute__((deprecated)) frbc_storage_description_t *frbc_storage_description_create(
    char *diagnostic_label,
    char *fill_level_label,
    int *provides_leakage_behaviour,
    int *provides_fill_level_target_profile,
    int *provides_usage_forecast,
    number_range_t *fill_level_range
);

void frbc_storage_description_free(frbc_storage_description_t *frbc_storage_description);

frbc_storage_description_t *frbc_storage_description_parseFromJSON(cJSON *frbc_storage_descriptionJSON);

cJSON *frbc_storage_description_convertToJSON(frbc_storage_description_t *frbc_storage_description);

#endif /* _frbc_storage_description_H_ */

