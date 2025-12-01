#include "FileScanner.h"
using namespace std;
/*假设传入的路径正确
我不管，必须正确
*/
FileScanner::FileScanner(const fs::path& desktoppath)//构造函数，传入桌面路径
{
	this->desktopPath = desktoppath;
}
std::vector<fs::path> FileScanner::getAllFiles(const fs::path& desktopPath)//遍历所有文件，返回文件路径列表
{
	vector<fs::path> allFiles;
	//遍历desktopPath目录下一级文件
	if (!fs::exists(desktopPath))//路径不存在，报错
		{
			cerr << "路径不存在" << endl;
			return std::vector<fs::path>();
		}
	else 
		{
		for (const auto& entry : fs::directory_iterator(desktopPath))
			{
				if (entry.is_regular_file())
				{
					allFiles.push_back(entry.path());
				}
			}
		return allFiles;
		}
}
//分类获取文件，返回指定类型的文件路径列表（完成）
vector<fs::path> FileScanner::getFilesByType(const std::string& extension)
{
	vector<fs::path> filesByType;
	try {
		for (fs::path files : getAllFiles(desktopPath)) {
			if(files.extension() == extension)
			{
				filesByType.push_back(files);
			}
		}
		if(filesByType.size()==0)
		{
			throw runtime_error("未找到该类型文件");
		}
	}
	catch (const runtime_error& e) {
		cerr << "错误: " << e.what() << endl;
	}//未找到就报错，此时返回空数组
	return filesByType;
}
