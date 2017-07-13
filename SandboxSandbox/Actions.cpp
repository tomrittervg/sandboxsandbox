#include "stdafx.h"
#include "Actions.h"

void AllocateRWX()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_EXECUTE_READWRITE);

	if (page != NULL) {
		LPSTR pagePtr = (LPSTR)page;
		pagePtr[0] = 0x42;
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ==========================================================================
void AllocateR()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_READONLY);

	if (page != NULL) {
		bool bigProblem = false;
		try {
			LPSTR pagePtr = (LPSTR)page;
			pagePtr[0] = 0x42;
			bigProblem = true;
		}
		catch (...) {
		}

		if (bigProblem) {
			wprintf(L"\t ERROR: Somehow we were able to write to a read-only page.\n");
		}
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ==========================================================================
void AllocateX()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_EXECUTE);

	if (page != NULL) {
		bool bigProblem = false;
		try {
			LPSTR pagePtr = (LPSTR)page;
			pagePtr[0] = 0x42;
			bigProblem = true;
		}
		catch (...) {
		}

		if (bigProblem) {
			wprintf(L"\t ERROR: Somehow we were able to write to a execute-only page.\n");
		}
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ==========================================================================
void AllocateRX()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_EXECUTE_READ);

	if (page != NULL) {
		bool bigProblem = false;
		try {
			LPSTR pagePtr = (LPSTR)page;
			pagePtr[0] = 0x42;
			bigProblem = true;
		}
		catch (...) {
		}

		if (bigProblem) {
			wprintf(L"\t ERROR: Somehow we were able to write to a readexecute-only page.\n");
		}
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ==========================================================================
void AllocateRW()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_READWRITE);

	if (page != NULL) {
		bool bigProblem = false;
		try {
			LPSTR pagePtr = (LPSTR)page;
			pagePtr[0] = 0xCC;
			funcptr* fp = (funcptr*)pagePtr;
			fp();
			bigProblem = true;
		}
		catch (...) {
		}

		if (bigProblem) {
			wprintf(L"\t ERROR: Somehow we were able to execute a readwrite-only page.\n");
		}
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}
// ==========================================================================
void AllocateRW_Then_RX()
{
	printf("%s\n", __FUNCTION__);
	LPVOID page = VirtualAlloc(
		NULL,
		100,
		MEM_COMMIT,
		PAGE_READWRITE);

	if (page != NULL) {
		DWORD oldProtect;
		bool success = VirtualProtect(
			page,
			100,
			PAGE_EXECUTE_READ,
			(PDWORD)&oldProtect);
		
		if(!success) {
			DWORD errorCode = GetLastError();
			wprintf(L"\t Could not reallocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
		}
	}
	else {
		DWORD errorCode = GetLastError();
		wprintf(L"\t Could not initially allocate page (0x%x): %s\n", errorCode, FormatError(errorCode));
	}
}