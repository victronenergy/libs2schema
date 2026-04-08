#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_sequence_status.h>


char* ppbc_power_sequence_status_ppbc_power_sequence_status_ToString(s2_ppbc_power_sequence_status__e ppbc_power_sequence_status) {
    char *ppbc_power_sequence_statusArray[] =  { "NULL", "NOT_SCHEDULED", "SCHEDULED", "EXECUTING", "INTERRUPTED", "FINISHED", "ABORTED" };
    return ppbc_power_sequence_statusArray[ppbc_power_sequence_status];
}

s2_ppbc_power_sequence_status__e ppbc_power_sequence_status_ppbc_power_sequence_status_FromString(char* ppbc_power_sequence_status) {
    size_t stringToReturn = 0;
    char *ppbc_power_sequence_statusArray[] =  { "NULL", "NOT_SCHEDULED", "SCHEDULED", "EXECUTING", "INTERRUPTED", "FINISHED", "ABORTED" };
    size_t sizeofArray = sizeof(ppbc_power_sequence_statusArray) / sizeof(ppbc_power_sequence_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ppbc_power_sequence_status, ppbc_power_sequence_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *ppbc_power_sequence_status_convertToJSON(s2_ppbc_power_sequence_status__e ppbc_power_sequence_status) {
    cJSON *item = cJSON_CreateString(ppbc_power_sequence_status_ppbc_power_sequence_status_ToString(ppbc_power_sequence_status));
    // if(cJSON_AddStringToObject(item, "ppbc_power_sequence_status", ppbc_power_sequence_status_ppbc_power_sequence_status_ToString(ppbc_power_sequence_status)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_ppbc_power_sequence_status__e ppbc_power_sequence_status_parseFromJSON(cJSON *ppbc_power_sequence_statusJSON) {
    if(!cJSON_IsString(ppbc_power_sequence_statusJSON) || (ppbc_power_sequence_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return ppbc_power_sequence_status_ppbc_power_sequence_status_FromString(ppbc_power_sequence_statusJSON->valuestring);
}
