/*
 * ppbc_power_sequence_container.h
 * 
 */

#ifndef _ppbc_power_sequence_container_H_
#define _ppbc_power_sequence_container_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_sequence_container_t ppbc_power_sequence_container_t;

#include <s2schema/ppbc_power_sequence.h>



typedef struct ppbc_power_sequence_container_t {
    char *id; // string
    list_t *power_sequences; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_sequence_container_t;

__attribute__((deprecated)) ppbc_power_sequence_container_t *ppbc_power_sequence_container_create(
    char *id,
    list_t *power_sequences
);

void ppbc_power_sequence_container_free(ppbc_power_sequence_container_t *ppbc_power_sequence_container);

ppbc_power_sequence_container_t *ppbc_power_sequence_container_parseFromJSON(cJSON *ppbc_power_sequence_containerJSON);

cJSON *ppbc_power_sequence_container_convertToJSON(ppbc_power_sequence_container_t *ppbc_power_sequence_container);

#endif /* _ppbc_power_sequence_container_H_ */

