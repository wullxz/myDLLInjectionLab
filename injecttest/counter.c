#include <stdio.h>
#include "counterlib.h"


int main()
{
	int i = 0;
	while (1) {
		i = count(i);
		printf("value: %d", i);
		getchar();
	}
    return 0;
}

