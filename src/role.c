#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/role.h>



static role_t *role_create_internal(
    s2_role_type__e role,
    s2_commodity__e commodity
    ) {
    role_t *role_local_var = malloc(sizeof(role_t));
    if (!role_local_var) {
        return NULL;
    }
    memset(role_local_var, 0, sizeof(role_t));
    role_local_var->_library_owned = 1;
    role_local_var->role = role;
    role_local_var->commodity = commodity;
    return role_local_var;
}

__attribute__((deprecated)) role_t *role_create(
    s2_role_type__e role,
    s2_commodity__e commodity
    ) {
    role_t *result = role_create_internal (
        role,
        commodity
        );
    if (!result) {
    }
    return result;
}

void role_free(role_t *role) {
    if(NULL == role){
        return ;
    }
    if(role->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "role_free");
        return ;
    }
    free(role);
}

cJSON *role_convertToJSON(role_t *role) {
    cJSON *item = cJSON_CreateObject();

    // role->role
    if (s2_role_type__NULL == role->role) {
        goto fail;
    }
    cJSON *role_local_JSON = role_type_convertToJSON(role->role);
    if(role_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "role", role_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // role->commodity
    if (s2_commodity__NULL == role->commodity) {
        goto fail;
    }
    cJSON *commodity_local_JSON = commodity_convertToJSON(role->commodity);
    if(commodity_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "commodity", commodity_local_JSON);
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

role_t *role_parseFromJSON(cJSON *roleJSON){

    role_t *role_local_var = NULL;

    // define the local variable for role->role
    s2_role_type__e role_local_nonprim = 0;

    // define the local variable for role->commodity
    s2_commodity__e commodity_local_nonprim = 0;

    // role->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(roleJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    role_local_nonprim = role_type_parseFromJSON(role); //custom

    // role->commodity
    cJSON *commodity = cJSON_GetObjectItemCaseSensitive(roleJSON, "commodity");
    if (cJSON_IsNull(commodity)) {
        commodity = NULL;
    }
    if (!commodity) {
        goto end;
    }

    
    commodity_local_nonprim = commodity_parseFromJSON(commodity); //custom



    role_local_var = role_create_internal (
        role_local_nonprim,
        commodity_local_nonprim
        );

    if (!role_local_var) {
        goto end;
    }

    return role_local_var;
end:
    if (role_local_nonprim) {
        role_local_nonprim = 0;
    }
    if (commodity_local_nonprim) {
        commodity_local_nonprim = 0;
    }
    return NULL;

}
