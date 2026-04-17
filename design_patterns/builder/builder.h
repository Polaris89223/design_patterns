#pragma once
/*
Builder 模式（建造者模式）
建造者模式：一种创建型设计模式
应用场景：
某类对象的构建过程由多步组成，各步执行细节一直变化，但是所有步骤间的组合关系不变
举例：
要画一个图形，分为画形状和填色两步，这两步固定不会变，但是具体画的形状与颜色会随着需求而经常变化。
每次形状与颜色的需求变更时，为了不更改原本类的代码，而是通过扩展新类的方式完成，可以通过构建一个建造者，
该建造者只能满足某次需求的要求构建出图形（类似于特定的画笔，只能画出来绿色圆或红色三角），然后在需求变更时
扩展出一个新的建造者即可。
实现方式：
首先，构建要被构造出来的图形类，并向外部提供能修改该图形类各组成部分的接口；
然后，构建建造者的抽象类，所有派生的建造者根据自身作用重写接口，返回不同的图形对象；
最后，构建一个导演类，导演类对象可根据设定的不同构建者，获得不同的图形对象。
优点：
将一个复杂对象的构建与它的表示分离，相同的构建过程可以创建不同的表示。
有新的表示可以遵循开放封闭原则，扩展新的类代码完成需求
缺点：
如果构建步骤发生添加或删除，所有建造者类都需要更改代码
*/
#include <iostream>
#include <string>
using namespace std;
//要构建的对象
class graphic {
public:
	graphic() {};
	//常变属性设置接口
	void setShape(const string&shape);
	void setColor(const string&color);
	void show();
private:
	string m_shape;
	string m_color;
};
//建造者抽象类
class builder {
public:
	builder() :m_pgraphic(nullptr) {};
	//创建空白图像对象
	void createGraphic();
	graphic* getGraphic();
	// 留给派生类实现的描绘过程
	virtual void drawShape() = 0;
	virtual void drawColor() = 0;
protected:
	graphic* m_pgraphic;
};

class greencirclebuilder : public builder {
public:
	virtual void drawShape();
	virtual void drawColor();
};

class redrectanglebuilder : public builder {
public:
	virtual void drawShape();
	virtual void drawColor();
};

class bluetrianglebuilder : public builder {
public:
	virtual void drawShape();
	virtual void drawColor();
};
//导演类
class director {
public:
	director() :m_pbuilder(nullptr) {};
	// 根据需求设置对应的建造者
	void setBuilder(builder& pBuilder);
	// 通过建造者获得描绘完成的图形
	graphic* drawGraphic();
private:
	builder* m_pbuilder;
};
void testBuilder();