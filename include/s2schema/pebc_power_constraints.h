/*
 * pebc_power_constraints.h
 * 
 */

#ifndef _pebc_power_constraints_H_
#define _pebc_power_constraints_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_power_constraints_t pebc_power_constraints_t;

#include <s2schema/pebc_allowed_limit_range.h>
#include <s2schema/pebc_power_envelope_consequence_type.h>



typedef struct pebc_power_constraints_t {
    char *message_type; // string
    char *message_id; // string
    char *id; // string
    char *valid_from; //date time
    char *valid_until; //date time
    s2_pebc_power_envelope_consequence_type__e consequence_type; //referenced enum
    list_t *allowed_limit_ranges; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_power_constraints_t;

__attribute__((deprecated)) pebc_power_constraints_t *pebc_power_constraints_create(
    char *message_type,
    char *message_id,
    char *id,
    char *valid_from,
    char *valid_until,
    s2_pebc_power_envelope_consequence_type__e consequence_type,
    list_t *allowed_limit_ranges
);

void pebc_power_constraints_free(pebc_power_constraints_t *pebc_power_constraints);

pebc_power_constraints_t *pebc_power_constraints_parseFromJSON(cJSON *pebc_power_constraintsJSON);

cJSON *pebc_power_constraints_convertToJSON(pebc_power_constraints_t *pebc_power_constraints);

#endif /* _pebc_power_constraints_H_ */

