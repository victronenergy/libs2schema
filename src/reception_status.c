#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/reception_status.h>



static reception_status_t *reception_status_create_internal(
    char *message_type,
    char *subject_message_id,
    s2_reception_status_values__e status,
    char *diagnostic_label
    ) {
    reception_status_t *reception_status_local_var = malloc(sizeof(reception_status_t));
    if (!reception_status_local_var) {
        return NULL;
    }
    memset(reception_status_local_var, 0, sizeof(reception_status_t));
    reception_status_local_var->_library_owned = 1;
    reception_status_local_var->message_type = message_type;
    reception_status_local_var->subject_message_id = subject_message_id;
    reception_status_local_var->status = status;
    reception_status_local_var->diagnostic_label = diagnostic_label;
    return reception_status_local_var;
}

__attribute__((deprecated)) reception_status_t *reception_status_create(
    char *message_type,
    char *subject_message_id,
    s2_reception_status_values__e status,
    char *diagnostic_label
    ) {
    reception_status_t *result = reception_status_create_internal (
        message_type,
        subject_message_id,
        status,
        diagnostic_label
        );
    if (!result) {
    }
    return result;
}

void reception_status_free(reception_status_t *reception_status) {
    if(NULL == reception_status){
        return ;
    }
    if(reception_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reception_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reception_status->message_type) {
        free(reception_status->message_type);
        reception_status->message_type = NULL;
    }
    if (reception_status->subject_message_id) {
        free(reception_status->subject_message_id);
        reception_status->subject_message_id = NULL;
    }
    if (reception_status->diagnostic_label) {
        free(reception_status->diagnostic_label);
        reception_status->diagnostic_label = NULL;
    }
    free(reception_status);
}

cJSON *reception_status_convertToJSON(reception_status_t *reception_status) {
    cJSON *item = cJSON_CreateObject();

    // reception_status->message_type
    if (!reception_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", reception_status->message_type) == NULL) {
    goto fail; //String
    }


    // reception_status->subject_message_id
    if (!reception_status->subject_message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subject_message_id", reception_status->subject_message_id) == NULL) {
    goto fail; //String
    }


    // reception_status->status
    if (s2_reception_status_values__NULL == reception_status->status) {
        goto fail;
    }
    cJSON *status_local_JSON = reception_status_values_convertToJSON(reception_status->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // reception_status->diagnostic_label
    if(reception_status->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", reception_status->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reception_status_t *reception_status_parseFromJSON(cJSON *reception_statusJSON){

    reception_status_t *reception_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *subject_message_id_local_str = NULL;

    // define the local variable for reception_status->status
    s2_reception_status_values__e status_local_nonprim = 0;

    char *diagnostic_label_local_str = NULL;

    // reception_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(reception_statusJSON, "message_type");
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

    // reception_status->subject_message_id
    cJSON *subject_message_id = cJSON_GetObjectItemCaseSensitive(reception_statusJSON, "subject_message_id");
    if (cJSON_IsNull(subject_message_id)) {
        subject_message_id = NULL;
    }
    if (!subject_message_id) {
        goto end;
    }

    
    if(!cJSON_IsString(subject_message_id))
    {
    goto end; //String
    }

    // reception_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(reception_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = reception_status_values_parseFromJSON(status); //custom

    // reception_status->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(reception_statusJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (subject_message_id && !cJSON_IsNull(subject_message_id)) subject_message_id_local_str = strdup(subject_message_id->valuestring);
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    reception_status_local_var = reception_status_create_internal (
        message_type_local_str,
        subject_message_id_local_str,
        status_local_nonprim,
        diagnostic_label_local_str
        );

    if (!reception_status_local_var) {
        goto end;
    }

    return reception_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (subject_message_id_local_str) {
        free(subject_message_id_local_str);
        subject_message_id_local_str = NULL;
    }
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    return NULL;

}
