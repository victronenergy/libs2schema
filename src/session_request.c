#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/session_request.h>



static session_request_t *session_request_create_internal(
    char *message_type,
    char *message_id,
    s2_session_request_type__e request,
    char *diagnostic_label
    ) {
    session_request_t *session_request_local_var = malloc(sizeof(session_request_t));
    if (!session_request_local_var) {
        return NULL;
    }
    memset(session_request_local_var, 0, sizeof(session_request_t));
    session_request_local_var->_library_owned = 1;
    session_request_local_var->message_type = message_type;
    session_request_local_var->message_id = message_id;
    session_request_local_var->request = request;
    session_request_local_var->diagnostic_label = diagnostic_label;
    return session_request_local_var;
}

__attribute__((deprecated)) session_request_t *session_request_create(
    char *message_type,
    char *message_id,
    s2_session_request_type__e request,
    char *diagnostic_label
    ) {
    session_request_t *result = session_request_create_internal (
        message_type,
        message_id,
        request,
        diagnostic_label
        );
    if (!result) {
    }
    return result;
}

void session_request_free(session_request_t *session_request) {
    if(NULL == session_request){
        return ;
    }
    if(session_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "session_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (session_request->message_type) {
        free(session_request->message_type);
        session_request->message_type = NULL;
    }
    if (session_request->message_id) {
        free(session_request->message_id);
        session_request->message_id = NULL;
    }
    if (session_request->diagnostic_label) {
        free(session_request->diagnostic_label);
        session_request->diagnostic_label = NULL;
    }
    free(session_request);
}

cJSON *session_request_convertToJSON(session_request_t *session_request) {
    cJSON *item = cJSON_CreateObject();

    // session_request->message_type
    if (!session_request->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", session_request->message_type) == NULL) {
    goto fail; //String
    }


    // session_request->message_id
    if (!session_request->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", session_request->message_id) == NULL) {
    goto fail; //String
    }


    // session_request->request
    if (s2_session_request_type__NULL == session_request->request) {
        goto fail;
    }
    cJSON *request_local_JSON = session_request_type_convertToJSON(session_request->request);
    if(request_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "request", request_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // session_request->diagnostic_label
    if(session_request->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", session_request->diagnostic_label) == NULL) {
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

session_request_t *session_request_parseFromJSON(cJSON *session_requestJSON){

    session_request_t *session_request_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    // define the local variable for session_request->request
    s2_session_request_type__e request_local_nonprim = 0;

    char *diagnostic_label_local_str = NULL;

    // session_request->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(session_requestJSON, "message_type");
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

    // session_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(session_requestJSON, "message_id");
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

    // session_request->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(session_requestJSON, "request");
    if (cJSON_IsNull(request)) {
        request = NULL;
    }
    if (!request) {
        goto end;
    }

    
    request_local_nonprim = session_request_type_parseFromJSON(request); //custom

    // session_request->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(session_requestJSON, "diagnostic_label");
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
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    session_request_local_var = session_request_create_internal (
        message_type_local_str,
        message_id_local_str,
        request_local_nonprim,
        diagnostic_label_local_str
        );

    if (!session_request_local_var) {
        goto end;
    }

    return session_request_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (request_local_nonprim) {
        request_local_nonprim = 0;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    return NULL;

}
