/*
 * role.h
 * 
 */

#ifndef _role_H_
#define _role_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct role_t role_t;

#include <s2schema/commodity.h>
#include <s2schema/role_type.h>



typedef struct role_t {
    s2_role_type__e role; //referenced enum
    s2_commodity__e commodity; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} role_t;

__attribute__((deprecated)) role_t *role_create(
    s2_role_type__e role,
    s2_commodity__e commodity
);

void role_free(role_t *role);

role_t *role_parseFromJSON(cJSON *roleJSON);

cJSON *role_convertToJSON(role_t *role);

#endif /* _role_H_ */

