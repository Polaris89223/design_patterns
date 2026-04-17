#include "dispensestate.h"
#include "raffleactivity.h"

DispenseState::DispenseState(RaffleActivity*activity) {
	m_activity = activity;
}
void DispenseState::deductMeney(){
	std::cout << "不能扣除积分" << std::endl;
}
bool DispenseState::raffle(){
	std::cout << "不能抽奖了" << std::endl;
	return false;
}
//发放奖品
void DispenseState::dispensePrize(){
	if (m_activity->getCount() > 0)
	{
		std::cout << "送出奖品" << std::endl;
		m_activity->setState(m_activity->getNoRaffleState());
	}
	else
	{
		std::cout << "很遗憾,奖品发完了" << std::endl;
		//奖品已经发完，后面的人就不能抽奖了
		m_activity->setState(m_activity->getDispenseOutState());
	}
}