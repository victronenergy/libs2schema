#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ddbc_instruction.h>



static ddbc_instruction_t *ddbc_instruction_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *actuator_id,
    char *operation_mode_id,
    double *operation_mode_factor
    ) {
    ddbc_instruction_t *ddbc_instruction_local_var = malloc(sizeof(ddbc_instruction_t));
    if (!ddbc_instruction_local_var) {
        return NULL;
    }
    memset(ddbc_instruction_local_var, 0, sizeof(ddbc_instruction_t));
    ddbc_instruction_local_var->_library_owned = 1;
    ddbc_instruction_local_var->message_type = message_type;
    ddbc_instruction_local_var->message_id = message_id;
    ddbc_instruction_local_var->id = id;
    ddbc_instruction_local_var->execution_time = execution_time;
    ddbc_instruction_local_var->abnormal_condition = abnormal_condition;
    ddbc_instruction_local_var->actuator_id = actuator_id;
    ddbc_instruction_local_var->operation_mode_id = operation_mode_id;
    ddbc_instruction_local_var->operation_mode_factor = operation_mode_factor;
    return ddbc_instruction_local_var;
}

__attribute__((deprecated)) ddbc_instruction_t *ddbc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *actuator_id,
    char *operation_mode_id,
    double *operation_mode_factor
    ) {
    int *abnormal_condition_copy = NULL;
    if (abnormal_condition) {
        abnormal_condition_copy = malloc(sizeof(int));
        if (abnormal_condition_copy) *abnormal_condition_copy = *abnormal_condition;
    }
    double *operation_mode_factor_copy = NULL;
    if (operation_mode_factor) {
        operation_mode_factor_copy = malloc(sizeof(double));
        if (operation_mode_factor_copy) *operation_mode_factor_copy = *operation_mode_factor;
    }
    ddbc_instruction_t *result = ddbc_instruction_create_internal (
        message_type,
        message_id,
        id,
        execution_time,
        abnormal_condition_copy,
        actuator_id,
        operation_mode_id,
        operation_mode_factor_copy
        );
    if (!result) {
        free(abnormal_condition_copy);
        free(operation_mode_factor_copy);
    }
    return result;
}

void ddbc_instruction_free(ddbc_instruction_t *ddbc_instruction) {
    if(NULL == ddbc_instruction){
        return ;
    }
    if(ddbc_instruction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ddbc_instruction_free");
        return ;
    }
    if (ddbc_instruction->message_type) {
        free(ddbc_instruction->message_type);
        ddbc_instruction->message_type = NULL;
    }
    if (ddbc_instruction->message_id) {
        free(ddbc_instruction->message_id);
        ddbc_instruction->message_id = NULL;
    }
    if (ddbc_instruction->id) {
        free(ddbc_instruction->id);
        ddbc_instruction->id = NULL;
    }
    if (ddbc_instruction->execution_time) {
        free(ddbc_instruction->execution_time);
        ddbc_instruction->execution_time = NULL;
    }
    if (ddbc_instruction->abnormal_condition) {
        free(ddbc_instruction->abnormal_condition);
        ddbc_instruction->abnormal_condition = NULL;
    }
    if (ddbc_instruction->actuator_id) {
        free(ddbc_instruction->actuator_id);
        ddbc_instruction->actuator_id = NULL;
    }
    if (ddbc_instruction->operation_mode_id) {
        free(ddbc_instruction->operation_mode_id);
        ddbc_instruction->operation_mode_id = NULL;
    }
    if (ddbc_instruction->operation_mode_factor) {
        free(ddbc_instruction->operation_mode_factor);
        ddbc_instruction->operation_mode_factor = NULL;
    }
    free(ddbc_instruction);
}

cJSON *ddbc_instruction_convertToJSON(ddbc_instruction_t *ddbc_instruction) {
    cJSON *item = cJSON_CreateObject();

    // ddbc_instruction->message_type
    if (!ddbc_instruction->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ddbc_instruction->message_type) == NULL) {
    goto fail; //String
    }


    // ddbc_instruction->message_id
    if (!ddbc_instruction->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ddbc_instruction->message_id) == NULL) {
    goto fail; //String
    }


    // ddbc_instruction->id
    if (!ddbc_instruction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ddbc_instruction->id) == NULL) {
    goto fail; //String
    }


    // ddbc_instruction->execution_time
    if (!ddbc_instruction->execution_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_time", ddbc_instruction->execution_time) == NULL) {
    goto fail; //Date-Time
    }


    // ddbc_instruction->abnormal_condition
    if (!ddbc_instruction->abnormal_condition) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition", *ddbc_instruction->abnormal_condition) == NULL) {
    goto fail; //Bool
    }


    // ddbc_instruction->actuator_id
    if (!ddbc_instruction->actuator_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "actuator_id", ddbc_instruction->actuator_id) == NULL) {
    goto fail; //String
    }


    // ddbc_instruction->operation_mode_id
    if (!ddbc_instruction->operation_mode_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operation_mode_id", ddbc_instruction->operation_mode_id) == NULL) {
    goto fail; //String
    }


    // ddbc_instruction->operation_mode_factor
    if (!ddbc_instruction->operation_mode_factor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operation_mode_factor", *ddbc_instruction->operation_mode_factor) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ddbc_instruction_t *ddbc_instruction_parseFromJSON(cJSON *ddbc_instructionJSON){

    ddbc_instruction_t *ddbc_instruction_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *execution_time_local_str = NULL;

    // define the local variable for ddbc_instruction->abnormal_condition
    int *abnormal_condition_local_var = NULL;

    char *actuator_id_local_str = NULL;

    char *operation_mode_id_local_str = NULL;

    // define the local variable for ddbc_instruction->operation_mode_factor
    double *operation_mode_factor_local_var = NULL;

    // ddbc_instruction->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "message_type");
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

    // ddbc_instruction->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "message_id");
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

    // ddbc_instruction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "id");
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

    // ddbc_instruction->execution_time
    cJSON *execution_time = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "execution_time");
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

    // ddbc_instruction->abnormal_condition
    cJSON *abnormal_condition = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "abnormal_condition");
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

    // ddbc_instruction->actuator_id
    cJSON *actuator_id = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "actuator_id");
    if (cJSON_IsNull(actuator_id)) {
        actuator_id = NULL;
    }
    if (!actuator_id) {
        goto end;
    }

    
    if(!cJSON_IsString(actuator_id))
    {
    goto end; //String
    }

    // ddbc_instruction->operation_mode_id
    cJSON *operation_mode_id = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "operation_mode_id");
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

    // ddbc_instruction->operation_mode_factor
    cJSON *operation_mode_factor = cJSON_GetObjectItemCaseSensitive(ddbc_instructionJSON, "operation_mode_factor");
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


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (execution_time && !cJSON_IsNull(execution_time)) execution_time_local_str = strdup(execution_time->valuestring);
    if (actuator_id && !cJSON_IsNull(actuator_id)) actuator_id_local_str = strdup(actuator_id->valuestring);
    if (operation_mode_id && !cJSON_IsNull(operation_mode_id)) operation_mode_id_local_str = strdup(operation_mode_id->valuestring);

    ddbc_instruction_local_var = ddbc_instruction_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        execution_time_local_str,
        abnormal_condition_local_var,
        actuator_id_local_str,
        operation_mode_id_local_str,
        operation_mode_factor_local_var
        );

    if (!ddbc_instruction_local_var) {
        goto end;
    }

    return ddbc_instruction_local_var;
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
    if (abnormal_condition_local_var) {
        free(abnormal_condition_local_var);
        abnormal_condition_local_var = NULL;
    }
    if (actuator_id_local_str) {
        free(actuator_id_local_str);
        actuator_id_local_str = NULL;
    }
    if (operation_mode_id_local_str) {
        free(operation_mode_id_local_str);
        operation_mode_id_local_str = NULL;
    }
    if (operation_mode_factor_local_var) {
        free(operation_mode_factor_local_var);
        operation_mode_factor_local_var = NULL;
    }
    return NULL;

}
