#include "canrafflestate.h"
#include "raffleactivity.h"
CanRaffleState::CanRaffleState(RaffleActivity*activity) {
	srand(time(NULL));
	m_activity = activity;
}
//已经扣除积分了，不能再扣了
void CanRaffleState::deductMeney(){
	std::cout << "已经扣过积分了" << std::endl;
}
//可以抽奖，根据抽奖情况改成新的状态
bool CanRaffleState::raffle(){
	std::cout << "正在抽奖..." << std::endl;
	int result = rand() % 10;
	if (!result) {
		//将activity的状态设置为发放奖品的状态
		m_activity->setState(m_activity->getDispenseState());
		return true;
	}
	else {
		std::cout << "很遗憾没有抽中奖品" << std::endl;
		//将activity的状态设置为不能抽奖的状态
		m_activity->setState(m_activity->getNoRaffleState());
		return false;
	}
}
void CanRaffleState::dispensePrize(){
	std::cout << "没中奖,不能发放奖品" << std::endl;
}