#include "composite.h"
//==============抽象组件=====================
void FileSystemComponent::add(shared_ptr<FileSystemComponent>component) {
	throw std::runtime_error("不支持添加操作");
}
void FileSystemComponent::remove(shared_ptr<FileSystemComponent>component) {
	throw std::runtime_error("不支持删除操作");
}
shared_ptr<FileSystemComponent> FileSystemComponent::getChild(int index) {
	throw std::runtime_error("无子组件");
}
int FileSystemComponent::getChildCount()const {
	return 0;
}
string FileSystemComponent::getName()const {
	return name_;
}
bool FileSystemComponent::isDirectory()const {
	return false;
}
//格式化工具
string FileSystemComponent::indent(int depth) {
	return std::string(depth * 2, ' ');
}
string FileSystemComponent::formatSize(int bytes) {
	const char* units[] = { "B", "KB", "MB", "GB" };
	double size = bytes;
	int unitIndex = 0;

	while (size >= 1024 && unitIndex < 3) {
		size /= 1024;
		unitIndex++;
	}

	char buffer[32];
	snprintf(buffer, sizeof(buffer), "%.1f %s", size, units[unitIndex]);
	return buffer;
}
//叶子组件:文件
int File::getSize()const {
	return size_;
}
string File::getExtension()const {
	return extension_;
}
void File::display(int depth)const {
	cout << indent(depth)<< "📄 " << name_<< " [" << formatSize(size_) << "]"
	<< " (" << extension_ << ")"<< std::endl;
}

//复合组件:目录
//重写组件管理方法
void Directory::add(shared_ptr<FileSystemComponent>component) {
	children_.push_back(component);
}
void Directory::remove(shared_ptr<FileSystemComponent>component) {
	auto it = std::find(children_.begin(), children_.end(), component);
	if (it != children_.end()) {
		children_.erase(it);
	}
}
shared_ptr<FileSystemComponent> Directory::getChild(int index) {
	if (index >= 0 && index < static_cast<int>(children_.size())) {
		return children_[index];
	}
	return nullptr;
}
int Directory::getChildCount()const {
	return static_cast<int>(children_.size());
}
bool Directory::isDirectory()const {
	return true;
}
int Directory::getSize()const {
	int totalSize = 0;
	for (const auto& child : children_) {
		totalSize += child->getSize();
	}
	return totalSize;
}
void Directory::display(int depth)const {
	// 显示当前目录
	cout << indent(depth)
		<< "📁 " << name_
		<< " [" << getChildCount() << " items, "
		<< formatSize(getSize()) << "]"
		<< std::endl;

	// 递归显示子组件
	for (const auto& child : children_) {
		child->display(depth + 1);
	}
}
shared_ptr<FileSystemComponent>Directory::find(const string&name) {
	for (const auto& child : children_) {
		if (child->getName() == name) {
			return child;
		}
		// 如果是目录，递归查找
		if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
			auto result = dir->find(name);
			if (result) return result;
		}
	}
	return nullptr;
}
int Directory::countFiles()const {
	int count = 0;
	for (const auto& child : children_) {
		if (!child->isDirectory()) {
			count++;
		}
		else {
			if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
				count += dir->countFiles();
			}
		}
	}
	return count;
}
int Directory::countDirectories()const {
	int count = 0;
	for (const auto& child : children_) {
		if (child->isDirectory()) {
			count++;
			if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
				count += dir->countDirectories();
			}
		}
	}
	return count;
}
void testComposite() {
	cout << "=================Composite start===============" << endl;
	cout << "🌳 文件系统浏览器 - 组合模式演示\n";
	cout << "================================\n\n";

	//创建文件
	auto file1 = std::make_shared<File>("readme.txt", 2048);
	auto file2 = std::make_shared<File>("main.cpp", 4096);
	auto file3 = std::make_shared<File>("image.jpg", 1024 * 1024 * 2);  // 2MB
	auto file4 = std::make_shared<File>("config.json", 512);
	auto file5 = std::make_shared<File>("video.mp4", 1024 * 1024 * 100);  // 100MB

	//创建目录结构
	auto root = std::make_shared<Directory>("/");
	auto documents = std::make_shared<Directory>("Documents");
	auto pictures = std::make_shared<Directory>("Pictures");
	auto videos = std::make_shared<Directory>("Videos");
	auto src = std::make_shared<Directory>("src");

	// 构建树形结构
	documents->add(file1);
	documents->add(file4);

	pictures->add(file3);

	videos->add(file5);

	src->add(file2);

	// 添加到根目录
	root->add(documents);
	root->add(pictures);
	root->add(videos);
	root->add(src);

	// 显示整个文件系统
	cout << "📁 完整文件系统结构:\n";
	root->display();

	cout << "\n📊 统计信息:\n";
	cout << "文件总数: " << root->countFiles() << "\n";
	cout << "目录总数: " << root->countDirectories() << "\n";
	cout << "总大小: " << FileSystemComponent::formatSize(root->getSize()) << "\n";

	// 搜索文件
	cout << "\n🔍 搜索文件:\n";
	auto found = root->find("main.cpp");
	if (found) {
		cout << "找到: ";
		found->display(0);
	}

	// 统一处理组件
	cout << "\n🔄 统一处理所有组件:\n";
	vector<std::shared_ptr<FileSystemComponent>> components = {
		root, documents, file1, src, file2
	};

	for (const auto& comp : components) {
		std::cout << "- " << comp->getName()
			<< " (" << (comp->isDirectory() ? "目录" : "文件") << ")"
			<< " 大小: " << FileSystemComponent::formatSize(comp->getSize())
			<< std::endl;
	}

	// 动态添加新文件
	std::cout << "\n➕ 动态添加新文件:\n";
	auto newFile = std::make_shared<File>("newfile.txt", 1024);
	documents->add(newFile);
	documents->display(1);
	cout << "=================Composite end===============" << endl;
}