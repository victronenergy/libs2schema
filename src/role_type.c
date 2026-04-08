#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/role_type.h>


char* role_type_role_type_ToString(s2_role_type__e role_type) {
    char *role_typeArray[] =  { "NULL", "ENERGY_PRODUCER", "ENERGY_CONSUMER", "ENERGY_STORAGE" };
    return role_typeArray[role_type];
}

s2_role_type__e role_type_role_type_FromString(char* role_type) {
    size_t stringToReturn = 0;
    char *role_typeArray[] =  { "NULL", "ENERGY_PRODUCER", "ENERGY_CONSUMER", "ENERGY_STORAGE" };
    size_t sizeofArray = sizeof(role_typeArray) / sizeof(role_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(role_type, role_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *role_type_convertToJSON(s2_role_type__e role_type) {
    cJSON *item = cJSON_CreateString(role_type_role_type_ToString(role_type));
    // if(cJSON_AddStringToObject(item, "role_type", role_type_role_type_ToString(role_type)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_role_type__e role_type_parseFromJSON(cJSON *role_typeJSON) {
    if(!cJSON_IsString(role_typeJSON) || (role_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return role_type_role_type_FromString(role_typeJSON->valuestring);
}
