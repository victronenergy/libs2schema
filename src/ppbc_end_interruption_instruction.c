#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_end_interruption_instruction.h>



static ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *power_profile_id,
    char *sequence_container_id,
    char *power_sequence_id,
    char *execution_time,
    int *abnormal_condition
    ) {
    ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction_local_var = malloc(sizeof(ppbc_end_interruption_instruction_t));
    if (!ppbc_end_interruption_instruction_local_var) {
        return NULL;
    }
    memset(ppbc_end_interruption_instruction_local_var, 0, sizeof(ppbc_end_interruption_instruction_t));
    ppbc_end_interruption_instruction_local_var->_library_owned = 1;
    ppbc_end_interruption_instruction_local_var->message_type = message_type;
    ppbc_end_interruption_instruction_local_var->message_id = message_id;
    ppbc_end_interruption_instruction_local_var->id = id;
    ppbc_end_interruption_instruction_local_var->power_profile_id = power_profile_id;
    ppbc_end_interruption_instruction_local_var->sequence_container_id = sequence_container_id;
    ppbc_end_interruption_instruction_local_var->power_sequence_id = power_sequence_id;
    ppbc_end_interruption_instruction_local_var->execution_time = execution_time;
    ppbc_end_interruption_instruction_local_var->abnormal_condition = abnormal_condition;
    return ppbc_end_interruption_instruction_local_var;
}

__attribute__((deprecated)) ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *power_profile_id,
    char *sequence_container_id,
    char *power_sequence_id,
    char *execution_time,
    int *abnormal_condition
    ) {
    int *abnormal_condition_copy = NULL;
    if (abnormal_condition) {
        abnormal_condition_copy = malloc(sizeof(int));
        if (abnormal_condition_copy) *abnormal_condition_copy = *abnormal_condition;
    }
    ppbc_end_interruption_instruction_t *result = ppbc_end_interruption_instruction_create_internal (
        message_type,
        message_id,
        id,
        power_profile_id,
        sequence_container_id,
        power_sequence_id,
        execution_time,
        abnormal_condition_copy
        );
    if (!result) {
        free(abnormal_condition_copy);
    }
    return result;
}

void ppbc_end_interruption_instruction_free(ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction) {
    if(NULL == ppbc_end_interruption_instruction){
        return ;
    }
    if(ppbc_end_interruption_instruction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_end_interruption_instruction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ppbc_end_interruption_instruction->message_type) {
        free(ppbc_end_interruption_instruction->message_type);
        ppbc_end_interruption_instruction->message_type = NULL;
    }
    if (ppbc_end_interruption_instruction->message_id) {
        free(ppbc_end_interruption_instruction->message_id);
        ppbc_end_interruption_instruction->message_id = NULL;
    }
    if (ppbc_end_interruption_instruction->id) {
        free(ppbc_end_interruption_instruction->id);
        ppbc_end_interruption_instruction->id = NULL;
    }
    if (ppbc_end_interruption_instruction->power_profile_id) {
        free(ppbc_end_interruption_instruction->power_profile_id);
        ppbc_end_interruption_instruction->power_profile_id = NULL;
    }
    if (ppbc_end_interruption_instruction->sequence_container_id) {
        free(ppbc_end_interruption_instruction->sequence_container_id);
        ppbc_end_interruption_instruction->sequence_container_id = NULL;
    }
    if (ppbc_end_interruption_instruction->power_sequence_id) {
        free(ppbc_end_interruption_instruction->power_sequence_id);
        ppbc_end_interruption_instruction->power_sequence_id = NULL;
    }
    if (ppbc_end_interruption_instruction->execution_time) {
        free(ppbc_end_interruption_instruction->execution_time);
        ppbc_end_interruption_instruction->execution_time = NULL;
    }
    if (ppbc_end_interruption_instruction->abnormal_condition) {
        free(ppbc_end_interruption_instruction->abnormal_condition);
        ppbc_end_interruption_instruction->abnormal_condition = NULL;
    }
    free(ppbc_end_interruption_instruction);
}

cJSON *ppbc_end_interruption_instruction_convertToJSON(ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_end_interruption_instruction->message_type
    if (!ppbc_end_interruption_instruction->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", ppbc_end_interruption_instruction->message_type) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->message_id
    if (!ppbc_end_interruption_instruction->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", ppbc_end_interruption_instruction->message_id) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->id
    if (!ppbc_end_interruption_instruction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ppbc_end_interruption_instruction->id) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->power_profile_id
    if (!ppbc_end_interruption_instruction->power_profile_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "power_profile_id", ppbc_end_interruption_instruction->power_profile_id) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->sequence_container_id
    if (!ppbc_end_interruption_instruction->sequence_container_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sequence_container_id", ppbc_end_interruption_instruction->sequence_container_id) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->power_sequence_id
    if (!ppbc_end_interruption_instruction->power_sequence_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "power_sequence_id", ppbc_end_interruption_instruction->power_sequence_id) == NULL) {
    goto fail; //String
    }


    // ppbc_end_interruption_instruction->execution_time
    if (!ppbc_end_interruption_instruction->execution_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_time", ppbc_end_interruption_instruction->execution_time) == NULL) {
    goto fail; //Date-Time
    }


    // ppbc_end_interruption_instruction->abnormal_condition
    if (!ppbc_end_interruption_instruction->abnormal_condition) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition", *ppbc_end_interruption_instruction->abnormal_condition) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction_parseFromJSON(cJSON *ppbc_end_interruption_instructionJSON){

    ppbc_end_interruption_instruction_t *ppbc_end_interruption_instruction_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *power_profile_id_local_str = NULL;

    char *sequence_container_id_local_str = NULL;

    char *power_sequence_id_local_str = NULL;

    char *execution_time_local_str = NULL;

    // define the local variable for ppbc_end_interruption_instruction->abnormal_condition
    int *abnormal_condition_local_var = NULL;

    // ppbc_end_interruption_instruction->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "message_type");
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

    // ppbc_end_interruption_instruction->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "message_id");
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

    // ppbc_end_interruption_instruction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "id");
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

    // ppbc_end_interruption_instruction->power_profile_id
    cJSON *power_profile_id = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "power_profile_id");
    if (cJSON_IsNull(power_profile_id)) {
        power_profile_id = NULL;
    }
    if (!power_profile_id) {
        goto end;
    }

    
    if(!cJSON_IsString(power_profile_id))
    {
    goto end; //String
    }

    // ppbc_end_interruption_instruction->sequence_container_id
    cJSON *sequence_container_id = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "sequence_container_id");
    if (cJSON_IsNull(sequence_container_id)) {
        sequence_container_id = NULL;
    }
    if (!sequence_container_id) {
        goto end;
    }

    
    if(!cJSON_IsString(sequence_container_id))
    {
    goto end; //String
    }

    // ppbc_end_interruption_instruction->power_sequence_id
    cJSON *power_sequence_id = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "power_sequence_id");
    if (cJSON_IsNull(power_sequence_id)) {
        power_sequence_id = NULL;
    }
    if (!power_sequence_id) {
        goto end;
    }

    
    if(!cJSON_IsString(power_sequence_id))
    {
    goto end; //String
    }

    // ppbc_end_interruption_instruction->execution_time
    cJSON *execution_time = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "execution_time");
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

    // ppbc_end_interruption_instruction->abnormal_condition
    cJSON *abnormal_condition = cJSON_GetObjectItemCaseSensitive(ppbc_end_interruption_instructionJSON, "abnormal_condition");
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
    if (power_profile_id && !cJSON_IsNull(power_profile_id)) power_profile_id_local_str = strdup(power_profile_id->valuestring);
    if (sequence_container_id && !cJSON_IsNull(sequence_container_id)) sequence_container_id_local_str = strdup(sequence_container_id->valuestring);
    if (power_sequence_id && !cJSON_IsNull(power_sequence_id)) power_sequence_id_local_str = strdup(power_sequence_id->valuestring);
    if (execution_time && !cJSON_IsNull(execution_time)) execution_time_local_str = strdup(execution_time->valuestring);

    ppbc_end_interruption_instruction_local_var = ppbc_end_interruption_instruction_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        power_profile_id_local_str,
        sequence_container_id_local_str,
        power_sequence_id_local_str,
        execution_time_local_str,
        abnormal_condition_local_var
        );

    if (!ppbc_end_interruption_instruction_local_var) {
        goto end;
    }

    return ppbc_end_interruption_instruction_local_var;
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
    if (power_profile_id_local_str) {
        free(power_profile_id_local_str);
        power_profile_id_local_str = NULL;
    }
    if (sequence_container_id_local_str) {
        free(sequence_container_id_local_str);
        sequence_container_id_local_str = NULL;
    }
    if (power_sequence_id_local_str) {
        free(power_sequence_id_local_str);
        power_sequence_id_local_str = NULL;
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
