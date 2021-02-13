#include "pch.h"

void entry()
{
	std::cout << "[NoSleep] Loaded!\n";
}

THook(void, "?setSleeping@Player@@UEAAX_N@Z",Player* pl, bool bl)
{
	if (bl) {
		pl->setOnFire(1000);
	}
	return original(pl, bl);
}