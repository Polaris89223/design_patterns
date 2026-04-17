#include "chain.h"
int PurchaseRequest::getType()const {
	return type;
}
float PurchaseRequest::getPrice()const {
	return price;
}
int PurchaseRequest::getId()const {
	return id;
}
void Approver::setApprover(Approver*const approver) {
	this->nextApprover = approver;
}
void DepartmentApprover::processRequest(PurchaseRequest* purchaseRequest)
{
	if (purchaseRequest->getPrice() <= 5000)
	{
		cout << "请求编号id=" << purchaseRequest->getId() << "被" << this->m_name << "处理" << endl;
	}
	else
	{
		nextApprover->processRequest(purchaseRequest);
	}
}

void CollegeApprover::processRequest(PurchaseRequest* purchaseRequest)
{
	if (purchaseRequest->getPrice() > 5000 && purchaseRequest->getPrice() <= 10000)
	{
		cout << "请求编号id=" << purchaseRequest->getId() << "被" << this->m_name << "处理" << endl;
	}
	else
	{
		nextApprover->processRequest(purchaseRequest);
	}
}
void ViceSchoolMasterApprover::processRequest(PurchaseRequest* purchaseRequest)
{
	if (purchaseRequest->getPrice() > 10000 && purchaseRequest->getPrice() <= 30000)
	{
		cout << "请求编号id=" << purchaseRequest->getId() << "被" << this->m_name << "处理" << endl;
	}
	else
	{
		nextApprover->processRequest(purchaseRequest);
	}
}
void SchoolMasterApprover::processRequest(PurchaseRequest* purchaseRequest)
{
	if (purchaseRequest->getPrice() > 30000)
	{
		cout << "请求编号id=" << purchaseRequest->getId() << "被" << this->m_name << "处理" << endl;
	}
	else
	{
		nextApprover->processRequest(purchaseRequest);
	}
}
void testChainOfResponsibility() {
	cout << "=================chain of responsibility begin===============" << endl;
	//创建一个请求
	std::unique_ptr<PurchaseRequest> purchaseRequest = std::make_unique<PurchaseRequest>(1, 1000, 1);
	std::unique_ptr<PurchaseRequest> purchaseRequest1 = std::make_unique<PurchaseRequest>(1, 30000, 2);
	//创建相关的审批人
	std::unique_ptr<DepartmentApprover> department = std::make_unique<DepartmentApprover>("张主任");
	std::unique_ptr <CollegeApprover > college = std::make_unique<CollegeApprover>("李院长");
	std::unique_ptr <ViceSchoolMasterApprover > viceSchoolMaster = std::make_unique<ViceSchoolMasterApprover>("王副校长");
	std::unique_ptr <SchoolMasterApprover > schoolMaster = std::make_unique<SchoolMasterApprover>("佟校长");
	//需要将各个审批级别的下一个人设置好(处理人构成一个环装就可以从任何一个人开始处理了)
	//否则必须从第一个处理人开始
	department->setApprover(college.get());
	college->setApprover(viceSchoolMaster.get());
	viceSchoolMaster->setApprover(schoolMaster.get());
	schoolMaster->setApprover(department.get());

	//开始处理请求
	viceSchoolMaster->processRequest(purchaseRequest.get());
	department->processRequest(purchaseRequest1.get());
	cout << "=================chain of responsibility end===============" << endl;
}