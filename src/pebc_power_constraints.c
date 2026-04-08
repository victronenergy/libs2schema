#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_power_constraints.h>



static pebc_power_constraints_t *pebc_power_constraints_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    s2_pebc_power_envelope_consequence_type__e consequence_type,
    list_t *allowed_limit_ranges
    ) {
    pebc_power_constraints_t *pebc_power_constraints_local_var = malloc(sizeof(pebc_power_constraints_t));
    if (!pebc_power_constraints_local_var) {
        return NULL;
    }
    memset(pebc_power_constraints_local_var, 0, sizeof(pebc_power_constraints_t));
    pebc_power_constraints_local_var->_library_owned = 1;
    pebc_power_constraints_local_var->message_type = message_type;
    pebc_power_constraints_local_var->message_id = message_id;
    pebc_power_constraints_local_var->id = id;
    pebc_power_constraints_local_var->valid_from = valid_from;
    pebc_power_constraints_local_var->valid_until = valid_until;
    pebc_power_constraints_local_var->consequence_type = consequence_type;
    pebc_power_constraints_local_var->allowed_limit_ranges = allowed_limit_ranges;
    return pebc_power_constraints_local_var;
}

__attribute__((deprecated)) pebc_power_constraints_t *pebc_power_constraints_create(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    s2_pebc_power_envelope_consequence_type__e consequence_type,
    list_t *allowed_limit_ranges
    ) {
    pebc_power_constraints_t *result = pebc_power_constraints_create_internal (
        message_type,
        message_id,
        id,
        valid_from,
        valid_until,
        consequence_type,
        allowed_limit_ranges
        );
    if (!result) {
    }
    return result;
}

void pebc_power_constraints_free(pebc_power_constraints_t *pebc_power_constraints) {
    if(NULL == pebc_power_constraints){
        return ;
    }
    if(pebc_power_constraints->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_power_constraints_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pebc_power_constraints->message_type) {
        free(pebc_power_constraints->message_type);
        pebc_power_constraints->message_type = NULL;
    }
    if (pebc_power_constraints->message_id) {
        free(pebc_power_constraints->message_id);
        pebc_power_constraints->message_id = NULL;
    }
    if (pebc_power_constraints->id) {
        free(pebc_power_constraints->id);
        pebc_power_constraints->id = NULL;
    }
    if (pebc_power_constraints->valid_from) {
        free(pebc_power_constraints->valid_from);
        pebc_power_constraints->valid_from = NULL;
    }
    if (pebc_power_constraints->valid_until) {
        free(pebc_power_constraints->valid_until);
        pebc_power_constraints->valid_until = NULL;
    }
    if (pebc_power_constraints->allowed_limit_ranges) {
        list_ForEach(listEntry, pebc_power_constraints->allowed_limit_ranges) {
            pebc_allowed_limit_range_free(listEntry->data);
        }
        list_freeList(pebc_power_constraints->allowed_limit_ranges);
        pebc_power_constraints->allowed_limit_ranges = NULL;
    }
    free(pebc_power_constraints);
}

cJSON *pebc_power_constraints_convertToJSON(pebc_power_constraints_t *pebc_power_constraints) {
    cJSON *item = cJSON_CreateObject();

    // pebc_power_constraints->message_type
    if (!pebc_power_constraints->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", pebc_power_constraints->message_type) == NULL) {
    goto fail; //String
    }


    // pebc_power_constraints->message_id
    if (!pebc_power_constraints->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", pebc_power_constraints->message_id) == NULL) {
    goto fail; //String
    }


    // pebc_power_constraints->id
    if (!pebc_power_constraints->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", pebc_power_constraints->id) == NULL) {
    goto fail; //String
    }


    // pebc_power_constraints->valid_from
    if (!pebc_power_constraints->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", pebc_power_constraints->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // pebc_power_constraints->valid_until
    if(pebc_power_constraints->valid_until) {
    if(cJSON_AddStringToObject(item, "valid_until", pebc_power_constraints->valid_until) == NULL) {
    goto fail; //Date-Time
    }
    }


    // pebc_power_constraints->consequence_type
    if (s2_pebc_power_envelope_consequence_type__NULL == pebc_power_constraints->consequence_type) {
        goto fail;
    }
    cJSON *consequence_type_local_JSON = pebc_power_envelope_consequence_type_convertToJSON(pebc_power_constraints->consequence_type);
    if(consequence_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "consequence_type", consequence_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // pebc_power_constraints->allowed_limit_ranges
    if (!pebc_power_constraints->allowed_limit_ranges) {
        goto fail;
    }
    cJSON *allowed_limit_ranges = cJSON_AddArrayToObject(item, "allowed_limit_ranges");
    if(allowed_limit_ranges == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_limit_rangesListEntry;
    if (pebc_power_constraints->allowed_limit_ranges) {
    list_ForEach(allowed_limit_rangesListEntry, pebc_power_constraints->allowed_limit_ranges) {
    cJSON *itemLocal = pebc_allowed_limit_range_convertToJSON(allowed_limit_rangesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_limit_ranges, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_power_constraints_t *pebc_power_constraints_parseFromJSON(cJSON *pebc_power_constraintsJSON){

    pebc_power_constraints_t *pebc_power_constraints_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *valid_until_local_str = NULL;

    // define the local variable for pebc_power_constraints->consequence_type
    s2_pebc_power_envelope_consequence_type__e consequence_type_local_nonprim = 0;

    // define the local list for pebc_power_constraints->allowed_limit_ranges
    list_t *allowed_limit_rangesList = NULL;

    // pebc_power_constraints->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "message_type");
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

    // pebc_power_constraints->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "message_id");
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

    // pebc_power_constraints->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "id");
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

    // pebc_power_constraints->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "valid_from");
    if (cJSON_IsNull(valid_from)) {
        valid_from = NULL;
    }
    if (!valid_from) {
        goto end;
    }

    
    if(!cJSON_IsString(valid_from) && !cJSON_IsNull(valid_from))
    {
    goto end; //DateTime
    }

    // pebc_power_constraints->valid_until
    cJSON *valid_until = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "valid_until");
    if (cJSON_IsNull(valid_until)) {
        valid_until = NULL;
    }
    if (valid_until) { 
    if(!cJSON_IsString(valid_until) && !cJSON_IsNull(valid_until))
    {
    goto end; //DateTime
    }
    }

    // pebc_power_constraints->consequence_type
    cJSON *consequence_type = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "consequence_type");
    if (cJSON_IsNull(consequence_type)) {
        consequence_type = NULL;
    }
    if (!consequence_type) {
        goto end;
    }

    
    consequence_type_local_nonprim = pebc_power_envelope_consequence_type_parseFromJSON(consequence_type); //custom

    // pebc_power_constraints->allowed_limit_ranges
    cJSON *allowed_limit_ranges = cJSON_GetObjectItemCaseSensitive(pebc_power_constraintsJSON, "allowed_limit_ranges");
    if (cJSON_IsNull(allowed_limit_ranges)) {
        allowed_limit_ranges = NULL;
    }
    if (!allowed_limit_ranges) {
        goto end;
    }

    
    cJSON *allowed_limit_ranges_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_limit_ranges)){
        goto end; //nonprimitive container
    }

    allowed_limit_rangesList = list_createList();

    cJSON_ArrayForEach(allowed_limit_ranges_local_nonprimitive,allowed_limit_ranges )
    {
        if(!cJSON_IsObject(allowed_limit_ranges_local_nonprimitive)){
            goto end;
        }
        pebc_allowed_limit_range_t *allowed_limit_rangesItem = pebc_allowed_limit_range_parseFromJSON(allowed_limit_ranges_local_nonprimitive);

        list_addElement(allowed_limit_rangesList, allowed_limit_rangesItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);
    if (valid_until && !cJSON_IsNull(valid_until)) valid_until_local_str = strdup(valid_until->valuestring);

    pebc_power_constraints_local_var = pebc_power_constraints_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        valid_from_local_str,
        valid_until_local_str,
        consequence_type_local_nonprim,
        allowed_limit_rangesList
        );

    if (!pebc_power_constraints_local_var) {
        goto end;
    }

    return pebc_power_constraints_local_var;
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
    if (valid_from_local_str) {
        free(valid_from_local_str);
        valid_from_local_str = NULL;
    }
    if (valid_until_local_str) {
        free(valid_until_local_str);
        valid_until_local_str = NULL;
    }
    if (consequence_type_local_nonprim) {
        consequence_type_local_nonprim = 0;
    }
    if (allowed_limit_rangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_limit_rangesList) {
            pebc_allowed_limit_range_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_limit_rangesList);
        allowed_limit_rangesList = NULL;
    }
    return NULL;

}
