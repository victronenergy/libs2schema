#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_power_envelope_element.h>



static pebc_power_envelope_element_t *pebc_power_envelope_element_create_internal(
    int *duration,
    double *upper_limit,
    double *lower_limit
    ) {
    pebc_power_envelope_element_t *pebc_power_envelope_element_local_var = malloc(sizeof(pebc_power_envelope_element_t));
    if (!pebc_power_envelope_element_local_var) {
        return NULL;
    }
    memset(pebc_power_envelope_element_local_var, 0, sizeof(pebc_power_envelope_element_t));
    pebc_power_envelope_element_local_var->_library_owned = 1;
    pebc_power_envelope_element_local_var->duration = duration;
    pebc_power_envelope_element_local_var->upper_limit = upper_limit;
    pebc_power_envelope_element_local_var->lower_limit = lower_limit;
    return pebc_power_envelope_element_local_var;
}

__attribute__((deprecated)) pebc_power_envelope_element_t *pebc_power_envelope_element_create(
    int *duration,
    double *upper_limit,
    double *lower_limit
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    double *upper_limit_copy = NULL;
    if (upper_limit) {
        upper_limit_copy = malloc(sizeof(double));
        if (upper_limit_copy) *upper_limit_copy = *upper_limit;
    }
    double *lower_limit_copy = NULL;
    if (lower_limit) {
        lower_limit_copy = malloc(sizeof(double));
        if (lower_limit_copy) *lower_limit_copy = *lower_limit;
    }
    pebc_power_envelope_element_t *result = pebc_power_envelope_element_create_internal (
        duration_copy,
        upper_limit_copy,
        lower_limit_copy
        );
    if (!result) {
        free(duration_copy);
        free(upper_limit_copy);
        free(lower_limit_copy);
    }
    return result;
}

void pebc_power_envelope_element_free(pebc_power_envelope_element_t *pebc_power_envelope_element) {
    if(NULL == pebc_power_envelope_element){
        return ;
    }
    if(pebc_power_envelope_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_power_envelope_element_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pebc_power_envelope_element->duration) {
        free(pebc_power_envelope_element->duration);
        pebc_power_envelope_element->duration = NULL;
    }
    if (pebc_power_envelope_element->upper_limit) {
        free(pebc_power_envelope_element->upper_limit);
        pebc_power_envelope_element->upper_limit = NULL;
    }
    if (pebc_power_envelope_element->lower_limit) {
        free(pebc_power_envelope_element->lower_limit);
        pebc_power_envelope_element->lower_limit = NULL;
    }
    free(pebc_power_envelope_element);
}

cJSON *pebc_power_envelope_element_convertToJSON(pebc_power_envelope_element_t *pebc_power_envelope_element) {
    cJSON *item = cJSON_CreateObject();

    // pebc_power_envelope_element->duration
    if (!pebc_power_envelope_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *pebc_power_envelope_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // pebc_power_envelope_element->upper_limit
    if (!pebc_power_envelope_element->upper_limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "upper_limit", *pebc_power_envelope_element->upper_limit) == NULL) {
    goto fail; //Numeric
    }


    // pebc_power_envelope_element->lower_limit
    if (!pebc_power_envelope_element->lower_limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lower_limit", *pebc_power_envelope_element->lower_limit) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_power_envelope_element_t *pebc_power_envelope_element_parseFromJSON(cJSON *pebc_power_envelope_elementJSON){

    pebc_power_envelope_element_t *pebc_power_envelope_element_local_var = NULL;

    // define the local variable for pebc_power_envelope_element->duration
    int *duration_local_var = NULL;

    // define the local variable for pebc_power_envelope_element->upper_limit
    double *upper_limit_local_var = NULL;

    // define the local variable for pebc_power_envelope_element->lower_limit
    double *lower_limit_local_var = NULL;

    // pebc_power_envelope_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(pebc_power_envelope_elementJSON, "duration");
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

    // pebc_power_envelope_element->upper_limit
    cJSON *upper_limit = cJSON_GetObjectItemCaseSensitive(pebc_power_envelope_elementJSON, "upper_limit");
    if (cJSON_IsNull(upper_limit)) {
        upper_limit = NULL;
    }
    if (!upper_limit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(upper_limit))
    {
    goto end; //Numeric
    }
    upper_limit_local_var = malloc(sizeof(double));
    if(!upper_limit_local_var)
    {
        goto end;
    }
    *upper_limit_local_var = upper_limit->valuedouble;

    // pebc_power_envelope_element->lower_limit
    cJSON *lower_limit = cJSON_GetObjectItemCaseSensitive(pebc_power_envelope_elementJSON, "lower_limit");
    if (cJSON_IsNull(lower_limit)) {
        lower_limit = NULL;
    }
    if (!lower_limit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lower_limit))
    {
    goto end; //Numeric
    }
    lower_limit_local_var = malloc(sizeof(double));
    if(!lower_limit_local_var)
    {
        goto end;
    }
    *lower_limit_local_var = lower_limit->valuedouble;



    pebc_power_envelope_element_local_var = pebc_power_envelope_element_create_internal (
        duration_local_var,
        upper_limit_local_var,
        lower_limit_local_var
        );

    if (!pebc_power_envelope_element_local_var) {
        goto end;
    }

    return pebc_power_envelope_element_local_var;
end:
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    if (upper_limit_local_var) {
        free(upper_limit_local_var);
        upper_limit_local_var = NULL;
    }
    if (lower_limit_local_var) {
        free(lower_limit_local_var);
        lower_limit_local_var = NULL;
    }
    return NULL;

}
