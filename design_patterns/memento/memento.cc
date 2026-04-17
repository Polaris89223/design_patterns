#include "memento.h"
std::shared_ptr<Memento> Originator::saveStateToMemento() {
	return std::make_shared<Memento>(state_);
}
void Originator::getStateFromMemento(std::shared_ptr<Memento>memento) {
	state_ = memento->getState();
}
void Originator::printState() {
	std::cout << "Current state: " << state_ << std::endl;
}
void Originator::setState(int newState) {
	state_ = newState;
}
int Originator::getState()const {
	return state_;
}
int Memento::getState() {
	return state_;
}
void Caretaker::add(std::shared_ptr<Memento>memonto) {
	mementoList_.push_back(memonto);
}
std::shared_ptr<Memento> Caretaker::get(int index) {
	return mementoList_.at(index);
}
void testMemento() {
	std::cout << "=================memento start===============" << std::endl;
	//创建发起人对象，初始状态为10
	Originator* originator = new Originator(10);
	Caretaker caretaker; //创建管理者对象

	//保存状态
	originator->printState();
	caretaker.add(originator->saveStateToMemento());

	//改变状态
	originator->setState(20);
	originator->printState();

	//恢复状态
	originator->getStateFromMemento(caretaker.get(0));
	originator->printState();
   
	//释放发起人对象
	delete originator;
	originator = nullptr;
	std::cout << "=================memento end===============" << std::endl;
}