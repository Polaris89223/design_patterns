#include "interpreter.h"
int NumberExpression::evaluate() {
	return m_value;
}
int AddExpression::evaluate() {
	return left->evaluate() + right->evaluate();
}
int SubtractExpression::evaluate() {
	return left->evaluate() - right->evaluate();
}
void testInterPreter() {
	cout << "=================InterPreter begin===============" << endl;
	IExpression *num1 = new NumberExpression(5);
	IExpression *num2 = new NumberExpression(3);

	IExpression *addExpr = new AddExpression(num1, num2);
	IExpression *subExpr = new SubtractExpression(num1, num2);

	std::cout << "加法结果: " << addExpr->evaluate() << std::endl;
	std::cout << "减法结果: " << subExpr->evaluate() << std::endl;

	delete num1;
	delete num2;
	delete addExpr;
	delete subExpr;
	cout << "=================InterPreter begin===============" << endl;
}