#pragma once
/*Strategy 模式和 Template 模式要解决的问题是相同（类似）的，都是为了给业务逻辑（算法）具体实现和抽象接口之间的解耦
简而言之,Strategy 模式是对算法的封装。处理一个问题的时候可能有多种算法,这些算法的接口(输入参数,输出参数等)都是一致的,
那么可以考虑采用Strategy 模式对这些算法进行封装,在基类中定义一个函数接口就可以了。
*/
/*假如现在有个英雄需要使用武器对付敌人，武器有两种匕首和AK，那么这么选择使用哪吧武器其实就是一种策略了那么就可以将策略模式分为三部分：
Strategy 策略基类 （抽象武器）
ConcreteStrategy 具体策略 （使用匕首或AK）
Context 具体使用策略的对象（英雄）*/

#include <iostream>
using namespace std;

//抽象武器 策略基类（抽象的策略）
class WeaponStrategy {
public:
	virtual void UseWeapon() = 0;
};

//具体的策略使用匕首做武器
class Knife :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "使用匕首" << endl;
	}
};

//具体的策略 使用AK47做武器
class AK47 :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "使用AK47" << endl;
	}
};
//具体使用策略的角色
class Context
{
public:
	void setWeapon(WeaponStrategy* pWeapon) {
		this->pWeapon = pWeapon;
	}
	void ThrowWeapon() {
		this->pWeapon->UseWeapon();
	}
private:
	WeaponStrategy*  pWeapon = nullptr;
};

void testStrategy();