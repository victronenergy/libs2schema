#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_average_demand_rate_forecast.h>



static ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_create_internal(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_local_var = malloc(sizeof(ddbc_average_demand_rate_forecast_t));
    if (!ddbc_average_demand_rate_forecast_local_var) {
        return NULL;
    }
    memset(ddbc_average_demand_rate_forecast_local_var, 0, sizeof(ddbc_average_demand_rate_forecast_t));
    ddbc_average_demand_rate_forecast_local_var->_library_owned = 1;
    ddbc_average_demand_rate_forecast_local_var->message_type = message_type;
    ddbc_average_demand_rate_forecast_local_var->message_id = message_id;
    ddbc_average_demand_rate_forecast_local_var->start_time = start_time;
    ddbc_average_demand_rate_forecast_local_var->elements = elements;
    return ddbc_average_demand_rate_forecast_local_var;
}

__attribute__((deprecated)) ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_create(
    char *message_type,
    char *message_id,
    char *start_time,
    list_t *elements
    ) {
    ddbc_average_demand_rate_forecast_t *result = ddbc_average_demand_rate_forecast_create_internal (
        message_type,
        message_id,
        start_time,
        elements
        );
    if (!result) {
    }
    return result;
}

void ddbc_average_demand_rate_forecast_free(ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast) {
    if(NULL == ddbc_average_demand_rate_forecast){
        return ;
    }
    if(ddbc_average_demand_rate_forecast->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_average_demand_rate_forecast_free");
        return ;
    }
    if (ddbc_average_demand_rate_forecast->message_type) {
        free(ddbc_average_demand_rate_forecast->message_type);
        ddbc_average_demand_rate_forecast->message_type = NULL;
    }
    if (ddbc_average_demand_rate_forecast->message_id) {
        free(ddbc_average_demand_rate_forecast->message_id);
        ddbc_average_demand_rate_forecast->message_id = NULL;
    }
    if (ddbc_average_demand_rate_forecast->start_time) {
        free(ddbc_average_demand_rate_forecast->start_time);
        ddbc_average_demand_rate_forecast->start_time = NULL;
    }
    if (ddbc_average_demand_rate_forecast->elements) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_average_demand_rate_forecast->elements) {
            ddbc_average_demand_rate_forecast_element_free(listEntry->data);
        }
        list_freeList(ddbc_average_demand_rate_forecast->elements);
        ddbc_average_demand_rate_forecast->elements = NULL;
    }
    free(ddbc_average_demand_rate_forecast);
}

cJSON *ddbc_average_demand_rate_forecast_convertToJSON(ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_average_demand_rate_forecast->message_type
    if (!ddbc_average_demand_rate_forecast->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ddbc_average_demand_rate_forecast->message_type) == NULL) {
    goto fail; //String
    }


    // ddbc_average_demand_rate_forecast->message_id
    if (!ddbc_average_demand_rate_forecast->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ddbc_average_demand_rate_forecast->message_id) == NULL) {
    goto fail; //String
    }


    // ddbc_average_demand_rate_forecast->start_time
    if (!ddbc_average_demand_rate_forecast->start_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start_time", ddbc_average_demand_rate_forecast->start_time) == NULL) {
    goto fail; //Date-Time
    }


    // ddbc_average_demand_rate_forecast->elements
    if (!ddbc_average_demand_rate_forecast->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (ddbc_average_demand_rate_forecast->elements) {
    list_ForEach(elementsListEntry, ddbc_average_demand_rate_forecast->elements) {
    cJSON *itemLocal = ddbc_average_demand_rate_forecast_element_convertToJSON(elementsListEntry->data);
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

ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_parseFromJSON(cJSON *ddbc_average_demand_rate_forecastJSON){

    ddbc_average_demand_rate_forecast_t *ddbc_average_demand_rate_forecast_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *start_time_local_str = NULL;

    // define the local list for ddbc_average_demand_rate_forecast->elements
    list_t *elementsList = NULL;

    // ddbc_average_demand_rate_forecast->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecastJSON, "message_type");
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

    // ddbc_average_demand_rate_forecast->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecastJSON, "message_id");
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

    // ddbc_average_demand_rate_forecast->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecastJSON, "start_time");
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

    // ddbc_average_demand_rate_forecast->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecastJSON, "elements");
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
        ddbc_average_demand_rate_forecast_element_t *elementsItem = ddbc_average_demand_rate_forecast_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);

    ddbc_average_demand_rate_forecast_local_var = ddbc_average_demand_rate_forecast_create_internal (
        message_type_local_str,
        message_id_local_str,
        start_time_local_str,
        elementsList
        );

    if (!ddbc_average_demand_rate_forecast_local_var) {
        goto end;
    }

    return ddbc_average_demand_rate_forecast_local_var;
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
            ddbc_average_demand_rate_forecast_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    return NULL;

}
