/*
 * ppbc_power_sequence.h
 * 
 */

#ifndef _ppbc_power_sequence_H_
#define _ppbc_power_sequence_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_sequence_t ppbc_power_sequence_t;

#include <s2schema/ppbc_power_sequence_element.h>



typedef struct ppbc_power_sequence_t {
    char *id; // string
    list_t *elements; //nonprimitive container
    int *is_interruptible; //boolean
    int *max_pause_before; //numeric
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_power_sequence_t;

__attribute__((deprecated)) ppbc_power_sequence_t *ppbc_power_sequence_create(
    char *id,
    list_t *elements,
    int *is_interruptible,
    int *max_pause_before,
    int *abnormal_condition_only
);

void ppbc_power_sequence_free(ppbc_power_sequence_t *ppbc_power_sequence);

ppbc_power_sequence_t *ppbc_power_sequence_parseFromJSON(cJSON *ppbc_power_sequenceJSON);

cJSON *ppbc_power_sequence_convertToJSON(ppbc_power_sequence_t *ppbc_power_sequence);

#endif /* _ppbc_power_sequence_H_ */

