/*
 * ddbc_actuator_status.h
 * 
 */

#ifndef _ddbc_actuator_status_H_
#define _ddbc_actuator_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_actuator_status_t ddbc_actuator_status_t;




typedef struct ddbc_actuator_status_t {
    char *message_type; // string
    char *message_id; // string
    char *actuator_id; // string
    char *active_operation_mode_id; // string
    double *operation_mode_factor; //numeric
    char *previous_operation_mode_id; // string
    char *transition_timestamp; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_actuator_status_t;

__attribute__((deprecated)) ddbc_actuator_status_t *ddbc_actuator_status_create(
    char *message_type,
    char *message_id,
    char *actuator_id,
    char *active_operation_mode_id,
    double *operation_mode_factor,
    char *previous_operation_mode_id,
    char *transition_timestamp
);

void ddbc_actuator_status_free(ddbc_actuator_status_t *ddbc_actuator_status);

ddbc_actuator_status_t *ddbc_actuator_status_parseFromJSON(cJSON *ddbc_actuator_statusJSON);

cJSON *ddbc_actuator_status_convertToJSON(ddbc_actuator_status_t *ddbc_actuator_status);

#endif /* _ddbc_actuator_status_H_ */

