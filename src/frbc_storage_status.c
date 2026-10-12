#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_storage_status.h>



static frbc_storage_status_t *frbc_storage_status_create_internal(
    char *message_type,
    char *message_id,
    double *present_fill_level
    ) {
    frbc_storage_status_t *frbc_storage_status_local_var = malloc(sizeof(frbc_storage_status_t));
    if (!frbc_storage_status_local_var) {
        return NULL;
    }
    memset(frbc_storage_status_local_var, 0, sizeof(frbc_storage_status_t));
    frbc_storage_status_local_var->_library_owned = 1;
    frbc_storage_status_local_var->message_type = message_type;
    frbc_storage_status_local_var->message_id = message_id;
    frbc_storage_status_local_var->present_fill_level = present_fill_level;
    return frbc_storage_status_local_var;
}

__attribute__((deprecated)) frbc_storage_status_t *frbc_storage_status_create(
    char *message_type,
    char *message_id,
    double *present_fill_level
    ) {
    double *present_fill_level_copy = NULL;
    if (present_fill_level) {
        present_fill_level_copy = malloc(sizeof(double));
        if (present_fill_level_copy) *present_fill_level_copy = *present_fill_level;
    }
    frbc_storage_status_t *result = frbc_storage_status_create_internal (
        message_type,
        message_id,
        present_fill_level_copy
        );
    if (!result) {
        free(present_fill_level_copy);
    }
    return result;
}

void frbc_storage_status_free(frbc_storage_status_t *frbc_storage_status) {
    if(NULL == frbc_storage_status){
        return ;
    }
    if(frbc_storage_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_storage_status_free");
        return ;
    }
    if (frbc_storage_status->message_type) {
        free(frbc_storage_status->message_type);
        frbc_storage_status->message_type = NULL;
    }
    if (frbc_storage_status->message_id) {
        free(frbc_storage_status->message_id);
        frbc_storage_status->message_id = NULL;
    }
    if (frbc_storage_status->present_fill_level) {
        free(frbc_storage_status->present_fill_level);
        frbc_storage_status->present_fill_level = NULL;
    }
    free(frbc_storage_status);
}

cJSON *frbc_storage_status_convertToJSON(frbc_storage_status_t *frbc_storage_status) {
    cJSON *item = cJSON_CreateObject();

    // frbc_storage_status->message_type
    if (!frbc_storage_status->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_storage_status->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_storage_status->message_id
    if (!frbc_storage_status->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_storage_status->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_storage_status->present_fill_level
    if (!frbc_storage_status->present_fill_level) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "present_fill_level", *frbc_storage_status->present_fill_level) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_storage_status_t *frbc_storage_status_parseFromJSON(cJSON *frbc_storage_statusJSON){

    frbc_storage_status_t *frbc_storage_status_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local variable for frbc_storage_status->present_fill_level
    double *present_fill_level_local_var = NULL;

    // frbc_storage_status->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_storage_statusJSON, "message_type");
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

    // frbc_storage_status->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_storage_statusJSON, "message_id");
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

    // frbc_storage_status->present_fill_level
    cJSON *present_fill_level = cJSON_GetObjectItemCaseSensitive(frbc_storage_statusJSON, "present_fill_level");
    if (cJSON_IsNull(present_fill_level)) {
        present_fill_level = NULL;
    }
    if (!present_fill_level) {
        goto end;
    }

    
    if(!cJSON_IsNumber(present_fill_level))
    {
    goto end; //Numeric
    }
    present_fill_level_local_var = malloc(sizeof(double));
    if(!present_fill_level_local_var)
    {
        goto end;
    }
    *present_fill_level_local_var = present_fill_level->valuedouble;


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);

    frbc_storage_status_local_var = frbc_storage_status_create_internal (
        message_type_local_str,
        message_id_local_str,
        present_fill_level_local_var
        );

    if (!frbc_storage_status_local_var) {
        goto end;
    }

    return frbc_storage_status_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (present_fill_level_local_var) {
        free(present_fill_level_local_var);
        present_fill_level_local_var = NULL;
    }
    return NULL;

}
