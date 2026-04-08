#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_sequence_container_status.h>



static ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_create_internal(
    char *power_profile_id,
    char *sequence_container_id,
    char *selected_sequence_id,
    int *progress,
    s2_ppbc_power_sequence_status__e status
    ) {
    ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_local_var = malloc(sizeof(ppbc_power_sequence_container_status_t));
    if (!ppbc_power_sequence_container_status_local_var) {
        return NULL;
    }
    memset(ppbc_power_sequence_container_status_local_var, 0, sizeof(ppbc_power_sequence_container_status_t));
    ppbc_power_sequence_container_status_local_var->_library_owned = 1;
    ppbc_power_sequence_container_status_local_var->power_profile_id = power_profile_id;
    ppbc_power_sequence_container_status_local_var->sequence_container_id = sequence_container_id;
    ppbc_power_sequence_container_status_local_var->selected_sequence_id = selected_sequence_id;
    ppbc_power_sequence_container_status_local_var->progress = progress;
    ppbc_power_sequence_container_status_local_var->status = status;
    return ppbc_power_sequence_container_status_local_var;
}

__attribute__((deprecated)) ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_create(
    char *power_profile_id,
    char *sequence_container_id,
    char *selected_sequence_id,
    int *progress,
    s2_ppbc_power_sequence_status__e status
    ) {
    int *progress_copy = NULL;
    if (progress) {
        progress_copy = malloc(sizeof(int));
        if (progress_copy) *progress_copy = *progress;
    }
    ppbc_power_sequence_container_status_t *result = ppbc_power_sequence_container_status_create_internal (
        power_profile_id,
        sequence_container_id,
        selected_sequence_id,
        progress_copy,
        status
        );
    if (!result) {
        free(progress_copy);
    }
    return result;
}

void ppbc_power_sequence_container_status_free(ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status) {
    if(NULL == ppbc_power_sequence_container_status){
        return ;
    }
    if(ppbc_power_sequence_container_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_sequence_container_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ppbc_power_sequence_container_status->power_profile_id) {
        free(ppbc_power_sequence_container_status->power_profile_id);
        ppbc_power_sequence_container_status->power_profile_id = NULL;
    }
    if (ppbc_power_sequence_container_status->sequence_container_id) {
        free(ppbc_power_sequence_container_status->sequence_container_id);
        ppbc_power_sequence_container_status->sequence_container_id = NULL;
    }
    if (ppbc_power_sequence_container_status->selected_sequence_id) {
        free(ppbc_power_sequence_container_status->selected_sequence_id);
        ppbc_power_sequence_container_status->selected_sequence_id = NULL;
    }
    if (ppbc_power_sequence_container_status->progress) {
        free(ppbc_power_sequence_container_status->progress);
        ppbc_power_sequence_container_status->progress = NULL;
    }
    free(ppbc_power_sequence_container_status);
}

cJSON *ppbc_power_sequence_container_status_convertToJSON(ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_sequence_container_status->power_profile_id
    if (!ppbc_power_sequence_container_status->power_profile_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "power_profile_id", ppbc_power_sequence_container_status->power_profile_id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_sequence_container_status->sequence_container_id
    if (!ppbc_power_sequence_container_status->sequence_container_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sequence_container_id", ppbc_power_sequence_container_status->sequence_container_id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_sequence_container_status->selected_sequence_id
    if(ppbc_power_sequence_container_status->selected_sequence_id) {
    if(cJSON_AddStringToObject(item, "selected_sequence_id", ppbc_power_sequence_container_status->selected_sequence_id) == NULL) {
    goto fail; //String
    }
    }


    // ppbc_power_sequence_container_status->progress
    if(ppbc_power_sequence_container_status->progress) {
    if(cJSON_AddNumberToObject(item, "progress", *ppbc_power_sequence_container_status->progress) == NULL) {
    goto fail; //Numeric
    }
    }


    // ppbc_power_sequence_container_status->status
    if (s2_ppbc_power_sequence_status__NULL == ppbc_power_sequence_container_status->status) {
        goto fail;
    }
    cJSON *status_local_JSON = ppbc_power_sequence_status_convertToJSON(ppbc_power_sequence_container_status->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_parseFromJSON(cJSON *ppbc_power_sequence_container_statusJSON){

    ppbc_power_sequence_container_status_t *ppbc_power_sequence_container_status_local_var = NULL;

    char *power_profile_id_local_str = NULL;

    char *sequence_container_id_local_str = NULL;

    char *selected_sequence_id_local_str = NULL;

    // define the local variable for ppbc_power_sequence_container_status->progress
    int *progress_local_var = NULL;

    // define the local variable for ppbc_power_sequence_container_status->status
    s2_ppbc_power_sequence_status__e status_local_nonprim = 0;

    // ppbc_power_sequence_container_status->power_profile_id
    cJSON *power_profile_id = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_container_statusJSON, "power_profile_id");
    if (cJSON_IsNull(power_profile_id)) {
        power_profile_id = NULL;
    }
    if (!power_profile_id) {
        goto end;
    }

    
    if(!cJSON_IsString(power_profile_id))
    {
    goto end; //String
    }

    // ppbc_power_sequence_container_status->sequence_container_id
    cJSON *sequence_container_id = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_container_statusJSON, "sequence_container_id");
    if (cJSON_IsNull(sequence_container_id)) {
        sequence_container_id = NULL;
    }
    if (!sequence_container_id) {
        goto end;
    }

    
    if(!cJSON_IsString(sequence_container_id))
    {
    goto end; //String
    }

    // ppbc_power_sequence_container_status->selected_sequence_id
    cJSON *selected_sequence_id = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_container_statusJSON, "selected_sequence_id");
    if (cJSON_IsNull(selected_sequence_id)) {
        selected_sequence_id = NULL;
    }
    if (selected_sequence_id) { 
    if(!cJSON_IsString(selected_sequence_id) && !cJSON_IsNull(selected_sequence_id))
    {
    goto end; //String
    }
    }

    // ppbc_power_sequence_container_status->progress
    cJSON *progress = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_container_statusJSON, "progress");
    if (cJSON_IsNull(progress)) {
        progress = NULL;
    }
    if (progress) { 
    if(!cJSON_IsNumber(progress))
    {
    goto end; //Numeric
    }
    progress_local_var = malloc(sizeof(int));
    if(!progress_local_var)
    {
        goto end;
    }
    *progress_local_var = progress->valuedouble;
    }

    // ppbc_power_sequence_container_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_container_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = ppbc_power_sequence_status_parseFromJSON(status); //custom


    if (power_profile_id && !cJSON_IsNull(power_profile_id)) power_profile_id_local_str = strdup(power_profile_id->valuestring);
    if (sequence_container_id && !cJSON_IsNull(sequence_container_id)) sequence_container_id_local_str = strdup(sequence_container_id->valuestring);
    if (selected_sequence_id && !cJSON_IsNull(selected_sequence_id)) selected_sequence_id_local_str = strdup(selected_sequence_id->valuestring);

    ppbc_power_sequence_container_status_local_var = ppbc_power_sequence_container_status_create_internal (
        power_profile_id_local_str,
        sequence_container_id_local_str,
        selected_sequence_id_local_str,
        progress_local_var,
        status_local_nonprim
        );

    if (!ppbc_power_sequence_container_status_local_var) {
        goto end;
    }

    return ppbc_power_sequence_container_status_local_var;
end:
    if (power_profile_id_local_str) {
        free(power_profile_id_local_str);
        power_profile_id_local_str = NULL;
    }
    if (sequence_container_id_local_str) {
        free(sequence_container_id_local_str);
        sequence_container_id_local_str = NULL;
    }
    if (selected_sequence_id_local_str) {
        free(selected_sequence_id_local_str);
        selected_sequence_id_local_str = NULL;
    }
    if (progress_local_var) {
        free(progress_local_var);
        progress_local_var = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
