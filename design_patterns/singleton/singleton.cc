#include "singleton.h"
#include <iostream>
using namespace std;
singletonlazy* singletonlazy::psingleton = nullptr;
std::mutex singletonlazy::mtx;
singletonlazy* singletonlazy::getInstance() {
	if (nullptr == psingleton) {
		std::lock_guard<std::mutex> lock(mtx);
		if (nullptr == psingleton) {
			psingleton = new singletonlazy();
		}
	}
	return psingleton;
}
void singletonlazy::releaseInstance() {
	if (nullptr != psingleton) {
		delete psingleton;
		psingleton = nullptr;
	}
}

singletonhungry* singletonhungry::psingleton = new singletonhungry();
singletonhungry* singletonhungry::getInstance() {
	return psingleton;
}
void singletonhungry::releaseInstance() {
	if (nullptr != psingleton) {
		delete psingleton;
		psingleton = nullptr;
	}
}

std::atomic<singletonlazyC11*> singletonlazyC11::psingleton{ nullptr };
std::mutex singletonlazyC11::mtx;
singletonlazyC11* singletonlazyC11::getInstance() {
	// 第一步：无锁快速检查（放松内存序）
	singletonlazyC11* tmp = psingleton.load(std::memory_order_relaxed);
	// 编译器屏障（防止重排，x86可省略，ARM等弱内存模型需保留）
	std::atomic_signal_fence(std::memory_order_acquire);
	if (nullptr == psingleton) {
		// 进入临界区
		std::lock_guard<std::mutex> lock(mtx);
		// 第二步：持锁后再次检查（Acquire语义读取）
		tmp = psingleton.load(std::memory_order_acquire);
		if (nullptr == psingleton) {
			// 创建对象（此时必然完成构造）
			tmp = new singletonlazyC11();
			// 第三步：释放语义写入指针（确保构造完成才可见）
			psingleton.store(tmp, std::memory_order_release);
		}
	}
	return tmp;
}
void singletonlazyC11::releaseInstance() {
	if (nullptr != psingleton) {
		delete psingleton;
		psingleton = nullptr;
	}
}




void testSingleton() {
	cout << "=================Singleton start===============" << endl;
	singletonlazy* p1 = singletonlazy::getInstance();
	singletonlazy* p2 = singletonlazy::getInstance();
	if (p1 == p2) {
		cout << "单例模式" << endl;
	}
	else {
		cout << "不是单例模式" << endl;
	}
	singletonhungry* p3 = singletonhungry::getInstance();
	singletonhungry* p4 = singletonhungry::getInstance();
	if (p3 == p4) {
		cout << "单例模式" << endl;
	}
	else {
		cout << "不是单例模式" << endl;
	}
	cout << "=================Singleton end===============" << endl;
}
