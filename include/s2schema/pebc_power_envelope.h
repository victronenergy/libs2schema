/*
 * pebc_power_envelope.h
 * 
 */

#ifndef _pebc_power_envelope_H_
#define _pebc_power_envelope_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_power_envelope_t pebc_power_envelope_t;

#include <s2schema/commodity_quantity.h>
#include <s2schema/pebc_power_envelope_element.h>



typedef struct pebc_power_envelope_t {
    char *id; // string
    s2_commodity_quantity__e commodity_quantity; //referenced enum
    list_t *power_envelope_elements; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_power_envelope_t;

__attribute__((deprecated)) pebc_power_envelope_t *pebc_power_envelope_create(
    char *id,
    s2_commodity_quantity__e commodity_quantity,
    list_t *power_envelope_elements
);

void pebc_power_envelope_free(pebc_power_envelope_t *pebc_power_envelope);

pebc_power_envelope_t *pebc_power_envelope_parseFromJSON(cJSON *pebc_power_envelopeJSON);

cJSON *pebc_power_envelope_convertToJSON(pebc_power_envelope_t *pebc_power_envelope);

#endif /* _pebc_power_envelope_H_ */

