#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/handshake_response.h>



static handshake_response_t *handshake_response_create_internal(
    char *message_type,
    char *message_id,
    char *selected_protocol_version
    ) {
    handshake_response_t *handshake_response_local_var = malloc(sizeof(handshake_response_t));
    if (!handshake_response_local_var) {
        return NULL;
    }
    memset(handshake_response_local_var, 0, sizeof(handshake_response_t));
    handshake_response_local_var->_library_owned = 1;
    handshake_response_local_var->message_type = message_type;
    handshake_response_local_var->message_id = message_id;
    handshake_response_local_var->selected_protocol_version = selected_protocol_version;
    return handshake_response_local_var;
}

__attribute__((deprecated)) handshake_response_t *handshake_response_create(
    char *message_type,
    char *message_id,
    char *selected_protocol_version
    ) {
    handshake_response_t *result = handshake_response_create_internal (
        message_type,
        message_id,
        selected_protocol_version
        );
    if (!result) {
    }
    return result;
}

void handshake_response_free(handshake_response_t *handshake_response) {
    if(NULL == handshake_response){
        return ;
    }
    if(handshake_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "handshake_response_free");
        return ;
    }
    if (handshake_response->message_type) {
        free(handshake_response->message_type);
        handshake_response->message_type = NULL;
    }
    if (handshake_response->message_id) {
        free(handshake_response->message_id);
        handshake_response->message_id = NULL;
    }
    if (handshake_response->selected_protocol_version) {
        free(handshake_response->selected_protocol_version);
        handshake_response->selected_protocol_version = NULL;
    }
    free(handshake_response);
}

cJSON *handshake_response_convertToJSON(handshake_response_t *handshake_response) {
    cJSON *item = cJSON_CreateObject();

    // handshake_response->message_type
    if (!handshake_response->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", handshake_response->message_type) == NULL) {
    goto fail; //String
    }


    // handshake_response->message_id
    if (!handshake_response->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", handshake_response->message_id) == NULL) {
    goto fail; //String
    }


    // handshake_response->selected_protocol_version
    if (!handshake_response->selected_protocol_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "selected_protocol_version", handshake_response->selected_protocol_version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

handshake_response_t *handshake_response_parseFromJSON(cJSON *handshake_responseJSON){

    handshake_response_t *handshake_response_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *selected_protocol_version_local_str = NULL;

    // handshake_response->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(handshake_responseJSON, "message_type");
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

    // handshake_response->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(handshake_responseJSON, "message_id");
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

    // handshake_response->selected_protocol_version
    cJSON *selected_protocol_version = cJSON_GetObjectItemCaseSensitive(handshake_responseJSON, "selected_protocol_version");
    if (cJSON_IsNull(selected_protocol_version)) {
        selected_protocol_version = NULL;
    }
    if (!selected_protocol_version) {
        goto end;
    }

    
    if(!cJSON_IsString(selected_protocol_version))
    {
    goto end; //String
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (selected_protocol_version && !cJSON_IsNull(selected_protocol_version)) selected_protocol_version_local_str = strdup(selected_protocol_version->valuestring);

    handshake_response_local_var = handshake_response_create_internal (
        message_type_local_str,
        message_id_local_str,
        selected_protocol_version_local_str
        );

    if (!handshake_response_local_var) {
        goto end;
    }

    return handshake_response_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (selected_protocol_version_local_str) {
        free(selected_protocol_version_local_str);
        selected_protocol_version_local_str = NULL;
    }
    return NULL;

}
