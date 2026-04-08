/*
 * frbc_timer_status.h
 * 
 */

#ifndef _frbc_timer_status_H_
#define _frbc_timer_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_timer_status_t frbc_timer_status_t;




typedef struct frbc_timer_status_t {
    char *message_type; // string
    char *message_id; // string
    char *timer_id; // string
    char *actuator_id; // string
    char *finished_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_timer_status_t;

__attribute__((deprecated)) frbc_timer_status_t *frbc_timer_status_create(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *actuator_id,
    char *finished_at
);

void frbc_timer_status_free(frbc_timer_status_t *frbc_timer_status);

frbc_timer_status_t *frbc_timer_status_parseFromJSON(cJSON *frbc_timer_statusJSON);

cJSON *frbc_timer_status_convertToJSON(frbc_timer_status_t *frbc_timer_status);

#endif /* _frbc_timer_status_H_ */

