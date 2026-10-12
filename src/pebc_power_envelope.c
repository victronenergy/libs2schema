#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_power_envelope.h>



static pebc_power_envelope_t *pebc_power_envelope_create_internal(
    char *id,
    s2_commodity_quantity__e commodity_quantity,
    list_t *power_envelope_elements
    ) {
    pebc_power_envelope_t *pebc_power_envelope_local_var = malloc(sizeof(pebc_power_envelope_t));
    if (!pebc_power_envelope_local_var) {
        return NULL;
    }
    memset(pebc_power_envelope_local_var, 0, sizeof(pebc_power_envelope_t));
    pebc_power_envelope_local_var->_library_owned = 1;
    pebc_power_envelope_local_var->id = id;
    pebc_power_envelope_local_var->commodity_quantity = commodity_quantity;
    pebc_power_envelope_local_var->power_envelope_elements = power_envelope_elements;
    return pebc_power_envelope_local_var;
}

__attribute__((deprecated)) pebc_power_envelope_t *pebc_power_envelope_create(
    char *id,
    s2_commodity_quantity__e commodity_quantity,
    list_t *power_envelope_elements
    ) {
    pebc_power_envelope_t *result = pebc_power_envelope_create_internal (
        id,
        commodity_quantity,
        power_envelope_elements
        );
    if (!result) {
    }
    return result;
}

void pebc_power_envelope_free(pebc_power_envelope_t *pebc_power_envelope) {
    if(NULL == pebc_power_envelope){
        return ;
    }
    if(pebc_power_envelope->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_power_envelope_free");
        return ;
    }
    if (pebc_power_envelope->id) {
        free(pebc_power_envelope->id);
        pebc_power_envelope->id = NULL;
    }
    if (pebc_power_envelope->power_envelope_elements) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, pebc_power_envelope->power_envelope_elements) {
            pebc_power_envelope_element_free(listEntry->data);
        }
        list_freeList(pebc_power_envelope->power_envelope_elements);
        pebc_power_envelope->power_envelope_elements = NULL;
    }
    free(pebc_power_envelope);
}

cJSON *pebc_power_envelope_convertToJSON(pebc_power_envelope_t *pebc_power_envelope) {
    cJSON *item = cJSON_CreateObject();

    // pebc_power_envelope->id
    if (!pebc_power_envelope->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", pebc_power_envelope->id) == NULL) {
    goto fail; //String
    }


    // pebc_power_envelope->commodity_quantity
    if (s2_commodity_quantity__NULL == pebc_power_envelope->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(pebc_power_envelope->commodity_quantity);
    if(commodity_quantity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity_quantity", commodity_quantity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // pebc_power_envelope->power_envelope_elements
    if (!pebc_power_envelope->power_envelope_elements) {
        goto fail;
    }
    cJSON *power_envelope_elements = cJSON_AddArrayToObject(item, "power_envelope_elements");
    if(power_envelope_elements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_envelope_elementsListEntry;
    if (pebc_power_envelope->power_envelope_elements) {
    list_ForEach(power_envelope_elementsListEntry, pebc_power_envelope->power_envelope_elements) {
    cJSON *itemLocal = pebc_power_envelope_element_convertToJSON(power_envelope_elementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_envelope_elements, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_power_envelope_t *pebc_power_envelope_parseFromJSON(cJSON *pebc_power_envelopeJSON){

    pebc_power_envelope_t *pebc_power_envelope_local_var = NULL;

    char *id_local_str = NULL;

    // define the local variable for pebc_power_envelope->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // define the local list for pebc_power_envelope->power_envelope_elements
    list_t *power_envelope_elementsList = NULL;

    // pebc_power_envelope->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pebc_power_envelopeJSON, "id");
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

    // pebc_power_envelope->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(pebc_power_envelopeJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom

    // pebc_power_envelope->power_envelope_elements
    cJSON *power_envelope_elements = cJSON_GetObjectItemCaseSensitive(pebc_power_envelopeJSON, "power_envelope_elements");
    if (cJSON_IsNull(power_envelope_elements)) {
        power_envelope_elements = NULL;
    }
    if (!power_envelope_elements) {
        goto end;
    }

    
    cJSON *power_envelope_elements_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_envelope_elements)){
        goto end; //nonprimitive container
    }

    power_envelope_elementsList = list_createList();

    cJSON_ArrayForEach(power_envelope_elements_local_nonprimitive,power_envelope_elements )
    {
        if(!cJSON_IsObject(power_envelope_elements_local_nonprimitive)){
            goto end;
        }
        pebc_power_envelope_element_t *power_envelope_elementsItem = pebc_power_envelope_element_parseFromJSON(power_envelope_elements_local_nonprimitive);

        list_addElement(power_envelope_elementsList, power_envelope_elementsItem);
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);

    pebc_power_envelope_local_var = pebc_power_envelope_create_internal (
        id_local_str,
        commodity_quantity_local_nonprim,
        power_envelope_elementsList
        );

    if (!pebc_power_envelope_local_var) {
        goto end;
    }

    return pebc_power_envelope_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    if (power_envelope_elementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_envelope_elementsList) {
            pebc_power_envelope_element_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_envelope_elementsList);
        power_envelope_elementsList = NULL;
    }
    return NULL;

}
