#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/revokable_objects.h>


char* revokable_objects_revokable_objects_ToString(s2_revokable_objects__e revokable_objects) {
    char *revokable_objectsArray[] =  { "NULL", "PEBC.PowerConstraints", "PEBC.EnergyConstraint", "PEBC.Instruction", "PPBC.PowerProfileDefinition", "PPBC.ScheduleInstruction", "PPBC.StartInterruptionInstruction", "PPBC.EndInterruptionInstruction", "OMBC.SystemDescription", "OMBC.Instruction", "FRBC.SystemDescription", "FRBC.Instruction", "DDBC.SystemDescription", "DDBC.Instruction" };
    return revokable_objectsArray[revokable_objects];
}

s2_revokable_objects__e revokable_objects_revokable_objects_FromString(char* revokable_objects) {
    size_t stringToReturn = 0;
    char *revokable_objectsArray[] =  { "NULL", "PEBC.PowerConstraints", "PEBC.EnergyConstraint", "PEBC.Instruction", "PPBC.PowerProfileDefinition", "PPBC.ScheduleInstruction", "PPBC.StartInterruptionInstruction", "PPBC.EndInterruptionInstruction", "OMBC.SystemDescription", "OMBC.Instruction", "FRBC.SystemDescription", "FRBC.Instruction", "DDBC.SystemDescription", "DDBC.Instruction" };
    size_t sizeofArray = sizeof(revokable_objectsArray) / sizeof(revokable_objectsArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(revokable_objects, revokable_objectsArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *revokable_objects_convertToJSON(s2_revokable_objects__e revokable_objects) {
    cJSON *item = cJSON_CreateString(revokable_objects_revokable_objects_ToString(revokable_objects));
    // if(cJSON_AddStringToObject(item, "revokable_objects", revokable_objects_revokable_objects_ToString(revokable_objects)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_revokable_objects__e revokable_objects_parseFromJSON(cJSON *revokable_objectsJSON) {
    if(!cJSON_IsString(revokable_objectsJSON) || (revokable_objectsJSON->valuestring == NULL)) {
        return 0;
    }
    return revokable_objects_revokable_objects_FromString(revokable_objectsJSON->valuestring);
}
