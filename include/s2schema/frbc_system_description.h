/*
 * frbc_system_description.h
 * 
 */

#ifndef _frbc_system_description_H_
#define _frbc_system_description_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_system_description_t frbc_system_description_t;

#include <s2schema/frbc_actuator_description.h>
#include <s2schema/frbc_storage_description.h>



typedef struct frbc_system_description_t {
    char *message_type; // string
    char *message_id; // string
    char *valid_from; //date time
    list_t *actuators; //nonprimitive container
    struct frbc_storage_description_t *storage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_system_description_t;

__attribute__((deprecated)) frbc_system_description_t *frbc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    frbc_storage_description_t *storage
);

void frbc_system_description_free(frbc_system_description_t *frbc_system_description);

frbc_system_description_t *frbc_system_description_parseFromJSON(cJSON *frbc_system_descriptionJSON);

cJSON *frbc_system_description_convertToJSON(frbc_system_description_t *frbc_system_description);

#endif /* _frbc_system_description_H_ */

