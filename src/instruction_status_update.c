#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/instruction_status_update.h>



static instruction_status_update_t *instruction_status_update_create_internal(
    char *message_type,
    char *message_id,
    char *instruction_id,
    s2_instruction_status__e status_type,
    char *timestamp
    ) {
    instruction_status_update_t *instruction_status_update_local_var = malloc(sizeof(instruction_status_update_t));
    if (!instruction_status_update_local_var) {
        return NULL;
    }
    memset(instruction_status_update_local_var, 0, sizeof(instruction_status_update_t));
    instruction_status_update_local_var->_library_owned = 1;
    instruction_status_update_local_var->message_type = message_type;
    instruction_status_update_local_var->message_id = message_id;
    instruction_status_update_local_var->instruction_id = instruction_id;
    instruction_status_update_local_var->status_type = status_type;
    instruction_status_update_local_var->timestamp = timestamp;
    return instruction_status_update_local_var;
}

__attribute__((deprecated)) instruction_status_update_t *instruction_status_update_create(
    char *message_type,
    char *message_id,
    char *instruction_id,
    s2_instruction_status__e status_type,
    char *timestamp
    ) {
    instruction_status_update_t *result = instruction_status_update_create_internal (
        message_type,
        message_id,
        instruction_id,
        status_type,
        timestamp
        );
    if (!result) {
    }
    return result;
}

void instruction_status_update_free(instruction_status_update_t *instruction_status_update) {
    if(NULL == instruction_status_update){
        return ;
    }
    if(instruction_status_update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instruction_status_update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instruction_status_update->message_type) {
        free(instruction_status_update->message_type);
        instruction_status_update->message_type = NULL;
    }
    if (instruction_status_update->message_id) {
        free(instruction_status_update->message_id);
        instruction_status_update->message_id = NULL;
    }
    if (instruction_status_update->instruction_id) {
        free(instruction_status_update->instruction_id);
        instruction_status_update->instruction_id = NULL;
    }
    if (instruction_status_update->timestamp) {
        free(instruction_status_update->timestamp);
        instruction_status_update->timestamp = NULL;
    }
    free(instruction_status_update);
}

cJSON *instruction_status_update_convertToJSON(instruction_status_update_t *instruction_status_update) {
    cJSON *item = cJSON_CreateObject();

    // instruction_status_update->message_type
    if (!instruction_status_update->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", instruction_status_update->message_type) == NULL) {
    goto fail; //String
    }


    // instruction_status_update->message_id
    if (!instruction_status_update->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", instruction_status_update->message_id) == NULL) {
    goto fail; //String
    }


    // instruction_status_update->instruction_id
    if (!instruction_status_update->instruction_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instruction_id", instruction_status_update->instruction_id) == NULL) {
    goto fail; //String
    }


    // instruction_status_update->status_type
    if (s2_instruction_status__NULL == instruction_status_update->status_type) {
        goto fail;
    }
    cJSON *status_type_local_JSON = instruction_status_convertToJSON(instruction_status_update->status_type);
    if(status_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status_type", status_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // instruction_status_update->timestamp
    if (!instruction_status_update->timestamp) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "timestamp", instruction_status_update->timestamp) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instruction_status_update_t *instruction_status_update_parseFromJSON(cJSON *instruction_status_updateJSON){

    instruction_status_update_t *instruction_status_update_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *instruction_id_local_str = NULL;

    // define the local variable for instruction_status_update->status_type
    s2_instruction_status__e status_type_local_nonprim = 0;

    char *timestamp_local_str = NULL;

    // instruction_status_update->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(instruction_status_updateJSON, "message_type");
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

    // instruction_status_update->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(instruction_status_updateJSON, "message_id");
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

    // instruction_status_update->instruction_id
    cJSON *instruction_id = cJSON_GetObjectItemCaseSensitive(instruction_status_updateJSON, "instruction_id");
    if (cJSON_IsNull(instruction_id)) {
        instruction_id = NULL;
    }
    if (!instruction_id) {
        goto end;
    }

    
    if(!cJSON_IsString(instruction_id))
    {
    goto end; //String
    }

    // instruction_status_update->status_type
    cJSON *status_type = cJSON_GetObjectItemCaseSensitive(instruction_status_updateJSON, "status_type");
    if (cJSON_IsNull(status_type)) {
        status_type = NULL;
    }
    if (!status_type) {
        goto end;
    }

    
    status_type_local_nonprim = instruction_status_parseFromJSON(status_type); //custom

    // instruction_status_update->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(instruction_status_updateJSON, "timestamp");
    if (cJSON_IsNull(timestamp)) {
        timestamp = NULL;
    }
    if (!timestamp) {
        goto end;
    }

    
    if(!cJSON_IsString(timestamp) && !cJSON_IsNull(timestamp))
    {
    goto end; //DateTime
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (instruction_id && !cJSON_IsNull(instruction_id)) instruction_id_local_str = strdup(instruction_id->valuestring);
    if (timestamp && !cJSON_IsNull(timestamp)) timestamp_local_str = strdup(timestamp->valuestring);

    instruction_status_update_local_var = instruction_status_update_create_internal (
        message_type_local_str,
        message_id_local_str,
        instruction_id_local_str,
        status_type_local_nonprim,
        timestamp_local_str
        );

    if (!instruction_status_update_local_var) {
        goto end;
    }

    return instruction_status_update_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (instruction_id_local_str) {
        free(instruction_id_local_str);
        instruction_id_local_str = NULL;
    }
    if (status_type_local_nonprim) {
        status_type_local_nonprim = 0;
    }
    if (timestamp_local_str) {
        free(timestamp_local_str);
        timestamp_local_str = NULL;
    }
    return NULL;

}
