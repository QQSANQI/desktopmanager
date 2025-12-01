#include<unordered_map>
#include "FileCLassifier.h"
#include "jsonconfig_loader.h"
/*完成了基本按规则分类功能,但是嵌套太多*/
bool FileCLassifier::result() const{return Is_classed;}
//分类函数；参数：文件路径列表，规则路径；s
void FileCLassifier::classFile(const vector<fs::path>& filePath, const fs::path& rulePath, const fs::path &storePath)
{
	JsonConfigLoader loader;
	auto map1 = loader.configloader(rulePath);

	for (const fs::path& item : filePath)
	{
		try
		{
			if (!fs::exists(item) || fs::is_directory(item))
				continue; // 只处理存在的文件

			std::string ext = item.extension().string();
			auto it = map1.find(ext);
			fs::path dir = (it != map1.end()) ? storePath / it->second : storePath / u8"其他";

			fs::create_directories(dir);
			fs::path target = dir / item.filename();

			fs::rename(item, target);
		}
		catch (const fs::filesystem_error& e)
		{
			std::cerr << "分类过程出错: " << e.what() << '\n';
		}
		catch (const std::exception& e)
		{
			std::cerr << "分类过程出错: " << e.what() << '\n';
		}
	}

	Is_classed = true;
}
