#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ombc_status.h>



static ombc_status_t *ombc_status_create_internal(
    char *message_type,
    char *message_id,
    char *active_operation_mode_id,
    double *operation_mode_factor,
    char *previous_operation_mode_id,
    char *transition_timestamp
    ) {
    ombc_status_t *ombc_status_local_var = malloc(sizeof(ombc_status_t));
    if (!ombc_status_local_var) {
        return NULL;
    }
    memset(ombc_status_local_var, 0, sizeof(ombc_status_t));
    ombc_status_local_var->_library_owned = 1;
    ombc_status_local_var->message_type = message_type;
    ombc_status_local_var->message_id = message_id;
    ombc_status_local_var->active_operation_mode_id = active_operation_mode_id;
    ombc_status_local_var->operation_mode_factor = operation_mode_factor;
    ombc_status_local_var->previous_operation_mode_id = previous_operation_mode_id;
    ombc_status_local_var->transition_timestamp = transition_timestamp;
    return ombc_status_local_var;
}

__attribute__((deprecated)) ombc_status_t *ombc_status_create(
    char *message_type,
    char *message_id,
    char *active_operation_mode_id,
    double *operation_mode_factor,
    char *previous_operation_mode_id,
    char *transition_timestamp
    ) {
    double *operation_mode_factor_copy = NULL;
    if (operation_mode_factor) {
        operation_mode_factor_copy = malloc(sizeof(double));
        if (operation_mode_factor_copy) *operation_mode_factor_copy = *operation_mode_factor;
    }
    ombc_status_t *result = ombc_status_create_internal (
        message_type,
        message_id,
        active_operation_mode_id,
        operation_mode_factor_copy,
        previous_operation_mode_id,
        transition_timestamp
        );
    if (!result) {
        free(operation_mode_factor_copy);
    }
    return result;
}

void ombc_status_free(ombc_status_t *ombc_status) {
    if(NULL == ombc_status){
        return ;
    }
    if(ombc_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ombc_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ombc_status->message_type) {
        free(ombc_status->message_type);
        ombc_status->message_type = NULL;
    }
    if (ombc_status->message_id) {
        free(ombc_status->message_id);
        ombc_status->message_id = NULL;
    }
    if (ombc_status->active_operation_mode_id) {
        free(ombc_status->active_operation_mode_id);
        ombc_status->active_operation_mode_id = NULL;
    }
    if (ombc_status->operation_mode_factor) {
        free(ombc_status->operation_mode_factor);
        ombc_status->operation_mode_factor = NULL;
    }
    if (ombc_status->previous_operation_mode_id) {
        free(ombc_status->previous_operation_mode_id);
        ombc_status->previous_operation_mode_id = NULL;
    }
    if (ombc_status->transition_timestamp) {
        free(ombc_status->transition_timestamp);
        ombc_status->transition_timestamp = NULL;
    }
    free(ombc_status);
}

cJSON *ombc_status_convertToJSON(ombc_status_t *ombc_status) {
    cJSON *item = cJSON_CreateObject();

    // ombc_status->message_type
    if (!ombc_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ombc_status->message_type) == NULL) {
    goto fail; //String
    }


    // ombc_status->message_id
    if (!ombc_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ombc_status->message_id) == NULL) {
    goto fail; //String
    }


    // ombc_status->active_operation_mode_id
    if (!ombc_status->active_operation_mode_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "active_operation_mode_id", ombc_status->active_operation_mode_id) == NULL) {
    goto fail; //String
    }


    // ombc_status->operation_mode_factor
    if (!ombc_status->operation_mode_factor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operation_mode_factor", *ombc_status->operation_mode_factor) == NULL) {
    goto fail; //Numeric
    }


    // ombc_status->previous_operation_mode_id
    if(ombc_status->previous_operation_mode_id) {
    if(cJSON_AddStringToObject(item, "previous_operation_mode_id", ombc_status->previous_operation_mode_id) == NULL) {
    goto fail; //String
    }
    }


    // ombc_status->transition_timestamp
    if(ombc_status->transition_timestamp) {
    if(cJSON_AddStringToObject(item, "transition_timestamp", ombc_status->transition_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ombc_status_t *ombc_status_parseFromJSON(cJSON *ombc_statusJSON){

    ombc_status_t *ombc_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *active_operation_mode_id_local_str = NULL;

    // define the local variable for ombc_status->operation_mode_factor
    double *operation_mode_factor_local_var = NULL;

    char *previous_operation_mode_id_local_str = NULL;

    char *transition_timestamp_local_str = NULL;

    // ombc_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "message_type");
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

    // ombc_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "message_id");
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

    // ombc_status->active_operation_mode_id
    cJSON *active_operation_mode_id = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "active_operation_mode_id");
    if (cJSON_IsNull(active_operation_mode_id)) {
        active_operation_mode_id = NULL;
    }
    if (!active_operation_mode_id) {
        goto end;
    }

    
    if(!cJSON_IsString(active_operation_mode_id))
    {
    goto end; //String
    }

    // ombc_status->operation_mode_factor
    cJSON *operation_mode_factor = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "operation_mode_factor");
    if (cJSON_IsNull(operation_mode_factor)) {
        operation_mode_factor = NULL;
    }
    if (!operation_mode_factor) {
        goto end;
    }

    
    if(!cJSON_IsNumber(operation_mode_factor))
    {
    goto end; //Numeric
    }
    operation_mode_factor_local_var = malloc(sizeof(double));
    if(!operation_mode_factor_local_var)
    {
        goto end;
    }
    *operation_mode_factor_local_var = operation_mode_factor->valuedouble;

    // ombc_status->previous_operation_mode_id
    cJSON *previous_operation_mode_id = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "previous_operation_mode_id");
    if (cJSON_IsNull(previous_operation_mode_id)) {
        previous_operation_mode_id = NULL;
    }
    if (previous_operation_mode_id) { 
    if(!cJSON_IsString(previous_operation_mode_id) && !cJSON_IsNull(previous_operation_mode_id))
    {
    goto end; //String
    }
    }

    // ombc_status->transition_timestamp
    cJSON *transition_timestamp = cJSON_GetObjectItemCaseSensitive(ombc_statusJSON, "transition_timestamp");
    if (cJSON_IsNull(transition_timestamp)) {
        transition_timestamp = NULL;
    }
    if (transition_timestamp) { 
    if(!cJSON_IsString(transition_timestamp) && !cJSON_IsNull(transition_timestamp))
    {
    goto end; //DateTime
    }
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (active_operation_mode_id && !cJSON_IsNull(active_operation_mode_id)) active_operation_mode_id_local_str = strdup(active_operation_mode_id->valuestring);
    if (previous_operation_mode_id && !cJSON_IsNull(previous_operation_mode_id)) previous_operation_mode_id_local_str = strdup(previous_operation_mode_id->valuestring);
    if (transition_timestamp && !cJSON_IsNull(transition_timestamp)) transition_timestamp_local_str = strdup(transition_timestamp->valuestring);

    ombc_status_local_var = ombc_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        active_operation_mode_id_local_str,
        operation_mode_factor_local_var,
        previous_operation_mode_id_local_str,
        transition_timestamp_local_str
        );

    if (!ombc_status_local_var) {
        goto end;
    }

    return ombc_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (active_operation_mode_id_local_str) {
        free(active_operation_mode_id_local_str);
        active_operation_mode_id_local_str = NULL;
    }
    if (operation_mode_factor_local_var) {
        free(operation_mode_factor_local_var);
        operation_mode_factor_local_var = NULL;
    }
    if (previous_operation_mode_id_local_str) {
        free(previous_operation_mode_id_local_str);
        previous_operation_mode_id_local_str = NULL;
    }
    if (transition_timestamp_local_str) {
        free(transition_timestamp_local_str);
        transition_timestamp_local_str = NULL;
    }
    return NULL;

}
