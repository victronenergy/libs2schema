#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/pebc_energy_constraint.h>



static pebc_energy_constraint_t *pebc_energy_constraint_create_internal(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    double *upper_average_power,
    double *lower_average_power,
    s2_commodity_quantity__e commodity_quantity
    ) {
    pebc_energy_constraint_t *pebc_energy_constraint_local_var = malloc(sizeof(pebc_energy_constraint_t));
    if (!pebc_energy_constraint_local_var) {
        return NULL;
    }
    memset(pebc_energy_constraint_local_var, 0, sizeof(pebc_energy_constraint_t));
    pebc_energy_constraint_local_var->_library_owned = 1;
    pebc_energy_constraint_local_var->message_type = message_type;
    pebc_energy_constraint_local_var->message_id = message_id;
    pebc_energy_constraint_local_var->id = id;
    pebc_energy_constraint_local_var->valid_from = valid_from;
    pebc_energy_constraint_local_var->valid_until = valid_until;
    pebc_energy_constraint_local_var->upper_average_power = upper_average_power;
    pebc_energy_constraint_local_var->lower_average_power = lower_average_power;
    pebc_energy_constraint_local_var->commodity_quantity = commodity_quantity;
    return pebc_energy_constraint_local_var;
}

__attribute__((deprecated)) pebc_energy_constraint_t *pebc_energy_constraint_create(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    double *upper_average_power,
    double *lower_average_power,
    s2_commodity_quantity__e commodity_quantity
    ) {
    double *upper_average_power_copy = NULL;
    if (upper_average_power) {
        upper_average_power_copy = malloc(sizeof(double));
        if (upper_average_power_copy) *upper_average_power_copy = *upper_average_power;
    }
    double *lower_average_power_copy = NULL;
    if (lower_average_power) {
        lower_average_power_copy = malloc(sizeof(double));
        if (lower_average_power_copy) *lower_average_power_copy = *lower_average_power;
    }
    pebc_energy_constraint_t *result = pebc_energy_constraint_create_internal (
        message_type,
        message_id,
        id,
        valid_from,
        valid_until,
        upper_average_power_copy,
        lower_average_power_copy,
        commodity_quantity
        );
    if (!result) {
        free(upper_average_power_copy);
        free(lower_average_power_copy);
    }
    return result;
}

void pebc_energy_constraint_free(pebc_energy_constraint_t *pebc_energy_constraint) {
    if(NULL == pebc_energy_constraint){
        return ;
    }
    if(pebc_energy_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pebc_energy_constraint_free");
        return ;
    }
    if (pebc_energy_constraint->message_type) {
        free(pebc_energy_constraint->message_type);
        pebc_energy_constraint->message_type = NULL;
    }
    if (pebc_energy_constraint->message_id) {
        free(pebc_energy_constraint->message_id);
        pebc_energy_constraint->message_id = NULL;
    }
    if (pebc_energy_constraint->id) {
        free(pebc_energy_constraint->id);
        pebc_energy_constraint->id = NULL;
    }
    if (pebc_energy_constraint->valid_from) {
        free(pebc_energy_constraint->valid_from);
        pebc_energy_constraint->valid_from = NULL;
    }
    if (pebc_energy_constraint->valid_until) {
        free(pebc_energy_constraint->valid_until);
        pebc_energy_constraint->valid_until = NULL;
    }
    if (pebc_energy_constraint->upper_average_power) {
        free(pebc_energy_constraint->upper_average_power);
        pebc_energy_constraint->upper_average_power = NULL;
    }
    if (pebc_energy_constraint->lower_average_power) {
        free(pebc_energy_constraint->lower_average_power);
        pebc_energy_constraint->lower_average_power = NULL;
    }
    free(pebc_energy_constraint);
}

cJSON *pebc_energy_constraint_convertToJSON(pebc_energy_constraint_t *pebc_energy_constraint) {
    cJSON *item = cJSON_CreateObject();

    // pebc_energy_constraint->message_type
    if (!pebc_energy_constraint->message_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_type", pebc_energy_constraint->message_type) == NULL) {
    goto fail; //String
    }


    // pebc_energy_constraint->message_id
    if (!pebc_energy_constraint->message_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_id", pebc_energy_constraint->message_id) == NULL) {
    goto fail; //String
    }


    // pebc_energy_constraint->id
    if (!pebc_energy_constraint->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", pebc_energy_constraint->id) == NULL) {
    goto fail; //String
    }


    // pebc_energy_constraint->valid_from
    if (!pebc_energy_constraint->valid_from) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_from", pebc_energy_constraint->valid_from) == NULL) {
    goto fail; //Date-Time
    }


    // pebc_energy_constraint->valid_until
    if (!pebc_energy_constraint->valid_until) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "valid_until", pebc_energy_constraint->valid_until) == NULL) {
    goto fail; //Date-Time
    }


    // pebc_energy_constraint->upper_average_power
    if (!pebc_energy_constraint->upper_average_power) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "upper_average_power", *pebc_energy_constraint->upper_average_power) == NULL) {
    goto fail; //Numeric
    }


    // pebc_energy_constraint->lower_average_power
    if (!pebc_energy_constraint->lower_average_power) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "lower_average_power", *pebc_energy_constraint->lower_average_power) == NULL) {
    goto fail; //Numeric
    }


    // pebc_energy_constraint->commodity_quantity
    if (s2_commodity_quantity__NULL == pebc_energy_constraint->commodity_quantity) {
        goto fail;
    }
    cJSON *commodity_quantity_local_JSON = commodity_quantity_convertToJSON(pebc_energy_constraint->commodity_quantity);
    if(commodity_quantity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity_quantity", commodity_quantity_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pebc_energy_constraint_t *pebc_energy_constraint_parseFromJSON(cJSON *pebc_energy_constraintJSON){

    pebc_energy_constraint_t *pebc_energy_constraint_local_var = NULL;

    char *message_type_local_str = NULL;

    char *message_id_local_str = NULL;

    char *id_local_str = NULL;

    char *valid_from_local_str = NULL;

    char *valid_until_local_str = NULL;

    // define the local variable for pebc_energy_constraint->upper_average_power
    double *upper_average_power_local_var = NULL;

    // define the local variable for pebc_energy_constraint->lower_average_power
    double *lower_average_power_local_var = NULL;

    // define the local variable for pebc_energy_constraint->commodity_quantity
    s2_commodity_quantity__e commodity_quantity_local_nonprim = 0;

    // pebc_energy_constraint->message_type
    cJSON *message_type = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "message_type");
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

    // pebc_energy_constraint->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "message_id");
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

    // pebc_energy_constraint->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "id");
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

    // pebc_energy_constraint->valid_from
    cJSON *valid_from = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "valid_from");
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

    // pebc_energy_constraint->valid_until
    cJSON *valid_until = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "valid_until");
    if (cJSON_IsNull(valid_until)) {
        valid_until = NULL;
    }
    if (!valid_until) {
        goto end;
    }

    
    if(!cJSON_IsString(valid_until) && !cJSON_IsNull(valid_until))
    {
    goto end; //DateTime
    }

    // pebc_energy_constraint->upper_average_power
    cJSON *upper_average_power = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "upper_average_power");
    if (cJSON_IsNull(upper_average_power)) {
        upper_average_power = NULL;
    }
    if (!upper_average_power) {
        goto end;
    }

    
    if(!cJSON_IsNumber(upper_average_power))
    {
    goto end; //Numeric
    }
    upper_average_power_local_var = malloc(sizeof(double));
    if(!upper_average_power_local_var)
    {
        goto end;
    }
    *upper_average_power_local_var = upper_average_power->valuedouble;

    // pebc_energy_constraint->lower_average_power
    cJSON *lower_average_power = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "lower_average_power");
    if (cJSON_IsNull(lower_average_power)) {
        lower_average_power = NULL;
    }
    if (!lower_average_power) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lower_average_power))
    {
    goto end; //Numeric
    }
    lower_average_power_local_var = malloc(sizeof(double));
    if(!lower_average_power_local_var)
    {
        goto end;
    }
    *lower_average_power_local_var = lower_average_power->valuedouble;

    // pebc_energy_constraint->commodity_quantity
    cJSON *commodity_quantity = cJSON_GetObjectItemCaseSensitive(pebc_energy_constraintJSON, "commodity_quantity");
    if (cJSON_IsNull(commodity_quantity)) {
        commodity_quantity = NULL;
    }
    if (!commodity_quantity) {
        goto end;
    }

    
    commodity_quantity_local_nonprim = commodity_quantity_parseFromJSON(commodity_quantity); //custom


    if (message_type && !cJSON_IsNull(message_type)) message_type_local_str = strdup(message_type->valuestring);
    if (message_id && !cJSON_IsNull(message_id)) message_id_local_str = strdup(message_id->valuestring);
    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (valid_from && !cJSON_IsNull(valid_from)) valid_from_local_str = strdup(valid_from->valuestring);
    if (valid_until && !cJSON_IsNull(valid_until)) valid_until_local_str = strdup(valid_until->valuestring);

    pebc_energy_constraint_local_var = pebc_energy_constraint_create_internal (
        message_type_local_str,
        message_id_local_str,
        id_local_str,
        valid_from_local_str,
        valid_until_local_str,
        upper_average_power_local_var,
        lower_average_power_local_var,
        commodity_quantity_local_nonprim
        );

    if (!pebc_energy_constraint_local_var) {
        goto end;
    }

    return pebc_energy_constraint_local_var;
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
    if (upper_average_power_local_var) {
        free(upper_average_power_local_var);
        upper_average_power_local_var = NULL;
    }
    if (lower_average_power_local_var) {
        free(lower_average_power_local_var);
        lower_average_power_local_var = NULL;
    }
    if (commodity_quantity_local_nonprim) {
        commodity_quantity_local_nonprim = 0;
    }
    return NULL;

}
