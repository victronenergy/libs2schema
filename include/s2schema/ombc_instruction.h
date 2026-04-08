/*
 * ombc_instruction.h
 * 
 */

#ifndef _ombc_instruction_H_
#define _ombc_instruction_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ombc_instruction_t ombc_instruction_t;




typedef struct ombc_instruction_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *execution_time; //date time
    char *operation_mode_id; // string
    double *operation_mode_factor; //numeric
    int *abnormal_condition; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ombc_instruction_t;

__attribute__((deprecated)) ombc_instruction_t *ombc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    char *operation_mode_id,
    double *operation_mode_factor,
    int *abnormal_condition
);

void ombc_instruction_free(ombc_instruction_t *ombc_instruction);

ombc_instruction_t *ombc_instruction_parseFromJSON(cJSON *ombc_instructionJSON);

cJSON *ombc_instruction_convertToJSON(ombc_instruction_t *ombc_instruction);

#endif /* _ombc_instruction_H_ */

