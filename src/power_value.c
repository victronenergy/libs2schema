#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_value.h>



static power_value_t *power_value_create_internal(
    s2_commodity_quantity__e commodity_quantity,
    double *value
    ) {
    power_value_t *power_value_local_var = malloc(sizeof(power_value_t));
    if (!power_value_local_var) {
        return NULL;
    }
    memset(power_value_local_var, 0, sizeof(power_value_t));
    power_value_local_var->_library_owned = 1;
    power_value_local_var->commodity_quantity = commodity_quantity;
    power_value_local_var->value = value;
    return power_value_local_var;
}

__attribute__((deprecated)) power_value_t *power_value_create(
    s2_commodity_quantity__e commodity_quantity,
    double *value
    ) {
    double *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(double));
        if (value_copy) *value_copy = *value;
    }
    power_value_t *result = power_value_create_internal (
        commodity_quantity,
        value_copy
        );
    if (!result) {
        free(value_copy);
    }
    return result;
}

void power_value_free(power_value_t *power_value) {
    if(NULL == power_value){
        return ;
    }
    if(power_value->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_value_free");
        return ;
    }
    if (power_value->value) {
        free(power_value->value);
        power_value->value = NULL;
    }
    free(power_value);
}

cJSON *power_value_convertToJSON(power_value_t *power_value) {
    cJSON *item = cJSON_CreateObject();

    // power_value->commodity_quantity
    if (s2_commodity_quantity__NULL == power_value->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(power_value->commodity_quantity);
    if(commodity_quantity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity_quantity", commodity_quantity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // power_value->value
    if (!power_value->value) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "value", *power_value->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

power_value_t *power_value_parseFromJSON(cJSON *power_valueJSON){

    power_value_t *power_value_local_var = NULL;

    // define the local variable for power_value->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // define the local variable for power_value->value
    double *value_local_var = NULL;

    // power_value->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(power_valueJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom

    // power_value->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(power_valueJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(double));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;



    power_value_local_var = power_value_create_internal (
        commodity_quantity_local_nonprim,
        value_local_var
        );

    if (!power_value_local_var) {
        goto end;
    }

    return power_value_local_var;
end:
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    return NULL;

}
