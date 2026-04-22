/*
*外观模式(Facade Pattern)是一种结构型设计模式，它为复杂系统提供一个统一的简化接口，
隐藏内部复杂性，让客户端更容易使用系统。
核心思想：简化接口，封装复杂性。外观模式为一组复杂接口提供统一的高层接口，降低使用门槛。
场景：家庭影院系统
一个复杂的家庭影院系统包含多个子系统：DVD播放器、投影仪、音响、灯光、空调等。
外观模式将这些复杂的操作简化为几个简单的方法。
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

//==============子系统类=================
//1.DVD播放器子系统
class DVDPlayer {
public:
	void on();
	void off();
	void play(const string&movie);
	void puase();
	void stop();
	void setSurroundSound();
};

//2.投影仪子系统
class Projector {
public:
	void on();
	void off();
	void setWideScreenMode();
	void setInput(const string&source);
};

//3.音响子系统
class AudioSystem {
public:
	void on();
	void off();
	void setVolume(int level);
	void setSurroundMode();
	void setInput(const string&source);
};

//4.灯光子系统
class LightingSystem {
public:
	void dim(int level);
	void on();
	void off();
};

//5.空调子系统
class AirConditioner {
public:
	void on();
	void off();
	void setTemperature(int degree);
	void setMode(const std::string&mode);
};

//6.家庭影院外观类
class HomeTheaterFacade {
private:
	unique_ptr<DVDPlayer> dvd;
	unique_ptr<Projector> projector;
	unique_ptr<AudioSystem> audio;
	unique_ptr<LightingSystem> lights;
	unique_ptr<AirConditioner> ac;
public:
	//构造函数创建所有子系统对象
	HomeTheaterFacade() :dvd(make_unique<DVDPlayer>()), projector(make_unique<Projector>()), audio(make_unique<AudioSystem>())
		, lights(make_unique<LightingSystem>()), ac(make_unique<AirConditioner>()) {}
	//也可以传入已经存在的子系统对象
	HomeTheaterFacade(unique_ptr<DVDPlayer> dvd,
		unique_ptr<Projector> projector,
		unique_ptr<AudioSystem> audio,
		unique_ptr<LightingSystem> lights,
		unique_ptr<AirConditioner> ac) :dvd(std::move(dvd)), projector(std::move(projector)),
		audio(std::move(audio)), lights(std::move(lights)), ac(std::move(ac)) {}
	//简化接口
	void watchMovie(const string&movie);
	void endMovie();
	void listenToMusic(const string&source);
	void shutdownAll();
	void adjustLighting(int level);
	void adjustVolume(int level);
	void adjustTemperature(int degree);
};

void testFacade();