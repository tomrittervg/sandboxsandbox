#pragma once
#include <Windows.h>

#define GET_ERROR_AND_PRINT(str) \
	do { \
	DWORD errorCode = GetLastError(); \
	wprintf(L"\t Could not " str " (0x%x): %s", errorCode, FormatError(errorCode)); \
	} while(false);

LPWSTR FormatError(DWORD errorCode);