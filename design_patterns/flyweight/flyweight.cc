#include "flyweight.h"
//--------------------享元类：树的类型（内部状态）------------------------------
void TreeType::draw(int x, int y)const {
	cout << "在位置(" << x << ", " << y << ") 绘制一棵"
		<< name_ << "树，颜色：" << color_
		<< "，纹理：" << texture_ << endl;
}
string TreeType::getKey()const {
	return name_ + "_" + color_ + "_" + texture_;
}
//-------------------享元工厂------------------------------------
// 静态成员初始化
unordered_map<string,shared_ptr<TreeType>> TreeFactory::treeTypes_;
shared_ptr<TreeType> TreeFactory::getTreeType(const string&name, const string& color, const string&texture) {
	std::string key = name + "_" + color + "_" + texture;
	auto it = treeTypes_.find(key);
	if (it != treeTypes_.end()) {
		// 已存在，返回共享对象
		return it->second;
	}
	else {
		// 不存在，创建新对象并存储
		auto treeType = std::make_shared<TreeType>(name, color, texture);
		treeTypes_[key] = treeType;
		return treeType;
	}
}
void TreeFactory::showTreeTypes() {
	std::cout << "\n已存在的树类型（享元对象）：" << std::endl;
	for (const auto& pair : treeTypes_) {
		std::cout << "  " << pair.first << std::endl;
	}
	std::cout << "总共：" << treeTypes_.size() << " 种类型" << std::endl;
}
//--------------------树类（包含外部状态）-------------------------------
void Tree::draw()const {
	type_->draw(x_, y_);
}
//------------------森林类(管理大量树)----------------------------------------
void Forest::plantTree(int x, int y, const string&name, const string& color, const string&texture) {
	// 从工厂获取共享的树类型
	auto type = TreeFactory::getTreeType(name, color, texture);
	// 创建树对象，包含外部状态
	trees_.emplace_back(x, y, type);
}
void Forest::draw()const {
	std::cout << "\n森林中有 " << trees_.size() << " 棵树：" << std::endl;
	for (const auto& tree : trees_) {
		tree.draw();
	}
}
void testFlyWeight() {
	cout << "=================FlyWeight End===============" << endl;
	Forest forest;
	// 种植大量树，但只有少数几种类型
	forest.plantTree(1, 1, "橡树", "绿色", "橡木纹理");
	forest.plantTree(2, 3, "松树", "深绿", "松木纹理");
	forest.plantTree(3, 5, "橡树", "绿色", "橡木纹理");  // 共享橡树类型
	forest.plantTree(4, 7, "枫树", "红色", "枫木纹理");
	forest.plantTree(5, 9, "松树", "深绿", "松木纹理");  // 共享松树类型
	forest.plantTree(6, 11, "橡树", "绿色", "橡木纹理"); // 共享橡树类型
	forest.plantTree(7, 13, "橡树", "黄色", "秋日橡木纹理"); // 新类型
	forest.plantTree(8, 15, "松树", "深绿", "松木纹理");  // 共享松树类型

	// 绘制森林
	forest.draw();
	// 显示共享的树类型
	TreeFactory::showTreeTypes();
	cout << "=================FlyWeight End===============" << endl;
}