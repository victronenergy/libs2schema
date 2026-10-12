#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_actuator_description.h>


// char* ddbc_actuator_description_supported_commodites_ToString(s2_ddbc_actuator_description__e supported_commodites) {
//     char *supported_commoditesArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
//     return supported_commoditesArray[supported_commodites - 1];
// }
//
// s2_ddbc_actuator_description__e ddbc_actuator_description_supported_commodites_FromString(char* supported_commodites) {
//     size_t stringToReturn = 0;
//     char *supported_commoditesArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
//     size_t sizeofArray = sizeof(supported_commoditesArray) / sizeof(supported_commoditesArray[0]);
//     while(stringToReturn < sizeofArray) {
//         if(strcmp(supported_commodites, supported_commoditesArray[stringToReturn]) == 0) {
//             return stringToReturn + 1;
//         }
//         stringToReturn++;
//     }
//     return 0;
// }

static ddbc_actuator_description_t *ddbc_actuator_description_create_internal(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodites,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    ddbc_actuator_description_t *ddbc_actuator_description_local_var = malloc(sizeof(ddbc_actuator_description_t));
    if (!ddbc_actuator_description_local_var) {
        return NULL;
    }
    memset(ddbc_actuator_description_local_var, 0, sizeof(ddbc_actuator_description_t));
    ddbc_actuator_description_local_var->_library_owned = 1;
    ddbc_actuator_description_local_var->id = id;
    ddbc_actuator_description_local_var->diagnostic_label = diagnostic_label;
    ddbc_actuator_description_local_var->supported_commodites = supported_commodites;
    ddbc_actuator_description_local_var->operation_modes = operation_modes;
    ddbc_actuator_description_local_var->transitions = transitions;
    ddbc_actuator_description_local_var->timers = timers;
    return ddbc_actuator_description_local_var;
}

__attribute__((deprecated)) ddbc_actuator_description_t *ddbc_actuator_description_create(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodites,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    ddbc_actuator_description_t *result = ddbc_actuator_description_create_internal (
        id,
        diagnostic_label,
        supported_commodites,
        operation_modes,
        transitions,
        timers
        );
    if (!result) {
    }
    return result;
}

void ddbc_actuator_description_free(ddbc_actuator_description_t *ddbc_actuator_description) {
    if(NULL == ddbc_actuator_description){
        return ;
    }
    if(ddbc_actuator_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_actuator_description_free");
        return ;
    }
    if (ddbc_actuator_description->id) {
        free(ddbc_actuator_description->id);
        ddbc_actuator_description->id = NULL;
    }
    if (ddbc_actuator_description->diagnostic_label) {
        free(ddbc_actuator_description->diagnostic_label);
        ddbc_actuator_description->diagnostic_label = NULL;
    }
    if (ddbc_actuator_description->supported_commodites) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_actuator_description->supported_commodites) {
        }
        list_freeList(ddbc_actuator_description->supported_commodites);
        ddbc_actuator_description->supported_commodites = NULL;
    }
    if (ddbc_actuator_description->operation_modes) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_actuator_description->operation_modes) {
            ddbc_operation_mode_free(listEntry->data);
        }
        list_freeList(ddbc_actuator_description->operation_modes);
        ddbc_actuator_description->operation_modes = NULL;
    }
    if (ddbc_actuator_description->transitions) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_actuator_description->transitions) {
            transition_free(listEntry->data);
        }
        list_freeList(ddbc_actuator_description->transitions);
        ddbc_actuator_description->transitions = NULL;
    }
    if (ddbc_actuator_description->timers) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_actuator_description->timers) {
            timer_type_free(listEntry->data);
        }
        list_freeList(ddbc_actuator_description->timers);
        ddbc_actuator_description->timers = NULL;
    }
    free(ddbc_actuator_description);
}

cJSON *ddbc_actuator_description_convertToJSON(ddbc_actuator_description_t *ddbc_actuator_description) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_actuator_description->id
    if (!ddbc_actuator_description->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ddbc_actuator_description->id) == NULL) {
    goto fail; //String
    }


    // ddbc_actuator_description->diagnostic_label
    if(ddbc_actuator_description->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", ddbc_actuator_description->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // ddbc_actuator_description->supported_commodites
    if (!ddbc_actuator_description->supported_commodites) {
        goto fail;
    }
    cJSON *supported_commodites = cJSON_AddArrayToObject(item, "supported_commodites");
    if(supported_commodites == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supported_commoditesListEntry;
    if (ddbc_actuator_description->supported_commodites) {
    list_ForEach(supported_commoditesListEntry, ddbc_actuator_description->supported_commodites) {
    cJSON *itemLocal = commodity_convertToJSON((s2_commodity__e)(intptr_t)supported_commoditesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supported_commodites, itemLocal);
    }
    }


    // ddbc_actuator_description->operation_modes
    if (!ddbc_actuator_description->operation_modes) {
        goto fail;
    }
    cJSON *operation_modes = cJSON_AddArrayToObject(item, "operation_modes");
    if(operation_modes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *operation_modesListEntry;
    if (ddbc_actuator_description->operation_modes) {
    list_ForEach(operation_modesListEntry, ddbc_actuator_description->operation_modes) {
    cJSON *itemLocal = ddbc_operation_mode_convertToJSON(operation_modesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(operation_modes, itemLocal);
    }
    }


    // ddbc_actuator_description->transitions
    if (!ddbc_actuator_description->transitions) {
        goto fail;
    }
    cJSON *transitions = cJSON_AddArrayToObject(item, "transitions");
    if(transitions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transitionsListEntry;
    if (ddbc_actuator_description->transitions) {
    list_ForEach(transitionsListEntry, ddbc_actuator_description->transitions) {
    cJSON *itemLocal = transition_convertToJSON(transitionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transitions, itemLocal);
    }
    }


    // ddbc_actuator_description->timers
    if (!ddbc_actuator_description->timers) {
        goto fail;
    }
    cJSON *timers = cJSON_AddArrayToObject(item, "timers");
    if(timers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *timersListEntry;
    if (ddbc_actuator_description->timers) {
    list_ForEach(timersListEntry, ddbc_actuator_description->timers) {
    cJSON *itemLocal = timer_type_convertToJSON(timersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(timers, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ddbc_actuator_description_t *ddbc_actuator_description_parseFromJSON(cJSON *ddbc_actuator_descriptionJSON){

    ddbc_actuator_description_t *ddbc_actuator_description_local_var = NULL;

    char *id_local_str = NULL;

    char *diagnostic_label_local_str = NULL;

    // define the local list for ddbc_actuator_description->supported_commodites
    list_t *supported_commoditesList = NULL;

    // define the local list for ddbc_actuator_description->operation_modes
    list_t *operation_modesList = NULL;

    // define the local list for ddbc_actuator_description->transitions
    list_t *transitionsList = NULL;

    // define the local list for ddbc_actuator_description->timers
    list_t *timersList = NULL;

    // ddbc_actuator_description->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // ddbc_actuator_description->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // ddbc_actuator_description->supported_commodites
    cJSON *supported_commodites = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "supported_commodites");
    if (cJSON_IsNull(supported_commodites)) {
        supported_commodites = NULL;
    }
    if (!supported_commodites) {
        goto end;
    }

    
    cJSON *supported_commodites_local_nonprimitive = NULL;
    if(!cJSON_IsArray(supported_commodites)){
        goto end; //nonprimitive container
    }

    supported_commoditesList = list_createList();

    cJSON_ArrayForEach(supported_commodites_local_nonprimitive,supported_commodites )
    {
        if(!cJSON_IsObject(supported_commodites_local_nonprimitive)){
            goto end;
        }
        s2_commodity__e supported_commoditesItem = commodity_parseFromJSON(supported_commodites_local_nonprimitive);

        list_addElement(supported_commoditesList, (void *)(intptr_t)supported_commoditesItem);
    }

    // ddbc_actuator_description->operation_modes
    cJSON *operation_modes = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "operation_modes");
    if (cJSON_IsNull(operation_modes)) {
        operation_modes = NULL;
    }
    if (!operation_modes) {
        goto end;
    }

    
    cJSON *operation_modes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(operation_modes)){
        goto end; //nonprimitive container
    }

    operation_modesList = list_createList();

    cJSON_ArrayForEach(operation_modes_local_nonprimitive,operation_modes )
    {
        if(!cJSON_IsObject(operation_modes_local_nonprimitive)){
            goto end;
        }
        ddbc_operation_mode_t *operation_modesItem = ddbc_operation_mode_parseFromJSON(operation_modes_local_nonprimitive);

        list_addElement(operation_modesList, operation_modesItem);
    }

    // ddbc_actuator_description->transitions
    cJSON *transitions = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "transitions");
    if (cJSON_IsNull(transitions)) {
        transitions = NULL;
    }
    if (!transitions) {
        goto end;
    }

    
    cJSON *transitions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(transitions)){
        goto end; //nonprimitive container
    }

    transitionsList = list_createList();

    cJSON_ArrayForEach(transitions_local_nonprimitive,transitions )
    {
        if(!cJSON_IsObject(transitions_local_nonprimitive)){
            goto end;
        }
        transition_t *transitionsItem = transition_parseFromJSON(transitions_local_nonprimitive);

        list_addElement(transitionsList, transitionsItem);
    }

    // ddbc_actuator_description->timers
    cJSON *timers = cJSON_GetObjectItemCaseSensitive(ddbc_actuator_descriptionJSON, "timers");
    if (cJSON_IsNull(timers)) {
        timers = NULL;
    }
    if (!timers) {
        goto end;
    }

    
    cJSON *timers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(timers)){
        goto end; //nonprimitive container
    }

    timersList = list_createList();

    cJSON_ArrayForEach(timers_local_nonprimitive,timers )
    {
        if(!cJSON_IsObject(timers_local_nonprimitive)){
            goto end;
        }
        timer_type_t *timersItem = timer_type_parseFromJSON(timers_local_nonprimitive);

        list_addElement(timersList, timersItem);
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    ddbc_actuator_description_local_var = ddbc_actuator_description_create_internal (
        id_local_str,
        diagnostic_label_local_str,
        supported_commoditesList,
        operation_modesList,
        transitionsList,
        timersList
        );

    if (!ddbc_actuator_description_local_var) {
        goto end;
    }

    return ddbc_actuator_description_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    if (supported_commoditesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_commoditesList) {
            listEntry->data = NULL;
        }
        list_freeList(supported_commoditesList);
        supported_commoditesList = NULL;
    }
    if (operation_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, operation_modesList) {
            ddbc_operation_mode_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(operation_modesList);
        operation_modesList = NULL;
    }
    if (transitionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, transitionsList) {
            transition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(transitionsList);
        transitionsList = NULL;
    }
    if (timersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, timersList) {
            timer_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(timersList);
        timersList = NULL;
    }
    return NULL;

}
