/*
 * instruction_status_update.h
 * 
 */

#ifndef _instruction_status_update_H_
#define _instruction_status_update_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct instruction_status_update_t instruction_status_update_t;

#include <s2schema/instruction_status.h>



typedef struct instruction_status_update_t {
    char *message_type; // string
    char *message_id; // string
    char *instruction_id; // string
    s2_instruction_status__e status_type; //referenced enum
    char *timestamp; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} instruction_status_update_t;

__attribute__((deprecated)) instruction_status_update_t *instruction_status_update_create(
    char *message_type,
    char *message_id,
    char *instruction_id,
    s2_instruction_status__e status_type,
    char *timestamp
);

void instruction_status_update_free(instruction_status_update_t *instruction_status_update);

instruction_status_update_t *instruction_status_update_parseFromJSON(cJSON *instruction_status_updateJSON);

cJSON *instruction_status_update_convertToJSON(instruction_status_update_t *instruction_status_update);

#endif /* _instruction_status_update_H_ */

