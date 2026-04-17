#include "norafflestate.h"
#include "raffleactivity.h"
NoRaffleState::NoRaffleState(RaffleActivity* activity) {
	m_activity = activity;
}
//在不能抽奖状态是可以扣积分的，扣除积分后设置成可以抽奖状态
void NoRaffleState::deductMeney(){
	std::cout << "扣除50积分，可以抽奖了" << std::endl;
	m_activity->setState(m_activity->getCanRaffleState());
}
bool NoRaffleState::raffle(){
	std::cout << "扣了积分才能抽奖" << std::endl;
	return false;
}
void NoRaffleState::dispensePrize(){
	std::cout << "不能发放奖品" << std::endl;
}