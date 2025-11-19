#include "jsonconfig_loader.h"
#include "Types&Rules.h"
#include "json.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

using json = nlohmann::json;
json config;
vector<CategoryRule> JsonConfigLoader::configloader(const fs::path& configloc)//配置加载器,默认规则为file_categories.json
{
	CategoryRule rule;
	vector<CategoryRule> rules;

	int index = 0;//配置索引
	ifstream configfile(configloc.filename().string());
	configfile >> config;
	for (int i = 0; i < config.at("categories").size(); i++)
	{
		if (config.at("categories").at(i).at("enabled") == true)
		{
			string name = config.at("categories").at(index).at("name");
			string objpath = config.at("categories").at(index).at("folder");
			const vector<string> exts = config.at("categories").at(index).at("extensions");
			bool enabled = config.at("categories").at(index).at("enabled");
			//导入各项配置
			rule.extension = exts;
			rule.category = name;
			rule.targetPath = objpath;
		}
	}

	rules.push_back(rule);
	return rules;
}
/*配置写入器，实现：
检查目录下customconfig.json是否存在，不存在则创建，将客户输入的配置信息写入*/
void configwriter(const fs::path& configs,const vector<CategoryRule>& customrules) //customrules从客户端传入
{
	if (!fs::exists(configs / "customconfig.json")) {
		ofstream configfile(configs / "customconfig.json");
		configfile.close();
	}
	json cfig;
	cfig["categories"] = json::array();
	for (const auto& rule : customrules) {
		json ruleJson;
		ruleJson["name"] = rule.category;
		ruleJson["folder"] = rule.targetPath.string();
		ruleJson["extensions"] = rule.extension;
		ruleJson["enabled"] = true; // 默认启用
		cfig["categories"].push_back(ruleJson);
	}
	ofstream configfile(configs / "customconfig.json");
	configfile << cfig.dump(4);
	configfile.close();
}