#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_instruction.h>



static pebc_instruction_t *pebc_instruction_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *power_constraints_id,
    list_t *power_envelopes
    ) {
    pebc_instruction_t *pebc_instruction_local_var = malloc(sizeof(pebc_instruction_t));
    if (!pebc_instruction_local_var) {
        return NULL;
    }
    memset(pebc_instruction_local_var, 0, sizeof(pebc_instruction_t));
    pebc_instruction_local_var->_library_owned = 1;
    pebc_instruction_local_var->message_type = message_type;
    pebc_instruction_local_var->message_id = message_id;
    pebc_instruction_local_var->id = id;
    pebc_instruction_local_var->execution_time = execution_time;
    pebc_instruction_local_var->abnormal_condition = abnormal_condition;
    pebc_instruction_local_var->power_constraints_id = power_constraints_id;
    pebc_instruction_local_var->power_envelopes = power_envelopes;
    return pebc_instruction_local_var;
}

__attribute__((deprecated)) pebc_instruction_t *pebc_instruction_create(
    char *message_type,
    char *message_id,
    char *id,
    char *execution_time,
    int *abnormal_condition,
    char *power_constraints_id,
    list_t *power_envelopes
    ) {
    int *abnormal_condition_copy = NULL;
    if (abnormal_condition) {
        abnormal_condition_copy = malloc(sizeof(int));
        if (abnormal_condition_copy) *abnormal_condition_copy = *abnormal_condition;
    }
    pebc_instruction_t *result = pebc_instruction_create_internal (
        message_type,
        message_id,
        id,
        execution_time,
        abnormal_condition_copy,
        power_constraints_id,
        power_envelopes
        );
    if (!result) {
        free(abnormal_condition_copy);
    }
    return result;
}

void pebc_instruction_free(pebc_instruction_t *pebc_instruction) {
    if(NULL == pebc_instruction){
        return ;
    }
    if(pebc_instruction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_instruction_free");
        return ;
    }
    if (pebc_instruction->message_type) {
        free(pebc_instruction->message_type);
        pebc_instruction->message_type = NULL;
    }
    if (pebc_instruction->message_id) {
        free(pebc_instruction->message_id);
        pebc_instruction->message_id = NULL;
    }
    if (pebc_instruction->id) {
        free(pebc_instruction->id);
        pebc_instruction->id = NULL;
    }
    if (pebc_instruction->execution_time) {
        free(pebc_instruction->execution_time);
        pebc_instruction->execution_time = NULL;
    }
    if (pebc_instruction->abnormal_condition) {
        free(pebc_instruction->abnormal_condition);
        pebc_instruction->abnormal_condition = NULL;
    }
    if (pebc_instruction->power_constraints_id) {
        free(pebc_instruction->power_constraints_id);
        pebc_instruction->power_constraints_id = NULL;
    }
    if (pebc_instruction->power_envelopes) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, pebc_instruction->power_envelopes) {
            pebc_power_envelope_free(listEntry->data);
        }
        list_freeList(pebc_instruction->power_envelopes);
        pebc_instruction->power_envelopes = NULL;
    }
    free(pebc_instruction);
}

cJSON *pebc_instruction_convertToJSON(pebc_instruction_t *pebc_instruction) {
    cJSON *item = cJSON_CreateObject();

    // pebc_instruction->message_type
    if (!pebc_instruction->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", pebc_instruction->message_type) == NULL) {
    goto fail; //String
    }


    // pebc_instruction->message_id
    if (!pebc_instruction->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", pebc_instruction->message_id) == NULL) {
    goto fail; //String
    }


    // pebc_instruction->id
    if (!pebc_instruction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", pebc_instruction->id) == NULL) {
    goto fail; //String
    }


    // pebc_instruction->execution_time
    if (!pebc_instruction->execution_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "execution_time", pebc_instruction->execution_time) == NULL) {
    goto fail; //Date-Time
    }


    // pebc_instruction->abnormal_condition
    if (!pebc_instruction->abnormal_condition) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition", *pebc_instruction->abnormal_condition) == NULL) {
    goto fail; //Bool
    }


    // pebc_instruction->power_constraints_id
    if (!pebc_instruction->power_constraints_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "power_constraints_id", pebc_instruction->power_constraints_id) == NULL) {
    goto fail; //String
    }


    // pebc_instruction->power_envelopes
    if (!pebc_instruction->power_envelopes) {
        goto fail;
    }
    cJSON *power_envelopes = cJSON_AddArrayToObject(item, "power_envelopes");
    if(power_envelopes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_envelopesListEntry;
    if (pebc_instruction->power_envelopes) {
    list_ForEach(power_envelopesListEntry, pebc_instruction->power_envelopes) {
    cJSON *itemLocal = pebc_power_envelope_convertToJSON(power_envelopesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_envelopes, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_instruction_t *pebc_instruction_parseFromJSON(cJSON *pebc_instructionJSON){

    pebc_instruction_t *pebc_instruction_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *execution_time_local_str = NULL;

    // define the local variable for pebc_instruction->abnormal_condition
    int *abnormal_condition_local_var = NULL;

    char *power_constraints_id_local_str = NULL;

    // define the local list for pebc_instruction->power_envelopes
    list_t *power_envelopesList = NULL;

    // pebc_instruction->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "message_type");
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

    // pebc_instruction->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "message_id");
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

    // pebc_instruction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "id");
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

    // pebc_instruction->execution_time
    cJSON *execution_time = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "execution_time");
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

    // pebc_instruction->abnormal_condition
    cJSON *abnormal_condition = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "abnormal_condition");
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

    // pebc_instruction->power_constraints_id
    cJSON *power_constraints_id = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "power_constraints_id");
    if (cJSON_IsNull(power_constraints_id)) {
        power_constraints_id = NULL;
    }
    if (!power_constraints_id) {
        goto end;
    }

    
    if(!cJSON_IsString(power_constraints_id))
    {
    goto end; //String
    }

    // pebc_instruction->power_envelopes
    cJSON *power_envelopes = cJSON_GetObjectItemCaseSensitive(pebc_instructionJSON, "power_envelopes");
    if (cJSON_IsNull(power_envelopes)) {
        power_envelopes = NULL;
    }
    if (!power_envelopes) {
        goto end;
    }

    
    cJSON *power_envelopes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_envelopes)){
        goto end; //nonprimitive container
    }

    power_envelopesList = list_createList();

    cJSON_ArrayForEach(power_envelopes_local_nonprimitive,power_envelopes )
    {
        if(!cJSON_IsObject(power_envelopes_local_nonprimitive)){
            goto end;
        }
        pebc_power_envelope_t *power_envelopesItem = pebc_power_envelope_parseFromJSON(power_envelopes_local_nonprimitive);

        list_addElement(power_envelopesList, power_envelopesItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (execution_time && !cJSON_IsNull(execution_time)) execution_time_local_str = strdup(execution_time->valuestring);
    if (power_constraints_id && !cJSON_IsNull(power_constraints_id)) power_constraints_id_local_str = strdup(power_constraints_id->valuestring);

    pebc_instruction_local_var = pebc_instruction_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        execution_time_local_str,
        abnormal_condition_local_var,
        power_constraints_id_local_str,
        power_envelopesList
        );

    if (!pebc_instruction_local_var) {
        goto end;
    }

    return pebc_instruction_local_var;
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
    if (power_constraints_id_local_str) {
        free(power_constraints_id_local_str);
        power_constraints_id_local_str = NULL;
    }
    if (power_envelopesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_envelopesList) {
            pebc_power_envelope_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_envelopesList);
        power_envelopesList = NULL;
    }
    return NULL;

}
