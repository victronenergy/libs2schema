/*
 * reception_status_values.h
 * INVALID_DATA: Message not understood (e.g. not valid JSON, no message_id found). Consequence: Message is ignored, proceed if possible INVALID_MESSAGE: Message was not according to schema. Consequence: Message is ignored, proceed if possible INVALID_CONTENT: Message contents is invalid (e.g. contains a non-existing ID). Somewhat equivalent to BAD_REQUEST in HTTP.. Consequence: Message is ignored, proceed if possible. TEMPORARY_ERROR: Receiver encountered an error. Consequence: Try to send to message again PERMANENT_ERROR: Receiver encountered an error which it cannot recover from. Consequence: Disconnect. OK: Message processed normally. Consequence: Proceed normally.
 */

#ifndef _reception_status_values_H_
#define _reception_status_values_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct reception_status_values_t reception_status_values_t;


// Enum  for reception_status_values

typedef enum { s2_reception_status_values__NULL = 0, s2_reception_status_values__INVALIDDATA, s2_reception_status_values__INVALIDMESSAGE, s2_reception_status_values__INVALIDCONTENT, s2_reception_status_values__TEMPORARYERROR, s2_reception_status_values__PERMANENTERROR, s2_reception_status_values__OK } s2_reception_status_values__e;

char* reception_status_values_reception_status_values_ToString(s2_reception_status_values__e reception_status_values);

s2_reception_status_values__e reception_status_values_reception_status_values_FromString(char* reception_status_values);

cJSON *reception_status_values_convertToJSON(s2_reception_status_values__e reception_status_values);

s2_reception_status_values__e reception_status_values_parseFromJSON(cJSON *reception_status_valuesJSON);

#endif /* _reception_status_values_H_ */

