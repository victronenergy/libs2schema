/*
 * ombc_operation_mode.h
 * 
 */

#ifndef _ombc_operation_mode_H_
#define _ombc_operation_mode_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ombc_operation_mode_t ombc_operation_mode_t;

#include <s2schema/number_range.h>
#include <s2schema/power_range.h>



typedef struct ombc_operation_mode_t {
    char *id; // string
    char *diagnostic_label; // string
    list_t *power_ranges; //nonprimitive container
    struct number_range_t *running_costs; //model
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ombc_operation_mode_t;

__attribute__((deprecated)) ombc_operation_mode_t *ombc_operation_mode_create(
    char *id,
    char *diagnostic_label,
    list_t *power_ranges,
    number_range_t *running_costs,
    int *abnormal_condition_only
);

void ombc_operation_mode_free(ombc_operation_mode_t *ombc_operation_mode);

ombc_operation_mode_t *ombc_operation_mode_parseFromJSON(cJSON *ombc_operation_modeJSON);

cJSON *ombc_operation_mode_convertToJSON(ombc_operation_mode_t *ombc_operation_mode);

#endif /* _ombc_operation_mode_H_ */

