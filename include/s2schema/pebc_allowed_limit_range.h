/*
 * pebc_allowed_limit_range.h
 * 
 */

#ifndef _pebc_allowed_limit_range_H_
#define _pebc_allowed_limit_range_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct pebc_allowed_limit_range_t pebc_allowed_limit_range_t;

#include <s2schema/commodity_quantity.h>
#include <s2schema/number_range.h>
#include <s2schema/pebc_power_envelope_limit_type.h>



typedef struct pebc_allowed_limit_range_t {
    s2_commodity_quantity__e commodity_quantity; //referenced enum
    s2_pebc_power_envelope_limit_type__e limit_type; //referenced enum
    struct number_range_t *range_boundary; //model
    int *abnormal_condition_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} pebc_allowed_limit_range_t;

__attribute__((deprecated)) pebc_allowed_limit_range_t *pebc_allowed_limit_range_create(
    s2_commodity_quantity__e commodity_quantity,
    s2_pebc_power_envelope_limit_type__e limit_type,
    number_range_t *range_boundary,
    int *abnormal_condition_only
);

void pebc_allowed_limit_range_free(pebc_allowed_limit_range_t *pebc_allowed_limit_range);

pebc_allowed_limit_range_t *pebc_allowed_limit_range_parseFromJSON(cJSON *pebc_allowed_limit_rangeJSON);

cJSON *pebc_allowed_limit_range_convertToJSON(pebc_allowed_limit_range_t *pebc_allowed_limit_range);

#endif /* _pebc_allowed_limit_range_H_ */

