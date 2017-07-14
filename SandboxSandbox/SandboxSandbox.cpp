#include "stdafx.h"
#include "Actions.h"
#include "Mitigations.h"

int main()
{
	Arbitrary_Code_Guard(true);
	printf("\n");
	All_Allocation_Actions();
	printf("\n");
	printf("\n");
	Arbitrary_Code_Guard(false);
	printf("\n");
	All_Allocation_Actions();

	printf("\n\n\nPress enter to exit\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
	return 0;
}

