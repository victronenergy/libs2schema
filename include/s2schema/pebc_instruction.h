/*
 * pebc_instruction.h
 * 
 */

#ifndef _pebc_instruction_H_
#define _pebc_instruction_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_instruction_t pebc_instruction_t;

#include <s2schema/pebc_power_envelope.h>



typedef struct pebc_instruction_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *execution_time; //date time
    int *abnormal_condition; //boolean
    char *power_constraints_id; // string
    list_t *power_envelopes; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_instruction_t;

__attribute__((deprecated)) pebc_instruction_t *pebc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *power_constraints_id,
    list_t *power_envelopes
);

void pebc_instruction_free(pebc_instruction_t *pebc_instruction);

pebc_instruction_t *pebc_instruction_parseFromJSON(cJSON *pebc_instructionJSON);

cJSON *pebc_instruction_convertToJSON(pebc_instruction_t *pebc_instruction);

#endif /* _pebc_instruction_H_ */

