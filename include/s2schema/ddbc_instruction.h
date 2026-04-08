/*
 * ddbc_instruction.h
 * 
 */

#ifndef _ddbc_instruction_H_
#define _ddbc_instruction_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ddbc_instruction_t ddbc_instruction_t;




typedef struct ddbc_instruction_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *execution_time; //date time
    int *abnormal_condition; //boolean
    char *actuator_id; // string
    char *operation_mode_id; // string
    double *operation_mode_factor; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ddbc_instruction_t;

__attribute__((deprecated)) ddbc_instruction_t *ddbc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *actuator_id,
    char *operation_mode_id,
    double *operation_mode_factor
);

void ddbc_instruction_free(ddbc_instruction_t *ddbc_instruction);

ddbc_instruction_t *ddbc_instruction_parseFromJSON(cJSON *ddbc_instructionJSON);

cJSON *ddbc_instruction_convertToJSON(ddbc_instruction_t *ddbc_instruction);

#endif /* _ddbc_instruction_H_ */

