/*
 * ombc_timer_status.h
 * 
 */

#ifndef _ombc_timer_status_H_
#define _ombc_timer_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ombc_timer_status_t ombc_timer_status_t;




typedef struct ombc_timer_status_t {
    char *message_type; // string
    char *message_id; // string
    char *timer_id; // string
    char *finished_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} ombc_timer_status_t;

__attribute__((deprecated)) ombc_timer_status_t *ombc_timer_status_create(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *finished_at
);

void ombc_timer_status_free(ombc_timer_status_t *ombc_timer_status);

ombc_timer_status_t *ombc_timer_status_parseFromJSON(cJSON *ombc_timer_statusJSON);

cJSON *ombc_timer_status_convertToJSON(ombc_timer_status_t *ombc_timer_status);

#endif /* _ombc_timer_status_H_ */

