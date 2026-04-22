/*
组合模式(composite pattern)是一种结构型设计模式，允许你将对象组合成树形结构来
表示“部分-整体”的层次结构。它让客户端能以统一的方式处理单个对象和对象的组合。
核心思想：一致性处理叶子与容器。无论处理单个对象还是组合对象，客户端都使用相同的接口。
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//==============抽象组件=====================
class FileSystemComponent {
protected:
	string name_;
public:
	explicit FileSystemComponent(const string&name) :name_(name) {}
	virtual ~FileSystemComponent() = default;

	//核心操作
	virtual void display(int depth = 0)const = 0;
	virtual int getSize()const = 0;

	//组件管理(叶子节点可抛出异常或空实现)
	virtual void add(shared_ptr<FileSystemComponent>component);
	virtual void remove(shared_ptr<FileSystemComponent>component);
	virtual shared_ptr<FileSystemComponent> getChild(int index);
	virtual int getChildCount()const;
	string getName()const;
	virtual bool isDirectory()const;
	//格式化工具
	static string indent(int depth);
	static string formatSize(int bytes);
};
//叶子组件:文件
class File :public FileSystemComponent {
private:
	int size_; //文件大小（字节）
	string extension_;
public:
	File(const std::string& name, int size)
		: FileSystemComponent(name), size_(size) {
		// 提取扩展名
		size_t dotPos = name.find_last_of('.');
		if (dotPos != std::string::npos) {
			extension_ = name.substr(dotPos + 1);
		}
	}
	int getSize()const override;
	string getExtension()const;
	void display(int depth = 0)const override;
};

//符合组件：目录
class Directory :public FileSystemComponent {
private:
	vector<shared_ptr<FileSystemComponent>>children_;
public:
	explicit Directory(const std::string&name) :FileSystemComponent(name) {}
	//重写组件管理方法
	void add(shared_ptr<FileSystemComponent>component)override;
	void remove(shared_ptr<FileSystemComponent>component)override;
	shared_ptr<FileSystemComponent> getChild(int index)override;
	int getChildCount()const override;
	bool isDirectory()const override;
	int getSize()const override;
	void display(int depth = 0)const override;
	shared_ptr<FileSystemComponent> find(const string&name);
	int countFiles()const;
	int countDirectories()const;
};
void testComposite();