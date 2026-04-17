#include "abstract_factory.h"
#include "abstract_product.h"

//中国工厂
abstract_apple*  china_factory::create_apple() {
	return new china_apple;
}
abstract_banana* china_factory::create_banana() {
	return new china_banana;
}
abstract_pear*   china_factory::create_pear() {
	return new china_pear;
}

//美国工厂
abstract_apple*  usa_factory::create_apple() {
	return new usa_apple;
}
abstract_banana* usa_factory::create_banana() {
	return new usa_banana;
}
abstract_pear*   usa_factory::create_pear() {
	return new usa_pear;
}

//日本工厂
abstract_apple*  japan_factory::create_apple() {
	return new japan_apple;
}
abstract_banana* japan_factory::create_banana() {
	return new japan_banana;
}
abstract_pear*   japan_factory::create_pear() {
	return new japan_pear;
}
void testAbstractFactory() {
	cout << "=====AbstractFactory Begin===================" << endl;
	abstract_factory* factory = nullptr;
	abstract_apple* apple = nullptr;
	abstract_banana* banana = nullptr;
	abstract_pear* pear = nullptr;

	factory = new china_factory;
	apple = factory->create_apple();
	banana = factory->create_banana();
	pear = factory->create_pear();

	apple->showName();
	banana->showName();
	pear->showName();

	delete pear;
	delete banana;
	delete apple;
	delete factory;


	factory = new usa_factory;
	apple = factory->create_apple();
	banana = factory->create_banana();
	pear = factory->create_pear();

	apple->showName();
	banana->showName();
	pear->showName();

	delete pear;
	delete banana;
	delete apple;
	delete factory;


	factory = new japan_factory;
	apple = factory->create_apple();
	banana = factory->create_banana();
	pear = factory->create_pear();

	apple->showName();
	banana->showName();
	pear->showName();

	delete pear;
	delete banana;
	delete apple;
	delete factory;
	cout << "=====AbstractFactory End===================" << endl;
}