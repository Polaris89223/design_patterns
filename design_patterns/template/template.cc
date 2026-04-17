#include "template.h"
void testTemplate() {
	cout << "=====Template Begin===================" << endl;
	Tea *tea = new Tea();
	tea->Make();

	Coffee* coffee = new Coffee();
	coffee->Make();

	delete tea;
	tea = nullptr;

	delete coffee;
	coffee = nullptr;
	cout << "=====Template END=====================" << endl;
}