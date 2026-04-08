#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/reception_status_values.h>


char* reception_status_values_reception_status_values_ToString(s2_reception_status_values__e reception_status_values) {
    char *reception_status_valuesArray[] =  { "NULL", "INVALID_DATA", "INVALID_MESSAGE", "INVALID_CONTENT", "TEMPORARY_ERROR", "PERMANENT_ERROR", "OK" };
    return reception_status_valuesArray[reception_status_values];
}

s2_reception_status_values__e reception_status_values_reception_status_values_FromString(char* reception_status_values) {
    size_t stringToReturn = 0;
    char *reception_status_valuesArray[] =  { "NULL", "INVALID_DATA", "INVALID_MESSAGE", "INVALID_CONTENT", "TEMPORARY_ERROR", "PERMANENT_ERROR", "OK" };
    size_t sizeofArray = sizeof(reception_status_valuesArray) / sizeof(reception_status_valuesArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(reception_status_values, reception_status_valuesArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *reception_status_values_convertToJSON(s2_reception_status_values__e reception_status_values) {
    cJSON *item = cJSON_CreateString(reception_status_values_reception_status_values_ToString(reception_status_values));
    // if(cJSON_AddStringToObject(item, "reception_status_values", reception_status_values_reception_status_values_ToString(reception_status_values)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_reception_status_values__e reception_status_values_parseFromJSON(cJSON *reception_status_valuesJSON) {
    if(!cJSON_IsString(reception_status_valuesJSON) || (reception_status_valuesJSON->valuestring == NULL)) {
        return 0;
    }
    return reception_status_values_reception_status_values_FromString(reception_status_valuesJSON->valuestring);
}
