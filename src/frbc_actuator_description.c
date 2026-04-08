#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_actuator_description.h>


// char* frbc_actuator_description_supported_commodities_ToString(s2_frbc_actuator_description__e supported_commodities) {
//     char *supported_commoditiesArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
//     return supported_commoditiesArray[supported_commodities - 1];
// }
//
// s2_frbc_actuator_description__e frbc_actuator_description_supported_commodities_FromString(char* supported_commodities) {
//     size_t stringToReturn = 0;
//     char *supported_commoditiesArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
//     size_t sizeofArray = sizeof(supported_commoditiesArray) / sizeof(supported_commoditiesArray[0]);
//     while(stringToReturn < sizeofArray) {
//         if(strcmp(supported_commodities, supported_commoditiesArray[stringToReturn]) == 0) {
//             return stringToReturn + 1;
//         }
//         stringToReturn++;
//     }
//     return 0;
// }

static frbc_actuator_description_t *frbc_actuator_description_create_internal(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodities,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    frbc_actuator_description_t *frbc_actuator_description_local_var = malloc(sizeof(frbc_actuator_description_t));
    if (!frbc_actuator_description_local_var) {
        return NULL;
    }
    memset(frbc_actuator_description_local_var, 0, sizeof(frbc_actuator_description_t));
    frbc_actuator_description_local_var->_library_owned = 1;
    frbc_actuator_description_local_var->id = id;
    frbc_actuator_description_local_var->diagnostic_label = diagnostic_label;
    frbc_actuator_description_local_var->supported_commodities = supported_commodities;
    frbc_actuator_description_local_var->operation_modes = operation_modes;
    frbc_actuator_description_local_var->transitions = transitions;
    frbc_actuator_description_local_var->timers = timers;
    return frbc_actuator_description_local_var;
}

__attribute__((deprecated)) frbc_actuator_description_t *frbc_actuator_description_create(
    char *id,
    char *diagnostic_label,
    list_t *supported_commodities,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    frbc_actuator_description_t *result = frbc_actuator_description_create_internal (
        id,
        diagnostic_label,
        supported_commodities,
        operation_modes,
        transitions,
        timers
        );
    if (!result) {
    }
    return result;
}

void frbc_actuator_description_free(frbc_actuator_description_t *frbc_actuator_description) {
    if(NULL == frbc_actuator_description){
        return ;
    }
    if(frbc_actuator_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_actuator_description_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_actuator_description->id) {
        free(frbc_actuator_description->id);
        frbc_actuator_description->id = NULL;
    }
    if (frbc_actuator_description->diagnostic_label) {
        free(frbc_actuator_description->diagnostic_label);
        frbc_actuator_description->diagnostic_label = NULL;
    }
    if (frbc_actuator_description->supported_commodities) {
        list_ForEach(listEntry, frbc_actuator_description->supported_commodities) {
        }
        list_freeList(frbc_actuator_description->supported_commodities);
        frbc_actuator_description->supported_commodities = NULL;
    }
    if (frbc_actuator_description->operation_modes) {
        list_ForEach(listEntry, frbc_actuator_description->operation_modes) {
            frbc_operation_mode_free(listEntry->data);
        }
        list_freeList(frbc_actuator_description->operation_modes);
        frbc_actuator_description->operation_modes = NULL;
    }
    if (frbc_actuator_description->transitions) {
        list_ForEach(listEntry, frbc_actuator_description->transitions) {
            transition_free(listEntry->data);
        }
        list_freeList(frbc_actuator_description->transitions);
        frbc_actuator_description->transitions = NULL;
    }
    if (frbc_actuator_description->timers) {
        list_ForEach(listEntry, frbc_actuator_description->timers) {
            timer_type_free(listEntry->data);
        }
        list_freeList(frbc_actuator_description->timers);
        frbc_actuator_description->timers = NULL;
    }
    free(frbc_actuator_description);
}

cJSON *frbc_actuator_description_convertToJSON(frbc_actuator_description_t *frbc_actuator_description) {
    cJSON *item = cJSON_CreateObject();

    // frbc_actuator_description->id
    if (!frbc_actuator_description->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", frbc_actuator_description->id) == NULL) {
    goto fail; //String
    }


    // frbc_actuator_description->diagnostic_label
    if(frbc_actuator_description->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", frbc_actuator_description->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // frbc_actuator_description->supported_commodities
    if (!frbc_actuator_description->supported_commodities) {
        goto fail;
    }
    cJSON *supported_commodities = cJSON_AddArrayToObject(item, "supported_commodities");
    if(supported_commodities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *supported_commoditiesListEntry;
    if (frbc_actuator_description->supported_commodities) {
    list_ForEach(supported_commoditiesListEntry, frbc_actuator_description->supported_commodities) {
    cJSON *itemLocal = commodity_convertToJSON((s2_commodity__e)supported_commoditiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(supported_commodities, itemLocal);
    }
    }


    // frbc_actuator_description->operation_modes
    if (!frbc_actuator_description->operation_modes) {
        goto fail;
    }
    cJSON *operation_modes = cJSON_AddArrayToObject(item, "operation_modes");
    if(operation_modes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *operation_modesListEntry;
    if (frbc_actuator_description->operation_modes) {
    list_ForEach(operation_modesListEntry, frbc_actuator_description->operation_modes) {
    cJSON *itemLocal = frbc_operation_mode_convertToJSON(operation_modesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(operation_modes, itemLocal);
    }
    }


    // frbc_actuator_description->transitions
    if (!frbc_actuator_description->transitions) {
        goto fail;
    }
    cJSON *transitions = cJSON_AddArrayToObject(item, "transitions");
    if(transitions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transitionsListEntry;
    if (frbc_actuator_description->transitions) {
    list_ForEach(transitionsListEntry, frbc_actuator_description->transitions) {
    cJSON *itemLocal = transition_convertToJSON(transitionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transitions, itemLocal);
    }
    }


    // frbc_actuator_description->timers
    if (!frbc_actuator_description->timers) {
        goto fail;
    }
    cJSON *timers = cJSON_AddArrayToObject(item, "timers");
    if(timers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *timersListEntry;
    if (frbc_actuator_description->timers) {
    list_ForEach(timersListEntry, frbc_actuator_description->timers) {
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

frbc_actuator_description_t *frbc_actuator_description_parseFromJSON(cJSON *frbc_actuator_descriptionJSON){

    frbc_actuator_description_t *frbc_actuator_description_local_var = NULL;

    char *id_local_str = NULL;

    char *diagnostic_label_local_str = NULL;

    // define the local list for frbc_actuator_description->supported_commodities
    list_t *supported_commoditiesList = NULL;

    // define the local list for frbc_actuator_description->operation_modes
    list_t *operation_modesList = NULL;

    // define the local list for frbc_actuator_description->transitions
    list_t *transitionsList = NULL;

    // define the local list for frbc_actuator_description->timers
    list_t *timersList = NULL;

    // frbc_actuator_description->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "id");
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

    // frbc_actuator_description->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // frbc_actuator_description->supported_commodities
    cJSON *supported_commodities = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "supported_commodities");
    if (cJSON_IsNull(supported_commodities)) {
        supported_commodities = NULL;
    }
    if (!supported_commodities) {
        goto end;
    }

    
    cJSON *supported_commodities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(supported_commodities)){
        goto end; //nonprimitive container
    }

    supported_commoditiesList = list_createList();

    cJSON_ArrayForEach(supported_commodities_local_nonprimitive,supported_commodities )
    {
        if(!cJSON_IsObject(supported_commodities_local_nonprimitive)){
            goto end;
        }
        s2_commodity__e supported_commoditiesItem = commodity_parseFromJSON(supported_commodities_local_nonprimitive);

        list_addElement(supported_commoditiesList, (void *)supported_commoditiesItem);
    }

    // frbc_actuator_description->operation_modes
    cJSON *operation_modes = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "operation_modes");
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
        frbc_operation_mode_t *operation_modesItem = frbc_operation_mode_parseFromJSON(operation_modes_local_nonprimitive);

        list_addElement(operation_modesList, operation_modesItem);
    }

    // frbc_actuator_description->transitions
    cJSON *transitions = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "transitions");
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

    // frbc_actuator_description->timers
    cJSON *timers = cJSON_GetObjectItemCaseSensitive(frbc_actuator_descriptionJSON, "timers");
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

    frbc_actuator_description_local_var = frbc_actuator_description_create_internal (
        id_local_str,
        diagnostic_label_local_str,
        supported_commoditiesList,
        operation_modesList,
        transitionsList,
        timersList
        );

    if (!frbc_actuator_description_local_var) {
        goto end;
    }

    return frbc_actuator_description_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    if (supported_commoditiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_commoditiesList) {
            listEntry->data = NULL;
        }
        list_freeList(supported_commoditiesList);
        supported_commoditiesList = NULL;
    }
    if (operation_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, operation_modesList) {
            frbc_operation_mode_free(listEntry->data);
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
