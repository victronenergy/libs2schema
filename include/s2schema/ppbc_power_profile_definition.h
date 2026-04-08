/*
 * ppbc_power_profile_definition.h
 * 
 */

#ifndef _ppbc_power_profile_definition_H_
#define _ppbc_power_profile_definition_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_profile_definition_t ppbc_power_profile_definition_t;

#include <s2schema/ppbc_power_sequence_container.h>



typedef struct ppbc_power_profile_definition_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *start_time; //date time
    char *end_time; //date time
    list_t *power_sequences_containers; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_profile_definition_t;

__attribute__((deprecated)) ppbc_power_profile_definition_t *ppbc_power_profile_definition_create(
    char *message_type,
    char *message_id,
    char *id,
    char *start_time,
    char *end_time,
    list_t *power_sequences_containers
);

void ppbc_power_profile_definition_free(ppbc_power_profile_definition_t *ppbc_power_profile_definition);

ppbc_power_profile_definition_t *ppbc_power_profile_definition_parseFromJSON(cJSON *ppbc_power_profile_definitionJSON);

cJSON *ppbc_power_profile_definition_convertToJSON(ppbc_power_profile_definition_t *ppbc_power_profile_definition);

#endif /* _ppbc_power_profile_definition_H_ */

