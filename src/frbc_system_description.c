#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_system_description.h>



static frbc_system_description_t *frbc_system_description_create_internal(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    frbc_storage_description_t *storage
    ) {
    frbc_system_description_t *frbc_system_description_local_var = malloc(sizeof(frbc_system_description_t));
    if (!frbc_system_description_local_var) {
        return NULL;
    }
    memset(frbc_system_description_local_var, 0, sizeof(frbc_system_description_t));
    frbc_system_description_local_var->_library_owned = 1;
    frbc_system_description_local_var->message_type = message_type;
    frbc_system_description_local_var->message_id = message_id;
    frbc_system_description_local_var->valid_from = valid_from;
    frbc_system_description_local_var->actuators = actuators;
    frbc_system_description_local_var->storage = storage;
    return frbc_system_description_local_var;
}

__attribute__((deprecated)) frbc_system_description_t *frbc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    frbc_storage_description_t *storage
    ) {
    frbc_system_description_t *result = frbc_system_description_create_internal (
        message_type,
        message_id,
        valid_from,
        actuators,
        storage
        );
    if (!result) {
    }
    return result;
}

void frbc_system_description_free(frbc_system_description_t *frbc_system_description) {
    if(NULL == frbc_system_description){
        return ;
    }
    if(frbc_system_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_system_description_free");
        return ;
    }
    if (frbc_system_description->message_type) {
        free(frbc_system_description->message_type);
        frbc_system_description->message_type = NULL;
    }
    if (frbc_system_description->message_id) {
        free(frbc_system_description->message_id);
        frbc_system_description->message_id = NULL;
    }
    if (frbc_system_description->valid_from) {
        free(frbc_system_description->valid_from);
        frbc_system_description->valid_from = NULL;
    }
    if (frbc_system_description->actuators) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, frbc_system_description->actuators) {
            frbc_actuator_description_free(listEntry->data);
        }
        list_freeList(frbc_system_description->actuators);
        frbc_system_description->actuators = NULL;
    }
    if (frbc_system_description->storage) {
        frbc_storage_description_free(frbc_system_description->storage);
        frbc_system_description->storage = NULL;
    }
    free(frbc_system_description);
}

cJSON *frbc_system_description_convertToJSON(frbc_system_description_t *frbc_system_description) {
    cJSON *item = cJSON_CreateObject();

    // frbc_system_description->message_type
    if (!frbc_system_description->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_system_description->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_system_description->message_id
    if (!frbc_system_description->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_system_description->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_system_description->valid_from
    if (!frbc_system_description->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", frbc_system_description->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // frbc_system_description->actuators
    if (!frbc_system_description->actuators) {
        goto fail;
    }
    cJSON *actuators = cJSON_AddArrayToObject(item, "actuators");
    if(actuators == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *actuatorsListEntry;
    if (frbc_system_description->actuators) {
    list_ForEach(actuatorsListEntry, frbc_system_description->actuators) {
    cJSON *itemLocal = frbc_actuator_description_convertToJSON(actuatorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(actuators, itemLocal);
    }
    }


    // frbc_system_description->storage
    if (!frbc_system_description->storage) {
        goto fail;
    }
    cJSON *storage_local_JSON = frbc_storage_description_convertToJSON(frbc_system_description->storage);
    if(storage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "storage", storage_local_JSON);
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

frbc_system_description_t *frbc_system_description_parseFromJSON(cJSON *frbc_system_descriptionJSON){

    frbc_system_description_t *frbc_system_description_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *valid_from_local_str = NULL;

    // define the local list for frbc_system_description->actuators
    list_t *actuatorsList = NULL;

    // define the local variable for frbc_system_description->storage
    frbc_storage_description_t *storage_local_nonprim = NULL;

    // frbc_system_description->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_system_descriptionJSON, "message_type");
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

    // frbc_system_description->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_system_descriptionJSON, "message_id");
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

    // frbc_system_description->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(frbc_system_descriptionJSON, "valid_from");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (!valid_from) {
        goto end;
    }

    
    if(!cJSON_IsString(valid_from) && !cJSON_IsNull(valid_from))
    {
    goto end; //DateTime
    }

    // frbc_system_description->actuators
    cJSON *actuators = cJSON_GetObjectItemCaseSensitive(frbc_system_descriptionJSON, "actuators");
    if (cJSON_IsNull(actuators)) {
        actuators = NULL;
    }
    if (!actuators) {
        goto end;
    }

    
    cJSON *actuators_local_nonprimitive = NULL;
    if(!cJSON_IsArray(actuators)){
        goto end; //nonprimitive container
    }

    actuatorsList = list_createList();

    cJSON_ArrayForEach(actuators_local_nonprimitive,actuators )
    {
        if(!cJSON_IsObject(actuators_local_nonprimitive)){
            goto end;
        }
        frbc_actuator_description_t *actuatorsItem = frbc_actuator_description_parseFromJSON(actuators_local_nonprimitive);

        list_addElement(actuatorsList, actuatorsItem);
    }

    // frbc_system_description->storage
    cJSON *storage = cJSON_GetObjectItemCaseSensitive(frbc_system_descriptionJSON, "storage");
    if (cJSON_IsNull(storage)) {
        storage = NULL;
    }
    if (!storage) {
        goto end;
    }

    
    storage_local_nonprim = frbc_storage_description_parseFromJSON(storage); //nonprimitive


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);

    frbc_system_description_local_var = frbc_system_description_create_internal (
        message_type_local_str,
        message_id_local_str,
        valid_from_local_str,
        actuatorsList,
        storage_local_nonprim
        );

    if (!frbc_system_description_local_var) {
        goto end;
    }

    return frbc_system_description_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (valid_from_local_str) {
        free(valid_from_local_str);
        valid_from_local_str = NULL;
    }
    if (actuatorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, actuatorsList) {
            frbc_actuator_description_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(actuatorsList);
        actuatorsList = NULL;
    }
    if (storage_local_nonprim) {
        frbc_storage_description_free(storage_local_nonprim);
        storage_local_nonprim = NULL;
    }
    return NULL;

}
