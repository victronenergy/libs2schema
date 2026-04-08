/*
 * frbc_leakage_behaviour.h
 * 
 */

#ifndef _frbc_leakage_behaviour_H_
#define _frbc_leakage_behaviour_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_leakage_behaviour_t frbc_leakage_behaviour_t;

#include <s2schema/frbc_leakage_behaviour_element.h>



typedef struct frbc_leakage_behaviour_t {
    char *message_type; // string
    char *message_id; // string
    char *valid_from; //date time
    list_t *elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_leakage_behaviour_t;

__attribute__((deprecated)) frbc_leakage_behaviour_t *frbc_leakage_behaviour_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *elements
);

void frbc_leakage_behaviour_free(frbc_leakage_behaviour_t *frbc_leakage_behaviour);

frbc_leakage_behaviour_t *frbc_leakage_behaviour_parseFromJSON(cJSON *frbc_leakage_behaviourJSON);

cJSON *frbc_leakage_behaviour_convertToJSON(frbc_leakage_behaviour_t *frbc_leakage_behaviour);

#endif /* _frbc_leakage_behaviour_H_ */

