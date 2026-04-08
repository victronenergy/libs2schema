#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/revoke_object.h>



static revoke_object_t *revoke_object_create_internal(
    char *message_type,
    char *message_id,
    s2_revokable_objects__e object_type,
    char *object_id
    ) {
    revoke_object_t *revoke_object_local_var = malloc(sizeof(revoke_object_t));
    if (!revoke_object_local_var) {
        return NULL;
    }
    memset(revoke_object_local_var, 0, sizeof(revoke_object_t));
    revoke_object_local_var->_library_owned = 1;
    revoke_object_local_var->message_type = message_type;
    revoke_object_local_var->message_id = message_id;
    revoke_object_local_var->object_type = object_type;
    revoke_object_local_var->object_id = object_id;
    return revoke_object_local_var;
}

__attribute__((deprecated)) revoke_object_t *revoke_object_create(
    char *message_type,
    char *message_id,
    s2_revokable_objects__e object_type,
    char *object_id
    ) {
    revoke_object_t *result = revoke_object_create_internal (
        message_type,
        message_id,
        object_type,
        object_id
        );
    if (!result) {
    }
    return result;
}

void revoke_object_free(revoke_object_t *revoke_object) {
    if(NULL == revoke_object){
        return ;
    }
    if(revoke_object->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_object_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revoke_object->message_type) {
        free(revoke_object->message_type);
        revoke_object->message_type = NULL;
    }
    if (revoke_object->message_id) {
        free(revoke_object->message_id);
        revoke_object->message_id = NULL;
    }
    if (revoke_object->object_id) {
        free(revoke_object->object_id);
        revoke_object->object_id = NULL;
    }
    free(revoke_object);
}

cJSON *revoke_object_convertToJSON(revoke_object_t *revoke_object) {
    cJSON *item = cJSON_CreateObject();

    // revoke_object->message_type
    if (!revoke_object->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", revoke_object->message_type) == NULL) {
    goto fail; //String
    }


    // revoke_object->message_id
    if (!revoke_object->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", revoke_object->message_id) == NULL) {
    goto fail; //String
    }


    // revoke_object->object_type
    if (s2_revokable_objects__NULL == revoke_object->object_type) {
        goto fail;
    }
    cJSON *object_type_local_JSON = revokable_objects_convertToJSON(revoke_object->object_type);
    if(object_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "object_type", object_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // revoke_object->object_id
    if (!revoke_object->object_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "object_id", revoke_object->object_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revoke_object_t *revoke_object_parseFromJSON(cJSON *revoke_objectJSON){

    revoke_object_t *revoke_object_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local variable for revoke_object->object_type
    s2_revokable_objects__e object_type_local_nonprim = 0;

    char *object_id_local_str = NULL;

    // revoke_object->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(revoke_objectJSON, "message_type");
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

    // revoke_object->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(revoke_objectJSON, "message_id");
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

    // revoke_object->object_type
    cJSON *object_type = cJSON_GetObjectItemCaseSensitive(revoke_objectJSON, "object_type");
    if (cJSON_IsNull(object_type)) {
        object_type = NULL;
    }
    if (!object_type) {
        goto end;
    }

    
    object_type_local_nonprim = revokable_objects_parseFromJSON(object_type); //custom

    // revoke_object->object_id
    cJSON *object_id = cJSON_GetObjectItemCaseSensitive(revoke_objectJSON, "object_id");
    if (cJSON_IsNull(object_id)) {
        object_id = NULL;
    }
    if (!object_id) {
        goto end;
    }

    
    if(!cJSON_IsString(object_id))
    {
    goto end; //String
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (object_id && !cJSON_IsNull(object_id)) object_id_local_str = strdup(object_id->valuestring);

    revoke_object_local_var = revoke_object_create_internal (
        message_type_local_str,
        message_id_local_str,
        object_type_local_nonprim,
        object_id_local_str
        );

    if (!revoke_object_local_var) {
        goto end;
    }

    return revoke_object_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (object_type_local_nonprim) {
        object_type_local_nonprim = 0;
    }
    if (object_id_local_str) {
        free(object_id_local_str);
        object_id_local_str = NULL;
    }
    return NULL;

}
