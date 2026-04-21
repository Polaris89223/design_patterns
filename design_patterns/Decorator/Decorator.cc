#include "Decorator.h"
#include <iostream>
#include <cctype>

//接口实现
void TextProcessor::operation(std::string&data)const {
	std::cout << "[TextProcessor] Processing: " << data << std::endl;
	//基础处理：转大写
	for (auto&c : data) c = std::toupper(c);
}

//抽象装饰器 //默认转发，子类可重写
void Decorator::operation(std::string&data)const {
	if (wrapped_) wrapped_->operation(data);
}

//添加前缀装饰器
void PrefixDecorator::operation(std::string&data)const {
	data = prefix_ + ">>" + data;
	Decorator::operation(data);//调用父类接口转发
}

//反转字符串
void  ReverseDecorator::operation(std::string&data)const {
	Decorator::operation(data); //先执行原操作
	std::reverse(data.begin(), data.end());
}

//统计长度装饰器
void LengthStateDecorator::operation(std::string&data)const {
	Decorator::operation(data);
	std::cout << "[Length] After processing:" << data.length() << "chars" << std::endl;
}

//调用测试
void testDecorator() {

	std::cout << "=================Decorator Begin===============" <<std::endl;
	std::string input = "hello world";
	std::cout << "=== 原始处理===" << std::endl;
	auto processor = std::make_unique<TextProcessor>();
	auto copy1 = input;
	processor->operation(copy1);
	std::cout << "Result: " << copy1 << std::endl;

	std::cout << "=== 装饰器链：前缀->大写->反转===" << std::endl;
	auto decorated = std::make_unique<ReverseDecorator>(
		std::make_unique<PrefixDecorator>(
			std::make_unique<TextProcessor>(),
			"Start"
			)
		);
	auto copy2 = input;
	decorated->operation(copy2);
	std::cout << "Result: " << copy2 << std::endl;

	std::cout << " === 加上统计装饰器===" << std::endl;
	auto withStats = std::make_unique<LengthStateDecorator>(
		std::make_unique<ReverseDecorator>(
		std::make_unique<PrefixDecorator>(
			std::make_unique<TextProcessor>(),
			"Demo")
		));
	auto copy3 = input;
	withStats->operation(copy3);
	std::cout << "Final: " << copy3 << std::endl;
	std::cout << "=================Decorator End===============" << std::endl;
}