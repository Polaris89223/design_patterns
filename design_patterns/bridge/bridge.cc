#include "bridge.h"
void HuaWeiPhone::runApp() {
	cout << "华为手机运行应用程序" << endl;
}
void IPhone::runApp() {
	cout << "苹果手机运行应用程序" << endl;
}
void WeChat::runOnPhone(Phone*phone) {
	cout << "微信在" << typeid(*phone).name() << " 上运行" << endl;
}
void WangZheRongYao::runOnPhone(Phone*phone) {
	cout << "王者荣耀在" << typeid(*phone).name() << " 上运行" << endl;
}
void testBridge() {
	cout << "=================Bridge begin===============" << endl;
	//创建华为手机对象
	std::shared_ptr<Phone> huawei = std::make_shared<HuaWeiPhone>();
	//创建微信应用程序对象
	std::shared_ptr<WeChat> wechat = std::make_shared<WeChat>();
	//在华为手机上运行微信
	wechat->runOnPhone(huawei.get());

	//创建苹果手机对象
	std::shared_ptr<Phone> iphone = std::make_shared<IPhone>();
	//创建王者荣耀对象
	std::shared_ptr<WangZheRongYao> wzry = std::make_shared<WangZheRongYao>();
	//在苹果手机上运行王者荣耀
	wzry->runOnPhone(iphone.get());

	cout << "=================Bridge End===============" << endl;
}