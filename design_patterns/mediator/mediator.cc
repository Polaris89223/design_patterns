#include "mediator.h"
void ConcreteMediator::send(const std::string&msg, Colleague*colleague) {
	for (auto c : colleagues) {
		if (c != colleague) // 不向自己发送消息
			c->notify(msg);
	}
}
void ConcreteMediator::addColleague(Colleague *colleague) {
	colleagues.emplace_back(colleague);
}
void ConcreteColleague1::send(const std::string&msg) {
	mediator->send(msg, this);
}
void ConcreteColleague1::notify(const std::string&msg) {
	std::cout << "ConcreteColleague1 received: " << msg << std::endl;
}

void ConcreteColleague2::send(const std::string&msg) {
	mediator->send(msg, this);
}
void ConcreteColleague2::notify(const std::string&msg) {
	std::cout << "ConcreteColleague2 received: " << msg << std::endl;
}
void testMediator() {
	std::cout << "=================mediator start===============" << std::endl;
	Mediator*        mediator = new  ConcreteMediator();
	ConcreteColleague1* c1 = new ConcreteColleague1(mediator);
	ConcreteColleague2* c2 = new ConcreteColleague2(mediator);

	mediator->addColleague(c1);
	mediator->addColleague(c2);

	c1->send("Hello");
	c2->send("World");

	delete c1;
	c1 = nullptr;
	delete c2;
	c2 = nullptr;

	delete mediator;
	mediator = nullptr;
	std::cout << "=================mediator end===============" << std::endl;
}