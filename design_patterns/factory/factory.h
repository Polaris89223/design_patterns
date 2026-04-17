#pragma once
/*Fatory模式（工厂模式）
在面向对象系统设计中经常可以遇到以下的两类问题：
- 我们经常会抽象出一些类的公共接口以形成抽象基类或者接口。这样我们可以通过声明一个指向基类的指针来指向实际的子类实现，
达到了多态的目的。所以就不得不在要用到子类的地方写new 对象。这样实体类的使用者必须知道实际的子类名称，以及会使程序的
扩展性和维护变得越来越困难。
- 还有一种情况就是在父类中并不知道具体要实例化哪一个具体的子类。只能在父类中写方法调用，具体调用哪一个类的方法交给子类实现。
以上两个问题也就引出了 Factory 模式的两个最重要的功能：
1）定义创建对象的接口，封装了对象的创建。
2）使得具体化类的工作延迟到了子类中。
*/
class Product;
class Factory{
public:
	virtual ~Factory() = default;
	//工厂方法
	virtual Product* createProduct() = 0;
};
class ConcreateFactoryA :public Factory
{
public:
	ConcreateFactoryA()=default;
	virtual ~ConcreateFactoryA()=default;
	Product* createProduct() override;
};
class ConcreateFactoryB:public Factory
{
public:
	ConcreateFactoryB() = default;
	virtual ~ConcreateFactoryB() = default;
	Product* createProduct() override;
};


void testFactory();