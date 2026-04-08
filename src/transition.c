#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/transition.h>



static transition_t *transition_create_internal(
    char *id,
    char *from,
    char *to,
    list_t *start_timers,
    list_t *blocking_timers,
    double *transition_costs,
    int *transition_duration,
    int *abnormal_condition_only
    ) {
    transition_t *transition_local_var = malloc(sizeof(transition_t));
    if (!transition_local_var) {
        return NULL;
    }
    memset(transition_local_var, 0, sizeof(transition_t));
    transition_local_var->_library_owned = 1;
    transition_local_var->id = id;
    transition_local_var->from = from;
    transition_local_var->to = to;
    transition_local_var->start_timers = start_timers;
    transition_local_var->blocking_timers = blocking_timers;
    transition_local_var->transition_costs = transition_costs;
    transition_local_var->transition_duration = transition_duration;
    transition_local_var->abnormal_condition_only = abnormal_condition_only;
    return transition_local_var;
}

__attribute__((deprecated)) transition_t *transition_create(
    char *id,
    char *from,
    char *to,
    list_t *start_timers,
    list_t *blocking_timers,
    double *transition_costs,
    int *transition_duration,
    int *abnormal_condition_only
    ) {
    double *transition_costs_copy = NULL;
    if (transition_costs) {
        transition_costs_copy = malloc(sizeof(double));
        if (transition_costs_copy) *transition_costs_copy = *transition_costs;
    }
    int *transition_duration_copy = NULL;
    if (transition_duration) {
        transition_duration_copy = malloc(sizeof(int));
        if (transition_duration_copy) *transition_duration_copy = *transition_duration;
    }
    int *abnormal_condition_only_copy = NULL;
    if (abnormal_condition_only) {
        abnormal_condition_only_copy = malloc(sizeof(int));
        if (abnormal_condition_only_copy) *abnormal_condition_only_copy = *abnormal_condition_only;
    }
    transition_t *result = transition_create_internal (
        id,
        from,
        to,
        start_timers,
        blocking_timers,
        transition_costs_copy,
        transition_duration_copy,
        abnormal_condition_only_copy
        );
    if (!result) {
        free(transition_costs_copy);
        free(transition_duration_copy);
        free(abnormal_condition_only_copy);
    }
    return result;
}

void transition_free(transition_t *transition) {
    if(NULL == transition){
        return ;
    }
    if(transition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transition->id) {
        free(transition->id);
        transition->id = NULL;
    }
    if (transition->from) {
        free(transition->from);
        transition->from = NULL;
    }
    if (transition->to) {
        free(transition->to);
        transition->to = NULL;
    }
    if (transition->start_timers) {
        list_ForEach(listEntry, transition->start_timers) {
            free(listEntry->data);
        }
        list_freeList(transition->start_timers);
        transition->start_timers = NULL;
    }
    if (transition->blocking_timers) {
        list_ForEach(listEntry, transition->blocking_timers) {
            free(listEntry->data);
        }
        list_freeList(transition->blocking_timers);
        transition->blocking_timers = NULL;
    }
    if (transition->transition_costs) {
        free(transition->transition_costs);
        transition->transition_costs = NULL;
    }
    if (transition->transition_duration) {
        free(transition->transition_duration);
        transition->transition_duration = NULL;
    }
    if (transition->abnormal_condition_only) {
        free(transition->abnormal_condition_only);
        transition->abnormal_condition_only = NULL;
    }
    free(transition);
}

cJSON *transition_convertToJSON(transition_t *transition) {
    cJSON *item = cJSON_CreateObject();

    // transition->id
    if (!transition->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", transition->id) == NULL) {
    goto fail; //String
    }


    // transition->from
    if (!transition->from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "from", transition->from) == NULL) {
    goto fail; //String
    }


    // transition->to
    if (!transition->to) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "to", transition->to) == NULL) {
    goto fail; //String
    }


    // transition->start_timers
    if (!transition->start_timers) {
        goto fail;
    }
    cJSON *start_timers = cJSON_AddArrayToObject(item, "start_timers");
    if(start_timers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *start_timersListEntry;
    list_ForEach(start_timersListEntry, transition->start_timers) {
    if(cJSON_AddStringToObject(start_timers, "", start_timersListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // transition->blocking_timers
    if (!transition->blocking_timers) {
        goto fail;
    }
    cJSON *blocking_timers = cJSON_AddArrayToObject(item, "blocking_timers");
    if(blocking_timers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *blocking_timersListEntry;
    list_ForEach(blocking_timersListEntry, transition->blocking_timers) {
    if(cJSON_AddStringToObject(blocking_timers, "", blocking_timersListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // transition->transition_costs
    if(transition->transition_costs) {
    if(cJSON_AddNumberToObject(item, "transition_costs", *transition->transition_costs) == NULL) {
    goto fail; //Numeric
    }
    }


    // transition->transition_duration
    if(transition->transition_duration) {
    if(cJSON_AddNumberToObject(item, "transition_duration", *transition->transition_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // transition->abnormal_condition_only
    if (!transition->abnormal_condition_only) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "abnormal_condition_only", *transition->abnormal_condition_only) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transition_t *transition_parseFromJSON(cJSON *transitionJSON){

    transition_t *transition_local_var = NULL;

    char *id_local_str = NULL;

    char *from_local_str = NULL;

    char *to_local_str = NULL;

    // define the local list for transition->start_timers
    list_t *start_timersList = NULL;

    // define the local list for transition->blocking_timers
    list_t *blocking_timersList = NULL;

    // define the local variable for transition->transition_costs
    double *transition_costs_local_var = NULL;

    // define the local variable for transition->transition_duration
    int *transition_duration_local_var = NULL;

    // define the local variable for transition->abnormal_condition_only
    int *abnormal_condition_only_local_var = NULL;

    // transition->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(transitionJSON, "id");
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

    // transition->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(transitionJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    if(!cJSON_IsString(from))
    {
    goto end; //String
    }

    // transition->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(transitionJSON, "to");
    if (cJSON_IsNull(to)) {
        to = NULL;
    }
    if (!to) {
        goto end;
    }

    
    if(!cJSON_IsString(to))
    {
    goto end; //String
    }

    // transition->start_timers
    cJSON *start_timers = cJSON_GetObjectItemCaseSensitive(transitionJSON, "start_timers");
    if (cJSON_IsNull(start_timers)) {
        start_timers = NULL;
    }
    if (!start_timers) {
        goto end;
    }

    
    cJSON *start_timers_local = NULL;
    if(!cJSON_IsArray(start_timers)) {
        goto end;//primitive container
    }
    start_timersList = list_createList();

    cJSON_ArrayForEach(start_timers_local, start_timers)
    {
        if(!cJSON_IsString(start_timers_local))
        {
            goto end;
        }
        list_addElement(start_timersList , strdup(start_timers_local->valuestring));
    }

    // transition->blocking_timers
    cJSON *blocking_timers = cJSON_GetObjectItemCaseSensitive(transitionJSON, "blocking_timers");
    if (cJSON_IsNull(blocking_timers)) {
        blocking_timers = NULL;
    }
    if (!blocking_timers) {
        goto end;
    }

    
    cJSON *blocking_timers_local = NULL;
    if(!cJSON_IsArray(blocking_timers)) {
        goto end;//primitive container
    }
    blocking_timersList = list_createList();

    cJSON_ArrayForEach(blocking_timers_local, blocking_timers)
    {
        if(!cJSON_IsString(blocking_timers_local))
        {
            goto end;
        }
        list_addElement(blocking_timersList , strdup(blocking_timers_local->valuestring));
    }

    // transition->transition_costs
    cJSON *transition_costs = cJSON_GetObjectItemCaseSensitive(transitionJSON, "transition_costs");
    if (cJSON_IsNull(transition_costs)) {
        transition_costs = NULL;
    }
    if (transition_costs) { 
    if(!cJSON_IsNumber(transition_costs))
    {
    goto end; //Numeric
    }
    transition_costs_local_var = malloc(sizeof(double));
    if(!transition_costs_local_var)
    {
        goto end;
    }
    *transition_costs_local_var = transition_costs->valuedouble;
    }

    // transition->transition_duration
    cJSON *transition_duration = cJSON_GetObjectItemCaseSensitive(transitionJSON, "transition_duration");
    if (cJSON_IsNull(transition_duration)) {
        transition_duration = NULL;
    }
    if (transition_duration) { 
    if(!cJSON_IsNumber(transition_duration))
    {
    goto end; //Numeric
    }
    transition_duration_local_var = malloc(sizeof(int));
    if(!transition_duration_local_var)
    {
        goto end;
    }
    *transition_duration_local_var = transition_duration->valuedouble;
    }

    // transition->abnormal_condition_only
    cJSON *abnormal_condition_only = cJSON_GetObjectItemCaseSensitive(transitionJSON, "abnormal_condition_only");
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
    if (from && !cJSON_IsNull(from)) from_local_str = strdup(from->valuestring);
    if (to && !cJSON_IsNull(to)) to_local_str = strdup(to->valuestring);

    transition_local_var = transition_create_internal (
        id_local_str,
        from_local_str,
        to_local_str,
        start_timersList,
        blocking_timersList,
        transition_costs_local_var,
        transition_duration_local_var,
        abnormal_condition_only_local_var
        );

    if (!transition_local_var) {
        goto end;
    }

    return transition_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (from_local_str) {
        free(from_local_str);
        from_local_str = NULL;
    }
    if (to_local_str) {
        free(to_local_str);
        to_local_str = NULL;
    }
    if (start_timersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, start_timersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(start_timersList);
        start_timersList = NULL;
    }
    if (blocking_timersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, blocking_timersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(blocking_timersList);
        blocking_timersList = NULL;
    }
    if (transition_costs_local_var) {
        free(transition_costs_local_var);
        transition_costs_local_var = NULL;
    }
    if (transition_duration_local_var) {
        free(transition_duration_local_var);
        transition_duration_local_var = NULL;
    }
    if (abnormal_condition_only_local_var) {
        free(abnormal_condition_only_local_var);
        abnormal_condition_only_local_var = NULL;
    }
    return NULL;

}
