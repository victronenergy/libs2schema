#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ombc_timer_status.h>



static ombc_timer_status_t *ombc_timer_status_create_internal(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *finished_at
    ) {
    ombc_timer_status_t *ombc_timer_status_local_var = malloc(sizeof(ombc_timer_status_t));
    if (!ombc_timer_status_local_var) {
        return NULL;
    }
    memset(ombc_timer_status_local_var, 0, sizeof(ombc_timer_status_t));
    ombc_timer_status_local_var->_library_owned = 1;
    ombc_timer_status_local_var->message_type = message_type;
    ombc_timer_status_local_var->message_id = message_id;
    ombc_timer_status_local_var->timer_id = timer_id;
    ombc_timer_status_local_var->finished_at = finished_at;
    return ombc_timer_status_local_var;
}

__attribute__((deprecated)) ombc_timer_status_t *ombc_timer_status_create(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *finished_at
    ) {
    ombc_timer_status_t *result = ombc_timer_status_create_internal (
        message_type,
        message_id,
        timer_id,
        finished_at
        );
    if (!result) {
    }
    return result;
}

void ombc_timer_status_free(ombc_timer_status_t *ombc_timer_status) {
    if(NULL == ombc_timer_status){
        return ;
    }
    if(ombc_timer_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ombc_timer_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ombc_timer_status->message_type) {
        free(ombc_timer_status->message_type);
        ombc_timer_status->message_type = NULL;
    }
    if (ombc_timer_status->message_id) {
        free(ombc_timer_status->message_id);
        ombc_timer_status->message_id = NULL;
    }
    if (ombc_timer_status->timer_id) {
        free(ombc_timer_status->timer_id);
        ombc_timer_status->timer_id = NULL;
    }
    if (ombc_timer_status->finished_at) {
        free(ombc_timer_status->finished_at);
        ombc_timer_status->finished_at = NULL;
    }
    free(ombc_timer_status);
}

cJSON *ombc_timer_status_convertToJSON(ombc_timer_status_t *ombc_timer_status) {
    cJSON *item = cJSON_CreateObject();

    // ombc_timer_status->message_type
    if (!ombc_timer_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ombc_timer_status->message_type) == NULL) {
    goto fail; //String
    }


    // ombc_timer_status->message_id
    if (!ombc_timer_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ombc_timer_status->message_id) == NULL) {
    goto fail; //String
    }


    // ombc_timer_status->timer_id
    if (!ombc_timer_status->timer_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "timer_id", ombc_timer_status->timer_id) == NULL) {
    goto fail; //String
    }


    // ombc_timer_status->finished_at
    if (!ombc_timer_status->finished_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "finished_at", ombc_timer_status->finished_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ombc_timer_status_t *ombc_timer_status_parseFromJSON(cJSON *ombc_timer_statusJSON){

    ombc_timer_status_t *ombc_timer_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *timer_id_local_str = NULL;

    char *finished_at_local_str = NULL;

    // ombc_timer_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ombc_timer_statusJSON, "message_type");
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

    // ombc_timer_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ombc_timer_statusJSON, "message_id");
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

    // ombc_timer_status->timer_id
    cJSON *timer_id = cJSON_GetObjectItemCaseSensitive(ombc_timer_statusJSON, "timer_id");
    if (cJSON_IsNull(timer_id)) {
        timer_id = NULL;
    }
    if (!timer_id) {
        goto end;
    }

    
    if(!cJSON_IsString(timer_id))
    {
    goto end; //String
    }

    // ombc_timer_status->finished_at
    cJSON *finished_at = cJSON_GetObjectItemCaseSensitive(ombc_timer_statusJSON, "finished_at");
    if (cJSON_IsNull(finished_at)) {
        finished_at = NULL;
    }
    if (!finished_at) {
        goto end;
    }

    
    if(!cJSON_IsString(finished_at) && !cJSON_IsNull(finished_at))
    {
    goto end; //DateTime
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (timer_id && !cJSON_IsNull(timer_id)) timer_id_local_str = strdup(timer_id->valuestring);
    if (finished_at && !cJSON_IsNull(finished_at)) finished_at_local_str = strdup(finished_at->valuestring);

    ombc_timer_status_local_var = ombc_timer_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        timer_id_local_str,
        finished_at_local_str
        );

    if (!ombc_timer_status_local_var) {
        goto end;
    }

    return ombc_timer_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (timer_id_local_str) {
        free(timer_id_local_str);
        timer_id_local_str = NULL;
    }
    if (finished_at_local_str) {
        free(finished_at_local_str);
        finished_at_local_str = NULL;
    }
    return NULL;

}
