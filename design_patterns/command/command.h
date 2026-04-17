#pragma once
/*
命令模式（Command Pattern）
是一种行为设计模式，它将一个请求封装为一个对象，从而允许用户使用不同的请求、队列或日志请求来参数化其他对象。
命令模式也支持可撤销的操作。它通常用于将调用操作的对象与知道如何实现该操作的对象解耦。
在C/C++中实现命令模式，你可以遵循以下步骤：
定义命令接口：一个接口，定义了一个执行操作的方法，通常叫做 execute。
实现具体命令：创建实现了命令接口的具体类，这些类包含了对特定操作的调用。
定义客户端：客户端是一个创建和配置命令对象的对象，然后将其传递给请求者。
请求者：请求者是一个知道如何去执行命令的对象，它通常持有一个命令对象的引用或指针。
调用对象：这是实际执行操作的对象，它可能由具体命令内部使用。
可选 - 引入撤销机制：如果需要，可以为命令添加撤销操作
例子:
假如现在有一个游戏服务器，该游戏服务器一共可以处理四种不同的请求：处理增加金币、处理增加钻石、处理玩家装备、玩家升级请求。
我们需要把这些请求封装成对象，从而加入请求队列一次进行处理。
*/
#include <iostream>
#include <queue>
#include <memory>
using namespace std;
class Request{
public:
	//处理增加金币
	void AddMoney()
	{
		cout << "给玩家增加金币" << endl;
	}
	//处理增加钻石
	void AddDiamond()
	{
		cout << "给玩家增加钻石" << endl;
	}
	//处理玩家装备
	void AddEquipment()
	{
		cout << "给玩家穿装备" << endl;
	}
	//玩家升级
	void AddLevel()
	{
		cout << "给玩家升级" << endl;
	}
};
//定义命令接口类
class AbstractCommand {
public:
	virtual void excute()=0;
};
//下面是把每一个请求封装为一个请求对象
//处理增加金币请求
class AddMoneyCommand :public AbstractCommand {
public:
	AddMoneyCommand(std::shared_ptr<Request> request) :m_request(std::move(request)) {};
	virtual void excute();
private:
	std::shared_ptr<Request> m_request;
};

//处理增加组钻石请求
class AddDiamondCommand :public AbstractCommand {
public:
	AddDiamondCommand(std::shared_ptr<Request> request) :m_request(std::move(request)) {};
	virtual void excute();
private:
	std::shared_ptr<Request> m_request;
};

//处理增加玩家装备请求
class AddEquitmentCommand :public AbstractCommand {
public:
	AddEquitmentCommand(std::shared_ptr<Request> request) :m_request(std::move(request)) {};
	virtual void excute();
private:
	std::shared_ptr<Request> m_request;
};

//处理玩家升级请求
class AddLevelCommand :public AbstractCommand {
public:
	AddLevelCommand(std::shared_ptr<Request> request) :m_request(std::move(request)) {};
	virtual void excute();
private:
	std::shared_ptr<Request> m_request;
};

//服务器程序(命令调用类)
class Server {
public:
	//将请求对象放入处理队列
	void addRequest(std::shared_ptr<AbstractCommand>command);
	//启动处理程序
	void startExcute();
private:
	queue<std::shared_ptr<AbstractCommand> > m_commands;
};

void testCommand();