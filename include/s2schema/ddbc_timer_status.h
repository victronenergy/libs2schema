/*
 * ddbc_timer_status.h
 * 
 */

#ifndef _ddbc_timer_status_H_
#define _ddbc_timer_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_timer_status_t ddbc_timer_status_t;




typedef struct ddbc_timer_status_t {
    char *message_type; // string
    char *message_id; // string
    char *timer_id; // string
    char *actuator_id; // string
    char *finished_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_timer_status_t;

__attribute__((deprecated)) ddbc_timer_status_t *ddbc_timer_status_create(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *actuator_id,
    char *finished_at
);

void ddbc_timer_status_free(ddbc_timer_status_t *ddbc_timer_status);

ddbc_timer_status_t *ddbc_timer_status_parseFromJSON(cJSON *ddbc_timer_statusJSON);

cJSON *ddbc_timer_status_convertToJSON(ddbc_timer_status_t *ddbc_timer_status);

#endif /* _ddbc_timer_status_H_ */

