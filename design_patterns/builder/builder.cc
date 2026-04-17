#include "builder.h"
//常变属性设置接口
void graphic::setShape(const string&shape) {
	m_shape = shape;
}
void graphic::setColor(const string&color) {
	m_color = color;
}
void graphic::show() {
	cout << m_color << m_shape << endl;
}

//创建空白图像对象
void builder::createGraphic() {
	if (NULL == m_pgraphic) {
		m_pgraphic = new graphic();
	}
}
graphic* builder::getGraphic() {
	return m_pgraphic;
}

void greencirclebuilder::drawShape() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setShape("circle");
	}
}
void greencirclebuilder::drawColor() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setColor("green");
	}
}
void redrectanglebuilder::drawShape() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setShape("rectang");
	}
}
void redrectanglebuilder::drawColor() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setColor("red");
	}
}
void bluetrianglebuilder::drawShape() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setShape("triangle");
	}
}
void bluetrianglebuilder::drawColor() {
	if (NULL != m_pgraphic) {
		m_pgraphic->setColor("blue");
	}
}
// 根据需求设置对应的建造者
void director::setBuilder(builder& pBuilder){
	m_pbuilder = &pBuilder;
}

//通过建造者获得描绘完成的图形
graphic* director::drawGraphic() {
	if (NULL == m_pbuilder) {
		return NULL;
	}
	//建造过程为不变的因素
	m_pbuilder->createGraphic();
	m_pbuilder->drawColor();
	m_pbuilder->drawShape();
	return m_pbuilder->getGraphic();
}

void testBuilder() {
	cout << "=================builder start===============" << endl;
	director MyDirector;
	// 根据导演的不同需求，分别设置不同的建造者，获得满足需求的图形
	greencirclebuilder BuilderGC; // 绿色圆形的建造者
	MyDirector.setBuilder(BuilderGC);
	graphic* pGraphicGC = MyDirector.drawGraphic(); // 导演使用建造者画图
	pGraphicGC->show();

	redrectanglebuilder BuilderRB; // 红色矩形的建造者
	MyDirector.setBuilder(BuilderRB);
	graphic* pGraphicRB = MyDirector.drawGraphic(); // 导演使用建造者画图
	pGraphicRB->show();

	bluetrianglebuilder BuilderBT; // 蓝色三角的建造者
	MyDirector.setBuilder(BuilderBT);
	graphic* pGraphicBT = MyDirector.drawGraphic(); // 导演使用建造者画图
	pGraphicBT->show();

	// 资源回收
	if (NULL == pGraphicGC) {
		delete pGraphicGC;
		pGraphicGC = NULL;
	}
	if (NULL == pGraphicRB) {
		delete pGraphicRB;
		pGraphicRB = NULL;
	}
	if (NULL == pGraphicBT) {
		delete pGraphicBT;
		pGraphicBT = NULL;
	}
	cout << "=================builder end===============" << endl;
}
