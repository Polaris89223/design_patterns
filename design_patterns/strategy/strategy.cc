#include "strategy.h"
void testStrategy() {
	cout << "=================strategy start===============" << endl;
	Context* character = new Context;
	WeaponStrategy* knife = new Knife;
	WeaponStrategy* ak47 = new AK47;

	//用匕首当作武器
	character->setWeapon(knife);
	character->ThrowWeapon();

	//用AK47当作武器
	character->setWeapon(ak47);
	character->ThrowWeapon();

	delete ak47;
	ak47 = nullptr;

	delete knife;
	knife = nullptr;

	delete character;
	character = nullptr;

	cout << "=================strategy end===============" << endl;

}