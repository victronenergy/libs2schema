#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/frbc_operation_mode.h>



static frbc_operation_mode_t *frbc_operation_mode_create_internal(
    char *id,
    char *diagnostic_label,
    list_t *elements,
    int *abnormal_condition_only
    ) {
    frbc_operation_mode_t *frbc_operation_mode_local_var = malloc(sizeof(frbc_operation_mode_t));
    if (!frbc_operation_mode_local_var) {
        return NULL;
    }
    memset(frbc_operation_mode_local_var, 0, sizeof(frbc_operation_mode_t));
    frbc_operation_mode_local_var->_library_owned = 1;
    frbc_operation_mode_local_var->id = id;
    frbc_operation_mode_local_var->diagnostic_label = diagnostic_label;
    frbc_operation_mode_local_var->elements = elements;
    frbc_operation_mode_local_var->abnormal_condition_only = abnormal_condition_only;
    return frbc_operation_mode_local_var;
}

__attribute__((deprecated)) frbc_operation_mode_t *frbc_operation_mode_create(
    char *id,
    char *diagnostic_label,
    list_t *elements,
    int *abnormal_condition_only
    ) {
    int *abnormal_condition_only_copy = NULL;
    if (abnormal_condition_only) {
        abnormal_condition_only_copy = malloc(sizeof(int));
        if (abnormal_condition_only_copy) *abnormal_condition_only_copy = *abnormal_condition_only;
    }
    frbc_operation_mode_t *result = frbc_operation_mode_create_internal (
        id,
        diagnostic_label,
        elements,
        abnormal_condition_only_copy
        );
    if (!result) {
        free(abnormal_condition_only_copy);
    }
    return result;
}

void frbc_operation_mode_free(frbc_operation_mode_t *frbc_operation_mode) {
    if(NULL == frbc_operation_mode){
        return ;
    }
    if(frbc_operation_mode->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "frbc_operation_mode_free");
        return ;
    }
    listEntry_t *listEntry;
    if (frbc_operation_mode->id) {
        free(frbc_operation_mode->id);
        frbc_operation_mode->id = NULL;
    }
    if (frbc_operation_mode->diagnostic_label) {
        free(frbc_operation_mode->diagnostic_label);
        frbc_operation_mode->diagnostic_label = NULL;
    }
    if (frbc_operation_mode->elements) {
        list_ForEach(listEntry, frbc_operation_mode->elements) {
            frbc_operation_mode_element_free(listEntry->data);
        }
        list_freeList(frbc_operation_mode->elements);
        frbc_operation_mode->elements = NULL;
    }
    if (frbc_operation_mode->abnormal_condition_only) {
        free(frbc_operation_mode->abnormal_condition_only);
        frbc_operation_mode->abnormal_condition_only = NULL;
    }
    free(frbc_operation_mode);
}

cJSON *frbc_operation_mode_convertToJSON(frbc_operation_mode_t *frbc_operation_mode) {
    cJSON *item = cJSON_CreateObject();

    // frbc_operation_mode->id
    if (!frbc_operation_mode->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", frbc_operation_mode->id) == NULL) {
    goto fail; //String
    }


    // frbc_operation_mode->diagnostic_label
    if(frbc_operation_mode->diagnostic_label) {
    if(cJSON_AddStringToObject(item, "diagnostic_label", frbc_operation_mode->diagnostic_label) == NULL) {
    goto fail; //String
    }
    }


    // frbc_operation_mode->elements
    if (!frbc_operation_mode->elements) {
        goto fail;
    }
    cJSON *elements = cJSON_AddArrayToObject(item, "elements");
    if(elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *elementsListEntry;
    if (frbc_operation_mode->elements) {
    list_ForEach(elementsListEntry, frbc_operation_mode->elements) {
    cJSON *itemLocal = frbc_operation_mode_element_convertToJSON(elementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(elements, itemLocal);
    }
    }


    // frbc_operation_mode->abnormal_condition_only
    if (!frbc_operation_mode->abnormal_condition_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition_only", *frbc_operation_mode->abnormal_condition_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

frbc_operation_mode_t *frbc_operation_mode_parseFromJSON(cJSON *frbc_operation_modeJSON){

    frbc_operation_mode_t *frbc_operation_mode_local_var = NULL;

    char *id_local_str = NULL;

    char *diagnostic_label_local_str = NULL;

    // define the local list for frbc_operation_mode->elements
    list_t *elementsList = NULL;

    // define the local variable for frbc_operation_mode->abnormal_condition_only
    int *abnormal_condition_only_local_var = NULL;

    // frbc_operation_mode->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(frbc_operation_modeJSON, "id");
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

    // frbc_operation_mode->diagnostic_label
    cJSON *diagnostic_label = cJSON_GetObjectItemCaseSensitive(frbc_operation_modeJSON, "diagnostic_label");
    if (cJSON_IsNull(diagnostic_label)) {
        diagnostic_label = NULL;
    }
    if (diagnostic_label) { 
    if(!cJSON_IsString(diagnostic_label) && !cJSON_IsNull(diagnostic_label))
    {
    goto end; //String
    }
    }

    // frbc_operation_mode->elements
    cJSON *elements = cJSON_GetObjectItemCaseSensitive(frbc_operation_modeJSON, "elements");
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
        frbc_operation_mode_element_t *elementsItem = frbc_operation_mode_element_parseFromJSON(elements_local_nonprimitive);

        list_addElement(elementsList, elementsItem);
    }

    // frbc_operation_mode->abnormal_condition_only
    cJSON *abnormal_condition_only = cJSON_GetObjectItemCaseSensitive(frbc_operation_modeJSON, "abnormal_condition_only");
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
    if (diagnostic_label && !cJSON_IsNull(diagnostic_label)) diagnostic_label_local_str = strdup(diagnostic_label->valuestring);

    frbc_operation_mode_local_var = frbc_operation_mode_create_internal (
        id_local_str,
        diagnostic_label_local_str,
        elementsList,
        abnormal_condition_only_local_var
        );

    if (!frbc_operation_mode_local_var) {
        goto end;
    }

    return frbc_operation_mode_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (diagnostic_label_local_str) {
        free(diagnostic_label_local_str);
        diagnostic_label_local_str = NULL;
    }
    if (elementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, elementsList) {
            frbc_operation_mode_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(elementsList);
        elementsList = NULL;
    }
    if (abnormal_condition_only_local_var) {
        free(abnormal_condition_only_local_var);
        abnormal_condition_only_local_var = NULL;
    }
    return NULL;

}
