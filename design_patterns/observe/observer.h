#pragma once
/*Observer 模式(观察者模式)
Observer 模式要解决的问题为：建立一个一（Subject）对多（Observer）的依赖关系，并且做到当“一”变化的时候，
依赖这个“一”的多也能够同步改变。最常见的一个例子就是：对同一组数据进行统计分析时候，我们希望能够提供多
种形式的表示（例如以表格进行统计显示、柱状图统计显示、百分比统计显示等）。指多个对象间存在一对多的依赖关系，
当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。
发布订阅模式是观察者模式演变而来，加入了主题队列
举例：
Subject 提供依赖于它的观察者 Observer 的注册（registerObserver）和注销（remove）操作，
并且提供了使得依赖于它的所有观察者同步的操作（notifyObserver），观察者 Observer 则提供一个 Update 操作，
注意这里的 Observer 的 Update 操作并不在 Observer 改变了 Subject 目标状态的时候就对自己进行更新，
这个更新操作要延迟到 Subject 对象发出 Notify 通知所有Observer 进行修改（调用 Update）。
*/
#include <iostream>
#include <list>
using namespace std;

//抽象的英雄 抽象的观察者  Observer
class AbstractHero{
public:
	virtual void Update() = 0;
};

//具体的英雄 具体的观察者
class HeroA :public AbstractHero {
public:
	HeroA() {
		cout << "英雄A正在鲁BOSS" << endl;
	}
	virtual void Update() {
		cout << "英雄A停止鲁,待机状态" << endl;
	}
};
class HeroB :public AbstractHero {
public:
	HeroB() {
		cout << "英雄B正在鲁BOSS" << endl;
	}
	virtual void Update() {
		cout << "英雄B停止鲁,待机状态" << endl;
	}
};
class HeroC :public AbstractHero {
public:
	HeroC() {
		cout << "英雄C正在鲁BOSS" << endl;
	}
	virtual void Update() {
		cout << "英雄C停止鲁,待机状态" << endl;
	}
};
class HeroD :public AbstractHero {
public:
	HeroD() {
		cout << "英雄D正在鲁BOSS" << endl;
	}
	virtual void Update() {
		cout << "英雄D停止鲁,待机状态" << endl;
	}
};
class HeroE :public AbstractHero {
public:
	HeroE() {
		cout << "英雄E正在鲁BOSS" << endl;
	}
	virtual void Update() {
		cout << "英雄E停止鲁,待机状态" << endl;
	}
};

//定义抽象的观察目标  Subject
class AbstractBoss
{
public:
	//添加观察者 对象
	virtual void addHero(AbstractHero*hero) = 0;
	//移除观察者 对象
	virtual void removeHero(AbstractHero*hero) = 0;
	//通知所有观察者对象
	virtual void notify() = 0;
};

//相当于 concreteSubject
class BOSSA:public AbstractBoss
{
public:
	//添加观察者 对象
	virtual void addHero(AbstractHero*hero) {
		pHeroList.emplace_back(hero);
	}
	//移除观察者 对象
	virtual void removeHero(AbstractHero*hero) {
		pHeroList.remove(hero);
	}
	//通知所有观察者对象
	virtual void notify() {
		for (auto iter = pHeroList.begin(); iter != pHeroList.end(); ++iter) {
			(*iter)->Update();
		}
	}

private:
	list<AbstractHero*> pHeroList;
};

void testObserver();
