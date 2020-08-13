#include "pch.h"

void entry()
{
	std::cout << "[NoSleep] Loaded!\n";
}

THook(void, "?setSleeping@Player@@UEAAX_N@Z", Player* pl, bool bl)
{
	if (bl) {
		pl->setOnFire(1000);
		LocateS<WLevel>()->broadcastText(pl->getNameTag() + u8" 正在尝试睡觉，但他着火了");
	}
	return original(pl, bl);
}