#pragma once
class Product
{
public:
	virtual ~Product() = default;
	virtual  void productInfo() = 0;
};

//产品A
class ConcreateProductA:public Product
{
public:
	ConcreateProductA()=default;
	virtual ~ConcreateProductA()=default;
	virtual void productInfo() override;
};

//产品B
class ConcreateProductB :public Product
{
public:
	ConcreateProductB() = default;
	virtual ~ConcreateProductB()=default;
	virtual void productInfo() override;
};
