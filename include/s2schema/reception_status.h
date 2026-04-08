/*
 * reception_status.h
 * 
 */

#ifndef _reception_status_H_
#define _reception_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct reception_status_t reception_status_t;

#include <s2schema/reception_status_values.h>



typedef struct reception_status_t {
    char *message_type; // string
    char *subject_message_id; // string
    s2_reception_status_values__e status; //referenced enum
    char *diagnostic_label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reception_status_t;

__attribute__((deprecated)) reception_status_t *reception_status_create(
    char *message_type,
    char *subject_message_id,
    s2_reception_status_values__e status,
    char *diagnostic_label
);

void reception_status_free(reception_status_t *reception_status);

reception_status_t *reception_status_parseFromJSON(cJSON *reception_statusJSON);

cJSON *reception_status_convertToJSON(reception_status_t *reception_status);

#endif /* _reception_status_H_ */

