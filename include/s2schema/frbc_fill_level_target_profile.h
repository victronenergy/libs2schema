/*
 * frbc_fill_level_target_profile.h
 * 
 */

#ifndef _frbc_fill_level_target_profile_H_
#define _frbc_fill_level_target_profile_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_fill_level_target_profile_t frbc_fill_level_target_profile_t;

#include <s2schema/frbc_fill_level_target_profile_element.h>



typedef struct frbc_fill_level_target_profile_t {
    char *message_type; // string
    char *message_id; // string
    char *start_time; //date time
    list_t *elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_fill_level_target_profile_t;

__attribute__((deprecated)) frbc_fill_level_target_profile_t *frbc_fill_level_target_profile_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
);

void frbc_fill_level_target_profile_free(frbc_fill_level_target_profile_t *frbc_fill_level_target_profile);

frbc_fill_level_target_profile_t *frbc_fill_level_target_profile_parseFromJSON(cJSON *frbc_fill_level_target_profileJSON);

cJSON *frbc_fill_level_target_profile_convertToJSON(frbc_fill_level_target_profile_t *frbc_fill_level_target_profile);

#endif /* _frbc_fill_level_target_profile_H_ */

