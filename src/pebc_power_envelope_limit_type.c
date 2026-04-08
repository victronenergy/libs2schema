#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_power_envelope_limit_type.h>


char* pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_ToString(s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type) {
    char *pebc_power_envelope_limit_typeArray[] =  { "NULL", "UPPER_LIMIT", "LOWER_LIMIT" };
    return pebc_power_envelope_limit_typeArray[pebc_power_envelope_limit_type];
}

s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_FromString(char* pebc_power_envelope_limit_type) {
    size_t stringToReturn = 0;
    char *pebc_power_envelope_limit_typeArray[] =  { "NULL", "UPPER_LIMIT", "LOWER_LIMIT" };
    size_t sizeofArray = sizeof(pebc_power_envelope_limit_typeArray) / sizeof(pebc_power_envelope_limit_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(pebc_power_envelope_limit_type, pebc_power_envelope_limit_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *pebc_power_envelope_limit_type_convertToJSON(s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type) {
    cJSON *item = cJSON_CreateString(pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_ToString(pebc_power_envelope_limit_type));
    // if(cJSON_AddStringToObject(item, "pebc_power_envelope_limit_type", pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_ToString(pebc_power_envelope_limit_type)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type_parseFromJSON(cJSON *pebc_power_envelope_limit_typeJSON) {
    if(!cJSON_IsString(pebc_power_envelope_limit_typeJSON) || (pebc_power_envelope_limit_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_FromString(pebc_power_envelope_limit_typeJSON->valuestring);
}
