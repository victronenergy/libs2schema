#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_usage_forecast.h>



static frbc_usage_forecast_t *frbc_usage_forecast_create_internal(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    frbc_usage_forecast_t *frbc_usage_forecast_local_var = malloc(sizeof(frbc_usage_forecast_t));
    if (!frbc_usage_forecast_local_var) {
        return NULL;
    }
    memset(frbc_usage_forecast_local_var, 0, sizeof(frbc_usage_forecast_t));
    frbc_usage_forecast_local_var->_library_owned = 1;
    frbc_usage_forecast_local_var->message_type = message_type;
    frbc_usage_forecast_local_var->message_id = message_id;
    frbc_usage_forecast_local_var->start_time = start_time;
    frbc_usage_forecast_local_var->elements = elements;
    return frbc_usage_forecast_local_var;
}

__attribute__((deprecated)) frbc_usage_forecast_t *frbc_usage_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    frbc_usage_forecast_t *result = frbc_usage_forecast_create_internal (
        message_type,
        message_id,
        start_time,
        elements
        );
    if (!result) {
    }
    return result;
}

void frbc_usage_forecast_free(frbc_usage_forecast_t *frbc_usage_forecast) {
    if(NULL == frbc_usage_forecast){
        return ;
    }
    if(frbc_usage_forecast->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_usage_forecast_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_usage_forecast->message_type) {
        free(frbc_usage_forecast->message_type);
        frbc_usage_forecast->message_type = NULL;
    }
    if (frbc_usage_forecast->message_id) {
        free(frbc_usage_forecast->message_id);
        frbc_usage_forecast->message_id = NULL;
    }
    if (frbc_usage_forecast->start_time) {
        free(frbc_usage_forecast->start_time);
        frbc_usage_forecast->start_time = NULL;
    }
    if (frbc_usage_forecast->elements) {
        list_ForEach(listEntry, frbc_usage_forecast->elements) {
            frbc_usage_forecast_element_free(listEntry->data);
        }
        list_freeList(frbc_usage_forecast->elements);
        frbc_usage_forecast->elements = NULL;
    }
    free(frbc_usage_forecast);
}

cJSON *frbc_usage_forecast_convertToJSON(frbc_usage_forecast_t *frbc_usage_forecast) {
    cJSON *item = cJSON_CreateObject();

    // frbc_usage_forecast->message_type
    if (!frbc_usage_forecast->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_usage_forecast->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_usage_forecast->message_id
    if (!frbc_usage_forecast->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_usage_forecast->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_usage_forecast->start_time
    if (!frbc_usage_forecast->start_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_time", frbc_usage_forecast->start_time) == NULL) {
    goto fail; //Date-Time
    }


    // frbc_usage_forecast->elements
    if (!frbc_usage_forecast->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (frbc_usage_forecast->elements) {
    list_ForEach(elementsListEntry, frbc_usage_forecast->elements) {
    cJSON *itemLocal = frbc_usage_forecast_element_convertToJSON(elementsListEntry->data);
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

frbc_usage_forecast_t *frbc_usage_forecast_parseFromJSON(cJSON *frbc_usage_forecastJSON){

    frbc_usage_forecast_t *frbc_usage_forecast_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *start_time_local_str = NULL;

    // define the local list for frbc_usage_forecast->elements
    list_t *elementsList = NULL;

    // frbc_usage_forecast->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecastJSON, "message_type");
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

    // frbc_usage_forecast->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecastJSON, "message_id");
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

    // frbc_usage_forecast->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecastJSON, "start_time");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (!start_time) {
        goto end;
    }

    
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //DateTime
    }

    // frbc_usage_forecast->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecastJSON, "elements");
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
        frbc_usage_forecast_element_t *elementsItem = frbc_usage_forecast_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    frbc_usage_forecast_local_var = frbc_usage_forecast_create_internal (
        message_type_local_str,
        message_id_local_str,
        start_time_local_str,
        elementsList
        );

    if (!frbc_usage_forecast_local_var) {
        goto end;
    }

    return frbc_usage_forecast_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (elementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, elementsList) {
            frbc_usage_forecast_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    return NULL;

}
