#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <s2schema/currency.h>


char* currency_currency_ToString(s2_currency__e currency) {
    char *currencyArray[] =  { "NULL", "AED", "ANG", "AUD", "CHE", "CHF", "CHW", "EUR", "GBP", "LBP", "LKR", "LRD", "LSL", "LYD", "MAD", "MDL", "MGA", "MKD", "MMK", "MNT", "MOP", "MRO", "MUR", "MVR", "MWK", "MXN", "MXV", "MYR", "MZN", "NAD", "NGN", "NIO", "NOK", "NPR", "NZD", "OMR", "PAB", "PEN", "PGK", "PHP", "PKR", "PLN", "PYG", "QAR", "RON", "RSD", "RUB", "RWF", "SAR", "SBD", "SCR", "SDG", "SEK", "SGD", "SHP", "SLL", "SOS", "SRD", "SSP", "STD", "SYP", "SZL", "THB", "TJS", "TMT", "TND", "TOP", "TRY", "TTD", "TWD", "TZS", "UAH", "UGX", "USD", "USN", "UYI", "UYU", "UZS", "VEF", "VND", "VUV", "WST", "XAG", "XAU", "XBA", "XBB", "XBC", "XBD", "XCD", "XOF", "XPD", "XPF", "XPT", "XSU", "XTS", "XUA", "XXX", "YER", "ZAR", "ZMW", "ZWL" };
    return currencyArray[currency];
}

s2_currency__e currency_currency_FromString(char* currency) {
    size_t stringToReturn = 0;
    char *currencyArray[] =  { "NULL", "AED", "ANG", "AUD", "CHE", "CHF", "CHW", "EUR", "GBP", "LBP", "LKR", "LRD", "LSL", "LYD", "MAD", "MDL", "MGA", "MKD", "MMK", "MNT", "MOP", "MRO", "MUR", "MVR", "MWK", "MXN", "MXV", "MYR", "MZN", "NAD", "NGN", "NIO", "NOK", "NPR", "NZD", "OMR", "PAB", "PEN", "PGK", "PHP", "PKR", "PLN", "PYG", "QAR", "RON", "RSD", "RUB", "RWF", "SAR", "SBD", "SCR", "SDG", "SEK", "SGD", "SHP", "SLL", "SOS", "SRD", "SSP", "STD", "SYP", "SZL", "THB", "TJS", "TMT", "TND", "TOP", "TRY", "TTD", "TWD", "TZS", "UAH", "UGX", "USD", "USN", "UYI", "UYU", "UZS", "VEF", "VND", "VUV", "WST", "XAG", "XAU", "XBA", "XBB", "XBC", "XBD", "XCD", "XOF", "XPD", "XPF", "XPT", "XSU", "XTS", "XUA", "XXX", "YER", "ZAR", "ZMW", "ZWL" };
    size_t sizeofArray = sizeof(currencyArray) / sizeof(currencyArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(currency, currencyArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *currency_convertToJSON(s2_currency__e currency) {
    cJSON *item = cJSON_CreateString(currency_currency_ToString(currency));
    // if(cJSON_AddStringToObject(item, "currency", currency_currency_ToString(currency)) == NULL) {
    //    goto fail;
    // }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

s2_currency__e currency_parseFromJSON(cJSON *currencyJSON) {
    if(!cJSON_IsString(currencyJSON) || (currencyJSON->valuestring == NULL)) {
        return 0;
    }
    return currency_currency_FromString(currencyJSON->valuestring);
}
