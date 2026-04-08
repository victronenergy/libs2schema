#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/energy_management_role.h>


char* energy_management_role_energy_management_role_ToString(s2_energy_management_role__e energy_management_role) {
    char *energy_management_roleArray[] =  { "NULL", "CEM", "RM" };
    return energy_management_roleArray[energy_management_role];
}

s2_energy_management_role__e energy_management_role_energy_management_role_FromString(char* energy_management_role) {
    size_t stringToReturn = 0;
    char *energy_management_roleArray[] =  { "NULL", "CEM", "RM" };
    size_t sizeofArray = sizeof(energy_management_roleArray) / sizeof(energy_management_roleArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(energy_management_role, energy_management_roleArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *energy_management_role_convertToJSON(s2_energy_management_role__e energy_management_role) {
    cJSON *item = cJSON_CreateString(energy_management_role_energy_management_role_ToString(energy_management_role));
    // if(cJSON_AddStringToObject(item, "energy_management_role", energy_management_role_energy_management_role_ToString(energy_management_role)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_energy_management_role__e energy_management_role_parseFromJSON(cJSON *energy_management_roleJSON) {
    if(!cJSON_IsString(energy_management_roleJSON) || (energy_management_roleJSON->valuestring == NULL)) {
        return 0;
    }
    return energy_management_role_energy_management_role_FromString(energy_management_roleJSON->valuestring);
}
