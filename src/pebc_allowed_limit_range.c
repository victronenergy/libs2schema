#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_allowed_limit_range.h>



static pebc_allowed_limit_range_t *pebc_allowed_limit_range_create_internal(
    s2_commodity_quantity__e commodity_quantity,
    s2_pebc_power_envelope_limit_type__e limit_type,
    number_range_t *range_boundary,
    int *abnormal_condition_only
    ) {
    pebc_allowed_limit_range_t *pebc_allowed_limit_range_local_var = malloc(sizeof(pebc_allowed_limit_range_t));
    if (!pebc_allowed_limit_range_local_var) {
        return NULL;
    }
    memset(pebc_allowed_limit_range_local_var, 0, sizeof(pebc_allowed_limit_range_t));
    pebc_allowed_limit_range_local_var->_library_owned = 1;
    pebc_allowed_limit_range_local_var->commodity_quantity = commodity_quantity;
    pebc_allowed_limit_range_local_var->limit_type = limit_type;
    pebc_allowed_limit_range_local_var->range_boundary = range_boundary;
    pebc_allowed_limit_range_local_var->abnormal_condition_only = abnormal_condition_only;
    return pebc_allowed_limit_range_local_var;
}

__attribute__((deprecated)) pebc_allowed_limit_range_t *pebc_allowed_limit_range_create(
    s2_commodity_quantity__e commodity_quantity,
    s2_pebc_power_envelope_limit_type__e limit_type,
    number_range_t *range_boundary,
    int *abnormal_condition_only
    ) {
    int *abnormal_condition_only_copy = NULL;
    if (abnormal_condition_only) {
        abnormal_condition_only_copy = malloc(sizeof(int));
        if (abnormal_condition_only_copy) *abnormal_condition_only_copy = *abnormal_condition_only;
    }
    pebc_allowed_limit_range_t *result = pebc_allowed_limit_range_create_internal (
        commodity_quantity,
        limit_type,
        range_boundary,
        abnormal_condition_only_copy
        );
    if (!result) {
        free(abnormal_condition_only_copy);
    }
    return result;
}

void pebc_allowed_limit_range_free(pebc_allowed_limit_range_t *pebc_allowed_limit_range) {
    if(NULL == pebc_allowed_limit_range){
        return ;
    }
    if(pebc_allowed_limit_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_allowed_limit_range_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pebc_allowed_limit_range->range_boundary) {
        number_range_free(pebc_allowed_limit_range->range_boundary);
        pebc_allowed_limit_range->range_boundary = NULL;
    }
    if (pebc_allowed_limit_range->abnormal_condition_only) {
        free(pebc_allowed_limit_range->abnormal_condition_only);
        pebc_allowed_limit_range->abnormal_condition_only = NULL;
    }
    free(pebc_allowed_limit_range);
}

cJSON *pebc_allowed_limit_range_convertToJSON(pebc_allowed_limit_range_t *pebc_allowed_limit_range) {
    cJSON *item = cJSON_CreateObject();

    // pebc_allowed_limit_range->commodity_quantity
    if (s2_commodity_quantity__NULL == pebc_allowed_limit_range->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(pebc_allowed_limit_range->commodity_quantity);
    if(commodity_quantity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity_quantity", commodity_quantity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // pebc_allowed_limit_range->limit_type
    if (s2_pebc_power_envelope_limit_type__NULL == pebc_allowed_limit_range->limit_type) {
        goto fail;
    }
    cJSON *limit_type_local_JSON = pebc_power_envelope_limit_type_convertToJSON(pebc_allowed_limit_range->limit_type);
    if(limit_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "limit_type", limit_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // pebc_allowed_limit_range->range_boundary
    if (!pebc_allowed_limit_range->range_boundary) {
        goto fail;
    }
    cJSON *range_boundary_local_JSON = number_range_convertToJSON(pebc_allowed_limit_range->range_boundary);
    if(range_boundary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "range_boundary", range_boundary_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // pebc_allowed_limit_range->abnormal_condition_only
    if (!pebc_allowed_limit_range->abnormal_condition_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition_only", *pebc_allowed_limit_range->abnormal_condition_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_allowed_limit_range_t *pebc_allowed_limit_range_parseFromJSON(cJSON *pebc_allowed_limit_rangeJSON){

    pebc_allowed_limit_range_t *pebc_allowed_limit_range_local_var = NULL;

    // define the local variable for pebc_allowed_limit_range->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // define the local variable for pebc_allowed_limit_range->limit_type
    s2_pebc_power_envelope_limit_type__e limit_type_local_nonprim = 0;

    // define the local variable for pebc_allowed_limit_range->range_boundary
    number_range_t *range_boundary_local_nonprim = NULL;

    // define the local variable for pebc_allowed_limit_range->abnormal_condition_only
    int *abnormal_condition_only_local_var = NULL;

    // pebc_allowed_limit_range->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(pebc_allowed_limit_rangeJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom

    // pebc_allowed_limit_range->limit_type
    cJSON *limit_type = cJSON_GetObjectItemCaseSensitive(pebc_allowed_limit_rangeJSON, "limit_type");
    if (cJSON_IsNull(limit_type)) {
        limit_type = NULL;
    }
    if (!limit_type) {
        goto end;
    }

    
    limit_type_local_nonprim = pebc_power_envelope_limit_type_parseFromJSON(limit_type); //custom

    // pebc_allowed_limit_range->range_boundary
    cJSON *range_boundary = cJSON_GetObjectItemCaseSensitive(pebc_allowed_limit_rangeJSON, "range_boundary");
    if (cJSON_IsNull(range_boundary)) {
        range_boundary = NULL;
    }
    if (!range_boundary) {
        goto end;
    }

    
    range_boundary_local_nonprim = number_range_parseFromJSON(range_boundary); //nonprimitive

    // pebc_allowed_limit_range->abnormal_condition_only
    cJSON *abnormal_condition_only = cJSON_GetObjectItemCaseSensitive(pebc_allowed_limit_rangeJSON, "abnormal_condition_only");
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



    pebc_allowed_limit_range_local_var = pebc_allowed_limit_range_create_internal (
        commodity_quantity_local_nonprim,
        limit_type_local_nonprim,
        range_boundary_local_nonprim,
        abnormal_condition_only_local_var
        );

    if (!pebc_allowed_limit_range_local_var) {
        goto end;
    }

    return pebc_allowed_limit_range_local_var;
end:
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    if (limit_type_local_nonprim) {
        limit_type_local_nonprim = 0;
    }
    if (range_boundary_local_nonprim) {
        number_range_free(range_boundary_local_nonprim);
        range_boundary_local_nonprim = NULL;
    }
    if (abnormal_condition_only_local_var) {
        free(abnormal_condition_only_local_var);
        abnormal_condition_only_local_var = NULL;
    }
    return NULL;

}
