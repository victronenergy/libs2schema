/*
 * instruction_status.h
 * NEW: Instruction was newly created ACCEPTED: Instruction has been accepted REJECTED: Instruction was rejected REVOKED: Instruction was revoked STARTED: Instruction was executed SUCCEEDED: Instruction finished successfully ABORTED: Instruction was aborted.
 */

#ifndef _instruction_status_H_
#define _instruction_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct instruction_status_t instruction_status_t;


// Enum  for instruction_status

typedef enum { s2_instruction_status__NULL = 0, s2_instruction_status__NEW, s2_instruction_status__ACCEPTED, s2_instruction_status__REJECTED, s2_instruction_status__REVOKED, s2_instruction_status__STARTED, s2_instruction_status__SUCCEEDED, s2_instruction_status__ABORTED } s2_instruction_status__e;

char* instruction_status_instruction_status_ToString(s2_instruction_status__e instruction_status);

s2_instruction_status__e instruction_status_instruction_status_FromString(char* instruction_status);

cJSON *instruction_status_convertToJSON(s2_instruction_status__e instruction_status);

s2_instruction_status__e instruction_status_parseFromJSON(cJSON *instruction_statusJSON);

#endif /* _instruction_status_H_ */

