#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_profile_definition.h>



static ppbc_power_profile_definition_t *ppbc_power_profile_definition_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *start_time,
    char *end_time,
    list_t *power_sequences_containers
    ) {
    ppbc_power_profile_definition_t *ppbc_power_profile_definition_local_var = malloc(sizeof(ppbc_power_profile_definition_t));
    if (!ppbc_power_profile_definition_local_var) {
        return NULL;
    }
    memset(ppbc_power_profile_definition_local_var, 0, sizeof(ppbc_power_profile_definition_t));
    ppbc_power_profile_definition_local_var->_library_owned = 1;
    ppbc_power_profile_definition_local_var->message_type = message_type;
    ppbc_power_profile_definition_local_var->message_id = message_id;
    ppbc_power_profile_definition_local_var->id = id;
    ppbc_power_profile_definition_local_var->start_time = start_time;
    ppbc_power_profile_definition_local_var->end_time = end_time;
    ppbc_power_profile_definition_local_var->power_sequences_containers = power_sequences_containers;
    return ppbc_power_profile_definition_local_var;
}

__attribute__((deprecated)) ppbc_power_profile_definition_t *ppbc_power_profile_definition_create(
    char *message_type,
    char *message_id,
    char *id,
    char *start_time,
    char *end_time,
    list_t *power_sequences_containers
    ) {
    ppbc_power_profile_definition_t *result = ppbc_power_profile_definition_create_internal (
        message_type,
        message_id,
        id,
        start_time,
        end_time,
        power_sequences_containers
        );
    if (!result) {
    }
    return result;
}

void ppbc_power_profile_definition_free(ppbc_power_profile_definition_t *ppbc_power_profile_definition) {
    if(NULL == ppbc_power_profile_definition){
        return ;
    }
    if(ppbc_power_profile_definition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_profile_definition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ppbc_power_profile_definition->message_type) {
        free(ppbc_power_profile_definition->message_type);
        ppbc_power_profile_definition->message_type = NULL;
    }
    if (ppbc_power_profile_definition->message_id) {
        free(ppbc_power_profile_definition->message_id);
        ppbc_power_profile_definition->message_id = NULL;
    }
    if (ppbc_power_profile_definition->id) {
        free(ppbc_power_profile_definition->id);
        ppbc_power_profile_definition->id = NULL;
    }
    if (ppbc_power_profile_definition->start_time) {
        free(ppbc_power_profile_definition->start_time);
        ppbc_power_profile_definition->start_time = NULL;
    }
    if (ppbc_power_profile_definition->end_time) {
        free(ppbc_power_profile_definition->end_time);
        ppbc_power_profile_definition->end_time = NULL;
    }
    if (ppbc_power_profile_definition->power_sequences_containers) {
        list_ForEach(listEntry, ppbc_power_profile_definition->power_sequences_containers) {
            ppbc_power_sequence_container_free(listEntry->data);
        }
        list_freeList(ppbc_power_profile_definition->power_sequences_containers);
        ppbc_power_profile_definition->power_sequences_containers = NULL;
    }
    free(ppbc_power_profile_definition);
}

cJSON *ppbc_power_profile_definition_convertToJSON(ppbc_power_profile_definition_t *ppbc_power_profile_definition) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_profile_definition->message_type
    if (!ppbc_power_profile_definition->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ppbc_power_profile_definition->message_type) == NULL) {
    goto fail; //String
    }


    // ppbc_power_profile_definition->message_id
    if (!ppbc_power_profile_definition->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ppbc_power_profile_definition->message_id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_profile_definition->id
    if (!ppbc_power_profile_definition->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ppbc_power_profile_definition->id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_profile_definition->start_time
    if (!ppbc_power_profile_definition->start_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_time", ppbc_power_profile_definition->start_time) == NULL) {
    goto fail; //Date-Time
    }


    // ppbc_power_profile_definition->end_time
    if (!ppbc_power_profile_definition->end_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "end_time", ppbc_power_profile_definition->end_time) == NULL) {
    goto fail; //Date-Time
    }


    // ppbc_power_profile_definition->power_sequences_containers
    if (!ppbc_power_profile_definition->power_sequences_containers) {
        goto fail;
    }
    cJSON *power_sequences_containers = cJSON_AddArrayToObject(item, "power_sequences_containers");
    if(power_sequences_containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_sequences_containersListEntry;
    if (ppbc_power_profile_definition->power_sequences_containers) {
    list_ForEach(power_sequences_containersListEntry, ppbc_power_profile_definition->power_sequences_containers) {
    cJSON *itemLocal = ppbc_power_sequence_container_convertToJSON(power_sequences_containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_sequences_containers, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_power_profile_definition_t *ppbc_power_profile_definition_parseFromJSON(cJSON *ppbc_power_profile_definitionJSON){

    ppbc_power_profile_definition_t *ppbc_power_profile_definition_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *start_time_local_str = NULL;

    char *end_time_local_str = NULL;

    // define the local list for ppbc_power_profile_definition->power_sequences_containers
    list_t *power_sequences_containersList = NULL;

    // ppbc_power_profile_definition->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "message_type");
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

    // ppbc_power_profile_definition->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "message_id");
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

    // ppbc_power_profile_definition->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "id");
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

    // ppbc_power_profile_definition->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "start_time");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (!start_time) {
        goto end;
    }

    
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }

    // ppbc_power_profile_definition->end_time
    cJSON *end_time = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "end_time");
    if (cJSON_IsNull(end_time)) {
        end_time = NULL;
    }
    if (!end_time) {
        goto end;
    }

    
    if(!cJSON_IsString(end_time) && !cJSON_IsNull(end_time))
    {
    goto end; //DateTime
    }

    // ppbc_power_profile_definition->power_sequences_containers
    cJSON *power_sequences_containers = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_definitionJSON, "power_sequences_containers");
    if (cJSON_IsNull(power_sequences_containers)) {
        power_sequences_containers = NULL;
    }
    if (!power_sequences_containers) {
        goto end;
    }

    
    cJSON *power_sequences_containers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_sequences_containers)){
        goto end; //nonprimitive container
    }

    power_sequences_containersList = list_createList();

    cJSON_ArrayForEach(power_sequences_containers_local_nonprimitive,power_sequences_containers )
    {
        if(!cJSON_IsObject(power_sequences_containers_local_nonprimitive)){
            goto end;
        }
        ppbc_power_sequence_container_t *power_sequences_containersItem = ppbc_power_sequence_container_parseFromJSON(power_sequences_containers_local_nonprimitive);

        list_addElement(power_sequences_containersList, power_sequences_containersItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);
    if (end_time && !cJSON_IsNull(end_time)) end_time_local_str = strdup(end_time->valuestring);

    ppbc_power_profile_definition_local_var = ppbc_power_profile_definition_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        start_time_local_str,
        end_time_local_str,
        power_sequences_containersList
        );

    if (!ppbc_power_profile_definition_local_var) {
        goto end;
    }

    return ppbc_power_profile_definition_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (end_time_local_str) {
        free(end_time_local_str);
        end_time_local_str = NULL;
    }
    if (power_sequences_containersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_sequences_containersList) {
            ppbc_power_sequence_container_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_sequences_containersList);
        power_sequences_containersList = NULL;
    }
    return NULL;

}
