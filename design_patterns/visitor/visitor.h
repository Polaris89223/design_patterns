#pragma once
/*
Visitor 模式（访问者模式）
- 访问者模式（VisitorPattern），封装一些作用于某种数据结构的各元素的操作，它可以在不改变
数据结构的前提下定义作用于这些元素的新的操作。
- 主要将数据结构与数据操作分离，解决 数据结构和操作耦合性问题
- 访问者模式的基本工作原理是：在被访问的类里面加一个对外提供接待访问者的接口
- 访问者模式主要应用场景是：需要对一个对象结构中的对象进行很多不同操作(这些操作彼此没有关联)，
同时需要避免让这些操作"污染"这些对象的类，可以选用访问者模式解决
特别适用于当你需要对一个对象集合执行多种不同的操作，而又不想在每个对象类中都添加这些操作时。
核心概念：
Visitor（访问者）：定义了一个访问者接口，声明了对每一个元素类访问的方法。
ConcreteVisitor（具体访问者）：实现Visitor接口，为每一个元素类提供相应的处理。
Element（元素）：定义了一个接受访问者的接口。
ConcreteElement（具体元素）：实现Element接口，为访问者提供接收访问的方法。
ObjectStructure（对象结构）：是一个包含元素的容器，可以遍历元素，允许访问者访问每一个元素。
应用场景：
当一个对象结构中的对象需要执行多种不同的操作，而这些操作可能在未来会不断增加时。
当这些操作与对象结构中的对象有紧密的耦合关系，但又能独立于对象结构变化时
示例：
假设我们有一个简单的文档编辑器，它包含不同类型的元素，如Paragraph和Header。我们希望添加一个功能，可以访问这些元素并执行某些操作。

在这个示例中，我们定义了一个Visitor接口，它有两个纯虚函数visit，分别用于访问Paragraph和Header对象。ConcreteVisitor类实现了Visitor接口，
并为每种元素提供了具体的操作。Element是一个抽象基类，它定义了一个accept方法，这个方法接受一个Visitor对象。Paragraph和Header类继承自
Element，并实现了accept方法，该方法调用访问者的visit方法。Document类是一个对象结构，它包含一个元素列表，并且有一个accept方法，该方法
遍历所有元素并调用它们的accept方法。最后，在main函数中，我们创建了一个Document对象，添加了一些元素，并使用ConcreteVisitor来访问这些
元素。这个示例展示了如何在C++中使用Visitor模式来对一个对象结构中的元素执行不同的操作，而不需要修改这些元素的类。
*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Paragraph;
class Header;
class Visitor {
public:
	~Visitor() {};
	virtual void visit(Paragraph*p) = 0;
	virtual void visit(Header*h) = 0;
};
//定义具体的访问者
class ConcreteVisitor :public Visitor {
public:
	void visit(Paragraph*p);
	void visit(Header*h);
};

//定义元素接口
class Element {
public:
	virtual ~Element() {};
	virtual void accept(Visitor*v) = 0;
};
class Paragraph :public Element {
public:
	Paragraph(const string&content) :m_content(content) {};
	void accept(Visitor*v);
	string getContent()const;
private:
	string m_content;
};
class Header :public Element {
public:
	Header(const string&content) :m_content(content) {};
	void accept(Visitor*v);
	string getContent()const;
private:
	string m_content;
};
//定义对象结构
class Document{
public:
	void addElement(std::unique_ptr<Element>elem);
	void accept(Visitor*v);
private:
	vector<std::unique_ptr<Element> > m_elements;
};
void testVisitor();