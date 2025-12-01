#pragma once
#include<filesystem>
#include <string>
#include <vector>
#include <unordered_map>
namespace fs = std::filesystem;
using namespace std;
using std::string;
using std::vector;
using std::unordered_map;

class JsonConfigLoader
{
private:
	std::unordered_map<std::string, std::string> rulesMap; // 存储扩展名到CategoryRule的映射
	bool is_loaded = false; // 配置是否已加载
	vector<string> exts;
public:
	string name;
	string objpath;
	//返回拓展名列表长度
	int extsnum();
	unordered_map<string,string> configloader(const fs::path& configloc);
	//写入客户端配置文件
	void configwriter(const fs::path& config_to,const string& name,const string& objpath,const vector<string>& exts);
};