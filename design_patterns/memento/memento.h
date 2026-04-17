#pragma once
/*
备忘录模式（Memento Pattern）
是一种软件设计模式，属于行为型模式。
它主要用于保存一个对象的某个状态，以便在需要时可以恢复到这个状态。
备忘录模式通常用于实现撤销功能，或者在某些情况下，实现对象的快照功能。
备忘录模式涉及三个角色：
Originator（发起人）：创建一个备忘录Memento，用以记录当前时刻的内部状态，并可以使用Memento恢复内部状态。
Memento（备忘录）：负责存储Originator的内部状态，并可以防止外部直接修改这个状态。
Caretaker（管理者）：负责保存好Memento，不能对Memento的内容进行操作或检查，只能进行保存或丢弃。
备忘录模式的典型应用场景包括:
撤销操作：在编辑器中，用户可能希望撤销最近的几次操作。
游戏存档：在游戏过程中，玩家可能希望保存当前进度，以便之后可以继续游戏。
事务处理：在数据库事务中，如果事务失败，需要恢复到事务之前的状态。
*/
#include <vector>
#include <memory>
#include <iostream>
class Memento;
//发起人 类负责创建备忘录，并根据备忘录恢复状态
class Originator {
public:
	Originator(int state) :state_(state) {}
	//创建备忘录
	std::shared_ptr<Memento> saveStateToMemento();
	//恢复状态
	void getStateFromMemento(std::shared_ptr<Memento>memento);

	//打印当前状态
	void printState();
	//用于改变状态的方法
	void setState(int newState);
	//获取当前状态
	int  getState()const;
private:
	int state_;
};

//备忘录类，负责存储发起人的内部状态
class Memento {
public:
	explicit Memento(int state) : state_(state) {}
	int getState();
private:
	int state_;
};

//管理者类，负责保存备忘录
class Caretaker {
public:
	//保存备忘录
	void add(std::shared_ptr<Memento>memonto);
	//根据索引获取备忘录
	std::shared_ptr<Memento> get(int index);
private:
	std::vector<std::shared_ptr<Memento>> mementoList_;
};

void testMemento();

