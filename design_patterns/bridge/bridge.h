#pragma once
/*
桥接模式（Bridge Pattern）是一种结构型设计模式，
它将抽象部分与实现部分分离，使它们可以独立地变化。
这种模式通过将一个类的抽象部分与它的实现部分分开，
允许它们可以独立扩展和变化，同时也提供了一种组合的方式来连接抽象部分和实现部分。
在 C++ 中，可以使用类来实现桥接模式。以下是一个简单的示例代码，
演示了如何使用桥接模式来实现不同类型的手机和不同的应用程序：
*/
#include <iostream>
#include <memory>
using namespace std;
//实现层：手机
class Phone {
public:
	virtual void runApp() = 0;
};
//抽象层：应用程序
class App {
public:
	virtual void runOnPhone(Phone*phone) = 0;
};

//具体手机类：华为手机
class HuaWeiPhone :public Phone {
public:
	virtual void runApp()override;
};

//具体手机类：苹果手机
class IPhone :public Phone {
public:
	virtual void runApp()override;
};

//具体的应用程序：微信
class WeChat :public App {
public:
	virtual void runOnPhone(Phone*phone)override;
};

//具体的应用程序：王者荣耀
class WangZheRongYao :public App {
public:
	virtual void runOnPhone(Phone*phone)override;
};

void testBridge();