#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_operation_mode.h>



static ddbc_operation_mode_t *ddbc_operation_mode_create_internal(
    char *id,
    char *diagnostic_label,
    list_t *power_ranges,
    number_range_t *supply_range,
    number_range_t *running_costs,
    int *abnormal_condition_only
    ) {
    ddbc_operation_mode_t *ddbc_operation_mode_local_var = malloc(sizeof(ddbc_operation_mode_t));
    if (!ddbc_operation_mode_local_var) {
        return NULL;
    }
    memset(ddbc_operation_mode_local_var, 0, sizeof(ddbc_operation_mode_t));
    ddbc_operation_mode_local_var->_library_owned = 1;
    ddbc_operation_mode_local_var->id = id;
    ddbc_operation_mode_local_var->diagnostic_label = diagnostic_label;
    ddbc_operation_mode_local_var->power_ranges = power_ranges;
    ddbc_operation_mode_local_var->supply_range = supply_range;
    ddbc_operation_mode_local_var->running_costs = running_costs;
    ddbc_operation_mode_local_var->abnormal_condition_only = abnormal_condition_only;
    return ddbc_operation_mode_local_var;
}

__attribute__((deprecated)) ddbc_operation_mode_t *ddbc_operation_mode_create(
    char *id,
    char *diagnostic_label,
    list_t *power_ranges,
    number_range_t *supply_range,
    number_range_t *running_costs,
    int *abnormal_condition_only
    ) {
    int *abnormal_condition_only_copy = NULL;
    if (abnormal_condition_only) {
        abnormal_condition_only_copy = malloc(sizeof(int));
        if (abnormal_condition_only_copy) *abnormal_condition_only_copy = *abnormal_condition_only;
    }
    ddbc_operation_mode_t *result = ddbc_operation_mode_create_internal (
        id,
        diagnostic_label,
        power_ranges,
        supply_range,
        running_costs,
        abnormal_condition_only_copy
        );
    if (!result) {
        free(abnormal_condition_only_copy);
    }
    return result;
}

void ddbc_operation_mode_free(ddbc_operation_mode_t *ddbc_operation_mode) {
    if(NULL == ddbc_operation_mode){
        return ;
    }
    if(ddbc_operation_mode->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_operation_mode_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ddbc_operation_mode->id) {
        free(ddbc_operation_mode->id);
        ddbc_operation_mode->id = NULL;
    }
    if (ddbc_operation_mode->diagnostic_label) {
        free(ddbc_operation_mode->diagnostic_label);
        ddbc_operation_mode->diagnostic_label = NULL;
    }
    if (ddbc_operation_mode->power_ranges) {
        list_ForEach(listEntry, ddbc_operation_mode->power_ranges) {
            power_range_free(listEntry->data);
        }
        list_freeList(ddbc_operation_mode->power_ranges);
        ddbc_operation_mode->power_ranges = NULL;
    }
    if (ddbc_operation_mode->supply_range) {
        number_range_free(ddbc_operation_mode->supply_range);
        ddbc_operation_mode->supply_range = NULL;
    }
    if (ddbc_operation_mode->running_costs) {
        number_range_free(ddbc_operation_mode->running_costs);
        ddbc_operation_mode->running_costs = NULL;
    }
    if (ddbc_operation_mode->abnormal_condition_only) {
        free(ddbc_operation_mode->abnormal_condition_only);
        ddbc_operation_mode->abnormal_condition_only = NULL;
    }
    free(ddbc_operation_mode);
}

cJSON *ddbc_operation_mode_convertToJSON(ddbc_operation_mode_t *ddbc_operation_mode) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_operation_mode->id
    if (!ddbc_operation_mode->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "Id", ddbc_operation_mode->id) == NULL) {
    goto fail; //String
    }


    // ddbc_operation_mode->diagnostic_label
    if(ddbc_operation_mode->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", ddbc_operation_mode->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // ddbc_operation_mode->power_ranges
    if (!ddbc_operation_mode->power_ranges) {
        goto fail;
    }
    cJSON *power_ranges = cJSON_AddArrayToObject(item, "power_ranges");
    if(power_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_rangesListEntry;
    if (ddbc_operation_mode->power_ranges) {
    list_ForEach(power_rangesListEntry, ddbc_operation_mode->power_ranges) {
    cJSON *itemLocal = power_range_convertToJSON(power_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_ranges, itemLocal);
    }
    }


    // ddbc_operation_mode->supply_range
    if (!ddbc_operation_mode->supply_range) {
        goto fail;
    }
    cJSON *supply_range_local_JSON = number_range_convertToJSON(ddbc_operation_mode->supply_range);
    if(supply_range_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "supply_range", supply_range_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ddbc_operation_mode->running_costs
    if(ddbc_operation_mode->running_costs) {
    cJSON *running_costs_local_JSON = number_range_convertToJSON(ddbc_operation_mode->running_costs);
    if(running_costs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "running_costs", running_costs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ddbc_operation_mode->abnormal_condition_only
    if (!ddbc_operation_mode->abnormal_condition_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition_only", *ddbc_operation_mode->abnormal_condition_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ddbc_operation_mode_t *ddbc_operation_mode_parseFromJSON(cJSON *ddbc_operation_modeJSON){

    ddbc_operation_mode_t *ddbc_operation_mode_local_var = NULL;

    char *id_local_str = NULL;

    char *diagnostic_label_local_str = NULL;

    // define the local list for ddbc_operation_mode->power_ranges
    list_t *power_rangesList = NULL;

    // define the local variable for ddbc_operation_mode->supply_range
    number_range_t *supply_range_local_nonprim = NULL;

    // define the local variable for ddbc_operation_mode->running_costs
    number_range_t *running_costs_local_nonprim = NULL;

    // define the local variable for ddbc_operation_mode->abnormal_condition_only
    int *abnormal_condition_only_local_var = NULL;

    // ddbc_operation_mode->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "Id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // ddbc_operation_mode->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // ddbc_operation_mode->power_ranges
    cJSON *power_ranges = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "power_ranges");
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

    // ddbc_operation_mode->supply_range
    cJSON *supply_range = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "supply_range");
    if (cJSON_IsNull(supply_range)) {
        supply_range = NULL;
    }
    if (!supply_range) {
        goto end;
    }

    
    supply_range_local_nonprim = number_range_parseFromJSON(supply_range); //nonprimitive

    // ddbc_operation_mode->running_costs
    cJSON *running_costs = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "running_costs");
    if (cJSON_IsNull(running_costs)) {
        running_costs = NULL;
    }
    if (running_costs) { 
    running_costs_local_nonprim = number_range_parseFromJSON(running_costs); //nonprimitive
    }

    // ddbc_operation_mode->abnormal_condition_only
    cJSON *abnormal_condition_only = cJSON_GetObjectItemCaseSensitive(ddbc_operation_modeJSON, "abnormal_condition_only");
    if (cJSON_IsNull(abnormal_condition_only)) {
        abnormal_condition_only = NULL;
    }
    if (!abnormal_condition_only) {
        goto end;
    }

    
    if(!cJSON_IsBool(abnormal_condition_only))
    {
    goto end; //Bool
    }
    abnormal_condition_only_local_var = malloc(sizeof(int));
    if(!abnormal_condition_only_local_var)
    {
        goto end;
    }
    *abnormal_condition_only_local_var = abnormal_condition_only->valueint;


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    ddbc_operation_mode_local_var = ddbc_operation_mode_create_internal (
        id_local_str,
        diagnostic_label_local_str,
        power_rangesList,
        supply_range_local_nonprim,
        running_costs ? running_costs_local_nonprim : NULL,
        abnormal_condition_only_local_var
        );

    if (!ddbc_operation_mode_local_var) {
        goto end;
    }

    return ddbc_operation_mode_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
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
    if (supply_range_local_nonprim) {
        number_range_free(supply_range_local_nonprim);
        supply_range_local_nonprim = NULL;
    }
    if (running_costs_local_nonprim) {
        number_range_free(running_costs_local_nonprim);
        running_costs_local_nonprim = NULL;
    }
    if (abnormal_condition_only_local_var) {
        free(abnormal_condition_only_local_var);
        abnormal_condition_only_local_var = NULL;
    }
    return NULL;

}
