#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ombc_system_description.h>



static ombc_system_description_t *ombc_system_description_create_internal(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    ombc_system_description_t *ombc_system_description_local_var = malloc(sizeof(ombc_system_description_t));
    if (!ombc_system_description_local_var) {
        return NULL;
    }
    memset(ombc_system_description_local_var, 0, sizeof(ombc_system_description_t));
    ombc_system_description_local_var->_library_owned = 1;
    ombc_system_description_local_var->message_type = message_type;
    ombc_system_description_local_var->message_id = message_id;
    ombc_system_description_local_var->valid_from = valid_from;
    ombc_system_description_local_var->operation_modes = operation_modes;
    ombc_system_description_local_var->transitions = transitions;
    ombc_system_description_local_var->timers = timers;
    return ombc_system_description_local_var;
}

__attribute__((deprecated)) ombc_system_description_t *ombc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *operation_modes,
    list_t *transitions,
    list_t *timers
    ) {
    ombc_system_description_t *result = ombc_system_description_create_internal (
        message_type,
        message_id,
        valid_from,
        operation_modes,
        transitions,
        timers
        );
    if (!result) {
    }
    return result;
}

void ombc_system_description_free(ombc_system_description_t *ombc_system_description) {
    if(NULL == ombc_system_description){
        return ;
    }
    if(ombc_system_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ombc_system_description_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ombc_system_description->message_type) {
        free(ombc_system_description->message_type);
        ombc_system_description->message_type = NULL;
    }
    if (ombc_system_description->message_id) {
        free(ombc_system_description->message_id);
        ombc_system_description->message_id = NULL;
    }
    if (ombc_system_description->valid_from) {
        free(ombc_system_description->valid_from);
        ombc_system_description->valid_from = NULL;
    }
    if (ombc_system_description->operation_modes) {
        list_ForEach(listEntry, ombc_system_description->operation_modes) {
            ombc_operation_mode_free(listEntry->data);
        }
        list_freeList(ombc_system_description->operation_modes);
        ombc_system_description->operation_modes = NULL;
    }
    if (ombc_system_description->transitions) {
        list_ForEach(listEntry, ombc_system_description->transitions) {
            transition_free(listEntry->data);
        }
        list_freeList(ombc_system_description->transitions);
        ombc_system_description->transitions = NULL;
    }
    if (ombc_system_description->timers) {
        list_ForEach(listEntry, ombc_system_description->timers) {
            timer_type_free(listEntry->data);
        }
        list_freeList(ombc_system_description->timers);
        ombc_system_description->timers = NULL;
    }
    free(ombc_system_description);
}

cJSON *ombc_system_description_convertToJSON(ombc_system_description_t *ombc_system_description) {
    cJSON *item = cJSON_CreateObject();

    // ombc_system_description->message_type
    if (!ombc_system_description->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ombc_system_description->message_type) == NULL) {
    goto fail; //String
    }


    // ombc_system_description->message_id
    if (!ombc_system_description->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ombc_system_description->message_id) == NULL) {
    goto fail; //String
    }


    // ombc_system_description->valid_from
    if (!ombc_system_description->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", ombc_system_description->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // ombc_system_description->operation_modes
    if (!ombc_system_description->operation_modes) {
        goto fail;
    }
    cJSON *operation_modes = cJSON_AddArrayToObject(item, "operation_modes");
    if(operation_modes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *operation_modesListEntry;
    if (ombc_system_description->operation_modes) {
    list_ForEach(operation_modesListEntry, ombc_system_description->operation_modes) {
    cJSON *itemLocal = ombc_operation_mode_convertToJSON(operation_modesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(operation_modes, itemLocal);
    }
    }


    // ombc_system_description->transitions
    if (!ombc_system_description->transitions) {
        goto fail;
    }
    cJSON *transitions = cJSON_AddArrayToObject(item, "transitions");
    if(transitions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transitionsListEntry;
    if (ombc_system_description->transitions) {
    list_ForEach(transitionsListEntry, ombc_system_description->transitions) {
    cJSON *itemLocal = transition_convertToJSON(transitionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transitions, itemLocal);
    }
    }


    // ombc_system_description->timers
    if (!ombc_system_description->timers) {
        goto fail;
    }
    cJSON *timers = cJSON_AddArrayToObject(item, "timers");
    if(timers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *timersListEntry;
    if (ombc_system_description->timers) {
    list_ForEach(timersListEntry, ombc_system_description->timers) {
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

ombc_system_description_t *ombc_system_description_parseFromJSON(cJSON *ombc_system_descriptionJSON){

    ombc_system_description_t *ombc_system_description_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *valid_from_local_str = NULL;

    // define the local list for ombc_system_description->operation_modes
    list_t *operation_modesList = NULL;

    // define the local list for ombc_system_description->transitions
    list_t *transitionsList = NULL;

    // define the local list for ombc_system_description->timers
    list_t *timersList = NULL;

    // ombc_system_description->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "message_type");
    if (cJSON_IsNull(message_type)) {
        message_type = NULL;
    }
    if (!message_type) {
        goto end;
    }

    
    if(!cJSON_IsString(message_type))
    {
    goto end; //String
    }

    // ombc_system_description->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsString(message_id))
    {
    goto end; //String
    }

    // ombc_system_description->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "valid_from");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (!valid_from) {
        goto end;
    }

    
    if(!cJSON_IsString(valid_from) && !cJSON_IsNull(valid_from))
    {
    goto end; //DateTime
    }

    // ombc_system_description->operation_modes
    cJSON *operation_modes = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "operation_modes");
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
        ombc_operation_mode_t *operation_modesItem = ombc_operation_mode_parseFromJSON(operation_modes_local_nonprimitive);

        list_addElement(operation_modesList, operation_modesItem);
    }

    // ombc_system_description->transitions
    cJSON *transitions = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "transitions");
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

    // ombc_system_description->timers
    cJSON *timers = cJSON_GetObjectItemCaseSensitive(ombc_system_descriptionJSON, "timers");
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


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);

    ombc_system_description_local_var = ombc_system_description_create_internal (
        message_type_local_str,
        message_id_local_str,
        valid_from_local_str,
        operation_modesList,
        transitionsList,
        timersList
        );

    if (!ombc_system_description_local_var) {
        goto end;
    }

    return ombc_system_description_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (valid_from_local_str) {
        free(valid_from_local_str);
        valid_from_local_str = NULL;
    }
    if (operation_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, operation_modesList) {
            ombc_operation_mode_free(listEntry->data);
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
