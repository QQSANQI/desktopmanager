#pragma once
#include <filesystem>
#include <vector>
#include <string>
using namespace std;
namespace fs = std::filesystem; // 文件系统库

// 模块1：文件扫描器 - 负责获取桌面文件信息
class FileScanner {
public:
    string getALLFiles();
    string getFilesByType();
    std::vector<fs::path> getAllFiles(const fs::path& desktopPath);
    std::vector<fs::path> getFilesByType(const std::string& extension);
private:

};