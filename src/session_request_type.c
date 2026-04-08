#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/session_request_type.h>


char* session_request_type_session_request_type_ToString(s2_session_request_type__e session_request_type) {
    char *session_request_typeArray[] =  { "NULL", "RECONNECT", "TERMINATE" };
    return session_request_typeArray[session_request_type];
}

s2_session_request_type__e session_request_type_session_request_type_FromString(char* session_request_type) {
    size_t stringToReturn = 0;
    char *session_request_typeArray[] =  { "NULL", "RECONNECT", "TERMINATE" };
    size_t sizeofArray = sizeof(session_request_typeArray) / sizeof(session_request_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(session_request_type, session_request_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *session_request_type_convertToJSON(s2_session_request_type__e session_request_type) {
    cJSON *item = cJSON_CreateString(session_request_type_session_request_type_ToString(session_request_type));
    // if(cJSON_AddStringToObject(item, "session_request_type", session_request_type_session_request_type_ToString(session_request_type)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_session_request_type__e session_request_type_parseFromJSON(cJSON *session_request_typeJSON) {
    if(!cJSON_IsString(session_request_typeJSON) || (session_request_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return session_request_type_session_request_type_FromString(session_request_typeJSON->valuestring);
}
