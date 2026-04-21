#include "Proxy.h"
#include <thread>
#include <chrono>
#include <exception>
//真实服务
string HeavyDatabaseService::request(const string& input)const {
	cout << "[RealService] Loading heavy resource for:" << input << endl;
	this_thread::sleep_for(chrono::seconds(2));
	return "Processed: " + input + " [by RealService]";
}

//代理服务
bool LazyCacheProxy::validateAccess()const {
	return !authToken_.empty() && authToken_ == "valid_token_123";
}
void LazyCacheProxy::logCall(const string&callerInfo)const {
	cout << "[Proxy] Log:Called by" << callerInfo << endl;
}
string LazyCacheProxy::request(const string&input)const {
	logCall("ClientApp");

	//1.鉴权
	if (!validateAccess()) {
		throw runtime_error("[Proxy] Acess denied:Invalid token");
	}

	//2.缓存检查
	if (hasCache_ && input == "cache_key") {
		cout << "[Proxy] Cache hit,returning cached result" << endl;
		return cacheResult_;
	}

	//3.懒加载真实对象
	if (!realService_) {
		cout << "[Proxy] Lazy-loading RealService...." << endl;
		realService_.reset(new HeavyDatabaseService());
	}

	//4.委托调用
	auto result = realService_->request(input);

	//5.更新缓存
	if (input == "cache_key") {
		cacheResult_ = result;
		hasCache_ = true;
	}
	return result;
}

void testDirect() {
	cout << "=== Direct access (no proxy) ===\n";
	HeavyDatabaseService real;
	std::string res = real.request("direct_test");
	cout << "Result: " << res << "\n\n";
}
void testInvalidProxy() {
	cout << "=== Valid proxy (caching + lazy load) ===\n";
	LazyCacheProxy proxy("valid_token_123");

	cout << "-- First call --\n";
	std::string r1 = proxy.request("cache_key");
	cout << "Result: " << r1 << "\n";

	cout << "\n-- Second call (cached) --\n";
	std::string r2 = proxy.request("cache_key");
	cout << "Result: " << r2 << "\n\n";
}
void testValidProxy() {
	cout << "=== Invalid proxy (access control) ===\n";
	LazyCacheProxy badProxy("");
	try {
		badProxy.request("any");
	}
	catch (const std::exception& e) {
		cerr << "Correctly blocked: " << e.what() << "\n";
	}
}
void testProxy() {
	cout << "=================Proxy Pattern start===============" << endl;
	testDirect();
	testInvalidProxy();
	testValidProxy();
	cout << "=================Proxy Pattern end===============" << endl;
}