/*
 * commodity.h
 * GAS: Identifier for Commodity GAS HEAT: Identifier for Commodity HEAT ELECTRICITY: Identifier for Commodity ELECTRICITY OIL: Identifier for Commodity OIL
 */

#ifndef _commodity_H_
#define _commodity_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct commodity_t commodity_t;


// Enum  for commodity

typedef enum { s2_commodity__NULL = 0, s2_commodity__GAS, s2_commodity__HEAT, s2_commodity__ELECTRICITY, s2_commodity__OIL } s2_commodity__e;

char* commodity_commodity_ToString(s2_commodity__e commodity);

s2_commodity__e commodity_commodity_FromString(char* commodity);

cJSON *commodity_convertToJSON(s2_commodity__e commodity);

s2_commodity__e commodity_parseFromJSON(cJSON *commodityJSON);

#endif /* _commodity_H_ */

