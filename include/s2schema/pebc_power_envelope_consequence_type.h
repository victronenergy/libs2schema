/*
 * pebc_power_envelope_consequence_type.h
 * VANISH: Indicating that the limited load or generated will be lost and not reappear in the future (see Clause 7.6.2) DEFER: Indicating that the limited load or generation will be postponed to a later moment (see Clause 7.6.2)
 */

#ifndef _pebc_power_envelope_consequence_type_H_
#define _pebc_power_envelope_consequence_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_power_envelope_consequence_type_t pebc_power_envelope_consequence_type_t;


// Enum  for pebc_power_envelope_consequence_type

typedef enum { s2_pebc_power_envelope_consequence_type__NULL = 0, s2_pebc_power_envelope_consequence_type__VANISH, s2_pebc_power_envelope_consequence_type__DEFER } s2_pebc_power_envelope_consequence_type__e;

char* pebc_power_envelope_consequence_type_pebc_power_envelope_consequence_type_ToString(s2_pebc_power_envelope_consequence_type__e pebc_power_envelope_consequence_type);

s2_pebc_power_envelope_consequence_type__e pebc_power_envelope_consequence_type_pebc_power_envelope_consequence_type_FromString(char* pebc_power_envelope_consequence_type);

cJSON *pebc_power_envelope_consequence_type_convertToJSON(s2_pebc_power_envelope_consequence_type__e pebc_power_envelope_consequence_type);

s2_pebc_power_envelope_consequence_type__e pebc_power_envelope_consequence_type_parseFromJSON(cJSON *pebc_power_envelope_consequence_typeJSON);

#endif /* _pebc_power_envelope_consequence_type_H_ */

