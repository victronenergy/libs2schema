#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/number_range.h>



static number_range_t *number_range_create_internal(
    double *start_of_range,
    double *end_of_range
    ) {
    number_range_t *number_range_local_var = malloc(sizeof(number_range_t));
    if (!number_range_local_var) {
        return NULL;
    }
    memset(number_range_local_var, 0, sizeof(number_range_t));
    number_range_local_var->_library_owned = 1;
    number_range_local_var->start_of_range = start_of_range;
    number_range_local_var->end_of_range = end_of_range;
    return number_range_local_var;
}

__attribute__((deprecated)) number_range_t *number_range_create(
    double *start_of_range,
    double *end_of_range
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
    number_range_t *result = number_range_create_internal (
        start_of_range_copy,
        end_of_range_copy
        );
    if (!result) {
        free(start_of_range_copy);
        free(end_of_range_copy);
    }
    return result;
}

void number_range_free(number_range_t *number_range) {
    if(NULL == number_range){
        return ;
    }
    if(number_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "number_range_free");
        return ;
    }
    if (number_range->start_of_range) {
        free(number_range->start_of_range);
        number_range->start_of_range = NULL;
    }
    if (number_range->end_of_range) {
        free(number_range->end_of_range);
        number_range->end_of_range = NULL;
    }
    free(number_range);
}

cJSON *number_range_convertToJSON(number_range_t *number_range) {
    cJSON *item = cJSON_CreateObject();

    // number_range->start_of_range
    if (!number_range->start_of_range) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "start_of_range", *number_range->start_of_range) == NULL) {
    goto fail; //Numeric
    }


    // number_range->end_of_range
    if (!number_range->end_of_range) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "end_of_range", *number_range->end_of_range) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

number_range_t *number_range_parseFromJSON(cJSON *number_rangeJSON){

    number_range_t *number_range_local_var = NULL;

    // define the local variable for number_range->start_of_range
    double *start_of_range_local_var = NULL;

    // define the local variable for number_range->end_of_range
    double *end_of_range_local_var = NULL;

    // number_range->start_of_range
    cJSON *start_of_range = cJSON_GetObjectItemCaseSensitive(number_rangeJSON, "start_of_range");
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

    // number_range->end_of_range
    cJSON *end_of_range = cJSON_GetObjectItemCaseSensitive(number_rangeJSON, "end_of_range");
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



    number_range_local_var = number_range_create_internal (
        start_of_range_local_var,
        end_of_range_local_var
        );

    if (!number_range_local_var) {
        goto end;
    }

    return number_range_local_var;
end:
    if (start_of_range_local_var) {
        free(start_of_range_local_var);
        start_of_range_local_var = NULL;
    }
    if (end_of_range_local_var) {
        free(end_of_range_local_var);
        end_of_range_local_var = NULL;
    }
    return NULL;

}
