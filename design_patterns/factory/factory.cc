#include "factory.h"
#include "product.h"
#include <iostream>
using namespace std;
Product* ConcreateFactoryA::createProduct() {
	return new ConcreateProductA();
}

Product* ConcreateFactoryB::createProduct(){
	return new ConcreateProductB();
}

void testFactory() {
	cout << "=================factory begin===============" << endl;
	Factory* fac = new ConcreateFactoryA();
	Product* proA = fac->createProduct();
	proA->productInfo();
	if (nullptr != proA) {
		delete proA;
		proA = nullptr;
	}
	if (nullptr != fac) {
		delete fac;
		fac = nullptr;
	}

	fac = new ConcreateFactoryB();
	Product* proB = fac->createProduct();
	proB->productInfo();
	if (nullptr != proB) {
		delete proB;
		proB = nullptr;
	}
	if (nullptr != fac) {
		delete fac;
		fac = nullptr;
	}
	cout << "=================factory end===============" << endl;
}