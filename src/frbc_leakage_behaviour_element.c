#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_leakage_behaviour_element.h>



static frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_create_internal(
    number_range_t *fill_level_range,
    double *leakage_rate
    ) {
    frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_local_var = malloc(sizeof(frbc_leakage_behaviour_element_t));
    if (!frbc_leakage_behaviour_element_local_var) {
        return NULL;
    }
    memset(frbc_leakage_behaviour_element_local_var, 0, sizeof(frbc_leakage_behaviour_element_t));
    frbc_leakage_behaviour_element_local_var->_library_owned = 1;
    frbc_leakage_behaviour_element_local_var->fill_level_range = fill_level_range;
    frbc_leakage_behaviour_element_local_var->leakage_rate = leakage_rate;
    return frbc_leakage_behaviour_element_local_var;
}

__attribute__((deprecated)) frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_create(
    number_range_t *fill_level_range,
    double *leakage_rate
    ) {
    double *leakage_rate_copy = NULL;
    if (leakage_rate) {
        leakage_rate_copy = malloc(sizeof(double));
        if (leakage_rate_copy) *leakage_rate_copy = *leakage_rate;
    }
    frbc_leakage_behaviour_element_t *result = frbc_leakage_behaviour_element_create_internal (
        fill_level_range,
        leakage_rate_copy
        );
    if (!result) {
        free(leakage_rate_copy);
    }
    return result;
}

void frbc_leakage_behaviour_element_free(frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element) {
    if(NULL == frbc_leakage_behaviour_element){
        return ;
    }
    if(frbc_leakage_behaviour_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_leakage_behaviour_element_free");
        return ;
    }
    if (frbc_leakage_behaviour_element->fill_level_range) {
        number_range_free(frbc_leakage_behaviour_element->fill_level_range);
        frbc_leakage_behaviour_element->fill_level_range = NULL;
    }
    if (frbc_leakage_behaviour_element->leakage_rate) {
        free(frbc_leakage_behaviour_element->leakage_rate);
        frbc_leakage_behaviour_element->leakage_rate = NULL;
    }
    free(frbc_leakage_behaviour_element);
}

cJSON *frbc_leakage_behaviour_element_convertToJSON(frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element) {
    cJSON *item = cJSON_CreateObject();

    // frbc_leakage_behaviour_element->fill_level_range
    if (!frbc_leakage_behaviour_element->fill_level_range) {
        goto fail;
    }
    cJSON *fill_level_range_local_JSON = number_range_convertToJSON(frbc_leakage_behaviour_element->fill_level_range);
    if(fill_level_range_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill_level_range", fill_level_range_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // frbc_leakage_behaviour_element->leakage_rate
    if (!frbc_leakage_behaviour_element->leakage_rate) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "leakage_rate", *frbc_leakage_behaviour_element->leakage_rate) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_parseFromJSON(cJSON *frbc_leakage_behaviour_elementJSON){

    frbc_leakage_behaviour_element_t *frbc_leakage_behaviour_element_local_var = NULL;

    // define the local variable for frbc_leakage_behaviour_element->fill_level_range
    number_range_t *fill_level_range_local_nonprim = NULL;

    // define the local variable for frbc_leakage_behaviour_element->leakage_rate
    double *leakage_rate_local_var = NULL;

    // frbc_leakage_behaviour_element->fill_level_range
    cJSON *fill_level_range = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviour_elementJSON, "fill_level_range");
    if (cJSON_IsNull(fill_level_range)) {
        fill_level_range = NULL;
    }
    if (!fill_level_range) {
        goto end;
    }

    
    fill_level_range_local_nonprim = number_range_parseFromJSON(fill_level_range); //nonprimitive

    // frbc_leakage_behaviour_element->leakage_rate
    cJSON *leakage_rate = cJSON_GetObjectItemCaseSensitive(frbc_leakage_behaviour_elementJSON, "leakage_rate");
    if (cJSON_IsNull(leakage_rate)) {
        leakage_rate = NULL;
    }
    if (!leakage_rate) {
        goto end;
    }

    
    if(!cJSON_IsNumber(leakage_rate))
    {
    goto end; //Numeric
    }
    leakage_rate_local_var = malloc(sizeof(double));
    if(!leakage_rate_local_var)
    {
        goto end;
    }
    *leakage_rate_local_var = leakage_rate->valuedouble;



    frbc_leakage_behaviour_element_local_var = frbc_leakage_behaviour_element_create_internal (
        fill_level_range_local_nonprim,
        leakage_rate_local_var
        );

    if (!frbc_leakage_behaviour_element_local_var) {
        goto end;
    }

    return frbc_leakage_behaviour_element_local_var;
end:
    if (fill_level_range_local_nonprim) {
        number_range_free(fill_level_range_local_nonprim);
        fill_level_range_local_nonprim = NULL;
    }
    if (leakage_rate_local_var) {
        free(leakage_rate_local_var);
        leakage_rate_local_var = NULL;
    }
    return NULL;

}
