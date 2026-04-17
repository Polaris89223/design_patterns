#pragma once
/*原型(Prototype)模式
是用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
思想：克 隆一个已有的类的实例（大家相比都用过甚至写过类的Clone实现，应该很容易理解了）。
场景：应用Clone的场景应该说非常多，理想情况下我当然希望任何类都能Clone， 需要的时候就能Clone一份一模一样的出来。
实现：这里将的实现主要之实现的表现形式，而不是如何用具体的语言来实现。因此，只要为需要Clone能力 的类定义一个Clone方法就行。
当然，一般，主流的程序语言框架都已经定义了通用的Clone接 口（当然也可以自己定义），继承并实现该接口和方法就好。
实例：Prototype模式提供了一个通过已存在对象进行新对象创建的接口（Clone）， Clone()实现和具体的语言相关，在C++中通过拷贝构造函数实现。
*/
#include <iostream>
using namespace std;
class prototype {
public:
	virtual prototype* clone() const = 0;
};
class concreteprototypeA:public prototype {
public:
	concreteprototypeA();
	concreteprototypeA(const concreteprototypeA&);
	virtual ~concreteprototypeA();
	virtual prototype* clone()const;
};
class concreteprototypeB :public prototype {
public:
	concreteprototypeB();
	concreteprototypeB(const concreteprototypeB&);
	virtual ~concreteprototypeB();
	virtual prototype* clone()const;
};
void testProtoType();
