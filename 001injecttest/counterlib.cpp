#include <stdio.h>
#include "counterlib.h"

__stdcall void hello(const char *s)
{
	printf("Dll %s loaded!", "counterlib.dll");
}

int count(int p)
{
	return ++p;
}
