#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/resource_manager_details.h>


// char* resource_manager_details_available_control_types_ToString(s2_resource_manager_details__e available_control_types) {
//     char *available_control_typesArray[] =  { "NULL", "POWER_ENVELOPE_BASED_CONTROL", "POWER_PROFILE_BASED_CONTROL", "OPERATION_MODE_BASED_CONTROL", "FILL_RATE_BASED_CONTROL", "DEMAND_DRIVEN_BASED_CONTROL", "NOT_CONTROLABLE", "NO_SELECTION" };
//     return available_control_typesArray[available_control_types - 1];
// }
//
// s2_resource_manager_details__e resource_manager_details_available_control_types_FromString(char* available_control_types) {
//     size_t stringToReturn = 0;
//     char *available_control_typesArray[] =  { "NULL", "POWER_ENVELOPE_BASED_CONTROL", "POWER_PROFILE_BASED_CONTROL", "OPERATION_MODE_BASED_CONTROL", "FILL_RATE_BASED_CONTROL", "DEMAND_DRIVEN_BASED_CONTROL", "NOT_CONTROLABLE", "NO_SELECTION" };
//     size_t sizeofArray = sizeof(available_control_typesArray) / sizeof(available_control_typesArray[0]);
//     while(stringToReturn < sizeofArray) {
//         if(strcmp(available_control_types, available_control_typesArray[stringToReturn]) == 0) {
//             return stringToReturn + 1;
//         }
//         stringToReturn++;
//     }
//     return 0;
// }
// char* resource_manager_details_provides_power_measurement_types_ToString(s2_resource_manager_details__e provides_power_measurement_types) {
//     char *provides_power_measurement_typesArray[] =  { "NULL", "ELECTRIC.POWER.L1", "ELECTRIC.POWER.L2", "ELECTRIC.POWER.L3", "ELECTRIC.POWER.3_PHASE_SYMMETRIC", "NATURAL_GAS.FLOW_RATE", "HYDROGEN.FLOW_RATE", "HEAT.TEMPERATURE", "HEAT.FLOW_RATE", "HEAT.THERMAL_POWER", "OIL.FLOW_RATE" };
//     return provides_power_measurement_typesArray[provides_power_measurement_types - 1];
// }
//
// s2_resource_manager_details__e resource_manager_details_provides_power_measurement_types_FromString(char* provides_power_measurement_types) {
//     size_t stringToReturn = 0;
//     char *provides_power_measurement_typesArray[] =  { "NULL", "ELECTRIC.POWER.L1", "ELECTRIC.POWER.L2", "ELECTRIC.POWER.L3", "ELECTRIC.POWER.3_PHASE_SYMMETRIC", "NATURAL_GAS.FLOW_RATE", "HYDROGEN.FLOW_RATE", "HEAT.TEMPERATURE", "HEAT.FLOW_RATE", "HEAT.THERMAL_POWER", "OIL.FLOW_RATE" };
//     size_t sizeofArray = sizeof(provides_power_measurement_typesArray) / sizeof(provides_power_measurement_typesArray[0]);
//     while(stringToReturn < sizeofArray) {
//         if(strcmp(provides_power_measurement_types, provides_power_measurement_typesArray[stringToReturn]) == 0) {
//             return stringToReturn + 1;
//         }
//         stringToReturn++;
//     }
//     return 0;
// }

static resource_manager_details_t *resource_manager_details_create_internal(
    char *message_type,
    char *message_id,
    char *resource_id,
    char *name,
    list_t *roles,
    char *manufacturer,
    char *model,
    char *serial_number,
    char *firmware_version,
    int *instruction_processing_delay,
    list_t *available_control_types,
    s2_currency__e currency,
    int *provides_forecast,
    list_t *provides_power_measurement_types
    ) {
    resource_manager_details_t *resource_manager_details_local_var = malloc(sizeof(resource_manager_details_t));
    if (!resource_manager_details_local_var) {
        return NULL;
    }
    memset(resource_manager_details_local_var, 0, sizeof(resource_manager_details_t));
    resource_manager_details_local_var->_library_owned = 1;
    resource_manager_details_local_var->message_type = message_type;
    resource_manager_details_local_var->message_id = message_id;
    resource_manager_details_local_var->resource_id = resource_id;
    resource_manager_details_local_var->name = name;
    resource_manager_details_local_var->roles = roles;
    resource_manager_details_local_var->manufacturer = manufacturer;
    resource_manager_details_local_var->model = model;
    resource_manager_details_local_var->serial_number = serial_number;
    resource_manager_details_local_var->firmware_version = firmware_version;
    resource_manager_details_local_var->instruction_processing_delay = instruction_processing_delay;
    resource_manager_details_local_var->available_control_types = available_control_types;
    resource_manager_details_local_var->currency = currency;
    resource_manager_details_local_var->provides_forecast = provides_forecast;
    resource_manager_details_local_var->provides_power_measurement_types = provides_power_measurement_types;
    return resource_manager_details_local_var;
}

__attribute__((deprecated)) resource_manager_details_t *resource_manager_details_create(
    char *message_type,
    char *message_id,
    char *resource_id,
    char *name,
    list_t *roles,
    char *manufacturer,
    char *model,
    char *serial_number,
    char *firmware_version,
    int *instruction_processing_delay,
    list_t *available_control_types,
    s2_currency__e currency,
    int *provides_forecast,
    list_t *provides_power_measurement_types
    ) {
    int *instruction_processing_delay_copy = NULL;
    if (instruction_processing_delay) {
        instruction_processing_delay_copy = malloc(sizeof(int));
        if (instruction_processing_delay_copy) *instruction_processing_delay_copy = *instruction_processing_delay;
    }
    int *provides_forecast_copy = NULL;
    if (provides_forecast) {
        provides_forecast_copy = malloc(sizeof(int));
        if (provides_forecast_copy) *provides_forecast_copy = *provides_forecast;
    }
    resource_manager_details_t *result = resource_manager_details_create_internal (
        message_type,
        message_id,
        resource_id,
        name,
        roles,
        manufacturer,
        model,
        serial_number,
        firmware_version,
        instruction_processing_delay_copy,
        available_control_types,
        currency,
        provides_forecast_copy,
        provides_power_measurement_types
        );
    if (!result) {
        free(instruction_processing_delay_copy);
        free(provides_forecast_copy);
    }
    return result;
}

void resource_manager_details_free(resource_manager_details_t *resource_manager_details) {
    if(NULL == resource_manager_details){
        return ;
    }
    if(resource_manager_details->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "resource_manager_details_free");
        return ;
    }
    if (resource_manager_details->message_type) {
        free(resource_manager_details->message_type);
        resource_manager_details->message_type = NULL;
    }
    if (resource_manager_details->message_id) {
        free(resource_manager_details->message_id);
        resource_manager_details->message_id = NULL;
    }
    if (resource_manager_details->resource_id) {
        free(resource_manager_details->resource_id);
        resource_manager_details->resource_id = NULL;
    }
    if (resource_manager_details->name) {
        free(resource_manager_details->name);
        resource_manager_details->name = NULL;
    }
    if (resource_manager_details->roles) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, resource_manager_details->roles) {
            role_free(listEntry->data);
        }
        list_freeList(resource_manager_details->roles);
        resource_manager_details->roles = NULL;
    }
    if (resource_manager_details->manufacturer) {
        free(resource_manager_details->manufacturer);
        resource_manager_details->manufacturer = NULL;
    }
    if (resource_manager_details->model) {
        free(resource_manager_details->model);
        resource_manager_details->model = NULL;
    }
    if (resource_manager_details->serial_number) {
        free(resource_manager_details->serial_number);
        resource_manager_details->serial_number = NULL;
    }
    if (resource_manager_details->firmware_version) {
        free(resource_manager_details->firmware_version);
        resource_manager_details->firmware_version = NULL;
    }
    if (resource_manager_details->instruction_processing_delay) {
        free(resource_manager_details->instruction_processing_delay);
        resource_manager_details->instruction_processing_delay = NULL;
    }
    if (resource_manager_details->available_control_types) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, resource_manager_details->available_control_types) {
        }
        list_freeList(resource_manager_details->available_control_types);
        resource_manager_details->available_control_types = NULL;
    }
    if (resource_manager_details->provides_forecast) {
        free(resource_manager_details->provides_forecast);
        resource_manager_details->provides_forecast = NULL;
    }
    if (resource_manager_details->provides_power_measurement_types) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, resource_manager_details->provides_power_measurement_types) {
        }
        list_freeList(resource_manager_details->provides_power_measurement_types);
        resource_manager_details->provides_power_measurement_types = NULL;
    }
    free(resource_manager_details);
}

cJSON *resource_manager_details_convertToJSON(resource_manager_details_t *resource_manager_details) {
    cJSON *item = cJSON_CreateObject();

    // resource_manager_details->message_type
    if (!resource_manager_details->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", resource_manager_details->message_type) == NULL) {
    goto fail; //String
    }


    // resource_manager_details->message_id
    if (!resource_manager_details->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", resource_manager_details->message_id) == NULL) {
    goto fail; //String
    }


    // resource_manager_details->resource_id
    if (!resource_manager_details->resource_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resource_id", resource_manager_details->resource_id) == NULL) {
    goto fail; //String
    }


    // resource_manager_details->name
    if(resource_manager_details->name) {
    if(cJSON_AddStringToObject(item, "name", resource_manager_details->name) == NULL) {
    goto fail; //String
    }
    }


    // resource_manager_details->roles
    if (!resource_manager_details->roles) {
        goto fail;
    }
    cJSON *roles = cJSON_AddArrayToObject(item, "roles");
    if(roles == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rolesListEntry;
    if (resource_manager_details->roles) {
    list_ForEach(rolesListEntry, resource_manager_details->roles) {
    cJSON *itemLocal = role_convertToJSON(rolesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(roles, itemLocal);
    }
    }


    // resource_manager_details->manufacturer
    if(resource_manager_details->manufacturer) {
    if(cJSON_AddStringToObject(item, "manufacturer", resource_manager_details->manufacturer) == NULL) {
    goto fail; //String
    }
    }


    // resource_manager_details->model
    if(resource_manager_details->model) {
    if(cJSON_AddStringToObject(item, "model", resource_manager_details->model) == NULL) {
    goto fail; //String
    }
    }


    // resource_manager_details->serial_number
    if(resource_manager_details->serial_number) {
    if(cJSON_AddStringToObject(item, "serial_number", resource_manager_details->serial_number) == NULL) {
    goto fail; //String
    }
    }


    // resource_manager_details->firmware_version
    if(resource_manager_details->firmware_version) {
    if(cJSON_AddStringToObject(item, "firmware_version", resource_manager_details->firmware_version) == NULL) {
    goto fail; //String
    }
    }


    // resource_manager_details->instruction_processing_delay
    if (!resource_manager_details->instruction_processing_delay) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "instruction_processing_delay", *resource_manager_details->instruction_processing_delay) == NULL) {
    goto fail; //Numeric
    }


    // resource_manager_details->available_control_types
    if (!resource_manager_details->available_control_types) {
        goto fail;
    }
    cJSON *available_control_types = cJSON_AddArrayToObject(item, "available_control_types");
    if(available_control_types == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *available_control_typesListEntry;
    if (resource_manager_details->available_control_types) {
    list_ForEach(available_control_typesListEntry, resource_manager_details->available_control_types) {
    cJSON *itemLocal = control_type_convertToJSON((s2_control_type__e)(intptr_t)available_control_typesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(available_control_types, itemLocal);
    }
    }


    // resource_manager_details->currency
    if(resource_manager_details->currency != s2_currency__NULL) {
    cJSON *currency_local_JSON = currency_convertToJSON(resource_manager_details->currency);
    if(currency_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "currency", currency_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // resource_manager_details->provides_forecast
    if (!resource_manager_details->provides_forecast) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "provides_forecast", *resource_manager_details->provides_forecast) == NULL) {
    goto fail; //Bool
    }


    // resource_manager_details->provides_power_measurement_types
    if (!resource_manager_details->provides_power_measurement_types) {
        goto fail;
    }
    cJSON *provides_power_measurement_types = cJSON_AddArrayToObject(item, "provides_power_measurement_types");
    if(provides_power_measurement_types == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *provides_power_measurement_typesListEntry;
    if (resource_manager_details->provides_power_measurement_types) {
    list_ForEach(provides_power_measurement_typesListEntry, resource_manager_details->provides_power_measurement_types) {
    cJSON *itemLocal = commodity_quantity_convertToJSON((s2_commodity_quantity__e)(intptr_t)provides_power_measurement_typesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(provides_power_measurement_types, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

resource_manager_details_t *resource_manager_details_parseFromJSON(cJSON *resource_manager_detailsJSON){

    resource_manager_details_t *resource_manager_details_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *resource_id_local_str = NULL;

    char *name_local_str = NULL;

    // define the local list for resource_manager_details->roles
    list_t *rolesList = NULL;

    char *manufacturer_local_str = NULL;

    char *model_local_str = NULL;

    char *serial_number_local_str = NULL;

    char *firmware_version_local_str = NULL;

    // define the local variable for resource_manager_details->instruction_processing_delay
    int *instruction_processing_delay_local_var = NULL;

    // define the local list for resource_manager_details->available_control_types
    list_t *available_control_typesList = NULL;

    // define the local variable for resource_manager_details->currency
    s2_currency__e currency_local_nonprim = 0;

    // define the local variable for resource_manager_details->provides_forecast
    int *provides_forecast_local_var = NULL;

    // define the local list for resource_manager_details->provides_power_measurement_types
    list_t *provides_power_measurement_typesList = NULL;

    // resource_manager_details->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "message_type");
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

    // resource_manager_details->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "message_id");
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

    // resource_manager_details->resource_id
    cJSON *resource_id = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "resource_id");
    if (cJSON_IsNull(resource_id)) {
        resource_id = NULL;
    }
    if (!resource_id) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_id))
    {
    goto end; //String
    }

    // resource_manager_details->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // resource_manager_details->roles
    cJSON *roles = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "roles");
    if (cJSON_IsNull(roles)) {
        roles = NULL;
    }
    if (!roles) {
        goto end;
    }

    
    cJSON *roles_local_nonprimitive = NULL;
    if(!cJSON_IsArray(roles)){
        goto end; //nonprimitive container
    }

    rolesList = list_createList();

    cJSON_ArrayForEach(roles_local_nonprimitive,roles )
    {
        if(!cJSON_IsObject(roles_local_nonprimitive)){
            goto end;
        }
        role_t *rolesItem = role_parseFromJSON(roles_local_nonprimitive);

        list_addElement(rolesList, rolesItem);
    }

    // resource_manager_details->manufacturer
    cJSON *manufacturer = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "manufacturer");
    if (cJSON_IsNull(manufacturer)) {
        manufacturer = NULL;
    }
    if (manufacturer) { 
    if(!cJSON_IsString(manufacturer) && !cJSON_IsNull(manufacturer))
    {
    goto end; //String
    }
    }

    // resource_manager_details->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // resource_manager_details->serial_number
    cJSON *serial_number = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "serial_number");
    if (cJSON_IsNull(serial_number)) {
        serial_number = NULL;
    }
    if (serial_number) { 
    if(!cJSON_IsString(serial_number) && !cJSON_IsNull(serial_number))
    {
    goto end; //String
    }
    }

    // resource_manager_details->firmware_version
    cJSON *firmware_version = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "firmware_version");
    if (cJSON_IsNull(firmware_version)) {
        firmware_version = NULL;
    }
    if (firmware_version) { 
    if(!cJSON_IsString(firmware_version) && !cJSON_IsNull(firmware_version))
    {
    goto end; //String
    }
    }

    // resource_manager_details->instruction_processing_delay
    cJSON *instruction_processing_delay = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "instruction_processing_delay");
    if (cJSON_IsNull(instruction_processing_delay)) {
        instruction_processing_delay = NULL;
    }
    if (!instruction_processing_delay) {
        goto end;
    }

    
    if(!cJSON_IsNumber(instruction_processing_delay))
    {
    goto end; //Numeric
    }
    instruction_processing_delay_local_var = malloc(sizeof(int));
    if(!instruction_processing_delay_local_var)
    {
        goto end;
    }
    *instruction_processing_delay_local_var = instruction_processing_delay->valuedouble;

    // resource_manager_details->available_control_types
    cJSON *available_control_types = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "available_control_types");
    if (cJSON_IsNull(available_control_types)) {
        available_control_types = NULL;
    }
    if (!available_control_types) {
        goto end;
    }

    
    cJSON *available_control_types_local_nonprimitive = NULL;
    if(!cJSON_IsArray(available_control_types)){
        goto end; //nonprimitive container
    }

    available_control_typesList = list_createList();

    cJSON_ArrayForEach(available_control_types_local_nonprimitive,available_control_types )
    {
        if(!cJSON_IsObject(available_control_types_local_nonprimitive)){
            goto end;
        }
        s2_control_type__e available_control_typesItem = control_type_parseFromJSON(available_control_types_local_nonprimitive);

        list_addElement(available_control_typesList, (void *)(intptr_t)available_control_typesItem);
    }

    // resource_manager_details->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    currency_local_nonprim = currency_parseFromJSON(currency); //custom
    }

    // resource_manager_details->provides_forecast
    cJSON *provides_forecast = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "provides_forecast");
    if (cJSON_IsNull(provides_forecast)) {
        provides_forecast = NULL;
    }
    if (!provides_forecast) {
        goto end;
    }

    
    if(!cJSON_IsBool(provides_forecast))
    {
    goto end; //Bool
    }
    provides_forecast_local_var = malloc(sizeof(int));
    if(!provides_forecast_local_var)
    {
        goto end;
    }
    *provides_forecast_local_var = provides_forecast->valueint;

    // resource_manager_details->provides_power_measurement_types
    cJSON *provides_power_measurement_types = cJSON_GetObjectItemCaseSensitive(resource_manager_detailsJSON, "provides_power_measurement_types");
    if (cJSON_IsNull(provides_power_measurement_types)) {
        provides_power_measurement_types = NULL;
    }
    if (!provides_power_measurement_types) {
        goto end;
    }

    
    cJSON *provides_power_measurement_types_local_nonprimitive = NULL;
    if(!cJSON_IsArray(provides_power_measurement_types)){
        goto end; //nonprimitive container
    }

    provides_power_measurement_typesList = list_createList();

    cJSON_ArrayForEach(provides_power_measurement_types_local_nonprimitive,provides_power_measurement_types )
    {
        if(!cJSON_IsObject(provides_power_measurement_types_local_nonprimitive)){
            goto end;
        }
        s2_commodity_quantity__e provides_power_measurement_typesItem = commodity_quantity_parseFromJSON(provides_power_measurement_types_local_nonprimitive);

        list_addElement(provides_power_measurement_typesList, (void *)(intptr_t)provides_power_measurement_typesItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (resource_id && !cJSON_IsNull(resource_id)) resource_id_local_str = strdup(resource_id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (manufacturer && !cJSON_IsNull(manufacturer)) manufacturer_local_str = strdup(manufacturer->valuestring);
    if (model && !cJSON_IsNull(model)) model_local_str = strdup(model->valuestring);
    if (serial_number && !cJSON_IsNull(serial_number)) serial_number_local_str = strdup(serial_number->valuestring);
    if (firmware_version && !cJSON_IsNull(firmware_version)) firmware_version_local_str = strdup(firmware_version->valuestring);

    resource_manager_details_local_var = resource_manager_details_create_internal (
        message_type_local_str,
        message_id_local_str,
        resource_id_local_str,
        name_local_str,
        rolesList,
        manufacturer_local_str,
        model_local_str,
        serial_number_local_str,
        firmware_version_local_str,
        instruction_processing_delay_local_var,
        available_control_typesList,
        currency ? currency_local_nonprim : 0,
        provides_forecast_local_var,
        provides_power_measurement_typesList
        );

    if (!resource_manager_details_local_var) {
        goto end;
    }

    return resource_manager_details_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (resource_id_local_str) {
        free(resource_id_local_str);
        resource_id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (rolesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rolesList) {
            role_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rolesList);
        rolesList = NULL;
    }
    if (manufacturer_local_str) {
        free(manufacturer_local_str);
        manufacturer_local_str = NULL;
    }
    if (model_local_str) {
        free(model_local_str);
        model_local_str = NULL;
    }
    if (serial_number_local_str) {
        free(serial_number_local_str);
        serial_number_local_str = NULL;
    }
    if (firmware_version_local_str) {
        free(firmware_version_local_str);
        firmware_version_local_str = NULL;
    }
    if (instruction_processing_delay_local_var) {
        free(instruction_processing_delay_local_var);
        instruction_processing_delay_local_var = NULL;
    }
    if (available_control_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, available_control_typesList) {
            listEntry->data = NULL;
        }
        list_freeList(available_control_typesList);
        available_control_typesList = NULL;
    }
    if (currency_local_nonprim) {
        currency_local_nonprim = 0;
    }
    if (provides_forecast_local_var) {
        free(provides_forecast_local_var);
        provides_forecast_local_var = NULL;
    }
    if (provides_power_measurement_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, provides_power_measurement_typesList) {
            listEntry->data = NULL;
        }
        list_freeList(provides_power_measurement_typesList);
        provides_power_measurement_typesList = NULL;
    }
    return NULL;

}
