#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/timer_type.h>



static timer_type_t *timer_type_create_internal(
    char *id,
    char *diagnostic_label,
    int *duration
    ) {
    timer_type_t *timer_type_local_var = malloc(sizeof(timer_type_t));
    if (!timer_type_local_var) {
        return NULL;
    }
    memset(timer_type_local_var, 0, sizeof(timer_type_t));
    timer_type_local_var->_library_owned = 1;
    timer_type_local_var->id = id;
    timer_type_local_var->diagnostic_label = diagnostic_label;
    timer_type_local_var->duration = duration;
    return timer_type_local_var;
}

__attribute__((deprecated)) timer_type_t *timer_type_create(
    char *id,
    char *diagnostic_label,
    int *duration
    ) {
    int *duration_copy = NULL;
    if (duration) {
        duration_copy = malloc(sizeof(int));
        if (duration_copy) *duration_copy = *duration;
    }
    timer_type_t *result = timer_type_create_internal (
        id,
        diagnostic_label,
        duration_copy
        );
    if (!result) {
        free(duration_copy);
    }
    return result;
}

void timer_type_free(timer_type_t *timer_type) {
    if(NULL == timer_type){
        return ;
    }
    if(timer_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "timer_type_free");
        return ;
    }
    if (timer_type->id) {
        free(timer_type->id);
        timer_type->id = NULL;
    }
    if (timer_type->diagnostic_label) {
        free(timer_type->diagnostic_label);
        timer_type->diagnostic_label = NULL;
    }
    if (timer_type->duration) {
        free(timer_type->duration);
        timer_type->duration = NULL;
    }
    free(timer_type);
}

cJSON *timer_type_convertToJSON(timer_type_t *timer_type) {
    cJSON *item = cJSON_CreateObject();

    // timer_type->id
    if (!timer_type->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", timer_type->id) == NULL) {
    goto fail; //String
    }


    // timer_type->diagnostic_label
    if(timer_type->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", timer_type->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // timer_type->duration
    if (!timer_type->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", *timer_type->duration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

timer_type_t *timer_type_parseFromJSON(cJSON *timer_typeJSON){

    timer_type_t *timer_type_local_var = NULL;

    char *id_local_str = NULL;

    char *diagnostic_label_local_str = NULL;

    // define the local variable for timer_type->duration
    int *duration_local_var = NULL;

    // timer_type->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(timer_typeJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // timer_type->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(timer_typeJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // timer_type->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(timer_typeJSON, "duration");
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


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    timer_type_local_var = timer_type_create_internal (
        id_local_str,
        diagnostic_label_local_str,
        duration_local_var
        );

    if (!timer_type_local_var) {
        goto end;
    }

    return timer_type_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    if (duration_local_var) {
        free(duration_local_var);
        duration_local_var = NULL;
    }
    return NULL;

}
