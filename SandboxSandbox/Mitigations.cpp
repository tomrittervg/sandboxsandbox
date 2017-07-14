#include "stdafx.h"
#include "Mitigations.h"

// ========================================
void Arbitrary_Code_Guard(bool on)
{
	printf("%s: %s\n", __FUNCTION__, on ? "On" : "Off");

	PROCESS_MITIGATION_DYNAMIC_CODE_POLICY policy;
	if(on)
		policy.Flags = 0x01;
	else
		policy.Flags = 0x00;
	
	BOOL success = SetProcessMitigationPolicy(
		ProcessDynamicCodePolicy,
		&policy,
		sizeof(policy)
	);

	if (!success)
		GET_ERROR_AND_PRINT("set mitigation");
}
// ========================================
void ApplyMitigations()
{
	Arbitrary_Code_Guard(true);
}
