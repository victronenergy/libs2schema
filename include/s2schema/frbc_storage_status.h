/*
 * frbc_storage_status.h
 * 
 */

#ifndef _frbc_storage_status_H_
#define _frbc_storage_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_storage_status_t frbc_storage_status_t;




typedef struct frbc_storage_status_t {
    char *message_type; // string
    char *message_id; // string
    double *present_fill_level; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_storage_status_t;

__attribute__((deprecated)) frbc_storage_status_t *frbc_storage_status_create(
    char *message_type,
    char *message_id,
    double *present_fill_level
);

void frbc_storage_status_free(frbc_storage_status_t *frbc_storage_status);

frbc_storage_status_t *frbc_storage_status_parseFromJSON(cJSON *frbc_storage_statusJSON);

cJSON *frbc_storage_status_convertToJSON(frbc_storage_status_t *frbc_storage_status);

#endif /* _frbc_storage_status_H_ */

