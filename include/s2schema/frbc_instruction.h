/*
 * frbc_instruction.h
 * 
 */

#ifndef _frbc_instruction_H_
#define _frbc_instruction_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct frbc_instruction_t frbc_instruction_t;




typedef struct frbc_instruction_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *actuator_id; // string
    char *operation_mode; // string
    double *operation_mode_factor; //numeric
    char *execution_time; //date time
    int *abnormal_condition; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} frbc_instruction_t;

__attribute__((deprecated)) frbc_instruction_t *frbc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *actuator_id,
    char *operation_mode,
    double *operation_mode_factor,
    char *execution_time,
    int *abnormal_condition
);

void frbc_instruction_free(frbc_instruction_t *frbc_instruction);

frbc_instruction_t *frbc_instruction_parseFromJSON(cJSON *frbc_instructionJSON);

cJSON *frbc_instruction_convertToJSON(frbc_instruction_t *frbc_instruction);

#endif /* _frbc_instruction_H_ */

