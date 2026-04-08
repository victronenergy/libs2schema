/*
 * ppbc_power_sequence_container_status.h
 * 
 */

#ifndef _ppbc_power_sequence_container_status_H_
#define _ppbc_power_sequence_container_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_sequence_container_status_t ppbc_power_sequence_container_status_t;

#include <s2schema/ppbc_power_sequence_status.h>



typedef struct ppbc_power_sequence_container_status_t {
    char *power_profile_id; // string
    char *sequence_container_id; // string
    char *selected_sequence_id; // string
    int *progress; //numeric
    s2_ppbc_power_sequence_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_sequence_container_status_t;

__attribute__((deprecated)) ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_create(
    char *power_profile_id,
    char *sequence_container_id,
    char *selected_sequence_id,
    int *progress,
    s2_ppbc_power_sequence_status__e status
);

void ppbc_power_sequence_container_status_free(ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status);

ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_parseFromJSON(cJSON *ppbc_power_sequence_container_statusJSON);

cJSON *ppbc_power_sequence_container_status_convertToJSON(ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status);

#endif /* _ppbc_power_sequence_container_status_H_ */

