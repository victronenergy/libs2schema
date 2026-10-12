#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/select_control_type.h>



static select_control_type_t *select_control_type_create_internal(
    char *message_type,
    char *message_id,
    s2_control_type__e control_type
    ) {
    select_control_type_t *select_control_type_local_var = malloc(sizeof(select_control_type_t));
    if (!select_control_type_local_var) {
        return NULL;
    }
    memset(select_control_type_local_var, 0, sizeof(select_control_type_t));
    select_control_type_local_var->_library_owned = 1;
    select_control_type_local_var->message_type = message_type;
    select_control_type_local_var->message_id = message_id;
    select_control_type_local_var->control_type = control_type;
    return select_control_type_local_var;
}

__attribute__((deprecated)) select_control_type_t *select_control_type_create(
    char *message_type,
    char *message_id,
    s2_control_type__e control_type
    ) {
    select_control_type_t *result = select_control_type_create_internal (
        message_type,
        message_id,
        control_type
        );
    if (!result) {
    }
    return result;
}

void select_control_type_free(select_control_type_t *select_control_type) {
    if(NULL == select_control_type){
        return ;
    }
    if(select_control_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "select_control_type_free");
        return ;
    }
    if (select_control_type->message_type) {
        free(select_control_type->message_type);
        select_control_type->message_type = NULL;
    }
    if (select_control_type->message_id) {
        free(select_control_type->message_id);
        select_control_type->message_id = NULL;
    }
    free(select_control_type);
}

cJSON *select_control_type_convertToJSON(select_control_type_t *select_control_type) {
    cJSON *item = cJSON_CreateObject();

    // select_control_type->message_type
    if (!select_control_type->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", select_control_type->message_type) == NULL) {
    goto fail; //String
    }


    // select_control_type->message_id
    if (!select_control_type->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", select_control_type->message_id) == NULL) {
    goto fail; //String
    }


    // select_control_type->control_type
    if (s2_control_type__NULL == select_control_type->control_type) {
        goto fail;
    }
    cJSON *control_type_local_JSON = control_type_convertToJSON(select_control_type->control_type);
    if(control_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "control_type", control_type_local_JSON);
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

select_control_type_t *select_control_type_parseFromJSON(cJSON *select_control_typeJSON){

    select_control_type_t *select_control_type_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local variable for select_control_type->control_type
    s2_control_type__e control_type_local_nonprim = 0;

    // select_control_type->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(select_control_typeJSON, "message_type");
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

    // select_control_type->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(select_control_typeJSON, "message_id");
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

    // select_control_type->control_type
    cJSON *control_type = cJSON_GetObjectItemCaseSensitive(select_control_typeJSON, "control_type");
    if (cJSON_IsNull(control_type)) {
        control_type = NULL;
    }
    if (!control_type) {
        goto end;
    }

    
    control_type_local_nonprim = control_type_parseFromJSON(control_type); //custom


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);

    select_control_type_local_var = select_control_type_create_internal (
        message_type_local_str,
        message_id_local_str,
        control_type_local_nonprim
        );

    if (!select_control_type_local_var) {
        goto end;
    }

    return select_control_type_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (control_type_local_nonprim) {
        control_type_local_nonprim = 0;
    }
    return NULL;

}
