#pragma once
/*
中介者模式（Mediator Pattern）
是软件工程中的一种设计模式，属于行为型模式。
它定义了一个中介对象，用于封装一系列对象之间的交互，使得这些对象不需要显式地相互引用。
通过这种封装，可以降低系统的耦合度，并且使得对象间的关系更加清晰。
在C/C++中实现中介者模式通常包含以下几个步骤：
定义中介者接口：创建一个中介者类，该类包含所有需要协调的对象的引用。
实现中介者类：实现中介者接口，定义协调各个对象交互的方法。
定义同事类：创建一组同事类，这些类需要通过中介者进行通信。
实现同事类：实现同事类，确保每个同事类都持有中介者的引用，并通过中介者与其他同事类进行交互。
场景:在面向对象系统的设计和开发过程中，对象之间的交互和通信是最为常见的情况，因为对象间的交互本身就是一种通信。在系统比较小的时候，
可能对象间的通信不是很多、对象也比较少，我们可以直接硬编码到各个对象的方法中。但是当系统规模变大，对象的量变引起系统复杂度的急剧增
加，对象间的通信也变得越来越复杂，这时候我们就要提供一个专门处理对象间交互和通信的类，这个中介者就是 Mediator 模式
*/
#include <string>
#include <vector>
#include <iostream>
class Colleague;
//定义中介接口类
class Mediator {
public:
	virtual void addColleague(Colleague *colleague) = 0;
	virtual void send(const std::string&msg,Colleague*colleague) = 0;
};
//定义具体的中介类
class ConcreteMediator :public Mediator {
public:
	virtual void send(const std::string&msg, Colleague*colleague);
	virtual void addColleague(Colleague *colleague);
private:
	std::vector<Colleague *> colleagues;
};

//定义同事类接口
class Colleague {
public:
	Colleague(Mediator* m) :mediator(m) {}
	virtual void send(const std::string&msg) = 0;
	virtual void notify(const std::string&msg) = 0;
protected:
	Mediator* mediator;
};

//定义具体的同事类
class ConcreteColleague1 :public Colleague {
public:
	ConcreteColleague1(Mediator* m) :Colleague(m) {}
	virtual void send(const std::string&msg);
	virtual void notify(const std::string&msg);
};

class ConcreteColleague2 :public Colleague {
public:
	ConcreteColleague2(Mediator* m) :Colleague(m) {}
	virtual void send(const std::string&msg);
	virtual void notify(const std::string&msg);
};

void testMediator();