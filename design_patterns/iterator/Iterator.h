#pragma once
/*Iterator 模式（迭代器模式)
迭代器模式是一种设计模式，它提供了一种方法来顺序访问一个聚合对象中的各个元素，而又不需要暴露该对象的内部表示
总结：
- 提供一个统一的方法遍历对象，客户不用再考虑聚合的类型，使用一种方法就可以遍历对象了。
- 隐藏了聚合的内部结构，客户端要遍历聚合的时候只能取到迭代器，而不会知道聚合的具体组成。
- 提供了一种设计思想，就是一个类应该只有一个引起变化的原因（叫做单一责任原则）。在聚合类中，我们把迭代器分开，就是要把管理对象集合和遍历对象集合的责任分开，这样一来集合改变的话，只影响到聚合对象。而如果遍历方式改变的话，只影响到了迭代器。
- 当要展示一组相似对象，或者遍历一组相同对象时使用, 适合使用迭代器模式
*/
#include <iostream>
using namespace std;
//抽象的迭代器类
class Iterator {
public:
	virtual ~Iterator() {};
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual int  currentItem() = 0;
};
//抽象聚合类
class Aggregate {
public:
	virtual ~Aggregate() {};
	virtual Iterator* createIterator() = 0;
};

//具体聚合类
class ConcreteIterator;
class ConcreteAggregate :public Aggregate {
public:
	ConcreteAggregate() {
		for (size_t i = 0; i < 5; i++)
		{
			item[i] = i;
		}
	}
	Iterator* createIterator()override;
	int getSize()const;
	int getItem(int index)const;
private:
	int item[5];
};

//具体迭代器
class ConcreteIterator :public Iterator {
public:
	ConcreteIterator(ConcreteAggregate*a):m_aggregate(a), m_current(0) {}
	virtual void first() override;
	virtual void next() override;
	virtual bool isDone() override;
	virtual int currentItem()override;
private:
	ConcreteAggregate* m_aggregate;
	int m_current;
};
void testIterator();