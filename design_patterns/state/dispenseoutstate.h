#pragma once
#include <iostream>
#include "state.h"
class RaffleActivity;
//奖品发放完毕状态
class DispenseOutState :public State {
public:
	DispenseOutState(RaffleActivity*activity);
	void deductMeney() override;
	bool raffle() override;
	void dispensePrize() override;
private:
	RaffleActivity* m_activity;
};