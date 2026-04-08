/*
 * pebc_power_envelope_limit_type.h
 * UPPER_LIMIT: Indicating the upper limit of a PEBC.PowerEnvelope (see Clause 7.6.2) LOWER_LIMIT: Indicating the lower limit of a PEBC.PowerEnvelope (see Clause 7.6.2)
 */

#ifndef _pebc_power_envelope_limit_type_H_
#define _pebc_power_envelope_limit_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_power_envelope_limit_type_t pebc_power_envelope_limit_type_t;


// Enum  for pebc_power_envelope_limit_type

typedef enum { s2_pebc_power_envelope_limit_type__NULL = 0, s2_pebc_power_envelope_limit_type__UPPERLIMIT, s2_pebc_power_envelope_limit_type__LOWERLIMIT } s2_pebc_power_envelope_limit_type__e;

char* pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_ToString(s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type);

s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type_pebc_power_envelope_limit_type_FromString(char* pebc_power_envelope_limit_type);

cJSON *pebc_power_envelope_limit_type_convertToJSON(s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type);

s2_pebc_power_envelope_limit_type__e pebc_power_envelope_limit_type_parseFromJSON(cJSON *pebc_power_envelope_limit_typeJSON);

#endif /* _pebc_power_envelope_limit_type_H_ */

