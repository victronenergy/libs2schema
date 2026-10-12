#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_forecast_element.h>



static power_forecast_element_t *power_forecast_element_create_internal(
    int *duration,
    list_t *power_values
    ) {
    power_forecast_element_t *power_forecast_element_local_var = malloc(sizeof(power_forecast_element_t));
    if (!power_forecast_element_local_var) {
        return NULL;
    }
    memset(power_forecast_element_local_var, 0, sizeof(power_forecast_element_t));
    power_forecast_element_local_var->_library_owned = 1;
    power_forecast_element_local_var->duration = duration;
    power_forecast_element_local_var->power_values = power_values;
    return power_forecast_element_local_var;
}

__attribute__((deprecated)) power_forecast_element_t *power_forecast_element_create(
    int *duration,
    list_t *power_values
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    power_forecast_element_t *result = power_forecast_element_create_internal (
        duration_copy,
        power_values
        );
    if (!result) {
        free(duration_copy);
    }
    return result;
}

void power_forecast_element_free(power_forecast_element_t *power_forecast_element) {
    if(NULL == power_forecast_element){
        return ;
    }
    if(power_forecast_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_forecast_element_free");
        return ;
    }
    if (power_forecast_element->duration) {
        free(power_forecast_element->duration);
        power_forecast_element->duration = NULL;
    }
    if (power_forecast_element->power_values) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, power_forecast_element->power_values) {
            power_forecast_value_free(listEntry->data);
        }
        list_freeList(power_forecast_element->power_values);
        power_forecast_element->power_values = NULL;
    }
    free(power_forecast_element);
}

cJSON *power_forecast_element_convertToJSON(power_forecast_element_t *power_forecast_element) {
    cJSON *item = cJSON_CreateObject();

    // power_forecast_element->duration
    if (!power_forecast_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *power_forecast_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // power_forecast_element->power_values
    if (!power_forecast_element->power_values) {
        goto fail;
    }
    cJSON *power_values = cJSON_AddArrayToObject(item, "power_values");
    if(power_values == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_valuesListEntry;
    if (power_forecast_element->power_values) {
    list_ForEach(power_valuesListEntry, power_forecast_element->power_values) {
    cJSON *itemLocal = power_forecast_value_convertToJSON(power_valuesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_values, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

power_forecast_element_t *power_forecast_element_parseFromJSON(cJSON *power_forecast_elementJSON){

    power_forecast_element_t *power_forecast_element_local_var = NULL;

    // define the local variable for power_forecast_element->duration
    int *duration_local_var = NULL;

    // define the local list for power_forecast_element->power_values
    list_t *power_valuesList = NULL;

    // power_forecast_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(power_forecast_elementJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    duration_local_var = malloc(sizeof(int));
    if(!duration_local_var)
    {
        goto end;
    }
    *duration_local_var = duration->valuedouble;

    // power_forecast_element->power_values
    cJSON *power_values = cJSON_GetObjectItemCaseSensitive(power_forecast_elementJSON, "power_values");
    if (cJSON_IsNull(power_values)) {
        power_values = NULL;
    }
    if (!power_values) {
        goto end;
    }

    
    cJSON *power_values_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_values)){
        goto end; //nonprimitive container
    }

    power_valuesList = list_createList();

    cJSON_ArrayForEach(power_values_local_nonprimitive,power_values )
    {
        if(!cJSON_IsObject(power_values_local_nonprimitive)){
            goto end;
        }
        power_forecast_value_t *power_valuesItem = power_forecast_value_parseFromJSON(power_values_local_nonprimitive);

        list_addElement(power_valuesList, power_valuesItem);
    }



    power_forecast_element_local_var = power_forecast_element_create_internal (
        duration_local_var,
        power_valuesList
        );

    if (!power_forecast_element_local_var) {
        goto end;
    }

    return power_forecast_element_local_var;
end:
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    if (power_valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_valuesList) {
            power_forecast_value_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_valuesList);
        power_valuesList = NULL;
    }
    return NULL;

}
