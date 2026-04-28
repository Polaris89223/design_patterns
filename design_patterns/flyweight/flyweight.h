/*
 享元模式(flyWeight pattern)是一种结构型设计模式，它通过共享技术来有效地支持大量细粒度对象的复用，从而减少内存使用和提高性能。
  核心思想：如果程序中有大量相似对象，可以将它们共有的部分（内部状态）提取出来共享，而变化的部分（外部状态）在运行时传入。
  形象比喻：字母处理器的例子
 - 文档中有成千上万个字母‘a’、‘b’、‘c’等
 - 每个字母都有自己的字体，大小、颜色、位置等
 - 如果为每个字母都创建完整的对象，内存占用巨大
 - 享元模式：创建一个共享的字母对象（内部状态：字符代码），将字体、颜色、位置等作为外部状态输入。
*/
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
using namespace std;
//--------------------享元类：树的类型（内部状态）------------------------------
//FlyWeight
class TreeType {
private:
	string name_;   //内部状态
	string color_;  //内部状态
	string texture_;//内部状态
public:
	TreeType(const string&name, const string& color, const string&texture) :name_(name), color_(color), texture_(texture) {}
	void draw(int x, int y)const;
	string getKey()const;
};
//-------------------享元工厂------------------------------------
class TreeFactory {
private:
	//存储共享的数类型对象
	static unordered_map<string, shared_ptr<TreeType>>treeTypes_;
public:
	static shared_ptr<TreeType> getTreeType(const string&name, const string& color, const string&texture);
	static void showTreeTypes();
};

//--------------------树类（包含外部状态）-------------------------------
class Tree {
private:
	int x_; //外部状态
	int y_; //外部状态
	shared_ptr<TreeType> type_;//共享的内部状态
public:
	Tree(int x, int y, shared_ptr<TreeType> type) :x_(x), y_(y), type_(type) {}
	void draw()const;
};

//------------------森林类(管理大量树)----------------------------------------
class Forest {
private:
	vector<Tree> trees_;
public:
	void plantTree(int x, int y, const string&name, const string& color, const string&texture);
	void draw()const;
};

void testFlyWeight();