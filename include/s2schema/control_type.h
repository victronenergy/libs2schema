/*
 * control_type.h
 * POWER_ENVELOPE_BASED_CONTROL: Identifier for the Power Envelope Based Control type POWER_PROFILE_BASED_CONTROL: Identifier for the Power Profile Based Control type OPERATION_MODE_BASED_CONTROL: Identifier for the Operation Mode Based Control type FILL_RATE_BASED_CONTROL: Identifier for the Demand Driven Based Control type DEMAND_DRIVEN_BASED_CONTROL: Identifier for the Fill Rate Based Control type NOT_CONTROLABLE: Identifier that is to be used if no control is possible. Resources of this type can still provide measurements and forecast NO_SELECTION: Identifier that is to be used if no control type is or has been selected. 
 */

#ifndef _control_type_H_
#define _control_type_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct control_type_t control_type_t;


// Enum  for control_type

typedef enum { s2_control_type__NULL = 0, s2_control_type__POWERENVELOPEBASEDCONTROL, s2_control_type__POWERPROFILEBASEDCONTROL, s2_control_type__OPERATIONMODEBASEDCONTROL, s2_control_type__FILLRATEBASEDCONTROL, s2_control_type__DEMANDDRIVENBASEDCONTROL, s2_control_type__NOTCONTROLABLE, s2_control_type__NOSELECTION } s2_control_type__e;

char* control_type_control_type_ToString(s2_control_type__e control_type);

s2_control_type__e control_type_control_type_FromString(char* control_type);

cJSON *control_type_convertToJSON(s2_control_type__e control_type);

s2_control_type__e control_type_parseFromJSON(cJSON *control_typeJSON);

#endif /* _control_type_H_ */

