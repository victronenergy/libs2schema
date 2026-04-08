#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_profile_status.h>



static ppbc_power_profile_status_t *ppbc_power_profile_status_create_internal(
    char *message_type,
    char *message_id,
    list_t *sequence_container_status
    ) {
    ppbc_power_profile_status_t *ppbc_power_profile_status_local_var = malloc(sizeof(ppbc_power_profile_status_t));
    if (!ppbc_power_profile_status_local_var) {
        return NULL;
    }
    memset(ppbc_power_profile_status_local_var, 0, sizeof(ppbc_power_profile_status_t));
    ppbc_power_profile_status_local_var->_library_owned = 1;
    ppbc_power_profile_status_local_var->message_type = message_type;
    ppbc_power_profile_status_local_var->message_id = message_id;
    ppbc_power_profile_status_local_var->sequence_container_status = sequence_container_status;
    return ppbc_power_profile_status_local_var;
}

__attribute__((deprecated)) ppbc_power_profile_status_t *ppbc_power_profile_status_create(
    char *message_type,
    char *message_id,
    list_t *sequence_container_status
    ) {
    ppbc_power_profile_status_t *result = ppbc_power_profile_status_create_internal (
        message_type,
        message_id,
        sequence_container_status
        );
    if (!result) {
    }
    return result;
}

void ppbc_power_profile_status_free(ppbc_power_profile_status_t *ppbc_power_profile_status) {
    if(NULL == ppbc_power_profile_status){
        return ;
    }
    if(ppbc_power_profile_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_profile_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ppbc_power_profile_status->message_type) {
        free(ppbc_power_profile_status->message_type);
        ppbc_power_profile_status->message_type = NULL;
    }
    if (ppbc_power_profile_status->message_id) {
        free(ppbc_power_profile_status->message_id);
        ppbc_power_profile_status->message_id = NULL;
    }
    if (ppbc_power_profile_status->sequence_container_status) {
        list_ForEach(listEntry, ppbc_power_profile_status->sequence_container_status) {
            ppbc_power_sequence_container_status_free(listEntry->data);
        }
        list_freeList(ppbc_power_profile_status->sequence_container_status);
        ppbc_power_profile_status->sequence_container_status = NULL;
    }
    free(ppbc_power_profile_status);
}

cJSON *ppbc_power_profile_status_convertToJSON(ppbc_power_profile_status_t *ppbc_power_profile_status) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_profile_status->message_type
    if (!ppbc_power_profile_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ppbc_power_profile_status->message_type) == NULL) {
    goto fail; //String
    }


    // ppbc_power_profile_status->message_id
    if (!ppbc_power_profile_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ppbc_power_profile_status->message_id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_profile_status->sequence_container_status
    if (!ppbc_power_profile_status->sequence_container_status) {
        goto fail;
    }
    cJSON *sequence_container_status = cJSON_AddArrayToObject(item, "sequence_container_status");
    if(sequence_container_status == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *sequence_container_statusListEntry;
    if (ppbc_power_profile_status->sequence_container_status) {
    list_ForEach(sequence_container_statusListEntry, ppbc_power_profile_status->sequence_container_status) {
    cJSON *itemLocal = ppbc_power_sequence_container_status_convertToJSON(sequence_container_statusListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(sequence_container_status, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_power_profile_status_t *ppbc_power_profile_status_parseFromJSON(cJSON *ppbc_power_profile_statusJSON){

    ppbc_power_profile_status_t *ppbc_power_profile_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local list for ppbc_power_profile_status->sequence_container_status
    list_t *sequence_container_statusList = NULL;

    // ppbc_power_profile_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_statusJSON, "message_type");
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

    // ppbc_power_profile_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_statusJSON, "message_id");
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

    // ppbc_power_profile_status->sequence_container_status
    cJSON *sequence_container_status = cJSON_GetObjectItemCaseSensitive(ppbc_power_profile_statusJSON, "sequence_container_status");
    if (cJSON_IsNull(sequence_container_status)) {
        sequence_container_status = NULL;
    }
    if (!sequence_container_status) {
        goto end;
    }

    
    cJSON *sequence_container_status_local_nonprimitive = NULL;
    if(!cJSON_IsArray(sequence_container_status)){
        goto end; //nonprimitive container
    }

    sequence_container_statusList = list_createList();

    cJSON_ArrayForEach(sequence_container_status_local_nonprimitive,sequence_container_status )
    {
        if(!cJSON_IsObject(sequence_container_status_local_nonprimitive)){
            goto end;
        }
        ppbc_power_sequence_container_status_t *sequence_container_statusItem = ppbc_power_sequence_container_status_parseFromJSON(sequence_container_status_local_nonprimitive);

        list_addElement(sequence_container_statusList, sequence_container_statusItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);

    ppbc_power_profile_status_local_var = ppbc_power_profile_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        sequence_container_statusList
        );

    if (!ppbc_power_profile_status_local_var) {
        goto end;
    }

    return ppbc_power_profile_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (sequence_container_statusList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, sequence_container_statusList) {
            ppbc_power_sequence_container_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(sequence_container_statusList);
        sequence_container_statusList = NULL;
    }
    return NULL;

}
