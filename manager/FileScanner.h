#pragma once
#include <filesystem>
#include <vector>
#include <string>
#include<iostream>
using namespace std;
namespace fs = std::filesystem; // 文件系统库

// 模块1：文件扫描器 - 负责获取桌面文件信息
class FileScanner {
public:
	fs::path desktopPath;//桌面路径
	//分类获取文件，返回指定类型的文件路径列表
	std::vector<fs::path> getFilesByType(const string& extension);
	FileScanner(const fs::path& desktopPath);
	std::vector<fs::path> getAllFiles(const fs::path& desktopPath);
private:
	//遍历所有
	
	//CategoryRule callFile(const vector<fs::path>& filepaths);//获取单个文件信息
};