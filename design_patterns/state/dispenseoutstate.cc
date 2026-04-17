#include "dispenseoutstate.h"
#include "raffleactivity.h"
DispenseOutState::DispenseOutState(RaffleActivity*activity) {
	m_activity = activity;
}
void DispenseOutState::deductMeney(){
	std::cout << "奖品已经发完了，请下次参加" << std::endl;
}
bool DispenseOutState::raffle(){
	std::cout << "奖品已经发完了，请下次参加" << std::endl;
	return false;
}
void DispenseOutState::dispensePrize(){
	std::cout << "奖品已经发完了，请下次参加" << std::endl;
}