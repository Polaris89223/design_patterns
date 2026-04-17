#pragma once
/*
适配器模式是一种结构型设计模式，它将一个类的接口转换成客户期望的另一个接口。
适配器模式使得原本由于接口不兼容而不能一起工作的类可以一起工作。
适配器模式分为类模式和对象模式

*/
#include <iostream>
using namespace std;
//目标接口
class Target {
public:
	virtual void Request() = 0;
};

//待适配的类
class Adaptee {
public:
	void specificRequest();
};

//适配器类
class Adapter :public Target {
private:
	Adaptee* adaptee_;
public:
	Adapter(Adaptee* adaptee) :adaptee_(adaptee) {};
	void Request()override;
};

void testAapter();