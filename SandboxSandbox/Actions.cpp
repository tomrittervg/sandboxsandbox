#include "stdafx.h"
#include "Actions.h"

void All_Allocation_Actions() {
	AllocateRWX();
	AllocateRW();
	AllocateRX();
	AllocateX();
	AllocateR();
	AllocateRW_Then_RX();
}
// ==========================================================================
// ==========================================================================
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
	else 
		GET_ERROR_AND_PRINT("allocate page");
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
	else
		GET_ERROR_AND_PRINT("allocate page");
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
	else 
		GET_ERROR_AND_PRINT("allocate page");
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
	else 
		GET_ERROR_AND_PRINT("allocate page");
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
	else 
		GET_ERROR_AND_PRINT("allocate page");
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
		BOOL success = VirtualProtect(
			page,
			100,
			PAGE_EXECUTE_READ,
			(PDWORD)&oldProtect);
		
		if(!success) 
			GET_ERROR_AND_PRINT("reallocate page");
	}
	else 
		GET_ERROR_AND_PRINT("initially allocate page");
}