#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_system_description.h>



static ddbc_system_description_t *ddbc_system_description_create_internal(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    number_range_t *present_demand_rate,
    int *provides_average_demand_rate_forecast
    ) {
    ddbc_system_description_t *ddbc_system_description_local_var = malloc(sizeof(ddbc_system_description_t));
    if (!ddbc_system_description_local_var) {
        return NULL;
    }
    memset(ddbc_system_description_local_var, 0, sizeof(ddbc_system_description_t));
    ddbc_system_description_local_var->_library_owned = 1;
    ddbc_system_description_local_var->message_type = message_type;
    ddbc_system_description_local_var->message_id = message_id;
    ddbc_system_description_local_var->valid_from = valid_from;
    ddbc_system_description_local_var->actuators = actuators;
    ddbc_system_description_local_var->present_demand_rate = present_demand_rate;
    ddbc_system_description_local_var->provides_average_demand_rate_forecast = provides_average_demand_rate_forecast;
    return ddbc_system_description_local_var;
}

__attribute__((deprecated)) ddbc_system_description_t *ddbc_system_description_create(
    char *message_type,
    char *message_id,
    char *valid_from,
    list_t *actuators,
    number_range_t *present_demand_rate,
    int *provides_average_demand_rate_forecast
    ) {
    int *provides_average_demand_rate_forecast_copy = NULL;
    if (provides_average_demand_rate_forecast) {
        provides_average_demand_rate_forecast_copy = malloc(sizeof(int));
        if (provides_average_demand_rate_forecast_copy) *provides_average_demand_rate_forecast_copy = *provides_average_demand_rate_forecast;
    }
    ddbc_system_description_t *result = ddbc_system_description_create_internal (
        message_type,
        message_id,
        valid_from,
        actuators,
        present_demand_rate,
        provides_average_demand_rate_forecast_copy
        );
    if (!result) {
        free(provides_average_demand_rate_forecast_copy);
    }
    return result;
}

void ddbc_system_description_free(ddbc_system_description_t *ddbc_system_description) {
    if(NULL == ddbc_system_description){
        return ;
    }
    if(ddbc_system_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_system_description_free");
        return ;
    }
    if (ddbc_system_description->message_type) {
        free(ddbc_system_description->message_type);
        ddbc_system_description->message_type = NULL;
    }
    if (ddbc_system_description->message_id) {
        free(ddbc_system_description->message_id);
        ddbc_system_description->message_id = NULL;
    }
    if (ddbc_system_description->valid_from) {
        free(ddbc_system_description->valid_from);
        ddbc_system_description->valid_from = NULL;
    }
    if (ddbc_system_description->actuators) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ddbc_system_description->actuators) {
            ddbc_actuator_description_free(listEntry->data);
        }
        list_freeList(ddbc_system_description->actuators);
        ddbc_system_description->actuators = NULL;
    }
    if (ddbc_system_description->present_demand_rate) {
        number_range_free(ddbc_system_description->present_demand_rate);
        ddbc_system_description->present_demand_rate = NULL;
    }
    if (ddbc_system_description->provides_average_demand_rate_forecast) {
        free(ddbc_system_description->provides_average_demand_rate_forecast);
        ddbc_system_description->provides_average_demand_rate_forecast = NULL;
    }
    free(ddbc_system_description);
}

cJSON *ddbc_system_description_convertToJSON(ddbc_system_description_t *ddbc_system_description) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_system_description->message_type
    if (!ddbc_system_description->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ddbc_system_description->message_type) == NULL) {
    goto fail; //String
    }


    // ddbc_system_description->message_id
    if (!ddbc_system_description->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ddbc_system_description->message_id) == NULL) {
    goto fail; //String
    }


    // ddbc_system_description->valid_from
    if (!ddbc_system_description->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", ddbc_system_description->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // ddbc_system_description->actuators
    if (!ddbc_system_description->actuators) {
        goto fail;
    }
    cJSON *actuators = cJSON_AddArrayToObject(item, "actuators");
    if(actuators == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *actuatorsListEntry;
    if (ddbc_system_description->actuators) {
    list_ForEach(actuatorsListEntry, ddbc_system_description->actuators) {
    cJSON *itemLocal = ddbc_actuator_description_convertToJSON(actuatorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(actuators, itemLocal);
    }
    }


    // ddbc_system_description->present_demand_rate
    if (!ddbc_system_description->present_demand_rate) {
        goto fail;
    }
    cJSON *present_demand_rate_local_JSON = number_range_convertToJSON(ddbc_system_description->present_demand_rate);
    if(present_demand_rate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "present_demand_rate", present_demand_rate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ddbc_system_description->provides_average_demand_rate_forecast
    if (!ddbc_system_description->provides_average_demand_rate_forecast) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "provides_average_demand_rate_forecast", *ddbc_system_description->provides_average_demand_rate_forecast) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ddbc_system_description_t *ddbc_system_description_parseFromJSON(cJSON *ddbc_system_descriptionJSON){

    ddbc_system_description_t *ddbc_system_description_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *valid_from_local_str = NULL;

    // define the local list for ddbc_system_description->actuators
    list_t *actuatorsList = NULL;

    // define the local variable for ddbc_system_description->present_demand_rate
    number_range_t *present_demand_rate_local_nonprim = NULL;

    // define the local variable for ddbc_system_description->provides_average_demand_rate_forecast
    int *provides_average_demand_rate_forecast_local_var = NULL;

    // ddbc_system_description->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "message_type");
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

    // ddbc_system_description->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "message_id");
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

    // ddbc_system_description->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "valid_from");
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

    // ddbc_system_description->actuators
    cJSON *actuators = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "actuators");
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
        ddbc_actuator_description_t *actuatorsItem = ddbc_actuator_description_parseFromJSON(actuators_local_nonprimitive);

        list_addElement(actuatorsList, actuatorsItem);
    }

    // ddbc_system_description->present_demand_rate
    cJSON *present_demand_rate = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "present_demand_rate");
    if (cJSON_IsNull(present_demand_rate)) {
        present_demand_rate = NULL;
    }
    if (!present_demand_rate) {
        goto end;
    }

    
    present_demand_rate_local_nonprim = number_range_parseFromJSON(present_demand_rate); //nonprimitive

    // ddbc_system_description->provides_average_demand_rate_forecast
    cJSON *provides_average_demand_rate_forecast = cJSON_GetObjectItemCaseSensitive(ddbc_system_descriptionJSON, "provides_average_demand_rate_forecast");
    if (cJSON_IsNull(provides_average_demand_rate_forecast)) {
        provides_average_demand_rate_forecast = NULL;
    }
    if (!provides_average_demand_rate_forecast) {
        goto end;
    }

    
    if(!cJSON_IsBool(provides_average_demand_rate_forecast))
    {
    goto end; //Bool
    }
    provides_average_demand_rate_forecast_local_var = malloc(sizeof(int));
    if(!provides_average_demand_rate_forecast_local_var)
    {
        goto end;
    }
    *provides_average_demand_rate_forecast_local_var = provides_average_demand_rate_forecast->valueint;


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);

    ddbc_system_description_local_var = ddbc_system_description_create_internal (
        message_type_local_str,
        message_id_local_str,
        valid_from_local_str,
        actuatorsList,
        present_demand_rate_local_nonprim,
        provides_average_demand_rate_forecast_local_var
        );

    if (!ddbc_system_description_local_var) {
        goto end;
    }

    return ddbc_system_description_local_var;
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
            ddbc_actuator_description_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(actuatorsList);
        actuatorsList = NULL;
    }
    if (present_demand_rate_local_nonprim) {
        number_range_free(present_demand_rate_local_nonprim);
        present_demand_rate_local_nonprim = NULL;
    }
    if (provides_average_demand_rate_forecast_local_var) {
        free(provides_average_demand_rate_forecast_local_var);
        provides_average_demand_rate_forecast_local_var = NULL;
    }
    return NULL;

}
