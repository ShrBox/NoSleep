#include "pch.h"

void entry()
{
	std::cout << "[NoSleep] Loaded!\n";
}

THook(void, "?setSleeping@Player@@UEAAX_N@Z",void* pl, bool bl)
{
	if (bl) {
		SymCall("?setOnFire@Actor@@UEAAXH@Z", void, void*, int)(pl, 1000);
	}
	return original(pl, bl);
}