/*
 * frbc_operation_mode.h
 * 
 */

#ifndef _frbc_operation_mode_H_
#define _frbc_operation_mode_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_operation_mode_t frbc_operation_mode_t;

#include <s2schema/frbc_operation_mode_element.h>



typedef struct frbc_operation_mode_t {
    char *id; // string
    char *diagnostic_label; // string
    list_t *elements; //nonprimitive container
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_operation_mode_t;

__attribute__((deprecated)) frbc_operation_mode_t *frbc_operation_mode_create(
    char *id,
    char *diagnostic_label,
    list_t *elements,
    int *abnormal_condition_only
);

void frbc_operation_mode_free(frbc_operation_mode_t *frbc_operation_mode);

frbc_operation_mode_t *frbc_operation_mode_parseFromJSON(cJSON *frbc_operation_modeJSON);

cJSON *frbc_operation_mode_convertToJSON(frbc_operation_mode_t *frbc_operation_mode);

#endif /* _frbc_operation_mode_H_ */

