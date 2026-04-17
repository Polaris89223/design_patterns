#include "observer.h"
void testObserver() {
	cout << "=================observer start===============" << endl;
	//创建观察者
	AbstractHero* heroA = new HeroA();
	AbstractHero* heroB = new HeroB();
	AbstractHero* heroC = new HeroC();
	AbstractHero* heroD = new HeroD();
	AbstractHero* heroE = new HeroE();

	//创建观察目标
	AbstractBoss* bossA = new BOSSA();
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);

	cout << "heroC阵亡" << endl;
	bossA->removeHero(heroC);

	cout << "Boss死了,通知其他英雄停止攻击..." << endl;
	bossA->notify();

	cout << "=================observer end===============" << endl;
}
