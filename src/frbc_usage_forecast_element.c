#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_usage_forecast_element.h>



static frbc_usage_forecast_element_t *frbc_usage_forecast_element_create_internal(
    int *duration,
    double *usage_rate_upper_limit,
    double *usage_rate_upper_95_ppr,
    double *usage_rate_upper_68_ppr,
    double *usage_rate_expected,
    double *usage_rate_lower_68_ppr,
    double *usage_rate_lower_95_ppr,
    double *usage_rate_lower_limit
    ) {
    frbc_usage_forecast_element_t *frbc_usage_forecast_element_local_var = malloc(sizeof(frbc_usage_forecast_element_t));
    if (!frbc_usage_forecast_element_local_var) {
        return NULL;
    }
    memset(frbc_usage_forecast_element_local_var, 0, sizeof(frbc_usage_forecast_element_t));
    frbc_usage_forecast_element_local_var->_library_owned = 1;
    frbc_usage_forecast_element_local_var->duration = duration;
    frbc_usage_forecast_element_local_var->usage_rate_upper_limit = usage_rate_upper_limit;
    frbc_usage_forecast_element_local_var->usage_rate_upper_95_ppr = usage_rate_upper_95_ppr;
    frbc_usage_forecast_element_local_var->usage_rate_upper_68_ppr = usage_rate_upper_68_ppr;
    frbc_usage_forecast_element_local_var->usage_rate_expected = usage_rate_expected;
    frbc_usage_forecast_element_local_var->usage_rate_lower_68_ppr = usage_rate_lower_68_ppr;
    frbc_usage_forecast_element_local_var->usage_rate_lower_95_ppr = usage_rate_lower_95_ppr;
    frbc_usage_forecast_element_local_var->usage_rate_lower_limit = usage_rate_lower_limit;
    return frbc_usage_forecast_element_local_var;
}

__attribute__((deprecated)) frbc_usage_forecast_element_t *frbc_usage_forecast_element_create(
    int *duration,
    double *usage_rate_upper_limit,
    double *usage_rate_upper_95_ppr,
    double *usage_rate_upper_68_ppr,
    double *usage_rate_expected,
    double *usage_rate_lower_68_ppr,
    double *usage_rate_lower_95_ppr,
    double *usage_rate_lower_limit
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    double *usage_rate_upper_limit_copy = NULL;
    if (usage_rate_upper_limit) {
        usage_rate_upper_limit_copy = malloc(sizeof(double));
        if (usage_rate_upper_limit_copy) *usage_rate_upper_limit_copy = *usage_rate_upper_limit;
    }
    double *usage_rate_upper_95_ppr_copy = NULL;
    if (usage_rate_upper_95_ppr) {
        usage_rate_upper_95_ppr_copy = malloc(sizeof(double));
        if (usage_rate_upper_95_ppr_copy) *usage_rate_upper_95_ppr_copy = *usage_rate_upper_95_ppr;
    }
    double *usage_rate_upper_68_ppr_copy = NULL;
    if (usage_rate_upper_68_ppr) {
        usage_rate_upper_68_ppr_copy = malloc(sizeof(double));
        if (usage_rate_upper_68_ppr_copy) *usage_rate_upper_68_ppr_copy = *usage_rate_upper_68_ppr;
    }
    double *usage_rate_expected_copy = NULL;
    if (usage_rate_expected) {
        usage_rate_expected_copy = malloc(sizeof(double));
        if (usage_rate_expected_copy) *usage_rate_expected_copy = *usage_rate_expected;
    }
    double *usage_rate_lower_68_ppr_copy = NULL;
    if (usage_rate_lower_68_ppr) {
        usage_rate_lower_68_ppr_copy = malloc(sizeof(double));
        if (usage_rate_lower_68_ppr_copy) *usage_rate_lower_68_ppr_copy = *usage_rate_lower_68_ppr;
    }
    double *usage_rate_lower_95_ppr_copy = NULL;
    if (usage_rate_lower_95_ppr) {
        usage_rate_lower_95_ppr_copy = malloc(sizeof(double));
        if (usage_rate_lower_95_ppr_copy) *usage_rate_lower_95_ppr_copy = *usage_rate_lower_95_ppr;
    }
    double *usage_rate_lower_limit_copy = NULL;
    if (usage_rate_lower_limit) {
        usage_rate_lower_limit_copy = malloc(sizeof(double));
        if (usage_rate_lower_limit_copy) *usage_rate_lower_limit_copy = *usage_rate_lower_limit;
    }
    frbc_usage_forecast_element_t *result = frbc_usage_forecast_element_create_internal (
        duration_copy,
        usage_rate_upper_limit_copy,
        usage_rate_upper_95_ppr_copy,
        usage_rate_upper_68_ppr_copy,
        usage_rate_expected_copy,
        usage_rate_lower_68_ppr_copy,
        usage_rate_lower_95_ppr_copy,
        usage_rate_lower_limit_copy
        );
    if (!result) {
        free(duration_copy);
        free(usage_rate_upper_limit_copy);
        free(usage_rate_upper_95_ppr_copy);
        free(usage_rate_upper_68_ppr_copy);
        free(usage_rate_expected_copy);
        free(usage_rate_lower_68_ppr_copy);
        free(usage_rate_lower_95_ppr_copy);
        free(usage_rate_lower_limit_copy);
    }
    return result;
}

void frbc_usage_forecast_element_free(frbc_usage_forecast_element_t *frbc_usage_forecast_element) {
    if(NULL == frbc_usage_forecast_element){
        return ;
    }
    if(frbc_usage_forecast_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_usage_forecast_element_free");
        return ;
    }
    if (frbc_usage_forecast_element->duration) {
        free(frbc_usage_forecast_element->duration);
        frbc_usage_forecast_element->duration = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_upper_limit) {
        free(frbc_usage_forecast_element->usage_rate_upper_limit);
        frbc_usage_forecast_element->usage_rate_upper_limit = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_upper_95_ppr) {
        free(frbc_usage_forecast_element->usage_rate_upper_95_ppr);
        frbc_usage_forecast_element->usage_rate_upper_95_ppr = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_upper_68_ppr) {
        free(frbc_usage_forecast_element->usage_rate_upper_68_ppr);
        frbc_usage_forecast_element->usage_rate_upper_68_ppr = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_expected) {
        free(frbc_usage_forecast_element->usage_rate_expected);
        frbc_usage_forecast_element->usage_rate_expected = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_lower_68_ppr) {
        free(frbc_usage_forecast_element->usage_rate_lower_68_ppr);
        frbc_usage_forecast_element->usage_rate_lower_68_ppr = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_lower_95_ppr) {
        free(frbc_usage_forecast_element->usage_rate_lower_95_ppr);
        frbc_usage_forecast_element->usage_rate_lower_95_ppr = NULL;
    }
    if (frbc_usage_forecast_element->usage_rate_lower_limit) {
        free(frbc_usage_forecast_element->usage_rate_lower_limit);
        frbc_usage_forecast_element->usage_rate_lower_limit = NULL;
    }
    free(frbc_usage_forecast_element);
}

cJSON *frbc_usage_forecast_element_convertToJSON(frbc_usage_forecast_element_t *frbc_usage_forecast_element) {
    cJSON *item = cJSON_CreateObject();

    // frbc_usage_forecast_element->duration
    if (!frbc_usage_forecast_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *frbc_usage_forecast_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // frbc_usage_forecast_element->usage_rate_upper_limit
    if(frbc_usage_forecast_element->usage_rate_upper_limit) {
    if(cJSON_AddNumberToObject(item, "usage_rate_upper_limit", *frbc_usage_forecast_element->usage_rate_upper_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // frbc_usage_forecast_element->usage_rate_upper_95_ppr
    if(frbc_usage_forecast_element->usage_rate_upper_95_ppr) {
    if(cJSON_AddNumberToObject(item, "usage_rate_upper_95PPR", *frbc_usage_forecast_element->usage_rate_upper_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // frbc_usage_forecast_element->usage_rate_upper_68_ppr
    if(frbc_usage_forecast_element->usage_rate_upper_68_ppr) {
    if(cJSON_AddNumberToObject(item, "usage_rate_upper_68PPR", *frbc_usage_forecast_element->usage_rate_upper_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // frbc_usage_forecast_element->usage_rate_expected
    if (!frbc_usage_forecast_element->usage_rate_expected) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "usage_rate_expected", *frbc_usage_forecast_element->usage_rate_expected) == NULL) {
    goto fail; //Numeric
    }


    // frbc_usage_forecast_element->usage_rate_lower_68_ppr
    if(frbc_usage_forecast_element->usage_rate_lower_68_ppr) {
    if(cJSON_AddNumberToObject(item, "usage_rate_lower_68PPR", *frbc_usage_forecast_element->usage_rate_lower_68_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // frbc_usage_forecast_element->usage_rate_lower_95_ppr
    if(frbc_usage_forecast_element->usage_rate_lower_95_ppr) {
    if(cJSON_AddNumberToObject(item, "usage_rate_lower_95PPR", *frbc_usage_forecast_element->usage_rate_lower_95_ppr) == NULL) {
    goto fail; //Numeric
    }
    }


    // frbc_usage_forecast_element->usage_rate_lower_limit
    if(frbc_usage_forecast_element->usage_rate_lower_limit) {
    if(cJSON_AddNumberToObject(item, "usage_rate_lower_limit", *frbc_usage_forecast_element->usage_rate_lower_limit) == NULL) {
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

frbc_usage_forecast_element_t *frbc_usage_forecast_element_parseFromJSON(cJSON *frbc_usage_forecast_elementJSON){

    frbc_usage_forecast_element_t *frbc_usage_forecast_element_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->duration
    int *duration_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_upper_limit
    double *usage_rate_upper_limit_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_upper_95_ppr
    double *usage_rate_upper_95_ppr_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_upper_68_ppr
    double *usage_rate_upper_68_ppr_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_expected
    double *usage_rate_expected_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_lower_68_ppr
    double *usage_rate_lower_68_ppr_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_lower_95_ppr
    double *usage_rate_lower_95_ppr_local_var = NULL;

    // define the local variable for frbc_usage_forecast_element->usage_rate_lower_limit
    double *usage_rate_lower_limit_local_var = NULL;

    // frbc_usage_forecast_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "duration");
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

    // frbc_usage_forecast_element->usage_rate_upper_limit
    cJSON *usage_rate_upper_limit = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_upper_limit");
    if (cJSON_IsNull(usage_rate_upper_limit)) {
        usage_rate_upper_limit = NULL;
    }
    if (usage_rate_upper_limit) { 
    if(!cJSON_IsNumber(usage_rate_upper_limit))
    {
    goto end; //Numeric
    }
    usage_rate_upper_limit_local_var = malloc(sizeof(double));
    if(!usage_rate_upper_limit_local_var)
    {
        goto end;
    }
    *usage_rate_upper_limit_local_var = usage_rate_upper_limit->valuedouble;
    }

    // frbc_usage_forecast_element->usage_rate_upper_95_ppr
    cJSON *usage_rate_upper_95_ppr = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_upper_95PPR");
    if (cJSON_IsNull(usage_rate_upper_95_ppr)) {
        usage_rate_upper_95_ppr = NULL;
    }
    if (usage_rate_upper_95_ppr) { 
    if(!cJSON_IsNumber(usage_rate_upper_95_ppr))
    {
    goto end; //Numeric
    }
    usage_rate_upper_95_ppr_local_var = malloc(sizeof(double));
    if(!usage_rate_upper_95_ppr_local_var)
    {
        goto end;
    }
    *usage_rate_upper_95_ppr_local_var = usage_rate_upper_95_ppr->valuedouble;
    }

    // frbc_usage_forecast_element->usage_rate_upper_68_ppr
    cJSON *usage_rate_upper_68_ppr = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_upper_68PPR");
    if (cJSON_IsNull(usage_rate_upper_68_ppr)) {
        usage_rate_upper_68_ppr = NULL;
    }
    if (usage_rate_upper_68_ppr) { 
    if(!cJSON_IsNumber(usage_rate_upper_68_ppr))
    {
    goto end; //Numeric
    }
    usage_rate_upper_68_ppr_local_var = malloc(sizeof(double));
    if(!usage_rate_upper_68_ppr_local_var)
    {
        goto end;
    }
    *usage_rate_upper_68_ppr_local_var = usage_rate_upper_68_ppr->valuedouble;
    }

    // frbc_usage_forecast_element->usage_rate_expected
    cJSON *usage_rate_expected = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_expected");
    if (cJSON_IsNull(usage_rate_expected)) {
        usage_rate_expected = NULL;
    }
    if (!usage_rate_expected) {
        goto end;
    }

    
    if(!cJSON_IsNumber(usage_rate_expected))
    {
    goto end; //Numeric
    }
    usage_rate_expected_local_var = malloc(sizeof(double));
    if(!usage_rate_expected_local_var)
    {
        goto end;
    }
    *usage_rate_expected_local_var = usage_rate_expected->valuedouble;

    // frbc_usage_forecast_element->usage_rate_lower_68_ppr
    cJSON *usage_rate_lower_68_ppr = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_lower_68PPR");
    if (cJSON_IsNull(usage_rate_lower_68_ppr)) {
        usage_rate_lower_68_ppr = NULL;
    }
    if (usage_rate_lower_68_ppr) { 
    if(!cJSON_IsNumber(usage_rate_lower_68_ppr))
    {
    goto end; //Numeric
    }
    usage_rate_lower_68_ppr_local_var = malloc(sizeof(double));
    if(!usage_rate_lower_68_ppr_local_var)
    {
        goto end;
    }
    *usage_rate_lower_68_ppr_local_var = usage_rate_lower_68_ppr->valuedouble;
    }

    // frbc_usage_forecast_element->usage_rate_lower_95_ppr
    cJSON *usage_rate_lower_95_ppr = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_lower_95PPR");
    if (cJSON_IsNull(usage_rate_lower_95_ppr)) {
        usage_rate_lower_95_ppr = NULL;
    }
    if (usage_rate_lower_95_ppr) { 
    if(!cJSON_IsNumber(usage_rate_lower_95_ppr))
    {
    goto end; //Numeric
    }
    usage_rate_lower_95_ppr_local_var = malloc(sizeof(double));
    if(!usage_rate_lower_95_ppr_local_var)
    {
        goto end;
    }
    *usage_rate_lower_95_ppr_local_var = usage_rate_lower_95_ppr->valuedouble;
    }

    // frbc_usage_forecast_element->usage_rate_lower_limit
    cJSON *usage_rate_lower_limit = cJSON_GetObjectItemCaseSensitive(frbc_usage_forecast_elementJSON, "usage_rate_lower_limit");
    if (cJSON_IsNull(usage_rate_lower_limit)) {
        usage_rate_lower_limit = NULL;
    }
    if (usage_rate_lower_limit) { 
    if(!cJSON_IsNumber(usage_rate_lower_limit))
    {
    goto end; //Numeric
    }
    usage_rate_lower_limit_local_var = malloc(sizeof(double));
    if(!usage_rate_lower_limit_local_var)
    {
        goto end;
    }
    *usage_rate_lower_limit_local_var = usage_rate_lower_limit->valuedouble;
    }



    frbc_usage_forecast_element_local_var = frbc_usage_forecast_element_create_internal (
        duration_local_var,
        usage_rate_upper_limit_local_var,
        usage_rate_upper_95_ppr_local_var,
        usage_rate_upper_68_ppr_local_var,
        usage_rate_expected_local_var,
        usage_rate_lower_68_ppr_local_var,
        usage_rate_lower_95_ppr_local_var,
        usage_rate_lower_limit_local_var
        );

    if (!frbc_usage_forecast_element_local_var) {
        goto end;
    }

    return frbc_usage_forecast_element_local_var;
end:
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    if (usage_rate_upper_limit_local_var) {
        free(usage_rate_upper_limit_local_var);
        usage_rate_upper_limit_local_var = NULL;
    }
    if (usage_rate_upper_95_ppr_local_var) {
        free(usage_rate_upper_95_ppr_local_var);
        usage_rate_upper_95_ppr_local_var = NULL;
    }
    if (usage_rate_upper_68_ppr_local_var) {
        free(usage_rate_upper_68_ppr_local_var);
        usage_rate_upper_68_ppr_local_var = NULL;
    }
    if (usage_rate_expected_local_var) {
        free(usage_rate_expected_local_var);
        usage_rate_expected_local_var = NULL;
    }
    if (usage_rate_lower_68_ppr_local_var) {
        free(usage_rate_lower_68_ppr_local_var);
        usage_rate_lower_68_ppr_local_var = NULL;
    }
    if (usage_rate_lower_95_ppr_local_var) {
        free(usage_rate_lower_95_ppr_local_var);
        usage_rate_lower_95_ppr_local_var = NULL;
    }
    if (usage_rate_lower_limit_local_var) {
        free(usage_rate_lower_limit_local_var);
        usage_rate_lower_limit_local_var = NULL;
    }
    return NULL;

}
