/*
 * role_type.h
 * ENERGY_PRODUCER: Identifier for RoleType Producer ENERGY_CONSUMER: Identifier for RoleType Consumer ENERGY_STORAGE: Identifier for RoleType Storage
 */

#ifndef _role_type_H_
#define _role_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct role_type_t role_type_t;


// Enum  for role_type

typedef enum { s2_role_type__NULL = 0, s2_role_type__ENERGYPRODUCER, s2_role_type__ENERGYCONSUMER, s2_role_type__ENERGYSTORAGE } s2_role_type__e;

char* role_type_role_type_ToString(s2_role_type__e role_type);

s2_role_type__e role_type_role_type_FromString(char* role_type);

cJSON *role_type_convertToJSON(s2_role_type__e role_type);

s2_role_type__e role_type_parseFromJSON(cJSON *role_typeJSON);

#endif /* _role_type_H_ */

