/*
 * ddbc_operation_mode.h
 * 
 */

#ifndef _ddbc_operation_mode_H_
#define _ddbc_operation_mode_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_operation_mode_t ddbc_operation_mode_t;

#include <s2schema/number_range.h>
#include <s2schema/power_range.h>



typedef struct ddbc_operation_mode_t {
    char *id; // string
    char *diagnostic_label; // string
    list_t *power_ranges; //nonprimitive container
    struct number_range_t *supply_range; //model
    struct number_range_t *running_costs; //model
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_operation_mode_t;

__attribute__((deprecated)) ddbc_operation_mode_t *ddbc_operation_mode_create(
    char *id,
    char *diagnostic_label,
    list_t *power_ranges,
    number_range_t *supply_range,
    number_range_t *running_costs,
    int *abnormal_condition_only
);

void ddbc_operation_mode_free(ddbc_operation_mode_t *ddbc_operation_mode);

ddbc_operation_mode_t *ddbc_operation_mode_parseFromJSON(cJSON *ddbc_operation_modeJSON);

cJSON *ddbc_operation_mode_convertToJSON(ddbc_operation_mode_t *ddbc_operation_mode);

#endif /* _ddbc_operation_mode_H_ */

