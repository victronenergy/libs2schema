#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_sequence_element.h>



static ppbc_power_sequence_element_t *ppbc_power_sequence_element_create_internal(
    int *duration,
    list_t *power_values
    ) {
    ppbc_power_sequence_element_t *ppbc_power_sequence_element_local_var = malloc(sizeof(ppbc_power_sequence_element_t));
    if (!ppbc_power_sequence_element_local_var) {
        return NULL;
    }
    memset(ppbc_power_sequence_element_local_var, 0, sizeof(ppbc_power_sequence_element_t));
    ppbc_power_sequence_element_local_var->_library_owned = 1;
    ppbc_power_sequence_element_local_var->duration = duration;
    ppbc_power_sequence_element_local_var->power_values = power_values;
    return ppbc_power_sequence_element_local_var;
}

__attribute__((deprecated)) ppbc_power_sequence_element_t *ppbc_power_sequence_element_create(
    int *duration,
    list_t *power_values
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    ppbc_power_sequence_element_t *result = ppbc_power_sequence_element_create_internal (
        duration_copy,
        power_values
        );
    if (!result) {
        free(duration_copy);
    }
    return result;
}

void ppbc_power_sequence_element_free(ppbc_power_sequence_element_t *ppbc_power_sequence_element) {
    if(NULL == ppbc_power_sequence_element){
        return ;
    }
    if(ppbc_power_sequence_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_sequence_element_free");
        return ;
    }
    if (ppbc_power_sequence_element->duration) {
        free(ppbc_power_sequence_element->duration);
        ppbc_power_sequence_element->duration = NULL;
    }
    if (ppbc_power_sequence_element->power_values) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ppbc_power_sequence_element->power_values) {
            power_forecast_value_free(listEntry->data);
        }
        list_freeList(ppbc_power_sequence_element->power_values);
        ppbc_power_sequence_element->power_values = NULL;
    }
    free(ppbc_power_sequence_element);
}

cJSON *ppbc_power_sequence_element_convertToJSON(ppbc_power_sequence_element_t *ppbc_power_sequence_element) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_sequence_element->duration
    if (!ppbc_power_sequence_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *ppbc_power_sequence_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // ppbc_power_sequence_element->power_values
    if (!ppbc_power_sequence_element->power_values) {
        goto fail;
    }
    cJSON *power_values = cJSON_AddArrayToObject(item, "power_values");
    if(power_values == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_valuesListEntry;
    if (ppbc_power_sequence_element->power_values) {
    list_ForEach(power_valuesListEntry, ppbc_power_sequence_element->power_values) {
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

ppbc_power_sequence_element_t *ppbc_power_sequence_element_parseFromJSON(cJSON *ppbc_power_sequence_elementJSON){

    ppbc_power_sequence_element_t *ppbc_power_sequence_element_local_var = NULL;

    // define the local variable for ppbc_power_sequence_element->duration
    int *duration_local_var = NULL;

    // define the local list for ppbc_power_sequence_element->power_values
    list_t *power_valuesList = NULL;

    // ppbc_power_sequence_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_elementJSON, "duration");
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

    // ppbc_power_sequence_element->power_values
    cJSON *power_values = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_elementJSON, "power_values");
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



    ppbc_power_sequence_element_local_var = ppbc_power_sequence_element_create_internal (
        duration_local_var,
        power_valuesList
        );

    if (!ppbc_power_sequence_element_local_var) {
        goto end;
    }

    return ppbc_power_sequence_element_local_var;
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
