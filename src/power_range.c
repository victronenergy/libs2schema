#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_range.h>



static power_range_t *power_range_create_internal(
    double *start_of_range,
    double *end_of_range,
    s2_commodity_quantity__e commodity_quantity
    ) {
    power_range_t *power_range_local_var = malloc(sizeof(power_range_t));
    if (!power_range_local_var) {
        return NULL;
    }
    memset(power_range_local_var, 0, sizeof(power_range_t));
    power_range_local_var->_library_owned = 1;
    power_range_local_var->start_of_range = start_of_range;
    power_range_local_var->end_of_range = end_of_range;
    power_range_local_var->commodity_quantity = commodity_quantity;
    return power_range_local_var;
}

__attribute__((deprecated)) power_range_t *power_range_create(
    double *start_of_range,
    double *end_of_range,
    s2_commodity_quantity__e commodity_quantity
    ) {
    double *start_of_range_copy = NULL;
    if (start_of_range) {
        start_of_range_copy = malloc(sizeof(double));
        if (start_of_range_copy) *start_of_range_copy = *start_of_range;
    }
    double *end_of_range_copy = NULL;
    if (end_of_range) {
        end_of_range_copy = malloc(sizeof(double));
        if (end_of_range_copy) *end_of_range_copy = *end_of_range;
    }
    power_range_t *result = power_range_create_internal (
        start_of_range_copy,
        end_of_range_copy,
        commodity_quantity
        );
    if (!result) {
        free(start_of_range_copy);
        free(end_of_range_copy);
    }
    return result;
}

void power_range_free(power_range_t *power_range) {
    if(NULL == power_range){
        return ;
    }
    if(power_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_range_free");
        return ;
    }
    if (power_range->start_of_range) {
        free(power_range->start_of_range);
        power_range->start_of_range = NULL;
    }
    if (power_range->end_of_range) {
        free(power_range->end_of_range);
        power_range->end_of_range = NULL;
    }
    free(power_range);
}

cJSON *power_range_convertToJSON(power_range_t *power_range) {
    cJSON *item = cJSON_CreateObject();

    // power_range->start_of_range
    if (!power_range->start_of_range) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "start_of_range", *power_range->start_of_range) == NULL) {
    goto fail; //Numeric
    }


    // power_range->end_of_range
    if (!power_range->end_of_range) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "end_of_range", *power_range->end_of_range) == NULL) {
    goto fail; //Numeric
    }


    // power_range->commodity_quantity
    if (s2_commodity_quantity__NULL == power_range->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(power_range->commodity_quantity);
    if(commodity_quantity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity_quantity", commodity_quantity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

power_range_t *power_range_parseFromJSON(cJSON *power_rangeJSON){

    power_range_t *power_range_local_var = NULL;

    // define the local variable for power_range->start_of_range
    double *start_of_range_local_var = NULL;

    // define the local variable for power_range->end_of_range
    double *end_of_range_local_var = NULL;

    // define the local variable for power_range->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // power_range->start_of_range
    cJSON *start_of_range = cJSON_GetObjectItemCaseSensitive(power_rangeJSON, "start_of_range");
    if (cJSON_IsNull(start_of_range)) {
        start_of_range = NULL;
    }
    if (!start_of_range) {
        goto end;
    }

    
    if(!cJSON_IsNumber(start_of_range))
    {
    goto end; //Numeric
    }
    start_of_range_local_var = malloc(sizeof(double));
    if(!start_of_range_local_var)
    {
        goto end;
    }
    *start_of_range_local_var = start_of_range->valuedouble;

    // power_range->end_of_range
    cJSON *end_of_range = cJSON_GetObjectItemCaseSensitive(power_rangeJSON, "end_of_range");
    if (cJSON_IsNull(end_of_range)) {
        end_of_range = NULL;
    }
    if (!end_of_range) {
        goto end;
    }

    
    if(!cJSON_IsNumber(end_of_range))
    {
    goto end; //Numeric
    }
    end_of_range_local_var = malloc(sizeof(double));
    if(!end_of_range_local_var)
    {
        goto end;
    }
    *end_of_range_local_var = end_of_range->valuedouble;

    // power_range->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(power_rangeJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom



    power_range_local_var = power_range_create_internal (
        start_of_range_local_var,
        end_of_range_local_var,
        commodity_quantity_local_nonprim
        );

    if (!power_range_local_var) {
        goto end;
    }

    return power_range_local_var;
end:
    if (start_of_range_local_var) {
        free(start_of_range_local_var);
        start_of_range_local_var = NULL;
    }
    if (end_of_range_local_var) {
        free(end_of_range_local_var);
        end_of_range_local_var = NULL;
    }
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    return NULL;

}
