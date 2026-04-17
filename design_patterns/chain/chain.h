#pragma once
/*
责任链模式（Chain of Responsibility Pattern）为请求创建了一个接收者对象的链。这种模式给予请求的类型，对请求的发送者和接收者进行解耦。
这种类型的设计模式属于行为型模式。在这种模式中，通常每个接收者都包含对另一个接收者的引用。如果一个对象不能处理该请求，那么它会把相同
的请求传给下一个接收者，依此类推
**主要解决：**职责链上的处理者负责处理请求，客户只需要将请求发送到职责链上即可，无须关心请求的处理细节和请求的传递，所以职责链将请求
的发送者和请求的处理者解耦了。
**何时使用：**在处理消息的时候以过滤很多道。
举例：
编写程序完成学校OA系统的采购审批项目：需求：
- 采购员采购教学器材
- 如果金额 小于等于5000, 由教学主任审批
- 如果金额 小于等于10000, 由院长审批
- 如果金额 小于等于30000, 由副校长审批
- 如果金额 超过30000以上，有校长审批
*/
#include <iostream>
#include <string>
#include <memory>
using namespace std;
//购买请求类
class PurchaseRequest{
public:
	PurchaseRequest(const int type, const float price, const int id)
	: type(type),
		price(price),
		id(id)
	{
	}
	int getType()const;
	float getPrice()const;
	int getId()const;
private:
	//请求类型
	int type;
	//价格
	float price = 0.f;
	int id = 0;
};
//审批类
class Approver {
public:
	explicit Approver(const string&name) :m_name(name) {};
	void setApprover(Approver*const approver);
	//处理审批请求的方法，得到一个请求，处理是子类完成的，因此该方法写成纯虚方法
	virtual void processRequest(PurchaseRequest* purchaseRequest)=0;
protected:
	//下一个处理者
	Approver* nextApprover;
	string m_name;
};

//教学主任
class DepartmentApprover:public Approver
{
public:
	explicit DepartmentApprover(const string&name) :Approver(name) {}
	void processRequest(PurchaseRequest*purchaseRequest)override;
};

//院长
class CollegeApprover :public Approver {
public:
	explicit CollegeApprover(const string&name) :Approver(name) {}
	void processRequest(PurchaseRequest*purchaseRequest)override;
};

//副校长
class ViceSchoolMasterApprover:public Approver {
public:
	explicit ViceSchoolMasterApprover(const string&name) :Approver(name) {}
	void processRequest(PurchaseRequest*purchaseRequest)override;
};

//校长
class SchoolMasterApprover :public Approver {
public:
	explicit SchoolMasterApprover(const string&name) :Approver(name) {}
	void processRequest(PurchaseRequest*purchaseRequest)override;
};

void testChainOfResponsibility();