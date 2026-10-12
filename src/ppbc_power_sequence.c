#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_sequence.h>



static ppbc_power_sequence_t *ppbc_power_sequence_create_internal(
    char *id,
    list_t *elements,
    int *is_interruptible,
    int *max_pause_before,
    int *abnormal_condition_only
    ) {
    ppbc_power_sequence_t *ppbc_power_sequence_local_var = malloc(sizeof(ppbc_power_sequence_t));
    if (!ppbc_power_sequence_local_var) {
        return NULL;
    }
    memset(ppbc_power_sequence_local_var, 0, sizeof(ppbc_power_sequence_t));
    ppbc_power_sequence_local_var->_library_owned = 1;
    ppbc_power_sequence_local_var->id = id;
    ppbc_power_sequence_local_var->elements = elements;
    ppbc_power_sequence_local_var->is_interruptible = is_interruptible;
    ppbc_power_sequence_local_var->max_pause_before = max_pause_before;
    ppbc_power_sequence_local_var->abnormal_condition_only = abnormal_condition_only;
    return ppbc_power_sequence_local_var;
}

__attribute__((deprecated)) ppbc_power_sequence_t *ppbc_power_sequence_create(
    char *id,
    list_t *elements,
    int *is_interruptible,
    int *max_pause_before,
    int *abnormal_condition_only
    ) {
    int *is_interruptible_copy = NULL;
    if (is_interruptible) {
        is_interruptible_copy = malloc(sizeof(int));
        if (is_interruptible_copy) *is_interruptible_copy = *is_interruptible;
    }
    int *max_pause_before_copy = NULL;
    if (max_pause_before) {
        max_pause_before_copy = malloc(sizeof(int));
        if (max_pause_before_copy) *max_pause_before_copy = *max_pause_before;
    }
    int *abnormal_condition_only_copy = NULL;
    if (abnormal_condition_only) {
        abnormal_condition_only_copy = malloc(sizeof(int));
        if (abnormal_condition_only_copy) *abnormal_condition_only_copy = *abnormal_condition_only;
    }
    ppbc_power_sequence_t *result = ppbc_power_sequence_create_internal (
        id,
        elements,
        is_interruptible_copy,
        max_pause_before_copy,
        abnormal_condition_only_copy
        );
    if (!result) {
        free(is_interruptible_copy);
        free(max_pause_before_copy);
        free(abnormal_condition_only_copy);
    }
    return result;
}

void ppbc_power_sequence_free(ppbc_power_sequence_t *ppbc_power_sequence) {
    if(NULL == ppbc_power_sequence){
        return ;
    }
    if(ppbc_power_sequence->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_sequence_free");
        return ;
    }
    if (ppbc_power_sequence->id) {
        free(ppbc_power_sequence->id);
        ppbc_power_sequence->id = NULL;
    }
    if (ppbc_power_sequence->elements) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ppbc_power_sequence->elements) {
            ppbc_power_sequence_element_free(listEntry->data);
        }
        list_freeList(ppbc_power_sequence->elements);
        ppbc_power_sequence->elements = NULL;
    }
    if (ppbc_power_sequence->is_interruptible) {
        free(ppbc_power_sequence->is_interruptible);
        ppbc_power_sequence->is_interruptible = NULL;
    }
    if (ppbc_power_sequence->max_pause_before) {
        free(ppbc_power_sequence->max_pause_before);
        ppbc_power_sequence->max_pause_before = NULL;
    }
    if (ppbc_power_sequence->abnormal_condition_only) {
        free(ppbc_power_sequence->abnormal_condition_only);
        ppbc_power_sequence->abnormal_condition_only = NULL;
    }
    free(ppbc_power_sequence);
}

cJSON *ppbc_power_sequence_convertToJSON(ppbc_power_sequence_t *ppbc_power_sequence) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_sequence->id
    if (!ppbc_power_sequence->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ppbc_power_sequence->id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_sequence->elements
    if (!ppbc_power_sequence->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (ppbc_power_sequence->elements) {
    list_ForEach(elementsListEntry, ppbc_power_sequence->elements) {
    cJSON *itemLocal = ppbc_power_sequence_element_convertToJSON(elementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(elements, itemLocal);
    }
    }


    // ppbc_power_sequence->is_interruptible
    if (!ppbc_power_sequence->is_interruptible) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_interruptible", *ppbc_power_sequence->is_interruptible) == NULL) {
    goto fail; //Bool
    }


    // ppbc_power_sequence->max_pause_before
    if(ppbc_power_sequence->max_pause_before) {
    if(cJSON_AddNumberToObject(item, "max_pause_before", *ppbc_power_sequence->max_pause_before) == NULL) {
    goto fail; //Numeric
    }
    }


    // ppbc_power_sequence->abnormal_condition_only
    if (!ppbc_power_sequence->abnormal_condition_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition_only", *ppbc_power_sequence->abnormal_condition_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_power_sequence_t *ppbc_power_sequence_parseFromJSON(cJSON *ppbc_power_sequenceJSON){

    ppbc_power_sequence_t *ppbc_power_sequence_local_var = NULL;

    char *id_local_str = NULL;

    // define the local list for ppbc_power_sequence->elements
    list_t *elementsList = NULL;

    // define the local variable for ppbc_power_sequence->is_interruptible
    int *is_interruptible_local_var = NULL;

    // define the local variable for ppbc_power_sequence->max_pause_before
    int *max_pause_before_local_var = NULL;

    // define the local variable for ppbc_power_sequence->abnormal_condition_only
    int *abnormal_condition_only_local_var = NULL;

    // ppbc_power_sequence->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequenceJSON, "id");
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

    // ppbc_power_sequence->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequenceJSON, "elements");
    if (cJSON_IsNull(elements)) {
        elements = NULL;
    }
    if (!elements) {
        goto end;
    }

    
    cJSON *elements_local_nonprimitive = NULL;
    if(!cJSON_IsArray(elements)){
        goto end; //nonprimitive container
    }

    elementsList = list_createList();

    cJSON_ArrayForEach(elements_local_nonprimitive,elements )
    {
        if(!cJSON_IsObject(elements_local_nonprimitive)){
            goto end;
        }
        ppbc_power_sequence_element_t *elementsItem = ppbc_power_sequence_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }

    // ppbc_power_sequence->is_interruptible
    cJSON *is_interruptible = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequenceJSON, "is_interruptible");
    if (cJSON_IsNull(is_interruptible)) {
        is_interruptible = NULL;
    }
    if (!is_interruptible) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_interruptible))
    {
    goto end; //Bool
    }
    is_interruptible_local_var = malloc(sizeof(int));
    if(!is_interruptible_local_var)
    {
        goto end;
    }
    *is_interruptible_local_var = is_interruptible->valueint;

    // ppbc_power_sequence->max_pause_before
    cJSON *max_pause_before = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequenceJSON, "max_pause_before");
    if (cJSON_IsNull(max_pause_before)) {
        max_pause_before = NULL;
    }
    if (max_pause_before) { 
    if(!cJSON_IsNumber(max_pause_before))
    {
    goto end; //Numeric
    }
    max_pause_before_local_var = malloc(sizeof(int));
    if(!max_pause_before_local_var)
    {
        goto end;
    }
    *max_pause_before_local_var = max_pause_before->valuedouble;
    }

    // ppbc_power_sequence->abnormal_condition_only
    cJSON *abnormal_condition_only = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequenceJSON, "abnormal_condition_only");
    if (cJSON_IsNull(abnormal_condition_only)) {
        abnormal_condition_only = NULL;
    }
    if (!abnormal_condition_only) {
        goto end;
    }

    
    if(!cJSON_IsBool(abnormal_condition_only))
    {
    goto end; //Bool
    }
    abnormal_condition_only_local_var = malloc(sizeof(int));
    if(!abnormal_condition_only_local_var)
    {
        goto end;
    }
    *abnormal_condition_only_local_var = abnormal_condition_only->valueint;


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);

    ppbc_power_sequence_local_var = ppbc_power_sequence_create_internal (
        id_local_str,
        elementsList,
        is_interruptible_local_var,
        max_pause_before_local_var,
        abnormal_condition_only_local_var
        );

    if (!ppbc_power_sequence_local_var) {
        goto end;
    }

    return ppbc_power_sequence_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (elementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, elementsList) {
            ppbc_power_sequence_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    if (is_interruptible_local_var) {
        free(is_interruptible_local_var);
        is_interruptible_local_var = NULL;
    }
    if (max_pause_before_local_var) {
        free(max_pause_before_local_var);
        max_pause_before_local_var = NULL;
    }
    if (abnormal_condition_only_local_var) {
        free(abnormal_condition_only_local_var);
        abnormal_condition_only_local_var = NULL;
    }
    return NULL;

}
