#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/instruction_status.h>


char* instruction_status_instruction_status_ToString(s2_instruction_status__e instruction_status) {
    char *instruction_statusArray[] =  { "NULL", "NEW", "ACCEPTED", "REJECTED", "REVOKED", "STARTED", "SUCCEEDED", "ABORTED" };
    return instruction_statusArray[instruction_status];
}

s2_instruction_status__e instruction_status_instruction_status_FromString(char* instruction_status) {
    size_t stringToReturn = 0;
    char *instruction_statusArray[] =  { "NULL", "NEW", "ACCEPTED", "REJECTED", "REVOKED", "STARTED", "SUCCEEDED", "ABORTED" };
    size_t sizeofArray = sizeof(instruction_statusArray) / sizeof(instruction_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(instruction_status, instruction_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *instruction_status_convertToJSON(s2_instruction_status__e instruction_status) {
    cJSON *item = cJSON_CreateString(instruction_status_instruction_status_ToString(instruction_status));
    // if(cJSON_AddStringToObject(item, "instruction_status", instruction_status_instruction_status_ToString(instruction_status)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_instruction_status__e instruction_status_parseFromJSON(cJSON *instruction_statusJSON) {
    if(!cJSON_IsString(instruction_statusJSON) || (instruction_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return instruction_status_instruction_status_FromString(instruction_statusJSON->valuestring);
}
