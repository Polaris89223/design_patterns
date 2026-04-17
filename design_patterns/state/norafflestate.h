#pragma once
#include <iostream>
#include "state.h"
class RaffleActivity;
//不能抽奖状态
class NoRaffleState :public State {
public:
	NoRaffleState(RaffleActivity* activity);
	//在不能抽奖状态是可以扣积分的，扣除积分后设置成可以抽奖状态
	void deductMeney() override;
	bool raffle() override;
	void dispensePrize() override;
private:
	RaffleActivity* m_activity;
};