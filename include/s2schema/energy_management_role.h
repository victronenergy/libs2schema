/*
 * energy_management_role.h
 * CEM: Customer Energy Manager RM: Resource Manager
 */

#ifndef _energy_management_role_H_
#define _energy_management_role_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct energy_management_role_t energy_management_role_t;


// Enum  for energy_management_role

typedef enum { s2_energy_management_role__NULL = 0, s2_energy_management_role__CEM, s2_energy_management_role__RM } s2_energy_management_role__e;

char* energy_management_role_energy_management_role_ToString(s2_energy_management_role__e energy_management_role);

s2_energy_management_role__e energy_management_role_energy_management_role_FromString(char* energy_management_role);

cJSON *energy_management_role_convertToJSON(s2_energy_management_role__e energy_management_role);

s2_energy_management_role__e energy_management_role_parseFromJSON(cJSON *energy_management_roleJSON);

#endif /* _energy_management_role_H_ */

