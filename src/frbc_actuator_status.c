#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_actuator_status.h>



static frbc_actuator_status_t *frbc_actuator_status_create_internal(
    char *message_type,
    char *message_id,
    char *actuator_id,
    char *active_operation_mode_id,
    double *operation_mode_factor,
    char *previous_operation_mode_id,
    char *transition_timestamp
    ) {
    frbc_actuator_status_t *frbc_actuator_status_local_var = malloc(sizeof(frbc_actuator_status_t));
    if (!frbc_actuator_status_local_var) {
        return NULL;
    }
    memset(frbc_actuator_status_local_var, 0, sizeof(frbc_actuator_status_t));
    frbc_actuator_status_local_var->_library_owned = 1;
    frbc_actuator_status_local_var->message_type = message_type;
    frbc_actuator_status_local_var->message_id = message_id;
    frbc_actuator_status_local_var->actuator_id = actuator_id;
    frbc_actuator_status_local_var->active_operation_mode_id = active_operation_mode_id;
    frbc_actuator_status_local_var->operation_mode_factor = operation_mode_factor;
    frbc_actuator_status_local_var->previous_operation_mode_id = previous_operation_mode_id;
    frbc_actuator_status_local_var->transition_timestamp = transition_timestamp;
    return frbc_actuator_status_local_var;
}

__attribute__((deprecated)) frbc_actuator_status_t *frbc_actuator_status_create(
    char *message_type,
    char *message_id,
    char *actuator_id,
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
    frbc_actuator_status_t *result = frbc_actuator_status_create_internal (
        message_type,
        message_id,
        actuator_id,
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

void frbc_actuator_status_free(frbc_actuator_status_t *frbc_actuator_status) {
    if(NULL == frbc_actuator_status){
        return ;
    }
    if(frbc_actuator_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_actuator_status_free");
        return ;
    }
    if (frbc_actuator_status->message_type) {
        free(frbc_actuator_status->message_type);
        frbc_actuator_status->message_type = NULL;
    }
    if (frbc_actuator_status->message_id) {
        free(frbc_actuator_status->message_id);
        frbc_actuator_status->message_id = NULL;
    }
    if (frbc_actuator_status->actuator_id) {
        free(frbc_actuator_status->actuator_id);
        frbc_actuator_status->actuator_id = NULL;
    }
    if (frbc_actuator_status->active_operation_mode_id) {
        free(frbc_actuator_status->active_operation_mode_id);
        frbc_actuator_status->active_operation_mode_id = NULL;
    }
    if (frbc_actuator_status->operation_mode_factor) {
        free(frbc_actuator_status->operation_mode_factor);
        frbc_actuator_status->operation_mode_factor = NULL;
    }
    if (frbc_actuator_status->previous_operation_mode_id) {
        free(frbc_actuator_status->previous_operation_mode_id);
        frbc_actuator_status->previous_operation_mode_id = NULL;
    }
    if (frbc_actuator_status->transition_timestamp) {
        free(frbc_actuator_status->transition_timestamp);
        frbc_actuator_status->transition_timestamp = NULL;
    }
    free(frbc_actuator_status);
}

cJSON *frbc_actuator_status_convertToJSON(frbc_actuator_status_t *frbc_actuator_status) {
    cJSON *item = cJSON_CreateObject();

    // frbc_actuator_status->message_type
    if (!frbc_actuator_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_actuator_status->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_actuator_status->message_id
    if (!frbc_actuator_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_actuator_status->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_actuator_status->actuator_id
    if (!frbc_actuator_status->actuator_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "actuator_id", frbc_actuator_status->actuator_id) == NULL) {
    goto fail; //String
    }


    // frbc_actuator_status->active_operation_mode_id
    if (!frbc_actuator_status->active_operation_mode_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "active_operation_mode_id", frbc_actuator_status->active_operation_mode_id) == NULL) {
    goto fail; //String
    }


    // frbc_actuator_status->operation_mode_factor
    if (!frbc_actuator_status->operation_mode_factor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operation_mode_factor", *frbc_actuator_status->operation_mode_factor) == NULL) {
    goto fail; //Numeric
    }


    // frbc_actuator_status->previous_operation_mode_id
    if(frbc_actuator_status->previous_operation_mode_id) {
    if(cJSON_AddStringToObject(item, "previous_operation_mode_id", frbc_actuator_status->previous_operation_mode_id) == NULL) {
    goto fail; //String
    }
    }


    // frbc_actuator_status->transition_timestamp
    if(frbc_actuator_status->transition_timestamp) {
    if(cJSON_AddStringToObject(item, "transition_timestamp", frbc_actuator_status->transition_timestamp) == NULL) {
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

frbc_actuator_status_t *frbc_actuator_status_parseFromJSON(cJSON *frbc_actuator_statusJSON){

    frbc_actuator_status_t *frbc_actuator_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *actuator_id_local_str = NULL;

    char *active_operation_mode_id_local_str = NULL;

    // define the local variable for frbc_actuator_status->operation_mode_factor
    double *operation_mode_factor_local_var = NULL;

    char *previous_operation_mode_id_local_str = NULL;

    char *transition_timestamp_local_str = NULL;

    // frbc_actuator_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "message_type");
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

    // frbc_actuator_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "message_id");
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

    // frbc_actuator_status->actuator_id
    cJSON *actuator_id = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "actuator_id");
    if (cJSON_IsNull(actuator_id)) {
        actuator_id = NULL;
    }
    if (!actuator_id) {
        goto end;
    }

    
    if(!cJSON_IsString(actuator_id))
    {
    goto end; //String
    }

    // frbc_actuator_status->active_operation_mode_id
    cJSON *active_operation_mode_id = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "active_operation_mode_id");
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

    // frbc_actuator_status->operation_mode_factor
    cJSON *operation_mode_factor = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "operation_mode_factor");
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

    // frbc_actuator_status->previous_operation_mode_id
    cJSON *previous_operation_mode_id = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "previous_operation_mode_id");
    if (cJSON_IsNull(previous_operation_mode_id)) {
        previous_operation_mode_id = NULL;
    }
    if (previous_operation_mode_id) { 
    if(!cJSON_IsString(previous_operation_mode_id) && !cJSON_IsNull(previous_operation_mode_id))
    {
    goto end; //String
    }
    }

    // frbc_actuator_status->transition_timestamp
    cJSON *transition_timestamp = cJSON_GetObjectItemCaseSensitive(frbc_actuator_statusJSON, "transition_timestamp");
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
    if (actuator_id && !cJSON_IsNull(actuator_id)) actuator_id_local_str = strdup(actuator_id->valuestring);
    if (active_operation_mode_id && !cJSON_IsNull(active_operation_mode_id)) active_operation_mode_id_local_str = strdup(active_operation_mode_id->valuestring);
    if (previous_operation_mode_id && !cJSON_IsNull(previous_operation_mode_id)) previous_operation_mode_id_local_str = strdup(previous_operation_mode_id->valuestring);
    if (transition_timestamp && !cJSON_IsNull(transition_timestamp)) transition_timestamp_local_str = strdup(transition_timestamp->valuestring);

    frbc_actuator_status_local_var = frbc_actuator_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        actuator_id_local_str,
        active_operation_mode_id_local_str,
        operation_mode_factor_local_var,
        previous_operation_mode_id_local_str,
        transition_timestamp_local_str
        );

    if (!frbc_actuator_status_local_var) {
        goto end;
    }

    return frbc_actuator_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (actuator_id_local_str) {
        free(actuator_id_local_str);
        actuator_id_local_str = NULL;
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
