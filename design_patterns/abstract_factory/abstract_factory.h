#pragma once
/*假如我们要买水果，水果的产地来自中国、日本、美国，每个国家的水果种类都可以分为苹果、香蕉、梨子。
作为开发者，我们就不得不创建苹果类（香蕉和梨子类似），然后每种苹果都继承自苹果类。每上架一个国家
的苹果我们都要实现一次苹果类，这样就会有成千上万的苹果类需要被创建，AbstractFactory 模式就是用来
解决这类问题的：要创建一组相关或者相互依赖的对象
*/
class abstract_apple;
class abstract_banana;
class abstract_pear;

//抽象工厂 针对产品族
class abstract_factory {
public:
	virtual abstract_apple*  create_apple() = 0;
	virtual abstract_banana* create_banana() = 0;
	virtual abstract_pear*   create_pear() = 0;
};

//中国工厂
class china_factory :public abstract_factory {
public:
	abstract_apple*  create_apple() override;
	abstract_banana* create_banana() override;
	abstract_pear*   create_pear()override;
};

//美国工厂
class usa_factory :public abstract_factory {
public:
	abstract_apple*  create_apple() override;
	abstract_banana* create_banana() override;
	abstract_pear*   create_pear()override;
};

//日本工厂
class japan_factory :public abstract_factory {
public:
	abstract_apple*  create_apple() override;
	abstract_banana* create_banana() override;
	abstract_pear*   create_pear()override;
};
void testAbstractFactory();