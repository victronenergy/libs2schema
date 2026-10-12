#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/power_measurement.h>



static power_measurement_t *power_measurement_create_internal(
    char *message_type,
    char *message_id,
    char *measurement_timestamp,
    list_t *values
    ) {
    power_measurement_t *power_measurement_local_var = malloc(sizeof(power_measurement_t));
    if (!power_measurement_local_var) {
        return NULL;
    }
    memset(power_measurement_local_var, 0, sizeof(power_measurement_t));
    power_measurement_local_var->_library_owned = 1;
    power_measurement_local_var->message_type = message_type;
    power_measurement_local_var->message_id = message_id;
    power_measurement_local_var->measurement_timestamp = measurement_timestamp;
    power_measurement_local_var->values = values;
    return power_measurement_local_var;
}

__attribute__((deprecated)) power_measurement_t *power_measurement_create(
    char *message_type,
    char *message_id,
    char *measurement_timestamp,
    list_t *values
    ) {
    power_measurement_t *result = power_measurement_create_internal (
        message_type,
        message_id,
        measurement_timestamp,
        values
        );
    if (!result) {
    }
    return result;
}

void power_measurement_free(power_measurement_t *power_measurement) {
    if(NULL == power_measurement){
        return ;
    }
    if(power_measurement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "power_measurement_free");
        return ;
    }
    if (power_measurement->message_type) {
        free(power_measurement->message_type);
        power_measurement->message_type = NULL;
    }
    if (power_measurement->message_id) {
        free(power_measurement->message_id);
        power_measurement->message_id = NULL;
    }
    if (power_measurement->measurement_timestamp) {
        free(power_measurement->measurement_timestamp);
        power_measurement->measurement_timestamp = NULL;
    }
    if (power_measurement->values) {
        listEntry_t *listEntry;
        list_ForEach(listEntry, power_measurement->values) {
            power_value_free(listEntry->data);
        }
        list_freeList(power_measurement->values);
        power_measurement->values = NULL;
    }
    free(power_measurement);
}

cJSON *power_measurement_convertToJSON(power_measurement_t *power_measurement) {
    cJSON *item = cJSON_CreateObject();

    // power_measurement->message_type
    if (!power_measurement->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", power_measurement->message_type) == NULL) {
    goto fail; //String
    }


    // power_measurement->message_id
    if (!power_measurement->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", power_measurement->message_id) == NULL) {
    goto fail; //String
    }


    // power_measurement->measurement_timestamp
    if (!power_measurement->measurement_timestamp) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "measurement_timestamp", power_measurement->measurement_timestamp) == NULL) {
    goto fail; //Date-Time
    }


    // power_measurement->values
    if (!power_measurement->values) {
        goto fail;
    }
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *valuesListEntry;
    if (power_measurement->values) {
    list_ForEach(valuesListEntry, power_measurement->values) {
    cJSON *itemLocal = power_value_convertToJSON(valuesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(values, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

power_measurement_t *power_measurement_parseFromJSON(cJSON *power_measurementJSON){

    power_measurement_t *power_measurement_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *measurement_timestamp_local_str = NULL;

    // define the local list for power_measurement->values
    list_t *valuesList = NULL;

    // power_measurement->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(power_measurementJSON, "message_type");
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

    // power_measurement->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(power_measurementJSON, "message_id");
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

    // power_measurement->measurement_timestamp
    cJSON *measurement_timestamp = cJSON_GetObjectItemCaseSensitive(power_measurementJSON, "measurement_timestamp");
    if (cJSON_IsNull(measurement_timestamp)) {
        measurement_timestamp = NULL;
    }
    if (!measurement_timestamp) {
        goto end;
    }

    
    if(!cJSON_IsString(measurement_timestamp) && !cJSON_IsNull(measurement_timestamp))
    {
    goto end; //DateTime
    }

    // power_measurement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(power_measurementJSON, "values");
    if (cJSON_IsNull(values)) {
        values = NULL;
    }
    if (!values) {
        goto end;
    }

    
    cJSON *values_local_nonprimitive = NULL;
    if(!cJSON_IsArray(values)){
        goto end; //nonprimitive container
    }

    valuesList = list_createList();

    cJSON_ArrayForEach(values_local_nonprimitive,values )
    {
        if(!cJSON_IsObject(values_local_nonprimitive)){
            goto end;
        }
        power_value_t *valuesItem = power_value_parseFromJSON(values_local_nonprimitive);

        list_addElement(valuesList, valuesItem);
    }


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (measurement_timestamp && !cJSON_IsNull(measurement_timestamp)) measurement_timestamp_local_str = strdup(measurement_timestamp->valuestring);

    power_measurement_local_var = power_measurement_create_internal (
        message_type_local_str,
        message_id_local_str,
        measurement_timestamp_local_str,
        valuesList
        );

    if (!power_measurement_local_var) {
        goto end;
    }

    return power_measurement_local_var;
end:
    if (message_type_local_str) {
        free(message_type_local_str);
        message_type_local_str = NULL;
    }
    if (message_id_local_str) {
        free(message_id_local_str);
        message_id_local_str = NULL;
    }
    if (measurement_timestamp_local_str) {
        free(measurement_timestamp_local_str);
        measurement_timestamp_local_str = NULL;
    }
    if (valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valuesList) {
            power_value_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valuesList);
        valuesList = NULL;
    }
    return NULL;

}
