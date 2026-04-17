#pragma once
#include <iostream>
using namespace std;
//抽象苹果基类
class abstract_apple {
public:
	virtual void showName() = 0;
};
//中国苹果
class china_apple :public abstract_apple {
public:
	virtual void showName();
};

//美国苹果
class usa_apple :public abstract_apple {
public:
	virtual void showName();
};

//中国苹果
class japan_apple :public abstract_apple {
public:
	virtual void showName();
};

//抽象香蕉基类
class abstract_banana {
public:
	virtual void showName() = 0;
};
//中国香蕉
class china_banana :public abstract_banana {
public:
	virtual void showName();
};

//美国香蕉
class usa_banana :public abstract_banana {
public:
	virtual void showName();
};

//日本香蕉
class japan_banana :public abstract_banana {
public:
	virtual void showName();
};

class abstract_pear {
public:
	virtual void showName() = 0;
};

//中国鸭梨
class china_pear :public abstract_pear {
public:
	virtual void showName();
};

//美国鸭梨
class usa_pear :public abstract_pear {
public:
	virtual void showName();
};

//日本鸭梨
class japan_pear :public abstract_pear {
public:
	virtual void showName();
};
