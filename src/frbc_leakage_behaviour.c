#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_leakage_behaviour.h>



static frbc_leakage_behaviour_t *frbc_leakage_behaviour_create_internal(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *elements
    ) {
    frbc_leakage_behaviour_t *frbc_leakage_behaviour_local_var = malloc(sizeof(frbc_leakage_behaviour_t));
    if (!frbc_leakage_behaviour_local_var) {
        return NULL;
    }
    memset(frbc_leakage_behaviour_local_var, 0, sizeof(frbc_leakage_behaviour_t));
    frbc_leakage_behaviour_local_var->_library_owned = 1;
    frbc_leakage_behaviour_local_var->message_type = message_type;
    frbc_leakage_behaviour_local_var->message_id = message_id;
    frbc_leakage_behaviour_local_var->valid_from = valid_from;
    frbc_leakage_behaviour_local_var->elements = elements;
    return frbc_leakage_behaviour_local_var;
}

__attribute__((deprecated)) frbc_leakage_behaviour_t *frbc_leakage_behaviour_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *elements
    ) {
    frbc_leakage_behaviour_t *result = frbc_leakage_behaviour_create_internal (
        message_type,
        message_id,
        valid_from,
        elements
        );
    if (!result) {
    }
    return result;
}

void frbc_leakage_behaviour_free(frbc_leakage_behaviour_t *frbc_leakage_behaviour) {
    if(NULL == frbc_leakage_behaviour){
        return ;
    }
    if(frbc_leakage_behaviour->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_leakage_behaviour_free");
        return ;
    }
    if (frbc_leakage_behaviour->message_type) {
        free(frbc_leakage_behaviour->message_type);
        frbc_leakage_behaviour->message_type = NULL;
    }
    if (frbc_leakage_behaviour->message_id) {
        free(frbc_leakage_behaviour->message_id);
        frbc_leakage_behaviour->message_id = NULL;
    }
    if (frbc_leakage_behaviour->valid_from) {
        free(frbc_leakage_behaviour->valid_from);
        frbc_leakage_behaviour->valid_from = NULL;
    }
    if (frbc_leakage_behaviour->elements) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, frbc_leakage_behaviour->elements) {
            frbc_leakage_behaviour_element_free(listEntry->data);
        }
        list_freeList(frbc_leakage_behaviour->elements);
        frbc_leakage_behaviour->elements = NULL;
    }
    free(frbc_leakage_behaviour);
}

cJSON *frbc_leakage_behaviour_convertToJSON(frbc_leakage_behaviour_t *frbc_leakage_behaviour) {
    cJSON *item = cJSON_CreateObject();

    // frbc_leakage_behaviour->message_type
    if (!frbc_leakage_behaviour->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_leakage_behaviour->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_leakage_behaviour->message_id
    if (!frbc_leakage_behaviour->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_leakage_behaviour->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_leakage_behaviour->valid_from
    if (!frbc_leakage_behaviour->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", frbc_leakage_behaviour->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // frbc_leakage_behaviour->elements
    if (!frbc_leakage_behaviour->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (frbc_leakage_behaviour->elements) {
    list_ForEach(elementsListEntry, frbc_leakage_behaviour->elements) {
    cJSON *itemLocal = frbc_leakage_behaviour_element_convertToJSON(elementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(elements, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_leakage_behaviour_t *frbc_leakage_behaviour_parseFromJSON(cJSON *frbc_leakage_behaviourJSON){

    frbc_leakage_behaviour_t *frbc_leakage_behaviour_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *valid_from_local_str = NULL;

    // define the local list for frbc_leakage_behaviour->elements
    list_t *elementsList = NULL;

    // frbc_leakage_behaviour->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviourJSON, "message_type");
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

    // frbc_leakage_behaviour->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviourJSON, "message_id");
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

    // frbc_leakage_behaviour->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviourJSON, "valid_from");
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

    // frbc_leakage_behaviour->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviourJSON, "elements");
    if (cJSON_IsNull(elements)) {
        elements = NULL;
    }
    if (!elements) {
        goto end;
    }

    
    cJSON *elements_local_nonprimitive = NULL;
    if(!cJSON_IsArray(elements)){
        goto end; //nonprimitive container
    }

    elementsList = list_createList();

    cJSON_ArrayForEach(elements_local_nonprimitive,elements )
    {
        if(!cJSON_IsObject(elements_local_nonprimitive)){
            goto end;
        }
        frbc_leakage_behaviour_element_t *elementsItem = frbc_leakage_behaviour_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);

    frbc_leakage_behaviour_local_var = frbc_leakage_behaviour_create_internal (
        message_type_local_str,
        message_id_local_str,
        valid_from_local_str,
        elementsList
        );

    if (!frbc_leakage_behaviour_local_var) {
        goto end;
    }

    return frbc_leakage_behaviour_local_var;
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
    if (elementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, elementsList) {
            frbc_leakage_behaviour_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    return NULL;

}
