#include "adapter.h"
void Adaptee::specificRequest(){
	cout << "Adaptee's specific request." << endl;
}
void Adapter::Request() {
	adaptee_->specificRequest();
}

void testAapter() {
	cout << "=================Aapter begin===============" << endl;
	Adaptee* adaptee = new Adaptee();
	Adapter* adapter = new Adapter(adaptee);
	adapter->Request();
	delete adaptee;
	delete adapter;
	cout << "=================Aapter end===============" << endl;
}