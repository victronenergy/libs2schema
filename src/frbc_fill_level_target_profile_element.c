#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_fill_level_target_profile_element.h>



static frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element_create_internal(
    int *duration,
    number_range_t *fill_level_range
    ) {
    frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element_local_var = malloc(sizeof(frbc_fill_level_target_profile_element_t));
    if (!frbc_fill_level_target_profile_element_local_var) {
        return NULL;
    }
    memset(frbc_fill_level_target_profile_element_local_var, 0, sizeof(frbc_fill_level_target_profile_element_t));
    frbc_fill_level_target_profile_element_local_var->_library_owned = 1;
    frbc_fill_level_target_profile_element_local_var->duration = duration;
    frbc_fill_level_target_profile_element_local_var->fill_level_range = fill_level_range;
    return frbc_fill_level_target_profile_element_local_var;
}

__attribute__((deprecated)) frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element_create(
    int *duration,
    number_range_t *fill_level_range
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    frbc_fill_level_target_profile_element_t *result = frbc_fill_level_target_profile_element_create_internal (
        duration_copy,
        fill_level_range
        );
    if (!result) {
        free(duration_copy);
    }
    return result;
}

void frbc_fill_level_target_profile_element_free(frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element) {
    if(NULL == frbc_fill_level_target_profile_element){
        return ;
    }
    if(frbc_fill_level_target_profile_element->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_fill_level_target_profile_element_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_fill_level_target_profile_element->duration) {
        free(frbc_fill_level_target_profile_element->duration);
        frbc_fill_level_target_profile_element->duration = NULL;
    }
    if (frbc_fill_level_target_profile_element->fill_level_range) {
        number_range_free(frbc_fill_level_target_profile_element->fill_level_range);
        frbc_fill_level_target_profile_element->fill_level_range = NULL;
    }
    free(frbc_fill_level_target_profile_element);
}

cJSON *frbc_fill_level_target_profile_element_convertToJSON(frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element) {
    cJSON *item = cJSON_CreateObject();

    // frbc_fill_level_target_profile_element->duration
    if (!frbc_fill_level_target_profile_element->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *frbc_fill_level_target_profile_element->duration) == NULL) {
    goto fail; //Numeric
    }


    // frbc_fill_level_target_profile_element->fill_level_range
    if (!frbc_fill_level_target_profile_element->fill_level_range) {
        goto fail;
    }
    cJSON *fill_level_range_local_JSON = number_range_convertToJSON(frbc_fill_level_target_profile_element->fill_level_range);
    if(fill_level_range_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill_level_range", fill_level_range_local_JSON);
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

frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element_parseFromJSON(cJSON *frbc_fill_level_target_profile_elementJSON){

    frbc_fill_level_target_profile_element_t *frbc_fill_level_target_profile_element_local_var = NULL;

    // define the local variable for frbc_fill_level_target_profile_element->duration
    int *duration_local_var = NULL;

    // define the local variable for frbc_fill_level_target_profile_element->fill_level_range
    number_range_t *fill_level_range_local_nonprim = NULL;

    // frbc_fill_level_target_profile_element->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(frbc_fill_level_target_profile_elementJSON, "duration");
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

    // frbc_fill_level_target_profile_element->fill_level_range
    cJSON *fill_level_range = cJSON_GetObjectItemCaseSensitive(frbc_fill_level_target_profile_elementJSON, "fill_level_range");
    if (cJSON_IsNull(fill_level_range)) {
        fill_level_range = NULL;
    }
    if (!fill_level_range) {
        goto end;
    }

    
    fill_level_range_local_nonprim = number_range_parseFromJSON(fill_level_range); //nonprimitive



    frbc_fill_level_target_profile_element_local_var = frbc_fill_level_target_profile_element_create_internal (
        duration_local_var,
        fill_level_range_local_nonprim
        );

    if (!frbc_fill_level_target_profile_element_local_var) {
        goto end;
    }

    return frbc_fill_level_target_profile_element_local_var;
end:
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    if (fill_level_range_local_nonprim) {
        number_range_free(fill_level_range_local_nonprim);
        fill_level_range_local_nonprim = NULL;
    }
    return NULL;

}
