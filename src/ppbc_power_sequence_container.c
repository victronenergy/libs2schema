#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/ppbc_power_sequence_container.h>



static ppbc_power_sequence_container_t *ppbc_power_sequence_container_create_internal(
    char *id,
    list_t *power_sequences
    ) {
    ppbc_power_sequence_container_t *ppbc_power_sequence_container_local_var = malloc(sizeof(ppbc_power_sequence_container_t));
    if (!ppbc_power_sequence_container_local_var) {
        return NULL;
    }
    memset(ppbc_power_sequence_container_local_var, 0, sizeof(ppbc_power_sequence_container_t));
    ppbc_power_sequence_container_local_var->_library_owned = 1;
    ppbc_power_sequence_container_local_var->id = id;
    ppbc_power_sequence_container_local_var->power_sequences = power_sequences;
    return ppbc_power_sequence_container_local_var;
}

__attribute__((deprecated)) ppbc_power_sequence_container_t *ppbc_power_sequence_container_create(
    char *id,
    list_t *power_sequences
    ) {
    ppbc_power_sequence_container_t *result = ppbc_power_sequence_container_create_internal (
        id,
        power_sequences
        );
    if (!result) {
    }
    return result;
}

void ppbc_power_sequence_container_free(ppbc_power_sequence_container_t *ppbc_power_sequence_container) {
    if(NULL == ppbc_power_sequence_container){
        return ;
    }
    if(ppbc_power_sequence_container->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ppbc_power_sequence_container_free");
        return ;
    }
    if (ppbc_power_sequence_container->id) {
        free(ppbc_power_sequence_container->id);
        ppbc_power_sequence_container->id = NULL;
    }
    if (ppbc_power_sequence_container->power_sequences) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, ppbc_power_sequence_container->power_sequences) {
            ppbc_power_sequence_free(listEntry->data);
        }
        list_freeList(ppbc_power_sequence_container->power_sequences);
        ppbc_power_sequence_container->power_sequences = NULL;
    }
    free(ppbc_power_sequence_container);
}

cJSON *ppbc_power_sequence_container_convertToJSON(ppbc_power_sequence_container_t *ppbc_power_sequence_container) {
    cJSON *item = cJSON_CreateObject();

    // ppbc_power_sequence_container->id
    if (!ppbc_power_sequence_container->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ppbc_power_sequence_container->id) == NULL) {
    goto fail; //String
    }


    // ppbc_power_sequence_container->power_sequences
    if (!ppbc_power_sequence_container->power_sequences) {
        goto fail;
    }
    cJSON *power_sequences = cJSON_AddArrayToObject(item, "power_sequences");
    if(power_sequences == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *power_sequencesListEntry;
    if (ppbc_power_sequence_container->power_sequences) {
    list_ForEach(power_sequencesListEntry, ppbc_power_sequence_container->power_sequences) {
    cJSON *itemLocal = ppbc_power_sequence_convertToJSON(power_sequencesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(power_sequences, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ppbc_power_sequence_container_t *ppbc_power_sequence_container_parseFromJSON(cJSON *ppbc_power_sequence_containerJSON){

    ppbc_power_sequence_container_t *ppbc_power_sequence_container_local_var = NULL;

    char *id_local_str = NULL;

    // define the local list for ppbc_power_sequence_container->power_sequences
    list_t *power_sequencesList = NULL;

    // ppbc_power_sequence_container->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_containerJSON, "id");
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

    // ppbc_power_sequence_container->power_sequences
    cJSON *power_sequences = cJSON_GetObjectItemCaseSensitive(ppbc_power_sequence_containerJSON, "power_sequences");
    if (cJSON_IsNull(power_sequences)) {
        power_sequences = NULL;
    }
    if (!power_sequences) {
        goto end;
    }

    
    cJSON *power_sequences_local_nonprimitive = NULL;
    if(!cJSON_IsArray(power_sequences)){
        goto end; //nonprimitive container
    }

    power_sequencesList = list_createList();

    cJSON_ArrayForEach(power_sequences_local_nonprimitive,power_sequences )
    {
        if(!cJSON_IsObject(power_sequences_local_nonprimitive)){
            goto end;
        }
        ppbc_power_sequence_t *power_sequencesItem = ppbc_power_sequence_parseFromJSON(power_sequences_local_nonprimitive);

        list_addElement(power_sequencesList, power_sequencesItem);
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);

    ppbc_power_sequence_container_local_var = ppbc_power_sequence_container_create_internal (
        id_local_str,
        power_sequencesList
        );

    if (!ppbc_power_sequence_container_local_var) {
        goto end;
    }

    return ppbc_power_sequence_container_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (power_sequencesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, power_sequencesList) {
            ppbc_power_sequence_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(power_sequencesList);
        power_sequencesList = NULL;
    }
    return NULL;

}
