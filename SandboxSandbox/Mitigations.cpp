#include "stdafx.h"
#include "Mitigations.h"

// ========================================
void ACG()
{
	printf("%s\n", __FUNCTION__);

	PROCESS_MITIGATION_DYNAMIC_CODE_POLICY policy;
	policy.Flags = 0x01;
	bool success = SetProcessMitigationPolicy(
		ProcessDynamicCodePolicy,
		&policy,
		sizeof(policy)
	);

	if (!success) {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not set mitigation (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ========================================
void ApplyMitigations()
{
	ACG();
}
