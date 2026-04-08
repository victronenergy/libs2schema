/*
 * ppbc_schedule_instruction.h
 * 
 */

#ifndef _ppbc_schedule_instruction_H_
#define _ppbc_schedule_instruction_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_schedule_instruction_t ppbc_schedule_instruction_t;




typedef struct ppbc_schedule_instruction_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *power_profile_id; // string
    char *sequence_container_id; // string
    char *power_sequence_id; // string
    char *execution_time; //date time
    int *abnormal_condition; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ppbc_schedule_instruction_t;

__attribute__((deprecated)) ppbc_schedule_instruction_t *ppbc_schedule_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *power_profile_id,
    char *sequence_container_id,
    char *power_sequence_id,
    char *execution_time,
    int *abnormal_condition
);

void ppbc_schedule_instruction_free(ppbc_schedule_instruction_t *ppbc_schedule_instruction);

ppbc_schedule_instruction_t *ppbc_schedule_instruction_parseFromJSON(cJSON *ppbc_schedule_instructionJSON);

cJSON *ppbc_schedule_instruction_convertToJSON(ppbc_schedule_instruction_t *ppbc_schedule_instruction);

#endif /* _ppbc_schedule_instruction_H_ */

