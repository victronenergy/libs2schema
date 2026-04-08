#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_average_demand_rate_forecast_element.h>



static ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_create_internal(
    int *duration,
    double *demand_rate_upper_limit,
    double *demand_rate_upper_95_ppr,
    double *demand_rate_upper_68_ppr,
    double *demand_rate_expected,
    double *demand_rate_lower_68_ppr,
    double *demand_rate_lower_95_ppr,
    double *demand_rate_lower_limit
    ) {
    ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_local_var = malloc(sizeof(ddbc_average_demand_rate_forecast_element_t));
    if (!ddbc_average_demand_rate_forecast_element_local_var) {
        return NULL;
    }
    memset(ddbc_average_demand_rate_forecast_element_local_var, 0, sizeof(ddbc_average_demand_rate_forecast_element_t));
    ddbc_average_demand_rate_forecast_element_local_var->_library_owned = 1;
    ddbc_average_demand_rate_forecast_element_local_var->duration = duration;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_upper_limit = demand_rate_upper_limit;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_upper_95_ppr = demand_rate_upper_95_ppr;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_upper_68_ppr = demand_rate_upper_68_ppr;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_expected = demand_rate_expected;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_lower_68_ppr = demand_rate_lower_68_ppr;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_lower_95_ppr = demand_rate_lower_95_ppr;
    ddbc_average_demand_rate_forecast_element_local_var->demand_rate_lower_limit = demand_rate_lower_limit;
    return ddbc_average_demand_rate_forecast_element_local_var;
}

__attribute__((deprecated)) ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_create(
    int *duration,
    double *demand_rate_upper_limit,
    double *demand_rate_upper_95_ppr,
    double *demand_rate_upper_68_ppr,
    double *demand_rate_expected,
    double *demand_rate_lower_68_ppr,
    double *demand_rate_lower_95_ppr,
    double *demand_rate_lower_limit
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    double *demand_rate_upper_limit_copy = NULL;
    if (demand_rate_upper_limit) {
        demand_rate_upper_limit_copy = malloc(sizeof(double));
        if (demand_rate_upper_limit_copy) *demand_rate_upper_limit_copy = *demand_rate_upper_limit;
    }
    double *demand_rate_upper_95_ppr_copy = NULL;
    if (demand_rate_upper_95_ppr) {
        demand_rate_upper_95_ppr_copy = malloc(sizeof(double));
        if (demand_rate_upper_95_ppr_copy) *demand_rate_upper_95_ppr_copy = *demand_rate_upper_95_ppr;
    }
    double *demand_rate_upper_68_ppr_copy = NULL;
    if (demand_rate_upper_68_ppr) {
        demand_rate_upper_68_ppr_copy = malloc(sizeof(double));
        if (demand_rate_upper_68_ppr_copy) *demand_rate_upper_68_ppr_copy = *demand_rate_upper_68_ppr;
    }
    double *demand_rate_expected_copy = NULL;
    if (demand_rate_expected) {
        demand_rate_expected_copy = malloc(sizeof(double));
        if (demand_rate_expected_copy) *demand_rate_expected_copy = *demand_rate_expected;
    }
    double *demand_rate_lower_68_ppr_copy = NULL;
    if (demand_rate_lower_68_ppr) {
        demand_rate_lower_68_ppr_copy = malloc(sizeof(double));
        if (demand_rate_lower_68_ppr_copy) *demand_rate_lower_68_ppr_copy = *demand_rate_lower_68_ppr;
    }
    double *demand_rate_lower_95_ppr_copy = NULL;
    if (demand_rate_lower_95_ppr) {
        demand_rate_lower_95_ppr_copy = malloc(sizeof(double));
        if (demand_rate_lower_95_ppr_copy) *demand_rate_lower_95_ppr_copy = *demand_rate_lower_95_ppr;
    }
    double *demand_rate_lower_limit_copy = NULL;
    if (demand_rate_lower_limit) {
        demand_rate_lower_limit_copy = malloc(sizeof(double));
        if (demand_rate_lower_limit_copy) *demand_rate_lower_limit_copy = *demand_rate_lower_limit;
    }
    ddbc_average_demand_rate_forecast_element_t *result = ddbc_average_demand_rate_forecast_element_create_internal (
        duration_copy,
        demand_rate_upper_limit_copy,
        demand_rate_upper_95_ppr_copy,
        demand_rate_upper_68_ppr_copy,
        demand_rate_expected_copy,
        demand_rate_lower_68_ppr_copy,
        demand_rate_lower_95_ppr_copy,
        demand_rate_lower_limit_copy
        );
    if (!result) {
        free(duration_copy);
        free(demand_rate_upper_limit_copy);
        free(demand_rate_upper_95_ppr_copy);
        free(demand_rate_upper_68_ppr_copy);
        free(demand_rate_expected_copy);
        free(demand_rate_lower_68_ppr_copy);
        free(demand_rate_lower_95_ppr_copy);
        free(demand_rate_lower_limit_copy);
    }
    return result;
}

void ddbc_average_demand_rate_forecast_element_free(ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element) {
    if(NULL == ddbc_average_demand_rate_forecast_element){
        return ;
    }
    if(ddbc_average_demand_rate_forecast_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_average_demand_rate_forecast_element_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ddbc_average_demand_rate_forecast_element->duration) {
        free(ddbc_average_demand_rate_forecast_element->duration);
        ddbc_average_demand_rate_forecast_element->duration = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit);
        ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr);
        ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr);
        ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_expected) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_expected);
        ddbc_average_demand_rate_forecast_element->demand_rate_expected = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr);
        ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr);
        ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr = NULL;
    }
    if (ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit) {
        free(ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit);
        ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit = NULL;
    }
    free(ddbc_average_demand_rate_forecast_element);
}

cJSON *ddbc_average_demand_rate_forecast_element_convertToJSON(ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_average_demand_rate_forecast_element->duration
    if (!ddbc_average_demand_rate_forecast_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *ddbc_average_demand_rate_forecast_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit
    if(ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit) {
    if(cJSON_AddNumberToObject(item, "demand_rate_upper_limit", *ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr
    if(ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr) {
    if(cJSON_AddNumberToObject(item, "demand_rate_upper_95PPR", *ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr
    if(ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr) {
    if(cJSON_AddNumberToObject(item, "demand_rate_upper_68PPR", *ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_expected
    if (!ddbc_average_demand_rate_forecast_element->demand_rate_expected) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "demand_rate_expected", *ddbc_average_demand_rate_forecast_element->demand_rate_expected) == NULL) {
    goto fail; //Numeric
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr
    if(ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr) {
    if(cJSON_AddNumberToObject(item, "demand_rate_lower_68PPR", *ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr
    if(ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr) {
    if(cJSON_AddNumberToObject(item, "demand_rate_lower_95PPR", *ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit
    if(ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit) {
    if(cJSON_AddNumberToObject(item, "demand_rate_lower_limit", *ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_parseFromJSON(cJSON *ddbc_average_demand_rate_forecast_elementJSON){

    ddbc_average_demand_rate_forecast_element_t *ddbc_average_demand_rate_forecast_element_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->duration
    int *duration_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit
    double *demand_rate_upper_limit_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr
    double *demand_rate_upper_95_ppr_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr
    double *demand_rate_upper_68_ppr_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_expected
    double *demand_rate_expected_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr
    double *demand_rate_lower_68_ppr_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr
    double *demand_rate_lower_95_ppr_local_var = NULL;

    // define the local variable for ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit
    double *demand_rate_lower_limit_local_var = NULL;

    // ddbc_average_demand_rate_forecast_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "duration");
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

    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_limit
    cJSON *demand_rate_upper_limit = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_upper_limit");
    if (cJSON_IsNull(demand_rate_upper_limit)) {
        demand_rate_upper_limit = NULL;
    }
    if (demand_rate_upper_limit) { 
    if(!cJSON_IsNumber(demand_rate_upper_limit))
    {
    goto end; //Numeric
    }
    demand_rate_upper_limit_local_var = malloc(sizeof(double));
    if(!demand_rate_upper_limit_local_var)
    {
        goto end;
    }
    *demand_rate_upper_limit_local_var = demand_rate_upper_limit->valuedouble;
    }

    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_95_ppr
    cJSON *demand_rate_upper_95_ppr = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_upper_95PPR");
    if (cJSON_IsNull(demand_rate_upper_95_ppr)) {
        demand_rate_upper_95_ppr = NULL;
    }
    if (demand_rate_upper_95_ppr) { 
    if(!cJSON_IsNumber(demand_rate_upper_95_ppr))
    {
    goto end; //Numeric
    }
    demand_rate_upper_95_ppr_local_var = malloc(sizeof(double));
    if(!demand_rate_upper_95_ppr_local_var)
    {
        goto end;
    }
    *demand_rate_upper_95_ppr_local_var = demand_rate_upper_95_ppr->valuedouble;
    }

    // ddbc_average_demand_rate_forecast_element->demand_rate_upper_68_ppr
    cJSON *demand_rate_upper_68_ppr = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_upper_68PPR");
    if (cJSON_IsNull(demand_rate_upper_68_ppr)) {
        demand_rate_upper_68_ppr = NULL;
    }
    if (demand_rate_upper_68_ppr) { 
    if(!cJSON_IsNumber(demand_rate_upper_68_ppr))
    {
    goto end; //Numeric
    }
    demand_rate_upper_68_ppr_local_var = malloc(sizeof(double));
    if(!demand_rate_upper_68_ppr_local_var)
    {
        goto end;
    }
    *demand_rate_upper_68_ppr_local_var = demand_rate_upper_68_ppr->valuedouble;
    }

    // ddbc_average_demand_rate_forecast_element->demand_rate_expected
    cJSON *demand_rate_expected = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_expected");
    if (cJSON_IsNull(demand_rate_expected)) {
        demand_rate_expected = NULL;
    }
    if (!demand_rate_expected) {
        goto end;
    }

    
    if(!cJSON_IsNumber(demand_rate_expected))
    {
    goto end; //Numeric
    }
    demand_rate_expected_local_var = malloc(sizeof(double));
    if(!demand_rate_expected_local_var)
    {
        goto end;
    }
    *demand_rate_expected_local_var = demand_rate_expected->valuedouble;

    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_68_ppr
    cJSON *demand_rate_lower_68_ppr = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_lower_68PPR");
    if (cJSON_IsNull(demand_rate_lower_68_ppr)) {
        demand_rate_lower_68_ppr = NULL;
    }
    if (demand_rate_lower_68_ppr) { 
    if(!cJSON_IsNumber(demand_rate_lower_68_ppr))
    {
    goto end; //Numeric
    }
    demand_rate_lower_68_ppr_local_var = malloc(sizeof(double));
    if(!demand_rate_lower_68_ppr_local_var)
    {
        goto end;
    }
    *demand_rate_lower_68_ppr_local_var = demand_rate_lower_68_ppr->valuedouble;
    }

    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_95_ppr
    cJSON *demand_rate_lower_95_ppr = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_lower_95PPR");
    if (cJSON_IsNull(demand_rate_lower_95_ppr)) {
        demand_rate_lower_95_ppr = NULL;
    }
    if (demand_rate_lower_95_ppr) { 
    if(!cJSON_IsNumber(demand_rate_lower_95_ppr))
    {
    goto end; //Numeric
    }
    demand_rate_lower_95_ppr_local_var = malloc(sizeof(double));
    if(!demand_rate_lower_95_ppr_local_var)
    {
        goto end;
    }
    *demand_rate_lower_95_ppr_local_var = demand_rate_lower_95_ppr->valuedouble;
    }

    // ddbc_average_demand_rate_forecast_element->demand_rate_lower_limit
    cJSON *demand_rate_lower_limit = cJSON_GetObjectItemCaseSensitive(ddbc_average_demand_rate_forecast_elementJSON, "demand_rate_lower_limit");
    if (cJSON_IsNull(demand_rate_lower_limit)) {
        demand_rate_lower_limit = NULL;
    }
    if (demand_rate_lower_limit) { 
    if(!cJSON_IsNumber(demand_rate_lower_limit))
    {
    goto end; //Numeric
    }
    demand_rate_lower_limit_local_var = malloc(sizeof(double));
    if(!demand_rate_lower_limit_local_var)
    {
        goto end;
    }
    *demand_rate_lower_limit_local_var = demand_rate_lower_limit->valuedouble;
    }



    ddbc_average_demand_rate_forecast_element_local_var = ddbc_average_demand_rate_forecast_element_create_internal (
        duration_local_var,
        demand_rate_upper_limit_local_var,
        demand_rate_upper_95_ppr_local_var,
        demand_rate_upper_68_ppr_local_var,
        demand_rate_expected_local_var,
        demand_rate_lower_68_ppr_local_var,
        demand_rate_lower_95_ppr_local_var,
        demand_rate_lower_limit_local_var
        );

    if (!ddbc_average_demand_rate_forecast_element_local_var) {
        goto end;
    }

    return ddbc_average_demand_rate_forecast_element_local_var;
end:
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    if (demand_rate_upper_limit_local_var) {
        free(demand_rate_upper_limit_local_var);
        demand_rate_upper_limit_local_var = NULL;
    }
    if (demand_rate_upper_95_ppr_local_var) {
        free(demand_rate_upper_95_ppr_local_var);
        demand_rate_upper_95_ppr_local_var = NULL;
    }
    if (demand_rate_upper_68_ppr_local_var) {
        free(demand_rate_upper_68_ppr_local_var);
        demand_rate_upper_68_ppr_local_var = NULL;
    }
    if (demand_rate_expected_local_var) {
        free(demand_rate_expected_local_var);
        demand_rate_expected_local_var = NULL;
    }
    if (demand_rate_lower_68_ppr_local_var) {
        free(demand_rate_lower_68_ppr_local_var);
        demand_rate_lower_68_ppr_local_var = NULL;
    }
    if (demand_rate_lower_95_ppr_local_var) {
        free(demand_rate_lower_95_ppr_local_var);
        demand_rate_lower_95_ppr_local_var = NULL;
    }
    if (demand_rate_lower_limit_local_var) {
        free(demand_rate_lower_limit_local_var);
        demand_rate_lower_limit_local_var = NULL;
    }
    return NULL;

}
