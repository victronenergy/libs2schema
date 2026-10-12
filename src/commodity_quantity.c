#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/commodity_quantity.h>


char* commodity_quantity_commodity_quantity_ToString(s2_commodity_quantity__e commodity_quantity) {
    char *commodity_quantityArray[] =  { "NULL", "ELECTRIC.POWER.L1", "ELECTRIC.POWER.L2", "ELECTRIC.POWER.L3", "ELECTRIC.POWER.3_PHASE_SYMMETRIC", "NATURAL_GAS.FLOW_RATE", "HYDROGEN.FLOW_RATE", "HEAT.TEMPERATURE", "HEAT.FLOW_RATE", "HEAT.THERMAL_POWER", "OIL.FLOW_RATE" };
    return commodity_quantityArray[commodity_quantity];
}

s2_commodity_quantity__e commodity_quantity_commodity_quantity_FromString(char* commodity_quantity) {
    size_t stringToReturn = 0;
    char *commodity_quantityArray[] =  { "NULL", "ELECTRIC.POWER.L1", "ELECTRIC.POWER.L2", "ELECTRIC.POWER.L3", "ELECTRIC.POWER.3_PHASE_SYMMETRIC", "NATURAL_GAS.FLOW_RATE", "HYDROGEN.FLOW_RATE", "HEAT.TEMPERATURE", "HEAT.FLOW_RATE", "HEAT.THERMAL_POWER", "OIL.FLOW_RATE" };
    size_t sizeofArray = sizeof(commodity_quantityArray) / sizeof(commodity_quantityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(commodity_quantity, commodity_quantityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *commodity_quantity_convertToJSON(s2_commodity_quantity__e commodity_quantity) {
    cJSON *item = cJSON_CreateString(commodity_quantity_commodity_quantity_ToString(commodity_quantity));
    // if(cJSON_AddStringToObject(item, "commodity_quantity", commodity_quantity_commodity_quantity_ToString(commodity_quantity)) == NULL) {
    //    goto fail;
    // }
    return item;
}

s2_commodity_quantity__e commodity_quantity_parseFromJSON(cJSON *commodity_quantityJSON) {
    if(!cJSON_IsString(commodity_quantityJSON) || (commodity_quantityJSON->valuestring == NULL)) {
        return 0;
    }
    return commodity_quantity_commodity_quantity_FromString(commodity_quantityJSON->valuestring);
}
