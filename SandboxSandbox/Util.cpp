#include "stdafx.h"
#include "Util.h"

LPWSTR FormatError(DWORD errorCode)
{
	LPWSTR lpMsgBuf = NULL;

	FormatMessageW(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPWSTR)&lpMsgBuf,
		0, NULL);
	
	return lpMsgBuf;
}
