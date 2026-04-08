/*
 * timer_type.h
 * 
 */

#ifndef _timer_type_H_
#define _timer_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct timer_type_t timer_type_t;




typedef struct timer_type_t {
    char *id; // string
    char *diagnostic_label; // string
    int *duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} timer_type_t;

__attribute__((deprecated)) timer_type_t *timer_type_create(
    char *id,
    char *diagnostic_label,
    int *duration
);

void timer_type_free(timer_type_t *timer_type);

timer_type_t *timer_type_parseFromJSON(cJSON *timer_typeJSON);

cJSON *timer_type_convertToJSON(timer_type_t *timer_type);

#endif /* _timer_type_H_ */

