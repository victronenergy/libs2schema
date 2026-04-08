#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/handshake.h>



static handshake_t *handshake_create_internal(
    char *message_type,
    char *message_id,
    s2_energy_management_role__e role,
    list_t *supported_protocol_versions
    ) {
    handshake_t *handshake_local_var = malloc(sizeof(handshake_t));
    if (!handshake_local_var) {
        return NULL;
    }
    memset(handshake_local_var, 0, sizeof(handshake_t));
    handshake_local_var->_library_owned = 1;
    handshake_local_var->message_type = message_type;
    handshake_local_var->message_id = message_id;
    handshake_local_var->role = role;
    handshake_local_var->supported_protocol_versions = supported_protocol_versions;
    return handshake_local_var;
}

__attribute__((deprecated)) handshake_t *handshake_create(
    char *message_type,
    char *message_id,
    s2_energy_management_role__e role,
    list_t *supported_protocol_versions
    ) {
    handshake_t *result = handshake_create_internal (
        message_type,
        message_id,
        role,
        supported_protocol_versions
        );
    if (!result) {
    }
    return result;
}

void handshake_free(handshake_t *handshake) {
    if(NULL == handshake){
        return ;
    }
    if(handshake->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "handshake_free");
        return ;
    }
    listEntry_t *listEntry;
    if (handshake->message_type) {
        free(handshake->message_type);
        handshake->message_type = NULL;
    }
    if (handshake->message_id) {
        free(handshake->message_id);
        handshake->message_id = NULL;
    }
    if (handshake->supported_protocol_versions) {
        list_ForEach(listEntry, handshake->supported_protocol_versions) {
            free(listEntry->data);
        }
        list_freeList(handshake->supported_protocol_versions);
        handshake->supported_protocol_versions = NULL;
    }
    free(handshake);
}

cJSON *handshake_convertToJSON(handshake_t *handshake) {
    cJSON *item = cJSON_CreateObject();

    // handshake->message_type
    if (!handshake->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", handshake->message_type) == NULL) {
    goto fail; //String
    }


    // handshake->message_id
    if (!handshake->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", handshake->message_id) == NULL) {
    goto fail; //String
    }


    // handshake->role
    if (s2_energy_management_role__NULL == handshake->role) {
        goto fail;
    }
    cJSON *role_local_JSON = energy_management_role_convertToJSON(handshake->role);
    if(role_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "role", role_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // handshake->supported_protocol_versions
    if(handshake->supported_protocol_versions) {
    cJSON *supported_protocol_versions = cJSON_AddArrayToObject(item, "supported_protocol_versions");
    if(supported_protocol_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *supported_protocol_versionsListEntry;
    list_ForEach(supported_protocol_versionsListEntry, handshake->supported_protocol_versions) {
    if(cJSON_AddStringToObject(supported_protocol_versions, "", supported_protocol_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

handshake_t *handshake_parseFromJSON(cJSON *handshakeJSON){

    handshake_t *handshake_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local variable for handshake->role
    s2_energy_management_role__e role_local_nonprim = 0;

    // define the local list for handshake->supported_protocol_versions
    list_t *supported_protocol_versionsList = NULL;

    // handshake->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(handshakeJSON, "message_type");
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

    // handshake->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(handshakeJSON, "message_id");
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

    // handshake->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(handshakeJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    role_local_nonprim = energy_management_role_parseFromJSON(role); //custom

    // handshake->supported_protocol_versions
    cJSON *supported_protocol_versions = cJSON_GetObjectItemCaseSensitive(handshakeJSON, "supported_protocol_versions");
    if (cJSON_IsNull(supported_protocol_versions)) {
        supported_protocol_versions = NULL;
    }
    if (supported_protocol_versions) { 
    cJSON *supported_protocol_versions_local = NULL;
    if(!cJSON_IsArray(supported_protocol_versions)) {
        goto end;//primitive container
    }
    supported_protocol_versionsList = list_createList();

    cJSON_ArrayForEach(supported_protocol_versions_local, supported_protocol_versions)
    {
        if(!cJSON_IsString(supported_protocol_versions_local))
        {
            goto end;
        }
        list_addElement(supported_protocol_versionsList , strdup(supported_protocol_versions_local->valuestring));
    }
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);

    handshake_local_var = handshake_create_internal (
        message_type_local_str,
        message_id_local_str,
        role_local_nonprim,
        supported_protocol_versions ? supported_protocol_versionsList : NULL
        );

    if (!handshake_local_var) {
        goto end;
    }

    return handshake_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (role_local_nonprim) {
        role_local_nonprim = 0;
    }
    if (supported_protocol_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_protocol_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(supported_protocol_versionsList);
        supported_protocol_versionsList = NULL;
    }
    return NULL;

}
