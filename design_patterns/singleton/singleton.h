#pragma once
#include <mutex>
#include <atomic>
/*
Singleton模式（单例模式）
Singleton 模式是设计模式中最为简单、最为常见、最容易实现，也是最应该熟悉和掌握的模式。
Singleton 模式就是一个类只创建一个唯一的对象，即一次创建多次使用。
实现单例模式的步骤：
1、构造函数私有化
2、增加静态私有的当前类的指针变量
3、提供静态对外接口,可以让用户获得单例对象
单例分为懒汉式和饿汉式
懒汉式：解决了饿汉式内存浪费问题，但是线程不安全的，可以通过互斥量mutex.lock()和mutex.unlock()来解决
饿汉式：还没有使用该单例对象，该单例对象就已经被加载到内存了，在对象过多时会造成内存浪费

//懒汉式   对象的创建在第一次调用getInstance函数时创建
//懒汉式是线程不安全的
*/

class singletonlazy {
public:
	static singletonlazy* getInstance();
	static void releaseInstance();
private:
	singletonlazy() {};
	static singletonlazy* psingleton;
	static std::mutex mtx;
};
//饿汉式 对象在程序执行时优先创建
//饿汉式是线程安全的
class singletonhungry {
public:
	static singletonhungry* getInstance();
	static void releaseInstance();
private:
	singletonhungry() {};
	static singletonhungry* psingleton;
};

//C++11 标准实现（DCLP）
class singletonlazyC11 {
public:
	static singletonlazyC11* getInstance();
	static void releaseInstance();
private:
	static std::atomic<singletonlazyC11*> psingleton;
	static std::mutex mtx;

	singletonlazyC11() = default;
	~singletonlazyC11() = default;
	singletonlazyC11(const singletonlazyC11&) = delete;
	singletonlazyC11& operator=(const singletonlazyC11&) = delete;
};


void testSingleton();


