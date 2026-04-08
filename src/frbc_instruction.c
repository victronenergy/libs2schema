#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_instruction.h>



static frbc_instruction_t *frbc_instruction_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *actuator_id,
    char *operation_mode,
    double *operation_mode_factor,
    char *execution_time,
    int *abnormal_condition
    ) {
    frbc_instruction_t *frbc_instruction_local_var = malloc(sizeof(frbc_instruction_t));
    if (!frbc_instruction_local_var) {
        return NULL;
    }
    memset(frbc_instruction_local_var, 0, sizeof(frbc_instruction_t));
    frbc_instruction_local_var->_library_owned = 1;
    frbc_instruction_local_var->message_type = message_type;
    frbc_instruction_local_var->message_id = message_id;
    frbc_instruction_local_var->id = id;
    frbc_instruction_local_var->actuator_id = actuator_id;
    frbc_instruction_local_var->operation_mode = operation_mode;
    frbc_instruction_local_var->operation_mode_factor = operation_mode_factor;
    frbc_instruction_local_var->execution_time = execution_time;
    frbc_instruction_local_var->abnormal_condition = abnormal_condition;
    return frbc_instruction_local_var;
}

__attribute__((deprecated)) frbc_instruction_t *frbc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *actuator_id,
    char *operation_mode,
    double *operation_mode_factor,
    char *execution_time,
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
    frbc_instruction_t *result = frbc_instruction_create_internal (
        message_type,
        message_id,
        id,
        actuator_id,
        operation_mode,
        operation_mode_factor_copy,
        execution_time,
        abnormal_condition_copy
        );
    if (!result) {
        free(operation_mode_factor_copy);
        free(abnormal_condition_copy);
    }
    return result;
}

void frbc_instruction_free(frbc_instruction_t *frbc_instruction) {
    if(NULL == frbc_instruction){
        return ;
    }
    if(frbc_instruction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_instruction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_instruction->message_type) {
        free(frbc_instruction->message_type);
        frbc_instruction->message_type = NULL;
    }
    if (frbc_instruction->message_id) {
        free(frbc_instruction->message_id);
        frbc_instruction->message_id = NULL;
    }
    if (frbc_instruction->id) {
        free(frbc_instruction->id);
        frbc_instruction->id = NULL;
    }
    if (frbc_instruction->actuator_id) {
        free(frbc_instruction->actuator_id);
        frbc_instruction->actuator_id = NULL;
    }
    if (frbc_instruction->operation_mode) {
        free(frbc_instruction->operation_mode);
        frbc_instruction->operation_mode = NULL;
    }
    if (frbc_instruction->operation_mode_factor) {
        free(frbc_instruction->operation_mode_factor);
        frbc_instruction->operation_mode_factor = NULL;
    }
    if (frbc_instruction->execution_time) {
        free(frbc_instruction->execution_time);
        frbc_instruction->execution_time = NULL;
    }
    if (frbc_instruction->abnormal_condition) {
        free(frbc_instruction->abnormal_condition);
        frbc_instruction->abnormal_condition = NULL;
    }
    free(frbc_instruction);
}

cJSON *frbc_instruction_convertToJSON(frbc_instruction_t *frbc_instruction) {
    cJSON *item = cJSON_CreateObject();

    // frbc_instruction->message_type
    if (!frbc_instruction->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", frbc_instruction->message_type) == NULL) {
    goto fail; //String
    }


    // frbc_instruction->message_id
    if (!frbc_instruction->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", frbc_instruction->message_id) == NULL) {
    goto fail; //String
    }


    // frbc_instruction->id
    if (!frbc_instruction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", frbc_instruction->id) == NULL) {
    goto fail; //String
    }


    // frbc_instruction->actuator_id
    if (!frbc_instruction->actuator_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "actuator_id", frbc_instruction->actuator_id) == NULL) {
    goto fail; //String
    }


    // frbc_instruction->operation_mode
    if (!frbc_instruction->operation_mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operation_mode", frbc_instruction->operation_mode) == NULL) {
    goto fail; //String
    }


    // frbc_instruction->operation_mode_factor
    if (!frbc_instruction->operation_mode_factor) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "operation_mode_factor", *frbc_instruction->operation_mode_factor) == NULL) {
    goto fail; //Numeric
    }


    // frbc_instruction->execution_time
    if (!frbc_instruction->execution_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_time", frbc_instruction->execution_time) == NULL) {
    goto fail; //Date-Time
    }


    // frbc_instruction->abnormal_condition
    if (!frbc_instruction->abnormal_condition) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition", *frbc_instruction->abnormal_condition) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_instruction_t *frbc_instruction_parseFromJSON(cJSON *frbc_instructionJSON){

    frbc_instruction_t *frbc_instruction_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *actuator_id_local_str = NULL;

    char *operation_mode_local_str = NULL;

    // define the local variable for frbc_instruction->operation_mode_factor
    double *operation_mode_factor_local_var = NULL;

    char *execution_time_local_str = NULL;

    // define the local variable for frbc_instruction->abnormal_condition
    int *abnormal_condition_local_var = NULL;

    // frbc_instruction->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "message_type");
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

    // frbc_instruction->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "message_id");
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

    // frbc_instruction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "id");
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

    // frbc_instruction->actuator_id
    cJSON *actuator_id = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "actuator_id");
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

    // frbc_instruction->operation_mode
    cJSON *operation_mode = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "operation_mode");
    if (cJSON_IsNull(operation_mode)) {
        operation_mode = NULL;
    }
    if (!operation_mode) {
        goto end;
    }

    
    if(!cJSON_IsString(operation_mode))
    {
    goto end; //String
    }

    // frbc_instruction->operation_mode_factor
    cJSON *operation_mode_factor = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "operation_mode_factor");
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

    // frbc_instruction->execution_time
    cJSON *execution_time = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "execution_time");
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

    // frbc_instruction->abnormal_condition
    cJSON *abnormal_condition = cJSON_GetObjectItemCaseSensitive(frbc_instructionJSON, "abnormal_condition");
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
    if (actuator_id && !cJSON_IsNull(actuator_id)) actuator_id_local_str = strdup(actuator_id->valuestring);
    if (operation_mode && !cJSON_IsNull(operation_mode)) operation_mode_local_str = strdup(operation_mode->valuestring);
    if (execution_time && !cJSON_IsNull(execution_time)) execution_time_local_str = strdup(execution_time->valuestring);

    frbc_instruction_local_var = frbc_instruction_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        actuator_id_local_str,
        operation_mode_local_str,
        operation_mode_factor_local_var,
        execution_time_local_str,
        abnormal_condition_local_var
        );

    if (!frbc_instruction_local_var) {
        goto end;
    }

    return frbc_instruction_local_var;
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
    if (actuator_id_local_str) {
        free(actuator_id_local_str);
        actuator_id_local_str = NULL;
    }
    if (operation_mode_local_str) {
        free(operation_mode_local_str);
        operation_mode_local_str = NULL;
    }
    if (operation_mode_factor_local_var) {
        free(operation_mode_factor_local_var);
        operation_mode_factor_local_var = NULL;
    }
    if (execution_time_local_str) {
        free(execution_time_local_str);
        execution_time_local_str = NULL;
    }
    if (abnormal_condition_local_var) {
        free(abnormal_condition_local_var);
        abnormal_condition_local_var = NULL;
    }
    return NULL;

}
