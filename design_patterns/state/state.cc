#include "state.h"
#include "raffleactivity.h"
/*
优点：
1.封装了转换规则。
2.枚举可能的状态，在枚举状态之前需要确定状态种类。
3.将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为。
4.允许状态转换逻辑与状态对象合成一体，而不是某一个巨大的条件语句块。
5.可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数。
*/
void testState() {
	std::cout << "=================state start===============" << std::endl;
	RaffleActivity* activity = new RaffleActivity(1);
	for (int i = 0; i < 50; i++)
	{
		std::cout << "第" << i << "次抽奖" << std::endl;
		activity->deductMoney();
		activity->raffle();
		std::cout << std::endl;
	}
	std::cout << "=================state end===============" << std::endl;
}