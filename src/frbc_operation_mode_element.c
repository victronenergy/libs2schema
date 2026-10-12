#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_operation_mode_element.h>



static frbc_operation_mode_element_t *frbc_operation_mode_element_create_internal(
    number_range_t *fill_level_range,
    number_range_t *fill_rate,
    list_t *power_ranges,
    number_range_t *running_costs
    ) {
    frbc_operation_mode_element_t *frbc_operation_mode_element_local_var = malloc(sizeof(frbc_operation_mode_element_t));
    if (!frbc_operation_mode_element_local_var) {
        return NULL;
    }
    memset(frbc_operation_mode_element_local_var, 0, sizeof(frbc_operation_mode_element_t));
    frbc_operation_mode_element_local_var->_library_owned = 1;
    frbc_operation_mode_element_local_var->fill_level_range = fill_level_range;
    frbc_operation_mode_element_local_var->fill_rate = fill_rate;
    frbc_operation_mode_element_local_var->power_ranges = power_ranges;
    frbc_operation_mode_element_local_var->running_costs = running_costs;
    return frbc_operation_mode_element_local_var;
}

__attribute__((deprecated)) frbc_operation_mode_element_t *frbc_operation_mode_element_create(
    number_range_t *fill_level_range,
    number_range_t *fill_rate,
    list_t *power_ranges,
    number_range_t *running_costs
    ) {
    frbc_operation_mode_element_t *result = frbc_operation_mode_element_create_internal (
        fill_level_range,
        fill_rate,
        power_ranges,
        running_costs
        );
    if (!result) {
    }
    return result;
}

void frbc_operation_mode_element_free(frbc_operation_mode_element_t *frbc_operation_mode_element) {
    if(NULL == frbc_operation_mode_element){
        return ;
    }
    if(frbc_operation_mode_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_operation_mode_element_free");
        return ;
    }
    if (frbc_operation_mode_element->fill_level_range) {
        number_range_free(frbc_operation_mode_element->fill_level_range);
        frbc_operation_mode_element->fill_level_range = NULL;
    }
    if (frbc_operation_mode_element->fill_rate) {
        number_range_free(frbc_operation_mode_element->fill_rate);
        frbc_operation_mode_element->fill_rate = NULL;
    }
    if (frbc_operation_mode_element->power_ranges) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, frbc_operation_mode_element->power_ranges) {
            power_range_free(listEntry->data);
        }
        list_freeList(frbc_operation_mode_element->power_ranges);
        frbc_operation_mode_element->power_ranges = NULL;
    }
    if (frbc_operation_mode_element->running_costs) {
        number_range_free(frbc_operation_mode_element->running_costs);
        frbc_operation_mode_element->running_costs = NULL;
    }
    free(frbc_operation_mode_element);
}

cJSON *frbc_operation_mode_element_convertToJSON(frbc_operation_mode_element_t *frbc_operation_mode_element) {
    cJSON *item = cJSON_CreateObject();

    // frbc_operation_mode_element->fill_level_range
    if (!frbc_operation_mode_element->fill_level_range) {
        goto fail;
    }
    cJSON *fill_level_range_local_JSON = number_range_convertToJSON(frbc_operation_mode_element->fill_level_range);
    if(fill_level_range_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill_level_range", fill_level_range_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // frbc_operation_mode_element->fill_rate
    if (!frbc_operation_mode_element->fill_rate) {
        goto fail;
    }
    cJSON *fill_rate_local_JSON = number_range_convertToJSON(frbc_operation_mode_element->fill_rate);
    if(fill_rate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill_rate", fill_rate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // frbc_operation_mode_element->power_ranges
    if (!frbc_operation_mode_element->power_ranges) {
        goto fail;
    }
    cJSON *power_ranges = cJSON_AddArrayToObject(item, "power_ranges");
    if(power_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_rangesListEntry;
    if (frbc_operation_mode_element->power_ranges) {
    list_ForEach(power_rangesListEntry, frbc_operation_mode_element->power_ranges) {
    cJSON *itemLocal = power_range_convertToJSON(power_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_ranges, itemLocal);
    }
    }


    // frbc_operation_mode_element->running_costs
    if(frbc_operation_mode_element->running_costs) {
    cJSON *running_costs_local_JSON = number_range_convertToJSON(frbc_operation_mode_element->running_costs);
    if(running_costs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "running_costs", running_costs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_operation_mode_element_t *frbc_operation_mode_element_parseFromJSON(cJSON *frbc_operation_mode_elementJSON){

    frbc_operation_mode_element_t *frbc_operation_mode_element_local_var = NULL;

    // define the local variable for frbc_operation_mode_element->fill_level_range
    number_range_t *fill_level_range_local_nonprim = NULL;

    // define the local variable for frbc_operation_mode_element->fill_rate
    number_range_t *fill_rate_local_nonprim = NULL;

    // define the local list for frbc_operation_mode_element->power_ranges
    list_t *power_rangesList = NULL;

    // define the local variable for frbc_operation_mode_element->running_costs
    number_range_t *running_costs_local_nonprim = NULL;

    // frbc_operation_mode_element->fill_level_range
    cJSON *fill_level_range = cJSON_GetObjectItemCaseSensitive(frbc_operation_mode_elementJSON, "fill_level_range");
    if (cJSON_IsNull(fill_level_range)) {
        fill_level_range = NULL;
    }
    if (!fill_level_range) {
        goto end;
    }

    
    fill_level_range_local_nonprim = number_range_parseFromJSON(fill_level_range); //nonprimitive

    // frbc_operation_mode_element->fill_rate
    cJSON *fill_rate = cJSON_GetObjectItemCaseSensitive(frbc_operation_mode_elementJSON, "fill_rate");
    if (cJSON_IsNull(fill_rate)) {
        fill_rate = NULL;
    }
    if (!fill_rate) {
        goto end;
    }

    
    fill_rate_local_nonprim = number_range_parseFromJSON(fill_rate); //nonprimitive

    // frbc_operation_mode_element->power_ranges
    cJSON *power_ranges = cJSON_GetObjectItemCaseSensitive(frbc_operation_mode_elementJSON, "power_ranges");
    if (cJSON_IsNull(power_ranges)) {
        power_ranges = NULL;
    }
    if (!power_ranges) {
        goto end;
    }

    
    cJSON *power_ranges_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_ranges)){
        goto end; //nonprimitive container
    }

    power_rangesList = list_createList();

    cJSON_ArrayForEach(power_ranges_local_nonprimitive,power_ranges )
    {
        if(!cJSON_IsObject(power_ranges_local_nonprimitive)){
            goto end;
        }
        power_range_t *power_rangesItem = power_range_parseFromJSON(power_ranges_local_nonprimitive);

        list_addElement(power_rangesList, power_rangesItem);
    }

    // frbc_operation_mode_element->running_costs
    cJSON *running_costs = cJSON_GetObjectItemCaseSensitive(frbc_operation_mode_elementJSON, "running_costs");
    if (cJSON_IsNull(running_costs)) {
        running_costs = NULL;
    }
    if (running_costs) { 
    running_costs_local_nonprim = number_range_parseFromJSON(running_costs); //nonprimitive
    }



    frbc_operation_mode_element_local_var = frbc_operation_mode_element_create_internal (
        fill_level_range_local_nonprim,
        fill_rate_local_nonprim,
        power_rangesList,
        running_costs ? running_costs_local_nonprim : NULL
        );

    if (!frbc_operation_mode_element_local_var) {
        goto end;
    }

    return frbc_operation_mode_element_local_var;
end:
    if (fill_level_range_local_nonprim) {
        number_range_free(fill_level_range_local_nonprim);
        fill_level_range_local_nonprim = NULL;
    }
    if (fill_rate_local_nonprim) {
        number_range_free(fill_rate_local_nonprim);
        fill_rate_local_nonprim = NULL;
    }
    if (power_rangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_rangesList) {
            power_range_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_rangesList);
        power_rangesList = NULL;
    }
    if (running_costs_local_nonprim) {
        number_range_free(running_costs_local_nonprim);
        running_costs_local_nonprim = NULL;
    }
    return NULL;

}
