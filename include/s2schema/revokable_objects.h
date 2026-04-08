/*
 * revokable_objects.h
 * PEBC.PowerConstraints: Object type PEBC.PowerConstraints PEBC.EnergyConstraint: Object type PEBC.EnergyConstraint PEBC.Instruction: Object type PEBC.Instruction PPBC.PowerProfileDefinition: Object type PPBC.PowerProfileDefinition PPBC.ScheduleInstruction: Object type PPBC.ScheduleInstruction PPBC.StartInterruptionInstruction: Object type PPBC.StartInterruptionInstruction PPBC.EndInterruptionInstruction: Object type PPBC.EndInterruptionInstruction OMBC.SystemDescription: Object type OMBC.SystemDescription OMBC.Instruction: Object type OMBC.Instruction FRBC.SystemDescription: Object type FRBC.SystemDescription FRBC.Instruction: Object type FRBC.Instruction DDBC.SystemDescription: Object type DDBC.SystemDescription DDBC.Instruction: Object type DDBC.Instruction
 */

#ifndef _revokable_objects_H_
#define _revokable_objects_H_

#include <string.h>
#include <cjson/cJSON.h>
#include <s2schema/list.h>
#include <s2schema/keyValuePair.h>
#include <s2schema/binary.h>

typedef struct revokable_objects_t revokable_objects_t;


// Enum  for revokable_objects

typedef enum { s2_revokable_objects__NULL = 0, s2_revokable_objects__PEBCPowerConstraints, s2_revokable_objects__PEBCEnergyConstraint, s2_revokable_objects__PEBCInstruction, s2_revokable_objects__PPBCPowerProfileDefinition, s2_revokable_objects__PPBCScheduleInstruction, s2_revokable_objects__PPBCStartInterruptionInstruction, s2_revokable_objects__PPBCEndInterruptionInstruction, s2_revokable_objects__OMBCSystemDescription, s2_revokable_objects__OMBCInstruction, s2_revokable_objects__FRBCSystemDescription, s2_revokable_objects__FRBCInstruction, s2_revokable_objects__DDBCSystemDescription, s2_revokable_objects__DDBCInstruction } s2_revokable_objects__e;

char* revokable_objects_revokable_objects_ToString(s2_revokable_objects__e revokable_objects);

s2_revokable_objects__e revokable_objects_revokable_objects_FromString(char* revokable_objects);

cJSON *revokable_objects_convertToJSON(s2_revokable_objects__e revokable_objects);

s2_revokable_objects__e revokable_objects_parseFromJSON(cJSON *revokable_objectsJSON);

#endif /* _revokable_objects_H_ */

