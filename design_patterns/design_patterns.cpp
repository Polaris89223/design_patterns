// design_patterns.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "observe/observer.h"
#include "strategy/strategy.h"
#include "template/template.h"
#include "state/state.h"
#include "factory/factory.h"
#include "abstract_factory/abstract_factory.h"
#include "singleton/singleton.h"
#include "builder/builder.h"
#include "prototype/protoype.h"
#include "memento/memento.h"
#include "mediator/mediator.h"
#include "command/command.h"
#include "visitor/visitor.h"
#include "chain/chain.h"
#include "iterator/Iterator.h"
#include "interpreter/interpreter.h"
#include "bridge/bridge.h"
#include "adapter/adapter.h"
#include "Decorator/Decorator.h"
#include "proxy/Proxy.h"
#include "facade/facade.h"
#include "composite/composite.h"
#include "flyweight/flyweight.h"
int main()
{
    ///=====================创建型模式====================================
	//测试工厂模式
	testFactory();

	//测试抽象工厂模式
	testAbstractFactory();
	  
	//测试单例模式
	testSingleton();

	//测试建造者模式
	testBuilder();

	//测试原型模式
	testProtoType();

	//====================================结构型模式==================================

	//测试适配器模式
	testAapter();

	//测试装饰器模式
	testDecorator();

	//测试代理模式
	testProxy();

	//测试外观模式
	testFacade();

	//测试组合模式
	testComposite();

	//测试桥接模式
	testBridge();

	//测试享元模式
	testFlyWeight();

	//====================================行为型模式==================================

    //测试观察者模式
	testObserver();

	//测试策略模式
	testStrategy();

	//测试模版模式
	testTemplate();

	//测试状态模式
	testState();

	//测试备忘录模式
	testMemento();

	//测试中介者模式
	testMediator();

	//测试命令模式
	testCommand();

	//测试访问者模式
	testVisitor();

	//测试责任链模式
	testChainOfResponsibility();

	//测试迭代器模式
	testIterator();

	//测试解释器模式
	testInterPreter();


	getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
