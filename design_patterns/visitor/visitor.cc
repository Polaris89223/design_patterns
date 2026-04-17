#include "visitor.h"
void ConcreteVisitor::visit(Paragraph*p) {
	cout << "Visiting a paragraph with content: " << p->getContent().c_str() << endl;
}
void ConcreteVisitor::visit(Header*h) {
	cout << "Visiting a Header with content: " << h->getContent().c_str() << endl;
}
void Paragraph::accept(Visitor*v) {
	v->visit(this);
}
string Paragraph::getContent()const {
	return m_content;
}
void Header::accept(Visitor*v) {
	v->visit(this);
}
string Header::getContent()const {
	return m_content;
}
void Document::addElement(std::unique_ptr<Element>elem) {
	m_elements.emplace_back(elem.release());
}
void Document::accept(Visitor*v) {
	for (auto &elem:m_elements)
	{
		elem->accept(v);
	}
}
void testVisitor(){
	cout << "=================visitor start===============" << endl;
	Document doc;
	doc.addElement(std::make_unique<Paragraph>("This is a paragraph."));
	doc.addElement(std::make_unique<Header>("This is a header."));

	ConcreteVisitor visitor;
	doc.accept(&visitor);
	cout << "=================visitor end===============" << endl;
}