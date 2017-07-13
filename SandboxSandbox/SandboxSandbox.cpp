#include "stdafx.h"
#include "Actions.h"
#include "Mitigations.h"

int main()
{
	ApplyMitigations();

	printf("\n");

	AllocateRWX();
	AllocateRW();
	AllocateRX();
	AllocateX();
	AllocateR();

	AllocateRW_Then_RX();

	printf("Press enter to exit\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
	return 0;
}

