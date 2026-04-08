#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/control_type.h>


char* control_type_control_type_ToString(s2_control_type__e control_type) {
    char *control_typeArray[] =  { "NULL", "POWER_ENVELOPE_BASED_CONTROL", "POWER_PROFILE_BASED_CONTROL", "OPERATION_MODE_BASED_CONTROL", "FILL_RATE_BASED_CONTROL", "DEMAND_DRIVEN_BASED_CONTROL", "NOT_CONTROLABLE", "NO_SELECTION" };
    return control_typeArray[control_type];
}

s2_control_type__e control_type_control_type_FromString(char* control_type) {
    size_t stringToReturn = 0;
    char *control_typeArray[] =  { "NULL", "POWER_ENVELOPE_BASED_CONTROL", "POWER_PROFILE_BASED_CONTROL", "OPERATION_MODE_BASED_CONTROL", "FILL_RATE_BASED_CONTROL", "DEMAND_DRIVEN_BASED_CONTROL", "NOT_CONTROLABLE", "NO_SELECTION" };
    size_t sizeofArray = sizeof(control_typeArray) / sizeof(control_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(control_type, control_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *control_type_convertToJSON(s2_control_type__e control_type) {
    cJSON *item = cJSON_CreateString(control_type_control_type_ToString(control_type));
    // if(cJSON_AddStringToObject(item, "control_type", control_type_control_type_ToString(control_type)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_control_type__e control_type_parseFromJSON(cJSON *control_typeJSON) {
    if(!cJSON_IsString(control_typeJSON) || (control_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return control_type_control_type_FromString(control_typeJSON->valuestring);
}
