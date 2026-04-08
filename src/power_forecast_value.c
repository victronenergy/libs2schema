#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_forecast_value.h>



static power_forecast_value_t *power_forecast_value_create_internal(
    double *value_upper_limit,
    double *value_upper_95_ppr,
    double *value_upper_68_ppr,
    double *value_expected,
    double *value_lower_68_ppr,
    double *value_lower_95_ppr,
    double *value_lower_limit,
    s2_commodity_quantity__e commodity_quantity
    ) {
    power_forecast_value_t *power_forecast_value_local_var = malloc(sizeof(power_forecast_value_t));
    if (!power_forecast_value_local_var) {
        return NULL;
    }
    memset(power_forecast_value_local_var, 0, sizeof(power_forecast_value_t));
    power_forecast_value_local_var->_library_owned = 1;
    power_forecast_value_local_var->value_upper_limit = value_upper_limit;
    power_forecast_value_local_var->value_upper_95_ppr = value_upper_95_ppr;
    power_forecast_value_local_var->value_upper_68_ppr = value_upper_68_ppr;
    power_forecast_value_local_var->value_expected = value_expected;
    power_forecast_value_local_var->value_lower_68_ppr = value_lower_68_ppr;
    power_forecast_value_local_var->value_lower_95_ppr = value_lower_95_ppr;
    power_forecast_value_local_var->value_lower_limit = value_lower_limit;
    power_forecast_value_local_var->commodity_quantity = commodity_quantity;
    return power_forecast_value_local_var;
}

__attribute__((deprecated)) power_forecast_value_t *power_forecast_value_create(
    double *value_upper_limit,
    double *value_upper_95_ppr,
    double *value_upper_68_ppr,
    double *value_expected,
    double *value_lower_68_ppr,
    double *value_lower_95_ppr,
    double *value_lower_limit,
    s2_commodity_quantity__e commodity_quantity
    ) {
    double *value_upper_limit_copy = NULL;
    if (value_upper_limit) {
        value_upper_limit_copy = malloc(sizeof(double));
        if (value_upper_limit_copy) *value_upper_limit_copy = *value_upper_limit;
    }
    double *value_upper_95_ppr_copy = NULL;
    if (value_upper_95_ppr) {
        value_upper_95_ppr_copy = malloc(sizeof(double));
        if (value_upper_95_ppr_copy) *value_upper_95_ppr_copy = *value_upper_95_ppr;
    }
    double *value_upper_68_ppr_copy = NULL;
    if (value_upper_68_ppr) {
        value_upper_68_ppr_copy = malloc(sizeof(double));
        if (value_upper_68_ppr_copy) *value_upper_68_ppr_copy = *value_upper_68_ppr;
    }
    double *value_expected_copy = NULL;
    if (value_expected) {
        value_expected_copy = malloc(sizeof(double));
        if (value_expected_copy) *value_expected_copy = *value_expected;
    }
    double *value_lower_68_ppr_copy = NULL;
    if (value_lower_68_ppr) {
        value_lower_68_ppr_copy = malloc(sizeof(double));
        if (value_lower_68_ppr_copy) *value_lower_68_ppr_copy = *value_lower_68_ppr;
    }
    double *value_lower_95_ppr_copy = NULL;
    if (value_lower_95_ppr) {
        value_lower_95_ppr_copy = malloc(sizeof(double));
        if (value_lower_95_ppr_copy) *value_lower_95_ppr_copy = *value_lower_95_ppr;
    }
    double *value_lower_limit_copy = NULL;
    if (value_lower_limit) {
        value_lower_limit_copy = malloc(sizeof(double));
        if (value_lower_limit_copy) *value_lower_limit_copy = *value_lower_limit;
    }
    power_forecast_value_t *result = power_forecast_value_create_internal (
        value_upper_limit_copy,
        value_upper_95_ppr_copy,
        value_upper_68_ppr_copy,
        value_expected_copy,
        value_lower_68_ppr_copy,
        value_lower_95_ppr_copy,
        value_lower_limit_copy,
        commodity_quantity
        );
    if (!result) {
        free(value_upper_limit_copy);
        free(value_upper_95_ppr_copy);
        free(value_upper_68_ppr_copy);
        free(value_expected_copy);
        free(value_lower_68_ppr_copy);
        free(value_lower_95_ppr_copy);
        free(value_lower_limit_copy);
    }
    return result;
}

void power_forecast_value_free(power_forecast_value_t *power_forecast_value) {
    if(NULL == power_forecast_value){
        return ;
    }
    if(power_forecast_value->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_forecast_value_free");
        return ;
    }
    listEntry_t *listEntry;
    if (power_forecast_value->value_upper_limit) {
        free(power_forecast_value->value_upper_limit);
        power_forecast_value->value_upper_limit = NULL;
    }
    if (power_forecast_value->value_upper_95_ppr) {
        free(power_forecast_value->value_upper_95_ppr);
        power_forecast_value->value_upper_95_ppr = NULL;
    }
    if (power_forecast_value->value_upper_68_ppr) {
        free(power_forecast_value->value_upper_68_ppr);
        power_forecast_value->value_upper_68_ppr = NULL;
    }
    if (power_forecast_value->value_expected) {
        free(power_forecast_value->value_expected);
        power_forecast_value->value_expected = NULL;
    }
    if (power_forecast_value->value_lower_68_ppr) {
        free(power_forecast_value->value_lower_68_ppr);
        power_forecast_value->value_lower_68_ppr = NULL;
    }
    if (power_forecast_value->value_lower_95_ppr) {
        free(power_forecast_value->value_lower_95_ppr);
        power_forecast_value->value_lower_95_ppr = NULL;
    }
    if (power_forecast_value->value_lower_limit) {
        free(power_forecast_value->value_lower_limit);
        power_forecast_value->value_lower_limit = NULL;
    }
    free(power_forecast_value);
}

cJSON *power_forecast_value_convertToJSON(power_forecast_value_t *power_forecast_value) {
    cJSON *item = cJSON_CreateObject();

    // power_forecast_value->value_upper_limit
    if(power_forecast_value->value_upper_limit) {
    if(cJSON_AddNumberToObject(item, "value_upper_limit", *power_forecast_value->value_upper_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->value_upper_95_ppr
    if(power_forecast_value->value_upper_95_ppr) {
    if(cJSON_AddNumberToObject(item, "value_upper_95PPR", *power_forecast_value->value_upper_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->value_upper_68_ppr
    if(power_forecast_value->value_upper_68_ppr) {
    if(cJSON_AddNumberToObject(item, "value_upper_68PPR", *power_forecast_value->value_upper_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->value_expected
    if (!power_forecast_value->value_expected) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "value_expected", *power_forecast_value->value_expected) == NULL) {
    goto fail; //Numeric
    }


    // power_forecast_value->value_lower_68_ppr
    if(power_forecast_value->value_lower_68_ppr) {
    if(cJSON_AddNumberToObject(item, "value_lower_68PPR", *power_forecast_value->value_lower_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->value_lower_95_ppr
    if(power_forecast_value->value_lower_95_ppr) {
    if(cJSON_AddNumberToObject(item, "value_lower_95PPR", *power_forecast_value->value_lower_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->value_lower_limit
    if(power_forecast_value->value_lower_limit) {
    if(cJSON_AddNumberToObject(item, "value_lower_limit", *power_forecast_value->value_lower_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // power_forecast_value->commodity_quantity
    if (s2_commodity_quantity__NULL == power_forecast_value->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(power_forecast_value->commodity_quantity);
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

power_forecast_value_t *power_forecast_value_parseFromJSON(cJSON *power_forecast_valueJSON){

    power_forecast_value_t *power_forecast_value_local_var = NULL;

    // define the local variable for power_forecast_value->value_upper_limit
    double *value_upper_limit_local_var = NULL;

    // define the local variable for power_forecast_value->value_upper_95_ppr
    double *value_upper_95_ppr_local_var = NULL;

    // define the local variable for power_forecast_value->value_upper_68_ppr
    double *value_upper_68_ppr_local_var = NULL;

    // define the local variable for power_forecast_value->value_expected
    double *value_expected_local_var = NULL;

    // define the local variable for power_forecast_value->value_lower_68_ppr
    double *value_lower_68_ppr_local_var = NULL;

    // define the local variable for power_forecast_value->value_lower_95_ppr
    double *value_lower_95_ppr_local_var = NULL;

    // define the local variable for power_forecast_value->value_lower_limit
    double *value_lower_limit_local_var = NULL;

    // define the local variable for power_forecast_value->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // power_forecast_value->value_upper_limit
    cJSON *value_upper_limit = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_upper_limit");
    if (cJSON_IsNull(value_upper_limit)) {
        value_upper_limit = NULL;
    }
    if (value_upper_limit) { 
    if(!cJSON_IsNumber(value_upper_limit))
    {
    goto end; //Numeric
    }
    value_upper_limit_local_var = malloc(sizeof(double));
    if(!value_upper_limit_local_var)
    {
        goto end;
    }
    *value_upper_limit_local_var = value_upper_limit->valuedouble;
    }

    // power_forecast_value->value_upper_95_ppr
    cJSON *value_upper_95_ppr = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_upper_95PPR");
    if (cJSON_IsNull(value_upper_95_ppr)) {
        value_upper_95_ppr = NULL;
    }
    if (value_upper_95_ppr) { 
    if(!cJSON_IsNumber(value_upper_95_ppr))
    {
    goto end; //Numeric
    }
    value_upper_95_ppr_local_var = malloc(sizeof(double));
    if(!value_upper_95_ppr_local_var)
    {
        goto end;
    }
    *value_upper_95_ppr_local_var = value_upper_95_ppr->valuedouble;
    }

    // power_forecast_value->value_upper_68_ppr
    cJSON *value_upper_68_ppr = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_upper_68PPR");
    if (cJSON_IsNull(value_upper_68_ppr)) {
        value_upper_68_ppr = NULL;
    }
    if (value_upper_68_ppr) { 
    if(!cJSON_IsNumber(value_upper_68_ppr))
    {
    goto end; //Numeric
    }
    value_upper_68_ppr_local_var = malloc(sizeof(double));
    if(!value_upper_68_ppr_local_var)
    {
        goto end;
    }
    *value_upper_68_ppr_local_var = value_upper_68_ppr->valuedouble;
    }

    // power_forecast_value->value_expected
    cJSON *value_expected = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_expected");
    if (cJSON_IsNull(value_expected)) {
        value_expected = NULL;
    }
    if (!value_expected) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value_expected))
    {
    goto end; //Numeric
    }
    value_expected_local_var = malloc(sizeof(double));
    if(!value_expected_local_var)
    {
        goto end;
    }
    *value_expected_local_var = value_expected->valuedouble;

    // power_forecast_value->value_lower_68_ppr
    cJSON *value_lower_68_ppr = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_lower_68PPR");
    if (cJSON_IsNull(value_lower_68_ppr)) {
        value_lower_68_ppr = NULL;
    }
    if (value_lower_68_ppr) { 
    if(!cJSON_IsNumber(value_lower_68_ppr))
    {
    goto end; //Numeric
    }
    value_lower_68_ppr_local_var = malloc(sizeof(double));
    if(!value_lower_68_ppr_local_var)
    {
        goto end;
    }
    *value_lower_68_ppr_local_var = value_lower_68_ppr->valuedouble;
    }

    // power_forecast_value->value_lower_95_ppr
    cJSON *value_lower_95_ppr = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_lower_95PPR");
    if (cJSON_IsNull(value_lower_95_ppr)) {
        value_lower_95_ppr = NULL;
    }
    if (value_lower_95_ppr) { 
    if(!cJSON_IsNumber(value_lower_95_ppr))
    {
    goto end; //Numeric
    }
    value_lower_95_ppr_local_var = malloc(sizeof(double));
    if(!value_lower_95_ppr_local_var)
    {
        goto end;
    }
    *value_lower_95_ppr_local_var = value_lower_95_ppr->valuedouble;
    }

    // power_forecast_value->value_lower_limit
    cJSON *value_lower_limit = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "value_lower_limit");
    if (cJSON_IsNull(value_lower_limit)) {
        value_lower_limit = NULL;
    }
    if (value_lower_limit) { 
    if(!cJSON_IsNumber(value_lower_limit))
    {
    goto end; //Numeric
    }
    value_lower_limit_local_var = malloc(sizeof(double));
    if(!value_lower_limit_local_var)
    {
        goto end;
    }
    *value_lower_limit_local_var = value_lower_limit->valuedouble;
    }

    // power_forecast_value->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(power_forecast_valueJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom



    power_forecast_value_local_var = power_forecast_value_create_internal (
        value_upper_limit_local_var,
        value_upper_95_ppr_local_var,
        value_upper_68_ppr_local_var,
        value_expected_local_var,
        value_lower_68_ppr_local_var,
        value_lower_95_ppr_local_var,
        value_lower_limit_local_var,
        commodity_quantity_local_nonprim
        );

    if (!power_forecast_value_local_var) {
        goto end;
    }

    return power_forecast_value_local_var;
end:
    if (value_upper_limit_local_var) {
        free(value_upper_limit_local_var);
        value_upper_limit_local_var = NULL;
    }
    if (value_upper_95_ppr_local_var) {
        free(value_upper_95_ppr_local_var);
        value_upper_95_ppr_local_var = NULL;
    }
    if (value_upper_68_ppr_local_var) {
        free(value_upper_68_ppr_local_var);
        value_upper_68_ppr_local_var = NULL;
    }
    if (value_expected_local_var) {
        free(value_expected_local_var);
        value_expected_local_var = NULL;
    }
    if (value_lower_68_ppr_local_var) {
        free(value_lower_68_ppr_local_var);
        value_lower_68_ppr_local_var = NULL;
    }
    if (value_lower_95_ppr_local_var) {
        free(value_lower_95_ppr_local_var);
        value_lower_95_ppr_local_var = NULL;
    }
    if (value_lower_limit_local_var) {
        free(value_lower_limit_local_var);
        value_lower_limit_local_var = NULL;
    }
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    return NULL;

}
