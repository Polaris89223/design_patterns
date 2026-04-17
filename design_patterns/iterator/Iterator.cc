#include "Iterator.h"
#include <memory>
Iterator* ConcreteAggregate::createIterator() {
	return new ConcreteIterator(this);
}
int ConcreteAggregate::getSize()const{
	return 5;
}
int ConcreteAggregate::getItem(int index)const{
	return item[index];
}
void ConcreteIterator::first() {
	m_current = 0;
}
void ConcreteIterator::next() {
	m_current++;
}
bool ConcreteIterator::isDone() {
	return m_current >= m_aggregate->getSize();
}
int ConcreteIterator::currentItem() {
	return m_aggregate->getItem(m_current);
}
void testIterator() {
	cout << "=================Iterator begin===============" << endl;
	std::shared_ptr<Aggregate> aggregate = std::make_shared<ConcreteAggregate>();
	Iterator* iterator = aggregate->createIterator();

	while (!iterator->isDone())
	{
		cout << iterator->currentItem() << " ";
		iterator->next();
	}
	cout << endl;
	cout << "=================Iterator end===============" << endl;
}