#pragma once
/*
在面向对象系统的分析与设计过程中经常会遇到这样一种情况：对于某一个业务逻辑（算法实现）在不同的对象中有不同的细节实现，
但是逻辑（算法）的框架（或通用的应用算法）是相同的。Template 提供了这种情况的一个实现框架。Template 模式是采用继承的
方式实现这一点：将逻辑（算法）框架放在抽象基类中，并定义好细节的接口，子类中实现细节
*/
/*
例子:假如我们要做饮料，那么我们首先会定义一个做饮料的模板，即煮水->冲泡->导入杯中->加辅助材料，
具体煮什么水、冲泡什么东西放到子类中实现。然后定义一个模板方法，当我们要做饮料时就调用这个方法即可。
*/
/*
模板方法模式:在父类中定义一个方法的抽象，由它的子类来实现细节的处理，在子类实现详细的处理算法时并不会改变算法中的执行次序。
*/
#include <iostream>
using namespace std;

//做饮料的模版
class DrinkTemplate
{
public:
	//煮水
	virtual void BoilWater() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加入辅助材料
	virtual void AddSomething() = 0;
	//模版方法
	void Make() {
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

//做咖啡 实现做饮料模版
class Coffee :public DrinkTemplate {
public:
	virtual void BoilWater() {
		cout << "煮山泉水" << endl;
	}
	virtual void Brew() {
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup() {
		cout << "咖啡倒入杯中" << endl;
	}
	virtual void AddSomething() {
		cout << "加糖，加牛奶" << endl;
	}
};

//作茶 实现做饮料模版
class Tea :public DrinkTemplate {
public:
	virtual void BoilWater() {
		cout << "煮自来水" << endl;
	}
	virtual void Brew() {
		cout << "冲泡菊花" << endl;
	}
	virtual void PourInCup() {
		cout << "茶水倒入杯中" << endl;
	}
	virtual void AddSomething() {
		cout << "加糖，加黑枸杞" << endl;
	}
};

void testTemplate();