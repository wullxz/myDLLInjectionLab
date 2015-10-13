#include <stdio.h>
#include "mod.h"
#include <windows.h>
#include <fcntl.h>
#include <io.h>

void WriteBytesASM(void * destAddress, void * patch);

__stdcall void hello(const char * s) {
	printf("Mod DLL %s loaded!", "mod.dll");
}

void makeSub() {
	void *dst = (void*)0x687814e2;
	byte patch[4] = {0x83, 0x6d, 0x08, 0x01};
	WriteBytesASM((void*)dst, (void*)patch);
}

void makeAdd() {

}

void run() {
	makeSub();
}

void WriteBytesASM(void * destAddress, void * patch)
{
	int numBytes = 4;
	// Store old protection of the memory page
	DWORD oldProtect = 0;

	// Store the source address
	DWORD srcAddress = PtrToUlong(patch);

	// Make sure page is writeable
	VirtualProtect((void*)(destAddress), numBytes, PAGE_EXECUTE_READWRITE, &oldProtect);

	// Do the patch (oldschool style to avoid memcpy)
	memcpy((void*)destAddress, (void*)patch, numBytes);

	// Restore old page protection
	VirtualProtect((void*)(destAddress), numBytes, oldProtect, &oldProtect);
}
