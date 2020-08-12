#include "pch.h"

void entry()
{
	std::cout << "[NoSleep] Loaded!\n";
}

THook(void, "?setSleeping@Player@@UEAAX_N@Z", Player* pl, bool bl)
{
	if (bl) {
		LocateS<WLevel>()->broadcastText(u8"§a[NoSleep] " + pl->getNameTag() + u8"正在尝试睡觉，但他火了");
		pl->setOnFire(1000);
	}
	return original(pl, bl);
}