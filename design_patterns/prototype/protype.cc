#include "protoype.h"
concreteprototypeA::concreteprototypeA() {
	cout << "concreteprototypeA" << endl;
}
concreteprototypeA::concreteprototypeA(const concreteprototypeA&) {
	cout << "concreteprototypeA copy" << endl;
}
concreteprototypeA::~concreteprototypeA() {
	cout << "~concreteprototypeA" << endl;
}
prototype* concreteprototypeA::clone() const{
	return new concreteprototypeA(*this);
}
concreteprototypeB::concreteprototypeB() {
	cout << "concreteprototypeB" << endl;
}
concreteprototypeB::concreteprototypeB(const concreteprototypeB&) {
	cout << "concreteprototypeB copy" << endl;
}
concreteprototypeB::~concreteprototypeB() {
	cout << "~concreteprototypeB" << endl;
}
prototype* concreteprototypeB::clone() const {
	return new concreteprototypeB(*this);
}
void testProtoType() {
	cout << "=================prototype start===============" << endl;
	prototype *p1 = new concreteprototypeA();
	prototype *p2 = p1->clone();
	cout << "------------------------" << endl;

	prototype *p3 = new concreteprototypeB();
	prototype *p4 = p3->clone();

	cout << "------------------------" << endl;
	delete p1;
	delete p2;
	cout << "------------------------" << endl;
	delete p3;
	delete p4;
	cout << "=================prototype end===============" << endl;
}