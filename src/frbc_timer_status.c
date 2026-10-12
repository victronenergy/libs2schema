#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_timer_status.h>



static frbc_timer_status_t *frbc_timer_status_create_internal(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *actuator_id,
    char *finished_at
    ) {
    frbc_timer_status_t *frbc_timer_status_local_var = malloc(sizeof(frbc_timer_status_t));
    if (!frbc_timer_status_local_var) {
        return NULL;
    }
    memset(frbc_timer_status_local_var, 0, sizeof(frbc_timer_status_t));
    frbc_timer_status_local_var->_library_owned = 1;
    frbc_timer_status_local_var->message_type = message_type;
    frbc_timer_status_local_var->message_id = message_id;
    frbc_timer_status_local_var->timer_id = timer_id;
    frbc_timer_status_local_var->actuator_id = actuator_id;
    frbc_timer_status_local_var->finished_at = finished_at;
    return frbc_timer_status_local_var;
}

__attribute__((deprecated)) frbc_timer_status_t *frbc_timer_status_create(
    char *message_type,
    char *message_id,
    char *timer_id,
    char *actuator_id,
    char *finished_at
    ) {
    frbc_timer_status_t *result = frbc_timer_status_create_internal (
        message_type,
        message_id,
        timer_id,
        actuator_id,
        finished_at
        );
    if (!result) {
    }
    return result;
}

void frbc_timer_status_free(frbc_timer_status_t *frbc_timer_status) {
    if(NULL == frbc_timer_status){
        return ;
    }
    if(frbc_timer_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_timer_status_free");
        return ;
    }
    if (frbc_timer_status->message_type) {
        free(frbc_timer_status->message_type);
        frbc_timer_status->message_type = NULL;
    }
    if (frbc_timer_status->message_id) {
        free(frbc_timer_status->message_id);
        frbc_timer_status->message_id = NULL;
    }
    if (frbc_timer_status->timer_id) {
        free(frbc_timer_status->timer_id);
        frbc_timer_status->timer_id = NULL;
    }
    if (frbc_timer_status->actuator_id) {
        free(frbc_timer_status->actuator_id);
        frbc_timer_status->actuator_id = NULL;
    }
    if (frbc_timer_status->finished_at) {
        free(frbc_timer_status->finished_at);
        frbc_timer_status->finished_at = NULL;
    }
    free(frbc_timer_status);
}

cJSON *frbc_timer_status_convertToJSON(frbc_timer_status_t *frbc_timer_status) {
    cJSON *item = cJSON_CreateObject();

    // frbc_timer_status->message_type
    if (!frbc_timer_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_timer_status->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_timer_status->message_id
    if (!frbc_timer_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_timer_status->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_timer_status->timer_id
    if (!frbc_timer_status->timer_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "timer_id", frbc_timer_status->timer_id) == NULL) {
    goto fail; //String
    }


    // frbc_timer_status->actuator_id
    if (!frbc_timer_status->actuator_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "actuator_id", frbc_timer_status->actuator_id) == NULL) {
    goto fail; //String
    }


    // frbc_timer_status->finished_at
    if (!frbc_timer_status->finished_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "finished_at", frbc_timer_status->finished_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_timer_status_t *frbc_timer_status_parseFromJSON(cJSON *frbc_timer_statusJSON){

    frbc_timer_status_t *frbc_timer_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *timer_id_local_str = NULL;

    char *actuator_id_local_str = NULL;

    char *finished_at_local_str = NULL;

    // frbc_timer_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_timer_statusJSON, "message_type");
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

    // frbc_timer_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_timer_statusJSON, "message_id");
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

    // frbc_timer_status->timer_id
    cJSON *timer_id = cJSON_GetObjectItemCaseSensitive(frbc_timer_statusJSON, "timer_id");
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

    // frbc_timer_status->actuator_id
    cJSON *actuator_id = cJSON_GetObjectItemCaseSensitive(frbc_timer_statusJSON, "actuator_id");
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

    // frbc_timer_status->finished_at
    cJSON *finished_at = cJSON_GetObjectItemCaseSensitive(frbc_timer_statusJSON, "finished_at");
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
    if (actuator_id && !cJSON_IsNull(actuator_id)) actuator_id_local_str = strdup(actuator_id->valuestring);
    if (finished_at && !cJSON_IsNull(finished_at)) finished_at_local_str = strdup(finished_at->valuestring);

    frbc_timer_status_local_var = frbc_timer_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        timer_id_local_str,
        actuator_id_local_str,
        finished_at_local_str
        );

    if (!frbc_timer_status_local_var) {
        goto end;
    }

    return frbc_timer_status_local_var;
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
    if (actuator_id_local_str) {
        free(actuator_id_local_str);
        actuator_id_local_str = NULL;
    }
    if (finished_at_local_str) {
        free(finished_at_local_str);
        finished_at_local_str = NULL;
    }
    return NULL;

}
