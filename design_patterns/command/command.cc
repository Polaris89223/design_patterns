#include "command.h"
#include <thread>
void AddMoneyCommand::excute() {
	m_request->AddMoney();
}
void AddDiamondCommand::excute() {
	m_request->AddDiamond();
}
void AddEquitmentCommand::excute() {
	m_request->AddEquipment();
}
void AddLevelCommand::excute() {
	m_request->AddLevel();
}
//将请求对象放入处理队列
void Server::addRequest(std::shared_ptr<AbstractCommand>command) {
	m_commands.push(command);
}
//启动处理程序
void Server::startExcute() {
	while (!m_commands.empty())
	{
		std::shared_ptr<AbstractCommand> command = std::move(m_commands.front());
		std::this_thread::sleep_for(std::chrono::seconds(2));
		command->excute();
		m_commands.pop();
	}
}
void testCommand() {
	cout << "=================command start===============" << endl;
	std::shared_ptr<Request> request = std::make_shared<Request>();
	//客户端增加金币的请求
	std::shared_ptr<AddMoneyCommand> addmoney = std::make_shared<AddMoneyCommand>(std::move(request));
	//客户端增加钻石的请求
	std::shared_ptr<AddDiamondCommand>addiamond = std::make_shared<AddDiamondCommand>(std::move(request));
	//客户端增加装备的请求
	std::shared_ptr<AddEquitmentCommand> addquitment = std::make_shared<AddEquitmentCommand>(std::move(request));
	//客户端升级的请求
	std::shared_ptr<AddLevelCommand> addlevel = std::make_shared<AddLevelCommand>(std::move(request));

	//将客户端的请求加入到请求队列中
	std::shared_ptr<Server> server = std::make_shared<Server>();
	server->addRequest(std::move(addmoney));
	server->addRequest(std::move(addiamond));
	server->addRequest(std::move(addquitment));
	server->addRequest(std::move(addlevel));

	//服务器开始处理请求
	server->startExcute();

	cout << "=================command end===============" << endl;
}