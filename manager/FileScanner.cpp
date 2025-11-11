#include "FileScanner.h"
using namespace std;

fs::path FileScanner::getALLFiles()//遍历所有文件
{
    fs::path desktopPath;
	cout << "目录内容" << endl;
    for (const auto& entry : desktopPath)
    {
		cout << entry.path() << endl;
    }
    return fs::path();
}

fs::path FileScanner::getFilesByType()//分类获取文件
{
    return fs::path();
}
