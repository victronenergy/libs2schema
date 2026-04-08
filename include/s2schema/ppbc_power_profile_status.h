/*
 * ppbc_power_profile_status.h
 * 
 */

#ifndef _ppbc_power_profile_status_H_
#define _ppbc_power_profile_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_profile_status_t ppbc_power_profile_status_t;

#include <s2schema/ppbc_power_sequence_container_status.h>



typedef struct ppbc_power_profile_status_t {
    char *message_type; // string
    char *message_id; // string
    list_t *sequence_container_status; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_profile_status_t;

__attribute__((deprecated)) ppbc_power_profile_status_t *ppbc_power_profile_status_create(
    char *message_type,
    char *message_id,
    list_t *sequence_container_status
);

void ppbc_power_profile_status_free(ppbc_power_profile_status_t *ppbc_power_profile_status);

ppbc_power_profile_status_t *ppbc_power_profile_status_parseFromJSON(cJSON *ppbc_power_profile_statusJSON);

cJSON *ppbc_power_profile_status_convertToJSON(ppbc_power_profile_status_t *ppbc_power_profile_status);

#endif /* _ppbc_power_profile_status_H_ */

