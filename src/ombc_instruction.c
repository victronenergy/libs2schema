#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ombc_instruction.h>



static ombc_instruction_t *ombc_instruction_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    char *operation_mode_id,
    double *operation_mode_factor,
    int *abnormal_condition
    ) {
    ombc_instruction_t *ombc_instruction_local_var = malloc(sizeof(ombc_instruction_t));
    if (!ombc_instruction_local_var) {
        return NULL;
    }
    memset(ombc_instruction_local_var, 0, sizeof(ombc_instruction_t));
    ombc_instruction_local_var->_library_owned = 1;
    ombc_instruction_local_var->message_type = message_type;
    ombc_instruction_local_var->message_id = message_id;
    ombc_instruction_local_var->id = id;
    ombc_instruction_local_var->execution_time = execution_time;
    ombc_instruction_local_var->operation_mode_id = operation_mode_id;
    ombc_instruction_local_var->operation_mode_factor = operation_mode_factor;
    ombc_instruction_local_var->abnormal_condition = abnormal_condition;
    return ombc_instruction_local_var;
}

__attribute__((deprecated)) ombc_instruction_t *ombc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    char *operation_mode_id,
    double *operation_mode_factor,
    int *abnormal_condition
    ) {
    double *operation_mode_factor_copy = NULL;
    if (operation_mode_factor) {
        operation_mode_factor_copy = malloc(sizeof(double));
        if (operation_mode_factor_copy) *operation_mode_factor_copy = *operation_mode_factor;
    }
    int *abnormal_condition_copy = NULL;
    if (abnormal_condition) {
        abnormal_condition_copy = malloc(sizeof(int));
        if (abnormal_condition_copy) *abnormal_condition_copy = *abnormal_condition;
    }
    ombc_instruction_t *result = ombc_instruction_create_internal (
        message_type,
        message_id,
        id,
        execution_time,
        operation_mode_id,
        operation_mode_factor_copy,
        abnormal_condition_copy
        );
    if (!result) {
        free(operation_mode_factor_copy);
        free(abnormal_condition_copy);
    }
    return result;
}

void ombc_instruction_free(ombc_instruction_t *ombc_instruction) {
    if(NULL == ombc_instruction){
        return ;
    }
    if(ombc_instruction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ombc_instruction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ombc_instruction->message_type) {
        free(ombc_instruction->message_type);
        ombc_instruction->message_type = NULL;
    }
    if (ombc_instruction->message_id) {
        free(ombc_instruction->message_id);
        ombc_instruction->message_id = NULL;
    }
    if (ombc_instruction->id) {
        free(ombc_instruction->id);
        ombc_instruction->id = NULL;
    }
    if (ombc_instruction->execution_time) {
        free(ombc_instruction->execution_time);
        ombc_instruction->execution_time = NULL;
    }
    if (ombc_instruction->operation_mode_id) {
        free(ombc_instruction->operation_mode_id);
        ombc_instruction->operation_mode_id = NULL;
    }
    if (ombc_instruction->operation_mode_factor) {
        free(ombc_instruction->operation_mode_factor);
        ombc_instruction->operation_mode_factor = NULL;
    }
    if (ombc_instruction->abnormal_condition) {
        free(ombc_instruction->abnormal_condition);
        ombc_instruction->abnormal_condition = NULL;
    }
    free(ombc_instruction);
}

cJSON *ombc_instruction_convertToJSON(ombc_instruction_t *ombc_instruction) {
    cJSON *item = cJSON_CreateObject();

    // ombc_instruction->message_type
    if (!ombc_instruction->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ombc_instruction->message_type) == NULL) {
    goto fail; //String
    }


    // ombc_instruction->message_id
    if (!ombc_instruction->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ombc_instruction->message_id) == NULL) {
    goto fail; //String
    }


    // ombc_instruction->id
    if (!ombc_instruction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ombc_instruction->id) == NULL) {
    goto fail; //String
    }


    // ombc_instruction->execution_time
    if (!ombc_instruction->execution_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_time", ombc_instruction->execution_time) == NULL) {
    goto fail; //Date-Time
    }


    // ombc_instruction->operation_mode_id
    if (!ombc_instruction->operation_mode_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operation_mode_id", ombc_instruction->operation_mode_id) == NULL) {
    goto fail; //String
    }


    // ombc_instruction->operation_mode_factor
    if (!ombc_instruction->operation_mode_factor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operation_mode_factor", *ombc_instruction->operation_mode_factor) == NULL) {
    goto fail; //Numeric
    }


    // ombc_instruction->abnormal_condition
    if (!ombc_instruction->abnormal_condition) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition", *ombc_instruction->abnormal_condition) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ombc_instruction_t *ombc_instruction_parseFromJSON(cJSON *ombc_instructionJSON){

    ombc_instruction_t *ombc_instruction_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *execution_time_local_str = NULL;

    char *operation_mode_id_local_str = NULL;

    // define the local variable for ombc_instruction->operation_mode_factor
    double *operation_mode_factor_local_var = NULL;

    // define the local variable for ombc_instruction->abnormal_condition
    int *abnormal_condition_local_var = NULL;

    // ombc_instruction->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "message_type");
    if (cJSON_IsNull(message_type)) {
        message_type = NULL;
    }
    if (!message_type) {
        goto end;
    }

    
    if(!cJSON_IsString(message_type))
    {
    goto end; //String
    }

    // ombc_instruction->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsString(message_id))
    {
    goto end; //String
    }

    // ombc_instruction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "id");
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

    // ombc_instruction->execution_time
    cJSON *execution_time = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "execution_time");
    if (cJSON_IsNull(execution_time)) {
        execution_time = NULL;
    }
    if (!execution_time) {
        goto end;
    }

    
    if(!cJSON_IsString(execution_time) && !cJSON_IsNull(execution_time))
    {
    goto end; //DateTime
    }

    // ombc_instruction->operation_mode_id
    cJSON *operation_mode_id = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "operation_mode_id");
    if (cJSON_IsNull(operation_mode_id)) {
        operation_mode_id = NULL;
    }
    if (!operation_mode_id) {
        goto end;
    }

    
    if(!cJSON_IsString(operation_mode_id))
    {
    goto end; //String
    }

    // ombc_instruction->operation_mode_factor
    cJSON *operation_mode_factor = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "operation_mode_factor");
    if (cJSON_IsNull(operation_mode_factor)) {
        operation_mode_factor = NULL;
    }
    if (!operation_mode_factor) {
        goto end;
    }

    
    if(!cJSON_IsNumber(operation_mode_factor))
    {
    goto end; //Numeric
    }
    operation_mode_factor_local_var = malloc(sizeof(double));
    if(!operation_mode_factor_local_var)
    {
        goto end;
    }
    *operation_mode_factor_local_var = operation_mode_factor->valuedouble;

    // ombc_instruction->abnormal_condition
    cJSON *abnormal_condition = cJSON_GetObjectItemCaseSensitive(ombc_instructionJSON, "abnormal_condition");
    if (cJSON_IsNull(abnormal_condition)) {
        abnormal_condition = NULL;
    }
    if (!abnormal_condition) {
        goto end;
    }

    
    if(!cJSON_IsBool(abnormal_condition))
    {
    goto end; //Bool
    }
    abnormal_condition_local_var = malloc(sizeof(int));
    if(!abnormal_condition_local_var)
    {
        goto end;
    }
    *abnormal_condition_local_var = abnormal_condition->valueint;


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (execution_time && !cJSON_IsNull(execution_time)) execution_time_local_str = strdup(execution_time->valuestring);
    if (operation_mode_id && !cJSON_IsNull(operation_mode_id)) operation_mode_id_local_str = strdup(operation_mode_id->valuestring);

    ombc_instruction_local_var = ombc_instruction_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        execution_time_local_str,
        operation_mode_id_local_str,
        operation_mode_factor_local_var,
        abnormal_condition_local_var
        );

    if (!ombc_instruction_local_var) {
        goto end;
    }

    return ombc_instruction_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (execution_time_local_str) {
        free(execution_time_local_str);
        execution_time_local_str = NULL;
    }
    if (operation_mode_id_local_str) {
        free(operation_mode_id_local_str);
        operation_mode_id_local_str = NULL;
    }
    if (operation_mode_factor_local_var) {
        free(operation_mode_factor_local_var);
        operation_mode_factor_local_var = NULL;
    }
    if (abnormal_condition_local_var) {
        free(abnormal_condition_local_var);
        abnormal_condition_local_var = NULL;
    }
    return NULL;

}
