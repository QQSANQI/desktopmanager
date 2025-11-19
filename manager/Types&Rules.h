#pragma once
#include <string>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;
using namespace std;
// 分类规则结构体
struct CategoryRule {
	vector<string> extension; // 文件扩展名
	string category;  // 文件类别
	fs::path targetPath; // 目标文件夹路径
};
// 文件类型结构体
struct FileType {
	string extension; // 文件扩展名
	fs::path FilePath; // 文件路径
};
// 配置数据结构体
struct configdata {
	vector<CategoryRule> rules; // 分类规则列表
	fs::path defaultPath; // 默认目标路径
};