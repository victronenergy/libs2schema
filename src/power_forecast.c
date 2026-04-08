#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_forecast.h>



static power_forecast_t *power_forecast_create_internal(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    power_forecast_t *power_forecast_local_var = malloc(sizeof(power_forecast_t));
    if (!power_forecast_local_var) {
        return NULL;
    }
    memset(power_forecast_local_var, 0, sizeof(power_forecast_t));
    power_forecast_local_var->_library_owned = 1;
    power_forecast_local_var->message_type = message_type;
    power_forecast_local_var->message_id = message_id;
    power_forecast_local_var->start_time = start_time;
    power_forecast_local_var->elements = elements;
    return power_forecast_local_var;
}

__attribute__((deprecated)) power_forecast_t *power_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    power_forecast_t *result = power_forecast_create_internal (
        message_type,
        message_id,
        start_time,
        elements
        );
    if (!result) {
    }
    return result;
}

void power_forecast_free(power_forecast_t *power_forecast) {
    if(NULL == power_forecast){
        return ;
    }
    if(power_forecast->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_forecast_free");
        return ;
    }
    listEntry_t *listEntry;
    if (power_forecast->message_type) {
        free(power_forecast->message_type);
        power_forecast->message_type = NULL;
    }
    if (power_forecast->message_id) {
        free(power_forecast->message_id);
        power_forecast->message_id = NULL;
    }
    if (power_forecast->start_time) {
        free(power_forecast->start_time);
        power_forecast->start_time = NULL;
    }
    if (power_forecast->elements) {
        list_ForEach(listEntry, power_forecast->elements) {
            power_forecast_element_free(listEntry->data);
        }
        list_freeList(power_forecast->elements);
        power_forecast->elements = NULL;
    }
    free(power_forecast);
}

cJSON *power_forecast_convertToJSON(power_forecast_t *power_forecast) {
    cJSON *item = cJSON_CreateObject();

    // power_forecast->message_type
    if (!power_forecast->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", power_forecast->message_type) == NULL) {
    goto fail; //String
    }


    // power_forecast->message_id
    if (!power_forecast->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", power_forecast->message_id) == NULL) {
    goto fail; //String
    }


    // power_forecast->start_time
    if (!power_forecast->start_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_time", power_forecast->start_time) == NULL) {
    goto fail; //Date-Time
    }


    // power_forecast->elements
    if (!power_forecast->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (power_forecast->elements) {
    list_ForEach(elementsListEntry, power_forecast->elements) {
    cJSON *itemLocal = power_forecast_element_convertToJSON(elementsListEntry->data);
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

power_forecast_t *power_forecast_parseFromJSON(cJSON *power_forecastJSON){

    power_forecast_t *power_forecast_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *start_time_local_str = NULL;

    // define the local list for power_forecast->elements
    list_t *elementsList = NULL;

    // power_forecast->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(power_forecastJSON, "message_type");
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

    // power_forecast->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(power_forecastJSON, "message_id");
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

    // power_forecast->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(power_forecastJSON, "start_time");
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

    // power_forecast->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(power_forecastJSON, "elements");
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
        power_forecast_element_t *elementsItem = power_forecast_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    power_forecast_local_var = power_forecast_create_internal (
        message_type_local_str,
        message_id_local_str,
        start_time_local_str,
        elementsList
        );

    if (!power_forecast_local_var) {
        goto end;
    }

    return power_forecast_local_var;
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
            power_forecast_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    return NULL;

}
