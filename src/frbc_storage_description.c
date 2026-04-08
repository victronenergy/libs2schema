#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_storage_description.h>



static frbc_storage_description_t *frbc_storage_description_create_internal(
    char *diagnostic_label,
    char *fill_level_label,
    int *provides_leakage_behaviour,
    int *provides_fill_level_target_profile,
    int *provides_usage_forecast,
    number_range_t *fill_level_range
    ) {
    frbc_storage_description_t *frbc_storage_description_local_var = malloc(sizeof(frbc_storage_description_t));
    if (!frbc_storage_description_local_var) {
        return NULL;
    }
    memset(frbc_storage_description_local_var, 0, sizeof(frbc_storage_description_t));
    frbc_storage_description_local_var->_library_owned = 1;
    frbc_storage_description_local_var->diagnostic_label = diagnostic_label;
    frbc_storage_description_local_var->fill_level_label = fill_level_label;
    frbc_storage_description_local_var->provides_leakage_behaviour = provides_leakage_behaviour;
    frbc_storage_description_local_var->provides_fill_level_target_profile = provides_fill_level_target_profile;
    frbc_storage_description_local_var->provides_usage_forecast = provides_usage_forecast;
    frbc_storage_description_local_var->fill_level_range = fill_level_range;
    return frbc_storage_description_local_var;
}

__attribute__((deprecated)) frbc_storage_description_t *frbc_storage_description_create(
    char *diagnostic_label,
    char *fill_level_label,
    int *provides_leakage_behaviour,
    int *provides_fill_level_target_profile,
    int *provides_usage_forecast,
    number_range_t *fill_level_range
    ) {
    int *provides_leakage_behaviour_copy = NULL;
    if (provides_leakage_behaviour) {
        provides_leakage_behaviour_copy = malloc(sizeof(int));
        if (provides_leakage_behaviour_copy) *provides_leakage_behaviour_copy = *provides_leakage_behaviour;
    }
    int *provides_fill_level_target_profile_copy = NULL;
    if (provides_fill_level_target_profile) {
        provides_fill_level_target_profile_copy = malloc(sizeof(int));
        if (provides_fill_level_target_profile_copy) *provides_fill_level_target_profile_copy = *provides_fill_level_target_profile;
    }
    int *provides_usage_forecast_copy = NULL;
    if (provides_usage_forecast) {
        provides_usage_forecast_copy = malloc(sizeof(int));
        if (provides_usage_forecast_copy) *provides_usage_forecast_copy = *provides_usage_forecast;
    }
    frbc_storage_description_t *result = frbc_storage_description_create_internal (
        diagnostic_label,
        fill_level_label,
        provides_leakage_behaviour_copy,
        provides_fill_level_target_profile_copy,
        provides_usage_forecast_copy,
        fill_level_range
        );
    if (!result) {
        free(provides_leakage_behaviour_copy);
        free(provides_fill_level_target_profile_copy);
        free(provides_usage_forecast_copy);
    }
    return result;
}

void frbc_storage_description_free(frbc_storage_description_t *frbc_storage_description) {
    if(NULL == frbc_storage_description){
        return ;
    }
    if(frbc_storage_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_storage_description_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_storage_description->diagnostic_label) {
        free(frbc_storage_description->diagnostic_label);
        frbc_storage_description->diagnostic_label = NULL;
    }
    if (frbc_storage_description->fill_level_label) {
        free(frbc_storage_description->fill_level_label);
        frbc_storage_description->fill_level_label = NULL;
    }
    if (frbc_storage_description->provides_leakage_behaviour) {
        free(frbc_storage_description->provides_leakage_behaviour);
        frbc_storage_description->provides_leakage_behaviour = NULL;
    }
    if (frbc_storage_description->provides_fill_level_target_profile) {
        free(frbc_storage_description->provides_fill_level_target_profile);
        frbc_storage_description->provides_fill_level_target_profile = NULL;
    }
    if (frbc_storage_description->provides_usage_forecast) {
        free(frbc_storage_description->provides_usage_forecast);
        frbc_storage_description->provides_usage_forecast = NULL;
    }
    if (frbc_storage_description->fill_level_range) {
        number_range_free(frbc_storage_description->fill_level_range);
        frbc_storage_description->fill_level_range = NULL;
    }
    free(frbc_storage_description);
}

cJSON *frbc_storage_description_convertToJSON(frbc_storage_description_t *frbc_storage_description) {
    cJSON *item = cJSON_CreateObject();

    // frbc_storage_description->diagnostic_label
    if(frbc_storage_description->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", frbc_storage_description->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // frbc_storage_description->fill_level_label
    if(frbc_storage_description->fill_level_label) {
    if(cJSON_AddStringToObject(item, "fill_level_label", frbc_storage_description->fill_level_label) == NULL) {
    goto fail; //String
    }
    }


    // frbc_storage_description->provides_leakage_behaviour
    if (!frbc_storage_description->provides_leakage_behaviour) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "provides_leakage_behaviour", *frbc_storage_description->provides_leakage_behaviour) == NULL) {
    goto fail; //Bool
    }


    // frbc_storage_description->provides_fill_level_target_profile
    if (!frbc_storage_description->provides_fill_level_target_profile) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "provides_fill_level_target_profile", *frbc_storage_description->provides_fill_level_target_profile) == NULL) {
    goto fail; //Bool
    }


    // frbc_storage_description->provides_usage_forecast
    if (!frbc_storage_description->provides_usage_forecast) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "provides_usage_forecast", *frbc_storage_description->provides_usage_forecast) == NULL) {
    goto fail; //Bool
    }


    // frbc_storage_description->fill_level_range
    if (!frbc_storage_description->fill_level_range) {
        goto fail;
    }
    cJSON *fill_level_range_local_JSON = number_range_convertToJSON(frbc_storage_description->fill_level_range);
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

frbc_storage_description_t *frbc_storage_description_parseFromJSON(cJSON *frbc_storage_descriptionJSON){

    frbc_storage_description_t *frbc_storage_description_local_var = NULL;

    char *diagnostic_label_local_str = NULL;

    char *fill_level_label_local_str = NULL;

    // define the local variable for frbc_storage_description->provides_leakage_behaviour
    int *provides_leakage_behaviour_local_var = NULL;

    // define the local variable for frbc_storage_description->provides_fill_level_target_profile
    int *provides_fill_level_target_profile_local_var = NULL;

    // define the local variable for frbc_storage_description->provides_usage_forecast
    int *provides_usage_forecast_local_var = NULL;

    // define the local variable for frbc_storage_description->fill_level_range
    number_range_t *fill_level_range_local_nonprim = NULL;

    // frbc_storage_description->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // frbc_storage_description->fill_level_label
    cJSON *fill_level_label = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "fill_level_label");
    if (cJSON_IsNull(fill_level_label)) {
        fill_level_label = NULL;
    }
    if (fill_level_label) { 
    if(!cJSON_IsString(fill_level_label) && !cJSON_IsNull(fill_level_label))
    {
    goto end; //String
    }
    }

    // frbc_storage_description->provides_leakage_behaviour
    cJSON *provides_leakage_behaviour = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "provides_leakage_behaviour");
    if (cJSON_IsNull(provides_leakage_behaviour)) {
        provides_leakage_behaviour = NULL;
    }
    if (!provides_leakage_behaviour) {
        goto end;
    }

    
    if(!cJSON_IsBool(provides_leakage_behaviour))
    {
    goto end; //Bool
    }
    provides_leakage_behaviour_local_var = malloc(sizeof(int));
    if(!provides_leakage_behaviour_local_var)
    {
        goto end;
    }
    *provides_leakage_behaviour_local_var = provides_leakage_behaviour->valueint;

    // frbc_storage_description->provides_fill_level_target_profile
    cJSON *provides_fill_level_target_profile = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "provides_fill_level_target_profile");
    if (cJSON_IsNull(provides_fill_level_target_profile)) {
        provides_fill_level_target_profile = NULL;
    }
    if (!provides_fill_level_target_profile) {
        goto end;
    }

    
    if(!cJSON_IsBool(provides_fill_level_target_profile))
    {
    goto end; //Bool
    }
    provides_fill_level_target_profile_local_var = malloc(sizeof(int));
    if(!provides_fill_level_target_profile_local_var)
    {
        goto end;
    }
    *provides_fill_level_target_profile_local_var = provides_fill_level_target_profile->valueint;

    // frbc_storage_description->provides_usage_forecast
    cJSON *provides_usage_forecast = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "provides_usage_forecast");
    if (cJSON_IsNull(provides_usage_forecast)) {
        provides_usage_forecast = NULL;
    }
    if (!provides_usage_forecast) {
        goto end;
    }

    
    if(!cJSON_IsBool(provides_usage_forecast))
    {
    goto end; //Bool
    }
    provides_usage_forecast_local_var = malloc(sizeof(int));
    if(!provides_usage_forecast_local_var)
    {
        goto end;
    }
    *provides_usage_forecast_local_var = provides_usage_forecast->valueint;

    // frbc_storage_description->fill_level_range
    cJSON *fill_level_range = cJSON_GetObjectItemCaseSensitive(frbc_storage_descriptionJSON, "fill_level_range");
    if (cJSON_IsNull(fill_level_range)) {
        fill_level_range = NULL;
    }
    if (!fill_level_range) {
        goto end;
    }

    
    fill_level_range_local_nonprim = number_range_parseFromJSON(fill_level_range); //nonprimitive


    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);
    if (fill_level_label && !cJSON_IsNull(fill_level_label)) fill_level_label_local_str = strdup(fill_level_label->valuestring);

    frbc_storage_description_local_var = frbc_storage_description_create_internal (
        diagnostic_label_local_str,
        fill_level_label_local_str,
        provides_leakage_behaviour_local_var,
        provides_fill_level_target_profile_local_var,
        provides_usage_forecast_local_var,
        fill_level_range_local_nonprim
        );

    if (!frbc_storage_description_local_var) {
        goto end;
    }

    return frbc_storage_description_local_var;
end:
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    if (fill_level_label_local_str) {
        free(fill_level_label_local_str);
        fill_level_label_local_str = NULL;
    }
    if (provides_leakage_behaviour_local_var) {
        free(provides_leakage_behaviour_local_var);
        provides_leakage_behaviour_local_var = NULL;
    }
    if (provides_fill_level_target_profile_local_var) {
        free(provides_fill_level_target_profile_local_var);
        provides_fill_level_target_profile_local_var = NULL;
    }
    if (provides_usage_forecast_local_var) {
        free(provides_usage_forecast_local_var);
        provides_usage_forecast_local_var = NULL;
    }
    if (fill_level_range_local_nonprim) {
        number_range_free(fill_level_range_local_nonprim);
        fill_level_range_local_nonprim = NULL;
    }
    return NULL;

}
