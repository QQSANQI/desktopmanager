#pragma once
#include <filesystem>
#include <vector>
#include <string>
#include<iostream>
#include "Types&Rules.h"
using namespace std;
namespace fs = std::filesystem;
class FileCLassifier
{
public:
	//分类目标路径列表
	vector<fs::path>GoalPaths;
	//是否已经分类
	bool Is_classed = false;
	//已经分类的文件string列表
	vector<fs::path>ClassedFiles;
	void classFile(const vector<fs::path>& filePath, const fs::path& rulePath);//分类文件
	bool result() const;//返回是否分类完成
private:

};
//class ConfigLoader
//{
//	bool loadConfig(const fs::path& configPath, vector<CategoryRule>& rules);//加载配置文件，返回是否成功
//	string GetGoalPath(const fs::file_type& filextension);//根据类别获取目标路径
//};
