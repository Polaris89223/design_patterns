#include "facade.h"
//============DVD播放器子系统==============
void DVDPlayer::on() {
	cout << "DVD播放器: 开启\n";
}
void DVDPlayer::off() {
	cout << "DVD播放器: 关闭\n";
}
void DVDPlayer::play(const string&movie) {
	cout << "DVD播放器: 播放电影《" << movie << "》\n";
}
void DVDPlayer::puase() {
	cout << "DVD播放器: 暂停\n";
}
void DVDPlayer::stop() {
	cout << "DVD播放器: 停止\n";
}
void DVDPlayer::setSurroundSound() {
	cout << "DVD播放器: 启用环绕声\n";
}
//============投影仪子系统==============
void Projector::on() {
	cout << "投影仪: 开启\n";
}
void Projector::off() {
	cout << "投影仪: 关闭\n";
}
void Projector::setWideScreenMode() {
	cout << "投影仪: 宽屏模式\n";
}
void Projector::setInput(const string&source) {
	cout << "投影仪: 输入源设置为 " << source << "\n";
}

//============音响子系统==============
void AudioSystem::on() {
	cout << "音响系统: 开启\n";
}
void AudioSystem::off() {
	cout << "音响系统: 关闭\n";
}
void AudioSystem::setVolume(int level) {
	cout << "音响系统: 音量设置为 " << level << "\n";
}
void AudioSystem::setSurroundMode() {
	cout << "音响系统: 环绕声模式\n";
}
void AudioSystem::setInput(const string&source) {
	cout << "音响系统: 输入源设置为 " << source << "\n";
}

//============灯光子系统==============
void LightingSystem::dim(int level) {
	cout << "灯光系统: 调暗到 " << level << "%\n";
}
void LightingSystem::on() {
	cout << "灯光系统: 开启\n";
}
void LightingSystem::off() {
	cout << "灯光系统: 关闭\n";
}

//============空调子系统==============
void AirConditioner::on() {
	cout << "空调: 开启\n";
}
void AirConditioner::off() {
	cout << "空调: 关闭\n";
}
void AirConditioner::setTemperature(int degree) {
	cout << "空调: 温度设置为 " << degree << "°C\n";
}
void AirConditioner::setMode(const std::string&mode) {
	cout << "空调: 模式设置为 " << mode << "\n";
}

// ====================家庭影院外观类 ====================
void HomeTheaterFacade::watchMovie(const string&movie) {
	cout << "\n🎬 准备观看电影: " << movie << "\n";
	cout << "================================\n";
	//按照正确顺序启动所有设备
	lights->dim(10); //调暗灯光
	projector->on();  //打开投影仪
	projector->setInput("DVD");
	projector->setWideScreenMode();

	audio->on();              // 打开音响
	audio->setInput("DVD");
	audio->setSurroundMode();
	audio->setVolume(20);

	dvd->on();                // 打开DVD
	dvd->setSurroundSound();
	dvd->play(movie);

	ac->on();                 // 打开空调
	ac->setTemperature(24);
	ac->setMode("舒适");
	cout << "✅ 家庭影院准备就绪，开始观影！\n";
}
void HomeTheaterFacade::endMovie() {
	cout << "\n⏹️ 结束观影\n";
	cout << "================================\n";

	dvd->stop();
	dvd->off();

	audio->setVolume(0);
	audio->off();

	projector->off();

	lights->on();            // 恢复灯光
	lights->dim(80);

	cout << "✅ 设备已关闭\n";
}
void HomeTheaterFacade::listenToMusic(const string&source) {
	cout << "\n🎵 听音乐模式\n";
	cout << "================================\n";

	lights->dim(30);
	audio->on();
	audio->setInput(source);
	audio->setVolume(15);
	ac->on();
	ac->setTemperature(25);

	cout << "✅ 音乐模式准备就绪\n";
}
void HomeTheaterFacade::shutdownAll() {
	cout << "\n🔌 关闭所有设备\n";
	cout << "================================\n";

	dvd->off();
	projector->off();
	audio->off();
	lights->off();
	ac->off();

	cout << "✅ 所有设备已关闭\n";
}
void HomeTheaterFacade::adjustLighting(int level) {
	lights->dim(level);
}
void HomeTheaterFacade::adjustVolume(int level) {
	audio->setVolume(level);
}
void HomeTheaterFacade::adjustTemperature(int degree) {
	ac->setTemperature(degree);
}
void testFacade() {
	cout << "=================Facade start===============" << endl;
	cout << "🏠 家庭影院系统演示\n";
	cout << "==================\n";
	// 方式1：外观类负责创建所有子系统
	HomeTheaterFacade theater;
	// 使用简化接口
	theater.watchMovie("阿凡达");
	theater.adjustVolume(25);  // 可以单独调整
	theater.endMovie();
	// 使用其他模式
	theater.listenToMusic("蓝牙");
	theater.shutdownAll();
	std::cout << "\n\n";

	// 方式2：依赖注入方式
	cout << "🎯 依赖注入方式演示\n";
	cout << "==================\n";
	auto customDVD = std::make_unique<DVDPlayer>();
	auto customProj = std::make_unique<Projector>();
	auto customAudio = std::make_unique<AudioSystem>();
	auto customLights = std::make_unique<LightingSystem>();
	auto customAC = std::make_unique<AirConditioner>();
	HomeTheaterFacade customTheater(
		std::move(customDVD),
		std::move(customProj),
		std::move(customAudio),
		std::move(customLights),
		std::move(customAC)
	);
	customTheater.watchMovie("星际穿越");
	customTheater.endMovie();
	cout << "=================Facade End===============" << endl;
}