/*
 * ppbc_power_sequence_status.h
 * NOT_SCHEDULED: No PPBC.PowerSequence within the PPBC.PowerSequenceContainer is scheduled SCHEDULED: The selected PPBC.PowerSequence is scheduled to be executed in the future EXECUTING: The selected PPBC.PowerSequence is currently being executed INTERRUPTED: The selected PPBC.PowerSequence is being executed, but is currently interrupted and will continue afterwards FINISHED: The selected PPBC.PowerSequence was executed and finished successfully ABORTED: The selected PPBC.PowerSequence was aborted by the device and will not continue
 */

#ifndef _ppbc_power_sequence_status_H_
#define _ppbc_power_sequence_status_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct ppbc_power_sequence_status_t ppbc_power_sequence_status_t;


// Enum  for ppbc_power_sequence_status

typedef enum { s2_ppbc_power_sequence_status__NULL = 0, s2_ppbc_power_sequence_status__NOTSCHEDULED, s2_ppbc_power_sequence_status__SCHEDULED, s2_ppbc_power_sequence_status__EXECUTING, s2_ppbc_power_sequence_status__INTERRUPTED, s2_ppbc_power_sequence_status__FINISHED, s2_ppbc_power_sequence_status__ABORTED } s2_ppbc_power_sequence_status__e;

char* ppbc_power_sequence_status_ppbc_power_sequence_status_ToString(s2_ppbc_power_sequence_status__e ppbc_power_sequence_status);

s2_ppbc_power_sequence_status__e ppbc_power_sequence_status_ppbc_power_sequence_status_FromString(char* ppbc_power_sequence_status);

cJSON *ppbc_power_sequence_status_convertToJSON(s2_ppbc_power_sequence_status__e ppbc_power_sequence_status);

s2_ppbc_power_sequence_status__e ppbc_power_sequence_status_parseFromJSON(cJSON *ppbc_power_sequence_statusJSON);

#endif /* _ppbc_power_sequence_status_H_ */

