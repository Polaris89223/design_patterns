/*Decorator模式（装饰器模式）
 装饰器模式(Decorator Pattern)是一种结构型设计模式，核心目标是在不修改原有类的基础上，
 动态地给对象添加新功能的行为。它通过创建一系列“装饰器”类来包装原始对象，形成一个
 可递归嵌套的对象链，从而实现功能的灵活组合。
 核心原则：对扩展开放，对修改关闭（OCP）。用组合代替继承，避免“子类爆炸”。
*/
#pragma once
#include <string>
#include <memory>
//1.IComponent:抽象接口
class IComponent {
public:
	virtual ~IComponent() = default;
	virtual void operation(std::string&data)const = 0;
};
//2.接口实现
class TextProcessor :public IComponent {
public:
	void operation(std::string&data)const override;
};

//3.Decorator:抽象装饰器基类
class Decorator :public IComponent {
protected:
	std::unique_ptr<IComponent> wrapped_; //被包装的对象
public:
	explicit Decorator(std::unique_ptr<IComponent>comp) :wrapped_(std::move(comp)) {}
	//默认转发，字类可重写
	void operation(std::string&data)const override;
};

//4.ConcreateDecoratorA:添加前缀
class PrefixDecorator :public Decorator {
	std::string prefix_;
public:
	PrefixDecorator(std::unique_ptr<IComponent>comp, std::string prefix)
		:Decorator(std::move(comp)), prefix_(prefix) {}
	void operation(std::string&data)const override;
};

//5.ConcreateDecoratorB:反转字符串
class ReverseDecorator :public Decorator {
public:
	//使用基类构造函数
	using Decorator::Decorator;
	void operation(std::string&data)const override;
};

//6:统计长度装饰器
class LengthStateDecorator :public Decorator {
public:
	using Decorator::Decorator;
	void operation(std::string&data)const override;
};

void testDecorator();