#pragma once
#include <iostream>
#include "state.h"
#include "canrafflestate.h"
#include "dispenseoutstate.h"
#include "dispensestate.h"
#include "norafflestate.h"
class RaffleActivity {
public:
	RaffleActivity(int count) {
	 //初始化当前状态为 不能抽奖状态
	 this->state = getNoRaffleState();
	 //初始化奖品数量
	 this->count = count;
	}
	//扣分，调用当前状态的deductMoney
	void deductMoney()
	{
	  state->deductMeney();
	}
	//抽奖
	void raffle()
	{
		//如果抽中奖了，则领奖品
		if (state->raffle())
		{
			state->dispensePrize();
		}
	}
	State* getState()const {
		return state;
	}
	void setState(State*const state) {
		this->state = state;
	}
	int getCount() {
		return count--;
	}
	void setCount(const int count) {
		this->count = count;
	}
	State* getNoRaffleState()const {
		return noRaffleState;
	}
	void setNoRaffleState(State* const noRaffleState)
	{
		this->noRaffleState = noRaffleState;
	}
	State* getCanRaffleState() const
	{
		return canRaffleState;
	}
	void setCanRaffleState(State* const canRaffleState)
	{
		this->canRaffleState = canRaffleState;
	}
	State* getDispenseState() const
	{
		return dispenseState;
	}
	void setDispenseState(State* const dispenseState)
	{
		this->dispenseState = dispenseState;
	}
	State* getDispenseOutState() const
	{
		return dispenseOutState;
	}
	void setDispenseOutState(State* const dispenseOutState)
	{
		this->dispenseOutState = dispenseOutState;
	}
private:
	//state表示活动当前的状态
	State* state = nullptr;
	//奖品数量
	int count = 0;
	//四个属性 表示四种状态
	State* noRaffleState = new NoRaffleState(this);
	State* canRaffleState = new CanRaffleState(this);
	State* dispenseState = new DispenseState(this);
	State* dispenseOutState = new DispenseOutState(this);
};
void testState();