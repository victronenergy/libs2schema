/*
 * pebc_energy_constraint.h
 * 
 */

#ifndef _pebc_energy_constraint_H_
#define _pebc_energy_constraint_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_energy_constraint_t pebc_energy_constraint_t;

#include <s2schema/commodity_quantity.h>



typedef struct pebc_energy_constraint_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *valid_from; //date time
    char *valid_until; //date time
    double *upper_average_power; //numeric
    double *lower_average_power; //numeric
    s2_commodity_quantity__e commodity_quantity; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_energy_constraint_t;

__attribute__((deprecated)) pebc_energy_constraint_t *pebc_energy_constraint_create(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    double *upper_average_power,
    double *lower_average_power,
    s2_commodity_quantity__e commodity_quantity
);

void pebc_energy_constraint_free(pebc_energy_constraint_t *pebc_energy_constraint);

pebc_energy_constraint_t *pebc_energy_constraint_parseFromJSON(cJSON *pebc_energy_constraintJSON);

cJSON *pebc_energy_constraint_convertToJSON(pebc_energy_constraint_t *pebc_energy_constraint);

#endif /* _pebc_energy_constraint_H_ */

