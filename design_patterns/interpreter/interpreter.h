#pragma once
/*Interpreter 模式（解释器模式）
- 在编译原理中，一个算术表达式通过词法分析器形成词法单元，而后这些词法单元再通过语法分析器构建语法分析树，
最终形成一颗抽象的语法分析树。这里的词法分析器和语法分析器都可以看做是解释器
- 解释器模式（Interpreter Pattern）：是指给定一个语言(表达式)，定义它的文法的一种表示，并定义一个解释器，
使用该解释器来解释语言中的句子(表达式)
- 应用场景：
- 1、应用可以将一个需要解释执行的语言中的句子表示为一个抽象语法树
- 2、一些重复出现的问题可以用一种简单的语言来表达
- 3、一个简单语法需要解释的场景
- 4、这样的例子还有，比如编译器、运算表达式计算、正则表达式、机器人等
优点：
- 可扩展性比较好，灵活。
- 增加了新的解释表达式的方式。
- 易于实现简单文法。
缺点：
- 可利用场景比较少。
- 对于复杂的文法比较难维护。
- 解释器模式会引起类膨胀。
- 解释器模式采用递归调用方法
*/
#include <iostream>
#include <string>
using namespace std;
//抽象表达式类
class IExpression{
public:
	virtual ~IExpression() {};
	virtual int evaluate() = 0;
};
//终结符表达式 - 数字
class NumberExpression:public IExpression {
public:
	NumberExpression(int val) :m_value(val) {}
	virtual int evaluate()override;
private:
	int m_value;
};
//非终结符表达式 - 加法
class AddExpression:public IExpression{
public:
	AddExpression(IExpression *l, IExpression *r) : left(l), right(r) {}
	virtual int evaluate()override;
private:
	IExpression *left;
	IExpression *right;
};

// 非终结符表达式 - 减法
class SubtractExpression : public IExpression {
private:
	IExpression *left;
	IExpression *right;
public:
	SubtractExpression(IExpression *l, IExpression *r) : left(l), right(r) {}
	virtual int evaluate() override;
};

void testInterPreter();