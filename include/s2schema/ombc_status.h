/*
 * ombc_status.h
 * 
 */

#ifndef _ombc_status_H_
#define _ombc_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ombc_status_t ombc_status_t;




typedef struct ombc_status_t {
    char *message_type; // string
    char *message_id; // string
    char *active_operation_mode_id; // string
    double *operation_mode_factor; //numeric
    char *previous_operation_mode_id; // string
    char *transition_timestamp; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ombc_status_t;

__attribute__((deprecated)) ombc_status_t *ombc_status_create(
    char *message_type,
    char *message_id,
    char *active_operation_mode_id,
    double *operation_mode_factor,
    char *previous_operation_mode_id,
    char *transition_timestamp
);

void ombc_status_free(ombc_status_t *ombc_status);

ombc_status_t *ombc_status_parseFromJSON(cJSON *ombc_statusJSON);

cJSON *ombc_status_convertToJSON(ombc_status_t *ombc_status);

#endif /* _ombc_status_H_ */

