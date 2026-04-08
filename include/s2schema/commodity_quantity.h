/*
 * commodity_quantity.h
 * ELECTRIC.POWER.L1: Electric power described in Watt on phase 1. If a device utilizes only one phase it should always use L1. ELECTRIC.POWER.L2: Electric power described in Watt on phase 2. Only applicable for 3 phase devices. ELECTRIC.POWER.L3: Electric power described in Watt on phase 3. Only applicable for 3 phase devices. ELECTRIC.POWER.3_PHASE_SYMMETRIC: Electric power described in Watt on when power is equally shared among the three phases. Only applicable for 3 phase devices. NATURAL_GAS.FLOW_RATE: Gas flow rate described in liters per second HYDROGEN.FLOW_RATE: Gas flow rate described in grams per second HEAT.TEMPERATURE: Heat described in degrees Celsius HEAT.FLOW_RATE: Flow rate of heat carrying gas or liquid in liters per second HEAT.THERMAL_POWER: Thermal power in Watt OIL.FLOW_RATE: Oil flow rate described in liters per hour
 */

#ifndef _commodity_quantity_H_
#define _commodity_quantity_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct commodity_quantity_t commodity_quantity_t;


// Enum  for commodity_quantity

typedef enum { s2_commodity_quantity__NULL = 0, s2_commodity_quantity__ELECTRICPOWERL1, s2_commodity_quantity__ELECTRICPOWERL2, s2_commodity_quantity__ELECTRICPOWERL3, s2_commodity_quantity__ELECTRICPOWER3PHASESYMMETRIC, s2_commodity_quantity__NATURALGASFLOWRATE, s2_commodity_quantity__HYDROGENFLOWRATE, s2_commodity_quantity__HEATTEMPERATURE, s2_commodity_quantity__HEATFLOWRATE, s2_commodity_quantity__HEATTHERMALPOWER, s2_commodity_quantity__OILFLOWRATE } s2_commodity_quantity__e;

char* commodity_quantity_commodity_quantity_ToString(s2_commodity_quantity__e commodity_quantity);

s2_commodity_quantity__e commodity_quantity_commodity_quantity_FromString(char* commodity_quantity);

cJSON *commodity_quantity_convertToJSON(s2_commodity_quantity__e commodity_quantity);

s2_commodity_quantity__e commodity_quantity_parseFromJSON(cJSON *commodity_quantityJSON);

#endif /* _commodity_quantity_H_ */

