#include <iostream>
#include <algorithm>
#include <fstream>
#include "jsonconfig_loader.h"
#include "json.hpp"

using json = nlohmann::json;

static string ReadFileStripUtf8BOM(const fs::path& p)
{
	ifstream ifs(p.string(), std::ios::binary);
	if (!ifs.is_open())
		return {};

	string s((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

	// 去除 UTF-8 BOM（若存在）
	if (s.size() >= 3 &&
		static_cast<unsigned char>(s[0]) == 0xEF &&
		static_cast<unsigned char>(s[1]) == 0xBB &&
		static_cast<unsigned char>(s[2]) == 0xBF)
	{
		s.erase(0, 3);
	}
	return s;
}
int JsonConfigLoader::extsnum() {
	return (int)exts.size();
}
//配置加载器，返回图：<字符串数组，字符串>=<拓展名数组，目标路径>
unordered_map<string,string> JsonConfigLoader::configloader(const fs::path& configloc)
{
	unordered_map<string,string> map1;

	string text = ReadFileStripUtf8BOM(configloc);
	if (text.empty()) {
		std::cerr << "无法打开，空的配置文件: " << configloc << std::endl;
	}

	try {
		json cfg = json::parse(text);

		if (!cfg.contains("categories") || !cfg["categories"].is_array()) {
			std::cerr << "关键数组'categories'不存在: " << configloc << std::endl;
		}

		for (const auto& item : cfg["categories"]) {
			if (!item.is_object()) continue;
			bool enabled = item.value("enabled", false);
			if (!enabled) continue;

			string name = item.value("name", string{});
			string objpath = item.value("folder", string{});
			exts = (item.contains("extensions") && item["extensions"].is_array())
				? item["extensions"].get<vector<string>>()
				: vector<string>{};
			
			for(string ext:exts)
			map1.emplace(ext, objpath);
		}
	}
	catch (const nlohmann::json::parse_error& e) {
		std::cerr << "JSON parse错误：" << configloc << ": " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "配置加载出错： " << configloc << ": " << e.what() << std::endl;
	}

	return map1;
}

/*配置写入器，实现：
检查目录下customconfig.json是否存在，不存在则创建，将客户输入的配置信息写入*/
void configwriter(const fs::path& config_to, string name, string objpath, vector<string> exts)
{
	if (!fs::exists(config_to / "customconfig.json"))
	{
		fstream ofs(config_to / "customconfig.json", ios::out);
		ofs.close();
	}
	fstream item(config_to / "customconfig.json");

	json j;
	j["categories"] = json::array();
	j.push_back("customRULE");
	j["categories"].push_back({
		{"name", name},
		{"folder", objpath},
		{"extensions", exts},
		{"enabled", true}
		});
	item << j.dump(4);
	item.close();
}