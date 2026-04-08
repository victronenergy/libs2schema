#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/commodity.h>


char* commodity_commodity_ToString(s2_commodity__e commodity) {
    char *commodityArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
    return commodityArray[commodity];
}

s2_commodity__e commodity_commodity_FromString(char* commodity) {
    size_t stringToReturn = 0;
    char *commodityArray[] =  { "NULL", "GAS", "HEAT", "ELECTRICITY", "OIL" };
    size_t sizeofArray = sizeof(commodityArray) / sizeof(commodityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(commodity, commodityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *commodity_convertToJSON(s2_commodity__e commodity) {
    cJSON *item = cJSON_CreateString(commodity_commodity_ToString(commodity));
    // if(cJSON_AddStringToObject(item, "commodity", commodity_commodity_ToString(commodity)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_commodity__e commodity_parseFromJSON(cJSON *commodityJSON) {
    if(!cJSON_IsString(commodityJSON) || (commodityJSON->valuestring == NULL)) {
        return 0;
    }
    return commodity_commodity_FromString(commodityJSON->valuestring);
}
