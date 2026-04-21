/*Proxy模式（代理模式）
 代理模式（Proxy Pattern）属于结构型设计模式，核心是为其他对象提供一种代理（替身）
 来控制对这个对象的访问。代理在客户端和目标对象之间起中介作用，用于控制访问、
 延迟加载、日志监控、安全校验等，不改变目标对象的功能本身。
 核心区别vs装饰器：装饰器是增强功能（加逻辑），代理是控制访问（管入口）
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//抽象接口类
class ISubject {
public:
	virtual ~ISubject() = default;
	virtual string request(const string& input)const =0;
};

//真实服务：模拟耗时资源加载
class HeavyDatabaseService :public ISubject {
public:
	string request(const string& input)const override;
};

//代理
class LazyCacheProxy :public ISubject {
private:
	mutable std::unique_ptr<HeavyDatabaseService> realService_;
	mutable std::string cacheResult_;
	mutable bool hasCache_;
	std::string authToken_;
private:
	bool validateAccess()const;
	void logCall(const string&callerInfo)const;
public:
	explicit LazyCacheProxy(const string&token) :hasCache_(false), authToken_(token) {}
	string request(const string&input)const override;
};
void testDirect();
void testInvalidProxy();
void testValidProxy();
void testProxy();