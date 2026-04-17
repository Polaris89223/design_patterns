#pragma once
#include <iostream>
#include "state.h"
class RaffleActivity;
//发放奖品状态
class DispenseState :public State {
public:
	DispenseState(RaffleActivity*activity);
	void deductMeney() override;
	bool raffle() override;
	//发放奖品
	void dispensePrize() override;
private:
	RaffleActivity* m_activity;
};