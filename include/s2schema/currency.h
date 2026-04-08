/*
 * currency.h
 * Currency used when this resource gives cost information
 */

#ifndef _currency_H_
#define _currency_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct currency_t currency_t;


// Enum  for currency

typedef enum { s2_currency__NULL = 0, s2_currency__AED, s2_currency__ANG, s2_currency__AUD, s2_currency__CHE, s2_currency__CHF, s2_currency__CHW, s2_currency__EUR, s2_currency__GBP, s2_currency__LBP, s2_currency__LKR, s2_currency__LRD, s2_currency__LSL, s2_currency__LYD, s2_currency__MAD, s2_currency__MDL, s2_currency__MGA, s2_currency__MKD, s2_currency__MMK, s2_currency__MNT, s2_currency__MOP, s2_currency__MRO, s2_currency__MUR, s2_currency__MVR, s2_currency__MWK, s2_currency__MXN, s2_currency__MXV, s2_currency__MYR, s2_currency__MZN, s2_currency__NAD, s2_currency__NGN, s2_currency__NIO, s2_currency__NOK, s2_currency__NPR, s2_currency__NZD, s2_currency__OMR, s2_currency__PAB, s2_currency__PEN, s2_currency__PGK, s2_currency__PHP, s2_currency__PKR, s2_currency__PLN, s2_currency__PYG, s2_currency__QAR, s2_currency__RON, s2_currency__RSD, s2_currency__RUB, s2_currency__RWF, s2_currency__SAR, s2_currency__SBD, s2_currency__SCR, s2_currency__SDG, s2_currency__SEK, s2_currency__SGD, s2_currency__SHP, s2_currency__SLL, s2_currency__SOS, s2_currency__SRD, s2_currency__SSP, s2_currency__STD, s2_currency__SYP, s2_currency__SZL, s2_currency__THB, s2_currency__TJS, s2_currency__TMT, s2_currency__TND, s2_currency__TOP, s2_currency__TRY, s2_currency__TTD, s2_currency__TWD, s2_currency__TZS, s2_currency__UAH, s2_currency__UGX, s2_currency__USD, s2_currency__USN, s2_currency__UYI, s2_currency__UYU, s2_currency__UZS, s2_currency__VEF, s2_currency__VND, s2_currency__VUV, s2_currency__WST, s2_currency__XAG, s2_currency__XAU, s2_currency__XBA, s2_currency__XBB, s2_currency__XBC, s2_currency__XBD, s2_currency__XCD, s2_currency__XOF, s2_currency__XPD, s2_currency__XPF, s2_currency__XPT, s2_currency__XSU, s2_currency__XTS, s2_currency__XUA, s2_currency__XXX, s2_currency__YER, s2_currency__ZAR, s2_currency__ZMW, s2_currency__ZWL } s2_currency__e;

char* currency_currency_ToString(s2_currency__e currency);

s2_currency__e currency_currency_FromString(char* currency);

cJSON *currency_convertToJSON(s2_currency__e currency);

s2_currency__e currency_parseFromJSON(cJSON *currencyJSON);

#endif /* _currency_H_ */

