#pragma once
#include "TYpes&Rules.h"
#include <string>
#include <unordered_map>

class JsonConfigLoader
{
private:
	configdata configData; // 存储配置数据
	std::unordered_map<std::string, CategoryRule> rulesMap; // 存储扩展名到CategoryRule的映射
	bool is_loaded = false; // 配置是否已加载
public:
	string name;
	string objpath;
	vector<CategoryRule> configloader(const fs::path& configloc);
};