#include <stdio.h>
#include "mod.h"

__stdcall void hello(const char * s) {
	printf("Mod DLL %s loaded!", "mod.dll");
}

void makeSub() {

}

void makeAdd() {

}
