/*
 * transition.h
 * 
 */

#ifndef _transition_H_
#define _transition_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct transition_t transition_t;




typedef struct transition_t {
    char *id; // string
    char *from; // string
    char *to; // string
    list_t *start_timers; //primitive container
    list_t *blocking_timers; //primitive container
    double *transition_costs; //numeric
    int *transition_duration; //numeric
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} transition_t;

__attribute__((deprecated)) transition_t *transition_create(
    char *id,
    char *from,
    char *to,
    list_t *start_timers,
    list_t *blocking_timers,
    double *transition_costs,
    int *transition_duration,
    int *abnormal_condition_only
);

void transition_free(transition_t *transition);

transition_t *transition_parseFromJSON(cJSON *transitionJSON);

cJSON *transition_convertToJSON(transition_t *transition);

#endif /* _transition_H_ */

